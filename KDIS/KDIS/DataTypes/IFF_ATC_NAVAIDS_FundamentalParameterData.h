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
    class:      IFF_ATC_NAVAIDS_FundamentalParameterData
    created:    2009/03/27
    author:     Karl Jones

    purpose:    Specifies the fundamental energy radiation characteristics of an
                IFF/ATC/NAVAIDS system emission.

    size:       192 bits / 24 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT IFF_ATC_NAVAIDS_FundamentalParameterData : public DataTypeBase
{
protected:

    KFLOAT32 m_f32ERP;

    KFLOAT32 m_f32Freq;

    KFLOAT32 m_f32PgRF;

    KFLOAT32 m_f32PulseWidth;

    KUINT32 m_ui32BurstLength;

    KUINT8 m_ui8AppMode;

    KUINT16 m_ui16Padding1;

    KUINT8 m_ui8Padding2;

public:

    static const KUINT16 IFF_ATC_NAVAIDS_FUNDAMENTAL_PARAMETER_SIZE = 24;

    IFF_ATC_NAVAIDS_FundamentalParameterData();

    IFF_ATC_NAVAIDS_FundamentalParameterData( KDataStream & stream )throw( KException );

    IFF_ATC_NAVAIDS_FundamentalParameterData( KFLOAT32 ERP, KFLOAT32 Freq, KFLOAT32 PgRF, KFLOAT32 PulseWidth,
                                              KUINT32 BurstLength, DATA_TYPE::ENUMS::SystemMode M );

    virtual ~IFF_ATC_NAVAIDS_FundamentalParameterData();

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::SetEffectiveRadiatedPower
    //              KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::GetEffectiveRadiatedPower
    // Description: Average peak radiated power for the emission in dBm.
    // Parameter:   KFLOAT32 F
    //************************************
    void SetEffectiveRadiatedPower( KFLOAT32 ERP );
    KFLOAT32 GetEffectiveRadiatedPower() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::SetFrequency
    //              KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::GetFrequency
    // Description: In Hertz.
    // Parameter:   KFLOAT32 F
    //************************************
    void SetFrequency( KFLOAT32 F );
    KFLOAT32 GetFrequency() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::SetPgRF
    //              KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::GetPgRF
    // Description: When applied to originators this field shall represent the number
    //              of interrogations per second emitted otherwid this value shall be zero.
    // Parameter:   KFLOAT32 P
    //************************************
    void SetPgRF( KFLOAT32 P );
    KFLOAT32 GetPgRF() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::SetPulseWidth
    //              KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::GetPulseWidth
    // Description: Average pulse width of the emission in microseconds.
    // Parameter:   KFLOAT32 PW
    //************************************
    void SetPulseWidth( KFLOAT32 PW );
    KFLOAT32 GetPulseWidth() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::SetBurstLength
    //              KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::GetBurstLength
    // Description:
    // Parameter:   KUINT32 BL
    //************************************
    void SetBurstLength( KUINT32 BL );
    KUINT32 GetBurstLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::SetApplicableModes
    //              KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::GetApplicableModes
    // Description: Specifies the modes to which the data applies.
    // Parameter:   SystemMode M
    //************************************
    void SetApplicableModes( DATA_TYPE::ENUMS::SystemMode M );
    DATA_TYPE::ENUMS::SystemMode GetApplicableModes() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const IFF_ATC_NAVAIDS_FundamentalParameterData & Value ) const;
    KBOOL operator != ( const IFF_ATC_NAVAIDS_FundamentalParameterData & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
