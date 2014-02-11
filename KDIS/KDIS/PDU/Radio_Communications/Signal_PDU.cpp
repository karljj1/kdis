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

#include "./Signal_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Signal_PDU::Signal_PDU() :
	m_ui32SampleRate( 0 ),
    m_ui16DataLength( 0 ),
	m_ui16Samples( 0 )
{
    m_ui8PDUType = Signal_PDU_Type;
    m_ui16PDULength = SIGNAL_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Signal_PDU::Signal_PDU( const Header & H ) :
	Radio_Communications_Header( H ),
	m_ui32SampleRate( 0 ),
    m_ui16DataLength( 0 ),
	m_ui16Samples( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Signal_PDU::Signal_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Signal_PDU::Signal_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Radio_Communications_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Signal_PDU::Signal_PDU( const EntityIdentifier & ID, KUINT16 RadioID, const EncodingScheme & ES,
                        KUINT32 SampleRate, KUINT16 Samples, const KOCTET * Data, KUINT16 DataLength ) :
    Radio_Communications_Header( ID, RadioID ),
    m_EncodingScheme( ES ),
    m_ui32SampleRate( SampleRate ),
    m_ui16Samples( Samples )
{
    m_ui8PDUType = Signal_PDU_Type;
    m_ui16PDULength = SIGNAL_PDU_SIZE;
    SetData( Data, DataLength );
}

//////////////////////////////////////////////////////////////////////////

Signal_PDU::~Signal_PDU()
{
    m_vData.clear();
}

//////////////////////////////////////////////////////////////////////////

void Signal_PDU::SetEncodingScheme( const EncodingScheme & ES )
{
    if( ES.GetEncodingClass() == DatabaseIndex )m_ui16DataLength = 96;
    m_EncodingScheme = ES;
}

//////////////////////////////////////////////////////////////////////////

const EncodingScheme & Signal_PDU::GetEncodingScheme() const
{
    return m_EncodingScheme;
}

//////////////////////////////////////////////////////////////////////////

EncodingScheme & Signal_PDU::GetEncodingScheme()
{
    return m_EncodingScheme;
}

//////////////////////////////////////////////////////////////////////////

void Signal_PDU::SetSampleRate( KUINT32 SR )
{
    m_ui32SampleRate = SR;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Signal_PDU::GetSampleRate() const
{
    return m_ui32SampleRate;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Signal_PDU::GetDataLength() const
{
    return m_ui16DataLength;
}

//////////////////////////////////////////////////////////////////////////

void Signal_PDU::SetSamples( KUINT16 S )
{
    m_ui16Samples = S;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Signal_PDU::GetSamples() const
{
    return m_ui16Samples;
}

//////////////////////////////////////////////////////////////////////////

void Signal_PDU::SetData( const KOCTET * D, KUINT16 Length )
{
    // If we already have data clear it first.
    m_ui16PDULength = SIGNAL_PDU_SIZE;
    m_vData.clear();	

    // Copy data into the vector
    KUINT16 uiDataSz = Length / 8;
	m_vData.reserve( uiDataSz );
    for( KUINT16 i = 0; i < uiDataSz; ++i, ++D )
    {
        m_vData.push_back( *D );
    }

	// Data length does not include the padding
	m_ui16DataLength = m_vData.size() * 8;

	// Do we need to apply padding, the PDU size should be a multiple
    // of 32 bits / 4 octets.
    KUINT8 ui8PaddingNeeded = m_vData.size() % 4 == 0 ? 0 : (4 - m_vData.size() % 4); // Add padding;
    for( KUINT8 i = 0; i < ui8PaddingNeeded; ++ i )
    {
        m_vData.push_back( 0 );
    }

	// Update lengths    
    m_ui16PDULength += m_vData.size();
}

//////////////////////////////////////////////////////////////////////////

void Signal_PDU::GetData( KOCTET * D, KUINT16 Length ) const throw( KException )
{
    if( Length < m_ui16DataLength )throw KException( __FUNCTION__, BUFFER_TOO_SMALL );

    // Only return the data, not any padding that may have been added.
    KUINT16 uiDataSz = m_ui16DataLength / 8;
    for( KUINT16 i = 0; i < uiDataSz; ++i )
    {
        D[i] = m_vData[i];
    }
}

//////////////////////////////////////////////////////////////////////////

KString Signal_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Signal PDU-\n"
       << Radio_Communications_Header::GetAsString()
       << m_EncodingScheme.GetAsString()
       << "Sample Rate:     " << m_ui32SampleRate << "\n"
       << "Data Length:     " << m_ui16DataLength << "\n"
       << "Samples:         " << m_ui16Samples    << "\n";

    // Data is not printed as we don't know how to interpret the data.
    // You could create a derived class and override the GetAsString
    // if you wanted to interpret a particular type of data.

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Signal_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < SIGNAL_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Radio_Communications_Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_EncodingScheme
           >> m_ui32SampleRate
           >> m_ui16DataLength
           >> m_ui16Samples;

    KUINT16 dl =  m_ui16DataLength / 8;
	dl += ( dl % 4 == 0 ? 0 : ( 4 - dl % 4 ) ); // Add padding
    for( KUINT16 i = 0; i < dl; ++i )
    {
        KOCTET o;
        stream >> o;
        m_vData.push_back( o );
    }	
}

//////////////////////////////////////////////////////////////////////////

KDataStream Signal_PDU::Encode() const
{
    KDataStream stream;

    Signal_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Signal_PDU::Encode( KDataStream & stream ) const
{
    Radio_Communications_Header::Encode( stream );

    stream << KDIS_STREAM m_EncodingScheme
           << m_ui32SampleRate
           << m_ui16DataLength
           << m_ui16Samples;

    vector<KOCTET>::const_iterator citr = m_vData.begin();
    vector<KOCTET>::const_iterator citrEnd = m_vData.end();
    for( ; citr != citrEnd; ++citr )
    {
        stream << *citr;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Signal_PDU::operator == ( const Signal_PDU & Value ) const
{
    if( Radio_Communications_Header::operator   !=( Value ) )               return false;
    if( m_EncodingScheme                        != Value.m_EncodingScheme ) return false;
    if( m_ui32SampleRate                        != Value.m_ui32SampleRate ) return false;
    if( m_ui16DataLength                        != Value.m_ui16DataLength ) return false;
    if( m_ui16Samples                           != Value.m_ui16Samples )    return false;
    if( m_vData                                 != Value.m_vData )          return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Signal_PDU::operator != ( const Signal_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
