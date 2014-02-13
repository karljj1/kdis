/**********************************************************************
The following UNLICENSE statement applies to this example.

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>
*********************************************************************/

#pragma once

#include "KDIS/PDU/Entity_Info_Interaction/Entity_State_PDU.h" 
#include "KDIS/PDU/Bundle.h"

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace PDU;
using namespace ENUMS;
using namespace UTILS;

class EntityGenerator
{
private:

	static int id;

public:

	//************************************
	// FullName:    GenerateEntity
	// Description: Creates a random Entity_State_PDU.
	//************************************
	static Entity_State_PDU GenerateEntity()
	{
		// Generate a new value to use for our entity. Id, name, pos etc.
		KUINT16 randomValue = ++id;

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
		// Generate a new value to use for our entity. Id, name, pos etc.
		KUINT16 randomValue = ++id;

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

// Init id variable
int EntityGenerator::id = 0;