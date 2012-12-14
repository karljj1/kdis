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

using KDIS::DATA_TYPE::ENUMS::IOStatus;
using KDIS::DATA_TYPE::ENUMS::IOLinkType;
using KDIS::DATA_TYPE::ENUMS::IOEffectType;

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

    IOEffect( IOStatus S, IOLinkType LT, IOEffectType ET, KUINT8 DutyCycle,
              KUINT16 Duration, KUINT16 Process ) throw( KException );

    IOEffect( void );

    IOEffect( KDataStream & stream ) throw( KException );

    virtual ~IOEffect( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::IOEffect::SetStatus
    //              KDIS::DATA_TYPE::IOEffect::GetStatus
    // Description: Indicates whether the IO effect has an effect on the sender,
    //              receiver, message(s) or some combination of them.
    // Parameter:   IOStatus S
    //************************************
    void SetStatus( IOStatus S );
    IOStatus GetStatus() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IOEffect::SetLinkType
    //              KDIS::DATA_TYPE::IOEffect::GetLinkType
    // Description: The IO link type as a logical or physical link or node.
    // Parameter:   IOLinkType LT
    //************************************
    void SetLinkType( IOLinkType LT );
    IOLinkType GetLinkType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IOEffect::SetEffectType
    //              KDIS::DATA_TYPE::IOEffect::GetEffectType
    // Description: The IO effect associated with this IO attack.
    // Parameter:   IOEffectType ET
    //************************************
    void SetEffectType( IOEffectType ET );
    IOEffectType GetEffectType() const;

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS
