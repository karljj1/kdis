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

#include "./APA.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

APA::APA( void ) :
    m_i16Value( 0 )
{
	m_ApaUnion.m_ui16ParamIndex = 0;
}

//////////////////////////////////////////////////////////////////////////

APA::APA( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

APA::APA( AdditionalPassiveParameterIndex APPI, KBOOL Val1, KBOOL Val2, KINT16 Value ) :
    m_i16Value( Value )
{
	m_ApaUnion.m_ui16ParamIndex = 0;
	m_ApaUnion.m_ui16APPI = APPI;
	m_ApaUnion.m_ui16Status1 = Val1;
	m_ApaUnion.m_ui16Status2 = Val2;
}

//////////////////////////////////////////////////////////////////////////

APA::~APA( void )
{
}

//////////////////////////////////////////////////////////////////////////

void APA::SetAPPI( AdditionalPassiveParameterIndex APPI )
{
    m_ApaUnion.m_ui16APPI = APPI;
}

//////////////////////////////////////////////////////////////////////////

AdditionalPassiveParameterIndex APA::GetAPPI() const
{
    return ( AdditionalPassiveParameterIndex )m_ApaUnion.m_ui16APPI;
}

//////////////////////////////////////////////////////////////////////////

void APA::SetStatus( KBOOL Val1, KBOOL Val2 )
{
    m_ApaUnion.m_ui16Status1 = Val1;
    m_ApaUnion.m_ui16Status2 = Val2;
}

//////////////////////////////////////////////////////////////////////////

KBOOL APA::GetStatusVal1() const
{
    return m_ApaUnion.m_ui16Status1;
}

//////////////////////////////////////////////////////////////////////////

KBOOL APA::GetStatusVal2() const
{
    return m_ApaUnion.m_ui16Status2;
}

//////////////////////////////////////////////////////////////////////////

void APA::SetValue( KINT16 V )
{
    m_i16Value = V;
}

//////////////////////////////////////////////////////////////////////////

KINT16 APA::GetValue() const
{
    return m_i16Value;
}

//////////////////////////////////////////////////////////////////////////

KString APA::GetAsString() const
{
    KStringStream ss;

    ss << "APA:"
       << "\n\tParam Index:  " << GetEnumAsStringAdditionalPassiveParameterIndex( m_ApaUnion.m_ui16APPI )
       << "\n\tStatus:       ( " << m_ApaUnion.m_ui16Status1 << " , " << m_ApaUnion.m_ui16Status2 << " )"
       << "\n\tValue:        " << m_i16Value
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void APA::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < APA_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ApaUnion.m_ui16ParamIndex
           >> m_i16Value;
}

//////////////////////////////////////////////////////////////////////////

KDataStream APA::Encode() const
{
    KDataStream stream;

    APA::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void APA::Encode( KDataStream & stream ) const
{
    stream << m_ApaUnion.m_ui16ParamIndex
           << m_i16Value;
}

//////////////////////////////////////////////////////////////////////////

KBOOL APA::operator == ( const APA & Value ) const
{
    if( m_ApaUnion.m_ui16ParamIndex != Value.m_ApaUnion.m_ui16ParamIndex ) return false;
    if( m_i16Value                  != Value.m_i16Value )                  return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL APA::operator != ( const APA & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

