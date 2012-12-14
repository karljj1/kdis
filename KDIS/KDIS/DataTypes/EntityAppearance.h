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

/********************************************************************
    class:      EntityAppearance
    created:    22/09/2008 - Updated July 2012
    author:     Karl Jones

    purpose:    Represents an entity appearance using bit fields.
				This class has had a significant upgrade, I have removed general
				and specific appearance types. Each type now has a single appearance type.
    size:       32 Bits / 4 Octet
*********************************************************************/

#pragma once

#include "./LandPlatformAppearance.h"
#include "./AirPlatformAppearance.h"
#include "./SurfacePlatformAppearance.h"
#include "./SubSurfacePlatformAppearance.h"
#include "./SpacePlatformAppearance.h"
#include "./GuidedMunitionsAppearance.h"
#include "./LifeFormAppearance.h"
#include "./EnvironmentalsAppearance.h"
#include "./CulturalFeatureAppearance.h"
#include "./SensorEmitterAppearance.h"
#include "./EntityType.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT EntityAppearance : public DataTypeBase
{
protected:

	union
    {
        LandPlatformAppearance         m_LandApp; 
        AirPlatformAppearance          m_AirApp;
        SurfacePlatformAppearance      m_SurfaceApp;
        SubSurfacePlatformAppearance   m_SubSurfaceApp;
        SpacePlatformAppearance        m_SpaceApp;
        GuidedMunitionsAppearance      m_GuidedMunitionsApp;
        LifeFormAppearance             m_LifeFormApp;
        EnvironmentalsAppearance       m_EnviroApp;
		CulturalFeatureAppearance      m_CultFeatApp;	
		SensorEmitterAppearance        m_SensEmitApp;
        KUINT32                        m_ui326Data;
    } m_AppearanceUnion;    

public:

    static const KUINT16 ENTITY_APPEARANCE_SIZE = 4;

    EntityAppearance( void );

    EntityAppearance( KDataStream & stream ) throw( KException );

	EntityAppearance( const LandPlatformAppearance & A );

	EntityAppearance( const AirPlatformAppearance & A );

	EntityAppearance( const SurfacePlatformAppearance & A );

	EntityAppearance( const SubSurfacePlatformAppearance & A );

	EntityAppearance( const SpacePlatformAppearance & A );

	EntityAppearance( const GuidedMunitionsAppearance & A );

	EntityAppearance( const LifeFormAppearance & A );

	EntityAppearance( const EnvironmentalsAppearance & A );		

	EntityAppearance( const CulturalFeatureAppearance & A );		

	EntityAppearance( const SensorEmitterAppearance & A );

    virtual ~EntityAppearance( void );

	//************************************
    // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetData
    //              KDIS::DATA_TYPE::EntityAppearance::GetData
    // Description: This is the raw appearance field. Each bit is interpreted differently depending
	//              on the appearance type.
	//              You will likely never need to touch this value unless something is missing from 
	//              one of my appearance types or you are using a field in a none standard way.
    // Parameter:   KUINT32 D
    //************************************
    void SetData( KUINT32 D );
    KUINT32 GetData() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance    
	//              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceAsLandPlatform    
    // Description: Get/Set the appearance data as a land platform.
    // Parameter:   const LandPlatformAppearance & A
    //************************************
	void SetAppearance( const LandPlatformAppearance & A );
	const LandPlatformAppearance & GetAppearanceAsLandPlatform() const;
	LandPlatformAppearance & GetAppearanceAsLandPlatform();
	
	//************************************
    // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance    
	//              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceAsAirPlatform    
    // Description: Get/Set the appearance data as a air platform.
    // Parameter:   const AirPlatformAppearance & A
    //************************************
	void SetAppearance( const AirPlatformAppearance & A );
	const AirPlatformAppearance & GetAppearanceAsAirPlatform() const;
	AirPlatformAppearance & GetAppearanceAsAirPlatform();

	//************************************
    // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance    
	//              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceAsSurfacePlatform    
    // Description: Get/Set the appearance data as a surface platform.
    // Parameter:   const SurfacePlatformAppearance & A
    //************************************
	void SetAppearance( const SurfacePlatformAppearance & A );
	const SurfacePlatformAppearance & GetAppearanceAsSurfacePlatform() const;
	SurfacePlatformAppearance & GetAppearanceAsSurfacePlatform();

	//************************************
    // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance    
	//              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceAsSubsurfacePlatform    
    // Description: Get/Set the appearance data as subsurface platform.
    // Parameter:   const SubSurfacePlatformAppearance & A
    //************************************	
	void SetAppearance( const SubSurfacePlatformAppearance & A );
	const SubSurfacePlatformAppearance & GetAppearanceAsSubsurfacePlatform() const;
	SubSurfacePlatformAppearance & GetAppearanceAsSubsurfacePlatform();	
	
	//************************************
    // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance    
	//              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceAsSpacePlatform    
    // Description: Get/Set the appearance data as space platform.
    // Parameter:   const SpacePlatformAppearance & A
    //************************************	
	void SetAppearance( const SpacePlatformAppearance & A );
	const SpacePlatformAppearance & GetAppearanceAsSpacePlatform() const;
	SpacePlatformAppearance & GetAppearanceAsSpacePlatform();	

	//************************************
    // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance    
	//              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceAsGuidedMuntions    
    // Description: Get/Set the appearance data as guided muntions.
    // Parameter:   const GuidedMunitionsAppearance & A
    //************************************	
	void SetAppearance( const GuidedMunitionsAppearance & A );
	const GuidedMunitionsAppearance & GetAppearanceAsGuidedMuntions() const;
	GuidedMunitionsAppearance & GetAppearanceAsGuidedMuntions();	

	//************************************
    // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance    
	//              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceAsLifeForm    
    // Description: Get/Set the appearance data as life form.
    // Parameter:   const LifeFormAppearance & A
    //************************************	
	void SetAppearance( const LifeFormAppearance & A );
	const LifeFormAppearance & GetAppearanceAsLifeForm() const;
	LifeFormAppearance & GetAppearanceAsLifeForm();	

	//************************************
    // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance    
	//              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceEnvironmentals    
    // Description: Get/Set the appearance data as environmentals.
    // Parameter:   const EnvironmentalsAppearance & A
    //************************************	
	void SetAppearance( const EnvironmentalsAppearance & A );
	const EnvironmentalsAppearance & GetAppearanceEnvironmentals() const;
	EnvironmentalsAppearance & GetAppearanceEnvironmentals();	

	//************************************
    // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance    
	//              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceCultural    
    // Description: Get/Set the appearance data as cultural feature.
    // Parameter:   const CulturalFeatureAppearance & A
    //************************************	
	void SetAppearance( const CulturalFeatureAppearance & A );
	const CulturalFeatureAppearance & GetAppearanceCultural() const;
	CulturalFeatureAppearance & GetAppearanceCultural();	

	//************************************
    // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance    
	//              KDIS::DATA_TYPE::EntityAppearance::GetSensorEmitter    
    // Description: Get/Set the appearance data as a Sensor/Emitter.
    // Parameter:   const SensorEmitterAppearance & A
    //************************************	
	void SetAppearance( const SensorEmitterAppearance & A );
	const SensorEmitterAppearance & GetSensorEmitter() const;
    SensorEmitterAppearance & GetSensorEmitter();	

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityAppearance::GetAsString
    // Description: Returns a string representation of the appearance. 
	//              This verson just returns the data as an integer.
    // Parameter:   const EntityType & EntType
    //************************************
	virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityAppearance::GetAsString
    // Description: Returns a string representation of the appearance based on type.
    // Parameter:   const EntityType & EntType
    //************************************
    KString GetAsString( const EntityType & EntType ) const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityAppearance::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityAppearance::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EntityAppearance & Value ) const;
    KBOOL operator != ( const EntityAppearance & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
