/*********************************************************************
Copyright 2013 Karl Jones
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

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

FundamentalOperationalData::FundamentalOperationalData() :
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

FundamentalOperationalData::~FundamentalOperationalData()
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


