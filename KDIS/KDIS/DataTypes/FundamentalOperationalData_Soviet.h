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
    class:      FundamentalOperationalData_Soviet
    created:    2008/12/07
    author:     Karl Jones

    purpose:    Specifies Fundamental Operational Data for system 3 & 4 =
                Soviet Transponder
                Soviet Interrogator

    size:       128 bits / 16 octets
*********************************************************************/

#pragma once

#include "./../KDefines.h"
#include "./Enums/KDISEnums.h"

namespace KDIS {
namespace DATA_TYPE {

struct KDIS_EXPORT FundamentalOperationalData_Soviet
{
protected:

    union
    {
        struct
        {
            KUINT8 m_ui8SystemOnOff : 1;
            KUINT8 m_ui8Param1      : 1;
            KUINT8 m_ui8Param2      : 1;
            KUINT8 m_ui8Param3      : 1;
            KUINT8 m_ui8Param4      : 1;
            KUINT8 m_ui8Param5      : 1;
            KUINT8 m_ui8Param6      : 1;
            KUINT8 m_ui8OpsStatus   : 1;
        };

        KUINT8 m_ui8SystemStatus;
    };

    KUINT8 m_ui8AltParam4; // Not used

    union
    {
        struct
        {
            KUINT8 m_ui8NotUsed1 : 1;
            KUINT8 m_ui8Layer1   : 1;
            KUINT8 m_ui8Layer2   : 1;
            KUINT8 m_ui8NotUsed2 : 5;
        };

        KUINT8 m_ui8InfoLayers;
    };

    KUINT8 m_ui8Modifier; // Not used

    union
    {
        struct
        {
            KUINT16 m_ui16Param1NotUsed1    : 13;
            KUINT16 m_ui16Param1Status      : 1;
            KUINT16 m_ui16Param1Dmg         : 1;
            KUINT16 m_ui16Param1Malfunction : 1;
        };

        KUINT16 m_ui16Param1; // Parameter 1
    };

    union
    {
        struct
        {
            KUINT16 m_ui16Param2NotUsed1    : 13;
            KUINT16 m_ui16Param2Status      : 1;
            KUINT16 m_ui16Param2Dmg         : 1;
            KUINT16 m_ui16Param2Malfunction : 1;
        };

        KUINT16 m_ui16Param2; // Parameter 2
    };

    union
    {
        struct
        {
            KUINT16 m_ui16Param3NotUsed1    : 13;
            KUINT16 m_ui16Param3Status      : 1;
            KUINT16 m_ui16Param3Dmg         : 1;
            KUINT16 m_ui16Param3Malfunction : 1;
        };

        KUINT16 m_ui16Param3; // Parameter 3
    };

    union
    {
        struct
        {
            KUINT16 m_ui16Param4NotUsed1    : 13;
            KUINT16 m_ui16Param4Status      : 1;
            KUINT16 m_ui16Param4Dmg         : 1;
            KUINT16 m_ui16Param4Malfunction : 1;
        };

        KUINT16 m_ui16Param4; // Parameter 4
    };

    union
    {
        struct
        {
            KUINT16 m_ui16Param5NotUsed1    : 13;
            KUINT16 m_ui16Param5Status      : 1;
            KUINT16 m_ui16Param5Dmg         : 1;
            KUINT16 m_ui16Param5Malfunction : 1;
        };

        KUINT16 m_ui16Param5; // Parameter 5
    };

    union
    {
        struct
        {
            KUINT16 m_ui16Param6NotUsed1    : 13;
            KUINT16 m_ui16Param6Status      : 1;
            KUINT16 m_ui16Param6Dmg         : 1;
            KUINT16 m_ui16Param6Malfunction : 1;
        };

