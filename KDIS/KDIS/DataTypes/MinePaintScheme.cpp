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

#include "./MinePaintScheme.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

MinePaintScheme::MinePaintScheme()
{
    m_PntScmUnion.m_ui8PntSchm = 0;
}

//////////////////////////////////////////////////////////////////////////

MinePaintScheme::MinePaintScheme( MineAlgae A, PaintScheme PS )
{
    m_PntScmUnion.m_ui8Alg = A;
    m_PntScmUnion.m_ui8PntSchm = PS;
}

//////////////////////////////////////////////////////////////////////////

MinePaintScheme::MinePaintScheme( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

MinePaintScheme::~MinePaintScheme()
{
}

//////////////////////////////////////////////////////////////////////////

void MinePaintScheme::SetAlgae( MineAlgae A )
{
    m_PntScmUnion.m_ui8Alg = A;
}

//////////////////////////////////////////////////////////////////////////

MineAlgae MinePaintScheme::GetAlgae() const
{
    return ( MineAlgae )m_PntScmUnion.m_ui8Alg;
}

//////////////////////////////////////////////////////////////////////////

void MinePaintScheme::SetPaintScheme( PaintScheme PS )
{
    m_PntScmUnion.m_ui8Scm = PS;
}

//////////////////////////////////////////////////////////////////////////

PaintScheme MinePaintScheme::GetPaintScheme() const
{
    return ( PaintScheme )m_PntScmUnion.m_ui8Scm;
}

//////////////////////////////////////////////////////////////////////////

KString MinePaintScheme::GetAsString() const
{
    KStringStream ss;

    ss << "MinePaintScheme:"
       << "\n\tAlgae:           " << GetEnumAsStringMineAlgae( m_PntScmUnion.m_ui8Alg )
       << "\n\tPaint Scheme:    " << GetEnumAsStringPaintScheme( m_PntScmUnion.m_ui8Scm )
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void MinePaintScheme::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MINE_PAINT_SCHEME_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_PntScmUnion.m_ui8PntSchm;
}

//////////////////////////////////////////////////////////////////////////

KDataStream MinePaintScheme::Encode() const
{
    KDataStream stream;

    MinePaintScheme::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void MinePaintScheme::Encode( KDataStream & stream ) const
{
    stream << m_PntScmUnion.m_ui8PntSchm;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinePaintScheme::operator == ( const MinePaintScheme & Value ) const
{
    if( m_PntScmUnion.m_ui8PntSchm != Value.m_PntScmUnion.m_ui8PntSchm )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinePaintScheme::operator != ( const MinePaintScheme & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


