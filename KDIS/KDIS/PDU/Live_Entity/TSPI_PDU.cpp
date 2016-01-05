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

#include "./TSPI_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace std;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

TSPI_PDU::TSPI_PDU() :
    m_ui8SSDLen( 0 )
{
    m_ui8PDUType = TSPI_PDU_Type;
    m_ui16PDULength = TSPI_PDU_SIZE;
    m_TSPIFlagUnion.m_ui8Flag = 0;
}

//////////////////////////////////////////////////////////////////////////

TSPI_PDU::TSPI_PDU( KDataStream & stream ) throw( KException ) :
    m_ui8SSDLen( 0 )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

TSPI_PDU::TSPI_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
    LE_Header( H ),
    m_ui8SSDLen( 0 )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

TSPI_PDU::TSPI_PDU( const LE_EntityIdentifier & ID ) :
    m_ui8SSDLen( 0 )
{
    m_EntID = ID;
    m_ui8PDUType = TSPI_PDU_Type;
    m_ui16PDULength = TSPI_PDU_SIZE;
    m_TSPIFlagUnion.m_ui8Flag = 0;
}

//////////////////////////////////////////////////////////////////////////

TSPI_PDU::~TSPI_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void TSPI_PDU::SetEntityLinearVelocityFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_TSPIFlagUnion.m_ui8LinVel )return;

    m_TSPIFlagUnion.m_ui8LinVel = F;

    if( F )
    {
        m_ui16PDULength += LE_Vector16_3::LE_VECTOR_SIZE;
    }
    else
    {
        m_ui16PDULength -= LE_Vector16_3::LE_VECTOR_SIZE;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL TSPI_PDU::GetEntityLinearVelocityFlag() const
{
    return m_TSPIFlagUnion.m_ui8LinVel;
}

//////////////////////////////////////////////////////////////////////////


void TSPI_PDU::SetEntityOrientationFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_TSPIFlagUnion.m_ui8Ori )return;

    m_TSPIFlagUnion.m_ui8Ori = F;

    if( F )
    {
        m_ui16PDULength += LE_EulerAngles::LE_EULER_ANGLES_SIZE;
    }
    else
    {
        m_ui16PDULength -= LE_EulerAngles::LE_EULER_ANGLES_SIZE;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL TSPI_PDU::GetEntityOrientationFlag() const
{
    return m_TSPIFlagUnion.m_ui8Ori;
}

//////////////////////////////////////////////////////////////////////////

void TSPI_PDU::SetPositionErrorFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_TSPIFlagUnion.m_ui8PosErr )return;

    m_TSPIFlagUnion.m_ui8PosErr = F;

    if( F )
    {
        m_ui16PDULength += PositionError::POSITION_ERROR_SIZE;
    }
    else
    {
        m_ui16PDULength -= PositionError::POSITION_ERROR_SIZE;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL TSPI_PDU::GetPositionErrorFlag() const
{
    return m_TSPIFlagUnion.m_ui8PosErr;
}

//////////////////////////////////////////////////////////////////////////

void TSPI_PDU::SetOrientationErrorFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_TSPIFlagUnion.m_ui8OriErr )return;

    m_TSPIFlagUnion.m_ui8OriErr = F;

    if( F )
    {
        m_ui16PDULength += OrientationError::ORIENTATION_ERROR_SIZE;
    }
    else
    {
        m_ui16PDULength -= OrientationError::ORIENTATION_ERROR_SIZE;
    }
}
//////////////////////////////////////////////////////////////////////////

KBOOL TSPI_PDU::GetOrientationErrorFlag() const
{
    return m_TSPIFlagUnion.m_ui8OriErr;
}

//////////////////////////////////////////////////////////////////////////

