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

#include "./UnderwaterAcousticEmitterBeam.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

UnderwaterAcousticEmitterBeam::UnderwaterAcousticEmitterBeam()  :
    m_ui8BeamDataLength( UNDERWATER_ACOUSTIC_EMITTER_BEAM_SIZE / 4 ),
    m_ui8BeamIDNumber( 0 ),
    m_ui16Padding1( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

UnderwaterAcousticEmitterBeam::UnderwaterAcousticEmitterBeam( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

UnderwaterAcousticEmitterBeam::UnderwaterAcousticEmitterBeam( KUINT8 ID, const UnderwaterAcousticFundamentalParameterData & UAFPD ) :
    m_ui8BeamDataLength( UNDERWATER_ACOUSTIC_EMITTER_BEAM_SIZE / 4 ),
    m_ui8BeamIDNumber( ID ),
    m_ui16Padding1( 0 ),
    m_UAFPD( UAFPD )
{
}

//////////////////////////////////////////////////////////////////////////

UnderwaterAcousticEmitterBeam::~UnderwaterAcousticEmitterBeam()
{
}

//////////////////////////////////////////////////////////////////////////

KUINT8 UnderwaterAcousticEmitterBeam::GetBeamDataLength() const
{
    return m_ui8BeamDataLength;
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticEmitterBeam::SetUnderwaterAcousticEmitterBeamIDNumber( KUINT8 ID )
{
    m_ui8BeamIDNumber = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 UnderwaterAcousticEmitterBeam::GetUnderwaterAcousticEmitterBeamIDNumber() const
{
    return m_ui8BeamIDNumber;
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticEmitterBeam::SetUnderwaterAcousticFundamentalParameterData( const UnderwaterAcousticFundamentalParameterData & UAFPD )
{
    m_UAFPD = UAFPD;
}

//////////////////////////////////////////////////////////////////////////

const UnderwaterAcousticFundamentalParameterData & UnderwaterAcousticEmitterBeam::GetUnderwaterAcousticFundamentalParameterData() const
{
    return m_UAFPD;
}

//////////////////////////////////////////////////////////////////////////

UnderwaterAcousticFundamentalParameterData & UnderwaterAcousticEmitterBeam::GetUnderwaterAcousticFundamentalParameterData()
{
    return m_UAFPD;
}

//////////////////////////////////////////////////////////////////////////

KString UnderwaterAcousticEmitterBeam::GetAsString() const
{
    KStringStream ss;

    ss << "Underwater Acoustic Emitter Beam:"
       << "\n\tBeam Data Length:              " << ( KUINT16 )m_ui8BeamDataLength
       << "\n\tBeam ID Number:		          " << ( KUINT16 )m_ui8BeamIDNumber
       << m_UAFPD.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticEmitterBeam::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < UNDERWATER_ACOUSTIC_EMITTER_BEAM_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8BeamDataLength
           >> m_ui8BeamIDNumber
           >> m_ui16Padding1
           >> KDIS_STREAM m_UAFPD;
}

//////////////////////////////////////////////////////////////////////////

KDataStream UnderwaterAcousticEmitterBeam::Encode() const
{
    KDataStream stream;

    UnderwaterAcousticEmitterBeam::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticEmitterBeam::Encode( KDataStream & stream ) const
{
    stream << m_ui8BeamDataLength
           << m_ui8BeamIDNumber
           << m_ui16Padding1
           << KDIS_STREAM m_UAFPD;
}

//////////////////////////////////////////////////////////////////////////

KBOOL UnderwaterAcousticEmitterBeam::operator == ( const UnderwaterAcousticEmitterBeam & Value ) const
{
    if( m_ui8BeamDataLength  != Value.m_ui8BeamDataLength ) return false;
    if( m_ui8BeamIDNumber    != Value.m_ui8BeamIDNumber )   return false;
    if( m_UAFPD              != Value.m_UAFPD )             return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL UnderwaterAcousticEmitterBeam::operator != ( const UnderwaterAcousticEmitterBeam & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////



