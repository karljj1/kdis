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

#include "./MineFusing.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

MineFusing::MineFusing( void )
{
    m_FuseUnion.m_ui16Fusing = 0;
}

//////////////////////////////////////////////////////////////////////////

MineFusing::MineFusing( MineFuse Primary, MineFuse Secondary, KBOOL AntiHandlingDevice )
{
    m_FuseUnion.m_ui16Fusing = 0;
    m_FuseUnion.m_ui16Primary = Primary;
    m_FuseUnion.m_ui16Secondary = Secondary;
    m_FuseUnion.m_ui16AHD = AntiHandlingDevice;
}

//////////////////////////////////////////////////////////////////////////

MineFusing::MineFusing( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

MineFusing::~MineFusing( void )
{
}

//////////////////////////////////////////////////////////////////////////

void MineFusing::SetPrimaryFuse( MineFuse F )
{
    m_FuseUnion.m_ui16Primary = F;
}

//////////////////////////////////////////////////////////////////////////

MineFuse MineFusing::GetPrimaryFuse() const
{
    return ( MineFuse )m_FuseUnion.m_ui16Primary;
}

//////////////////////////////////////////////////////////////////////////

void MineFusing::SetSecondaryFuse( MineFuse F )
{
    m_FuseUnion.m_ui16Secondary = F;
}

//////////////////////////////////////////////////////////////////////////

MineFuse MineFusing::GetSecondaryFuse() const
{
    return ( MineFuse )m_FuseUnion.m_ui16Secondary;
}

//////////////////////////////////////////////////////////////////////////

void MineFusing::SetHasAntiHandlingDevice( KBOOL AHD )
{
    m_FuseUnion.m_ui16AHD = AHD;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MineFusing::GetHasAntiHandlingDevice() const
{
    return m_FuseUnion.m_ui16AHD;
}

//////////////////////////////////////////////////////////////////////////

KString MineFusing::GetAsString() const
{
    KStringStream ss;

    ss << "MineFusing:"
       << "\n\tPrimary Fuse:			" << GetEnumAsStringMineFuse( m_FuseUnion.m_ui16Primary )
       << "\n\tSecondary Fuse:			" << GetEnumAsStringMineFuse( m_FuseUnion.m_ui16Secondary )
       << "\n\tAnti-Handling Device:	" << m_FuseUnion.m_ui16AHD
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void MineFusing::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MINE_FUSING_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_FuseUnion.m_ui16Fusing;
}

//////////////////////////////////////////////////////////////////////////

KDataStream MineFusing::Encode() const
{
    KDataStream stream;

    MineFusing::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void MineFusing::Encode( KDataStream & stream ) const
{
    stream << m_FuseUnion.m_ui16Fusing;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MineFusing::operator == ( const MineFusing & Value ) const
{
    if( m_FuseUnion.m_ui16Fusing != Value.m_FuseUnion.m_ui16Fusing )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MineFusing::operator != ( const MineFusing & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

