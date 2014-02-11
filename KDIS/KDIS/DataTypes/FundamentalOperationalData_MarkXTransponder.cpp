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

#include "./FundamentalOperationalData_MarkXTransponder.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetSystemStatus( KBOOL IsSystemOn, KBOOL IsParam1Capable, KBOOL IsParam2Capable,
        KBOOL IsParam3Capable, KBOOL IsParam4Capable, KBOOL IsParam5Capable,
        KBOOL IsParam6Capable, KBOOL IsOperational )
{
    m_ui8SystemOnOff = IsSystemOn;

    // Values flipped as 0 means capable and 1 not capable.
    m_ui8Param1 = !IsParam1Capable;
    m_ui8Param2 = !IsParam2Capable;
    m_ui8Param3 = !IsParam3Capable;
    m_ui8Param4 = !IsParam4Capable;
    m_ui8Param5 = !IsParam5Capable;
    m_ui8Param6 = !IsParam6Capable;
    m_ui8OpsStatus = !IsOperational;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetSystemStatusSystemOn( KBOOL IsSystemOn )
{
    m_ui8SystemOnOff = IsSystemOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetSystemStatusParam1Capable( KBOOL IsParamCapable )
{
    m_ui8Param1 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetSystemStatusParam2Capable( KBOOL IsParamCapable )
{
    m_ui8Param2 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetSystemStatusParam3Capable( KBOOL IsParamCapable )
{
    m_ui8Param3 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetSystemStatusParam4Capable( KBOOL IsParamCapable )
{
    m_ui8Param4 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetSystemStatusParam5Capable( KBOOL IsParamCapable )
{
    m_ui8Param5 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetSystemStatusParam6Capable( KBOOL IsParamCapable )
{
    m_ui8Param6 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetSystemStatusIsOperational( KBOOL IsOperational )
{
    m_ui8OpsStatus = !IsOperational;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::GetSystemStatusSystemOn() const
{
    return m_ui8SystemOnOff;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::GetSystemStatusParam1Capable() const
{
    return !m_ui8Param1;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::GetSystemStatusParam2Capable() const
{
    return !m_ui8Param2;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::GetSystemStatusParam3Capable() const
{
    return !m_ui8Param3;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::GetSystemStatusParam4Capable() const
{
    return !m_ui8Param4;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::GetSystemStatusParam5Capable() const
{
    return !m_ui8Param5;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::GetSystemStatusParam6Capable() const
{
    return !m_ui8Param6;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::GetSystemStatusIsOperational() const
{
    return !m_ui8OpsStatus;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetAlternateParameter4( AlternateParameter4 AP4 )
{
    m_ui8AltParam4 = AP4;
}

//////////////////////////////////////////////////////////////////////////

AlternateParameter4 FundamentalOperationalData_MarkXTransponder::GetAlternateParameter4() const
{
    return ( AlternateParameter4 )m_ui8AltParam4;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetInfomationLayersPresence( KBOOL IsLayer1Present, KBOOL IsLayer2Present )
{
    m_ui8Layer1 = IsLayer1Present;
    m_ui8Layer2 = IsLayer2Present;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetInfomationLayer1( KBOOL IsPresent )
{
    m_ui8Layer1 = IsPresent;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetInfomationLayer2( KBOOL IsPresent )
{
    m_ui8Layer2 = IsPresent;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsInfomationLayer1Present() const
{
    return m_ui8Layer1;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsInfomationLayer2Present() const
{
    return m_ui8Layer2;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetModifier( KBOOL IsEmergencyOn, KBOOL IsIdentSquawkFlashOn, KBOOL IsSTIOn )
{
    m_ui8Emergency = IsEmergencyOn;
    m_ui8IdentSquawkFlash = IsIdentSquawkFlashOn;
    m_ui8STI = IsSTIOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetModifierEmergency( KBOOL IsOn )
{
    m_ui8Emergency = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetModifierIdentSquawkFlash( KBOOL IsOn )
{
    m_ui8IdentSquawkFlash = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetModifierSTI( KBOOL IsOn )
{
    m_ui8STI = IsOn;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsModifierEmergencyOn() const
{
    return m_ui8Emergency;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsModifierIdentSquawkFlashOn() const
{
    return m_ui8IdentSquawkFlash;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsModifierSTIOn() const
{
    return m_ui8STI;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode1CodeStatus( KUINT8 CodeElement1, KUINT8 CodeElement2, KBOOL IsStatusOn,
        KBOOL IsDamaged, KBOOL IsMalfunctioning )
{
    m_ui16Mode1CodeElement1 = CodeElement1;
    m_ui16Mode1CodeElement2 = CodeElement2;
    m_ui16Mode1Status = IsStatusOn;
    m_ui16Mode1Dmg = IsDamaged;
    m_ui16Mode1Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode1CodeElement1( KUINT8 CE )
{
    m_ui16Mode1CodeElement1 = CE;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode1CodeElement2( KUINT8 CE )
{
    m_ui16Mode1CodeElement2 = CE;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode1Status( KBOOL IsOn )
{
    m_ui16Mode1Status = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode1Damage( KBOOL IsDamaged )
{
    m_ui16Mode1Dmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode1Malfunction( KBOOL IsMalfunctioning )
{
    m_ui16Mode1Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 FundamentalOperationalData_MarkXTransponder::GetMode1CodeElement1() const
{
    return m_ui16Mode1CodeElement1;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 FundamentalOperationalData_MarkXTransponder::GetMode1CodeElement2() const
{
    return m_ui16Mode1CodeElement2;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsMode1StatusOn() const
{
    return m_ui16Mode1Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsMode1Damaged() const
{
    return m_ui16Mode1Dmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsMode1Malfunctioning() const
{
    return m_ui16Mode1Malfunction;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode2CodeStatus( KUINT8 CodeElement1, KUINT8 CodeElement2, KUINT8 CodeElement3,
        KUINT8 CodeElement4, KBOOL IsStatusOn, KBOOL IsDamaged,
        KBOOL IsMalfunctioning )
{
    m_ui16Mode2CodeElement1 = CodeElement1;
    m_ui16Mode2CodeElement2 = CodeElement2;
    m_ui16Mode2CodeElement3 = CodeElement3;
    m_ui16Mode2CodeElement4 = CodeElement4;
    m_ui16Mode2Status = IsStatusOn;
    m_ui16Mode2Dmg = IsDamaged;
    m_ui16Mode2Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode2CodeElement1( KUINT8 CE )
{
    m_ui16Mode2CodeElement1 = CE;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode2CodeElement2( KUINT8 CE )
{
    m_ui16Mode2CodeElement2 = CE;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode2CodeElement3( KUINT8 CE )
{
    m_ui16Mode2CodeElement3 = CE;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode2CodeElement4( KUINT8 CE )
{
    m_ui16Mode2CodeElement4 = CE;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode2Status( KBOOL IsOn )
{
    m_ui16Mode2Status = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode2Damage( KBOOL IsDamaged )
{
    m_ui16Mode2Dmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode2Malfunction( KBOOL IsMalfunctioning )
{
    m_ui16Mode2Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 FundamentalOperationalData_MarkXTransponder::GetMode2CodeElement1() const
{
    return m_ui16Mode2CodeElement1;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 FundamentalOperationalData_MarkXTransponder::GetMode2CodeElement2() const
{
    return m_ui16Mode2CodeElement2;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 FundamentalOperationalData_MarkXTransponder::GetMode2CodeElement3() const
{
    return m_ui16Mode2CodeElement3;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 FundamentalOperationalData_MarkXTransponder::GetMode2CodeElement4() const
{
    return m_ui16Mode2CodeElement4;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsMode2StatusOn() const
{
    return m_ui16Mode2Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsMode2Damaged() const
{
    return m_ui16Mode2Dmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsMode2Malfunctioning() const
{
    return m_ui16Mode2Malfunction;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode3CodeStatus( KUINT8 CodeElement1, KUINT8 CodeElement2, KUINT8 CodeElement3,
        KUINT8 CodeElement4, KBOOL IsStatusOn, KBOOL IsDamaged,
        KBOOL IsMalfunctioning )
{
    m_ui16Mode3CodeElement1 = CodeElement1;
    m_ui16Mode3CodeElement2 = CodeElement2;
    m_ui16Mode3CodeElement3 = CodeElement3;
    m_ui16Mode3CodeElement4 = CodeElement4;
    m_ui16Mode3Status = IsStatusOn;
    m_ui16Mode3Dmg = IsDamaged;
    m_ui16Mode3Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode3CodeElement1( KUINT8 CE )
{
    m_ui16Mode3CodeElement1 = CE;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode3CodeElement2( KUINT8 CE )
{
    m_ui16Mode3CodeElement2 = CE;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode3CodeElement3( KUINT8 CE )
{
    m_ui16Mode3CodeElement3 = CE;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode3CodeElement4( KUINT8 CE )
{
    m_ui16Mode3CodeElement4 = CE;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode3Status( KBOOL IsOn )
{
    m_ui16Mode3Status = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode3Damage( KBOOL IsDamaged )
{
    m_ui16Mode3Dmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode3Malfunction( KBOOL IsMalfunctioning )
{
    m_ui16Mode3Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 FundamentalOperationalData_MarkXTransponder::GetMode3CodeElement1() const
{
    return m_ui16Mode3CodeElement1;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 FundamentalOperationalData_MarkXTransponder::GetMode3CodeElement2() const
{
    return m_ui16Mode3CodeElement2;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 FundamentalOperationalData_MarkXTransponder::GetMode3CodeElement3() const
{
    return m_ui16Mode3CodeElement3;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 FundamentalOperationalData_MarkXTransponder::GetMode3CodeElement4() const
{
    return m_ui16Mode3CodeElement4;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsMode3StatusOn() const
{
    return m_ui16Mode3Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsMode3Damaged() const
{
    return m_ui16Mode3Dmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsMode3Malfunctioning() const
{
    return m_ui16Mode3Malfunction;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode4CodeStatus( KUINT16 CodeElement1, KBOOL IsStatusOn, KBOOL IsDamaged,
        KBOOL IsMalfunctioning )
{
    m_ui16Mode4CodeElement1 = CodeElement1;
    m_ui16Mode4Status = IsStatusOn;
    m_ui16Mode4Dmg = IsDamaged;
    m_ui16Mode4Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode4CodeElement1( KUINT16 CE )
{
    m_ui16Mode4CodeElement1 = CE;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode4Status( KBOOL IsOn )
{
    m_ui16Mode4Status = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode4Damage( KBOOL IsDamaged )
{
    m_ui16Mode4Dmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetMode4Malfunction( KBOOL IsMalfunctioning )
{
    m_ui16Mode4Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 FundamentalOperationalData_MarkXTransponder::GetMode4CodeElement1() const
{
    return m_ui16Mode4CodeElement1;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsMode4StatusOn() const
{
    return m_ui16Mode4Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsMode4Damaged() const
{
    return m_ui16Mode4Dmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsMode4Malfunctioning() const
{
    return m_ui16Mode4Malfunction;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetModeCCodeStatus( KBOOL IsAltitudeNegativeMeanSeaLevel, KUINT16 Altitude,
        KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning )
{
    m_ui16ModeCNegativeAltitude = IsAltitudeNegativeMeanSeaLevel;
    m_ui16ModeCAltitude = Altitude;
    m_ui16ModeCStatus = IsStatusOn;
    m_ui16ModeCDmg = IsDamaged;
    m_ui16ModeCMalfunction = IsMalfunctioning;

    if( Altitude == 4095 )m_ui16ModeCNegativeAltitude = 1;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetModeCAltitude( KBOOL IsAltitudeNegativeMeanSeaLevel, KUINT16 Altitude )
{
    m_ui16ModeCNegativeAltitude = IsAltitudeNegativeMeanSeaLevel;
    m_ui16ModeCAltitude = Altitude;

    if( Altitude == 4095 )m_ui16ModeCNegativeAltitude = 1;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetModeCStatus( KBOOL IsOn )
{
    m_ui16ModeCStatus = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetModeCDamage( KBOOL IsDamaged )
{
    m_ui16ModeCDmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetModeCMalfunction( KBOOL IsMalfunctioning )
{
    m_ui16ModeCMalfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsModeCAltitudeNegativeMeanSeaLevel() const
{
    return m_ui16ModeCNegativeAltitude;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 FundamentalOperationalData_MarkXTransponder::GetModeCAltitude() const
{
    return m_ui16ModeCAltitude;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsModeCAlternativeMode5() const
{
    if( m_ui16ModeCAltitude == 4095 && m_ui16ModeCNegativeAltitude == 1 )return true;
    else return false;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsModeCStatusOn() const
{
    return m_ui16ModeCStatus;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsModeCDamaged() const
{
    return m_ui16ModeCDmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsModeCMalfunctioning() const
{
    return m_ui16ModeCMalfunction;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetModeSCodeStatus( TCAS TCASVersion, KBOOL IsStatusOn, KBOOL IsDamaged,
        KBOOL IsMalfunctioning )
{
    m_ui16ModeSTCAS = TCASVersion;
    m_ui16ModeCStatus = IsStatusOn;
    m_ui16ModeCDmg = IsDamaged;
    m_ui16ModeCMalfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetTCASVersion( TCAS TCASVersion )
{
    m_ui16ModeSTCAS = TCASVersion;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetModeSStatus( KBOOL IsOn )
{
    m_ui16ModeSStatus = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetModeSDamage( KBOOL IsDamaged )
{
    m_ui16ModeSDmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXTransponder::SetModeSMalfunction( KBOOL IsMalfunctioning )
{
    m_ui16ModeSMalfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

TCAS FundamentalOperationalData_MarkXTransponder::GetTCASVersion() const
{
    return ( TCAS )m_ui16ModeSTCAS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsModeSStatusOn() const
{
    return m_ui16ModeSStatus;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsModeSDamaged() const
{
    return m_ui16ModeSDmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::IsModeSMalfunctioning() const
{
    return m_ui16ModeSMalfunction;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::operator == ( const FundamentalOperationalData_MarkXTransponder & Value ) const
{
    if( m_ui8SystemStatus   != Value.m_ui8SystemStatus )    return false;
    if( m_ui8AltParam4      != Value.m_ui8AltParam4 )       return false;
    if( m_ui8InfoLayers     != Value.m_ui8InfoLayers )      return false;
    if( m_ui8Modifier       != Value.m_ui8Modifier )        return false;
    if( m_ui16Param1        != Value.m_ui16Param1 )         return false;
    if( m_ui16Param2        != Value.m_ui16Param2 )         return false;
    if( m_ui16Param3        != Value.m_ui16Param3 )         return false;
    if( m_ui16Param4        != Value.m_ui16Param4 )         return false;
    if( m_ui16Param5        != Value.m_ui16Param5 )         return false;
    if( m_ui16Param6        != Value.m_ui16Param6 )         return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXTransponder::operator != ( const FundamentalOperationalData_MarkXTransponder & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
