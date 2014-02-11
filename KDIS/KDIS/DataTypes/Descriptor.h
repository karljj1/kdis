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
    class:      Descriptor
    created:    22/04/2013
    author:     Karl Jones

    purpose:    Base class for Descriptor records.  

				In DIS < 7:
				All descriptors should use the Munition Descriptor record AKA Burst descriptor.

				In DIS  7 onwards:
				A Fire PDU descriptor can be either a Munition(AKA Burst) or an Expendable descriptor.
				A Detonation PDU descriptor can be either a Munition(AKA Burst), Expendable or an Explosion descriptor.
				
    size:       128 bits / 16 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./EntityType.h"
#include "./../Extras/KRef_Ptr.h"

namespace KDIS {
namespace DATA_TYPE {

/************************************************************************/
// Define the type of pointer we are using for Descriptor Records,
// do we want a weak reference or a ref counter?
// By default we use a ref pointer, however if you want to use a standard
// pointer or one of your own then simply change it below.
/************************************************************************/
class Descriptor;
typedef KDIS::UTILS::KRef_Ptr<Descriptor> DescPtr; // Ref counter
//typedef Descriptor* DescPtr; // Weak ref

#if DIS_VERSION > 6 
typedef Descriptor ExpendableDescriptor;
#endif

class KDIS_EXPORT Descriptor : public DataTypeBase
{
protected:

    EntityType m_Type;

public:

    static const KUINT16 DESCRIPTOR_SIZE = 16;

    Descriptor();

    Descriptor( KDataStream & stream )throw( KException );

    Descriptor( const EntityType & T );

    virtual ~Descriptor();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Descriptor::SetMunition
    //              KDIS::DATA_TYPE::Descriptor::GetMunition
    // Description: Munition, Explosion or Expendable Type.
    // Parameter:   const EntityType & T
    //************************************
    void SetType( const EntityType & T );
    const EntityType & GetType() const;
    EntityType & GetType();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Descriptor::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Descriptor::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::Descriptor::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Descriptor & Value ) const;
    KBOOL operator != ( const Descriptor & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
