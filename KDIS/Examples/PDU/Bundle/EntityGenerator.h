#pragma once

#include "KDIS/PDU/Entity_Info_Interaction/Entity_State_PDU.h" 
#include "KDIS/PDU/Bundle.h"
#include <math.h>

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace PDU;
using namespace ENUMS;
using namespace UTILS;

class EntityGenerator
{
public:

	//************************************
	// FullName:    GenerateEntity
	// Description: Creates a random Entity_State_PDU.
	//************************************
	static Entity_State_PDU GenerateEntity()
	{
		// Generate a random value to use for our entity. Id, name, pos etc.
		KUINT16 randomValue = rand();

		// First create the PDU we are going to send, for this example I will use a
		// Entity_State_PDU, When this PDU is sent most DIS applications should then show a new entity
		EntityIdentifier EntID( 1, 3001, randomValue );
		ForceID EntForceID( Friendly );
		EntityType EntType( 3, 1, 225, 3, 0, 1, 0 ); // A Civilian male
		Vector EntityLinearVelocity( 0, 0, 0 );

		// Location 
		KFLOAT64 GeoX = 3974445.65712107, GeoY = 220612.57183252, GeoZ = 4966838.38051275; // Cardiff 
		KFLOAT64 Heading = 0.0, Pitch = 0.0, Roll = 0.0;
		WorldCoordinates EntityLocation( GeoX, GeoY, GeoZ );

		// Appearance
		EntityAppearance EntEA; 
		DeadReckoningParameter DRP( Static, Vector( 0, 0, 0 ), Vector( 0, 0, 0 ) );
		KStringStream name;
		name << "Ent-" << randomValue;
		EntityMarking EntMarking( ASCII, name.str() );
		EntityCapabilities EntEC( false, false, false, false );

		// Create the PDU
		Entity_State_PDU Entity( EntID, EntForceID, EntType, EntType, EntityLinearVelocity, EntityLocation,
								 EulerAngles(), EntEA, DRP, EntMarking, EntEC );

		// Set the PDU Header values
		Entity.SetExerciseID( 1 );

		// Set the time stamp to automatically calculate each time encode is called.
		Entity.SetTimeStamp( TimeStamp( RelativeTime, 0, true ) );

		return Entity;
	}

	//************************************
	// FullName:    GenerateEntity
	// Description: Creates a random Entity_State_PDU and returns it as a ref pointer.
	//************************************
	static PduPtr GenerateEntityRef()
	{
		// Generate a random value to use for our entity. Id, name, pos etc.
		KUINT16 randomValue = rand();

		// First create the PDU we are going to send, for this example I will use a
		// Entity_State_PDU, When this PDU is sent most DIS applications should then show a new entity
		EntityIdentifier EntID( 1, 3001, randomValue );
		ForceID EntForceID( Friendly );
		EntityType EntType( 3, 1, 225, 3, 0, 1, 0 ); // A Civilian male
		Vector EntityLinearVelocity( 0, 0, 0 );

		// Location 
		KFLOAT64 GeoX = 3974445.65712107, GeoY = 220612.57183252, GeoZ = 4966838.38051275; // Cardiff 
		KFLOAT64 Heading = 0.0, Pitch = 0.0, Roll = 0.0;
		WorldCoordinates EntityLocation( GeoX, GeoY, GeoZ );

		// Appearance
		EntityAppearance EntEA; 
		DeadReckoningParameter DRP( Static, Vector( 0, 0, 0 ), Vector( 0, 0, 0 ) );
		KStringStream name;
		name << "Ent-" << randomValue;
		EntityMarking EntMarking( ASCII, name.str() );
		EntityCapabilities EntEC( false, false, false, false );

		// Create the PDU
		PduPtr pEntity( new Entity_State_PDU( EntID, EntForceID, EntType, EntType, EntityLinearVelocity,
                        EntityLocation, EulerAngles(), EntEA, DRP, EntMarking, EntEC ) );

		// Set the PDU Header values
		pEntity->SetExerciseID( 1 );

		// Set the time stamp to automatically calculate each time encode is called.
		pEntity->SetTimeStamp( TimeStamp( RelativeTime, 0, true ) );

		return pEntity;
	}
};