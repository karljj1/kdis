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

/********************************************************************
    class:      KDataStream
    created:    2008/09/22
    author:     Karl Jones

    purpose:    Converts data types into a buffer stream for sending
                via a network/writing to file.
*********************************************************************/

#pragma once

#include "./KDefines.h"
#include "./KEncodersDecoders.h"
#include "./Extras/KUtils.h"
#include <vector>

namespace KDIS {
using std::vector;

class KDIS_EXPORT KDataStream
{
private:

    Endian m_MachineEndian;

    Endian m_NetEndian;

    vector<KUOCTET> m_vBuffer;
    KUINT16 m_ui16CurrentWritePos;

public:

    // All DIS data is sent in Big Endian format
    KDataStream( Endian NetworkEndian = Big_Endian );

    KDataStream( KOCTET * SerialData, KUINT16 DataSize, Endian NetworkEndian = Big_Endian );

    ~KDataStream( void );

    //************************************
    // FullName:    KDIS::KDataStream::GetMachineEndian
    // Description: Returns the machine endian. Calculated automatically.
    //************************************
    Endian GetMachineEndian() const;

    //************************************
    // FullName:    KDIS::KDataStream::GetNetWorkEndian
    // Description: Returns the network endian, set by user in
    //              constructor, Big_Endian by default.
    //************************************
    Endian GetNetWorkEndian() const;

    //************************************
    // FullName:    KDIS::KDataStream::GetBufferSize
    // Description: Returns current buffer size in Octets/Bytes
    //************************************
    KUINT16 GetBufferSize() const;

    //************************************
    // FullName:    KDIS::KDataStream::CopyIntoBuffer
    // Description: Copy the stream into an Octet buffer,
    //              Returns total bytes copied into buffer.
    //              Throws exception if the buffer is too small.
    // Parameter:   KOCTET * Buffer
    // Parameter:   KUINT16 BufferSize
    // Parameter:   KUINT16 WritePos - Where to start writing into the buffer
    //************************************
    KUINT16 CopyIntoBuffer( KOCTET * Buffer, KUINT16 BufferSize, KUINT16 WritePos = 0 ) const throw( KException );

    //************************************
    // FullName:    KDIS::KDataStream::CopyFromBuffer
    // Description: Copy data from a buffer/array into the data stream
    // Parameter:   KOCTET * SerialData
    // Parameter:   KUINT16 DataSize
    // Parameter:   Endian NetworkEndian = Big_Endian
    //************************************
    void CopyFromBuffer( KOCTET * SerialData, KUINT16 DataSize, Endian NetworkEndian = Big_Endian );

    //************************************
    // FullName:    KDIS::KDataStream::GetBufferPtr
    // Description: Returns a pointer to the buffer.
    //              This is a more efficient way of sending data than using CopyIntoBuffer.
    //************************************
    const KOCTET * GetBufferPtr() const;

    //************************************
    // FullName:    KDIS::KDataStream::GetBuffer
    // Description: Returns a constant reference to the internal buffer.
    //              Useful if you need lower-level access to the data.
    //************************************
    const vector<KUOCTET> & GetBuffer() const;

    //************************************
    // FullName:    KDIS::KDataStream::ResetWritePosition
    // Description: Moves the write position back to the start of the buffer.
    //************************************
    void ResetWritePosition();

    //************************************
    // FullName:    KDIS::KDataStream::SetCurrentWritePosition
    //              KDIS::KDataStream::GetCurrentWritePosition
    // Description: The write position is the current position in the buffer that we are reading data from.
    //              Using these 2 functions it is possible to "peak" at data and then restore the buffers
    //              write position. For example if we wanted to read the next 4 bytes to determine what the
    //              next data type is we could peak and then reset the write position back by 4 so that the
    //              data can be re-read by the data types decode function.
    // Parameter:   KUINT16 WP
    //************************************
    void SetCurrentWritePosition( KUINT16 WP );
    KUINT16 GetCurrentWritePosition() const;

    //************************************
    // FullName:    KDIS::KDataStream::Clear
    // Description: Clears contents
    //************************************
    void Clear();

    //************************************
    // FullName:    KDIS::KDataStream::GetAsString
    // Description: Returns string representation of the stream, values are in hex.
    //************************************
    KString GetAsString() const;

    //************************************
    // FullName:    KDIS::KDataStream::GetAsString
    // Description: Read a string of hex octets and convert into
    //              a data stream.
    //              This function works in conjunction with GetAsString, each PDU could be saved to a
    //              file and then read back in using this function. Good for debugging or logging data.
    // Parameter:   const KString & S
    //************************************
    void ReadFromString( const KString & S );

    //************************************
    // FullName:    KDIS::KDataStream<Type>::Write
    // Description: Write data into stream.
    // Parameter:   Type T, KUOCTET V, KOCTET V
    //************************************
    template<class Type>
    void Write( Type T );
    void Write( KUOCTET V );
    void Write( KOCTET V );

    //************************************
    // FullName:    KDIS::KDataStream<Type>::Write
    // Description: Read data from stream.
    // Parameter:   Type & T, KUOCTET & V, KOCTET & V
    //************************************
    template<class Type>
    void Read( Type & T );
    void Read( KUOCTET & V );
    void Read( KOCTET & V );

    // Write into stream
    template<class Type>
    KDataStream & operator << ( Type T );
    KDataStream & operator << ( KDataStream val );

    // Read from stream
    template<class Type>
    KDataStream & operator >> ( Type & T );
};

//////////////////////////////////////////////////////////////////////////
// Template Operators
//////////////////////////////////////////////////////////////////////////

template<class Type>
void KDataStream::Write( Type T )
{
    KBOOL bSwapBytes;
    if( m_MachineEndian == m_NetEndian )bSwapBytes = false;
    else bSwapBytes = true;

    NetToDataType<Type> OctArray( T, bSwapBytes );

    for( KUINT8 i = 0; i < sizeof T; ++i )
    {
        m_vBuffer.push_back( OctArray.m_Octs[i] );
    }
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
void KDataStream::Read( Type & T )
{
    NetToDataType<Type> OctArray( T, false );

    // Copy octets into data type
    for( KUINT8 i = 0; i < sizeof T; ++i, ++m_ui16CurrentWritePos )
    {
        OctArray.m_Octs[i] = m_vBuffer[m_ui16CurrentWritePos];
    }

    if( m_MachineEndian != m_NetEndian )
    {
        OctArray.SwapBytes();
    }

    T = OctArray.m_Value;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
KDataStream & KDataStream::operator<<( Type T )
{
    Write( T );
    return *this;
}

//////////////////////////////////////////////////////////////////////////

template<class Type>
KDataStream & KDataStream::operator>>( Type & T )
{
    Read( T );
    return *this;
}

//////////////////////////////////////////////////////////////////////////
}; // END namespace KDIS

