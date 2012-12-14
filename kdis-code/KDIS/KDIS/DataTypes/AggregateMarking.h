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
    class:      AggregateMarking
    created:    07/02/2009
    author:     Karl Jones

    purpose:    Holds aggregate marking
                Note - Currently on supports ASCII marking text, changes will need
                to be made to support the other sets.
    size:       256 bits / 32 Octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::EntityMarkingCharacterSet;

class KDIS_EXPORT AggregateMarking : public DataTypeBase
{
protected:

    KUINT8 m_ui8AggregateMarkingCharacterSet;

    KCHAR8 m_sAggregateMarkingString[32]; // Extra octet for terminator, not included in size

public:

    static const KUINT16 AGGREGATE_MARKING_SIZE = 32;

    AggregateMarking( void );

    AggregateMarking( KDataStream & stream ) throw( KException );

    AggregateMarking( const EntityMarkingCharacterSet MarkingCharSet, const KCHAR8 * MarkingText, KUINT16 TextSize ) throw( KException );

    virtual ~AggregateMarking( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateMarking::SetAggregateMarkingCharacterSet
    //              KDIS::DATA_TYPE::AggregateMarking::GetAggregateMarkingCharacterSet
    // Description: Marking Char set
    // Parameter:   AggregateMarkingCharacterSet EMCS, void
    //************************************
    void SetAggregateMarkingCharacterSet( EntityMarkingCharacterSet EMCS );
    EntityMarkingCharacterSet GetAggregateMarkingCharacterSet() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateMarking::SetAggregateMarkingString
    //              KDIS::DATA_TYPE::AggregateMarking::GetAggregateMarkingString
    // Description: Marking string. entity name etc. max 31 octets/chars
    // Parameter:   const KCHAR8 * EMS, void
    // Parameter:   KUINT16 StringSize, void
    //************************************
    void SetAggregateMarkingString( const KCHAR8 * M, KUINT16 StringSize );
    KString GetAggregateMarkingString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateMarking::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateMarking::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateMarking::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const AggregateMarking & Value ) const;
    KBOOL operator != ( const AggregateMarking & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

