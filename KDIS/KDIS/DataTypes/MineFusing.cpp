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

#include "./MineFusing.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

MineFusing::MineFusing()
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

MineFusing::~MineFusing()
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
       << "\n\tPrimary Fuse:            " << GetEnumAsStringMineFuse( m_FuseUnion.m_ui16Primary )
       << "\n\tSecondary Fuse:          " << GetEnumAsStringMineFuse( m_FuseUnion.m_ui16Secondary )
       << "\n\tAnti-Handling Device:    " << m_FuseUnion.m_ui16AHD
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

