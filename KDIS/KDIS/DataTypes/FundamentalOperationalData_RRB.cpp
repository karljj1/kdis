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

#include "./FundamentalOperationalData_RRB.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetSystemStatus( KBOOL IsSystemOn, KBOOL IsResponseCapable, KBOOL IsParam2Capable,
        KBOOL IsParam3Capable, KBOOL IsParam4Capable, KBOOL IsParam5Capable,
        KBOOL IsParam6Capable, KBOOL IsOperational )
{
    m_ui8SystemOnOff = IsSystemOn;

    // Values flipped as 0 means capable and 1 not capable.
    m_ui8Param1 = !IsResponseCapable;
    m_ui8Param2 = !IsParam2Capable;
    m_ui8Param3 = !IsParam3Capable;
    m_ui8Param4 = !IsParam4Capable;
    m_ui8Param5 = !IsParam5Capable;
    m_ui8Param6 = !IsParam6Capable;
    m_ui8OpsStatus = !IsOperational;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetSystemStatusSystemOn( KBOOL IsSystemOn )
{
    m_ui8SystemOnOff = IsSystemOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetSystemStatusParam1Capable( KBOOL IsParamCapable )
{
    m_ui8Param1 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetSystemStatusParam2Capable( KBOOL IsParamCapable )
{
    m_ui8Param2 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetSystemStatusParam3Capable( KBOOL IsParamCapable )
{
    m_ui8Param3 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetSystemStatusParam4Capable( KBOOL IsParamCapable )
{
    m_ui8Param4 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetSystemStatusParam5Capable( KBOOL IsParamCapable )
{
    m_ui8Param5 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetSystemStatusParam6Capable( KBOOL IsParamCapable )
{
    m_ui8Param6 = !IsParamCapable;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetSystemStatusIsOperational( KBOOL IsOperational )
{
    m_ui8OpsStatus = !IsOperational;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_RRB::GetSystemStatusSystemOn() const
{
    return m_ui8SystemOnOff;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_RRB::GetSystemStatusParam1Capable() const
{
    return !m_ui8Param1;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_RRB::GetSystemStatusParam2Capable() const
{
    return !m_ui8Param2;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_RRB::GetSystemStatusParam3Capable() const
{
    return !m_ui8Param3;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_RRB::GetSystemStatusParam4Capable() const
{
    return !m_ui8Param4;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_RRB::GetSystemStatusParam5Capable() const
{
    return !m_ui8Param5;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_RRB::GetSystemStatusParam6Capable() const
{
    return !m_ui8Param6;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_RRB::GetSystemStatusIsOperational() const
{
    return !m_ui8OpsStatus;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetInfomationLayersPresence( KBOOL IsLayer1Present, KBOOL IsLayer2Present )
{
    m_ui8Layer1 = IsLayer1Present;
    m_ui8Layer2 = IsLayer2Present;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetInfomationLayer1( KBOOL IsPresent )
{
    m_ui8Layer1 = IsPresent;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetInfomationLayer2( KBOOL IsPresent )
{
    m_ui8Layer2 = IsPresent;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_RRB::IsInfomationLayer1Present() const
{
    return m_ui8Layer1;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_RRB::IsInfomationLayer2Present() const
{
    return m_ui8Layer2;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetResponse( KUINT8 Code, KBOOL PowerReduction, KBOOL RadarEnhancement,
        KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning )
{
    m_ui16ResponseCode = Code;
    m_ui16ResponsePowerReduction = PowerReduction;
    m_ui16ResponseRadarEnhancement = RadarEnhancement;
    m_ui16ResponseStatus = IsStatusOn;
    m_ui16ResponseDmg = IsDamaged;
    m_ui16ResponseMalfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetResponseCode( KUINT8 C )
{
    m_ui16ResponseCode = C;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetResponsePowerReduction( KBOOL PR )
{
    m_ui16ResponsePowerReduction = PR;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetResponseRadarEnhancement( KBOOL RE )
{
    m_ui16ResponseRadarEnhancement = RE;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetResponseStatus( KBOOL IsOn )
{
    m_ui16ResponseStatus = IsOn;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetResponseDamage( KBOOL IsDamaged )
{
    m_ui16ResponseDmg = IsDamaged;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData_RRB::SetResponseMalfunction( KBOOL IsMalfunctioning )
{
    m_ui16ResponseMalfunction = IsMalfunctioning;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 FundamentalOperationalData_RRB::GetResponseCode() const
{
    return m_ui16ResponseCode;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_RRB::GetResponsePowerReduction() const
{
    return m_ui16ResponsePowerReduction;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_RRB::GetResponseRadarEnhancement() const
{
    return m_ui16ResponseRadarEnhancement;
}
//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_RRB::IsResponseStatusOn() const
{
    return m_ui16ResponseStatus;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_RRB::IsResponseDamaged() const
{
    return m_ui16ResponseDmg;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_RRB::IsResponseMalfunctioning() const
{
    return m_ui16ResponseMalfunction;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData_RRB::operator == ( const FundamentalOperationalData_RRB & Value ) const
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

KBOOL FundamentalOperationalData_RRB::operator != ( const FundamentalOperationalData_RRB & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
