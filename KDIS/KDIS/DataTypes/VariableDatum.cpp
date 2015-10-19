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

#include "./VariableDatum.h"
#include <math.h>

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

VariableDatum::VariableDatum() :
    m_ui32DatumLength( 0 ),
    m_ui32DatumID( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

VariableDatum::VariableDatum( DatumID ID, const KString & Value )
{
    m_ui32DatumID = ID;

    SetDatumValue( Value );
}

//////////////////////////////////////////////////////////////////////////

VariableDatum::VariableDatum( DatumID ID, const KOCTET* data, KUINT32 sizeInBits )
{
    m_ui32DatumID = ID;

    SetDatumValue( data, sizeInBits );
}

//////////////////////////////////////////////////////////////////////////

VariableDatum::VariableDatum( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

VariableDatum::~VariableDatum()
{
}

//////////////////////////////////////////////////////////////////////////

void VariableDatum::SetDatumID( DatumID ID )
{
    m_ui32DatumID = ID;
}

//////////////////////////////////////////////////////////////////////////

DatumID VariableDatum::GetDatumID() const
{
    return ( DatumID )m_ui32DatumID;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 VariableDatum::GetDatumLength() const
{
    return m_ui32DatumLength;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 VariableDatum::GetPDULength() const
{
    return VARIABLE_DATUM_SIZE + ( m_v8DatumValue.size() * 8 );
}

//////////////////////////////////////////////////////////////////////////

void VariableDatum::SetDatumValue( const KString & s )
{
    SetDatumValue( s.c_str(), ( s.length() + 1 ) * 8 ); // +1 to allow for terminating NULL ...
}

//////////////////////////////////////////////////////////////////////////

void VariableDatum::SetDatumValue( const KOCTET * data, KUINT32 sizeInBits )
{
    m_v8DatumValue.clear();

    KUINT32 sizeInOctets = ceil( sizeInBits / 8.0 );
    for( KUINT16 i = 0; i < sizeInOctets; )
    {
        DatumEntry de;

        for( KUINT16 j = 0; j < 8 && i < sizeInOctets; ++j, ++i )
        {
            de.Buffer[j] = data[i];
        }
        m_v8DatumValue.push_back( de );
    }

    m_ui32DatumLength = sizeInBits;
}

//////////////////////////////////////////////////////////////////////////

void VariableDatum::GetDatumValueCopyIntoBuffer( KOCTET * Buffer, KUINT16 BufferSize ) const throw( KException )
{
    KUINT32 sizeInOctets = ceil( m_ui32DatumLength / 8.0 );

    if( BufferSize < sizeInOctets )throw KException( __FUNCTION__, BUFFER_TOO_SMALL );

    // Copy the data into the buffer, octet by octet
    vector<DatumEntry>::const_iterator citr = m_v8DatumValue.begin();

    KUINT16 i = 0;

    while( i < sizeInOctets )
    {
        for( KUINT16 j = 0; i < sizeInOctets && j < 8; ++j, ++i )
        {
            Buffer[i] = citr->Buffer[j];
        }
        ++citr;
    }
}

//////////////////////////////////////////////////////////////////////////

KString VariableDatum::GetDatumValueAsKString() const
{
    KStringStream ss;

    vector<DatumEntry>::const_iterator citr =  m_v8DatumValue.begin();
    vector<DatumEntry>::const_iterator citrEnd = m_v8DatumValue.end();

    KUINT32 i = 0;

    KUINT32 ui32LengthInOctets = ceil(m_ui32DatumLength / 8.0);

    while( citr != citrEnd )
    {
        for( KUINT16 j = 0; i < ui32LengthInOctets && j < 8; ++j, ++i )
        {
            ss << citr->Buffer[j];
        }
        ++citr;
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

vector<KUINT64> VariableDatum::GetDatumValueAsKUINT64() const
{
    KBOOL bSwapBytes = !IsMachineBigEndian();

    vector<DatumEntry>::const_iterator citr = m_v8DatumValue.begin();
    vector<DatumEntry>::const_iterator citrEnd = m_v8DatumValue.end();

    vector<KUINT64> m_Return;

    KUINT32 ui32CurrentPos = 0;
    KUINT32 ui32LengthInOctets = ceil(m_ui32DatumLength / 8.0);

    while( citr != citrEnd )
    {
        if( ( ui32LengthInOctets - ui32CurrentPos ) < 8 )break;

        m_Return.push_back( NetToKUINT64( citr->Buffer, bSwapBytes ).m_Value );

        ui32CurrentPos += 8;
    }

    return m_Return;
}

//////////////////////////////////////////////////////////////////////////

vector<KFLOAT64> VariableDatum::GetDatumValueAsKFLOAT64() const
{
    KBOOL bSwapBytes = !IsMachineBigEndian();

    vector<DatumEntry>::const_iterator citr = m_v8DatumValue.begin();
    vector<DatumEntry>::const_iterator citrEnd = m_v8DatumValue.end();

    vector<KFLOAT64> m_Return;

    KUINT32 ui32CurrentPos = 0;
    KUINT32 ui32LengthInOctets = ceil(m_ui32DatumLength / 8.0);

    while( citr != citrEnd )
    {
        if( ( ui32LengthInOctets - ui32CurrentPos ) < 8 )break;

        m_Return.push_back( NetToKFLOAT64( citr->Buffer, bSwapBytes ).m_Value );

        ui32CurrentPos += 8;
    }

    return m_Return;
}

//////////////////////////////////////////////////////////////////////////

void VariableDatum::ClearDatumValue()
{
    m_v8DatumValue.clear();
    m_ui32DatumLength = 0;
}

//////////////////////////////////////////////////////////////////////////

KString VariableDatum::GetAsString() const
{
    KStringStream ss;

    // For now we return the datum value as a string.
    ss << "Variable Datum:"
       << "\n\tID:          " << GetEnumAsStringDatumID( m_ui32DatumID )
       << "\n\tLength:      " << m_ui32DatumLength
       << "\n\tValue(S):    " << GetDatumValueAsKString()
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void VariableDatum::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < VARIABLE_DATUM_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_v8DatumValue.clear();

    stream >> m_ui32DatumID
           >> m_ui32DatumLength;

    KUINT32 ui32LengthInOctets = ceil(ceil(m_ui32DatumLength / 8.0) / 8.0) * 8;

    // Datum length is returned in bits, so we need to convert to octets
    for( KUINT16 i = 0; i < ui32LengthInOctets; )
    {
        DatumEntry de;

        for( KUINT16 j = 0; i < ui32LengthInOctets && j < 8; ++j, ++i )
        {
            KOCTET o;
            stream >> o;
            de.Buffer[j] = o;
        }
        m_v8DatumValue.push_back( de );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream VariableDatum::Encode() const
{
    KDataStream stream;

    VariableDatum::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void VariableDatum::Encode( KDataStream & stream ) const
{
    stream << m_ui32DatumID
           << m_ui32DatumLength;

    vector<DatumEntry>::const_iterator citr = m_v8DatumValue.begin();
    vector<DatumEntry>::const_iterator citrEnd = m_v8DatumValue.end();

    while( citr != citrEnd )
    {
        for( KUINT16 i = 0; i < 8; ++i )
        {
            stream << citr->Buffer[i];
        }

        ++citr;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL VariableDatum::operator == ( const VariableDatum & Value ) const
{
    if( m_ui32DatumID     != Value.m_ui32DatumID )     return false;
    if( m_ui32DatumLength != Value.m_ui32DatumLength ) return false;

    vector<DatumEntry>::const_iterator citrThis =  m_v8DatumValue.begin(),
                                       citrOther = Value.m_v8DatumValue.begin();

    while( citrThis != m_v8DatumValue.end() && citrOther != Value.m_v8DatumValue.end() )
    {
        if( memcmp( citrThis->Buffer, citrOther->Buffer, 8 ) != 0 )return false;
        ++citrThis;
        ++citrOther;
    }
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL VariableDatum::operator != ( const VariableDatum & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

