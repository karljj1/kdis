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
    class:      EncodingScheme
    created:    18/09/2008
    author:     Karl Jones

    purpose:    Scheme used to encode a set of data.

    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT EncodingScheme : public DataTypeBase
{
protected:

    union
    {
        struct
        {
            KUINT16 m_ui16Type  : 14;
            KUINT16 m_ui16Class : 2;
        };
        KUINT16 m_ui16EncodingScheme;
    } m_EncodingSchemeUnion;

    KUINT16 m_ui16TDLType;

public:

    static const KUINT16 ENCODING_SCHEME_SIZE = 4;

    EncodingScheme();

    EncodingScheme( KDataStream & stream ) throw( KException );

    EncodingScheme( KDIS::DATA_TYPE::ENUMS::EncodingClass EC, KUINT16 EncodingType, KDIS::DATA_TYPE::ENUMS::TDLType T );

    EncodingScheme( KDIS::DATA_TYPE::ENUMS::EncodingType Audio, KDIS::DATA_TYPE::ENUMS::TDLType T );

    virtual ~EncodingScheme();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EncodingScheme::SetEncodingClass
    //              KDIS::DATA_TYPE::EncodingScheme::GetEncodingClass
    // Description: Encoding Class
    // Parameter:   EncodingClass EC
    //************************************
    void SetEncodingClass( KDIS::DATA_TYPE::ENUMS::EncodingClass EC );
    KDIS::DATA_TYPE::ENUMS::EncodingClass GetEncodingClass() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EncodingScheme::SetEncodingTypeAudio
    //              KDIS::DATA_TYPE::EncodingScheme::SetEncodingType
	//              KDIS::DATA_TYPE::EncodingScheme::GetEncodingTypeAudio
	//              KDIS::DATA_TYPE::EncodingScheme::GetEncodingType
    // Description: When using encoded audio use an encoding type.
    //              Can also be used to represent the number of TDL
    //              (Tactical Data Links). If encoded class is not audio
    //              and the TDL type is 0 then this value should also be 0.
    // Parameter:   EncodingType T, KUINT16 T
    //************************************
    void SetEncodingTypeAudio( KDIS::DATA_TYPE::ENUMS::EncodingType T );
    void SetEncodingType( KUINT16 T );
    KDIS::DATA_TYPE::ENUMS::EncodingType GetEncodingTypeAudio() const;
    KUINT16 GetEncodingType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EncodingScheme::SetTDLType
    //              KDIS::DATA_TYPE::EncodingScheme::GetTDLType
    // Description: Tactical Data Link Type if the encoding class is
    //              representing a TDL type, if not then set to 0.
    // Parameter:   TDLType T
    //************************************
    void SetTDLType( KDIS::DATA_TYPE::ENUMS::TDLType T );
    KDIS::DATA_TYPE::ENUMS::TDLType GetTDLType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EncodingScheme::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EncodingScheme::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EncodingScheme::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EncodingScheme & Value ) const;
    KBOOL operator != ( const EncodingScheme & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

