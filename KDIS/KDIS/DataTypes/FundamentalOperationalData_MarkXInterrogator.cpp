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

#include "./FundamentalOperationalData_MarkXInterrogator.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetSystemStatus( KBOOL IsSystemOn, KBOOL IsParam1Capable, KBOOL IsParam2Capable,
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

void FundamentalOperationalData_MarkXInterrogator::SetSystemStatusSystemOn( KBOOL IsSystemOn )
{
    m_ui8SystemOnOff = IsSystemOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetSystemStatusParam1Capable( KBOOL IsParamCapable )
{
    m_ui8Param1 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetSystemStatusParam2Capable( KBOOL IsParamCapable )
{
    m_ui8Param2 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetSystemStatusParam3Capable( KBOOL IsParamCapable )
{
    m_ui8Param3 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetSystemStatusParam4Capable( KBOOL IsParamCapable )
{
    m_ui8Param4 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetSystemStatusParam5Capable( KBOOL IsParamCapable )
{
    m_ui8Param5 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetSystemStatusParam6Capable( KBOOL IsParamCapable )
{
    m_ui8Param6 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetSystemStatusIsOperational( KBOOL IsOperational )
{
    m_ui8OpsStatus = !IsOperational;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::GetSystemStatusSystemOn() const
{
    return m_ui8SystemOnOff;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::GetSystemStatusParam1Capable() const
{
    return !m_ui8Param1;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::GetSystemStatusParam2Capable() const
{
    return !m_ui8Param2;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::GetSystemStatusParam3Capable() const
{
    return !m_ui8Param3;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::GetSystemStatusParam4Capable() const
{
    return !m_ui8Param4;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::GetSystemStatusParam5Capable() const
{
    return !m_ui8Param5;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::GetSystemStatusParam6Capable() const
{
    return !m_ui8Param6;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::GetSystemStatusIsOperational() const
{
    return !m_ui8OpsStatus;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetAlternateParameter4( AlternateParameter4 AP4 )
{
    m_ui8AltParam4 = AP4;
}

//////////////////////////////////////////////////////////////////////////

AlternateParameter4 FundamentalOperationalData_MarkXInterrogator::GetAlternateParameter4() const
{
    return ( AlternateParameter4 )m_ui8AltParam4;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetInfomationLayersPresence( KBOOL IsLayer1Present, KBOOL IsLayer2Present )
{
    m_ui8Layer1 = IsLayer1Present;
    m_ui8Layer2 = IsLayer2Present;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetInfomationLayer1( KBOOL IsPresent )
{
    m_ui8Layer1 = IsPresent;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetInfomationLayer2( KBOOL IsPresent )
{
    m_ui8Layer2 = IsPresent;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsInfomationLayer1Present() const
{
    return m_ui8Layer1;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsInfomationLayer2Present() const
{
    return m_ui8Layer2;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetMode1InterrogatorStatus( KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning )
{
    m_ui16Mode1Status = IsStatusOn;
    m_ui16Mode1Dmg = IsDamaged;
    m_ui16Mode1Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetMode1Status( KBOOL IsOn )
{
    m_ui16Mode1Status = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetMode1Damage( KBOOL IsDamaged )
{
    m_ui16Mode1Dmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetMode1Malfunction( KBOOL IsMalfunctioning )
{
    m_ui16Mode1Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsMode1StatusOn() const
{
    return m_ui16Mode1Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsMode1Damaged() const
{
    return m_ui16Mode1Dmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsMode1Malfunctioning() const
{
    return m_ui16Mode1Malfunction;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetMode2CodeStatus( KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning )
{
    m_ui16Mode2Status = IsStatusOn;
    m_ui16Mode2Dmg = IsDamaged;
    m_ui16Mode2Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetMode2Status( KBOOL IsOn )
{
    m_ui16Mode2Status = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetMode2Damage( KBOOL IsDamaged )
{
    m_ui16Mode2Dmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetMode2Malfunction( KBOOL IsMalfunctioning )
{
    m_ui16Mode2Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsMode2StatusOn() const
{
    return m_ui16Mode2Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsMode2Damaged() const
{
    return m_ui16Mode2Dmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsMode2Malfunctioning() const
{
    return m_ui16Mode2Malfunction;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetMode3CodeStatus( KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning )
{
    m_ui16Mode3Status = IsStatusOn;
    m_ui16Mode3Dmg = IsDamaged;
    m_ui16Mode3Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetMode3Status( KBOOL IsOn )
{
    m_ui16Mode3Status = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetMode3Damage( KBOOL IsDamaged )
{
    m_ui16Mode3Dmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetMode3Malfunction( KBOOL IsMalfunctioning )
{
    m_ui16Mode3Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsMode3StatusOn() const
{
    return m_ui16Mode3Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsMode3Damaged() const
{
    return m_ui16Mode3Dmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsMode3Malfunctioning() const
{
    return m_ui16Mode3Malfunction;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetMode4CodeStatus( KUINT16 CodeElement1, KBOOL IsStatusOn, KBOOL IsDamaged,
        KBOOL IsMalfunctioning )
{
    m_ui16Mode4CodeElement1 = CodeElement1;
    m_ui16Mode4Status = IsStatusOn;
    m_ui16Mode4Dmg = IsDamaged;
    m_ui16Mode4Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetMode4CodeElement1( KUINT16 CE )
{
    m_ui16Mode4CodeElement1 = CE;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetMode4Status( KBOOL IsOn )
{
    m_ui16Mode4Status = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetMode4Damage( KBOOL IsDamaged )
{
    m_ui16Mode4Dmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetMode4Malfunction( KBOOL IsMalfunctioning )
{
    m_ui16Mode4Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 FundamentalOperationalData_MarkXInterrogator::GetMode4CodeElement1() const
{
    return m_ui16Mode4CodeElement1;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsMode4StatusOn() const
{
    return m_ui16Mode4Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsMode4Damaged() const
{
    return m_ui16Mode4Dmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsMode4Malfunctioning() const
{
    return m_ui16Mode4Malfunction;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetModeCCodeStatus( KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning )
{
    m_ui16ModeCStatus = IsStatusOn;
    m_ui16ModeCDmg = IsDamaged;
    m_ui16ModeCMalfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetModeCStatus( KBOOL IsOn )
{
    m_ui16ModeCStatus = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetModeCDamage( KBOOL IsDamaged )
{
    m_ui16ModeCDmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetModeCMalfunction( KBOOL IsMalfunctioning )
{
    m_ui16ModeCMalfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsModeCStatusOn() const
{
    return m_ui16ModeCStatus;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsModeCDamaged() const
{
    return m_ui16ModeCDmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsModeCMalfunctioning() const
{
    return m_ui16ModeCMalfunction;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetModeSCodeStatus( TCAS TCASVersion, KBOOL IsStatusOn, KBOOL IsDamaged,
        KBOOL IsMalfunctioning )
{
    m_ui16ModeSTCAS = TCASVersion;
    m_ui16ModeCStatus = IsStatusOn;
    m_ui16ModeCDmg = IsDamaged;
    m_ui16ModeCMalfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetTCASVersion( TCAS TCASVersion )
{
    m_ui16ModeSTCAS = TCASVersion;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetModeSStatus( KBOOL IsOn )
{
    m_ui16ModeSStatus = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetModeSDamage( KBOOL IsDamaged )
{
    m_ui16ModeSDmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_MarkXInterrogator::SetModeSMalfunction( KBOOL IsMalfunctioning )
{
    m_ui16ModeSMalfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

TCAS FundamentalOperationalData_MarkXInterrogator::GetTCASVersion() const
{
    return ( TCAS )m_ui16ModeSTCAS;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsModeSStatusOn() const
{
    return m_ui16ModeSStatus;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsModeSDamaged() const
{
    return m_ui16ModeSDmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::IsModeSMalfunctioning() const
{
    return m_ui16ModeSMalfunction;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_MarkXInterrogator::operator == ( const FundamentalOperationalData_MarkXInterrogator & Value ) const
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

KBOOL FundamentalOperationalData_MarkXInterrogator::operator != ( const FundamentalOperationalData_MarkXInterrogator & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

