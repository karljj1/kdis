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

#include "./GridData.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

GridData::GridData( void ) :
    m_ui16SmpTyp( 0 ),
    m_ui16DtRep( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

GridData::GridData( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

GridData::~GridData( void )
{
}

//////////////////////////////////////////////////////////////////////////

void GridData::SetSampleType( KUINT16 ST )
{
    m_ui16SmpTyp = ST;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 GridData::GetSampleType() const
{
    return m_ui16SmpTyp;
}

//////////////////////////////////////////////////////////////////////////

GridDataRepresentation GridData::GetDataRepresentation() const
{
    return ( GridDataRepresentation )m_ui16DtRep;
}

//////////////////////////////////////////////////////////////////////////

KString GridData::GetAsString() const
{
    KStringStream ss;

    ss << "GridData:"
       << "\n\tSample Type:	" << m_ui16SmpTyp
       << "\n\tData Representation: " << GetEnumAsStringGridDataRepresentation( m_ui16DtRep )
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void GridData::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < GRID_DATA_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16SmpTyp
           >> m_ui16DtRep;
}

//////////////////////////////////////////////////////////////////////////

KDataStream GridData::Encode() const
{
    KDataStream stream;

    GridData::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void GridData::Encode( KDataStream & stream ) const
{
    stream << m_ui16SmpTyp
           << m_ui16DtRep;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GridData::operator == ( const GridData & Value ) const
{
    if( m_ui16SmpTyp != Value.m_ui16SmpTyp ) return false;
    if( m_ui16DtRep  != Value.m_ui16DtRep )       return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL GridData::operator != ( const GridData & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

