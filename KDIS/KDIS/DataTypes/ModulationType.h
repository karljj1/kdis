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
    class:      ModulationType
    created:    2008/10/21
    author:     Karl Jones

    purpose:    Contains information about the type of modulation used for
                a radio transmission.
    size:       64 bits / 8 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::RadioMajorModulation;
using KDIS::DATA_TYPE::ENUMS::ModulationSystem;
using KDIS::DATA_TYPE::ENUMS::DetailAmplitude;
using KDIS::DATA_TYPE::ENUMS::DetailAmplitudeAndAngle;
using KDIS::DATA_TYPE::ENUMS::DetailAngle;
using KDIS::DATA_TYPE::ENUMS::DetailCombination;
using KDIS::DATA_TYPE::ENUMS::DetailPulse;
using KDIS::DATA_TYPE::ENUMS::DetailUnmodulated;
using KDIS::DATA_TYPE::ENUMS::DetailCarrierPhaseShift;

class KDIS_EXPORT ModulationType :  public DataTypeBase
{
protected:

    union
    {
        struct
        {
            KUINT16 m_ui16FreqHop       : 1;
            KUINT16 m_ui16PseudoNoise   : 1;
            KUINT16 m_ui16TimeHop       : 1;
            // Bits 3 - 15 TBD
        };
        KUINT16 m_ui16SpreadSpectrum;
    };

    KUINT16 m_ui16MajorModulationType;

    KUINT16 m_ui16Detail;

    KUINT16 m_ui16System;

public:

    static const KUINT16 MODULATION_TYPE_SIZE = 8;

    ModulationType( void );

    ModulationType( KDataStream & stream )throw( KException );

    ModulationType( KBOOL FreqHop, KBOOL PseudoNoise, KBOOL TimeHop,
                    KUINT16 MajorModulation, KUINT16 Detail,
                    KUINT16 System );

    virtual ~ModulationType( void );

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
    RadioMajorModulation GetMajorModulation() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModulationType::GetMajorModulation
    // Description: Determines major modulation param.
    //              Provides details information.
    // Parameter:   <various>
    //************************************
    void SetDetail( DetailAmplitude A );
    void SetDetail( DetailAmplitudeAndAngle AA );
    void SetDetail( DetailAngle A );
    void SetDetail( DetailCombination C );
    void SetDetail( DetailPulse P );
    void SetDetail( DetailUnmodulated U );
    void SetDetail( DetailCarrierPhaseShift CPS );
    KUINT16 GetDetail() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModulationType::SetSystem
    //              KDIS::DATA_TYPE::ModulationType::GetSystem
    // Description: Specifies the interpretation of the
    //              modulation parameter field(s).
    // Parameter:   ModulationSystem S, void
    //************************************
    void SetSystem( ModulationSystem S );
    ModulationSystem GetSystem() const;

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS
