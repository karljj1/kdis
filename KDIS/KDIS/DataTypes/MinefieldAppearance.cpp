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

#include "./MinefieldAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

MinefieldAppearance::MinefieldAppearance( void )
{
    m_ui16BitUnion.m_ui16App = 0;
}

//////////////////////////////////////////////////////////////////////////

MinefieldAppearance::MinefieldAppearance( MinefieldType T, KBOOL IsStatusActive, KBOOL IsLaneActive, KBOOL IsStateActive )
{
    m_ui16BitUnion.m_ui16App = 0;
    m_ui16BitUnion.m_ui16Type = T;
    m_ui16BitUnion.m_ui16ActiveStatus = !IsStateActive;
    m_ui16BitUnion.m_ui16Lane = !IsLaneActive;
    m_ui16BitUnion.m_ui16State = !IsStateActive;
}

//////////////////////////////////////////////////////////////////////////

MinefieldAppearance::MinefieldAppearance( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

MinefieldAppearance::~MinefieldAppearance( void )
{
}

//////////////////////////////////////////////////////////////////////////

void MinefieldAppearance::SetMinefieldType( MinefieldType T )
{
    m_ui16BitUnion.m_ui16Type = T;
}

//////////////////////////////////////////////////////////////////////////

MinefieldType MinefieldAppearance::GetMinefieldType() const
{
    return ( MinefieldType )m_ui16BitUnion.m_ui16Type;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldAppearance::SetStatusActive( KBOOL A )
{
    m_ui16BitUnion.m_ui16ActiveStatus = !A;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldAppearance::IsStatusActive() const
{
    return !m_ui16BitUnion.m_ui16ActiveStatus;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldAppearance::SetLaneActive( KBOOL A )
{
    m_ui16BitUnion.m_ui16Lane = !A;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldAppearance::IsLaneActive() const
{
    return !m_ui16BitUnion.m_ui16Lane;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldAppearance::SetStateActive( KBOOL A )
{
    m_ui16BitUnion.m_ui16State = !A;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldAppearance::IsStateActive() const
{
    return !m_ui16BitUnion.m_ui16State;
}

//////////////////////////////////////////////////////////////////////////

KString MinefieldAppearance::GetAsString() const
{
    KStringStream ss;

    ss << "MinefieldAppearance:"
       << "\n\tMinefield Type:		     " << GetEnumAsStringMinefieldType( m_ui16BitUnion.m_ui16Type )
       << "\n\tActive Status(0 = true):  " << m_ui16BitUnion.m_ui16ActiveStatus
       << "\n\tActive Lane(0 = true):    " << m_ui16BitUnion.m_ui16Lane
       << "\n\tState(0 = true):          " << m_ui16BitUnion.m_ui16State
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void MinefieldAppearance::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MINEFIELD_APPEARANCE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16BitUnion.m_ui16App;
}

//////////////////////////////////////////////////////////////////////////

KDataStream MinefieldAppearance::Encode() const
{
    KDataStream stream;

    MinefieldAppearance::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldAppearance::Encode( KDataStream & stream ) const
{
    stream << m_ui16BitUnion.m_ui16App;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldAppearance::operator == ( const MinefieldAppearance & Value ) const
{
    if( m_ui16BitUnion.m_ui16App != Value.m_ui16BitUnion.m_ui16App )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldAppearance::operator != ( const MinefieldAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

