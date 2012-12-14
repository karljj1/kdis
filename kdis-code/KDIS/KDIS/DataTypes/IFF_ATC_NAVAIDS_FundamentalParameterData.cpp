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

#include "./IFF_ATC_NAVAIDS_FundamentalParameterData.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

IFF_ATC_NAVAIDS_FundamentalParameterData::IFF_ATC_NAVAIDS_FundamentalParameterData( void ) :
    m_f32ERP( 0 ),
    m_f32Freq( 0 ),
    m_f32PgRF( 0 ),
    m_f32PulseWidth( 0 ),
    m_ui32BurstLength( 0 ),
    m_ui8AppMode( 0 ),
    m_ui16Padding1( 0 ),
    m_ui8Padding2( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

IFF_ATC_NAVAIDS_FundamentalParameterData::IFF_ATC_NAVAIDS_FundamentalParameterData( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

IFF_ATC_NAVAIDS_FundamentalParameterData::IFF_ATC_NAVAIDS_FundamentalParameterData( KFLOAT32 ERP, KFLOAT32 Freq, KFLOAT32 PgRF, KFLOAT32 PulseWidth,
        KUINT32 BurstLength, SystemMode M ) :
    m_f32ERP( ERP ),
    m_f32Freq( Freq ),
    m_f32PgRF( PgRF ),
    m_f32PulseWidth( PulseWidth ),
    m_ui32BurstLength( BurstLength ),
    m_ui8AppMode( M ),
    m_ui16Padding1( 0 ),
    m_ui8Padding2( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

IFF_ATC_NAVAIDS_FundamentalParameterData::~IFF_ATC_NAVAIDS_FundamentalParameterData( void )
{
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_FundamentalParameterData::SetEffectiveRadiatedPower( KFLOAT32 ERP )
{
    m_f32ERP = ERP;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 IFF_ATC_NAVAIDS_FundamentalParameterData::GetEffectiveRadiatedPower() const
{
    return m_f32ERP;
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_FundamentalParameterData::SetFrequency( KFLOAT32 F )
{
    m_f32Freq = F;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 IFF_ATC_NAVAIDS_FundamentalParameterData::GetFrequency() const
{
    return m_f32Freq;
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_FundamentalParameterData::SetPgRF( KFLOAT32 P )
{
    m_f32PgRF = P;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 IFF_ATC_NAVAIDS_FundamentalParameterData::GetPgRF() const
{
    return m_f32PgRF;
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_FundamentalParameterData::SetPulseWidth( KFLOAT32 PW )
{
    m_f32PulseWidth = PW;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 IFF_ATC_NAVAIDS_FundamentalParameterData::GetPulseWidth() const
{
    return m_f32PulseWidth;
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_FundamentalParameterData::SetBurstLength( KUINT32 BL )
{
    m_ui32BurstLength = BL;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 IFF_ATC_NAVAIDS_FundamentalParameterData::GetBurstLength() const
{
    return m_ui32BurstLength;
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_FundamentalParameterData::SetApplicableModes( SystemMode M )
{
    m_ui8AppMode = M;
}

//////////////////////////////////////////////////////////////////////////

SystemMode IFF_ATC_NAVAIDS_FundamentalParameterData::GetApplicableModes() const
{
    return ( SystemMode )m_ui8AppMode;
}

//////////////////////////////////////////////////////////////////////////

KString IFF_ATC_NAVAIDS_FundamentalParameterData::GetAsString() const
{
    KStringStream ss;

    ss << "IFF/ATC/NAVAID Fundamental Parameter Data:"
       << "\n\tERP:              " << m_f32ERP
       << "\n\tFrequency:        " << m_f32Freq
       << "\n\tPgRF:             " << m_f32PgRF
       << "\n\tPulse Width:      " << m_f32PulseWidth
       << "\n\tBurst Length:     " << m_ui32BurstLength
       << "\n\tApplicable Modes: " << GetEnumAsStringSystemMode( m_ui8AppMode )
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_FundamentalParameterData::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < IFF_ATC_NAVAIDS_FUNDAMENTAL_PARAMETER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_f32ERP
           >> m_f32Freq
           >> m_f32PgRF
           >> m_f32PulseWidth
           >> m_ui32BurstLength
           >> m_ui8AppMode
           >> m_ui16Padding1
           >> m_ui8Padding2;
}

//////////////////////////////////////////////////////////////////////////

KDataStream IFF_ATC_NAVAIDS_FundamentalParameterData::Encode() const
{
    KDataStream stream;

    IFF_ATC_NAVAIDS_FundamentalParameterData::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_FundamentalParameterData::Encode( KDataStream & stream ) const
{
    stream << m_f32ERP
           << m_f32Freq
           << m_f32PgRF
           << m_f32PulseWidth
           << m_ui32BurstLength
           << m_ui8AppMode
           << m_ui16Padding1
           << m_ui8Padding2;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_ATC_NAVAIDS_FundamentalParameterData::operator == ( const IFF_ATC_NAVAIDS_FundamentalParameterData & Value ) const
{
    if( m_f32ERP           != Value.m_f32ERP )           return false;
    if( m_f32Freq          != Value.m_f32Freq )          return false;
    if( m_f32PgRF          != Value.m_f32PgRF )          return false;
    if( m_f32PulseWidth    != Value.m_f32PulseWidth )    return false;
    if( m_ui32BurstLength  != Value.m_ui32BurstLength )  return false;
    if( m_ui8AppMode       != Value.m_ui8AppMode )       return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_ATC_NAVAIDS_FundamentalParameterData::operator != ( const IFF_ATC_NAVAIDS_FundamentalParameterData & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
