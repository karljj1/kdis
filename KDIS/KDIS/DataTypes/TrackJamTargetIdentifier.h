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

/********************************************************************
    class:      TrackJamTargetIdentifier
    created:    19/10/2008
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

    TrackJamTargetIdentifier();

    TrackJamTargetIdentifier( KDataStream & stream )throw( KException );

    TrackJamTargetIdentifier( const EntityIdentifier & EntityID );

    TrackJamTargetIdentifier( KUINT16 SiteID, KUINT16 ApplicatonID, KUINT16 EntityID,
                              KUINT8 EmitterID = 0, KUINT8 BeamID = 0 );

    virtual ~TrackJamTargetIdentifier();

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

} // END namespace DATA_TYPES
} // END namespace KDIS
