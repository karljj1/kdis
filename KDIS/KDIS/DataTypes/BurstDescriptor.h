/*********************************************************************
Copyright 2013 KDIS
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
    class:      BurstDescriptor
    created:    09/10/2008
    author:     Karl Jones

    purpose:    Represents the firing of a a round or a burst of ammunition
                This data type is also referred to as a Munition Descriptor in newer versions
                of DIS the standard.
    size:       128 bits / 16 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./EntityType.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::WarheadType;
using KDIS::DATA_TYPE::ENUMS::FuseType;

class KDIS_EXPORT BurstDescriptor : public DataTypeBase
{
protected:

    EntityType m_Munition;

    KUINT16 m_ui16Warhead;

    KUINT16 m_ui16Fuse;

    KUINT16 m_ui16Quantity;

    KUINT16 m_ui16Rate;

public:

    static const KUINT16 BURST_DESCRIPTOR_SIZE = 16;

    BurstDescriptor();

    BurstDescriptor( KDataStream & stream )throw( KException );

    BurstDescriptor( const EntityType & M, WarheadType WT, FuseType FT,
                     KUINT16 Quantity, KUINT16 Rate );

    virtual ~BurstDescriptor();

    //************************************
    // FullName:    KDIS::DATA_TYPE::BurstDescriptor::SetMunition
    //              KDIS::DATA_TYPE::BurstDescriptor::GetMunition
    // Description: Entity DIS enum for the Munition Type.
    // Parameter:   const EntityType & M, void
    //************************************
    void SetMunition( const EntityType & M );
    const EntityType & GetMunition() const;
    EntityType & GetMunition();

    //************************************
    // FullName:    KDIS::DATA_TYPE::BurstDescriptor::SetWarhead
    //              KDIS::DATA_TYPE::BurstDescriptor::GetWarhead
    // Description: Warhead type enumeration.
    // Parameter:   WarheadType WT, void
    //************************************
    void SetWarhead( WarheadType WT );
    WarheadType GetWarhead() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::BurstDescriptor::SetFuse
    //              KDIS::DATA_TYPE::BurstDescriptor::GetFuse
    // Description: Fuse type enumeration.
    // Parameter:   FuseType FT, void
    //************************************
    void SetFuse( FuseType FT );
    FuseType GetFuse() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::BurstDescriptor::SetQuantity
    //              KDIS::DATA_TYPE::BurstDescriptor::GetQuantity
    // Description: Number of rounds fired in the burst.
    // Parameter:   KUINT16 Q, void
    //************************************
    void SetQuantity( KUINT16 Q );
    KUINT16 GetQuantity() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::BurstDescriptor::SetRate
    //              KDIS::DATA_TYPE::BurstDescriptor::GetRate
    // Description: Rounds per minute.
    // Parameter:   KUINT16 R, void
    //************************************
    void SetRate( KUINT16 R );
    KUINT16 GetRate() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::BurstDescriptor::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::BurstDescriptor::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::BurstDescriptor::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const BurstDescriptor & Value ) const;
    KBOOL operator != ( const BurstDescriptor & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
