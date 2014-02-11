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

#include "./LayerHeader.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

LayerHeader::LayerHeader() :
    m_ui8LayerNumber( 0 ),
    m_ui8LayerSpecificInfo( 0 ),
    m_ui16LayerLength( LAYER_HEADER_SIZE )
{
}

//////////////////////////////////////////////////////////////////////////

LayerHeader::LayerHeader( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

LayerHeader::LayerHeader( KUINT8 LayerNumber, KUINT8 LayerSpecificInfo, KUINT16 LayerLength ) :
    m_ui8LayerNumber( LayerNumber ),
    m_ui8LayerSpecificInfo( LayerSpecificInfo ),
    m_ui16LayerLength( LayerLength )
{
}

//////////////////////////////////////////////////////////////////////////

LayerHeader::~LayerHeader()
{
}

//////////////////////////////////////////////////////////////////////////

void LayerHeader::SetLayerNumber( KUINT8 LN )
{
    m_ui8LayerNumber = LN;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 LayerHeader::GetLayerNumber() const
{
    return m_ui8LayerNumber;
}

//////////////////////////////////////////////////////////////////////////

void LayerHeader::SetLayerSpecificInfomation( KUINT8 LSI )
{
    m_ui8LayerSpecificInfo = LSI;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 LayerHeader::GetLayerSpecificInfomation() const
{
    return m_ui8LayerSpecificInfo;
}

//////////////////////////////////////////////////////////////////////////

void LayerHeader::SetLayerLength( KUINT16 L )
{
    m_ui16LayerLength = L;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 LayerHeader::GetLayerLength() const
{
    return m_ui16LayerLength;
}

//////////////////////////////////////////////////////////////////////////

KString LayerHeader::GetAsString() const
{
    KStringStream ss;

    ss << "LayerHeader:"
       << "\n\tLayer Number:        " << ( KUINT16 )m_ui8LayerNumber
       << "\n\tLayer Specific Info: " << ( KUINT16 )m_ui8LayerSpecificInfo
       << "\n\tLayer Length:        " << m_ui16LayerLength
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void LayerHeader::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < LAYER_HEADER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8LayerNumber
           >> m_ui8LayerSpecificInfo
           >> m_ui16LayerLength;
}

//////////////////////////////////////////////////////////////////////////

KDataStream LayerHeader::Encode() const
{
    KDataStream stream;

    LayerHeader::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void LayerHeader::Encode( KDataStream & stream ) const
{
    stream << m_ui8LayerNumber
           << m_ui8LayerSpecificInfo
           << m_ui16LayerLength;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LayerHeader::operator == ( const LayerHeader & Value ) const
{
    if( m_ui8LayerNumber       != Value.m_ui8LayerNumber )       return false;
    if( m_ui8LayerSpecificInfo != Value.m_ui8LayerSpecificInfo ) return false;
    if( m_ui16LayerLength      != Value.m_ui16LayerLength )      return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LayerHeader::operator != ( const LayerHeader & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////



