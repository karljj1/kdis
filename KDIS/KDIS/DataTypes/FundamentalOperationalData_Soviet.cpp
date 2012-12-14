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

#include "./FundamentalOperationalData_Soviet.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetSystemStatus( KBOOL IsSystemOn, KBOOL IsParam1Capable, KBOOL IsParam2Capable,
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

void FundamentalOperationalData_Soviet::SetSystemStatusSystemOn( KBOOL IsSystemOn )
{
    m_ui8SystemOnOff = IsSystemOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetSystemStatusParam1Capable( KBOOL IsParamCapable )
{
    m_ui8Param1 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetSystemStatusParam2Capable( KBOOL IsParamCapable )
{
    m_ui8Param2 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetSystemStatusParam3Capable( KBOOL IsParamCapable )
{
    m_ui8Param3 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetSystemStatusParam4Capable( KBOOL IsParamCapable )
{
    m_ui8Param4 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetSystemStatusParam5Capable( KBOOL IsParamCapable )
{
    m_ui8Param5 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetSystemStatusParam6Capable( KBOOL IsParamCapable )
{
    m_ui8Param6 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetSystemStatusIsOperational( KBOOL IsOperational )
{
    m_ui8OpsStatus = !IsOperational;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::GetSystemStatusSystemOn() const
{
    return m_ui8SystemOnOff;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::GetSystemStatusParam1Capable() const
{
    return !m_ui8Param1;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::GetSystemStatusParam2Capable() const
{
    return !m_ui8Param2;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::GetSystemStatusParam3Capable() const
{
    return !m_ui8Param3;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::GetSystemStatusParam4Capable() const
{
    return !m_ui8Param4;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::GetSystemStatusParam5Capable() const
{
    return !m_ui8Param5;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::GetSystemStatusParam6Capable() const
{
    return !m_ui8Param6;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::GetSystemStatusIsOperational() const
{
    return !m_ui8OpsStatus;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetInfomationLayersPresence( KBOOL IsLayer1Present, KBOOL IsLayer2Present )
{
    m_ui8Layer1 = IsLayer1Present;
    m_ui8Layer2 = IsLayer2Present;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetInfomationLayer1( KBOOL IsPresent )
{
    m_ui8Layer1 = IsPresent;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetInfomationLayer2( KBOOL IsPresent )
{
    m_ui8Layer2 = IsPresent;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsInfomationLayer1Present() const
{
    return m_ui8Layer1;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsInfomationLayer2Present() const
{
    return m_ui8Layer2;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter1( KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning )
{
    m_ui16Param1Status = IsStatusOn;
    m_ui16Param1Dmg = IsDamaged;
    m_ui16Param1Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter1Status( KBOOL IsOn )
{
    m_ui16Param1Status = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter1Damage( KBOOL IsDamaged )
{
    m_ui16Param1Dmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter1Malfunction( KBOOL IsMalfunctioning )
{
    m_ui16Param1Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsParameter1StatusOn() const
{
    return m_ui16Param1Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsParameter1Damaged() const
{
    return m_ui16Param1Dmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsParameter1Malfunctioning() const
{
    return m_ui16Param1Malfunction;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter2( KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning )
{
    m_ui16Param2Status = IsStatusOn;
    m_ui16Param2Dmg = IsDamaged;
    m_ui16Param2Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter2Status( KBOOL IsOn )
{
    m_ui16Param2Status = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter2Damage( KBOOL IsDamaged )
{
    m_ui16Param2Dmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter2Malfunction( KBOOL IsMalfunctioning )
{
    m_ui16Param2Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsParameter2StatusOn() const
{
    return m_ui16Param2Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsParameter2Damaged() const
{
    return m_ui16Param2Dmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsParameter2Malfunctioning() const
{
    return m_ui16Param2Malfunction;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter3( KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning )
{
    m_ui16Param3Status = IsStatusOn;
    m_ui16Param3Dmg = IsDamaged;
    m_ui16Param3Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter3Status( KBOOL IsOn )
{
    m_ui16Param3Status = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter3Damage( KBOOL IsDamaged )
{
    m_ui16Param3Dmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter3Malfunction( KBOOL IsMalfunctioning )
{
    m_ui16Param3Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsParameter3StatusOn() const
{
    return m_ui16Param3Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsParameter3Damaged() const
{
    return m_ui16Param3Dmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsParameter3Malfunctioning() const
{
    return m_ui16Param3Malfunction;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter4( KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning )
{
    m_ui16Param4Status = IsStatusOn;
    m_ui16Param4Dmg = IsDamaged;
    m_ui16Param4Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter4Status( KBOOL IsOn )
{
    m_ui16Param4Status = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter4Damage( KBOOL IsDamaged )
{
    m_ui16Param4Dmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter4Malfunction( KBOOL IsMalfunctioning )
{
    m_ui16Param4Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsParameter4StatusOn() const
{
    return m_ui16Param4Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsParameter4Damaged() const
{
    return m_ui16Param4Dmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsParameter4Malfunctioning() const
{
    return m_ui16Param4Malfunction;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter5( KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning )
{
    m_ui16Param5Status = IsStatusOn;
    m_ui16Param5Dmg = IsDamaged;
    m_ui16Param5Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter5Status( KBOOL IsOn )
{
    m_ui16Param5Status = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter5Damage( KBOOL IsDamaged )
{
    m_ui16Param5Dmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter5Malfunction( KBOOL IsMalfunctioning )
{
    m_ui16Param5Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsParameter5StatusOn() const
{
    return m_ui16Param5Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsParameter5Damaged() const
{
    return m_ui16Param5Dmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsParameter5Malfunctioning() const
{
    return m_ui16Param5Malfunction;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter6( KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning )
{
    m_ui16Param5Status = IsStatusOn;
    m_ui16Param5Dmg = IsDamaged;
    m_ui16Param5Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter6Status( KBOOL IsOn )
{
    m_ui16Param6Status = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter6Damage( KBOOL IsDamaged )
{
    m_ui16Param6Dmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_Soviet::SetParameter6Malfunction( KBOOL IsMalfunctioning )
{
    m_ui16Param6Malfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsParameter6StatusOn() const
{
    return m_ui16Param6Status;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsParameter6Damaged() const
{
    return m_ui16Param6Dmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::IsParameter6Malfunctioning() const
{
    return m_ui16Param6Malfunction;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_Soviet::operator == ( const FundamentalOperationalData_Soviet & Value ) const
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

KBOOL FundamentalOperationalData_Soviet::operator != ( const FundamentalOperationalData_Soviet & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
