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

#include "./IFF_PDU.h"

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

IFF_PDU::IFF_PDU() :
    m_ui8SystemDesignator( 0 ),
	m_ui8SystemSpecific( 0 )
{
    m_ui8ProtocolFamily = Distributed_Emission_Regeneration;
    m_ui8PDUType = IFF_ATC_NAVAIDS_PDU_Type;
    m_ui16PDULength = IFF_PDU_SIZE;

	#if DIS_VERSION > 6
	m_ui8ProtocolVersion = IEEE_1278_1_2012;
	#else 
	m_ui8ProtocolVersion = IEEE_1278_1A_1998;
	#endif
}

//////////////////////////////////////////////////////////////////////////

IFF_PDU::IFF_PDU( const Header & H ) :
	Header( H ),
	m_ui8SystemDesignator( 0 ),
	m_ui8SystemSpecific( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

IFF_PDU::IFF_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

IFF_PDU::IFF_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

IFF_PDU::IFF_PDU( const EntityIdentifier & EmittingID, const EntityIdentifier & EventID, const Vector & Location,
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
    m_ui16PDULength = IFF_PDU_SIZE;

	#if DIS_VERSION > 6
	m_ui8ProtocolVersion = IEEE_1278_1_2012;
	#else 
	m_ui8ProtocolVersion = IEEE_1278_1A_1998;
	#endif
}

//////////////////////////////////////////////////////////////////////////

IFF_PDU::~IFF_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::SetEmittingEntityID( const EntityIdentifier & ID )
{
    m_EmittingEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & IFF_PDU::GetEmittingEntityID() const
{
    return m_EmittingEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & IFF_PDU::GetEmittingEntityID()
{
    return m_EmittingEntityID;
}

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::SetEventID( const EntityIdentifier & ID )
{
    m_EventID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & IFF_PDU::GetEventID() const
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & IFF_PDU::GetEventID()
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::SetLocation( const Vector & L )
{
    m_Location = L;
}

//////////////////////////////////////////////////////////////////////////

const Vector & IFF_PDU::GetLocation() const
{
    return m_Location;
}

//////////////////////////////////////////////////////////////////////////

Vector & IFF_PDU::GetLocation()
{
    return m_Location;
}

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::SetSystemIdentifier( const SystemIdentifier & ID )
{
    m_SystemID = ID;
}

//////////////////////////////////////////////////////////////////////////

const SystemIdentifier & IFF_PDU::GetSystemIdentifier() const
{
    return m_SystemID;
}

//////////////////////////////////////////////////////////////////////////

SystemIdentifier & IFF_PDU::GetSystemIdentifier()
{
    return m_SystemID;
}

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::SetFundamentalOperationalData( const FundamentalOperationalData & FOD )
{
    m_FOD = FOD;
}

//////////////////////////////////////////////////////////////////////////

const FundamentalOperationalData & IFF_PDU::GetFundamentalOperationalData() const
{
    return m_FOD;
}

//////////////////////////////////////////////////////////////////////////

FundamentalOperationalData & IFF_PDU::GetFundamentalOperationalData()
{
    return m_FOD;
}

//////////////////////////////////////////////////////////////////////////

#if DIS_VERSION > 6

void IFF_PDU::SetSystemDesignator ( KUINT8 SD )
{
	m_ui8SystemDesignator = SD;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 IFF_PDU::GetSystemDesignator() const
{
	return m_ui8SystemDesignator;
}

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::SetSystemSpecificData ( KUINT8 SSD )
{
	m_ui8SystemSpecific = SSD;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 IFF_PDU::GetSystemSpecificData() const
{
	return m_ui8SystemSpecific;
}

#endif

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::AddLayer( const LyrHdrPtr & L )
{
	m_vLayers.push_back( L );
	m_ui16PDULength += L->GetLayerLength();
}

//////////////////////////////////////////////////////////////////////////
 
void IFF_PDU::SetLayers( const vector<LyrHdrPtr> & L )
{
	m_vLayers = L;
	m_ui16PDULength = IFF_PDU_SIZE;
	vector<LyrHdrPtr>::const_iterator citr = L.begin();
	vector<LyrHdrPtr>::const_iterator citrEnd = L.end();
	for( ; citr != citrEnd; ++citr )
	{
		m_ui16PDULength += ( *citr )->GetLayerLength();
	}
}

//////////////////////////////////////////////////////////////////////////

const std::vector<LyrHdrPtr> & IFF_PDU::GetLayers() const
{
	return m_vLayers;
}

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::ClearLayers()
{
	m_vLayers.clear();
	m_ui16PDULength = IFF_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

KString IFF_PDU::GetAsString() const
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

	vector<LyrHdrPtr>::const_iterator citr = m_vLayers.begin();
	vector<LyrHdrPtr>::const_iterator citrEnd = m_vLayers.end();
	for( ; citr != citrEnd; ++citr )
	{
		ss << ( *citr )->GetAsString();
	}

    return ss.str();	
}

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < IFF_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream, ignoreHeader );	

	// Record the size of the stream so we can calculate how much data is left. We could just use 
	// stream.GetBufferSize() but what if this PDU was part of a PDU bundle...
	KUINT32 streamSizeSnapshot = stream.GetBufferSize();

    stream >> KDIS_STREAM m_EmittingEntityID
           >> KDIS_STREAM m_EventID
           >> KDIS_STREAM m_Location
           >> KDIS_STREAM m_SystemID
           >> m_ui8SystemDesignator
		   >> m_ui8SystemSpecific
           >> KDIS_STREAM m_FOD;
	
	KUINT16 remainingData = m_ui16PDULength - HEADER6_PDU_SIZE - ( streamSizeSnapshot - stream.GetBufferSize() );
	
	// Decode each layer
	while( remainingData )
	{
		LayerHeader hdr( stream );
		LayerHeader * layer = NULL;

		switch ( hdr.GetLayerNumber() )
		{
			case 2: layer = new IFF_Layer2( hdr, stream ); break;

			#if DIS_VERSION > 6
			case 3: 
				switch( m_SystemID.GetSystemType() )
				{
					case Mark_X_XII_ATCRBS_ModeS_Transponder:
					case RRB_Transponder:
					case Soviet_Transponder:
						layer = new IFF_Layer3Transponder( hdr, stream );
						break;

					case Mark_X_XII_ATCRBS_ModeS_Interrogator:
					case Soviet_Interrogator:
						layer = new IFF_Layer3Interrogator( hdr, stream );
						break;
				}							
				break;
			#endif
			
			//case 4: layer = new IFF_Layer4( hdr, stream ); break;
			//case 5: layer = new IFF_Layer5( hdr, stream ); break;
				
			default: throw KException( __FUNCTION__, UNSUPPORTED_DATATYPE, hdr.GetLayerNumber() );						
		}

		if( layer )
		{
			m_vLayers.push_back( layer );
			remainingData -= layer->GetLayerLength();
		}
		else
		{
			throw KException( __FUNCTION__, INVALID_OPERATION, "Layer is null" );
		}
	}
}

//////////////////////////////////////////////////////////////////////////

KDataStream IFF_PDU::Encode() const
{
    KDataStream stream;

    IFF_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void IFF_PDU::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );

    stream << KDIS_STREAM m_EmittingEntityID
           << KDIS_STREAM m_EventID
           << KDIS_STREAM m_Location
           << KDIS_STREAM m_SystemID
           << m_ui8SystemDesignator
		   << m_ui8SystemSpecific
           << KDIS_STREAM m_FOD;

	vector<LyrHdrPtr>::const_iterator citr = m_vLayers.begin();
	vector<LyrHdrPtr>::const_iterator citrEnd = m_vLayers.end();
	for( ; citr != citrEnd; ++citr )
	{
		( *citr )->Encode( stream );
	}
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_PDU::operator == ( const IFF_PDU & Value ) const
{
    if( Header::operator    !=( Value ) )                 return false;
    if( m_EmittingEntityID  != Value.m_EmittingEntityID ) return false;
    if( m_EventID           != Value.m_EventID )          return false;
    if( m_Location          != Value.m_Location )         return false;
    if( m_SystemID          != Value.m_SystemID )         return false;
    if( m_FOD               != Value.m_FOD )              return false;
	if( m_vLayers           != Value.m_vLayers )          return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_PDU::operator != ( const IFF_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

