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

#include "./KDataStream.h"

using namespace KDIS;
using namespace KDIS::UTILS;
using namespace std;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

KDataStream::KDataStream( Endian Network_Endian /*= Big_Endian*/ ) :
    m_NetEndian( Network_Endian ),
    m_ui16CurrentWritePos( 0 )
{
    if( IsMachineBigEndian() == true )
    {
        m_MachineEndian = Big_Endian;
    }
    else
    {
        m_MachineEndian = Little_Endian;
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream::KDataStream( KOCTET * SerialData, KUINT16 DataSize, Endian Network_Endian /*= Big_Endian */ ) :
    m_NetEndian( Network_Endian ),
    m_ui16CurrentWritePos( 0 )
{
    // Copy Data into vector
    for( KUINT16 i = 0; i < DataSize; ++i )
    {
        m_vBuffer.push_back( SerialData[i] );
    }

    if( IsMachineBigEndian() == true )
    {
        m_MachineEndian = Big_Endian;
    }
    else
    {
        m_MachineEndian = Little_Endian;
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream::~KDataStream()
{
}

//////////////////////////////////////////////////////////////////////////

Endian KDataStream::GetMachineEndian() const
{
    return m_MachineEndian;
}

//////////////////////////////////////////////////////////////////////////

Endian KDataStream::GetNetWorkEndian() const
{
    return m_NetEndian;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 KDataStream::GetBufferSize() const
{
    return ( m_vBuffer.size() - m_ui16CurrentWritePos );
}

//////////////////////////////////////////////////////////////////////////

KUINT16 KDataStream::CopyIntoBuffer( KOCTET * Buffer, KUINT16 BufferSize,  KUINT16 WritePos /*= 0*/ ) const throw( KException )
{
    if( ( BufferSize - WritePos ) < ( KUINT16 )m_vBuffer.size() )
    {
        throw KException( BUFFER_TOO_SMALL );
    }

    vector<KUOCTET>::const_iterator citr = m_vBuffer.begin();
    vector<KUOCTET>::const_iterator citrEnd = m_vBuffer.end();

    KUINT16 CurrentWritePos = WritePos;

    for( ; citr != citrEnd; ++citr, ++CurrentWritePos )
    {
        Buffer[CurrentWritePos] = *citr;
    }

    return m_vBuffer.size();
}

//////////////////////////////////////////////////////////////////////////

void KDataStream::CopyFromBuffer( const KOCTET * SerialData, KUINT16 DataSize, Endian NetworkEndian /*= Big_Endian*/ )
{
    // Copy Data into vector
    for( KUINT16 i = 0; i < DataSize; ++i )
    {
        m_vBuffer.push_back( SerialData[i] );
    }
}

//////////////////////////////////////////////////////////////////////////

const KOCTET * KDataStream::GetBufferPtr() const
{
    return ( const KOCTET* )&m_vBuffer[0];
}

//////////////////////////////////////////////////////////////////////////

const vector<KUOCTET> & KDataStream::GetBuffer() const
{
    return m_vBuffer;
}

//////////////////////////////////////////////////////////////////////////

void KDataStream::ResetWritePosition()
{
    m_ui16CurrentWritePos = 0;
}

//////////////////////////////////////////////////////////////////////////

void KDataStream::SetCurrentWritePosition( KUINT16 WP )
{
    m_ui16CurrentWritePos = WP;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 KDataStream::GetCurrentWritePosition() const
{
    return m_ui16CurrentWritePos;
}

//////////////////////////////////////////////////////////////////////////

void KDataStream::Clear()
{
    m_vBuffer.clear();
    m_ui16CurrentWritePos = 0;
}

//////////////////////////////////////////////////////////////////////////

KString KDataStream::GetAsString() const
{
    KStringStream ss;

    vector<KUOCTET>::const_iterator citr = m_vBuffer.begin();
    vector<KUOCTET>::const_iterator citrEnd = m_vBuffer.end();

    for( ; citr != citrEnd; ++citr )
    {
        // If less than 10 add a zero so that each octet has the same 2 digit
        // representation.
        if( *citr < 10 )ss << "0";

        ss << hex << ( KUINT16 )*citr << " ";
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void KDataStream::ReadFromString( const KString & S )
{
    KStringStream ss( S );

    KUINT16 o;
    while( ss >> hex >> o )
    {
        m_vBuffer.push_back( o );
    }
}

//////////////////////////////////////////////////////////////////////////

void KDataStream::Write( KUOCTET V )
{
    m_vBuffer.push_back( V );
}

//////////////////////////////////////////////////////////////////////////

void KDataStream::Write( KOCTET V )
{
    m_vBuffer.push_back( V );
}

//////////////////////////////////////////////////////////////////////////

void KDataStream::Read( KUOCTET & V )
{
    V = m_vBuffer[m_ui16CurrentWritePos++];
}

//////////////////////////////////////////////////////////////////////////

void KDataStream::Read( KOCTET & V )
{
    V = m_vBuffer[m_ui16CurrentWritePos++];
}

//////////////////////////////////////////////////////////////////////////

KDataStream & KDataStream::operator << ( KDataStream val )
{
    vector<KUOCTET>::const_iterator citr = val.m_vBuffer.begin();
    vector<KUOCTET>::const_iterator citrEnd = val.m_vBuffer.end();

    // Copy data into the buffer OCTET by OCTET
    for( ; citr != citrEnd; ++citr )
    {
        m_vBuffer.push_back( *citr );
    }

    return *this;
}

//////////////////////////////////////////////////////////////////////////

KBOOL KDataStream::operator == ( const KDataStream & Value ) const
{    
	if( m_vBuffer != Value.m_vBuffer ) return false;	
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL KDataStream::operator != ( const KDataStream & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
