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

#include "./PointObjectAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

PointObjectAppearance::PointObjectAppearance()
{
    m_SpecificAppearanceUnion.m_ui32SpecificAppearance = 0;
}

//////////////////////////////////////////////////////////////////////////

PointObjectAppearance::PointObjectAppearance( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

PointObjectAppearance::~PointObjectAppearance()
{
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetBreach( Breach2bit B )
{
    m_SpecificAppearanceUnion.m_LogCribAbatisVehicleDefiladeInf.m_ui32Breach = B;
}

//////////////////////////////////////////////////////////////////////////

Breach2bit PointObjectAppearance::GetBreach() const
{
    return ( Breach2bit )m_SpecificAppearanceUnion.m_LogCribAbatisVehicleDefiladeInf.m_ui32Breach;
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetOpacity( KUINT8 O ) throw( KException )
{
    if( O > 100 ) throw KException( __FUNCTION__, INVALID_DATA, "Acceptable values are 0-100." );

    m_SpecificAppearanceUnion.m_AirBurstGroundBurst.m_ui32Opacity = O;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 PointObjectAppearance::GetOpacity() const
{
    return m_SpecificAppearanceUnion.m_AirBurstGroundBurst.m_ui32Opacity;
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetBurstSize( KUINT8 S )
{
    m_SpecificAppearanceUnion.m_AirBurstGroundBurst.m_ui32Size = S;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 PointObjectAppearance::GetBurstSize() const
{
    return m_SpecificAppearanceUnion.m_AirBurstGroundBurst.m_ui32Size;
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetHeight( KUINT8 H )
{
    m_SpecificAppearanceUnion.m_AirBurstGroundBurst.m_ui32Height = H;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 PointObjectAppearance::GetHeight() const
{
    return m_SpecificAppearanceUnion.m_AirBurstGroundBurst.m_ui32Height;
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetNumBursts( KUINT8 N )
{
	m_SpecificAppearanceUnion.m_AirBurstGroundBurst.m_ui32NumBurst = N;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 PointObjectAppearance::GetNumBursts() const
{
    return m_SpecificAppearanceUnion.m_AirBurstGroundBurst.m_ui32NumBurst;
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetChemical( Chemical C )
{
    m_SpecificAppearanceUnion.m_AirBurstGroundBurst.m_ui32Chemical = C;
}

//////////////////////////////////////////////////////////////////////////

Chemical PointObjectAppearance::GetChemical() const
{
    return ( Chemical )m_SpecificAppearanceUnion.m_AirBurstGroundBurst.m_ui32Chemical;
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetCraterSize( KUINT8 S )
{
    m_SpecificAppearanceUnion.m_Crater.m_ui32Size = S;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 PointObjectAppearance::GetCraterSize() const
{
    return m_SpecificAppearanceUnion.m_Crater.m_ui32Size;
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::SetNumSegments( KUINT8 N )
{
    m_SpecificAppearanceUnion.m_RibbonBridge.m_ui32NumSeg = N;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 PointObjectAppearance::GetNumSegments() const
{
    return m_SpecificAppearanceUnion.m_RibbonBridge.m_ui32NumSeg;
}

//////////////////////////////////////////////////////////////////////////

KString PointObjectAppearance::GetAsString() const
{
    KStringStream ss;

    ss << ObjectAppearance::GetAsString()
       << "\tSpecific Appearance: " << m_SpecificAppearanceUnion.m_ui32SpecificAppearance << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < POINT_OBJECT_APPEARANCE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_SpecificAppearanceUnion.m_ui32SpecificAppearance
           >> m_GeneralAppearanceUnion.m_ui16GeneralAppearance;
}

//////////////////////////////////////////////////////////////////////////

KDataStream PointObjectAppearance::Encode() const
{
    KDataStream stream;

    PointObjectAppearance::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void PointObjectAppearance::Encode( KDataStream & stream ) const
{
    // First add the specific bytes and then the general.
    stream << m_SpecificAppearanceUnion.m_ui32SpecificAppearance
           << m_GeneralAppearanceUnion.m_ui16GeneralAppearance;
}

//////////////////////////////////////////////////////////////////////////

KBOOL PointObjectAppearance::operator == ( const PointObjectAppearance & Value ) const
{
    if( ObjectAppearance::operator  != ( Value ) ) return false;
    if( m_SpecificAppearanceUnion.m_ui32SpecificAppearance != Value.m_SpecificAppearanceUnion.m_ui32SpecificAppearance ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL PointObjectAppearance::operator != ( const PointObjectAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
