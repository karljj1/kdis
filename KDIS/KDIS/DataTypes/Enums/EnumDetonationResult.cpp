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

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDetonationResult()
{
	return sizeof( DetonationResultDescriptor ) / sizeof( EnumDescriptor );
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDetonationResult( KUINT32 Index )
{
	return &DetonationResultDescriptor[Index];
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetonationResult( KINT32 Value )
{
    return GetEnumAsString( DetonationResultDescriptor, sizeof( DetonationResultDescriptor ) / sizeof( EnumDescriptor ), Value );
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetonationResult( const KString & Value, KINT32 & ValueOut )
{
	return GetEnumFromString( DetonationResultDescriptor, sizeof( DetonationResultDescriptor ) / sizeof( EnumDescriptor ), Value, ValueOut );
}

#else

KUINT32 KDIS::DATA_TYPE::ENUMS::GetEnumSizeDetonationResult()
{
	return 0;
}

const EnumDescriptor * KDIS::DATA_TYPE::ENUMS::GetEnumDescriptorDetonationResult( KUINT32 Index )
{
	return NULL;
}

KString KDIS::DATA_TYPE::ENUMS::GetEnumAsStringDetonationResult( KINT32 Value )
{
    KStringStream ss;
    ss << Value;
    return ss.str().c_str();
}

KBOOL KDIS::DATA_TYPE::ENUMS::GetEnumFromStringDetonationResult( const KString & Value, KINT32 & ValueOut )
{
	return false; // Maybe throw an exception?
}


#endif

