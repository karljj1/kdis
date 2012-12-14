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
    class:      EntityMarking
    created:    22/09/2008
    author:     Karl Jones

    purpose:    Holds entity marking
                Note - Currently only supports ASCII marking text, changes will need
                to be made to support the other sets.
    size:       96 bits / 12 Octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::EntityMarkingCharacterSet;

class KDIS_EXPORT EntityMarking : public DataTypeBase
{
protected:

    KUINT8 m_ui8EntityMarkingCharacterSet;

    KCHAR8 m_sEntityMarkingString[12]; // Extra octet for terminator, not included in size

public:

    static const KUINT16 ENTITY_MARKING_SIZE = 12;

    EntityMarking( void );

    EntityMarking( KDataStream & stream ) throw( KException );

    EntityMarking( const EntityMarkingCharacterSet MarkingCharSet, const KCHAR8 * MarkingText, KUINT16 TextSize ) throw( KException );

	EntityMarking( const EntityMarkingCharacterSet MarkingCharSet, const KString & MarkingText ) throw( KException );

    virtual ~EntityMarking( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityMarking::SetEntityMarkingCharacterSet
    //              KDIS::DATA_TYPE::EntityMarking::GetEntityMarkingCharacterSet
    // Description: Marking Char set
    // Parameter:   EntityMarkingCharacterSet EMCS, void
    //************************************
    void SetEntityMarkingCharacterSet( EntityMarkingCharacterSet EMCS );
    EntityMarkingCharacterSet GetEntityMarkingCharacterSet() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityMarking::SetEntityMarkingString
    //              KDIS::DATA_TYPE::EntityMarking::GetEntityMarkingString
    // Description: Marking string. entity name etc. max 11 characters.. Throws exception if string is too big.
    // Parameter:   const KCHAR8 * EMS, const KString & EMS
    // Parameter:   KUINT16 StringSize
    //************************************
    void SetEntityMarkingString( const KCHAR8 * EMS, KUINT16 StringSize ) throw( KException );
	void SetEntityMarkingString( const KString & EMS ) throw( KException );
    KString GetEntityMarkingString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityMarking::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityMarking::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityMarking::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EntityMarking & Value ) const;
    KBOOL operator != ( const EntityMarking & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

