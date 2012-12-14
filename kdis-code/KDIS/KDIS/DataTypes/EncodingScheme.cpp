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

#include "./EncodingScheme.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

EncodingScheme::EncodingScheme( void )
{
    m_EncodingSchemeUnion.m_ui16EncodingScheme = 0;
}

//////////////////////////////////////////////////////////////////////////

EncodingScheme::EncodingScheme( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

EncodingScheme::EncodingScheme( EncodingClass EC, KUINT16 EncodingType, TDLType T ) :
    m_ui16TDLType( T )
{
    m_EncodingSchemeUnion.m_ui16Type = EncodingType;
    m_EncodingSchemeUnion.m_ui16Class = EC;
}

//////////////////////////////////////////////////////////////////////////

EncodingScheme::EncodingScheme( EncodingType Audio, TDLType T ) :
    m_ui16TDLType( T )
{
    m_EncodingSchemeUnion.m_ui16Type = Audio;
    m_EncodingSchemeUnion.m_ui16Class = EncodedAudio;
}

//////////////////////////////////////////////////////////////////////////

EncodingScheme::~EncodingScheme( void )
{
}

//////////////////////////////////////////////////////////////////////////

void EncodingScheme::SetEncodingClass( EncodingClass EC )
{
    m_EncodingSchemeUnion.m_ui16Class = EC;
}

//////////////////////////////////////////////////////////////////////////

EncodingClass EncodingScheme::GetEncodingClass() const
{
    return ( EncodingClass )m_EncodingSchemeUnion.m_ui16Class;
}

//////////////////////////////////////////////////////////////////////////

void EncodingScheme::SetEncodingTypeAudio( EncodingType T )
{
    m_EncodingSchemeUnion.m_ui16Class = EncodedAudio;
    m_EncodingSchemeUnion.m_ui16Type = T;
}

//////////////////////////////////////////////////////////////////////////

EncodingType EncodingScheme::GetEncodingTypeAudio() const
{
    return ( EncodingType )m_EncodingSchemeUnion.m_ui16Type;
}

//////////////////////////////////////////////////////////////////////////

void EncodingScheme::SetEncodingType( KUINT16 T )
{
    m_EncodingSchemeUnion.m_ui16Type = T;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 EncodingScheme::GetEncodingType() const
{
    return m_EncodingSchemeUnion.m_ui16Type;
}

//////////////////////////////////////////////////////////////////////////

void EncodingScheme::SetTDLType( TDLType T )
{
    m_ui16TDLType = T;
}

//////////////////////////////////////////////////////////////////////////

TDLType EncodingScheme::GetTDLType() const
{
    return ( TDLType )m_ui16TDLType;
}

//////////////////////////////////////////////////////////////////////////

KString EncodingScheme::GetAsString() const
{
    KStringStream ss;

    ss << "Encoding Scheme:"
       << "\n\tClass:    " << GetEnumAsStringEncodingClass( m_EncodingSchemeUnion.m_ui16Class )
       << "\n\tType:     " << m_EncodingSchemeUnion.m_ui16Type
       << "\n\tTDL:	     " << GetEnumAsStringTDLType( m_ui16TDLType )
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void EncodingScheme::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ENCODING_SCHEME_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_EncodingSchemeUnion.m_ui16EncodingScheme
           >> m_ui16TDLType;
}

//////////////////////////////////////////////////////////////////////////

KDataStream EncodingScheme::Encode() const
{
    KDataStream stream;

    EncodingScheme::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void EncodingScheme::Encode( KDataStream & stream ) const
{
    stream << m_EncodingSchemeUnion.m_ui16EncodingScheme
           << m_ui16TDLType;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EncodingScheme::operator == ( const EncodingScheme & Value ) const
{
    if( m_EncodingSchemeUnion.m_ui16EncodingScheme != Value.m_EncodingSchemeUnion.m_ui16EncodingScheme ) return false;
    if( m_ui16TDLType        != Value.m_ui16TDLType )        return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EncodingScheme::operator != ( const EncodingScheme & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

