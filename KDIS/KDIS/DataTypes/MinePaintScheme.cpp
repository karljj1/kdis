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

#include "./MinePaintScheme.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

MinePaintScheme::MinePaintScheme( void )
{
    m_PntScmUnion.m_ui8PntSchm = 0;
}

//////////////////////////////////////////////////////////////////////////

MinePaintScheme::MinePaintScheme( MineAlgae A, PaintScheme PS )
{
    m_PntScmUnion.m_ui8Alg = A;
    m_PntScmUnion.m_ui8PntSchm = PS;
}

//////////////////////////////////////////////////////////////////////////

MinePaintScheme::MinePaintScheme( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

MinePaintScheme::~MinePaintScheme( void )
{
}

//////////////////////////////////////////////////////////////////////////

void MinePaintScheme::SetAlgae( MineAlgae A )
{
    m_PntScmUnion.m_ui8Alg = A;
}

//////////////////////////////////////////////////////////////////////////

MineAlgae MinePaintScheme::GetAlgae() const
{
    return ( MineAlgae )m_PntScmUnion.m_ui8Alg;
}

//////////////////////////////////////////////////////////////////////////

void MinePaintScheme::SetPaintScheme( PaintScheme PS )
{
    m_PntScmUnion.m_ui8PntSchm = PS;
}

//////////////////////////////////////////////////////////////////////////

PaintScheme MinePaintScheme::GetPaintScheme() const
{
    return ( PaintScheme )m_PntScmUnion.m_ui8PntSchm;
}

//////////////////////////////////////////////////////////////////////////

KString MinePaintScheme::GetAsString() const
{
    KStringStream ss;

    ss << "MinePaintScheme:"
       << "\n\tAlgae:			" << GetEnumAsStringMineAlgae( m_PntScmUnion.m_ui8Alg )
       << "\n\tSecondary Fuse:	" << GetEnumAsStringPaintScheme( m_PntScmUnion.m_ui8PntSchm )
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void MinePaintScheme::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MINE_PAINT_SCHEME_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_PntScmUnion.m_ui8PntSchm;
}

//////////////////////////////////////////////////////////////////////////

KDataStream MinePaintScheme::Encode() const
{
    KDataStream stream;

    MinePaintScheme::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void MinePaintScheme::Encode( KDataStream & stream ) const
{
    stream << m_PntScmUnion.m_ui8PntSchm;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinePaintScheme::operator == ( const MinePaintScheme & Value ) const
{
    if( m_PntScmUnion.m_ui8PntSchm != Value.m_PntScmUnion.m_ui8PntSchm )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinePaintScheme::operator != ( const MinePaintScheme & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


