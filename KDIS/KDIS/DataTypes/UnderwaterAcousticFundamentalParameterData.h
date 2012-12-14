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
    class:      UnderwaterAcousticFundamentalParameterData
    created:    2009/01/15
    author:     Karl Jones

    purpose:    Contains regeneration parameters for active emission systems
                that are variable thoughout a scenario.
    size:       160 bits / 20 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::ActiveEmissionParameterIndex;
using KDIS::DATA_TYPE::ENUMS::ScanPattern;

class KDIS_EXPORT UnderwaterAcousticFundamentalParameterData : public DataTypeBase
{
protected:

    KUINT16 m_ui16AEPI;

    KUINT16 m_ui16ScanPattern;

    KFLOAT32 m_f32BeamCenterAzimuth;

    KFLOAT32 m_f32AzimuthalBeamWidth;

    KFLOAT32 m_f32BeamCenterDE;

    KFLOAT32 m_f32DEBeamwidth;

public:

    static const KUINT16 UNDERWATER_ACOUSTIC_FUNDAMENTAL_PARAMETER_SIZE_SIZE = 20;

    UnderwaterAcousticFundamentalParameterData( void );

    UnderwaterAcousticFundamentalParameterData( KDataStream & stream )throw( KException );

    UnderwaterAcousticFundamentalParameterData( ActiveEmissionParameterIndex AEPI, ScanPattern SP, KFLOAT32 BeamCenterAzimuth,
            KFLOAT32 AzimuthalBeamwidth, KFLOAT32 BeamCenter, KFLOAT32 BeamWidth );

    virtual ~UnderwaterAcousticFundamentalParameterData( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::SetActiveEmissionParameterIndex
    //              KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::GetActiveEmissionParameterIndex
    // Description: Indicates which database record shall be used in the definition of
    //              intentional emissions of the entity.
    // Parameter:   ActiveEmissionParameterIndex AEPI, void
    //************************************
    void SetActiveEmissionParameterIndex( ActiveEmissionParameterIndex AEPI );
    ActiveEmissionParameterIndex GetActiveEmissionParameterIndex() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::SetScanPattern
    //              KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::GetScanPattern
    // Description: Desscribes the UA scan pattern.
    // Parameter:   ScanPattern SP, void
    //************************************
    void SetScanPattern( ScanPattern SP );
    ScanPattern GetScanPattern() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::SetBeamCenterAzimuth
    //              KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::GetBeamCenterAzimuth
    // Description: Beam center azimuth(Horizontal bearing). Specifies the center azimuthal bearing of the main
    //              beam(as opposed to sidelobes) in relation to the emitter coordinate system.
    //              The azimuth center for 360 degrees bearing shall be 0. Omnidirectional beams shall have
    //              the value 0.
    //              Represented as radians/
    // Parameter:   KFLOAT32 BCA, void
    //************************************
    void SetBeamCenterAzimuth( KFLOAT32 BCA );
    KFLOAT32 GetBeamCenterAzimuth() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::SetAzimuthalBeamwidth
    //              KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::GetAzimuthalBeamWidth
    // Description: Azimuthal beam width(Horizontal beamwidth). Beamwidth shall be measured
    //              at the 3db down point of peak radiated power. Omnidirectional beams shall have
    //              the value 0.
    //              Represented as radians.
    // Parameter:   KFLOAT32 AB, void
    //************************************
    void SetAzimuthalBeamwidth( KFLOAT32 AB );
    KFLOAT32 GetAzimuthalBeamWidth() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::SetBeamCenter
    //              KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::GetBeamCenter
    // Description: Beam center Depression/Elevation (D/E). Specifies the center of the
    //              D/E angle of the main beam relative to the stabilized D/E angle of the target(I.E
    //              assume the target is stabilized and parrallel to the earth for determining the D/E angle).
    //              Represented as radians.
    //              A depression angle shall be defines as a downward angle and assigned a negative value.
    //              An elevation shall be defined as an upward angle and assigned a positive value.
    //              Omnidirectional beams shall have the value 0.
    // Parameter:   KFLOAT32 BC, void
    //************************************
    void SetBeamCenter( KFLOAT32 BC );
    KFLOAT32 GetBeamCenter() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::SetBeamWidth
    //              KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::GetBeamWidth
    // Description: Depression/Elevation (D/E) Beamwidth(Vertical Beamwidth).
    //              Beamwidth shall be measured at the 3db point of the peak radiated power.
    //              Represented as radians.
    //              Omnidirectional beams shall have the value 0.
    // Parameter:   KFLOAT32 BC, void
    //************************************
    void SetBeamWidth( KFLOAT32 BW );
    KFLOAT32 GetBeamWidth() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const UnderwaterAcousticFundamentalParameterData & Value ) const;
    KBOOL operator != ( const UnderwaterAcousticFundamentalParameterData & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
