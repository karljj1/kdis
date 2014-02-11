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
    class:      UnderwaterAcousticFundamentalParameterData
    created:    15/01/2009
    author:     Karl Jones

    purpose:    Contains regeneration parameters for active emission systems
                that are variable thoughout a scenario.
    size:       160 bits / 20 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

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

    UnderwaterAcousticFundamentalParameterData();

    UnderwaterAcousticFundamentalParameterData( KDataStream & stream )throw( KException );

    UnderwaterAcousticFundamentalParameterData( KDIS::DATA_TYPE::ENUMS::ActiveEmissionParameterIndex AEPI, KDIS::DATA_TYPE::ENUMS::ScanPattern SP, 
		                                        KFLOAT32 BeamCenterAzimuth, KFLOAT32 AzimuthalBeamwidth, KFLOAT32 BeamCenter, KFLOAT32 BeamWidth );

    virtual ~UnderwaterAcousticFundamentalParameterData();

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::SetActiveEmissionParameterIndex
    //              KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::GetActiveEmissionParameterIndex
    // Description: Indicates which database record shall be used in the definition of
    //              intentional emissions of the entity.
    // Parameter:   ActiveEmissionParameterIndex AEPI
    //************************************
    void SetActiveEmissionParameterIndex( KDIS::DATA_TYPE::ENUMS::ActiveEmissionParameterIndex AEPI );
    KDIS::DATA_TYPE::ENUMS::ActiveEmissionParameterIndex GetActiveEmissionParameterIndex() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::SetScanPattern
    //              KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::GetScanPattern
    // Description: Desscribes the UA scan pattern.
    // Parameter:   ScanPattern SP
    //************************************
    void SetScanPattern( KDIS::DATA_TYPE::ENUMS::ScanPattern SP );
    KDIS::DATA_TYPE::ENUMS::ScanPattern GetScanPattern() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::SetBeamCenterAzimuth
    //              KDIS::DATA_TYPE::UnderwaterAcousticFundamentalParameterData::GetBeamCenterAzimuth
    // Description: Beam center azimuth(Horizontal bearing). Specifies the center azimuthal bearing of the main
    //              beam(as opposed to sidelobes) in relation to the emitter coordinate system.
    //              The azimuth center for 360 degrees bearing shall be 0. Omnidirectional beams shall have
    //              the value 0.
    //              Represented as radians.
    // Parameter:   KFLOAT32 BCA
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
    // Parameter:   KFLOAT32 AB
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
    // Parameter:   KFLOAT32 BC
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
    // Parameter:   KFLOAT32 BC
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

} // END namespace DATA_TYPES
} // END namespace KDIS
