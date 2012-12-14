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

#include "./FixedDatum.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

FixedDatum::FixedDatum( void ) :
    m_ui32DatumID( 0 )
{
    memset( m_cDatumValue, 0, 4 );
}

//////////////////////////////////////////////////////////////////////////

FixedDatum::FixedDatum( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

FixedDatum::~FixedDatum( void )
{
}

//////////////////////////////////////////////////////////////////////////

void FixedDatum::SetDatumID( DatumID ID )
{
    m_ui32DatumID = ID;
}

//////////////////////////////////////////////////////////////////////////

DatumID FixedDatum::GetDatumID() const
{
    return ( DatumID )m_ui32DatumID;
}

//////////////////////////////////////////////////////////////////////////

void FixedDatum::GetDatumValue( KOCTET * Buffer, KUINT16 BufferSize ) const throw( KException )
{
    if( BufferSize < 4 )throw KException( __FUNCTION__, BUFFER_TOO_SMALL );

    strncpy( Buffer, m_cDatumValue, 4 );
}

//////////////////////////////////////////////////////////////////////////

KString FixedDatum::GetAsString() const
{
    KStringStream ss;

    NetToKUINT32 NetToSys( m_cDatumValue, false );

    // TODO: maybe determine what the data type should be when printing out, this
    // could be a lot of work.
    ss << "Fixed Datum:"
       << "\n\tID:          " << GetEnumAsStringDatumID( m_ui32DatumID )
       << "\n\tValue(UI32): " << NetToSys.m_Value
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void FixedDatum::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < FixedDatum::FIXED_DATUM_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32DatumID;

    for( KUINT16 i = 0; i < 4; ++i )
    {
        stream >> m_cDatumValue[i];
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream FixedDatum::Encode() const
{
    KDataStream stream;

    FixedDatum::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void FixedDatum::Encode( KDataStream & stream ) const
{
    stream << m_ui32DatumID;

    for( KUINT16 i = 0; i < 4; ++i )
    {
        stream << m_cDatumValue[i];
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL FixedDatum::operator == ( const FixedDatum & Value ) const
{
    if( m_ui32DatumID != Value.m_ui32DatumID )                 return false;
    if( memcmp( m_cDatumValue, Value.m_cDatumValue, 4 ) != 0 ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FixedDatum::operator != ( const FixedDatum & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


