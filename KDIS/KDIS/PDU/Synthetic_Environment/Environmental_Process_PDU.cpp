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

#include "./Environmental_Process_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Environmental_Process_PDU::Environmental_Process_PDU() :
    m_ui8ModelType( 0 ),
    m_ui8EnvStatus( 0 ),
    m_ui16NumEnvRec( 0 ),
    m_ui16SeqNum( 0 )
{
    m_ui8ProtocolFamily = SyntheticEnvironment;
    m_ui8PDUType = EnvironmentalProcess_PDU_Type;
    m_ui16PDULength = ENVIROMENTAL_PROCESS_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Environmental_Process_PDU::Environmental_Process_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Environmental_Process_PDU::Environmental_Process_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Environmental_Process_PDU::Environmental_Process_PDU( const EntityIdentifier & EnvironmentalProcessID, const EnvironmentType & ET,
        KUINT8 ModelType, KBOOL EnvironmentStatusLast, KBOOL EnvironmentStatusOn,
        KUINT16 SequenceNumber ) :
    m_EnvProcID( EnvironmentalProcessID ),
    m_EnvType( ET ),
    m_ui8ModelType( ModelType ),
    m_ui8EnvStatusBit0( EnvironmentStatusLast ),
    m_ui8EnvStatusBit1( EnvironmentStatusOn ),
    m_ui16NumEnvRec( 0 ),
    m_ui16SeqNum( SequenceNumber )
{
    m_ui8ProtocolFamily = SyntheticEnvironment;
    m_ui8PDUType = EnvironmentalProcess_PDU_Type;
    m_ui16PDULength = ENVIROMENTAL_PROCESS_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Environmental_Process_PDU::Environmental_Process_PDU( const EntityIdentifier & EnvironmentalProcessID, const EnvironmentType & ET,
        KUINT8 ModelType, KBOOL EnvironmentStatusLast, KBOOL EnvironmentStatusOn,
        KUINT16 SequenceNumber, const vector<EnvironmentRecordPtr> & ERL ) :
    m_EnvProcID( EnvironmentalProcessID ),
    m_EnvType( ET ),
    m_ui8ModelType( ModelType ),
    m_ui8EnvStatusBit0( EnvironmentStatusLast ),
    m_ui8EnvStatusBit1( EnvironmentStatusOn ),
    m_ui16NumEnvRec( ERL.size() ),
    m_ui16SeqNum( SequenceNumber ),
    m_vEnvRecords( ERL )
{
    m_ui8ProtocolFamily = SyntheticEnvironment;
    m_ui8PDUType = EnvironmentalProcess_PDU_Type;
    m_ui16PDULength = ENVIROMENTAL_PROCESS_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Environmental_Process_PDU::~Environmental_Process_PDU()
{
    m_vEnvRecords.clear();
}

//////////////////////////////////////////////////////////////////////////

void Environmental_Process_PDU::SetEnvironmentalProcessID( const EntityIdentifier & ID )
{
    m_EnvProcID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Environmental_Process_PDU::GetEnvironmentalProcessID() const
{
    return m_EnvProcID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Environmental_Process_PDU::GetEnvironmentalProcessID()
{
    return m_EnvProcID;
}

//////////////////////////////////////////////////////////////////////////

void Environmental_Process_PDU::SetEnvironmentType( const EnvironmentType & ET )
{
    m_EnvType = ET;
}

//////////////////////////////////////////////////////////////////////////

const EnvironmentType & Environmental_Process_PDU::GetEnvironmentType() const
{
    return m_EnvType;
}

//////////////////////////////////////////////////////////////////////////

EnvironmentType & Environmental_Process_PDU::GetEnvironmentType()
{
    return m_EnvType;
}

//////////////////////////////////////////////////////////////////////////

void Environmental_Process_PDU::SetModelType( KUINT8 MT )
{
    m_ui8ModelType = MT;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Environmental_Process_PDU::GetModelType() const
{
    return m_ui8ModelType;
}

//////////////////////////////////////////////////////////////////////////

void Environmental_Process_PDU::SetEnvironmentStatus( KUINT8 ES )
{
    m_ui8EnvStatus = ES;
}

//////////////////////////////////////////////////////////////////////////

void Environmental_Process_PDU::SetEnvironmentStatus( KBOOL Last, KBOOL On )
{
    m_ui8EnvStatusBit0 = Last;
    m_ui8EnvStatusBit1 = On;
}

//////////////////////////////////////////////////////////////////////////

void Environmental_Process_PDU::SetEnvironmentStatusLast( KBOOL L )
{
    m_ui8EnvStatusBit0 = L;
}

//////////////////////////////////////////////////////////////////////////

void Environmental_Process_PDU::SetEnvironmentStatusOn( KBOOL O )
{
    m_ui8EnvStatusBit1 = O;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Environmental_Process_PDU::GetEnvironmentStatus() const
{
    return m_ui8EnvStatus;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Environmental_Process_PDU::IsEnvironmentStatusLast() const
{
    return m_ui8EnvStatusBit0;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Environmental_Process_PDU::IsEnvironmentStatusOn() const
{
    return m_ui8EnvStatusBit1;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Environmental_Process_PDU::GetNumberOfEnvironmentRecords() const
{
    return m_ui16NumEnvRec;
}

//////////////////////////////////////////////////////////////////////////

void Environmental_Process_PDU::SetSequenceNumber( KUINT16 SN )
{
    m_ui16SeqNum = SN;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Environmental_Process_PDU::GetSequenceNumber() const
{
    return m_ui16SeqNum;
}

//////////////////////////////////////////////////////////////////////////

void Environmental_Process_PDU::SetEnvironmentRecords( const vector<EnvironmentRecordPtr> & ER )
{
    // Reset the PDU length.
    m_ui16PDULength = ENVIROMENTAL_PROCESS_PDU_SIZE;
    m_vEnvRecords = ER;
    m_ui16NumEnvRec = m_vEnvRecords.size();

    vector<EnvironmentRecordPtr>::const_iterator citr = m_vEnvRecords.begin();
    vector<EnvironmentRecordPtr>::const_iterator citrEnd = m_vEnvRecords.end();

    // Calculate the new PDU length
    for( ; citr != citrEnd; ++citr )
    {
        // GetLength returns value in bits so convert to bytes and add the header length
        m_ui16PDULength += EnvironmentRecord::ENVIRONMENT_RECORD_SIZE + ( ( *citr )->GetLength() / 8 );
    }
}

//////////////////////////////////////////////////////////////////////////

const vector<EnvironmentRecordPtr> & Environmental_Process_PDU::GetEnvironmentRecords() const
{
    return m_vEnvRecords;
}

//////////////////////////////////////////////////////////////////////////

void Environmental_Process_PDU::AddEnvironmentRecord( EnvironmentRecordPtr ER )
{
    m_vEnvRecords.push_back( ER );
    ++m_ui16NumEnvRec;
    m_ui16PDULength += EnvironmentRecord::ENVIRONMENT_RECORD_SIZE + ( ER->GetLength() / 8 ); // GetLength returns value in bits so convert to bytes.;
}

//////////////////////////////////////////////////////////////////////////

void Environmental_Process_PDU::ClearEnvironmentRecords()
{
    // Reset the PDU length.
    m_ui16PDULength = ENVIROMENTAL_PROCESS_PDU_SIZE;
	m_vEnvRecords.clear();
}

//////////////////////////////////////////////////////////////////////////

KString Environmental_Process_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Environmental Process PDU-\n"
       << "Environmental Process ID:\n"
       << IndentString( m_EnvProcID.GetAsString(), 1 )
       << "Environment Type: "             << m_EnvType.GetAsString()
       << "Model Type:		 "             << ( KUINT16 )m_ui8ModelType     << "\n"
       << "Environment Status:"                                              << "\n"
       << "\tLast PDU: "                   << ( KUINT16 )m_ui8EnvStatusBit0 << "\n"
       << "\tActive: "                     << ( KUINT16 )m_ui8EnvStatusBit1 << "\n"
       << "Number Of Environment Records: " << m_ui16NumEnvRec               << "\n"
       << "Sequence Number: "              << m_ui16SeqNum                  << "\n";

    vector<EnvironmentRecordPtr>::const_iterator citr = m_vEnvRecords.begin();
    vector<EnvironmentRecordPtr>::const_iterator citrEnd = m_vEnvRecords.end();

    for( ; citr != citrEnd; ++citr )
    {
        ss << ( *citr )->GetAsString();
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Environmental_Process_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < ENVIROMENTAL_PROCESS_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vEnvRecords.clear();

    Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_EnvProcID
           >> KDIS_STREAM m_EnvType
           >> m_ui8ModelType
           >> m_ui8EnvStatus
           >> m_ui16NumEnvRec
           >> m_ui16SeqNum;

    for( KUINT16 i = 0; i < m_ui16NumEnvRec; ++i )
    {
        // We now need to "peak" at the next 4 bytes to determine the Environment Record type,
        // once we have determined the type we need to return the buffers write positon as this
        // field needs to be re-read by the decode function of the derived Environment Record.
        KUINT16 ui16CurrentWritePos = stream.GetCurrentWritePosition();

        KUINT32 ui32RecType;
        stream >> ui32RecType;

        // We now know what type of record we should create, we need to reset the buffer so this value can be re-read.
        stream.SetCurrentWritePosition( ui16CurrentWritePos );

		m_vEnvRecords.push_back( EnvironmentRecord::FactoryDecodeEnvironmentRecord( stream ) );		
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Environmental_Process_PDU::Encode() const
{
    KDataStream stream;

    Environmental_Process_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Environmental_Process_PDU::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );

    stream << KDIS_STREAM m_EnvProcID
           << KDIS_STREAM m_EnvType
           << m_ui8ModelType
           << m_ui8EnvStatus
           << m_ui16NumEnvRec
           << m_ui16SeqNum;

    vector<EnvironmentRecordPtr>::const_iterator citr = m_vEnvRecords.begin();
    vector<EnvironmentRecordPtr>::const_iterator citrEnd = m_vEnvRecords.end();
    for( ; citr != citrEnd; ++citr )
    {
        ( *citr )->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Environmental_Process_PDU::operator == ( const Environmental_Process_PDU & Value ) const
{
    if( Header::operator != ( Value ) )             return false;
    if( m_EnvProcID      != Value.m_EnvProcID )     return false;
    if( m_EnvType        != Value.m_EnvType )       return false;
    if( m_ui8ModelType   != Value.m_ui8ModelType )  return false;
    if( m_ui8EnvStatus   != Value.m_ui8EnvStatus )  return false;
    if( m_ui16NumEnvRec  != Value.m_ui16NumEnvRec ) return false;
    if( m_ui16SeqNum     != Value.m_ui16SeqNum )    return false;
    if( m_vEnvRecords    != Value.m_vEnvRecords )   return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Environmental_Process_PDU::operator != ( const Environmental_Process_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////





