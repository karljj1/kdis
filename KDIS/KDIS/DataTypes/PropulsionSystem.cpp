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

#include "./PropulsionSystem.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

PropulsionSystem::PropulsionSystem( void ) :
    m_f32PowerSetting( 0 ),
    m_f32EngineRPM( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

PropulsionSystem::PropulsionSystem( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

PropulsionSystem::PropulsionSystem( KFLOAT32 PowerSetting, KFLOAT32 EngineRPM ) :
    m_f32PowerSetting( PowerSetting ),
    m_f32EngineRPM( EngineRPM )
{
}

//////////////////////////////////////////////////////////////////////////

PropulsionSystem::~PropulsionSystem( void )
{
}

//////////////////////////////////////////////////////////////////////////

void PropulsionSystem::SetPowerSetting( KFLOAT32 PS )
{
    m_f32PowerSetting = PS;
}

//////////////////////////////////////////////////////////////////////////

void PropulsionSystem::SetPowerSetting( PowerSettingAircraft PS )
{
    m_f32PowerSetting = PS;
}

//////////////////////////////////////////////////////////////////////////

void PropulsionSystem::SetPowerSetting( PowerSettingHelicopter PS )
{
    m_f32PowerSetting = PS;
}

//////////////////////////////////////////////////////////////////////////

void PropulsionSystem::SetPowerSetting( ActiveEmissionParameterIndex PS )
{
    m_f32PowerSetting = PS;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 PropulsionSystem::GetPowerSetting() const
{
    return m_f32PowerSetting;
}

//////////////////////////////////////////////////////////////////////////

void PropulsionSystem::SetEngineRPM( KFLOAT32 RPM )
{
    m_f32EngineRPM = RPM;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 PropulsionSystem::GetEngineRPM() const
{
    return m_f32EngineRPM;
}

//////////////////////////////////////////////////////////////////////////

KString PropulsionSystem::GetAsString() const
{
    KStringStream ss;

    ss << "Propulsion System:"
       << "\n\tPower Setting:  " << m_f32PowerSetting
       << "\n\tEngine RPM:     " << m_f32EngineRPM
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void PropulsionSystem::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < PROPULSION_SYSTEM_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_f32PowerSetting
           >> m_f32EngineRPM;
}

//////////////////////////////////////////////////////////////////////////

KDataStream PropulsionSystem::Encode() const
{
    KDataStream stream;

    PropulsionSystem::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void PropulsionSystem::Encode( KDataStream & stream ) const
{
    stream << m_f32PowerSetting
           << m_f32EngineRPM;
}

//////////////////////////////////////////////////////////////////////////

KBOOL PropulsionSystem::operator == ( const PropulsionSystem & Value ) const
{
    if( m_f32PowerSetting  != Value.m_f32PowerSetting ) return false;
    if( m_f32EngineRPM     != Value.m_f32EngineRPM )    return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL PropulsionSystem::operator != ( const PropulsionSystem & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////



