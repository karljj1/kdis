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

#include "./EnumDetonationResult.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

// Implementation of string values for DetonationResult

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor DetonationResultDescriptor[] =
{
    { 0 , "OtherDetonationResult" },
    { 1 , "EntityImpact" },
    { 2 , "EntityProximateDetonation" },
    { 3 , "GroundImpact" },
    { 4 , "GroundProximateDetonation" },
    { 5 , "Detonation" },
    { 6 , "NoneOrNoDetonation_Dud" },
    { 7 , "HEhit_Small" },
    { 8 , "HEhit_Medium" },
    { 9 , "HEhit_Large" },
    { 10 , "Armor_PiercingHit" },
    { 11 , "Dirtblast_Small" },
    { 12 , "Dirtblast_Medium" },
    { 13 , "Dirtblast_Large" },
    { 14 , "Waterblast_Small" },
    { 15 , "Waterblast_Medium" },
    { 16 , "Waterblast_Large" },
    { 17 , "AirHit" },
    { 18 , "BuildingHit_Small" },
    { 19 , "BuildingHit_Medium" },
    { 20 , "BuildingHit_Large" },
    { 21 , "MineClearingLineCharge" },
    { 22 , "EnvironmentObjectImpact" },
    { 23 , "EnvironmentObjectProximateDetonation" },
    { 24 , "WaterImpact" },
    { 25 , "AirBurst" },
    { 26 , "KillWithFragmentType1" },
    { 27 , "KillWithFragmentType2" },
    { 28 , "KillWithFragmentType3" },
    { 29 , "KillWithFragmentType1AfterflyOutFailure" },
    { 30 , "KillWithFragmentType2AfterflyOutFailure" },
    { 31 , "MissDueToflyOutFailure" },
    { 32 , "MissDueToEndGameFailure" },
    { 33 , "MissDueToflyOutAndEndGameFailure" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetonationResult( KINT32 Value )
{
    return GetEnumAsString( DetonationResultDescriptor, sizeof( DetonationResultDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetonationResult( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( DetonationResultDescriptor, sizeof( DetonationResultDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetonationResult( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetonationResult( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}


#endif

#if DIS_VERSION > 6
//////////////////////////////////////////////////////////////////////////

// Implementation of string values for DetonationType

#ifdef KDIS_USE_ENUM_DESCRIPTORS

const EnumDescriptor DetonationTypeDescriptor[] =
{
    { 0 , "MunitionDetonationType" },
    { 1 , "ExpendableDetonationType" },
    { 2 , "NonMunitionExplosionDetonationType" }
};

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetonationType( KINT32 Value )
{
    return GetEnumAsString( DetonationTypeDescriptor, sizeof( DetonationTypeDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetonationType( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( DetonationTypeDescriptor, sizeof( DetonationTypeDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetonationType( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
};

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetonationType( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}

#endif
#endif
