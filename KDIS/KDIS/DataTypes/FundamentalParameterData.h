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
    class:      FundamentalParameterData
    created:    2008/10/19
    author:     Karl Jones

    purpose:    Contains electromagnetic emission regeneration parameters that
                are variable throughout a scenario.
    size:       320 bits / 40 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT FundamentalParameterData : public DataTypeBase
{
protected:

    KFLOAT32 m_f32Freq;

    KFLOAT32 m_f32FreqRange;

    KFLOAT32 m_f32EffectiveRadiatedPower;

    KFLOAT32 m_f32PulseRepetitionFreq;

    KFLOAT32 m_f32PulseWidth;

    KFLOAT32 m_f32BeamAzimuthCenter;

    KFLOAT32 m_f32BeamAzimuthSweep;

    KFLOAT32 m_f32BeamElevationCenter;

    KFLOAT32 m_f32BeamElevationSweep;

    KFLOAT32 m_f32BeamSweepSync;

public:

    static const KUINT16 FUNDAMENTAL_PARAMETER_SIZE = 40;

    FundamentalParameterData( void );

    FundamentalParameterData( KDataStream & stream )throw( KException );

    FundamentalParameterData( KFLOAT32 Freq, KFLOAT32 FreqRange, KFLOAT32 EffectiveRadiatedPower,
                              KFLOAT32 PulseRepetitionFreq,  KFLOAT32 PulseWidth, KFLOAT32 BeamAzimuthCenter,
                              KFLOAT32 BeamAzimuthSweep, KFLOAT32 BeamElevationCenter, KFLOAT32 BeamElevationSweep,
                              KFLOAT32 BeamSweepSync );

    virtual ~FundamentalParameterData( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalParameterData::SetFrequency
    //              KDIS::DATA_TYPE::FundamentalParameterData::GetFrequency
    // Description: Hertz
    // Parameter:   KFLOAT32 F, void
    //************************************
    void SetFrequency( KFLOAT32 F );
    KFLOAT32 GetFrequency() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalParameterData::SetFrequencyRange
    //              KDIS::DATA_TYPE::FundamentalParameterData::GetFrequencyRange
    // Description: Bandwidth range of frequencies, if a single frequency then set to 0.
    // Parameter:   KFLOAT32 F, void
    //************************************
    void SetFrequencyRange( KFLOAT32 FR );
    KFLOAT32 GetFrequencyRange() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalParameterData::SetEffectiveRadiatedPower
    //              KDIS::DATA_TYPE::FundamentalParameterData::GetEffectiveRadiatedPower
    // Description: Average peak radiated power in dBm.
    // Parameter:   KFLOAT32 F, void
    //************************************
    void SetEffectiveRadiatedPower( KFLOAT32 ERP );
    KFLOAT32 GetEffectiveRadiatedPower() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalParameterData::SetPulseRepetitionFrequency
    //              KDIS::DATA_TYPE::FundamentalParameterData::GetPulseRepetitionFrequency
    // Description: Hertz
    // Parameter:   KFLOAT32 F, void
    //************************************
    void SetPulseRepetitionFrequency( KFLOAT32 PRF );
    KFLOAT32 GetPulseRepetitionFrequency() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalParameterData::SetPulseWidth
    //              KDIS::DATA_TYPE::FundamentalParameterData::GetPulseWidth
    // Description: Average pulse width of the emission in microseconds.
    // Parameter:   KFLOAT32 F, void
    //************************************
    void SetPulseWidth( KFLOAT32 PW );
    KFLOAT32 GetPulseWidth() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalParameterData::SetBeamAzimuthCenter
    //              KDIS::DATA_TYPE::FundamentalParameterData::GetBeamAzimuthCenter
    // Description: If coverage is a full 360 degrees then set to 0. In radians.
    // Parameter:   KFLOAT32 F, void
    //************************************
    void SetBeamAzimuthCenter( KFLOAT32 BAC );
    KFLOAT32 GetBeamAzimuthCenter() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalParameterData::SetBeamAzimuthSweep
    //              KDIS::DATA_TYPE::FundamentalParameterData::GetBeamAzimuthSweep
    // Description: If coverage is a full 360 degrees then set to 0. In radians.
    // Parameter:   KFLOAT32 F, void
    //************************************
    void SetBeamAzimuthSweep( KFLOAT32 BAS );
    KFLOAT32 GetBeamAzimuthSweep() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalParameterData::SetBeamElevationCenter
    //              KDIS::DATA_TYPE::FundamentalParameterData::GetBeamElevationCenter
    // Description: If coverage is a full 360 degrees then set to 0. In radians.
    // Parameter:   KFLOAT32 F, void
    //************************************
    void SetBeamElevationCenter( KFLOAT32 BEC );
    KFLOAT32 GetBeamElevationCenter() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalParameterData::SetBeamElevationSweep
    //              KDIS::DATA_TYPE::FundamentalParameterData::GetBeamElevationSweep
    // Description: If coverage is a full 360 degrees then set to 0. In radians.
    // Parameter:   KFLOAT32 F, void
    //************************************
    void SetBeamElevationSweep( KFLOAT32 BES );
    KFLOAT32 GetBeamElevationSweep() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalParameterData::SetBeamSweepSync
    //              KDIS::DATA_TYPE::FundamentalParameterData::GetBeamSweepSync
    // Description: Used to allow a receiver to synchronize its regenerated scan pattern
    //              to that of the emitter. Specifies the percentage of time a scan is through
    //              its pattern from its origin.
    // Parameter:   KFLOAT32 F, void
    //************************************
    void SetBeamSweepSync( KFLOAT32 BSS );
    KFLOAT32 GetBeamSweepSync() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalParameterData::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalParameterData::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalParameterData::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const FundamentalParameterData & Value ) const;
    KBOOL operator != ( const FundamentalParameterData & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
