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

#include "./UnderwaterAcousticFundamentalParameterData.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

UnderwaterAcousticFundamentalParameterData::UnderwaterAcousticFundamentalParameterData( void ) :
    m_ui16AEPI( 0 ),
    m_ui16ScanPattern( 0 ),
    m_f32BeamCenterAzimuth( 0 ),
    m_f32AzimuthalBeamWidth( 0 ),
    m_f32BeamCenterDE( 0 ),
    m_f32DEBeamwidth( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

UnderwaterAcousticFundamentalParameterData::UnderwaterAcousticFundamentalParameterData( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

UnderwaterAcousticFundamentalParameterData::UnderwaterAcousticFundamentalParameterData( ActiveEmissionParameterIndex AEPI, ScanPattern SP, KFLOAT32 BeamCenterAzimuth,
        KFLOAT32 AzimuthalBeamwidth, KFLOAT32 BeamCenter, KFLOAT32 BeamWidth ) :
    m_ui16AEPI( AEPI ),
    m_ui16ScanPattern( SP ),
    m_f32BeamCenterAzimuth( BeamCenterAzimuth ),
    m_f32AzimuthalBeamWidth( AzimuthalBeamwidth ),
    m_f32BeamCenterDE( BeamCenter ),
    m_f32DEBeamwidth( BeamWidth )
{
}

//////////////////////////////////////////////////////////////////////////

UnderwaterAcousticFundamentalParameterData::~UnderwaterAcousticFundamentalParameterData( void )
{
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticFundamentalParameterData::SetActiveEmissionParameterIndex( ActiveEmissionParameterIndex AEPI )
{
    m_ui16AEPI = AEPI;
}

//////////////////////////////////////////////////////////////////////////

ActiveEmissionParameterIndex UnderwaterAcousticFundamentalParameterData::GetActiveEmissionParameterIndex() const
{
    return ( ActiveEmissionParameterIndex )m_ui16AEPI;
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticFundamentalParameterData::SetScanPattern( ScanPattern SP )
{
    m_ui16ScanPattern = SP;
}

//////////////////////////////////////////////////////////////////////////

ScanPattern UnderwaterAcousticFundamentalParameterData::GetScanPattern() const
{
    return ( ScanPattern )m_ui16ScanPattern;
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticFundamentalParameterData::SetBeamCenterAzimuth( KFLOAT32 BCA )
{
    m_f32BeamCenterAzimuth = BCA;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 UnderwaterAcousticFundamentalParameterData::GetBeamCenterAzimuth() const
{
    return m_f32BeamCenterAzimuth;
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticFundamentalParameterData::SetAzimuthalBeamwidth( KFLOAT32 AB )
{
    m_f32AzimuthalBeamWidth = AB;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 UnderwaterAcousticFundamentalParameterData::GetAzimuthalBeamWidth() const
{
    return m_f32AzimuthalBeamWidth;
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticFundamentalParameterData::SetBeamCenter( KFLOAT32 BC )
{
    m_f32BeamCenterDE = BC;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 UnderwaterAcousticFundamentalParameterData::GetBeamCenter() const
{
    return m_f32BeamCenterDE;
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticFundamentalParameterData::SetBeamWidth( KFLOAT32 BW )
{
    m_f32DEBeamwidth = BW;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 UnderwaterAcousticFundamentalParameterData::GetBeamWidth() const
{
    return m_f32DEBeamwidth;
}

//////////////////////////////////////////////////////////////////////////

KString UnderwaterAcousticFundamentalParameterData::GetAsString() const
{
    KStringStream ss;

    ss << "Underwater Acoustic Fundamental Parameter Data:"
       << "\n\tAEPI:				" << GetEnumAsStringActiveEmissionParameterIndex( m_ui16AEPI )
       << "\n\tScan Pattern:		" << GetEnumAsStringScanPattern( m_ui16ScanPattern )
       << "\n\tBeam Center Azimuth: " << m_f32BeamCenterAzimuth
       << "\n\tAzimuthal Beamwidth: " << m_f32AzimuthalBeamWidth
       << "\n\tBeam Center D/E:     " << m_f32BeamCenterDE
       << "\n\tD/E Beamwidth:       " << m_f32DEBeamwidth
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticFundamentalParameterData::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < UNDERWATER_ACOUSTIC_FUNDAMENTAL_PARAMETER_SIZE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16AEPI
           >> m_ui16ScanPattern
           >> m_f32BeamCenterAzimuth
           >> m_f32AzimuthalBeamWidth
           >> m_f32BeamCenterDE
           >> m_f32DEBeamwidth;
}

//////////////////////////////////////////////////////////////////////////

KDataStream UnderwaterAcousticFundamentalParameterData::Encode() const
{
    KDataStream stream;

    UnderwaterAcousticFundamentalParameterData::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void UnderwaterAcousticFundamentalParameterData::Encode( KDataStream & stream ) const
{
    stream << m_ui16AEPI
           << m_ui16ScanPattern
           << m_f32BeamCenterAzimuth
           << m_f32AzimuthalBeamWidth
           << m_f32BeamCenterDE
           << m_f32DEBeamwidth;
}

//////////////////////////////////////////////////////////////////////////

KBOOL UnderwaterAcousticFundamentalParameterData::operator == ( const UnderwaterAcousticFundamentalParameterData & Value ) const
{
    if( m_ui16AEPI                != Value.m_ui16AEPI )              return false;
    if( m_ui16ScanPattern         != Value.m_ui16ScanPattern )       return false;
    if( m_f32BeamCenterAzimuth    != Value.m_f32BeamCenterAzimuth )  return false;
    if( m_f32AzimuthalBeamWidth   != Value.m_f32AzimuthalBeamWidth ) return false;
    if( m_f32BeamCenterDE         != Value.m_f32BeamCenterDE )       return false;
    if( m_f32DEBeamwidth          != Value.m_f32DEBeamwidth )        return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL UnderwaterAcousticFundamentalParameterData::operator != ( const UnderwaterAcousticFundamentalParameterData & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
