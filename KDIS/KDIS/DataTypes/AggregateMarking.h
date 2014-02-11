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

class KDIS_EXPORT AggregateMarking : public DataTypeBase
{
protected:

    KUINT8 m_ui8AggregateMarkingCharacterSet;

    KCHAR8 m_sAggregateMarkingString[32]; // Extra octet for terminator, not included in size

public:

    static const KUINT16 AGGREGATE_MARKING_SIZE = 32;

    AggregateMarking();

    AggregateMarking( KDataStream & stream ) throw( KException );

    AggregateMarking( const KDIS::DATA_TYPE::ENUMS::EntityMarkingCharacterSet MarkingCharSet, const KCHAR8 * MarkingText, KUINT16 TextSize ) throw( KException );

    virtual ~AggregateMarking();

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateMarking::SetAggregateMarkingCharacterSet
    //              KDIS::DATA_TYPE::AggregateMarking::GetAggregateMarkingCharacterSet
    // Description: Marking Char set
    // Parameter:   AggregateMarkingCharacterSet EMCS, void
    //************************************
    void SetAggregateMarkingCharacterSet( KDIS::DATA_TYPE::ENUMS::EntityMarkingCharacterSet EMCS );
    KDIS::DATA_TYPE::ENUMS::EntityMarkingCharacterSet GetAggregateMarkingCharacterSet() const;

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

} // END namespace DATA_TYPES
} // END namespace KDIS

