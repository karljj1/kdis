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

#include "./FundamentalOperationalData.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

FundamentalOperationalData::FundamentalOperationalData( void ) :
    m_ui8SystemStatus( 0 ),
    m_ui8AltParam4( 0 ),
    m_ui8InfoLayers( 0 ),
    m_ui8Modifier( 0 ),
    m_ui16Param1( 0 ),
    m_ui16Param2( 0 ),
    m_ui16Param3( 0 ),
    m_ui16Param4( 0 ),
    m_ui16Param5( 0 ),
    m_ui16Param6( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

FundamentalOperationalData::FundamentalOperationalData( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

FundamentalOperationalData::FundamentalOperationalData( const FundamentalOperationalData_MarkXTransponder & FOD )
{
    m_FODSystemMarkTransponder = FOD;
}

//////////////////////////////////////////////////////////////////////////

FundamentalOperationalData::FundamentalOperationalData( const FundamentalOperationalData_MarkXInterrogator & FOD )
{
    m_FODSystemMarkInterrogator = FOD;
}

//////////////////////////////////////////////////////////////////////////

FundamentalOperationalData::FundamentalOperationalData( const FundamentalOperationalData_Soviet & FOD )
{
    m_FODSystemSoviet = FOD;
}

//////////////////////////////////////////////////////////////////////////

FundamentalOperationalData::FundamentalOperationalData( const FundamentalOperationalData_RRB & FOD )
{
    m_FODSystemRRB = FOD;
}

//////////////////////////////////////////////////////////////////////////

FundamentalOperationalData::~FundamentalOperationalData( void )
{
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData::SetFundamentalOperationalData_MarkXTransponder( const FundamentalOperationalData_MarkXTransponder & FOD )
{
    m_FODSystemMarkTransponder = FOD;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData::SetFundamentalOperationalData_MarkXInterrogator( const FundamentalOperationalData_MarkXInterrogator & FOD )
{
    m_FODSystemMarkInterrogator = FOD;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData::SetFundamentalOperationalData_Soviet( const FundamentalOperationalData_Soviet & FOD )
{
    m_FODSystemSoviet = FOD;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData::SetFundamentalOperationalData_RRB( const FundamentalOperationalData_RRB & FOD )
{
    m_FODSystemRRB = FOD;
}

//////////////////////////////////////////////////////////////////////////

const FundamentalOperationalData_MarkXTransponder & FundamentalOperationalData::GetSetFundamentalOperationalData_MarkXTransponder() const
{
    return m_FODSystemMarkTransponder;
}

//////////////////////////////////////////////////////////////////////////

FundamentalOperationalData_MarkXTransponder & FundamentalOperationalData::GetSetFundamentalOperationalData_MarkXTransponder()
{
    return m_FODSystemMarkTransponder;
}

//////////////////////////////////////////////////////////////////////////

const FundamentalOperationalData_MarkXInterrogator & FundamentalOperationalData::GetFundamentalOperationalData_MarkXInterrogator() const
{
    return m_FODSystemMarkInterrogator;
}

//////////////////////////////////////////////////////////////////////////

FundamentalOperationalData_MarkXInterrogator & FundamentalOperationalData::GetFundamentalOperationalData_MarkXInterrogator()
{
    return m_FODSystemMarkInterrogator;
}

//////////////////////////////////////////////////////////////////////////

const FundamentalOperationalData_Soviet & FundamentalOperationalData::GetFundamentalOperationalData_Soviet() const
{
    return m_FODSystemSoviet;
}

//////////////////////////////////////////////////////////////////////////

FundamentalOperationalData_Soviet & FundamentalOperationalData::GetFundamentalOperationalData_Soviet()
{
    return m_FODSystemSoviet;
}

//////////////////////////////////////////////////////////////////////////

const FundamentalOperationalData_RRB & FundamentalOperationalData::GetFundamentalOperationalData_RRB() const
{
    return m_FODSystemRRB;
}

//////////////////////////////////////////////////////////////////////////

FundamentalOperationalData_RRB & FundamentalOperationalData::GetFundamentalOperationalData_RRB()
{
    return m_FODSystemRRB;
}

//////////////////////////////////////////////////////////////////////////

KString FundamentalOperationalData::GetAsString() const
{
    KStringStream ss;

    ss << "FundamentalOperationalData:"
       << "\tNOT IMPLEMENTED YET\n";

    // TODO: Get string for a specific system type.

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < FUNDAMENTAL_OPERATIONAL_DATA_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8SystemStatus
           >> m_ui8AltParam4
           >> m_ui8InfoLayers
           >> m_ui8Modifier
           >> m_ui16Param1
           >> m_ui16Param2
           >> m_ui16Param3
           >> m_ui16Param4
           >> m_ui16Param5
           >> m_ui16Param6;
}

//////////////////////////////////////////////////////////////////////////

KDataStream FundamentalOperationalData::Encode() const
{
    KDataStream stream;

    FundamentalOperationalData::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalOperationalData::Encode( KDataStream & stream ) const
{
    stream << m_ui8SystemStatus
           << m_ui8AltParam4
           << m_ui8InfoLayers
           << m_ui8Modifier
           << m_ui16Param1
           << m_ui16Param2
           << m_ui16Param3
           << m_ui16Param4
           << m_ui16Param5
           << m_ui16Param6;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData::operator == ( const FundamentalOperationalData & Value ) const
{
    if( m_ui8SystemStatus   != Value.m_ui8SystemStatus )    return false;
    if( m_ui8AltParam4      != Value.m_ui8AltParam4 )       return false;
    if( m_ui8InfoLayers     != Value.m_ui8InfoLayers )      return false;
    if( m_ui8Modifier       != Value.m_ui8Modifier )        return false;
    if( m_ui16Param1        != Value.m_ui16Param1 )         return false;
    if( m_ui16Param2        != Value.m_ui16Param2 )         return false;
    if( m_ui16Param3        != Value.m_ui16Param3 )         return false;
    if( m_ui16Param4        != Value.m_ui16Param4 )         return false;
    if( m_ui16Param5        != Value.m_ui16Param5 )         return false;
    if( m_ui16Param6        != Value.m_ui16Param6 )         return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalOperationalData::operator != ( const FundamentalOperationalData & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