        KUINT16 m_ui16Param6; // Parameter 6
    };

public:

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_Soviet::SetSystemStatus
    //              KDIS::DATA_TYPE::FundamentalOperationalData_Soviet::GetSystemStatus
    // Description: Specifies whether the entire system is operational
    //              and which modes it is capable of.
    // Parameter:   KBOOL, void
    //************************************
    void SetSystemStatus( KBOOL IsSystemOn, KBOOL IsParam1Capable, KBOOL IsParam2Capable,
                          KBOOL IsParam3Capable, KBOOL IsParam4Capable, KBOOL IsParam5Capable,
                          KBOOL IsParam6Capable, KBOOL IsOperational );
    void SetSystemStatusSystemOn( KBOOL IsSystemOn );
    void SetSystemStatusParam1Capable( KBOOL IsParamCapable );
    void SetSystemStatusParam2Capable( KBOOL IsParamCapable );
    void SetSystemStatusParam3Capable( KBOOL IsParamCapable );
    void SetSystemStatusParam4Capable( KBOOL IsParamCapable );
    void SetSystemStatusParam5Capable( KBOOL IsParamCapable );
    void SetSystemStatusParam6Capable( KBOOL IsParamCapable );
    void SetSystemStatusIsOperational( KBOOL IsOperational );
    KBOOL GetSystemStatusSystemOn() const;
    KBOOL GetSystemStatusParam1Capable() const;
    KBOOL GetSystemStatusParam2Capable() const;
    KBOOL GetSystemStatusParam3Capable() const;
    KBOOL GetSystemStatusParam4Capable() const;
    KBOOL GetSystemStatusParam5Capable() const;
    KBOOL GetSystemStatusParam6Capable() const;
    KBOOL GetSystemStatusIsOperational() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_Soviet::SetInfomationLayer
    //              KDIS::DATA_TYPE::FundamentalOperationalData_Soviet::IsInfomationLayerPresent
    // Description: Used for an alternative representation of parameter 4
    // Parameter:   KBOOL, void
    //************************************
    void SetInfomationLayersPresence( KBOOL IsLayer1Present, KBOOL IsLayer2Present );
    void SetInfomationLayer1( KBOOL IsPresent );
    void SetInfomationLayer2( KBOOL IsPresent );
    KBOOL IsInfomationLayer1Present() const;
    KBOOL IsInfomationLayer2Present() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_Soviet::SetParameter1
    //              KDIS::DATA_TYPE::FundamentalOperationalData_Soviet::GetParameter1
    // Description: Parameter 1 data - Mode 1 Interrogator Status
    // Parameter:   KBOOL, void
    //************************************
    void SetParameter1( KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning );
    void SetParameter1Status( KBOOL IsOn );
    void SetParameter1Damage( KBOOL IsDamaged );
    void SetParameter1Malfunction( KBOOL IsMalfunctioning );
    KBOOL IsParameter1StatusOn() const;
    KBOOL IsParameter1Damaged() const;
    KBOOL IsParameter1Malfunctioning() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_Soviet::SetParameter2
    //              KDIS::DATA_TYPE::FundamentalOperationalData_Soviet::GetParameter2
    // Description: Parameter 2 data - Mode 2 Interrogator Status
    // Parameter:   KBOOL, void
    //************************************
    void SetParameter2( KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning );
    void SetParameter2Status( KBOOL IsOn );
    void SetParameter2Damage( KBOOL IsDamaged );
    void SetParameter2Malfunction( KBOOL IsMalfunctioning );
    KBOOL IsParameter2StatusOn() const;
    KBOOL IsParameter2Damaged() const;
    KBOOL IsParameter2Malfunctioning() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_Soviet::SetParameter3
    //              KDIS::DATA_TYPE::FundamentalOperationalData_Soviet::GetParameter3
    // Description: Parameter 3 data - Mode 3 Code/Status
    // Parameter:   KBOOL, void
    //************************************
    void SetParameter3( KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning );
    void SetParameter3Status( KBOOL IsOn );
    void SetParameter3Damage( KBOOL IsDamaged );
    void SetParameter3Malfunction( KBOOL IsMalfunctioning );
    KBOOL IsParameter3StatusOn() const;
    KBOOL IsParameter3Damaged() const;
    KBOOL IsParameter3Malfunctioning() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_Soviet::SetParameter4
    //              KDIS::DATA_TYPE::FundamentalOperationalData_Soviet::GetParameter4
    // Description: Parameter 4 data
    // Parameter:   KBOOL, KUINT16, void
    //************************************
    void SetParameter4( KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning );
    void SetParameter4Status( KBOOL IsOn );
    void SetParameter4Damage( KBOOL IsDamaged );
    void SetParameter4Malfunction( KBOOL IsMalfunctioning );
    KBOOL IsParameter4StatusOn() const;
    KBOOL IsParameter4Damaged() const;
    KBOOL IsParameter4Malfunctioning() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_Soviet::SetParameter5
    //              KDIS::DATA_TYPE::FundamentalOperationalData_Soviet::GetParameter5
    // Description: Parameter 5 data
    // Parameter:   KBOOL, void
    //************************************
    void SetParameter5( KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning );
    void SetParameter5Status( KBOOL IsOn );
    void SetParameter5Damage( KBOOL IsDamaged );
    void SetParameter5Malfunction( KBOOL IsMalfunctioning );
    KBOOL IsParameter5StatusOn() const;
    KBOOL IsParameter5Damaged() const;
    KBOOL IsParameter5Malfunctioning() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_Soviet::SetParameter6
    //              KDIS::DATA_TYPE::FundamentalOperationalData_Soviet::GetParameter6
    // Description: Parameter 6 data
    // Parameter:   KBOOL, void
    //************************************
    void SetParameter6( KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning );
    void SetParameter6Status( KBOOL IsOn );
    void SetParameter6Damage( KBOOL IsDamaged );
    void SetParameter6Malfunction( KBOOL IsMalfunctioning );
    KBOOL IsParameter6StatusOn() const;
    KBOOL IsParameter6Damaged() const;
    KBOOL IsParameter6Malfunctioning() const;

    KBOOL operator == ( const FundamentalOperationalData_Soviet & Value ) const;
    KBOOL operator != ( const FundamentalOperationalData_Soviet & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

