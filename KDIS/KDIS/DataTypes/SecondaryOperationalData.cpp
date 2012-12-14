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

#include "./SecondaryOperationalData.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

SecondaryOperationalData::SecondaryOperationalData( void ) :
    m_ui8Param1( 0 ),
    m_ui8Param2( 0 ),
    m_ui16NumFundParamSets( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

SecondaryOperationalData::SecondaryOperationalData( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

SecondaryOperationalData::SecondaryOperationalData( KUINT8 Param1, KUINT8 Param2, KUINT16 NumFundParamSets ) :
    m_ui8Param1( Param1 ),
    m_ui8Param2( Param2 ),
    m_ui16NumFundParamSets( NumFundParamSets )
{
}

//////////////////////////////////////////////////////////////////////////

SecondaryOperationalData::~SecondaryOperationalData( void )
{
}

//////////////////////////////////////////////////////////////////////////

void SecondaryOperationalData::SetParameter1( KUINT8 P )
{
    m_ui8Param1 = P;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 SecondaryOperationalData::GetParameter1() const
{
    return m_ui8Param1;
}

//////////////////////////////////////////////////////////////////////////

void SecondaryOperationalData::SetParameter2( KUINT8 P )
{
    m_ui8Param2 = P;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 SecondaryOperationalData::GetParameter2() const
{
    return m_ui8Param2;
}

//////////////////////////////////////////////////////////////////////////

void SecondaryOperationalData::SetNumberOfFundamentalParamSets( KUINT8 NFPDS )
{
    m_ui16NumFundParamSets = NFPDS;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 SecondaryOperationalData::GetNumberOfFundamentalParamSets() const
{
    return m_ui16NumFundParamSets;
}

//////////////////////////////////////////////////////////////////////////

KString SecondaryOperationalData::GetAsString() const
{
    KStringStream ss;

    ss << "SecondaryOperationalData:"
       << "\n\tParameter 1:                   " << m_ui8Param1
       << "\n\tParameter 2:                   " << m_ui8Param2
       << "\n\tNumber Fundamental Param Sets: " << m_ui16NumFundParamSets
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void SecondaryOperationalData::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < SECONDARY_OPERATIONAL_DATA_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8Param1
           >> m_ui8Param2
           >> m_ui16NumFundParamSets;
}

//////////////////////////////////////////////////////////////////////////

KDataStream SecondaryOperationalData::Encode() const
{
    KDataStream stream;

    SecondaryOperationalData::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void SecondaryOperationalData::Encode( KDataStream & stream ) const
{
    stream << m_ui8Param1
           << m_ui8Param2
           << m_ui16NumFundParamSets;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SecondaryOperationalData::operator == ( const SecondaryOperationalData & Value ) const
{
    if( m_ui8Param1             != Value.m_ui8Param1 )            return false;
    if( m_ui8Param2             != Value.m_ui8Param2 )            return false;
    if( m_ui16NumFundParamSets  != Value.m_ui16NumFundParamSets ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SecondaryOperationalData::operator != ( const SecondaryOperationalData & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
