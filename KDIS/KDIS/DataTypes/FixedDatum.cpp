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

#include "./FixedDatum.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

FixedDatum::FixedDatum() :
    m_ui32DatumID( 0 )
{
    memset( m_cDatumValue, 0, 4 );
}

//////////////////////////////////////////////////////////////////////////

FixedDatum::FixedDatum( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

FixedDatum::~FixedDatum()
{
}

//////////////////////////////////////////////////////////////////////////

void FixedDatum::SetDatumID( DatumID ID )
{
    m_ui32DatumID = ID;
}

//////////////////////////////////////////////////////////////////////////

DatumID FixedDatum::GetDatumID() const
{
    return ( DatumID )m_ui32DatumID;
}

//////////////////////////////////////////////////////////////////////////

void FixedDatum::GetDatumValue( KOCTET * Buffer, KUINT16 BufferSize ) const throw( KException )
{
    if( BufferSize < 4 )throw KException( __FUNCTION__, BUFFER_TOO_SMALL );
	memcpy( Buffer, m_cDatumValue, 4 );
}

//////////////////////////////////////////////////////////////////////////

KString FixedDatum::GetAsString() const
{
    KStringStream ss;

    NetToKUINT32 NetToSys( m_cDatumValue, false );

    // TODO: maybe determine what the data type should be when printing out, this
    // could be a lot of work.
    ss << "Fixed Datum:"
       << "\n\tID:          " << GetEnumAsStringDatumID( m_ui32DatumID )
       << "\n\tValue(UI32): " << NetToSys.m_Value
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void FixedDatum::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < FixedDatum::FIXED_DATUM_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32DatumID;

    for( KUINT16 i = 0; i < 4; ++i )
    {
        stream >> m_cDatumValue[i];
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream FixedDatum::Encode() const
{
    KDataStream stream;

    FixedDatum::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void FixedDatum::Encode( KDataStream & stream ) const
{
    stream << m_ui32DatumID;

    for( KUINT16 i = 0; i < 4; ++i )
    {
        stream << m_cDatumValue[i];
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL FixedDatum::operator == ( const FixedDatum & Value ) const
{
    if( m_ui32DatumID != Value.m_ui32DatumID )                 return false;
    if( memcmp( m_cDatumValue, Value.m_cDatumValue, 4 ) != 0 ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FixedDatum::operator != ( const FixedDatum & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


