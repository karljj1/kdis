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

    BeamData( void );

    BeamData( KDataStream & stream ) throw( KException );

    BeamData( KFLOAT32 AziCtr, KFLOAT32 AziSwp, KFLOAT32 EleCtr,
              KFLOAT32 EleSwp, KFLOAT32 SwpSyn );

    virtual ~BeamData( void );

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS

