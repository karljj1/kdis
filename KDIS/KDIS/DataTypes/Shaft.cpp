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

#include "./Shaft.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

Shaft::Shaft() :
    m_i16CurrentRPM( 0 ),
    m_i16OrderedRPM( 0 ),
    m_i32RPMRateOfChange( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Shaft::Shaft( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Shaft::Shaft( KINT16 CurrentRPM, KINT16 OrderedRPM, KINT32 RateOfChange ) :
    m_i16CurrentRPM( CurrentRPM ),
    m_i16OrderedRPM( OrderedRPM ),
    m_i32RPMRateOfChange( RateOfChange )
{
}

//////////////////////////////////////////////////////////////////////////

Shaft::~Shaft()
{
}

//////////////////////////////////////////////////////////////////////////

void Shaft::SetCurrentRPM( KINT16 RPM )
{
    m_i16CurrentRPM = RPM;
}

//////////////////////////////////////////////////////////////////////////

KINT16 Shaft::GetCurrentRPM() const
{
    return m_i16CurrentRPM;
}

//////////////////////////////////////////////////////////////////////////

void Shaft::SetOrderedRPM( KINT16 RPM )
{
    m_i16OrderedRPM = RPM;
}

//////////////////////////////////////////////////////////////////////////

KINT16 Shaft::GetOrderedRPM() const
{
    return m_i16OrderedRPM;
}

//////////////////////////////////////////////////////////////////////////

void Shaft::SetRateOfChange( KINT32 ROC )
{
    m_i32RPMRateOfChange = ROC;
}

//////////////////////////////////////////////////////////////////////////

KINT32 Shaft::GetRateOfChange() const
{
    return m_i32RPMRateOfChange;
}

//////////////////////////////////////////////////////////////////////////

KString Shaft::GetAsString() const
{
    KStringStream ss;

    ss << "Shaft:"
       << "\n\tCurrent RPM:    " << m_i16CurrentRPM
       << "\n\tOrdered RPM:    " << m_i16OrderedRPM
       << "\n\tRate Of Change: " << m_i32RPMRateOfChange
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Shaft::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < SHAFT_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_i16CurrentRPM
           >> m_i16OrderedRPM
           >> m_i32RPMRateOfChange;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Shaft::Encode() const
{
    KDataStream stream;

    Shaft::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Shaft::Encode( KDataStream & stream ) const
{
    stream << m_i16CurrentRPM
           << m_i16OrderedRPM
           << m_i32RPMRateOfChange;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Shaft::operator == ( const Shaft & Value ) const
{
    if( m_i16CurrentRPM      != Value.m_i16CurrentRPM )       return false;
    if( m_i16OrderedRPM      != Value.m_i16OrderedRPM )       return false;
    if( m_i32RPMRateOfChange != Value.m_i32RPMRateOfChange )  return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Shaft::operator != ( const Shaft & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
