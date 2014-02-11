/*********************************************************************
Copyright 2013 Karl Jones
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

For Further Information Please Contact me at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

#include "./Minefield_Data_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// protected:
//////////////////////////////////////////////////////////////////////////

KUINT8 Minefield_Data_PDU::calcPaddingPaintScheme() const
{
    // Padding — 8{[4 – N(2 F(8) + M F(9) + F(10) + 2)] mod4} bits unused
    KUINT8 ui8NeedPadding = 2, ui8Pad = 0;
    if( m_DataFilter.IsFusing() )                       ui8NeedPadding += 2;
    if( m_DataFilter.IsScalarDetectionCoefficient() )   ui8NeedPadding += m_ui8NumSensTyp;
    if( m_DataFilter.IsPaintScheme() )                  ++ui8NeedPadding;
    ui8NeedPadding = 4 - ( m_ui8NumMines * ui8NeedPadding );
    return ui8NeedPadding % 4;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Minefield_Data_PDU::calcPaddingVertices() const
{
    vector<Mine>::const_iterator citrMn = m_vMines.begin();
    vector<Mine>::const_iterator citrMnEnd = m_vMines.end();
    KUINT8 ui8NeedPadding = 0;
    for( ; citrMn != citrMnEnd; ++citrMn )
    {
        ui8NeedPadding += citrMn->GetTripDetonationWire().size();
    }

    return ui8NeedPadding % 4;
}

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Minefield_Data_PDU::Minefield_Data_PDU() :
    m_ui8ReqID( 0 ),
    m_ui8PduSeqNum( 0 ),
    m_ui8NumPdus( 0 ),
    m_ui8NumMines( 0 ),
    m_ui8NumSensTyp( 0 ),
    m_ui8Padding1( 0 )
{
    m_ui8PDUType = MinefieldData_PDU_Type;
    m_ui16PDULength = MINEFIELD_DATA_PDU_SIZE;
    m_SeqNumUnion.m_ui16SeqNum = 0;
}

	
//////////////////////////////////////////////////////////////////////////

Minefield_Data_PDU::Minefield_Data_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Minefield_Data_PDU::Minefield_Data_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Minefield_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Minefield_Data_PDU::Minefield_Data_PDU( const EntityIdentifier & MinefieldID, const EntityIdentifier & RequestingSimulationID,
                                        KUINT16 SeqNum, KUINT8 RequestID, KUINT8 PduSeqNum, KUINT8 NumPdus,
                                        const MinefieldDataFilter & DF, const EntityType & MineType ) :
    m_ReqID( RequestingSimulationID ),
    m_ui8ReqID( RequestID ),
    m_ui8PduSeqNum( PduSeqNum ),
    m_ui8NumPdus( NumPdus ),
    m_DataFilter( DF ),
    m_MineTyp( MineType ),
    m_ui8NumMines( 0 ),
    m_ui8NumSensTyp( 0 ),
    m_ui8Padding1( 0 )
{
    m_ui8PDUType = MinefieldData_PDU_Type;
    m_ui16PDULength = MINEFIELD_DATA_PDU_SIZE;
    m_SeqNumUnion.m_ui16SeqNum15 = SeqNum;
    m_MinefieldID = MinefieldID;
}

//////////////////////////////////////////////////////////////////////////

Minefield_Data_PDU::~Minefield_Data_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Data_PDU::SetRequestingSimulationID( const EntityIdentifier & ID )
{
    m_ReqID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Minefield_Data_PDU::GetRequestingSimulationID() const
{
    return m_ReqID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Minefield_Data_PDU::GetRequestingSimulationID()
{
    return m_ReqID;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Data_PDU::SetSequenceNumber( KUINT16 S )
{
    m_SeqNumUnion.m_ui16SeqNum15 = S;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Minefield_Data_PDU::GetSequenceNumber() const
{
    return m_SeqNumUnion.m_ui16SeqNum15;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Data_PDU::SetRequestID( KUINT8 ID )
{
    m_ui8ReqID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Minefield_Data_PDU::GetRequestID() const
{
    return m_ui8ReqID;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Data_PDU::SetPDUSequenceNumber( KUINT8 SN )
{
    m_ui8PduSeqNum = SN;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Minefield_Data_PDU::GetPDUSequenceNumber() const
{
    return m_ui8PduSeqNum;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Data_PDU::SetNumberOfPDUs( KUINT8 N )
{
    m_ui8NumPdus = N;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Minefield_Data_PDU::GetNumberOfPDUs() const
{
    return m_ui8NumPdus;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Minefield_Data_PDU::GetNumberOfMines() const
{
    return m_ui8NumMines;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Minefield_Data_PDU::GetNumberOfSensorsTypes() const
{
    return m_ui8NumSensTyp;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Data_PDU::SetDataFilter( const MinefieldDataFilter & DF )
{
    m_DataFilter = DF;
}

//////////////////////////////////////////////////////////////////////////

const MinefieldDataFilter & Minefield_Data_PDU::GetDataFilter() const
{
    return m_DataFilter;
}

//////////////////////////////////////////////////////////////////////////

MinefieldDataFilter & Minefield_Data_PDU::GetDataFilter()
{
    return m_DataFilter;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Data_PDU::SetMineType( const EntityType & MT )
{
    m_MineTyp = MT;
}

//////////////////////////////////////////////////////////////////////////

const EntityType & Minefield_Data_PDU::GetMineType() const
{
    return m_MineTyp;
}

//////////////////////////////////////////////////////////////////////////

EntityType & Minefield_Data_PDU::GetMineType()
{
    return m_MineTyp;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Data_PDU::AddSensorType( SensorType ST )
{
    m_vui16SensorTypes.push_back( ST );
    m_ui16PDULength += 2; // 16 bit enum. = 2 octets
    ++m_ui8NumSensTyp;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Data_PDU::SetSensorTypes( const vector<KUINT16> & ST )
{
    // Subtract old values from pdu length.
    m_ui16PDULength -= m_ui8NumSensTyp * 2; // 2 = size of sensor type.

    m_vui16SensorTypes = ST;
    m_ui8NumSensTyp = m_vui16SensorTypes.size();

    // Calculate the new size
    m_ui16PDULength += m_ui8NumSensTyp * 2;
}

//////////////////////////////////////////////////////////////////////////

const vector<KUINT16> & Minefield_Data_PDU::GetSensorTypes() const
{
    return m_vui16SensorTypes;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Data_PDU::AddMine( const Mine & M ) throw( KException )
{
    // First check the mine has the same optional fields set as MinefieldDataFilter.
    if( M.MinefieldDataFilter::operator != ( m_DataFilter ) )
    {
        throw KException( __FUNCTION__, INVALID_OPERATION, "The Mine filter does not match the PDU MinefieldDataFilter.			\
															All mines must have the same optional values set as specified by	\
															the PDU MinefieldDataFilter. This mine has been ignored." );
    }

    m_vMines.push_back( M );
    m_ui16PDULength += M.GetLength();
    ++m_ui8NumMines;
}

//////////////////////////////////////////////////////////////////////////

void Minefield_Data_PDU::SetMines( const std::vector<Mine> & M ) throw( KException )
{
    // First check the mines all have the same optional fields set as MinefieldDataFilter.
    vector<Mine>::const_iterator citr = M.begin();
    vector<Mine>::const_iterator citrEnd = M.end();
    for( ; citr != citrEnd; ++citr )
    {
        if( citr->MinefieldDataFilter::operator != ( m_DataFilter ) )
        {
            throw KException( __FUNCTION__, INVALID_OPERATION, "One or more mines do not have the correct filters.				\
																They must have the same filter as the PDU MinefieldDataFilter.	\
																This set request has been ignored" );
        }
    }

    m_vMines = M;
    m_ui8NumMines = M.size();

    // Calculate the new size
    m_ui16PDULength = MINEFIELD_DATA_PDU_SIZE + ( m_ui8NumSensTyp * 2 );
    citr = m_vMines.begin();
    citrEnd = m_vMines.end();
    for( ; citr != citrEnd; ++citr )
    {
        m_ui16PDULength += citr->GetLength();
    }
}

//////////////////////////////////////////////////////////////////////////

const std::vector<Mine> & Minefield_Data_PDU::GetMines() const
{
    return m_vMines;
}

//////////////////////////////////////////////////////////////////////////

KString Minefield_Data_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Minefield Data PDU-\n"
       << Minefield_Header::GetAsString()
       << "Requesting ID: "             << IndentString( m_ReqID.GetAsString(), 1 )
       << "Minefield Sequence Number: " << m_SeqNumUnion.m_ui16SeqNum
       << "Request ID: "                << ( KUINT16 )m_ui8ReqID        << "\n"
       << "PDU Sequence Number: "       << ( KUINT16 )m_ui8PduSeqNum    << "\n"
       << "Number Of PDU's: "           << ( KUINT16 )m_ui8NumPdus      << "\n"
       << "Number Of Mines: "           << ( KUINT16 )m_ui8NumMines     << "\n"
       << "Number Of Sensor Types: "    << ( KUINT16 )m_ui8NumSensTyp   << "\n"
       << m_DataFilter.GetAsString()
       << "Mine Type: " << m_MineTyp.GetAsString()
       << "Sensor Types:\n";

    // Sensor Types
    vector<KUINT16>::const_iterator citrSt = m_vui16SensorTypes.begin();
    vector<KUINT16>::const_iterator citrStEnd = m_vui16SensorTypes.end();
    for( ; citrSt != citrStEnd; ++citrSt )
    {
        ss <<  "\t" << *citrSt << "\n";
    }

    ss << "Mines:\n";

    vector<Mine>::const_iterator citrMn = m_vMines.begin();
    vector<Mine>::const_iterator citrMnEnd = m_vMines.end();
    for( ; citrMn != citrMnEnd; ++citrMn )
    {
        ss << citrMn->GetAsString();
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

// 2 simple macros for decoding the various mine fields. Makes the code easier to read.
#define MINE_DECODE_NATIVE( TYPE, SETFUNCTION ) for( i = 0; i < m_ui8NumMines; ++i )                \
                                                {                                                   \
                                                    TYPE t;                                         \
                                                    stream >> t;                                    \
                                                    m_vMines[i].SETFUNCTION( t );                   \
                                                }

#define MINE_DECODE_CLASS( TYPE, SETFUNCTION )  for( i = 0; i < m_ui8NumMines; ++i )                \
                                                {                                                   \
                                                    m_vMines[i].SETFUNCTION( TYPE( stream ) );      \
                                                }

//////////////////////////////////////////////////////////////////////////

void Minefield_Data_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < MINEFIELD_DATA_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vui16SensorTypes.clear();
    m_vMines.clear();

    Minefield_Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_ReqID
           >> m_SeqNumUnion.m_ui16SeqNum
           >> m_ui8ReqID
           >> m_ui8PduSeqNum
           >> m_ui8NumPdus
           >> m_ui8NumMines
           >> m_ui8NumSensTyp
           >> m_ui8Padding1
           >> KDIS_STREAM m_DataFilter
           >> KDIS_STREAM m_MineTyp;

    // Sensor Types
    KUINT16 ui16SnsTyp = 0;
    KUINT8 i = 0;
    for( i = 0; i < m_ui8NumSensTyp; ++i )
    {
        stream >> ui16SnsTyp;
        m_vui16SensorTypes.push_back( ui16SnsTyp );
    }

    // Padding?
    KUINT8 ui8PaddingNeeded1 = m_ui8NumSensTyp % 2;
    if( ui8PaddingNeeded1 )
    {
        KUINT16 ui16Pad = 0;
        stream >> ui16Pad;
    }

    /************************************************************************/
    /* Mines                                                                */
    /************************************************************************/

    // Create the mines and extract location from stream
    for( i = 0; i < m_ui8NumMines; ++i )
    {
        Mine mn;
        mn.SetLocation( Vector( stream ) );
        m_vMines.push_back( mn );
    }

    // The following are all dependent on the data filter( except ID ):
    if( m_DataFilter.IsGroundBurialDepthOffset() )  MINE_DECODE_NATIVE( KFLOAT32, SetGroundBurialDepthOffsetValue )
        if( m_DataFilter.IsWaterBurialDepthOffset() )   MINE_DECODE_NATIVE( KFLOAT32, SetWaterBurialDepthOffsetValue )
            if( m_DataFilter.IsSnowBurialDepthOffset() )    MINE_DECODE_NATIVE( KFLOAT32, SetSnowBurialDepthOffsetValue )
                if( m_DataFilter.IsMineOrientation() )          MINE_DECODE_CLASS( EulerAngles, SetMineOrientationValue )
                    if( m_DataFilter.IsThermalContrast() )          MINE_DECODE_NATIVE( KFLOAT32, SetThermalContrastValue )
                        if( m_DataFilter.IsReflectance() )              MINE_DECODE_NATIVE( KFLOAT32, SetReflectanceValue )
                            if( m_DataFilter.IsMineEmplacementAge() )       MINE_DECODE_CLASS( ClockTime, SetMineEmplacementAgeValue )
                                MINE_DECODE_NATIVE( KUINT16, SetID )
                                if( m_DataFilter.IsFusing() )                   MINE_DECODE_CLASS( MineFusing, SetFusingValue )

                                    if( m_DataFilter.IsScalarDetectionCoefficient() )
                                    {
                                        for( i = 0; i < m_ui8NumMines; ++i )
                                        {
                                            for( KUINT8 j = 0; j < m_ui8NumSensTyp; ++j )
                                            {
                                                KUINT8 ui8Sdc = 0;
                                                stream >> ui8Sdc;
                                                m_vMines[i].AddScalarDetectionCoefficientValue( ui8Sdc );
                                            }
                                        }
                                    }

    if( m_DataFilter.IsPaintScheme() ) MINE_DECODE_CLASS( MinePaintScheme, SetPaintSchemeValue )

    // Do we need to add padding?
    // Padding — 8{[4 – N(2 F(8) + M F(9) + F(10) + 2)] mod4} bits unused
    KUINT8 ui8PaddingNeeded2 = calcPaddingPaintScheme();
    KUINT8 ui8Pad = 0;
    for( KUINT8 i = 0; i < ui8PaddingNeeded2; ++i )
    {
        stream >> ui8Pad;
    }

    // Trip/Det wires
    if( m_DataFilter.IsTripDetonationWire() )
    {
        // Get the number of trip/det wires
        vector<KUINT8> vNumTripDet( m_ui8NumMines );
        KUINT16 ui16TtlVerts = 0;
        KUINT8 ui8Tmp = 0;
        for( i = 0; i < m_ui8NumMines; ++i )
        {
            stream >> ui8Tmp;
            ui16TtlVerts += ui8Tmp;
            vNumTripDet.push_back( ui8Tmp );
        }

        // Do we need to extract any padding?
        KUINT8 ui8PaddingNeeded = ( 4 - m_ui8NumMines ) % 4;
        for( i = 0; i < ui8PaddingNeeded; ++i )
        {
            stream >> ui8Pad;
        }

        // Number of vertices's.
        vector<KUINT8> vNumVerts( ui16TtlVerts );
        for( i = 0; i < ui16TtlVerts; ++i )
        {
            stream >> ui8Tmp;
            vNumVerts.push_back( ui8Tmp );
        }

        // More padding?	
        ui8PaddingNeeded = ( vNumVerts.size() % 4 == 0 ? 0 : ( 4 - vNumVerts.size() % 4 ) );
        for( i = 0; i < ui8PaddingNeeded; ++i )
        {
            stream >> ui8Pad;
        }

        // Extract all vertices's and place them into the correct mines.
        // For each mine
        vector<KUINT8>::const_iterator citrVert = vNumVerts.begin();
        for( i = 0; i < m_ui8NumMines; ++i )
        {
            // For each wire in the mine
            KUINT8 ui8Loop = vNumTripDet[i];
            for( KUINT8 j = 0; j < ui8Loop; ++j )
            {
                // Get the vertices's.
                vector<Vector> vVerts( *citrVert );
                KUINT8 ui8LoopVerts = *citrVert;
                for( KUINT8 k = 0; k < ui8LoopVerts; ++k )
                {
                    vVerts.push_back( Vector( stream ) );
                }

                // Add the vertices's to the current mine.
                m_vMines[i].AddTripDetonationWire( vVerts );
                ++citrVert;
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Minefield_Data_PDU::Encode() const throw( KException )
{
    KDataStream stream;

    Minefield_Data_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

// 2 simple macros for encoding the various mine fields. Makes the code easier to read.
#define MINE_ENCODE_CLASS( GETFUNCTION )citrMn = m_vMines.begin();                          \
                                        citrMnEnd = m_vMines.end();                         \
                                        for( ; citrMn != citrMnEnd; ++citrMn )              \
                                        {                                                   \
                                            stream << KDIS_STREAM citrMn->GETFUNCTION();    \
                                        }

#define MINE_ENCODE_NATIVE( GETFUNCTION )citrMn = m_vMines.begin();                         \
                                         citrMnEnd = m_vMines.end();                        \
                                         for( ; citrMn != citrMnEnd; ++citrMn )             \
                                         {                                                  \
                                             stream << citrMn->GETFUNCTION();               \
                                         }

//////////////////////////////////////////////////////////////////////////

void Minefield_Data_PDU::Encode( KDataStream & stream ) const throw( KException )
{
    // Calculate padding first and add it to the pdu length
    KUINT16 m_ui16OldLength = m_ui16PDULength;
    KUINT8 ui8PaddingNeeded1 = ( m_ui8NumSensTyp % 2 ) * 2;
    KUINT8 ui8PaddingNeeded2 = calcPaddingPaintScheme();
    KUINT8 ui8PaddingNeeded3 = 0;
    if( m_DataFilter.IsTripDetonationWire() )ui8PaddingNeeded3 += ( 4 - m_ui8NumMines ) % 4;
    KUINT8 ui8PaddingNeeded4 = calcPaddingVertices();
    KUINT8 ui8Pad = 0;

    // Add all the padding to the PDU length
    Header * pHead = ( Header* )this;
    pHead->SetPDULength( m_ui16PDULength + ui8PaddingNeeded1 + ui8PaddingNeeded2 + ui8PaddingNeeded3 + ui8PaddingNeeded4 );

    Minefield_Header::Encode( stream );

    stream << KDIS_STREAM m_ReqID
           << m_SeqNumUnion.m_ui16SeqNum
           << m_ui8ReqID
           << m_ui8PduSeqNum
           << m_ui8NumPdus
           << m_ui8NumMines
           << m_ui8NumSensTyp
           << m_ui8Padding1
           << KDIS_STREAM m_DataFilter
           << KDIS_STREAM m_MineTyp;

    // Sensor Types
    vector<KUINT16>::const_iterator citrSt = m_vui16SensorTypes.begin();
    vector<KUINT16>::const_iterator citrStEnd = m_vui16SensorTypes.end();
    for( ; citrSt != citrStEnd; ++citrSt )
    {
        stream << *citrSt;
    }

    if( ui8PaddingNeeded1 )
    {
        KUINT16 ui16Pad = 0;
        stream << ui16Pad;
    }

    /************************************************************************/
    /* Mines                                                                */
    /************************************************************************/
    vector<Mine>::const_iterator citrMn;
    vector<Mine>::const_iterator citrMnEnd;

    MINE_ENCODE_CLASS( GetLocation )

    // The following are all dependent on the data filter( except ID ):
    if( m_DataFilter.IsGroundBurialDepthOffset() )  MINE_ENCODE_NATIVE( GetGroundBurialDepthOffsetValue )
        if( m_DataFilter.IsWaterBurialDepthOffset() )   MINE_ENCODE_NATIVE( GetWaterBurialDepthOffsetValue )
            if( m_DataFilter.IsSnowBurialDepthOffset() )    MINE_ENCODE_NATIVE( GetSnowBurialDepthOffsetValue )
                if( m_DataFilter.IsMineOrientation() )          MINE_ENCODE_CLASS( GetMineOrientationValue )
                    if( m_DataFilter.IsThermalContrast() )          MINE_ENCODE_NATIVE( GetThermalContrastValue )
                        if( m_DataFilter.IsReflectance() )              MINE_ENCODE_NATIVE( GetReflectanceValue )
                            if( m_DataFilter.IsMineEmplacementAge() )       MINE_ENCODE_CLASS( GetMineEmplacementAgeValue )
                                MINE_ENCODE_NATIVE( GetID )
                                if( m_DataFilter.IsFusing() )                   MINE_ENCODE_CLASS( GetFusingValue )

                                    if( m_DataFilter.IsScalarDetectionCoefficient() )
                                    {
                                        citrMnEnd = m_vMines.end();
                                        citrMn = m_vMines.begin();
                                        for( ; citrMn != citrMnEnd; ++citrMn )
                                        {
                                            // First check that the mine has the correct number of SDC.
                                            if( m_ui8NumSensTyp != citrMn->GetScalarDetectionCoefficientValues().size() )
                                            {
                                                throw KException( __FUNCTION__, INVALID_DATA, "Mine does not have the correct number of scalar detection \
															  coefficient values. Each mine must have the same number of \
															  SDC values as sensor types" );
                                            }

                                            vector<KUINT8>::const_iterator citrSDC = citrMn->GetScalarDetectionCoefficientValues().begin();
                                            vector<KUINT8>::const_iterator citrSDCEnd = citrMn->GetScalarDetectionCoefficientValues().end();
                                            for( ; citrSDC != citrSDCEnd; ++citrSDC )
                                            {
                                                stream << *citrSDC;
                                            }
                                        }
                                    }

    if( m_DataFilter.IsPaintScheme() ) MINE_ENCODE_CLASS( GetPaintSchemeValue )

        // Do we need to add padding?
        for( KUINT8 i = 0; i < ui8PaddingNeeded2; ++i )
        {
            stream << ui8Pad;
        }

    // Trip/Det wires
    if( m_DataFilter.IsTripDetonationWire() )
    {
        MINE_ENCODE_NATIVE( GetNumberTripDetonationWires )

        // Do we need more padding? [(4-n) mod4] 8[F(7)]
        for( KUINT8 i = 0; i < ui8PaddingNeeded3; ++i )
        {
            stream << ui8Pad;
        }

        // Number of vertices's field
        citrMnEnd = m_vMines.end();
        citrMn = m_vMines.begin();
        for( ; citrMn != citrMnEnd; ++citrMn )
        {
            map< KUINT16, vector<Vector> >::const_iterator citrWr = citrMn->GetTripDetonationWire().begin();
            map< KUINT16, vector<Vector> >::const_iterator citrWrEnd = citrMn->GetTripDetonationWire().end();
            for( ; citrWr != citrWrEnd; ++citrWr )
            {
                stream << ( KUINT8 )citrWr->second.size();
            }
        }
    }

    // Padding?
    for( KUINT8 i = 0; i < ui8PaddingNeeded4; ++i )
    {
        stream << ui8Pad;
    }

    // Vertices's
    citrMnEnd = m_vMines.end();
    citrMn = m_vMines.begin();
    for( ; citrMn != citrMnEnd; ++citrMn )
    {
        map< KUINT16, vector<Vector> >::const_iterator citrWr = citrMn->GetTripDetonationWire().begin();
        map< KUINT16, vector<Vector> >::const_iterator citrWrEnd = citrMn->GetTripDetonationWire().end();
        for( ; citrWr != citrWrEnd; ++citrWr )
        {
            vector<Vector>::const_iterator citrVr = citrWr->second.begin();
            vector<Vector>::const_iterator citrVrEnd = citrWr->second.end();
            for( ; citrVr != citrVrEnd; citrVr )
            {
                stream << KDIS_STREAM *citrVr;
            }
        }
    }

    // Reset the length for the next encode
    pHead->SetPDULength( m_ui16OldLength );
}

//////////////////////////////////////////////////////////////////////////

KBOOL Minefield_Data_PDU::operator == ( const Minefield_Data_PDU & Value ) const
{
    if( Minefield_Header::operator  != ( Value ) )                          return false;
    if( m_ReqID                     != Value.m_ReqID )                      return false;
    if( m_SeqNumUnion.m_ui16SeqNum  != Value.m_SeqNumUnion.m_ui16SeqNum )   return false;
    if( m_ui8ReqID                  != Value.m_ui8ReqID )                   return false;
    if( m_ui8PduSeqNum              != Value.m_ui8PduSeqNum )               return false;
    if( m_ui8NumPdus                != Value.m_ui8NumPdus )                 return false;
    if( m_ui8NumMines               != Value.m_ui8NumMines )                return false;
    if( m_ui8NumSensTyp             != Value.m_ui8NumSensTyp )              return false;
    if( m_DataFilter                != Value.m_DataFilter )                 return false;
    if( m_MineTyp                   != Value.m_MineTyp )                    return false;
    if( m_vui16SensorTypes          != Value.m_vui16SensorTypes )           return false;
    if( m_vMines                    != Value.m_vMines )                     return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Minefield_Data_PDU::operator != ( const Minefield_Data_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


