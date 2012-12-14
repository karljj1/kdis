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

#include "./PositionError.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

PositionError::PositionError( void )
{
}

//////////////////////////////////////////////////////////////////////////

PositionError::PositionError( KFIXED16_8 Horizontal, KFIXED16_8 Vertical ) :
    m_HorzErr( Horizontal ),
    m_VertErr( Vertical )
{
}

//////////////////////////////////////////////////////////////////////////

PositionError::PositionError( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

PositionError::~PositionError( void )
{
}

//////////////////////////////////////////////////////////////////////////

void PositionError::SetHorizontalError( KFIXED16_8 HE )
{
    m_HorzErr = HE;
}

//////////////////////////////////////////////////////////////////////////

KFIXED16_8 PositionError::GetHorizontalError() const
{
    return m_HorzErr;
}

//////////////////////////////////////////////////////////////////////////

void PositionError::SetVerticalError( KFIXED16_8 VE )
{
    m_VertErr = VE;
}

//////////////////////////////////////////////////////////////////////////

KFIXED16_8 PositionError::GetVerticalError() const
{
    return m_VertErr;
}

//////////////////////////////////////////////////////////////////////////

KString PositionError::GetAsString() const
{
    KStringStream ss;

    ss << "PositionError:\n"
       << "\tHorizontal Error: " << m_HorzErr.GetAsString()
       << "\tVertical Error:   " << m_VertErr.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void PositionError::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < POSITION_ERROR_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> KDIS_STREAM m_HorzErr
           >> KDIS_STREAM m_VertErr;
}

//////////////////////////////////////////////////////////////////////////

KDataStream PositionError::Encode() const
{
    KDataStream stream;

    PositionError::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void PositionError::Encode( KDataStream & stream ) const
{
    stream << KDIS_STREAM m_HorzErr
           << KDIS_STREAM m_VertErr;
}

//////////////////////////////////////////////////////////////////////////

KBOOL PositionError::operator == ( const PositionError & Value ) const
{
    if( m_HorzErr != Value.m_HorzErr )return false;
    if( m_VertErr != Value.m_VertErr )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL PositionError::operator != ( const PositionError & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

