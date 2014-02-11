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
    class:      FundamentalOperationalData_MarkXTransponder
    created:    2008/12/07
    author:     Karl Jones

    purpose:    Specifies Fundamental Operational Data for system 1 =
                Mark_X_XII_ATCRBS_ModeS_Transponder system.

    size:       128 bits / 16 octets
*********************************************************************/

#pragma once

#include "./../KDefines.h"
#include "./Enums/KDISEnums.h"

namespace KDIS {
namespace DATA_TYPE {

struct KDIS_EXPORT FundamentalOperationalData_MarkXTransponder
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

    KUINT8 m_ui8AltParam4;

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

    union
    {
        struct
        {
            KUINT8 m_ui8Other             : 1;
            KUINT8 m_ui8Emergency         : 1;
            KUINT8 m_ui8IdentSquawkFlash  : 1;
            KUINT8 m_ui8STI               : 1;
            // 4-7 not used
        };

        KUINT8 m_ui8Modifier;
    };

    union
    {
        struct
        {
            KUINT16 m_ui16Mode1CodeElement1 : 3;
            KUINT16 m_ui16Mode1CodeElement2 : 3;
            KUINT16 m_ui16Mode1NotUsed1     : 7;
            KUINT16 m_ui16Mode1Status       : 1;
            KUINT16 m_ui16Mode1Dmg          : 1;
            KUINT16 m_ui16Mode1Malfunction  : 1;
        };

        KUINT16 m_ui16Param1; // Mode 1 Code/Status
    };

    union
    {
        struct
        {
            KUINT16 m_ui16Mode2CodeElement1 : 3;
            KUINT16 m_ui16Mode2CodeElement2 : 3;
            KUINT16 m_ui16Mode2CodeElement3 : 3;
            KUINT16 m_ui16Mode2CodeElement4 : 3;
            KUINT16 m_ui16Mode2NotUsed1     : 1;
            KUINT16 m_ui16Mode2Status       : 1;
            KUINT16 m_ui16Mode2Dmg          : 1;
            KUINT16 m_ui16Mode2Malfunction  : 1;
        };

        KUINT16 m_ui16Param2; // Mode 2 Code/Status
    };

    union
    {
        struct
        {
            KUINT16 m_ui16Mode3CodeElement1 : 3;
            KUINT16 m_ui16Mode3CodeElement2 : 3;
            KUINT16 m_ui16Mode3CodeElement3 : 3;
            KUINT16 m_ui16Mode3CodeElement4 : 3;
            KUINT16 m_ui16Mode3NotUsed1     : 1;
            KUINT16 m_ui16Mode3Status       : 1;
            KUINT16 m_ui16Mode3Dmg          : 1;
            KUINT16 m_ui16Mode3Malfunction  : 1;
        };

        KUINT16 m_ui16Param3; // Mode 3 Code/Status
    };

    union
    {
        struct
        {
            KUINT16 m_ui16Mode4CodeElement1 : 12;
            KUINT16 m_ui16Mode4NotUsed1     : 1;
            KUINT16 m_ui16Mode4Status       : 1;
            KUINT16 m_ui16Mode4Dmg          : 1;
            KUINT16 m_ui16Mode4Malfunction  : 1;
        };

        KUINT16 m_ui16Param4; // Mode 4 Code/Status
    };

    union
    {
        struct
        {
            KUINT16 m_ui16ModeCNegativeAltitude : 1;
            KUINT16 m_ui16ModeCAltitude         : 11;
            KUINT16 m_ui16ModeCNotUsed1         : 1;
            KUINT16 m_ui16ModeCStatus           : 1;
            KUINT16 m_ui16ModeCDmg              : 1;
            KUINT16 m_ui16ModeCMalfunction      : 1;
        };

        KUINT16 m_ui16Param5; // Mode C Code/Status
    };

    union
    {
        struct
        {
            KUINT16 m_ui16ModeSToBeDefined : 12;
            KUINT16 m_ui16ModeSTCAS        : 1;
            KUINT16 m_ui16ModeSStatus      : 1;
            KUINT16 m_ui16ModeSDmg         : 1;
            KUINT16 m_ui16ModeSMalfunction : 1;
        };

