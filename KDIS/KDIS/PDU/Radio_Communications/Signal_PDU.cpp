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

Signal_PDU::Signal_PDU( void ) :
	m_ui32SampleRate( 0 ),
    m_ui16DataLength( 0 ),
	m_ui16Samples( 0 )
{
    m_ui8PDUType = Signal_PDU_Type;
    m_ui16PDULength = SIGNAL_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Signal_PDU::Signal_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
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

Signal_PDU::~Signal_PDU( void )
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
    m_ui16PDULength -= m_vData.size();
    m_vData.clear();

    // Copy data into the vector
    KUINT16 uiDataSz = Length / 8;
    for( KUINT16 i = 0; i < uiDataSz; ++i, ++D )
    {
        m_vData.push_back( *D );
    }

    // Do we need to apply padding, the PDU size should be a multiple
    // of 32 bits / 4 octets.
    KUINT8 ui8PaddingNeeded = m_ui16PDULength % 4;

    for( KUINT8 i = 0; i < ui8PaddingNeeded; ++ i )
    {
        m_vData.push_back( 0 );
    }

    // Update lengths
    m_ui16DataLength = m_vData.size() * 8;
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

void Signal_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < SIGNAL_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Radio_Communications_Header::Decode( stream );

    stream >> KDIS_STREAM m_EncodingScheme
           >> m_ui32SampleRate
           >> m_ui16DataLength
           >> m_ui16Samples;

    for( KUINT16 i = 0; i < ( m_ui16DataLength / 8 ); ++i )
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
