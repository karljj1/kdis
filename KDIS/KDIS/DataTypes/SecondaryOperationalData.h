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
    class:      SecondaryOperationalData
    created:    2009/03/27
    author:     Karl Jones

    purpose:    Conatains additional data for the IFF/ATC/NAVAIDS emitting
                system and the number of fundamental parameter data sets.
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include <vector>

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT SecondaryOperationalData : public DataTypeBase
{
protected:

    KUINT8 m_ui8Param1;

    KUINT8 m_ui8Param2;

    KUINT16 m_ui16NumFundParamSets;

public:

    static const KUINT16 SECONDARY_OPERATIONAL_DATA_SIZE = 4;

    SecondaryOperationalData();

    SecondaryOperationalData( KDataStream & stream ) throw( KException );

    SecondaryOperationalData( KUINT8 Param1, KUINT8 Param2, KUINT16 NumFundParamSets );

    virtual ~SecondaryOperationalData();

    //************************************
    // FullName:    KDIS::DATA_TYPE::SecondaryOperationalData::SetParameter1
    //              KDIS::DATA_TYPE::SecondaryOperationalData::GetParameter1
    // Description: Operational parameter 1. Represented as an enumeration, only
    //              0 is currently defined as Other.
    // Parameter:   const KUINT8 P, void
    //************************************
    void SetParameter1( KUINT8 P );
    KUINT8 GetParameter1() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SecondaryOperationalData::SetParameter2
    //              KDIS::DATA_TYPE::SecondaryOperationalData::GetParameter2
    // Description: Operational parameter 2. Represented as an enumeration, only
    //              0 is currently defined as Other.
    // Parameter:   const KUINT8 P, void
    //************************************
    void SetParameter2( KUINT8 P );
    KUINT8 GetParameter2() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SecondaryOperationalData::SetNumberOfFundamentalParamSets
    //              KDIS::DATA_TYPE::SecondaryOperationalData::GetNumberOfFundamentalParamSets
    // Description: Returns number of Fundamental Parameter Data Sets
    // Paramter:    KUINT8 NFPDS, void
    //************************************
    void SetNumberOfFundamentalParamSets( KUINT8 NFPDS );
    KUINT16 GetNumberOfFundamentalParamSets() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SecondaryOperationalData::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SecondaryOperationalData::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::SecondaryOperationalData::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const SecondaryOperationalData & Value ) const;
    KBOOL operator != ( const SecondaryOperationalData & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

