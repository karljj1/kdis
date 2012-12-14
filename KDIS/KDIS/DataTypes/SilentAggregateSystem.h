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
    class:      SilentAggregateSystem
    created:    2009/02/08
    author:     Karl Jones

    purpose:    Contains information about subaggregates not producing
                Aggregate State PDUs.
    size:       96 bits / 12 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./AggregateType.h"
#include <vector>

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT SilentAggregateSystem : public DataTypeBase
{
protected:

    KUINT16 m_ui16NumAggregates;

    AggregateType m_AggTyp;

public:

    static const KUINT16 SILENT_AGGREGATE_SYSTEM_SIZE = 12;

    SilentAggregateSystem( void );

    SilentAggregateSystem( KDataStream & stream ) throw( KException );

    SilentAggregateSystem( KUINT16 NumAggregates, const AggregateType & T );

    virtual ~SilentAggregateSystem( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::SilentAggregateSystem::SetNumberOfAggregates
    //              KDIS::DATA_TYPE::SilentAggregateSystem::GetNumberOfAggregates
    // Description: Number of aggregates of this type.
    // Parameter:   KUINT16 NOA
    //************************************
    void SetNumberOfAggregates( KUINT16 NOA );
    KUINT16 GetNumberOfAggregates() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SilentAggregateSystem::SetAggregateType
    //              KDIS::DATA_TYPE::SilentAggregateSystem::GetAggregateType
    // Description: Aggregate type for this record.
    // Parameter:   const AggregateType & A, void
    //************************************
    void SetAggregateType( const AggregateType & A );
    const AggregateType & GetAggregateType() const;
    AggregateType & GetAggregateType();

    //************************************
    // FullName:    KDIS::DATA_TYPE::SilentAggregateSystem::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SilentAggregateSystem::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::SilentAggregateSystem::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const SilentAggregateSystem & Value ) const;
    KBOOL operator != ( const SilentAggregateSystem & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

