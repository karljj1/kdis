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
    class:      IOEffect
    created:    05/12/2010
    author:     Karl Jones

    purpose:    Identification of IO effects on an entity when calculated by an IO simulation.
    size:       128 bits / 16 octets
*********************************************************************/

#pragma once

#include "./StandardVariable.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT IOEffect : public StandardVariable
{
protected:

    KUINT8 m_ui8Status;

    KUINT8 m_ui8LnkTyp;

    KUINT8 m_ui8Eff;

    KUINT8 m_ui8EffDtyCyc;

    KUINT16 m_ui16EffDur;

    KUINT16 m_ui16Proc;

    KUINT16 m_ui16Padding;

public:

    static const KUINT16 IO_EFFECT_TYPE_SIZE = 16;

    IOEffect( KDIS::DATA_TYPE::ENUMS::IOStatus S, KDIS::DATA_TYPE::ENUMS::IOLinkType LT, KDIS::DATA_TYPE::ENUMS::IOEffectType ET, 
		      KUINT8 DutyCycle, KUINT16 Duration, KUINT16 Process ) throw( KException );

    IOEffect();

    IOEffect( KDataStream & stream ) throw( KException );

    virtual ~IOEffect();

    //************************************
    // FullName:    KDIS::DATA_TYPE::IOEffect::SetStatus
    //              KDIS::DATA_TYPE::IOEffect::GetStatus
    // Description: Indicates whether the IO effect has an effect on the sender,
    //              receiver, message(s) or some combination of them.
    // Parameter:   IOStatus S
    //************************************
    void SetStatus( KDIS::DATA_TYPE::ENUMS::IOStatus S );
    KDIS::DATA_TYPE::ENUMS::IOStatus GetStatus() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IOEffect::SetLinkType
    //              KDIS::DATA_TYPE::IOEffect::GetLinkType
    // Description: The IO link type as a logical or physical link or node.
    // Parameter:   IOLinkType LT
    //************************************
    void SetLinkType( KDIS::DATA_TYPE::ENUMS::IOLinkType LT );
    KDIS::DATA_TYPE::ENUMS::IOLinkType GetLinkType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IOEffect::SetEffectType
    //              KDIS::DATA_TYPE::IOEffect::GetEffectType
    // Description: The IO effect associated with this IO attack.
    // Parameter:   IOEffectType ET
    //************************************
    void SetEffectType( KDIS::DATA_TYPE::ENUMS::IOEffectType ET );
    KDIS::DATA_TYPE::ENUMS::IOEffectType GetEffectType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IOEffect::SetEffectDutyCycle
    //              KDIS::DATA_TYPE::IOEffect::GetEffectDutyCycle
    // Description: The IO effect duty cycle represented as a percentage in
    //              the range of 0 - 100% in one-percent increments.
    //              Throws OUT_OF_BOUNDS exception if value is > 100.
    // Parameter:   KUINT8 EDC
    //************************************
    void SetEffectDutyCycle( KUINT8 EDC ) throw( KException );
    KUINT8 GetEffectDutyCycle() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IOEffect::SetEffectDuration
    //              KDIS::DATA_TYPE::IOEffect::GetEffectDuration
    // Description: Indicates the duration of the IO effect in seconds, from 1
    //              to 65534 seconds.
    //              It shall be set to indicate UNTIL_FURTHER_NOTICE (65535) if
    //              the duration has no fixed amount of time.
    //              It shall be set to zero only if the IO Effect field is set
    //              to Terminate Effect(255).
    // Parameter:   KUINT16 ED
    //************************************
    void SetEffectDuration( KUINT16 ED );
    KUINT16 GetEffectDuration() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IOEffect::SetProcess
    //              KDIS::DATA_TYPE::IOEffect::GetProcess
    // Description: The IO process being performed.
    // Parameter:   KUINT16 P
    //************************************
    void SetProcess( KUINT16 P );
    KUINT16 GetProcess() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IOEffect::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IOEffect::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::IOEffect::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const IOEffect & Value ) const;
    KBOOL operator != ( const IOEffect & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
