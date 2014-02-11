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
    class:      EmissionSystem
    created:    2008/010/19

    author:     Karl Jones

    purpose:    Contains information about a emission system
    size:       160 bits / 20 octets min size
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./EmitterSystem.h"
#include "./Vector.h"
#include "./EmitterBeam.h"
#include <vector>

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT EmissionSystem : public DataTypeBase
{
protected:

    KUINT8 m_ui8SystemDataLength;

    KUINT8 m_ui8NumberOfBeams;

    KUINT16 m_ui16Padding;

    EmitterSystem m_EmitterSystemRecord;

    Vector m_Location;

    std::vector<EmitterBeam> m_vEmitterBeams;

public:

    static const KUINT16 EMISSION_SYSTEM_SIZE = 20; // Min Size

    EmissionSystem();

    EmissionSystem( KDataStream & stream )throw( KException );

    EmissionSystem( const EmitterSystem & ESR, const Vector & Location );

    virtual ~EmissionSystem();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmissionSystem::GetSystemDataLength
    // Description: Length of the emission system in 32 bit words.
    //              E.G 1 = 32 bits / 4 octets. Calculated automatically.
    //************************************
    KUINT8 GetSystemDataLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmissionSystem::SetEmitterSystemRecord
    //              KDIS::DATA_TYPE::EmissionSystem::GetEmitterSystemRecord
    // Description: Contains information about a particular emitter system
    // Parameter:   const EmitterSystem & ESR
    //************************************
    void SetEmitterSystemRecord( const EmitterSystem & ESR );
    EmitterSystem GetEmitterSystemRecord() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmissionSystem::SetLocation
    //              KDIS::DATA_TYPE::EmissionSystem::GetLocation
    // Description: Location of antenna beam source with respect to emitting
    //              entity coordinate system. Represented as Entity Coordinate Vector.
    // Parameter:   const Vector & L
    //************************************
    void SetLocation( const Vector & L );
    const Vector & GetLocation() const;
    Vector & GetLocation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmissionSystem::AddEmitterBeam
    //              KDIS::DATA_TYPE::EmissionSystem::SetEmitterBeams
    //              KDIS::DATA_TYPE::EmissionSystem::GetEmitterBeams
    // Description: The emitter beans attached to this system.
    // Parameter:   const EmitterBeam & EB, const vector<EmitterBeam> & Beams
    //************************************
    void AddEmitterBeam( const EmitterBeam & EB );
    void SetEmitterBeams( const std::vector<EmitterBeam> & Beams );
    const std::vector<EmitterBeam> & GetEmitterBeams() const;
    void ClearEmitterBeams();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmissionSystem::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmissionSystem::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmissionSystem::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EmissionSystem & Value ) const;
    KBOOL operator != ( const EmissionSystem & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
