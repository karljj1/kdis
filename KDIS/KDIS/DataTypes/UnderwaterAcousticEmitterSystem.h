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
    class:      UnderwaterAcousticEmitterSystem
    created:    2009/01/06
    author:     Karl Jones

    purpose:    Contains infomation about a particular Underwater Acoustic emitter
    size:       160 bits / 20 octets - min size
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./AcousticEmitterSystem.h"
#include "./Vector.h"
#include "./UnderwaterAcousticEmitterBeam.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT UnderwaterAcousticEmitterSystem : public DataTypeBase
{
protected:

    KUINT8 m_ui8EmitterSystemDataLength;

    KUINT8 m_ui8NumBeams;

    KUINT16 m_ui16Padding1;

    AcousticEmitterSystem m_AES;

    Vector m_Location;

    std::vector<UnderwaterAcousticEmitterBeam> m_vUAEB;

public:

    static const KUINT16 UNDERWATER_ACOUSTIC_EMITTER_SYSTEM_SIZE = 20; // Min Size

    UnderwaterAcousticEmitterSystem();

    UnderwaterAcousticEmitterSystem( KDataStream & stream ) throw( KException );

    virtual ~UnderwaterAcousticEmitterSystem();

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::GetEmitterSystemDataLength
    // Description: Length of the emitter system in 32 bits words.
    //************************************
    KUINT8 GetEmitterSystemDataLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::GetNumberOfBeams
    // Description: Returns number of beams for the current system
    //************************************
    KUINT8 GetNumberOfBeams() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::SetAcousticEmitterSystem
    //              KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::GetAcousticEmitterSystem
    // Description: Holds infomation about a particular Underwater Acoustic emitter.
    // Parameter:   const AcousticEmitterSystem & AES
    //************************************
    void SetAcousticEmitterSystem( const AcousticEmitterSystem & AES );
    const AcousticEmitterSystem & GetAcousticEmitterSystem() const;
    AcousticEmitterSystem & GetAcousticEmitterSystem();

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::SetLocation
    //              KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::GetLocation
    // Description: Location of the acoustic source with respect to emitting
    //              entity coordinate system. Represented as Entity Coordinate Vector.
    // Parameter:   const Vector & L
    //************************************
    void SetLocation( const Vector & L );
    const Vector & GetLocation() const;
    Vector & GetLocation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::AddUnderwaterAcousticEmitterBeam
    //              KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::SetUnderwaterAcousticEmitterBeam
    //              KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::GetUnderwaterAcousticEmitterBeam
    //              KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::ClearUnderwaterAcousticEmitterBeams
    // Description: Add a articulation parameter / Get vector or params
    //              Adding will update the Number Of Variable Params
    //              field.
    // Parameter:   const UnderwaterAcousticEmitterBeam & UAEB
    //************************************
    void AddUnderwaterAcousticEmitterBeam( const UnderwaterAcousticEmitterBeam & UAEB );
    void SetUnderwaterAcousticEmitterBeams( const std::vector<UnderwaterAcousticEmitterBeam> & UAEB );
    const std::vector<UnderwaterAcousticEmitterBeam> & GetUnderwaterAcousticEmitterBeam() const;
    void ClearUnderwaterAcousticEmitterBeams();

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const UnderwaterAcousticEmitterSystem & Value ) const;
    KBOOL operator != ( const UnderwaterAcousticEmitterSystem & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

