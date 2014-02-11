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
    class:      MunitionDescriptor
    created:    22/04/2013
    author:     Karl Jones

    purpose:    Represents the firing of a a round or a burst of ammunition
                This data type is also referred to as a Burst Descriptor in older versions of DIS.
                This descriptor is applicable to the Fire PDU and Detonation PDU.
    size:       128 bits / 16 octets
*********************************************************************/

#pragma once

#include "./Descriptor.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT MunitionDescriptor : public Descriptor
{
protected:

    KUINT16 m_ui16Warhead;

    KUINT16 m_ui16Fuse;

    KUINT16 m_ui16Quantity;

    KUINT16 m_ui16Rate;

public:

    MunitionDescriptor();

    MunitionDescriptor( KDataStream & stream )throw( KException );

    MunitionDescriptor( const EntityType & T, KDIS::DATA_TYPE::ENUMS::WarheadType WT, 
		                KDIS::DATA_TYPE::ENUMS::FuseType FT, KUINT16 Quantity, KUINT16 Rate );

    virtual ~MunitionDescriptor();

    //************************************
    // FullName:    KDIS::DATA_TYPE::MunitionDescriptor::SetWarhead
    //              KDIS::DATA_TYPE::MunitionDescriptor::GetWarhead
    // Description: Warhead type enumeration.
    // Parameter:   WarheadType WT
    //************************************
    void SetWarhead( KDIS::DATA_TYPE::ENUMS::WarheadType WT );
    KDIS::DATA_TYPE::ENUMS::WarheadType GetWarhead() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MunitionDescriptor::SetFuse
    //              KDIS::DATA_TYPE::MunitionDescriptor::GetFuse
    // Description: Fuse type enumeration.
    // Parameter:   FuseType FT
    //************************************
    void SetFuse( KDIS::DATA_TYPE::ENUMS::FuseType FT );
    KDIS::DATA_TYPE::ENUMS::FuseType GetFuse() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MunitionDescriptor::SetQuantity
    //              KDIS::DATA_TYPE::MunitionDescriptor::GetQuantity
    // Description: Number of rounds fired in the burst.
    // Parameter:   KUINT16 Q
    //************************************
    void SetQuantity( KUINT16 Q );
    KUINT16 GetQuantity() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MunitionDescriptor::SetRate
    //              KDIS::DATA_TYPE::MunitionDescriptor::GetRate
    // Description: Rounds per minute.
    // Parameter:   KUINT16 R
    //************************************
    void SetRate( KUINT16 R );
    KUINT16 GetRate() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MunitionDescriptor::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MunitionDescriptor::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::MunitionDescriptor::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const MunitionDescriptor & Value ) const;
    KBOOL operator != ( const MunitionDescriptor & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
