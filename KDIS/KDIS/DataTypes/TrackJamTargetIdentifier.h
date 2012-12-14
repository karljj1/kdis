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

/********************************************************************
    class:      TrackJamTargetIdentifier
    created:    2008/10/19
    author:     Karl Jones

    purpose:    Contains information about a tracked/jammed target
                For a tracked target only the entity identifier is needed,
                Emitter ID and Beam ID are used for jammed targets only.
    size:       64 bits / 8 octets
*********************************************************************/

#pragma once

#include "./EntityIdentifier.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT TrackJamTargetIdentifier : public EntityIdentifier
{
protected:

    KUINT8 m_ui8EmitterID;

    KUINT8 m_ui8BeamID;

public:

    static const KUINT16 TRACK_JAM_TARGET_SIZE = 8; // Min Size

    TrackJamTargetIdentifier( void );

    TrackJamTargetIdentifier( KDataStream & stream )throw( KException );

    TrackJamTargetIdentifier( const EntityIdentifier & EntityID );

    TrackJamTargetIdentifier( KUINT16 SiteID, KUINT16 ApplicatonID, KUINT16 EntityID,
                              KUINT8 EmitterID = 0, KUINT8 BeamID = 0 );

    virtual ~TrackJamTargetIdentifier( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::TrackJamTargetIdentifier::SetEmitterID
    //              KDIS::DATA_TYPE::TrackJamTargetIdentifier::GetEmitterID
    // Description: For tracking this value is 0. For jamming represents
    //              the ID of the emitter the jamming session is
    //              is intended for.
    // Parameter:   KUINT8 ID, void
    //************************************
    void SetEmitterID( KUINT8 ID );
    KUINT8 GetEmitterID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::TrackJamTargetIdentifier::SetBeamID
    //              KDIS::DATA_TYPE::TrackJamTargetIdentifier::GetBeamID
    // Description: For tracking this value is 0. For jamming represents
    //              the ID of the beam the jamming session is
    //              is intended for.
    // Parameter:   KUINT8 ID, void
    //************************************
    void SetBeamID( KUINT8 ID );
    KUINT8 GetBeamID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::TrackJamTargetIdentifier::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::TrackJamTargetIdentifier::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::TrackJamTargetIdentifier::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const TrackJamTargetIdentifier & Value )const;
    KBOOL operator != ( const TrackJamTargetIdentifier & Value )const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
