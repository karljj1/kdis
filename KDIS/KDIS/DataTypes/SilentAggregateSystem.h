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

    KUINT16 m_ui16Padding;

    AggregateType m_AggTyp;

public:

    static const KUINT16 SILENT_AGGREGATE_SYSTEM_SIZE = 12;

    SilentAggregateSystem();

    SilentAggregateSystem( KDataStream & stream ) throw( KException );

    SilentAggregateSystem( KUINT16 NumAggregates, const AggregateType & T );

    virtual ~SilentAggregateSystem();

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

} // END namespace DATA_TYPES
} // END namespace KDIS

