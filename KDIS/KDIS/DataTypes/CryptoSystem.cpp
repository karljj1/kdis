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

#include "./CryptoSystem.h"
//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

CryptoSystem::CryptoSystem() :
    m_ui16CryptoSystemType( 0 ),
    m_ui16EncryptionMode( 0 ),
    m_ui16KeyID( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

CryptoSystem::CryptoSystem( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

CryptoSystem::CryptoSystem( CryptoSystemType CST, EncryptionMode EM, KUINT16 Key ) :
    m_ui16CryptoSystemType( CST ),
    m_ui16EncryptionMode( EM ),
    m_ui16KeyID( Key )
{
}

//////////////////////////////////////////////////////////////////////////

CryptoSystem::~CryptoSystem()
{
}

//////////////////////////////////////////////////////////////////////////

void CryptoSystem::SetCryptoSystemType( CryptoSystemType T )
{
    m_ui16CryptoSystemType = T;
}

//////////////////////////////////////////////////////////////////////////

CryptoSystemType CryptoSystem::GetCryptoSystemType() const
{
    return ( CryptoSystemType )m_ui16CryptoSystemType;
}

//////////////////////////////////////////////////////////////////////////

void CryptoSystem::SetEncryptionMode( EncryptionMode EM )
{
    m_ui16EncryptionMode = EM;
}

//////////////////////////////////////////////////////////////////////////

EncryptionMode CryptoSystem::GetEncryptionMode() const
{
    return ( EncryptionMode )m_ui16EncryptionMode;
}

//////////////////////////////////////////////////////////////////////////

void CryptoSystem::SetKeyID( KUINT16 KeyID )
{
    m_ui16KeyID = KeyID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 CryptoSystem::GetKeyID() const
{
    return m_ui16KeyID;
}

//////////////////////////////////////////////////////////////////////////

void CryptoSystem::SetKey( KUINT16 K )
{
    m_ui16CryptoKey = K;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 CryptoSystem::GetKey() const
{
    return m_ui16CryptoKey;
}

//////////////////////////////////////////////////////////////////////////

KString CryptoSystem::GetAsString() const
{
    KStringStream ss;

    ss << "Crypto System:"
       << "\n\tEquipment:   " << GetEnumAsStringCryptoSystemType( m_ui16CryptoSystemType )
       << "\n\tMode:        " << GetEnumAsStringEncryptionMode( m_ui16EncryptionMode )
       << "\n\tKey:         " << m_ui16KeyID
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void CryptoSystem::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < CRYPTO_SYSTEM_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16CryptoSystemType
           >> m_ui16CryptoKey;
}

//////////////////////////////////////////////////////////////////////////

KDataStream CryptoSystem::Encode() const
{
    KDataStream stream;

    CryptoSystem::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void CryptoSystem::Encode( KDataStream & stream ) const
{
    stream << m_ui16CryptoSystemType
           << m_ui16CryptoKey;
}

//////////////////////////////////////////////////////////////////////////

KBOOL CryptoSystem::operator == ( const CryptoSystem & Value ) const
{
    if( m_ui16CryptoSystemType  != Value.m_ui16CryptoSystemType ) return false;
    if( m_ui16CryptoKey         != Value.m_ui16CryptoKey )        return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL CryptoSystem::operator != ( const CryptoSystem & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////




