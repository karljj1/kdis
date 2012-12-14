/*********************************************************************
KDIS is free software; you can redistribute it and/or modify it under the
terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option)
any later version.

KDIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this library; if not, write to the Free Software Foundation, Inc.,
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

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

IFF_ATC_NAVAIDS_L1_PDU::IFF_ATC_NAVAIDS_L1_PDU( void ) :
    m_ui16Padding( 0 )
{
    m_ui8ProtocolFamily = Distributed_Emission_Regeneration;
    m_ui8PDUType = IFF_ATC_NAVAIDS_PDU_Type;
    m_ui16PDULength = IFF_ATC_NAVAIDS_L1_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

IFF_ATC_NAVAIDS_L1_PDU::IFF_ATC_NAVAIDS_L1_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

IFF_ATC_NAVAIDS_L1_PDU::IFF_ATC_NAVAIDS_L1_PDU( const EntityIdentifier & EmittingID, const EntityIdentifier & EventID, const Vector & Location,
        const SystemIdentifier & ID, const FundamentalOperationalData & FOD ) :
    m_EmittingEntityID( EmittingID ),
    m_EventID( EventID ),
    m_Location( Location ),
    m_SystemID( ID ),
    m_FOD( FOD ),
    m_ui16Padding( 0 )
{
    m_ui8ProtocolFamily = Distributed_Emission_Regeneration;
    m_ui8PDUType = IFF_ATC_NAVAIDS_PDU_Type;
    m_ui16PDULength = IFF_ATC_NAVAIDS_L1_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

IFF_ATC_NAVAIDS_L1_PDU::~IFF_ATC_NAVAIDS_L1_PDU( void )
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

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_L1_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < IFF_ATC_NAVAIDS_L1_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream );

    stream >> KDIS_STREAM m_EmittingEntityID
           >> KDIS_STREAM m_EventID
           >> KDIS_STREAM m_Location
           >> KDIS_STREAM m_SystemID
           >> m_ui16Padding
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
           << m_ui16Padding
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

