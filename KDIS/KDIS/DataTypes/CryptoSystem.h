/*********************************************************************
Copyright 2013 KDIS
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
