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

#include "./MinefieldAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

MinefieldAppearance::MinefieldAppearance()
{
    m_ui16BitUnion.m_ui16App = 0;
}

//////////////////////////////////////////////////////////////////////////

MinefieldAppearance::MinefieldAppearance( MinefieldType T, KBOOL IsStatusActive, KBOOL IsLaneActive, KBOOL IsStateActive )
{
    m_ui16BitUnion.m_ui16App = 0;
    m_ui16BitUnion.m_ui16Type = T;
    m_ui16BitUnion.m_ui16ActiveStatus = (IsStatusActive ? 0 : 1);
    m_ui16BitUnion.m_ui16Lane = (IsLaneActive ? 0 : 1);
    m_ui16BitUnion.m_ui16State = (IsStateActive ? 0 : 1);
}

//////////////////////////////////////////////////////////////////////////

MinefieldAppearance::MinefieldAppearance( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

MinefieldAppearance::~MinefieldAppearance()
{
}

//////////////////////////////////////////////////////////////////////////

void MinefieldAppearance::SetMinefieldType( MinefieldType T )
{
    m_ui16BitUnion.m_ui16Type = T;
}

//////////////////////////////////////////////////////////////////////////

MinefieldType MinefieldAppearance::GetMinefieldType() const
{
    return ( MinefieldType )m_ui16BitUnion.m_ui16Type;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldAppearance::SetStatusActive( KBOOL A )
{
    m_ui16BitUnion.m_ui16ActiveStatus = (A ? 0 : 1);
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldAppearance::IsStatusActive() const
{
    return m_ui16BitUnion.m_ui16ActiveStatus == 0;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldAppearance::SetLaneActive( KBOOL A )
{
    m_ui16BitUnion.m_ui16Lane = (A ? 0 : 1);
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldAppearance::IsLaneActive() const
{
    return m_ui16BitUnion.m_ui16Lane == 0;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldAppearance::SetStateActive( KBOOL A )
{
    m_ui16BitUnion.m_ui16State = (A ? 0 : 1);
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldAppearance::IsStateActive() const
{
    return m_ui16BitUnion.m_ui16State == 0;
}

//////////////////////////////////////////////////////////////////////////

KString MinefieldAppearance::GetAsString() const
{
    KStringStream ss;

    ss << "MinefieldAppearance:"
       << "\n\tMinefield Type:           " << GetEnumAsStringMinefieldType( m_ui16BitUnion.m_ui16Type )
       << "\n\tActive Status(0 = true):  " << m_ui16BitUnion.m_ui16ActiveStatus
       << "\n\tActive Lane(0 = true):    " << m_ui16BitUnion.m_ui16Lane
       << "\n\tState(0 = true):          " << m_ui16BitUnion.m_ui16State
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void MinefieldAppearance::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MINEFIELD_APPEARANCE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16BitUnion.m_ui16App;
}

//////////////////////////////////////////////////////////////////////////

KDataStream MinefieldAppearance::Encode() const
{
    KDataStream stream;

    MinefieldAppearance::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void MinefieldAppearance::Encode( KDataStream & stream ) const
{
    stream << m_ui16BitUnion.m_ui16App;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldAppearance::operator == ( const MinefieldAppearance & Value ) const
{
    if( m_ui16BitUnion.m_ui16App != Value.m_ui16BitUnion.m_ui16App )return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL MinefieldAppearance::operator != ( const MinefieldAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

