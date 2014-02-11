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
    class:      EmitterSystem
    created:    2008/09/18
    author:     Karl Jones

    purpose:    Contains information about a emitter system
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::EmitterName;
using KDIS::DATA_TYPE::ENUMS::EmitterFunction;

class KDIS_EXPORT EmitterSystem : public DataTypeBase
{
protected:

    KUINT16 m_ui16EmitterName;

    KUINT8 m_ui8Function;

    KUINT8 m_ui8EmitterIDNumber;

public:

    static const KUINT16 EMITTER_SYSTEM_SIZE = 4;

    EmitterSystem();

    EmitterSystem( KDataStream & stream )throw( KException );

    EmitterSystem( EmitterName EN, EmitterFunction F, KUINT8 ID );

    virtual ~EmitterSystem();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterSystem::SetEmitterName
    //              KDIS::DATA_TYPE::EmitterSystem::GetEmitterName
    // Description: Emitter name
    // Parameter:   EmitterName EN, void
    //************************************
    void SetEmitterName( EmitterName EN );
    EmitterName GetEmitterName() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterSystem::SetFunction
    //              KDIS::DATA_TYPE::EmitterSystem::GetFunction
    // Description: Emitter function
    // Parameter:   EmitterFunction F, void
    //************************************
    void SetFunction( EmitterFunction F );
    EmitterFunction GetFunction() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterSystem::SetEmitterID
    //              KDIS::DATA_TYPE::EmitterSystem::GetEmitterID
    // Description: ID of the emitter
    // Parameter:   KUINT8 ID, void
    //************************************
    void SetEmitterID( KUINT8 ID );
    KUINT8 GetEmitterID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterSystem::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterSystem::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterSystem::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EmitterSystem & Value ) const;
    KBOOL operator != ( const EmitterSystem & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
