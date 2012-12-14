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

    BurstDescriptor( void );

    BurstDescriptor( KDataStream & stream )throw( KException );

    BurstDescriptor( const EntityType & M, WarheadType WT, FuseType FT,
                     KUINT16 Quantity, KUINT16 Rate );

    virtual ~BurstDescriptor( void );

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS
