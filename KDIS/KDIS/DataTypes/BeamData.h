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
    class:      BeamData
    created:    23/03/2009
    author:     Karl Jones

    purpose:    Contains specific infomation to describe a sensors scan volume.
    size:       160 bits / 20 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT BeamData : public DataTypeBase
{
protected:

    KFLOAT32 m_f32AziCtr;

    KFLOAT32 m_f32AziSwp;

    KFLOAT32 m_f32EleCtr;

    KFLOAT32 m_f32EleSwp;

    KFLOAT32 m_f32SwpSyn;

public:

    static const KUINT16 BEAM_DATA_SIZE = 20;

    BeamData();

    BeamData( KDataStream & stream ) throw( KException );

    BeamData( KFLOAT32 AziCtr, KFLOAT32 AziSwp, KFLOAT32 EleCtr,
              KFLOAT32 EleSwp, KFLOAT32 SwpSyn );

    virtual ~BeamData();

    //************************************
    // FullName:    KDIS::DATA_TYPE::BeamData::SetAzimuthCenter
    //              KDIS::DATA_TYPE::BeamData::GetAzimuthCenter
    // Description: Beam azimuth center angle in radians. All angles shall be measured in
    //              relation to the emitter coordinate system.
    //              The azimuth center for 360° scan systems shall be 0°.
    // Parameter:   KFLOAT32 AC
    //************************************
    void SetAzimuthCenter( KFLOAT32 AC );
    KFLOAT32 GetAzimuthCenter()const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::BeamData::SetAzimuthSweep
    //              KDIS::DATA_TYPE::BeamData::GetAzimuthSweep
    // Description: Azimuth sweep angle in radians.
    //              All angles shall be measured in
    //              relation to the emitter coordinate system.
    // Parameter:   KFLOAT32 AS
    //************************************
    void SetAzimuthSweep( KFLOAT32 AS );
    KFLOAT32 GetAzimuthSweep()const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::BeamData::SetElevationCenter
    //              KDIS::DATA_TYPE::BeamData::GetElevationCenter
    // Description: Elevation center angle in radians.
    //              All angles shall be measured in
    //              relation to the emitter coordinate system.
    // Parameter:   KFLOAT32 EC
    //************************************
    void SetElevationCenter( KFLOAT32 EC );
    KFLOAT32 GetElevationCenter()const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::BeamData::SetElevationSweep
    //              KDIS::DATA_TYPE::BeamData::GetElevationSweep
    // Description: Elevation sweep angle in radians.
    //              All angles shall be measured in
    //              relation to the emitter coordinate system.
    // Parameter:   KFLOAT32 ES
    //************************************
    void SetElevationSweep( KFLOAT32 ES );
    KFLOAT32 GetElevationSweep()const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::BeamData::SetBeamSweepSync
    //              KDIS::DATA_TYPE::BeamData::GetBeamSweepSync
    // Description: Specifies the percentage of time a scan is through its
    //              pattern from its origin. The pattern and origin data
    //              shall be derived from database parameters.
    //              Provided to allow a receiver to synchronize its regeneration
    //              scan pattern to that of the emitter.
    // Parameter:   KFLOAT32 BSS
    //************************************
    void SetBeamSweepSync( KFLOAT32 BSS );
    KFLOAT32 GetBeamSweepSync()const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::BeamData::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::BeamData::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::BeamData::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const BeamData & Value ) const;
    KBOOL operator != ( const BeamData & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

