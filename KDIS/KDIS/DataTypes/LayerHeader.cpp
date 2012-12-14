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

#include "./LayerHeader.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

LayerHeader::LayerHeader( void ) :
    m_ui8LayerNumber( 0 ),
    m_ui8LayerSpecificInfo( 0 ),
    m_ui16LayerLength( LAYER_HEADER_SIZE )
{
}

//////////////////////////////////////////////////////////////////////////

LayerHeader::LayerHeader( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

LayerHeader::LayerHeader( KUINT8 LayerNumber, KUINT8 LayerSpecificInfo, KUINT16 LayerLength ) :
    m_ui8LayerNumber( LayerNumber ),
    m_ui8LayerSpecificInfo( LayerSpecificInfo ),
    m_ui16LayerLength( LayerLength )
{
}

//////////////////////////////////////////////////////////////////////////

LayerHeader::~LayerHeader( void )
{
}

//////////////////////////////////////////////////////////////////////////

void LayerHeader::SetLayerNumber( KUINT8 LN )
{
    m_ui8LayerNumber = LN;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 LayerHeader::GetLayerNumber() const
{
    return m_ui8LayerNumber;
}

//////////////////////////////////////////////////////////////////////////

void LayerHeader::SetLayerSpecificInfomation( KUINT8 LSI )
{
    m_ui8LayerSpecificInfo = LSI;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 LayerHeader::GetLayerSpecificInfomation() const
{
    return m_ui8LayerSpecificInfo;
}

//////////////////////////////////////////////////////////////////////////

void LayerHeader::SetLayerLength( KUINT16 L )
{
    m_ui16LayerLength = L;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 LayerHeader::GetLayerLength() const
{
    return m_ui16LayerLength;
}

//////////////////////////////////////////////////////////////////////////

KString LayerHeader::GetAsString() const
{
    KStringStream ss;

    ss << "LayerHeader:"
       << "\n\tLayer Number:        " << ( KUINT16 )m_ui8LayerNumber
       << "\n\tLayer Specific Info: " << ( KUINT16 )m_ui8LayerSpecificInfo
       << "\n\tLayer Length:        " << m_ui16LayerLength
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void LayerHeader::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < LAYER_HEADER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8LayerNumber
           >> m_ui8LayerSpecificInfo
           >> m_ui16LayerLength;
}

//////////////////////////////////////////////////////////////////////////

KDataStream LayerHeader::Encode() const
{
    KDataStream stream;

    LayerHeader::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void LayerHeader::Encode( KDataStream & stream ) const
{
    stream << m_ui8LayerNumber
           << m_ui8LayerSpecificInfo
           << m_ui16LayerLength;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LayerHeader::operator == ( const LayerHeader & Value ) const
{
    if( m_ui8LayerNumber       != Value.m_ui8LayerNumber )       return false;
    if( m_ui8LayerSpecificInfo != Value.m_ui8LayerSpecificInfo ) return false;
    if( m_ui16LayerLength      != Value.m_ui16LayerLength )      return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LayerHeader::operator != ( const LayerHeader & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////



