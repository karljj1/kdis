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
    class:      CryptoSystem
    created:    2008/10/22
    author:     Karl Jones

    purpose:    Stores details about a transmitters crypto system
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::CryptoSystemType;
using KDIS::DATA_TYPE::ENUMS::EncryptionMode;

class KDIS_EXPORT CryptoSystem : public DataTypeBase
{
protected:

    KUINT16 m_ui16CryptoSystemType;

    union
    {
        struct
        {
            KUINT16 m_ui16EncryptionMode : 1;
            KUINT16 m_ui16KeyID          : 15;
        };

        KUINT16 m_ui16CryptoKey;
    };

public:

    static const KUINT16 CRYPTO_SYSTEM_SIZE = 4;

    CryptoSystem( void );

    CryptoSystem( KDataStream & stream )throw( KException );

    CryptoSystem( CryptoSystemType CST, EncryptionMode EM, KUINT16 Key );

    virtual ~CryptoSystem( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::CryptoSystem::SetCryptoSystemType
    //              KDIS::DATA_TYPE::CryptoSystem::GetCryptoSystemType
    // Description: Equipment being used
    // Parameter:   CryptoSystemType T, void
    //************************************
    void SetCryptoSystemType( CryptoSystemType T );
    CryptoSystemType GetCryptoSystemType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::CryptoSystem::SetEncryptionMode
    //              KDIS::DATA_TYPE::CryptoSystem::GetEncryptionMode
    // Description: Mode being used to encrypt the data
    // Parameter:   EncryptionMode EM, void
    //************************************
    void SetEncryptionMode( EncryptionMode EM );
    EncryptionMode GetEncryptionMode() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::CryptoSystem::SetKey
    //              KDIS::DATA_TYPE::CryptoSystem::GetKey
    // Description: Key. Not an actual crypto key, if the key
    //              from the sender is the same as the key of the
    //              receiver then they are considered to be using the
    //              same key.
    // Parameter:   KUINT16 EM, void
    //************************************
    void SetKey( KUINT16 K );
    KUINT16 GetKey() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::CryptoSystem::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::CryptoSystem::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::CryptoSystem::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const CryptoSystem & Value ) const;
    KBOOL operator != ( const CryptoSystem & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
