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

using DATA_TYPE::ENUMS::SystemMode;

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

    static const KUINT16 IFF_ATC_NAVAIDS_FUNDAMENTAL_PARAMETER_SIZE = 40;

    IFF_ATC_NAVAIDS_FundamentalParameterData( void );

    IFF_ATC_NAVAIDS_FundamentalParameterData( KDataStream & stream )throw( KException );

    IFF_ATC_NAVAIDS_FundamentalParameterData( KFLOAT32 ERP, KFLOAT32 Freq, KFLOAT32 PgRF, KFLOAT32 PulseWidth,
            KUINT32 BurstLength, SystemMode M );

    virtual ~IFF_ATC_NAVAIDS_FundamentalParameterData( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::SetEffectiveRadiatedPower
    //              KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::GetEffectiveRadiatedPower
    // Description: Average peak radiated power for the emission in dBm.
    // Parameter:   KFLOAT32 F, void
    //************************************
    void SetEffectiveRadiatedPower( KFLOAT32 ERP );
    KFLOAT32 GetEffectiveRadiatedPower() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::SetFrequency
    //              KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::GetFrequency
    // Description: In Hertz.
    // Parameter:   KFLOAT32 F, void
    //************************************
    void SetFrequency( KFLOAT32 F );
    KFLOAT32 GetFrequency() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::SetPgRF
    //              KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::GetPgRF
    // Description: When applied to originators this field shall represent the number
    //              of interrogations per second emitted otherwid this value shall be zero.
    // Parameter:   KFLOAT32 P, void
    //************************************
    void SetPgRF( KFLOAT32 P );
    KFLOAT32 GetPgRF() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::SetPulseWidth
    //              KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::GetPulseWidth
    // Description: Average pulse width of the emission in microseconds.
    // Parameter:   KFLOAT32 PW, void
    //************************************
    void SetPulseWidth( KFLOAT32 PW );
    KFLOAT32 GetPulseWidth() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::SetBurstLength
    //              KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::GetBurstLength
    // Description:
    // Parameter:   KUINT32 BL, void
    //************************************
    void SetBurstLength( KUINT32 BL );
    KUINT32 GetBurstLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::SetApplicableModes
    //              KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData::GetApplicableModes
    // Description: Specifies the modes to which the data applies.
    // Parameter:   SystemMode M, void
    //************************************
    void SetApplicableModes( SystemMode M );
    SystemMode GetApplicableModes() const;

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS
