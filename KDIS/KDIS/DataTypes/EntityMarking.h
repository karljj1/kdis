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

class KDIS_EXPORT EntityMarking : public DataTypeBase
{
protected:

    KUINT8 m_ui8EntityMarkingCharacterSet;

    KCHAR8 m_sEntityMarkingString[12]; // Extra octet for terminator, not included in size

public:

    static const KUINT16 ENTITY_MARKING_SIZE = 12;

    EntityMarking();

    EntityMarking( KDataStream & stream ) throw( KException );

    EntityMarking( const KDIS::DATA_TYPE::ENUMS::EntityMarkingCharacterSet MarkingCharSet, const KCHAR8 * MarkingText, KUINT16 TextSize ) throw( KException );

	EntityMarking( const KDIS::DATA_TYPE::ENUMS::EntityMarkingCharacterSet MarkingCharSet, const KString & MarkingText ) throw( KException );

    virtual ~EntityMarking();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EntityMarking::SetEntityMarkingCharacterSet
    //              KDIS::DATA_TYPE::EntityMarking::GetEntityMarkingCharacterSet
    // Description: Marking Char set
    // Parameter:   EntityMarkingCharacterSet EMCS, void
    //************************************
    void SetEntityMarkingCharacterSet( KDIS::DATA_TYPE::ENUMS::EntityMarkingCharacterSet EMCS );
    KDIS::DATA_TYPE::ENUMS::EntityMarkingCharacterSet GetEntityMarkingCharacterSet() const;

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

} // END namespace DATA_TYPES
} // END namespace KDIS

