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
    class:      PropulsionSystem
    created:    2009/01/15
    author:     Karl Jones

    purpose:    Contains infomation describin the propulsion system
                of the entity.
    size:       64 bits / 8 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::PowerSettingAircraft;
using KDIS::DATA_TYPE::ENUMS::PowerSettingHelicopter;
using KDIS::DATA_TYPE::ENUMS::ActiveEmissionParameterIndex;

class KDIS_EXPORT PropulsionSystem : public DataTypeBase
{
protected:

    KFLOAT32 m_f32PowerSetting;

    KFLOAT32 m_f32EngineRPM;

public:

    static const KUINT16 PROPULSION_SYSTEM_SIZE = 8;

    PropulsionSystem( void );

    PropulsionSystem( KDataStream & stream ) throw( KException );

    PropulsionSystem( KFLOAT32 PowerSetting, KFLOAT32 EngineRPM );

    virtual ~PropulsionSystem( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::PropulsionSystem::SetPowerSetting
    //              KDIS::DATA_TYPE::PropulsionSystem::GetPowerSetting
    // Description: The power settings after any response lags have been incorprated.
    // Parameter:   KFLOAT32  PS, PowerSetting PS
    //************************************
    void SetPowerSetting( KFLOAT32 PS );
    void SetPowerSetting( PowerSettingAircraft PS );
    void SetPowerSetting( PowerSettingHelicopter PS );
    void SetPowerSetting( ActiveEmissionParameterIndex PS );
    KFLOAT32 GetPowerSetting() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::PropulsionSystem::SetEngineRPM
    //              KDIS::DATA_TYPE::PropulsionSystem::GetEngineRPM
    // Description: Current engine speed in RPM
    // Parameter:   KFLOAT32 RPM, void
    //************************************
    void SetEngineRPM( KFLOAT32 RPM );
    KFLOAT32 GetEngineRPM() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::PropulsionSystem::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::PropulsionSystem::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::PropulsionSystem::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const PropulsionSystem & Value ) const;
    KBOOL operator != ( const PropulsionSystem & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

