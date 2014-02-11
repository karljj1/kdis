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

#include "./ModulationType.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

ModulationType::ModulationType() :
    m_ui16SpreadSpectrum( 0 ),
    m_ui16Detail( 0 ),
    m_ui16MajorModulationType( 0 ),
    m_ui16System( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

ModulationType::ModulationType( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

ModulationType::ModulationType( KBOOL FreqHop, KBOOL PseudoNoise, KBOOL TimeHop,
                                KUINT16 MajorModulation, KUINT16 Detail,
                                KUINT16 System ) :
    m_ui16FreqHop( FreqHop ),
    m_ui16PseudoNoise( PseudoNoise ),
    m_ui16TimeHop( TimeHop ),
    m_ui16MajorModulationType( MajorModulation ),
    m_ui16Detail( Detail ),
    m_ui16System( System )
{
}

//////////////////////////////////////////////////////////////////////////

ModulationType::~ModulationType()
{
}

//////////////////////////////////////////////////////////////////////////

void ModulationType::SetSpreadSpectrum( KUINT16 SS )
{
    m_ui16SpreadSpectrum = SS;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 ModulationType::GetSpreadSpectrum() const
{
    return m_ui16SpreadSpectrum;
}

//////////////////////////////////////////////////////////////////////////

void ModulationType::SetFrequencyHop( KBOOL FH )
{
    m_ui16FreqHop = FH;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModulationType::GetFrequencyHop() const
{
    return m_ui16FreqHop;
}

//////////////////////////////////////////////////////////////////////////

void ModulationType::SetPseudoNoise( KBOOL PN )
{
    m_ui16PseudoNoise = PN;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModulationType::GetPseudoNoise() const
{
    return m_ui16PseudoNoise;
}

//////////////////////////////////////////////////////////////////////////

void ModulationType::SetTimeHop( KBOOL TH )
{
    m_ui16TimeHop = TH;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModulationType::GetTimeHop() const
{
    return m_ui16TimeHop;
}

//////////////////////////////////////////////////////////////////////////

RadioMajorModulation ModulationType::GetMajorModulation() const
{
    return ( RadioMajorModulation )m_ui16MajorModulationType;
}

//////////////////////////////////////////////////////////////////////////

void ModulationType::SetDetail( DetailAmplitude A )
{
    m_ui16MajorModulationType = Amplitude;
    m_ui16Detail = A;
}

//////////////////////////////////////////////////////////////////////////

void ModulationType::SetDetail( DetailAmplitudeAndAngle AA )
{
    m_ui16MajorModulationType = AmplitudeAndAngle;
    m_ui16Detail = AA;
}

//////////////////////////////////////////////////////////////////////////

void ModulationType::SetDetail( DetailAngle A )
{
    m_ui16MajorModulationType = Angle;
    m_ui16Detail = A;
}

//////////////////////////////////////////////////////////////////////////

void ModulationType::SetDetail( DetailCombination C )
{
    m_ui16MajorModulationType = Combination;
    m_ui16Detail = C;
}

//////////////////////////////////////////////////////////////////////////

void ModulationType::SetDetail( DetailPulse P )
{
    m_ui16MajorModulationType = Pulse;
    m_ui16Detail = P;
}

//////////////////////////////////////////////////////////////////////////

void ModulationType::SetDetail( DetailUnmodulated U )
{
    m_ui16MajorModulationType = Unmodulated;
    m_ui16Detail = U;
}

//////////////////////////////////////////////////////////////////////////

void ModulationType::SetDetail( DetailCarrierPhaseShift CPS )
{
    m_ui16MajorModulationType = CarrierPhaseShiftModulation_CPSM;
    m_ui16Detail = CPS;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 ModulationType::GetDetail() const
{
    return m_ui16Detail;
}

//////////////////////////////////////////////////////////////////////////

void ModulationType::SetSystem( ModulationSystem S )
{
    m_ui16System = S;
}

//////////////////////////////////////////////////////////////////////////

ModulationSystem ModulationType::GetSystem() const
{
    return ( ModulationSystem )m_ui16System;
}

//////////////////////////////////////////////////////////////////////////

KString ModulationType::GetAsString() const
{
    KStringStream ss;

    ss << "Modulation:\n"
       << "\tSpread Spectrum:"
       << "\n\t\tFrequency Hop:    "     << m_ui16FreqHop
       << "\n\t\tPsudo Noise:      "     << m_ui16PseudoNoise
       << "\n\t\tTime Hop:         "     << m_ui16TimeHop
       << "\n\tMajor Modulation Type:  " << GetEnumAsStringRadioMajorModulation( m_ui16MajorModulationType )
       << "\n\tDetail:                 ";

    switch( m_ui16MajorModulationType )
    {
    case Amplitude:
        ss << GetEnumAsStringDetailAmplitude( m_ui16Detail );
        break;

    case AmplitudeAndAngle:
        ss << GetEnumAsStringDetailAmplitudeAndAngle( m_ui16Detail );
        break;

    case Angle:
        ss << GetEnumAsStringDetailAngle( m_ui16Detail );
        break;

    case Combination:
        ss << GetEnumAsStringDetailCombination( m_ui16Detail );
        break;

    case Pulse:
        ss << GetEnumAsStringDetailPulse( m_ui16Detail );
        break;

    case Unmodulated:
        ss << GetEnumAsStringDetailUnmodulated( m_ui16Detail );
        break;

    case CarrierPhaseShiftModulation_CPSM:
        ss << GetEnumAsStringDetailCarrierPhaseShift( m_ui16Detail );
        break;

    default:
        ss << m_ui16Detail;
        break;
    }

    ss << "\n\tSystem:                 " << GetEnumAsStringModulationSystem( m_ui16System )
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ModulationType::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MODULATION_TYPE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16SpreadSpectrum
           >> m_ui16MajorModulationType
           >> m_ui16Detail
           >> m_ui16System;
}

//////////////////////////////////////////////////////////////////////////

KDataStream ModulationType::Encode() const
{
    KDataStream stream;

    ModulationType::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ModulationType::Encode( KDataStream & stream ) const
{
    stream << m_ui16SpreadSpectrum
           << m_ui16MajorModulationType
           << m_ui16Detail
           << m_ui16System;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModulationType::operator == ( const ModulationType & Value ) const
{
    if( m_ui16SpreadSpectrum       != Value.m_ui16SpreadSpectrum )      return false;
    if( m_ui16MajorModulationType  != Value.m_ui16MajorModulationType ) return false;
    if( m_ui16Detail               != Value.m_ui16Detail )              return false;
    if( m_ui16System               != Value.m_ui16System )              return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModulationType::operator != ( const ModulationType & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