void TSPI_PDU::SetDeadReckoningParameterFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_TSPIFlagUnion.m_ui8DRM )return;

    m_TSPIFlagUnion.m_ui8DRM = F;

    if( F )
    {
        m_ui16PDULength += LE_DeadReckoningParameter::LE_DEAD_RECKONING_PARAMETER_SIZE;
    }
    else
    {
        m_ui16PDULength -= LE_DeadReckoningParameter::LE_DEAD_RECKONING_PARAMETER_SIZE;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL TSPI_PDU::GetDeadReckoningParameterFlag() const
{
    return m_TSPIFlagUnion.m_ui8DRM;
}

//////////////////////////////////////////////////////////////////////////

void TSPI_PDU::SetMeasuredSpeedFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_TSPIFlagUnion.m_ui8Spd )return;

    m_TSPIFlagUnion.m_ui8Spd = F;

    if( F )
    {
        m_ui16PDULength += 2; // 2 = size of KFIXED16.
    }
    else
    {
        m_ui16PDULength -= 2;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL TSPI_PDU::GetMeasuredSpeedFlag() const
{
    return m_TSPIFlagUnion.m_ui8Spd;
}

//////////////////////////////////////////////////////////////////////////

void TSPI_PDU::SetSystemSpecificDataFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_TSPIFlagUnion.m_ui8Data )return;

    m_TSPIFlagUnion.m_ui8Data = F;

    if( F )
    {
        m_ui16PDULength += 1; // 1 = size of data length var.
    }
    else
    {
        m_ui16PDULength -= 1;

        // Remove data size
        m_ui16PDULength -= m_vSSD.size();
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL TSPI_PDU::GetSystemSpecificDataFlag() const
{
    return m_TSPIFlagUnion.m_ui8Data;
}

//////////////////////////////////////////////////////////////////////////

void TSPI_PDU::SetEntityLocation( const RelativeWorldCoordinates & L )
{
    m_Loc = L;
}

//////////////////////////////////////////////////////////////////////////

const RelativeWorldCoordinates & TSPI_PDU::GetEntityLocation() const
{
    return m_Loc;
}

//////////////////////////////////////////////////////////////////////////

RelativeWorldCoordinates & TSPI_PDU::GetEntityLocation()
{
    return m_Loc;
}

//////////////////////////////////////////////////////////////////////////

void TSPI_PDU::SetEntityLinearVelocity( const LE_Vector16_3 & V )
{
    SetEntityLinearVelocityFlag( true );
    m_LinVel = V;
}

//////////////////////////////////////////////////////////////////////////

const LE_Vector16_3 & TSPI_PDU::GetEntityLinearVelocity() const
{
    return m_LinVel;
}

//////////////////////////////////////////////////////////////////////////

LE_Vector16_3 & TSPI_PDU::GetEntityLinearVelocity()
{
    return m_LinVel;
}

//////////////////////////////////////////////////////////////////////////

void TSPI_PDU::SetEntityLinearOrientation( const LE_EulerAngles & O )
{
    SetEntityOrientationFlag( true );
    m_Ori = O;
}

//////////////////////////////////////////////////////////////////////////

const LE_EulerAngles & TSPI_PDU::GetEntityLinearOrientation() const
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

LE_EulerAngles & TSPI_PDU::GetEntityLinearOrientation()
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

void TSPI_PDU::SetPositionError( const PositionError & PE )
{
    SetPositionErrorFlag( true );
    m_PosErr = PE;
}

//////////////////////////////////////////////////////////////////////////

const PositionError & TSPI_PDU::GetPositionError() const
{
    return m_PosErr;
}

//////////////////////////////////////////////////////////////////////////

PositionError & TSPI_PDU::GetPositionError()
{
    return m_PosErr;
}

//////////////////////////////////////////////////////////////////////////

void TSPI_PDU::SetOrientationError( const OrientationError & OE )
{
    SetOrientationErrorFlag( true );
    m_OriErr = OE;
}

//////////////////////////////////////////////////////////////////////////

const OrientationError & TSPI_PDU::GetOrientationError() const
{
    return m_OriErr;
}

//////////////////////////////////////////////////////////////////////////

OrientationError & TSPI_PDU::GetOrientationError()
{
    return m_OriErr;
}

//////////////////////////////////////////////////////////////////////////

void TSPI_PDU::SetDeadReckoningParameter( const LE_DeadReckoningParameter & DRP )
{
    SetDeadReckoningParameterFlag( true );
    m_DeadReckoningParameter = DRP;
}

//////////////////////////////////////////////////////////////////////////

const LE_DeadReckoningParameter & TSPI_PDU::GetDeadReckoningParameter() const
{
    return m_DeadReckoningParameter;
}

//////////////////////////////////////////////////////////////////////////

LE_DeadReckoningParameter & TSPI_PDU::GetDeadReckoningParameter()
{
    return m_DeadReckoningParameter;
}

//////////////////////////////////////////////////////////////////////////

void TSPI_PDU::SetMeasuredSpeed( KFIXED16_3 S )
{
    SetMeasuredSpeedFlag( true );
    m_MeasureSpd = S;
}

//////////////////////////////////////////////////////////////////////////

KFIXED16_3 TSPI_PDU::GetMeasuredSpeed() const
{
    return m_MeasureSpd;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 TSPI_PDU::GetSystemSpecificDataLength() const
{
    return m_ui8SSDLen;
}

//////////////////////////////////////////////////////////////////////////

void TSPI_PDU::SetSystemSpecificData( const std::vector<KOCTET> & SSD )
{
    ClearSystemSpecificData();
    SetSystemSpecificDataFlag( true );
    m_vSSD = SSD;
    m_ui8SSDLen = m_vSSD.size();

    // Set the new pdu length
    m_ui16PDULength += m_vSSD.size();
}

//////////////////////////////////////////////////////////////////////////

void TSPI_PDU::SetSystemSpecificData( const KOCTET * Data, KUINT8 Length )
{
    ClearSystemSpecificData();
    SetSystemSpecificDataFlag( true );
    m_vSSD.clear();

    for( KUINT8 i = 0; i < Length; ++i )
    {
        m_vSSD.push_back( Data[i] );
    }

    m_ui8SSDLen = Length;

    // Set the new pdu length
    m_ui16PDULength += Length;
}

//////////////////////////////////////////////////////////////////////////

const std::vector<KOCTET> & TSPI_PDU::GetSystemSpecificData() const
{
    return m_vSSD;
}

//////////////////////////////////////////////////////////////////////////

void TSPI_PDU::ClearSystemSpecificData()
{
    // Remove old data from pdu length, if any exists.
    m_ui16PDULength -= m_vSSD.size();
    m_vSSD.clear();
}

//////////////////////////////////////////////////////////////////////////

KString TSPI_PDU::GetAsString() const
{
    KStringStream ss;

    ss << LE_Header::GetAsString()
       << "-Time Space Position Information(TSPI) PDU-\n"
       << "Optional Field Flags:\n"
       << "\tLinear Velocity:          " << ( KUINT16 )m_TSPIFlagUnion.m_ui8LinVel << "\n"
       << "\tLinear Orientation:       " << ( KUINT16 )m_TSPIFlagUnion.m_ui8Ori    << "\n"
       << "\tPosition Error:           " << ( KUINT16 )m_TSPIFlagUnion.m_ui8PosErr << "\n"
       << "\tOrientation Error:        " << ( KUINT16 )m_TSPIFlagUnion.m_ui8OriErr << "\n"
       << "\tDead Reckoning Parameter: " << ( KUINT16 )m_TSPIFlagUnion.m_ui8DRM    << "\n"
       << "\tMeasured Speed:           " << ( KUINT16 )m_TSPIFlagUnion.m_ui8Spd    << "\n"
       << "\tSystem Specific Data:     " << ( KUINT16 )m_TSPIFlagUnion.m_ui8Data   << "\n"
       << "Location - "                << m_Loc.GetAsString();

    if( m_TSPIFlagUnion.m_ui8LinVel )
    {
        ss << "Linear Velocity:          " << m_LinVel.GetAsString();
    }

    if( m_TSPIFlagUnion.m_ui8Ori )
    {
        ss << "Linear Orientation:       " << m_Ori.GetAsString();
    }

    if( m_TSPIFlagUnion.m_ui8PosErr )
    {
        ss << "Position Error:           " << m_PosErr.GetAsString();
    }

    if( m_TSPIFlagUnion.m_ui8OriErr )
    {
        ss << "Orientation Error:        " << m_OriErr.GetAsString();
    }

    if( m_TSPIFlagUnion.m_ui8DRM )
    {
        ss << m_DeadReckoningParameter.GetAsString();
    }

    if( m_TSPIFlagUnion.m_ui8Spd )
    {
        ss << "Measured Speed:           " << m_MeasureSpd.GetAsFloat32();
    }

    if( m_TSPIFlagUnion.m_ui8Data )
    {
        ss  << "System Specific Data:\n"
            << "\tData Length: "    << ( KUINT16 )m_ui8SSDLen << "\n"
            << "\tData: ";

        vector<KOCTET>::const_iterator citr = m_vSSD.begin();
        vector<KOCTET>::const_iterator citrEnd = m_vSSD.end();
        for( ; citr != citrEnd; ++citr )
        {
            ss << hex << *citr;
        }
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void TSPI_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < TSPI_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vSSD.clear();

    LE_Header::Decode( stream, ignoreHeader );	

    stream >> m_TSPIFlagUnion.m_ui8Flag
           >> KDIS_STREAM m_Loc;

    if( m_TSPIFlagUnion.m_ui8LinVel )
    {
        stream >> KDIS_STREAM m_LinVel;
    }

    if( m_TSPIFlagUnion.m_ui8Ori )
    {
        stream >> KDIS_STREAM m_Ori;
    }

    if( m_TSPIFlagUnion.m_ui8PosErr )
    {
        stream >> KDIS_STREAM m_PosErr;
    }

    if( m_TSPIFlagUnion.m_ui8OriErr )
    {
        stream >> KDIS_STREAM m_OriErr;
    }

    if( m_TSPIFlagUnion.m_ui8DRM )
    {
        stream >> KDIS_STREAM m_DeadReckoningParameter;
    }

    if( m_TSPIFlagUnion.m_ui8Spd )
    {
        stream >> KDIS_STREAM m_MeasureSpd;
    }

    if( m_TSPIFlagUnion.m_ui8Data )
    {
        stream >> m_ui8SSDLen;

        // Decode System Specific Data
        KOCTET tmp;
        for( KUINT8 i = 0; i < m_ui8SSDLen; ++i )
        {
            stream >> tmp;
            m_vSSD.push_back( tmp );
        }
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream TSPI_PDU::Encode() const
{
    KDataStream stream;

    TSPI_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void TSPI_PDU::Encode( KDataStream & stream ) const
{

    LE_Header::Encode( stream );

    stream << m_TSPIFlagUnion.m_ui8Flag
           << KDIS_STREAM m_Loc;

    if( m_TSPIFlagUnion.m_ui8LinVel )
    {
        stream << KDIS_STREAM m_LinVel;
    }

    if( m_TSPIFlagUnion.m_ui8Ori )
    {
        stream << KDIS_STREAM m_Ori;
    }

    if( m_TSPIFlagUnion.m_ui8PosErr )
    {
        stream << KDIS_STREAM m_PosErr;
    }

    if( m_TSPIFlagUnion.m_ui8OriErr )
    {
        stream << KDIS_STREAM m_OriErr;
    }

    if( m_TSPIFlagUnion.m_ui8DRM )
    {
        stream << KDIS_STREAM m_DeadReckoningParameter;
    }

    if( m_TSPIFlagUnion.m_ui8Spd )
    {
        stream << KDIS_STREAM m_MeasureSpd;
    }

    if( m_TSPIFlagUnion.m_ui8Data )
    {
        stream << m_ui8SSDLen;

        // Encode System Specific Data
        vector<KOCTET>::const_iterator citr = m_vSSD.begin();
        vector<KOCTET>::const_iterator citrEnd = m_vSSD.end();
        for( ; citr != citrEnd; ++citr )
        {
            stream << *citr;
        }
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL TSPI_PDU::operator == ( const TSPI_PDU & Value ) const
{
    if( LE_Header::operator         != ( Value ) )                      return false;
    if( m_TSPIFlagUnion.m_ui8Flag   != Value.m_TSPIFlagUnion.m_ui8Flag )return false;
    if( m_Loc                       != Value.m_Loc )                    return false;
    if( m_LinVel                    != Value.m_LinVel )                 return false;
    if( m_Ori                       != Value.m_Ori )                    return false;
    if( m_PosErr                    != Value.m_PosErr )                 return false;
    if( m_OriErr                    != Value.m_OriErr )                 return false;
    if( m_DeadReckoningParameter    != Value.m_DeadReckoningParameter ) return false;
    if( m_MeasureSpd                != Value.m_MeasureSpd )             return false;
    if( m_ui8SSDLen                 != Value.m_ui8SSDLen )              return false;
    if( m_vSSD                      != Value.m_vSSD )                   return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL TSPI_PDU::operator != ( const TSPI_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


