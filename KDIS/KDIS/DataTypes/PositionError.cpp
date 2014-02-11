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

#include "./PositionError.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

PositionError::PositionError()
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

PositionError::~PositionError()
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

