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

#include "./Mode5TransponderBasicData.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace UTILS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Mode5TransponderBasicData::Mode5TransponderBasicData() :
    m_ui16PIN( 0 ),
    m_ui32MsgFormats( 0 ),
    m_ui16NationalOrigin( 0 ),
    m_ui8NavSrc( 0 ),
    m_ui8FigMerit( 0 ),
    m_ui8Padding( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Mode5TransponderBasicData::Mode5TransponderBasicData( const Mode5TransponderStatus & S, KUINT16 PersonalIdentificationNumber, KUINT32 MsgFormats,
                                                      const EnhancedMode1Code & EMC1, KUINT16 NationalOrigin, Mode5TransponderSupplementalData SD,
                                                      KDIS::DATA_TYPE::ENUMS::NavigationSource NS, KUINT8 FigureOfMerit ) :
    m_ui16PIN( PersonalIdentificationNumber ),
    m_ui32MsgFormats( MsgFormats ),
    m_ui16NationalOrigin( NationalOrigin ),
    m_ui8NavSrc( NS ),
    m_ui8FigMerit( FigureOfMerit ),
    m_ui8Padding( 0 )
{
    m_Status = S;
    m_EM1Code = EMC1;
    m_SupplementalData = SD;
}

//////////////////////////////////////////////////////////////////////////

Mode5TransponderBasicData::Mode5TransponderBasicData( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Mode5TransponderBasicData::~Mode5TransponderBasicData()
{
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderBasicData::SetStatus( const Mode5TransponderStatus & S )
{
    m_Status = S;
}

//////////////////////////////////////////////////////////////////////////

const Mode5TransponderStatus & Mode5TransponderBasicData::GetStatus() const
{
    return m_Status;
}

//////////////////////////////////////////////////////////////////////////

Mode5TransponderStatus & Mode5TransponderBasicData::GetStatus()
{
    return m_Status;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderBasicData::SetPersonalIdentificationNumber( KUINT16 PIN )
{
    m_ui16PIN = PIN;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Mode5TransponderBasicData::GetPersonalIdentificationNumber() const
{
    return m_ui16PIN;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderBasicData::SetMessageFormatsPresent( KUINT32 MFP )
{
    m_ui32MsgFormats = MFP;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderBasicData::SetMessageFormatsPresent( const std::bitset<32> & MFP )
{
    m_ui32MsgFormats = MFP.to_ulong();
}

//////////////////////////////////////////////////////////////////////////

const std::bitset<32> Mode5TransponderBasicData::GetMessageFormatsPresentBitSet() const
{
    return bitset<32>( ( KINT32 )m_ui32MsgFormats );
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Mode5TransponderBasicData::GetMessageFormatsPresent()
{
    return m_ui32MsgFormats;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderBasicData::SetEnhancedMode1Code( const EnhancedMode1Code & EMC1 )
{
    m_EM1Code = EMC1;
}

//////////////////////////////////////////////////////////////////////////

const EnhancedMode1Code & Mode5TransponderBasicData::GetEnhancedMode1Code() const
{
    return m_EM1Code;
}

//////////////////////////////////////////////////////////////////////////

EnhancedMode1Code & Mode5TransponderBasicData::GetEnhancedMode1Code()
{
    return m_EM1Code;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderBasicData::SetNationalOrigin( KUINT16 NO )
{
    m_ui16NationalOrigin = NO;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Mode5TransponderBasicData::GetNationalOrigin() const
{
    return m_ui16NationalOrigin;
}

//////////////////////////////////////////////////////////////////////////

void  Mode5TransponderBasicData::SetSupplementalData( Mode5TransponderSupplementalData SD )
{
    m_SupplementalData = SD;
}

//////////////////////////////////////////////////////////////////////////

Mode5TransponderSupplementalData  Mode5TransponderBasicData::GetSupplementalData() const
{
    return m_SupplementalData;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderBasicData::SetNavigationSource( NavigationSource NS )
{
    m_ui8NavSrc = NS;
}

//////////////////////////////////////////////////////////////////////////

NavigationSource Mode5TransponderBasicData::GetNavigationSource() const
{
    return ( NavigationSource )m_ui8NavSrc;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderBasicData::SetFigureOfMerit( KUINT8 FOM ) throw( KException )
{
    if( FOM > 31 )throw KException( __FUNCTION__, INVALID_DATA, "Value must be between 0-31." );
    m_ui8FigMerit = FOM;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Mode5TransponderBasicData::GetFigureOfMerit() const
{
    return m_ui8FigMerit;
}

//////////////////////////////////////////////////////////////////////////

KString Mode5TransponderBasicData::GetAsString() const
{
    KStringStream ss;

    ss << "Mode 5 Transponder Basic Data:"
        << IndentString( m_Status.GetAsString() )
        << "Personal ID Number: " << m_ui16PIN            << "\n"
        << "Message Formats:    " << m_ui32MsgFormats     << "\n"
        << IndentString( m_EM1Code.GetAsString() )
        << "National Origin:    " << m_ui16NationalOrigin << "\n"
        << m_SupplementalData.GetAsString()
        << GetEnumAsStringNavigationSource( m_ui8NavSrc ) << "\n"
        << "Figure Of Merit:    " << m_ui8FigMerit        << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderBasicData::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MODE_5_TRANSPONDER_BASIC_DATA_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> KDIS_STREAM m_Status
           >> m_ui16PIN
           >> m_ui32MsgFormats
           >> KDIS_STREAM m_EM1Code
           >> m_ui16NationalOrigin
           >> KDIS_STREAM m_SupplementalData
           >> m_ui8NavSrc
           >> m_ui8FigMerit
           >> m_ui8Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Mode5TransponderBasicData::Encode() const
{
    KDataStream stream;

    Mode5TransponderBasicData::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Mode5TransponderBasicData::Encode( KDataStream & stream ) const
{
    stream << KDIS_STREAM m_Status
           << m_ui16PIN
           << m_ui32MsgFormats
           << KDIS_STREAM m_EM1Code
           << m_ui16NationalOrigin
           << KDIS_STREAM m_SupplementalData
           << m_ui8NavSrc
           << m_ui8FigMerit
           << m_ui8Padding;

}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderBasicData::operator == ( const Mode5TransponderBasicData & Value ) const
{
    if( m_Status             != Value.m_Status )             return false;
    if( m_ui16PIN            != Value.m_ui16PIN )            return false;
    if( m_ui32MsgFormats     != Value.m_ui32MsgFormats )     return false;
    if( m_EM1Code            != Value.m_EM1Code )            return false;
    if( m_ui16NationalOrigin != Value.m_ui16NationalOrigin ) return false;
    if( m_SupplementalData   != Value.m_SupplementalData )   return false;
    if( m_ui8NavSrc          != Value.m_ui8NavSrc )          return false;
    if( m_ui8FigMerit        != Value.m_ui8FigMerit )        return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Mode5TransponderBasicData::operator != ( const Mode5TransponderBasicData & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
