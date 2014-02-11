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
    class:      AggregateIdentifier
    created:    07/02/2009
    author:     Karl Jones

    purpose:    Aggregate Identifier Field. Used only to provide a unique,
                exercise-wide number to identify aggregates and/or to
                address specific simulation applications.
    size:       48 bits / 6 octets
*********************************************************************/

#pragma once

#include "./SimulationIdentifier.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT AggregateIdentifier : public SimulationIdentifier
{
protected:

    KUINT16 m_ui16AggregateID;

public:

    static const KUINT16 AGGREGATE_IDENTIFER_SIZE = 6;

    AggregateIdentifier();

    AggregateIdentifier( KUINT16 SiteID, KUINT16 ApplicatonID, KUINT16 AggregateID );

    AggregateIdentifier( const SimulationIdentifier & SimID, KUINT16 AggregateID );

    AggregateIdentifier( KDataStream & stream ) throw( KException );

    virtual ~AggregateIdentifier();

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateIdentifier::SetAggregateID
    //              KDIS::DATA_TYPE::AggregateIdentifier::GetAggregateID
    // Description: Aggregate ID
    // Parameter:   KUINT16 ID, void
    //************************************
    void SetAggregateID( KUINT16 ID );
    KUINT16 GetAggregateID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateIdentifier::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateIdentifier::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateIdentifier::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const AggregateIdentifier & Value ) const;
    KBOOL operator != ( const AggregateIdentifier & Value ) const;
    KBOOL operator  < ( const AggregateIdentifier & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

