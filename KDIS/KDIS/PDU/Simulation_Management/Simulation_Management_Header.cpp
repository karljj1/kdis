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

#include "./Simulation_Management_Header.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Simulation_Management_Header::Simulation_Management_Header( void )
{
    m_ui8ProtocolFamily = Simulation_Management;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Simulation_Management_Header::Simulation_Management_Header( KDataStream & stream ) throw( KException )
{
    try
    {
        Decode( stream );
    }
    catch ( KException & e )
    {
        throw e;
    }
}

//////////////////////////////////////////////////////////////////////////

Simulation_Management_Header::Simulation_Management_Header( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID ) :
    m_OriginatingEntityID( OriginatingEntityID ),
    m_ReceivingEntityID( ReceivingEntityID )
{
    m_ui8ProtocolFamily = Simulation_Management;
    m_ui8ProtocolVersion = IEEE_1278_1_1995;
}

//////////////////////////////////////////////////////////////////////////

Simulation_Management_Header::~Simulation_Management_Header( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Simulation_Management_Header::SetOriginatingEntityID( const EntityIdentifier & ID )
{
    m_OriginatingEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Simulation_Management_Header::GetOriginatingEntityID() const
{
    return m_OriginatingEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Simulation_Management_Header::GetOriginatingEntityID()
{
    return m_OriginatingEntityID;
}

//////////////////////////////////////////////////////////////////////////

void Simulation_Management_Header::SetReceivingEntityID( const EntityIdentifier & ID )
{
    m_ReceivingEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Simulation_Management_Header::GetReceivingEntityID() const
{
    return m_ReceivingEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Simulation_Management_Header::GetReceivingEntityID()
{
    return m_ReceivingEntityID;
}

//////////////////////////////////////////////////////////////////////////

KString Simulation_Management_Header::GetAsString() const
{
    KStringStream ss;

    ss << "Originating Entity ID:\n"
       << IndentString( m_OriginatingEntityID.GetAsString(), 1 )
       << "Receiving Entity ID:\n"
       << IndentString( m_ReceivingEntityID.GetAsString(), 1 );

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Simulation_Management_Header::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < SIMULATION_MANAGEMENT_HEADER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream );

    stream >> KDIS_STREAM m_OriginatingEntityID
           >> KDIS_STREAM m_ReceivingEntityID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Simulation_Management_Header::Encode() const
{
    KDataStream stream;

    Simulation_Management_Header::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Simulation_Management_Header::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );
    stream << KDIS_STREAM m_OriginatingEntityID
           << KDIS_STREAM m_ReceivingEntityID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Simulation_Management_Header::operator == ( const Simulation_Management_Header & Value ) const
{
    if( Header::operator        !=( Value ) )                    return false;
    if( m_OriginatingEntityID   != Value.m_OriginatingEntityID ) return false;
    if( m_ReceivingEntityID     != Value.m_ReceivingEntityID )   return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Simulation_Management_Header::operator != ( const Simulation_Management_Header & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
