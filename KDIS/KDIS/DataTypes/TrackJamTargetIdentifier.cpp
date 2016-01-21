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

#include "./TrackJamTargetIdentifier.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

TrackJamTargetIdentifier::TrackJamTargetIdentifier() :
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

TrackJamTargetIdentifier::~TrackJamTargetIdentifier()
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

    ss << "Site:        " << m_ui16SiteID              << "\n"
       << "Application: " << m_ui16ApplicationID       << "\n"
       << "Entity:      " << m_ui16EntityID            << "\n"
       << "Emitter ID:  " << ( KUINT16 )m_ui8EmitterID << "\n"
       << "Beam ID:     " << ( KUINT16 )m_ui8BeamID    << "\n";

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
