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

#include "./TrackJamTargetIdentifier.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

TrackJamTargetIdentifier::TrackJamTargetIdentifier( void ) :
    m_ui8EmitterID( 0 ),
    m_ui8BeamID( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

TrackJamTargetIdentifier::TrackJamTargetIdentifier( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

TrackJamTargetIdentifier::TrackJamTargetIdentifier( const EntityIdentifier & EntityID ) :
    EntityIdentifier( EntityID ),
    m_ui8EmitterID( 0 ),
    m_ui8BeamID( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

TrackJamTargetIdentifier::TrackJamTargetIdentifier( KUINT16 SiteID, KUINT16 ApplicatonID, KUINT16 EntityID,
        KUINT8 EmitterID /*= 0*/, KUINT8 BeamID /*= 0 */ ) :
    EntityIdentifier( SiteID, ApplicatonID, EntityID ),
    m_ui8EmitterID( EmitterID ),
    m_ui8BeamID( BeamID )
{
}

//////////////////////////////////////////////////////////////////////////

TrackJamTargetIdentifier::~TrackJamTargetIdentifier( void )
{
}

//////////////////////////////////////////////////////////////////////////

void TrackJamTargetIdentifier::SetEmitterID( KUINT8 ID )
{
    m_ui8EmitterID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 TrackJamTargetIdentifier::GetEmitterID() const
{
    return m_ui8EmitterID;
}

//////////////////////////////////////////////////////////////////////////

void TrackJamTargetIdentifier::SetBeamID( KUINT8 ID )
{
    m_ui8BeamID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 TrackJamTargetIdentifier::GetBeamID() const
{
    return m_ui8BeamID;
}

//////////////////////////////////////////////////////////////////////////

KString TrackJamTargetIdentifier::GetAsString() const
{
    KStringStream ss;

    ss << "Site:	    " << m_ui16SiteID          << "\n"
       << "Application: " << m_ui16ApplicationID    << "\n"
       << "Entity:      " << m_ui16EntityID         << "\n"
       << "Emitter ID:  " << m_ui8EmitterID         << "\n"
       << "Beam ID:     " << m_ui8BeamID            << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void TrackJamTargetIdentifier::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < TRACK_JAM_TARGET_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16SiteID
           >> m_ui16ApplicationID
           >> m_ui16EntityID
           >> m_ui8EmitterID
           >> m_ui8BeamID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream TrackJamTargetIdentifier::Encode() const
{
    KDataStream stream;

    TrackJamTargetIdentifier::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void TrackJamTargetIdentifier::Encode( KDataStream & stream ) const
{
    stream << m_ui16SiteID
           << m_ui16ApplicationID
           << m_ui16EntityID
           << m_ui8EmitterID
           << m_ui8BeamID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL TrackJamTargetIdentifier::operator == ( const TrackJamTargetIdentifier & Value ) const
{
    if( m_ui16SiteID        != Value.m_ui16SiteID )         return false;
    if( m_ui16ApplicationID != Value.m_ui16ApplicationID )  return false;
    if( m_ui16EntityID      != Value.m_ui16EntityID )       return false;
    if( m_ui8EmitterID      != Value.m_ui8EmitterID )       return false;
    if( m_ui8BeamID         != Value.m_ui8BeamID )          return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL TrackJamTargetIdentifier::operator != ( const TrackJamTargetIdentifier & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