        KUINT16 m_ui16Param6; // Mode S Code/Status
    };

public:

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::SetSystemStatus
    //              KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::GetSystemStatus
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
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::SetAlternateParameter4
    //              KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::GetAlternateParameter4
    // Description: Used for an alternative representation of parameter 4
    // Parameter:   AlternateParameter4 AP4
    //************************************
    void SetAlternateParameter4( KDIS::DATA_TYPE::ENUMS::AlternateParameter4 AP4 );
    KDIS::DATA_TYPE::ENUMS::AlternateParameter4 GetAlternateParameter4() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::SetInfomationLayer
    //              KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::IsInfomationLayerPresent
    // Description: Used for an alternative representation of parameter 4
    // Parameter:   KBOOL
    //************************************
    void SetInfomationLayersPresence( KBOOL IsLayer1Present, KBOOL IsLayer2Present );
    void SetInfomationLayer1( KBOOL IsPresent );
    void SetInfomationLayer2( KBOOL IsPresent );
    KBOOL IsInfomationLayer1Present() const;
    KBOOL IsInfomationLayer2Present() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::SetModifier
    //              KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::IsModifier
    // Description: Contains specific data.
    // Parameter:   KBOOL, void
    //************************************
    void SetModifier( KBOOL IsEmergencyOn, KBOOL IsIdentSquawkFlashOn, KBOOL IsSTIOn );
    void SetModifierEmergency( KBOOL IsOn );
    void SetModifierIdentSquawkFlash( KBOOL IsOn );
    void SetModifierSTI( KBOOL IsOn );
    KBOOL IsModifierEmergencyOn() const;
    KBOOL IsModifierIdentSquawkFlashOn() const;
    KBOOL IsModifierSTIOn() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::SetMode1
    //              KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::GetMode1
    // Description: Parameter 1 data - Mode 1 Code/Status
    // Parameter:   KBOOL, KUINT8
    //************************************
    void SetMode1CodeStatus( KUINT8 CodeElement1, KUINT8 CodeElement2, KBOOL IsStatusOn,
                             KBOOL IsDamaged, KBOOL IsMalfunctioning );
    void SetMode1CodeElement1( KUINT8 CE );
    void SetMode1CodeElement2( KUINT8 CE );
    void SetMode1Status( KBOOL IsOn );
    void SetMode1Damage( KBOOL IsDamaged );
    void SetMode1Malfunction( KBOOL IsMalfunctioning );
    KUINT8 GetMode1CodeElement1() const;
    KUINT8 GetMode1CodeElement2() const;
    KBOOL IsMode1StatusOn() const;
    KBOOL IsMode1Damaged() const;
    KBOOL IsMode1Malfunctioning() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::SetMode2
    //              KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::GetMode2
    // Description: Parameter 2 data - Mode 2 Code/Status
    // Parameter:   KBOOL, KUINT8
    //************************************
    void SetMode2CodeStatus( KUINT8 CodeElement1, KUINT8 CodeElement2, KUINT8 CodeElement3,
                             KUINT8 CodeElement4, KBOOL IsStatusOn, KBOOL IsDamaged,
                             KBOOL IsMalfunctioning );
    void SetMode2CodeElement1( KUINT8 CE );
    void SetMode2CodeElement2( KUINT8 CE );
    void SetMode2CodeElement3( KUINT8 CE );
    void SetMode2CodeElement4( KUINT8 CE );
    void SetMode2Status( KBOOL IsOn );
    void SetMode2Damage( KBOOL IsDamaged );
    void SetMode2Malfunction( KBOOL IsMalfunctioning );
    KUINT8 GetMode2CodeElement1() const;
    KUINT8 GetMode2CodeElement2() const;
    KUINT8 GetMode2CodeElement3() const;
    KUINT8 GetMode2CodeElement4() const;
    KBOOL IsMode2StatusOn() const;
    KBOOL IsMode2Damaged() const;
    KBOOL IsMode2Malfunctioning() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::SetMode3
    //              KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::GetMode3
    // Description: Parameter 3 data - Mode 3 Code/Status
    // Parameter:   KBOOL, KUINT8, void
    //************************************
    void SetMode3CodeStatus( KUINT8 CodeElement1, KUINT8 CodeElement2, KUINT8 CodeElement3,
                             KUINT8 CodeElement4, KBOOL IsStatusOn, KBOOL IsDamaged,
                             KBOOL IsMalfunctioning );
    void SetMode3CodeElement1( KUINT8 CE );
    void SetMode3CodeElement2( KUINT8 CE );
    void SetMode3CodeElement3( KUINT8 CE );
    void SetMode3CodeElement4( KUINT8 CE );
    void SetMode3Status( KBOOL IsOn );
    void SetMode3Damage( KBOOL IsDamaged );
    void SetMode3Malfunction( KBOOL IsMalfunctioning );
    KUINT8 GetMode3CodeElement1() const;
    KUINT8 GetMode3CodeElement2() const;
    KUINT8 GetMode3CodeElement3() const;
    KUINT8 GetMode3CodeElement4() const;
    KBOOL IsMode3StatusOn() const;
    KBOOL IsMode3Damaged() const;
    KBOOL IsMode3Malfunctioning() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::SetMode4
    //              KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::GetMode4
    // Description: Parameter 4 data - Mode 4 Code/Status
    //              Note: CodeElement1 value ranges = 0-4094 = "Pseudo-Crypto" value
    //              4095 = No Pseudo-Crypto value. Use Alternate Mode 4 value.
    // Parameter:   KBOOL, KUINT16
    //************************************
    void SetMode4CodeStatus( KUINT16 CodeElement1, KBOOL IsStatusOn, KBOOL IsDamaged,
                             KBOOL IsMalfunctioning );
    void SetMode4CodeElement1( KUINT16 CE );
    void SetMode4Status( KBOOL IsOn );
    void SetMode4Damage( KBOOL IsDamaged );
    void SetMode4Malfunction( KBOOL IsMalfunctioning );
    KUINT16 GetMode4CodeElement1() const;
    KBOOL IsMode4StatusOn() const;
    KBOOL IsMode4Damaged() const;
    KBOOL IsMode4Malfunctioning() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::SetModeC
    //              KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::GetModeC
    // Description: Parameter 5 data - Mode C Code/Status
    //              Note: For Negative Altitude:
    //              1 = Alternate Mode 5 (if altitude Bits = 2047)
    //              Altitude value: Range 0-1260 in hundreds of feet.
    //              2047 = Not actual Mode C altitude value.  Use
    //              alternate Mode 5 (Bits 0-11 = 4095 i.e. all 1-s)
    // Parameter:   KBOOL, KUINT16
    //************************************
    void SetModeCCodeStatus( KBOOL IsAltitudeNegativeMeanSeaLevel, KUINT16 Altitude,
                             KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning );
    void SetModeCAltitude( KBOOL IsAltitudeNegativeMeanSeaLevel, KUINT16 Altitude );
    void SetModeCStatus( KBOOL IsOn );
    void SetModeCDamage( KBOOL IsDamaged );
    void SetModeCMalfunction( KBOOL IsMalfunctioning );
    KBOOL IsModeCAltitudeNegativeMeanSeaLevel() const;
    KUINT16 GetModeCAltitude() const;
    KBOOL IsModeCAlternativeMode5() const;
    KBOOL IsModeCStatusOn() const;
    KBOOL IsModeCDamaged() const;
    KBOOL IsModeCMalfunctioning() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::SetModeS
    //              KDIS::DATA_TYPE::FundamentalOperationalData_MarkXTransponder::GetModeS
    // Description: Parameter 6 data - Mode S Code/Status
    // Parameter:   KBOOL
    //************************************
    void SetModeSCodeStatus( KDIS::DATA_TYPE::ENUMS::TCAS TCASVersion, KBOOL IsStatusOn, KBOOL IsDamaged,
                             KBOOL IsMalfunctioning );
    void SetTCASVersion( KDIS::DATA_TYPE::ENUMS::TCAS TCASVersion );
    void SetModeSStatus( KBOOL IsOn );
    void SetModeSDamage( KBOOL IsDamaged );
    void SetModeSMalfunction( KBOOL IsMalfunctioning );
    KDIS::DATA_TYPE::ENUMS::TCAS GetTCASVersion() const;
    KBOOL IsModeSStatusOn() const;
    KBOOL IsModeSDamaged() const;
    KBOOL IsModeSMalfunctioning() const;

    KBOOL operator == ( const FundamentalOperationalData_MarkXTransponder & Value ) const;
    KBOOL operator != ( const FundamentalOperationalData_MarkXTransponder & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

