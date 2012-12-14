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

#include "./EntityAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance( void )
{
	m_AppearanceUnion.m_ui326Data = 0;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance( const LandPlatformAppearance & A )
{
	m_AppearanceUnion.m_LandApp = A;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance( const AirPlatformAppearance & A )
{
	m_AppearanceUnion.m_AirApp = A;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance( const SurfacePlatformAppearance & A )
{
	m_AppearanceUnion.m_SurfaceApp = A;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance( const SubSurfacePlatformAppearance & A )
{
	m_AppearanceUnion.m_SubSurfaceApp = A;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance( const SpacePlatformAppearance & A )
{
	m_AppearanceUnion.m_SpaceApp = A;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance( const GuidedMunitionsAppearance & A )
{
	m_AppearanceUnion.m_GuidedMunitionsApp = A;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance( const LifeFormAppearance & A )
{
	m_AppearanceUnion.m_LifeFormApp = A;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance( const EnvironmentalsAppearance & A )
{
	m_AppearanceUnion.m_EnviroApp = A;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance( const CulturalFeatureAppearance & A )
{
	m_AppearanceUnion.m_CultFeatApp = A;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance( const SensorEmitterAppearance & A )
{
	m_AppearanceUnion.m_SensEmitApp = A;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::~EntityAppearance( void )
{
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetData( KUINT32 D )
{
	m_AppearanceUnion.m_ui326Data = D;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 EntityAppearance::GetData() const
{
    return m_AppearanceUnion.m_ui326Data;
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance( const LandPlatformAppearance & A )
{
	m_AppearanceUnion.m_LandApp = A;
}

//////////////////////////////////////////////////////////////////////////

const LandPlatformAppearance & EntityAppearance::GetAppearanceAsLandPlatform() const
{
	return m_AppearanceUnion.m_LandApp;
}

//////////////////////////////////////////////////////////////////////////

LandPlatformAppearance & EntityAppearance::GetAppearanceAsLandPlatform()
{
	return m_AppearanceUnion.m_LandApp;
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance( const AirPlatformAppearance & A )
{
	m_AppearanceUnion.m_AirApp = A;
}

//////////////////////////////////////////////////////////////////////////

const AirPlatformAppearance & EntityAppearance::GetAppearanceAsAirPlatform() const
{
	return m_AppearanceUnion.m_AirApp;
}

//////////////////////////////////////////////////////////////////////////

AirPlatformAppearance & EntityAppearance::GetAppearanceAsAirPlatform()
{
	return m_AppearanceUnion.m_AirApp;
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance( const SurfacePlatformAppearance & A )
{
	m_AppearanceUnion.m_SurfaceApp = A;
}

//////////////////////////////////////////////////////////////////////////

const SurfacePlatformAppearance & EntityAppearance::GetAppearanceAsSurfacePlatform() const
{
	return m_AppearanceUnion.m_SurfaceApp;
}

//////////////////////////////////////////////////////////////////////////

SurfacePlatformAppearance & EntityAppearance::GetAppearanceAsSurfacePlatform()
{
	return m_AppearanceUnion.m_SurfaceApp;
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance( const SubSurfacePlatformAppearance & A )
{
	m_AppearanceUnion.m_SubSurfaceApp = A;
}

//////////////////////////////////////////////////////////////////////////

const SubSurfacePlatformAppearance & EntityAppearance::GetAppearanceAsSubsurfacePlatform() const
{
	return m_AppearanceUnion.m_SubSurfaceApp;
}

//////////////////////////////////////////////////////////////////////////

SubSurfacePlatformAppearance & EntityAppearance::GetAppearanceAsSubsurfacePlatform()
{
	return m_AppearanceUnion.m_SubSurfaceApp;
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance( const SpacePlatformAppearance & A )
{
	m_AppearanceUnion.m_SpaceApp = A;
}

//////////////////////////////////////////////////////////////////////////

const SpacePlatformAppearance & EntityAppearance::GetAppearanceAsSpacePlatform() const
{
	return m_AppearanceUnion.m_SpaceApp;
}

//////////////////////////////////////////////////////////////////////////

SpacePlatformAppearance & EntityAppearance::GetAppearanceAsSpacePlatform()
{
	return m_AppearanceUnion.m_SpaceApp;
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance( const GuidedMunitionsAppearance & A )
{
	m_AppearanceUnion.m_GuidedMunitionsApp = A;
}

//////////////////////////////////////////////////////////////////////////

const GuidedMunitionsAppearance & EntityAppearance::GetAppearanceAsGuidedMuntions() const
{
	return m_AppearanceUnion.m_GuidedMunitionsApp;
}

//////////////////////////////////////////////////////////////////////////

GuidedMunitionsAppearance & EntityAppearance::GetAppearanceAsGuidedMuntions()
{
	return m_AppearanceUnion.m_GuidedMunitionsApp;
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance( const LifeFormAppearance & A )
{
	m_AppearanceUnion.m_LifeFormApp = A;
}

//////////////////////////////////////////////////////////////////////////

const LifeFormAppearance & EntityAppearance::GetAppearanceAsLifeForm() const
{
	return m_AppearanceUnion.m_LifeFormApp;
}

//////////////////////////////////////////////////////////////////////////

LifeFormAppearance & EntityAppearance::GetAppearanceAsLifeForm()
{
	return m_AppearanceUnion.m_LifeFormApp;
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance( const EnvironmentalsAppearance & A )
{
	m_AppearanceUnion.m_EnviroApp = A;
}

//////////////////////////////////////////////////////////////////////////

const EnvironmentalsAppearance & EntityAppearance::GetAppearanceEnvironmentals() const
{
	return m_AppearanceUnion.m_EnviroApp;
}

//////////////////////////////////////////////////////////////////////////

EnvironmentalsAppearance & EntityAppearance::GetAppearanceEnvironmentals()
{
	return m_AppearanceUnion.m_EnviroApp;
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance( const CulturalFeatureAppearance & A )
{
	m_AppearanceUnion.m_CultFeatApp = A;
}

//////////////////////////////////////////////////////////////////////////

const CulturalFeatureAppearance & EntityAppearance::GetAppearanceCultural() const
{
	return m_AppearanceUnion.m_CultFeatApp;
}

//////////////////////////////////////////////////////////////////////////

CulturalFeatureAppearance & EntityAppearance::GetAppearanceCultural()
{
	return m_AppearanceUnion.m_CultFeatApp;
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance( const SensorEmitterAppearance & A )
{
	m_AppearanceUnion.m_SensEmitApp = A;
}

//////////////////////////////////////////////////////////////////////////

const SensorEmitterAppearance & EntityAppearance::GetSensorEmitter() const
{
	return m_AppearanceUnion.m_SensEmitApp;
}

//////////////////////////////////////////////////////////////////////////

SensorEmitterAppearance & EntityAppearance::GetSensorEmitter()
{
	return m_AppearanceUnion.m_SensEmitApp;
}

//////////////////////////////////////////////////////////////////////////

KString EntityAppearance::GetAsString() const
{
    KStringStream ss;

	ss << "Entity Appearance Data: " << m_AppearanceUnion.m_ui326Data << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KString EntityAppearance::GetAsString( const EntityType & EntType ) const
{	
	switch( EntType.GetEntityKind() ) // Kind
	{
		case Platform:					
		switch( EntType.GetDomain() ) // Domain
		{
			case Land:       return m_AppearanceUnion.m_LandApp.GetAsString();
			case Air:        return m_AppearanceUnion.m_AirApp.GetAsString();
			case Surface:    return m_AppearanceUnion.m_SurfaceApp.GetAsString();
			case Subsurface: return m_AppearanceUnion.m_SubSurfaceApp.GetAsString();
			case Space:      return m_AppearanceUnion.m_SpaceApp.GetAsString();
		}

		case Munition: return m_AppearanceUnion.m_GuidedMunitionsApp.GetAsString();

		case Lifeform: return m_AppearanceUnion.m_LifeFormApp.GetAsString();

		case Environmental: return m_AppearanceUnion.m_EnviroApp.GetAsString();

		case Culturalfeature: return m_AppearanceUnion.m_CultFeatApp.GetAsString();

		case SensorEmitter: return m_AppearanceUnion.m_SensEmitApp.GetAsString();
	}    

	// Fall back
	return GetAsString();
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ENTITY_APPEARANCE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

	stream >> m_AppearanceUnion.m_ui326Data;
}

//////////////////////////////////////////////////////////////////////////

KDataStream EntityAppearance::Encode() const
{
    KDataStream stream;

    EntityAppearance::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::Encode( KDataStream & stream ) const
{
	stream << m_AppearanceUnion.m_ui326Data;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityAppearance::operator == ( const EntityAppearance & Value ) const
{
    if( m_AppearanceUnion.m_ui326Data != Value.m_AppearanceUnion.m_ui326Data ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityAppearance::operator != ( const EntityAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
