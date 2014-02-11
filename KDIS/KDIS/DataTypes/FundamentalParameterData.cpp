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

#include "./FundamentalParameterData.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

FundamentalParameterData::FundamentalParameterData() :
    m_f32Freq( 0 ),
    m_f32FreqRange( 0 ),
    m_f32EffectiveRadiatedPower( 0 ),
    m_f32PulseRepetitionFreq( 0 ),
    m_f32PulseWidth( 0 ),
    m_f32BeamAzimuthCenter( 0 ),
    m_f32BeamAzimuthSweep( 0 ),
    m_f32BeamElevationCenter( 0 ),
    m_f32BeamElevationSweep( 0 ),
    m_f32BeamSweepSync( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

FundamentalParameterData::FundamentalParameterData( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

FundamentalParameterData::FundamentalParameterData( KFLOAT32 Freq, KFLOAT32 FreqRange, KFLOAT32 EffectiveRadiatedPower,
        KFLOAT32 PulseRepetitionFreq, KFLOAT32 PulseWidth, KFLOAT32 BeamAzimuthCenter,
        KFLOAT32 BeamAzimuthSweep, KFLOAT32 BeamElevationCenter, KFLOAT32 BeamElevationSweep,
        KFLOAT32 BeamSweepSync ) :
    m_f32Freq( Freq ),
    m_f32FreqRange( FreqRange ),
    m_f32EffectiveRadiatedPower( EffectiveRadiatedPower ),
    m_f32PulseRepetitionFreq( PulseRepetitionFreq ),
    m_f32PulseWidth( PulseWidth ),
    m_f32BeamAzimuthCenter( BeamAzimuthCenter ),
    m_f32BeamAzimuthSweep( BeamAzimuthSweep ),
    m_f32BeamElevationCenter( BeamElevationCenter ),
    m_f32BeamElevationSweep( BeamElevationSweep ),
    m_f32BeamSweepSync( BeamSweepSync )
{
}

//////////////////////////////////////////////////////////////////////////

FundamentalParameterData::~FundamentalParameterData()
{
}

//////////////////////////////////////////////////////////////////////////

void FundamentalParameterData::SetFrequency( KFLOAT32 F )
{
    m_f32Freq = F;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 FundamentalParameterData::GetFrequency() const
{
    return m_f32Freq;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalParameterData::SetFrequencyRange( KFLOAT32 FR )
{
    m_f32FreqRange = FR;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 FundamentalParameterData::GetFrequencyRange() const
{
    return m_f32FreqRange;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalParameterData::SetEffectiveRadiatedPower( KFLOAT32 ERP )
{
    m_f32EffectiveRadiatedPower = ERP;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 FundamentalParameterData::GetEffectiveRadiatedPower() const
{
    return m_f32EffectiveRadiatedPower;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalParameterData::SetPulseRepetitionFrequency( KFLOAT32 PRF )
{
    m_f32PulseRepetitionFreq = PRF;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 FundamentalParameterData::GetPulseRepetitionFrequency() const
{
    return m_f32PulseRepetitionFreq;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalParameterData::SetPulseWidth( KFLOAT32 PW )
{
    m_f32PulseWidth = PW;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 FundamentalParameterData::GetPulseWidth() const
{
    return m_f32PulseWidth;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalParameterData::SetBeamAzimuthCenter( KFLOAT32 BAC )
{
    m_f32BeamAzimuthCenter = BAC;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 FundamentalParameterData::GetBeamAzimuthCenter() const
{
    return m_f32BeamAzimuthCenter;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalParameterData::SetBeamAzimuthSweep( KFLOAT32 BAS )
{
    m_f32BeamAzimuthSweep = BAS;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 FundamentalParameterData::GetBeamAzimuthSweep() const
{
    return m_f32BeamAzimuthSweep;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalParameterData::SetBeamElevationCenter( KFLOAT32 BEC )
{
    m_f32BeamElevationCenter = BEC;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 FundamentalParameterData::GetBeamElevationCenter() const
{
    return m_f32BeamElevationCenter;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalParameterData::SetBeamElevationSweep( KFLOAT32 BES )
{
    m_f32BeamElevationSweep = BES;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 FundamentalParameterData::GetBeamElevationSweep() const
{
    return m_f32BeamElevationSweep;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalParameterData::SetBeamSweepSync( KFLOAT32 BSS )
{
    m_f32BeamSweepSync = BSS;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 FundamentalParameterData::GetBeamSweepSync() const
{
    return m_f32BeamSweepSync;
}

//////////////////////////////////////////////////////////////////////////

KString FundamentalParameterData::GetAsString() const
{
    KStringStream ss;

    ss << "Fundamental Parameter Data:"
       << "\n\tFrequency:                  " << m_f32Freq
       << "\n\tFrequency Range:            " << m_f32FreqRange
       << "\n\tEffective Radiated Power:   " << m_f32EffectiveRadiatedPower
       << "\n\tPulse Repetition Frequency: " << m_f32PulseRepetitionFreq
       << "\n\tPulse Width:                " << m_f32PulseWidth
       << "\n\tBeam Azimuth Center:        " << m_f32BeamAzimuthCenter
       << "\n\tBeam Azimuth Sweep:         " << m_f32BeamAzimuthSweep
       << "\n\tBeam Elevation Center:      " << m_f32BeamElevationCenter
       << "\n\tBeam Elevation Sweep:       " << m_f32BeamElevationSweep
       << "\n\tBeam Sweep Sync:            " << m_f32BeamSweepSync
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void FundamentalParameterData::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < FUNDAMENTAL_PARAMETER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_f32Freq
           >> m_f32FreqRange
           >> m_f32EffectiveRadiatedPower
           >> m_f32PulseRepetitionFreq
           >> m_f32PulseWidth
           >> m_f32BeamAzimuthCenter
           >> m_f32BeamAzimuthSweep
           >> m_f32BeamElevationCenter
           >> m_f32BeamElevationSweep
           >> m_f32BeamSweepSync;
}

//////////////////////////////////////////////////////////////////////////

KDataStream FundamentalParameterData::Encode() const
{
    KDataStream stream;

    FundamentalParameterData::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void FundamentalParameterData::Encode( KDataStream & stream ) const
{
    stream << m_f32Freq
           << m_f32FreqRange
           << m_f32EffectiveRadiatedPower
           << m_f32PulseRepetitionFreq
           << m_f32PulseWidth
           << m_f32BeamAzimuthCenter
           << m_f32BeamAzimuthSweep
           << m_f32BeamElevationCenter
           << m_f32BeamElevationSweep
           << m_f32BeamSweepSync;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalParameterData::operator == ( const FundamentalParameterData & Value ) const
{
    if( m_f32Freq                   != Value.m_f32Freq )                    return false;
    if( m_f32FreqRange              != Value.m_f32FreqRange )               return false;
    if( m_f32EffectiveRadiatedPower != Value.m_f32EffectiveRadiatedPower )  return false;
    if( m_f32PulseRepetitionFreq    != Value.m_f32PulseRepetitionFreq )     return false;
    if( m_f32PulseWidth             != Value.m_f32PulseWidth )              return false;
    if( m_f32BeamAzimuthCenter      != Value.m_f32BeamAzimuthCenter )       return false;
    if( m_f32BeamAzimuthSweep       != Value.m_f32BeamAzimuthSweep )        return false;
    if( m_f32BeamElevationCenter    != Value.m_f32BeamElevationCenter )     return false;
    if( m_f32BeamElevationSweep     != Value.m_f32BeamElevationSweep )      return false;
    if( m_f32BeamSweepSync          != Value.m_f32BeamSweepSync )           return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL FundamentalParameterData::operator != ( const FundamentalParameterData & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
