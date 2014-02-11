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

#include "./EntityAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance()
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

EntityAppearance::~EntityAppearance()
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
