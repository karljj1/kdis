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

#include "./GridData.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

GridData::GridData() :
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

GridData::~GridData()
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
       << "\n\tSample Type:         " << m_ui16SmpTyp
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

