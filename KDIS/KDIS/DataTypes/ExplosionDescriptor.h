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

/********************************************************************
    class:      ExplosionDescriptor
    created:    22/04/2013
    author:     Karl Jones

    purpose:    Represents the explosion of a non-munition.
	            The exploding object may be an entity for which an Entity State PDU 
				has been issued or may be an articulated or attached part of an entity.
				If it is necessary to provide more details of the characteristics ofthe explosion,
				one or more VP records may be developed and included in the VP record section of
				the Detonation PDU to convey such information. 
				
				NOTE: Any munition that explodes, whether for its intended purpose or not, is 
				represented by the Munition Descriptor record and not an Explosion Description record.
	
                This descriptor is applicable to the Detonation PDU.

    size:       128 bits / 16 octets
*********************************************************************/

#pragma once

#include "./Descriptor.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT ExplosionDescriptor : public Descriptor
{
protected:

    KUINT16 m_ui16ExplMat;

	KUINT16 m_ui16Padding;

	KFLOAT32 m_f32ExplForce;

public:

    ExplosionDescriptor();

    ExplosionDescriptor( KDataStream & stream )throw( KException );

    ExplosionDescriptor( const EntityType & T, KDIS::DATA_TYPE::ENUMS::ExplosiveMaterial EM, KFLOAT32 Force );                         

    virtual ~ExplosionDescriptor();

    //************************************
    // FullName:    KDIS::DATA_TYPE::ExplosionDescriptor::SetExplosiveMaterial
    //              KDIS::DATA_TYPE::ExplosionDescriptor::GetExplosiveMaterial
    // Description: Indicates the material that exploded. 
    // Parameter:   ExplosiveMaterial EM
    //************************************
    void SetExplosiveMaterial( KDIS::DATA_TYPE::ENUMS::ExplosiveMaterial EM );
    KDIS::DATA_TYPE::ENUMS::ExplosiveMaterial GetExplosiveMaterial() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ExplosionDescriptor::SetExplosiveForce
    //              KDIS::DATA_TYPE::ExplosionDescriptor::GetExplosiveForce
    // Description: The explosive force expressed as the equivalent kilograms
	//              of TNT (4.184 x 106 Joules per kilogram). 
    // Parameter:   ExplosiveMaterial EM
    //************************************
    void SetExplosiveForce( KFLOAT32 F );
    KFLOAT32 GetExplosiveForce() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ExplosionDescriptor::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ExplosionDescriptor::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ExplosionDescriptor::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const ExplosionDescriptor & Value ) const;
    KBOOL operator != ( const ExplosionDescriptor & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
