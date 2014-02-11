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

#include "./RecordSet.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

RecordSet::RecordSet() :
    m_ui32RecID( 0 ),
    m_ui32RecSetSerialNum( 0 ),
    m_ui16RecLen( RECORD_SET_SIZE ),
    m_ui16RecCnt( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

RecordSet::RecordSet( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

RecordSet::RecordSet( RecordID ID, KUINT32 SerialNum, const vector<KUINT8> & RecordValue,
                      KUINT16 RecordCount ) :
    m_ui32RecID( ID ),
    m_ui32RecSetSerialNum( SerialNum )
{
    SetRecordValues( RecordValue, RecordCount );
}

//////////////////////////////////////////////////////////////////////////

RecordSet::~RecordSet()
{
    m_vui8RecVals.clear();
}

//////////////////////////////////////////////////////////////////////////

void RecordSet::SetRecordID( RecordID ID )
{
    m_ui32RecID = ID;
}

//////////////////////////////////////////////////////////////////////////

RecordID RecordSet::GetRecordID() const
{
    return ( RecordID )m_ui32RecID;
}

//////////////////////////////////////////////////////////////////////////

void RecordSet::SetSerialNumber( KUINT32 SN )
{
    m_ui32RecSetSerialNum = SN;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 RecordSet::GetSerialNumber() const
{
    return m_ui32RecSetSerialNum;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 RecordSet::GetRecordLength() const
{
    return m_ui16RecLen;
}

//////////////////////////////////////////////////////////////////////////

void RecordSet::SetRecordCount( KUINT16 RC )
{
    m_ui16RecCnt = RC;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 RecordSet::GetRecordCount() const
{
    return m_ui16RecCnt;
}

//////////////////////////////////////////////////////////////////////////

void RecordSet::SetRecordValues( const vector<KUINT8> & RV, KUINT16 RecCnt )
{
    m_ui16RecCnt = RecCnt;
    m_vui8RecVals = RV;

    // Calculate padding to a 32 bit boundary.
    KUINT8 ui8NumPadding = m_ui16RecLen % 4;

    // Add the padding
    KUINT8 ui8Pad = 0;

    for( KUINT8 i = 0; i < ui8NumPadding; ++i )
    {
        m_vui8RecVals.push_back( ui8Pad );
    }

    m_ui16RecLen += RECORD_SET_SIZE + m_vui8RecVals.size();
}

//////////////////////////////////////////////////////////////////////////

const vector<KUINT8> & RecordSet::GetRecordValues() const
{
    return m_vui8RecVals;
}

//////////////////////////////////////////////////////////////////////////

void RecordSet::ClearRecordValues()
{
    m_ui16RecCnt = 0;
    m_vui8RecVals.clear();
    m_ui16RecLen = RECORD_SET_SIZE;
}

//////////////////////////////////////////////////////////////////////////

KString RecordSet::GetAsString() const
{
    KStringStream ss;

    ss << "Record Set"
       << "\n\tID:            " << m_ui32RecID
       << "\n\tSerial Number: " << m_ui32RecSetSerialNum
       << "\n\tLength:        " << m_ui16RecLen
       << "\n\tCount:         " << m_ui16RecCnt
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void RecordSet::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < RECORD_SET_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vui8RecVals.clear();

    stream >> m_ui32RecID
           >> m_ui32RecSetSerialNum
           >> m_ui16RecLen
           >> m_ui16RecCnt;

    KUINT8 ui8LenOfRecVal = m_ui16RecLen - RECORD_SET_SIZE;

    KUINT8 ui8Val = 0;

    // This data also includes any padding that may exist.
    for( KUINT8 i = 0; i < ui8LenOfRecVal; ++i )
    {
        stream >> ui8Val;
        m_vui8RecVals.push_back( ui8Val );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream RecordSet::Encode() const
{
    KDataStream stream;

    RecordSet::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void RecordSet::Encode( KDataStream & stream ) const
{
    stream << m_ui32RecID
           << m_ui32RecSetSerialNum
           << m_ui16RecLen
           << m_ui16RecCnt;

    vector<KUINT8>::const_iterator citr = m_vui8RecVals.begin();
    vector<KUINT8>::const_iterator citrEnd = m_vui8RecVals.end();

    for( ; citr != citrEnd; ++citr )
    {
        stream << *citr;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL RecordSet::operator == ( const RecordSet & Value ) const
{
    if( m_ui32RecID           != Value.m_ui32RecID )            return false;
    if( m_ui32RecSetSerialNum != Value.m_ui32RecSetSerialNum )  return false;
    if( m_ui16RecLen          != Value.m_ui16RecLen )           return false;
    if( m_ui16RecCnt          != Value.m_ui16RecCnt )           return false;
    if( m_vui8RecVals         != Value.m_vui8RecVals )          return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL RecordSet::operator != ( const RecordSet & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

