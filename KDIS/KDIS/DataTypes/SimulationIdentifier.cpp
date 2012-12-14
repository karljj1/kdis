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

#include "./SimulationIdentifier.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

SimulationIdentifier::SimulationIdentifier( void ) :
    m_ui16SiteID( 0 ),
    m_ui16ApplicationID( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

SimulationIdentifier::SimulationIdentifier( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

SimulationIdentifier::SimulationIdentifier( KUINT16 SiteID, KUINT16 ApplicatonID ) :
    m_ui16SiteID( SiteID ),
    m_ui16ApplicationID( ApplicatonID )
{
}

//////////////////////////////////////////////////////////////////////////

SimulationIdentifier::~SimulationIdentifier( void )
{
}

//////////////////////////////////////////////////////////////////////////

void SimulationIdentifier::SetSiteID( KUINT16 ID )
{
    m_ui16SiteID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 SimulationIdentifier::GetSiteID() const
{
    return m_ui16SiteID;
}

//////////////////////////////////////////////////////////////////////////

void SimulationIdentifier::SetApplicationID( KUINT16 ID )
{
    m_ui16ApplicationID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 SimulationIdentifier::GetApplicationID() const
{
    return m_ui16ApplicationID;
}

//////////////////////////////////////////////////////////////////////////

KString SimulationIdentifier::GetAsString() const
{
    KStringStream ss;

    ss << "Site:        " << m_ui16SiteID           << "\n"
       << "Application: " << m_ui16ApplicationID    << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void SimulationIdentifier::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < SIMULATION_IDENTIFIER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16SiteID
           >> m_ui16ApplicationID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream SimulationIdentifier::Encode() const
{
    KDataStream stream;

    SimulationIdentifier::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void SimulationIdentifier::Encode( KDataStream & stream ) const
{
    stream << m_ui16SiteID
           << m_ui16ApplicationID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SimulationIdentifier::operator == ( const SimulationIdentifier & Value ) const
{
    if( m_ui16SiteID        != Value.m_ui16SiteID )         return false;
    if( m_ui16ApplicationID != Value.m_ui16ApplicationID )  return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SimulationIdentifier::operator != ( const SimulationIdentifier & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

KBOOL SimulationIdentifier::operator <  ( const SimulationIdentifier & Value ) const
{
    // We will bit shift all fields into a single KUINT64, this will generate a new unique value which we can then use for comparison.
    // bits 0-15  = SiteID
    // bits 16-31 = ApplicationID
    // bits 32-63 = 0
    KUINT64 ui64ThisCmpVal = 0, ui64OtherCmpVal = 0;

    ui64ThisCmpVal = m_ui16SiteID | ( KUINT64 )m_ui16ApplicationID << 16;
    ui64OtherCmpVal = Value.m_ui16SiteID | ( KUINT64 )Value.m_ui16ApplicationID << 16;

    return ui64ThisCmpVal < ui64OtherCmpVal;
}

//////////////////////////////////////////////////////////////////////////
