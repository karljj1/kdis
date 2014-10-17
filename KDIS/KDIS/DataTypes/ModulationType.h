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
    class:      ModulationType
    created:    21/10/2008
    author:     Karl Jones

    purpose:    Contains information about the type of modulation used for
                a radio transmission.
    size:       64 bits / 8 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT ModulationType :  public DataTypeBase
{
protected:

    union
    {
        struct
        {
            KUINT16 m_ui16FreqHop     : 1;
            KUINT16 m_ui16PseudoNoise : 1;
            KUINT16 m_ui16TimeHop     : 1;
            // Bits 3 - 15 TBD
        };
        KUINT16 m_ui16SpreadSpectrum;
    };

    KUINT16 m_ui16MajorModulationType;

    KUINT16 m_ui16Detail;

    KUINT16 m_ui16System;

public:

    static const KUINT16 MODULATION_TYPE_SIZE = 8;

    ModulationType();

    ModulationType( KDataStream & stream )throw( KException );

    ModulationType( KBOOL FreqHop, KBOOL PseudoNoise, KBOOL TimeHop,
                    KUINT16 MajorModulation, KUINT16 Detail,
                    KUINT16 System );

    virtual ~ModulationType();

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModulationType::SetSpreadSpectrum
    //              KDIS::DATA_TYPE::ModulationType::GetSpreadSpectrum
    // Description: Spread Spectrum Boolean array.
    // Parameter:   KUINT16 SS, void
    //************************************
    void SetSpreadSpectrum( KUINT16 SS );
    KUINT16 GetSpreadSpectrum() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModulationType::SetFrequencyHop
    //              KDIS::DATA_TYPE::ModulationType::GetFrequencyHop
    // Description: Spread Spectrum Boolean array value 0.
    // Parameter:   KBOOL FH, void
    //************************************
    void SetFrequencyHop( KBOOL FH );
    KBOOL GetFrequencyHop() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModulationType::SetPseudoNoise
    //              KDIS::DATA_TYPE::ModulationType::GetPseudoNoise
    // Description: Spread Spectrum Boolean array value 1.
    // Parameter:   KBOOL PN, void
    //************************************
    void SetPseudoNoise( KBOOL PN );
    KBOOL GetPseudoNoise() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModulationType::SetTimeHop
    //              KDIS::DATA_TYPE::ModulationType::GetTimeHop
    // Description: Spread Spectrum Boolean array value 2.
    // Parameter:   KBOOL TH, void
    //************************************
    void SetTimeHop( KBOOL TH );
    KBOOL GetTimeHop() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModulationType::GetMajorModulation
    // Description: Major classification of the modulation type.
    //              Note: This value is set automatically from the SetDetails function.
    //************************************
    KDIS::DATA_TYPE::ENUMS::RadioMajorModulation GetMajorModulation() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModulationType::GetMajorModulation
    // Description: Determines major modulation param.
    //              Provides details information.
    // Parameter:   <various>
    //************************************
    void SetDetail( KDIS::DATA_TYPE::ENUMS::DetailAmplitude A );
    void SetDetail( KDIS::DATA_TYPE::ENUMS::DetailAmplitudeAndAngle AA );
    void SetDetail( KDIS::DATA_TYPE::ENUMS::DetailAngle A );
    void SetDetail( KDIS::DATA_TYPE::ENUMS::DetailCombination C );
    void SetDetail( KDIS::DATA_TYPE::ENUMS::DetailPulse P );
    void SetDetail( KDIS::DATA_TYPE::ENUMS::DetailUnmodulated U );
    void SetDetail( KDIS::DATA_TYPE::ENUMS::DetailCarrierPhaseShift CPS );
    KUINT16 GetDetail() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModulationType::SetSystem
    //              KDIS::DATA_TYPE::ModulationType::GetSystem
    // Description: Specifies the interpretation of the
    //              modulation parameter field(s).
    // Parameter:   ModulationSystem S
    //************************************
    void SetSystem( KDIS::DATA_TYPE::ENUMS::ModulationSystem S );
    KDIS::DATA_TYPE::ENUMS::ModulationSystem GetSystem() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModulationType::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModulationType::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModulationType::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const ModulationType & Value ) const;
    KBOOL operator != ( const ModulationType & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
