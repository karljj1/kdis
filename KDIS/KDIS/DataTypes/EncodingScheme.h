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
    class:      EncodingScheme
    created:    18/09/2008
    author:     Karl Jones

    purpose:    Scheme used to encode a set of data
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::EncodingClass;
using KDIS::DATA_TYPE::ENUMS::EncodingType;
using KDIS::DATA_TYPE::ENUMS::TDLType;

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

    EncodingScheme( void );

    EncodingScheme( KDataStream & stream ) throw( KException );

    EncodingScheme( EncodingClass EC, KUINT16 EncodingType, TDLType T );

    EncodingScheme( EncodingType Audio, TDLType T );

    virtual ~EncodingScheme( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EncodingScheme::SetEncodingClass
    //              KDIS::DATA_TYPE::EncodingScheme::GetEncodingClass
    // Description: Encoding Class
    // Parameter:   EncodingClass EC, void
    //************************************
    void SetEncodingClass( EncodingClass EC );
    EncodingClass GetEncodingClass() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EncodingScheme::SetHour
    //              KDIS::DATA_TYPE::EncodingScheme::GetHour
    // Description: When using encoded audio use an encoding type.
    //              Can also be used to represent the number of TDL
    //              (Tactical Data Links). If encoded class is not audio
    //              and the TDL type is 0 then this value should also be 0.
    // Parameter:   EncodingType T, KUINT16, void, void
    //************************************
    void SetEncodingTypeAudio( EncodingType T );
    void SetEncodingType( KUINT16 T );
    EncodingType GetEncodingTypeAudio() const;
    KUINT16 GetEncodingType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EncodingScheme::SetTDLType
    //              KDIS::DATA_TYPE::EncodingScheme::GetTDLType
    // Description: Tactical Data Link Type if the encoding class is
    //              representing a TDL type, if not then set to 0.
    // Parameter:   TDLType T, void
    //************************************
    void SetTDLType( TDLType T );
    TDLType GetTDLType() const;

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS

