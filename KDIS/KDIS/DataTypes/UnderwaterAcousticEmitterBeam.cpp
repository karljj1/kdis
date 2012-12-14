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

#include "./UnderwaterAcousticEmitterBeam.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

UnderwaterAcousticEmitterBeam::UnderwaterAcousticEmitterBeam( void )  :
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

UnderwaterAcousticEmitterBeam::~UnderwaterAcousticEmitterBeam( void )
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



