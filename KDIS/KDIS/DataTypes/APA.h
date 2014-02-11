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
    class:      APA
    created:    2009/01/05
    author:     Karl Jones

    purpose:    Additional Passive Activity ( APA )
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT APA : public DataTypeBase
{
protected:

    union
    {
        struct
        {
            KUINT16 m_ui16APPI    : 14;
            KUINT16 m_ui16Status2 : 1;
            KUINT16 m_ui16Status1 : 1;
        };
        KUINT16 m_ui16ParamIndex;
    }m_ApaUnion;

    KINT16 m_i16Value;

public:

    static const KUINT16 APA_SIZE = 4;

    APA();

    APA( KDataStream & stream ) throw( KException );

    APA( KDIS::DATA_TYPE::ENUMS::AdditionalPassiveParameterIndex APPI, KBOOL Val1, KBOOL Val2, KINT16 Value );

    virtual ~APA();

    //************************************
    // FullName:    KDIS::DATA_TYPE::APA::SetAPPI
    //              KDIS::DATA_TYPE::APA::GetAPPI
    // Description: Indicates which database record ( or file ) shall be used to describe
    //              an additional acoustic source such as transient effects, pre-launch
    //              data( i.e torpedo tube floodings ), additional sources, and the
    //              states available for each source type. This index shall be used to
    //              identify data from databases such as the Special Event Database
    //              ( SEDB )and an Additional Narrow band Database ( ANDB ).
    // Parameter:   AdditionalPassiveParameterIndex RPM, void
    //************************************
    void SetAPPI( KDIS::DATA_TYPE::ENUMS::AdditionalPassiveParameterIndex APPI );
    KDIS::DATA_TYPE::ENUMS::AdditionalPassiveParameterIndex GetAPPI() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::APA::SetStatus
    //              KDIS::DATA_TYPE::APA::GetStatus
    // Description: The left most 2 bits are used to indicate
    //              on/off/change status of the record.
    //              A value of ( 1, 1 ) shall be used to indicate
    //              the record shall be activated commensurate
    //              with the conditions in the database and the following APA value
    //              field. A value of ( 0, 0 ) shall be used to indicate
    //              that the record has been deselected or turned off.
    //              A value of ( 1, 0 ) shall indicate a state change has occurred.
    //              A value of ( 0, 1 ) shall indicate the state has not
    //              changed, but the corresponding APA value field has changed.
    // Parameter:   KBOOL Val1, void
    // Parameter:   KBOOL Val2
    //************************************
    void SetStatus( KBOOL Val1, KBOOL Val2 );
    KBOOL GetStatusVal1() const;
    KBOOL GetStatusVal2() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::APA::SetValue
    //              KDIS::DATA_TYPE::APA::GetValue
    // Description: Represents the value of a state change
    //              defined in the APA param index field.
    // Parameter:   KINT16 V, void
    //************************************
    void SetValue( KINT16 V );
    KINT16 GetValue() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::APA::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::APA::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::APA::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const APA & Value ) const;
    KBOOL operator != ( const APA & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

