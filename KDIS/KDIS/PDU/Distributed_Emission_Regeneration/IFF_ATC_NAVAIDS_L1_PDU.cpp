/*********************************************************************
Copyright 2013 KDIS
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

#include "./IFF_ATC_NAVAIDS_L1_PDU.h"

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

IFF_ATC_NAVAIDS_L1_PDU::IFF_ATC_NAVAIDS_L1_PDU() :
    m_ui8SystemDesignator( 0 ),
	m_ui8SystemSpecific( 0 )
{
    m_ui8ProtocolFamily = Distributed_Emission_Regeneration;
    m_ui8PDUType = IFF_ATC_NAVAIDS_PDU_Type;
    m_ui16PDULength = IFF_ATC_NAVAIDS_L1_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

IFF_ATC_NAVAIDS_L1_PDU::IFF_ATC_NAVAIDS_L1_PDU( const Header & H ) :
	Header( H ),
	m_ui8SystemDesignator( 0 ),
	m_ui8SystemSpecific( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

IFF_ATC_NAVAIDS_L1_PDU::IFF_ATC_NAVAIDS_L1_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

IFF_ATC_NAVAIDS_L1_PDU::IFF_ATC_NAVAIDS_L1_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

IFF_ATC_NAVAIDS_L1_PDU::IFF_ATC_NAVAIDS_L1_PDU( const EntityIdentifier & EmittingID, const EntityIdentifier & EventID, const Vector & Location,
        const SystemIdentifier & ID, const FundamentalOperationalData & FOD ) :
    m_EmittingEntityID( EmittingID ),
    m_EventID( EventID ),
    m_Location( Location ),
    m_SystemID( ID ),
    m_FOD( FOD ),
	m_ui8SystemDesignator( 0 ),
	m_ui8SystemSpecific( 0 )
{
    m_ui8ProtocolFamily = Distributed_Emission_Regeneration;
    m_ui8PDUType = IFF_ATC_NAVAIDS_PDU_Type;
    m_ui16PDULength = IFF_ATC_NAVAIDS_L1_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

IFF_ATC_NAVAIDS_L1_PDU::~IFF_ATC_NAVAIDS_L1_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_L1_PDU::SetEmittingEntityID( const EntityIdentifier & ID )
{
    m_EmittingEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & IFF_ATC_NAVAIDS_L1_PDU::GetEmittingEntityID() const
{
    return m_EmittingEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & IFF_ATC_NAVAIDS_L1_PDU::GetEmittingEntityID()
{
    return m_EmittingEntityID;
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_L1_PDU::SetEventID( const EntityIdentifier & ID )
{
    m_EventID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & IFF_ATC_NAVAIDS_L1_PDU::GetEventID() const
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & IFF_ATC_NAVAIDS_L1_PDU::GetEventID()
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_L1_PDU::SetLocation( const Vector & L )
{
    m_Location = L;
}

//////////////////////////////////////////////////////////////////////////

const Vector & IFF_ATC_NAVAIDS_L1_PDU::GetLocation() const
{
    return m_Location;
}

//////////////////////////////////////////////////////////////////////////

Vector & IFF_ATC_NAVAIDS_L1_PDU::GetLocation()
{
    return m_Location;
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_L1_PDU::SetSystemIdentifier( const SystemIdentifier & ID )
{
    m_SystemID = ID;
}

//////////////////////////////////////////////////////////////////////////

const SystemIdentifier & IFF_ATC_NAVAIDS_L1_PDU::GetSystemIdentifier() const
{
    return m_SystemID;
}

//////////////////////////////////////////////////////////////////////////

SystemIdentifier & IFF_ATC_NAVAIDS_L1_PDU::GetSystemIdentifier()
{
    return m_SystemID;
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_L1_PDU::SetFundamentalOperationalData( const FundamentalOperationalData & FOD )
{
    m_FOD = FOD;
}

//////////////////////////////////////////////////////////////////////////

const FundamentalOperationalData & IFF_ATC_NAVAIDS_L1_PDU::GetFundamentalOperationalData() const
{
    return m_FOD;
}

//////////////////////////////////////////////////////////////////////////

FundamentalOperationalData & IFF_ATC_NAVAIDS_L1_PDU::GetFundamentalOperationalData()
{
    return m_FOD;
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_L1_PDU::SetSystemDesignator ( KUINT8 SD )
{
	m_ui8SystemDesignator = SD;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 IFF_ATC_NAVAIDS_L1_PDU::GetSystemDesignator() const
{
	return m_ui8SystemDesignator;
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_L1_PDU::SetSystemSpecificData ( KUINT8 SSD )
{
	m_ui8SystemSpecific = SSD;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 IFF_ATC_NAVAIDS_L1_PDU::GetSystemSpecificData() const
{
	return m_ui8SystemSpecific;
}

//////////////////////////////////////////////////////////////////////////

KString IFF_ATC_NAVAIDS_L1_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-IFF/ATC/NAVAIDS Layer 1 PDU-\n"
       << "Emitting Entity ID:\n"
       << IndentString( m_EmittingEntityID.GetAsString(), 1 )
       << "Event ID:\n"
       << IndentString( m_EventID.GetAsString(), 1 )
       << "Location:    " << m_Location.GetAsString()
       << m_SystemID.GetAsString()
       << m_FOD.GetAsString();

	#if DIS_VERSION > 6

	ss << "System Designator:    " << ( KUINT16 )m_ui8SystemDesignator << "\n"
	   << "System Specific Data: " << ( KUINT16 )m_ui8SystemSpecific << "\n";

	#endif

    return ss.str();	
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_L1_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < IFF_ATC_NAVAIDS_L1_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_EmittingEntityID
           >> KDIS_STREAM m_EventID
           >> KDIS_STREAM m_Location
           >> KDIS_STREAM m_SystemID
           >> m_ui8SystemDesignator
		   >> m_ui8SystemSpecific
           >> KDIS_STREAM m_FOD;
}

//////////////////////////////////////////////////////////////////////////

KDataStream IFF_ATC_NAVAIDS_L1_PDU::Encode() const
{
    KDataStream stream;

    IFF_ATC_NAVAIDS_L1_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_L1_PDU::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );

    stream << KDIS_STREAM m_EmittingEntityID
           << KDIS_STREAM m_EventID
           << KDIS_STREAM m_Location
           << KDIS_STREAM m_SystemID
           << m_ui8SystemDesignator
		   << m_ui8SystemSpecific
           << KDIS_STREAM m_FOD;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_ATC_NAVAIDS_L1_PDU::operator == ( const IFF_ATC_NAVAIDS_L1_PDU & Value ) const
{
    if( Header::operator    !=( Value ) )                 return false;
    if( m_EmittingEntityID  != Value.m_EmittingEntityID ) return false;
    if( m_EventID           != Value.m_EventID )          return false;
    if( m_Location          != Value.m_Location )         return false;
    if( m_SystemID          != Value.m_SystemID )         return false;
    if( m_FOD               != Value.m_FOD )              return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_ATC_NAVAIDS_L1_PDU::operator != ( const IFF_ATC_NAVAIDS_L1_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

