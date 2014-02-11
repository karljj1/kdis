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
    class:      Supplies
    created:    22/09/2008
    author:     Karl Jones

    purpose:    Represents a supply and its quantity
    size:       96 Bits / 12 Octets
*********************************************************************/

#pragma once

#include "./EntityType.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT Supplies : public EntityType
{
protected:

    KFLOAT32 m_f32Quantity;

public:

    static const KUINT16 SUPPLIES_SIZE = 12;

    Supplies();

    Supplies( KDIS::DATA_TYPE::ENUMS::EntityKind Kind, KUINT8 Domain, KDIS::DATA_TYPE::ENUMS::Country Country, 
			  KUINT8 Categoy, KUINT8 SubCategory, KUINT8 Specific, KUINT8 Extra, KFLOAT32 Quantity );

    Supplies( EntityType Type, KFLOAT32 Quantity );

    Supplies( KDataStream & stream ) throw( KException );

    virtual ~Supplies();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Supplies::SetQuantity
    //              KDIS::DATA_TYPE::Supplies::GetQuantity
    // Description: Quantity for selected supply.
    // Parameter:   KFLOAT32  F, void
    //************************************
    void SetQuantity( KFLOAT32 F );
    KFLOAT32 GetQuantity() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Supplies::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::DataTypeBase::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::Supplies::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Supplies & Value ) const;
    KBOOL operator != ( const Supplies & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
