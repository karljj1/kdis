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

#include "./CryptoSystem.h"
//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

CryptoSystem::CryptoSystem( void ) :
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

CryptoSystem::~CryptoSystem( void )
{
}

//////////////////////////////////////////////////////////////////////////

void CryptoSystem::SetCryptoSystemType( CryptoSystemType T )
{
    m_ui16CryptoSystemType;
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
       << "\n\tMode:		" << GetEnumAsStringEncryptionMode( m_ui16EncryptionMode )
       << "\n\tKey:			" << m_ui16KeyID
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




