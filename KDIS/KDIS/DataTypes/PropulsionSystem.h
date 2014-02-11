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

class KDIS_EXPORT PropulsionSystem : public DataTypeBase
{
protected:

    KFLOAT32 m_f32PowerSetting;

    KFLOAT32 m_f32EngineRPM;

public:

    static const KUINT16 PROPULSION_SYSTEM_SIZE = 8;

    PropulsionSystem();

    PropulsionSystem( KDataStream & stream ) throw( KException );

    PropulsionSystem( KFLOAT32 PowerSetting, KFLOAT32 EngineRPM );

    virtual ~PropulsionSystem();

    //************************************
    // FullName:    KDIS::DATA_TYPE::PropulsionSystem::SetPowerSetting
    //              KDIS::DATA_TYPE::PropulsionSystem::GetPowerSetting
    // Description: The power settings after any response lags have been incorprated.
    // Parameter:   KFLOAT32 PS, PowerSetting PS
    //************************************
    void SetPowerSetting( KFLOAT32 PS );
    void SetPowerSetting( KDIS::DATA_TYPE::ENUMS::PowerSettingAircraft PS );
    void SetPowerSetting( KDIS::DATA_TYPE::ENUMS::PowerSettingHelicopter PS );
    void SetPowerSetting( KDIS::DATA_TYPE::ENUMS::ActiveEmissionParameterIndex PS );
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

} // END namespace DATA_TYPES
} // END namespace KDIS

