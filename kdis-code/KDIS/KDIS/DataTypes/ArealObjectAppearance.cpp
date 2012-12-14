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

#include "./ArealObjectAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace std;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

ArealObjectAppearance::ArealObjectAppearance( void )
{
    m_SpecificAppearanceUnion.m_ui32SpecificAppearance = 0;
}

//////////////////////////////////////////////////////////////////////////

ArealObjectAppearance::ArealObjectAppearance( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

ArealObjectAppearance::~ArealObjectAppearance( void )
{
}

//////////////////////////////////////////////////////////////////////////

void ArealObjectAppearance::SetBreach( Breach2bit B )
{
    m_SpecificAppearanceUnion.m_Minefield.m_ui32Breach = B;
}

//////////////////////////////////////////////////////////////////////////

Breach2bit ArealObjectAppearance::GetBreach() const
{
    return ( Breach2bit )m_SpecificAppearanceUnion.m_Minefield.m_ui32Breach;
}

//////////////////////////////////////////////////////////////////////////////

void ArealObjectAppearance::SetMineCount( KUINT16 M )
{
    m_SpecificAppearanceUnion.m_Minefield.m_ui32Mines = M;
}

//////////////////////////////////////////////////////////////////////////////

KUINT16 ArealObjectAppearance::GetMineCount() const
{
    return m_SpecificAppearanceUnion.m_Minefield.m_ui32Mines;
}

//////////////////////////////////////////////////////////////////////////

KString ArealObjectAppearance::GetAsString() const
{
    KStringStream ss;

    ss << ObjectAppearance::GetAsString()
       << "\tSpecific Appearance: " << m_SpecificAppearanceUnion.m_ui32SpecificAppearance << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ArealObjectAppearance::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ArealObjectAppearance::AREAL_OBJECT_APPEARANCE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_SpecificAppearanceUnion.m_ui32SpecificAppearance
           >> m_GeneralAppearanceUnion.m_ui16GeneralAppearance;
}

//////////////////////////////////////////////////////////////////////////

KDataStream ArealObjectAppearance::Encode() const
{
    KDataStream stream;

    ArealObjectAppearance::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ArealObjectAppearance::Encode( KDataStream & stream ) const
{
    // First add the specific bytes and then the general.
    stream << m_SpecificAppearanceUnion.m_ui32SpecificAppearance
           << m_GeneralAppearanceUnion.m_ui16GeneralAppearance;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ArealObjectAppearance::operator == ( const ArealObjectAppearance & Value ) const
{
    if( ObjectAppearance::operator  != ( Value ) ) return false;
    if( m_SpecificAppearanceUnion.m_ui32SpecificAppearance != Value.m_SpecificAppearanceUnion.m_ui32SpecificAppearance ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ArealObjectAppearance::operator != ( const ArealObjectAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
