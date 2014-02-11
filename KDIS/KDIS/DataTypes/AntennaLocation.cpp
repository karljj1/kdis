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

#include "./AntennaLocation.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

AntennaLocation::AntennaLocation()
{
}

//////////////////////////////////////////////////////////////////////////

AntennaLocation::AntennaLocation( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

AntennaLocation::AntennaLocation( const WorldCoordinates & Location, const Vector & RelativeLocation ) :
    m_AntennaLocation( Location ),
    m_RelativeAntennaLocation( RelativeLocation )
{
}

//////////////////////////////////////////////////////////////////////////

AntennaLocation::~AntennaLocation()
{
}

//////////////////////////////////////////////////////////////////////////

void AntennaLocation::SetAntennaLocation( const WorldCoordinates & AL )
{
    m_AntennaLocation = AL;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & AntennaLocation::GetAntennaLocation() const
{
    return m_AntennaLocation;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & AntennaLocation::GetAntennaLocation()
{
    return m_AntennaLocation;
}

//////////////////////////////////////////////////////////////////////////

void AntennaLocation::SetRelativeAntennaLocation( const Vector & RAL )
{
    m_RelativeAntennaLocation = RAL;
}

//////////////////////////////////////////////////////////////////////////

const Vector & AntennaLocation::GetRelativeAntennaLocation() const
{
    return m_RelativeAntennaLocation;
}

//////////////////////////////////////////////////////////////////////////

Vector & AntennaLocation::GetRelativeAntennaLocation()
{
    return m_RelativeAntennaLocation;
}

//////////////////////////////////////////////////////////////////////////

KString AntennaLocation::GetAsString() const
{
    KStringStream ss;

    ss << "Antenna Location:\n"
       << "\tWorld Location:       " << m_AntennaLocation.GetAsString()
       << "\tEntity Location:      " << m_RelativeAntennaLocation.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void AntennaLocation::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ANTENNA_LOCATION_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> KDIS_STREAM m_AntennaLocation
           >> KDIS_STREAM m_RelativeAntennaLocation;
}

//////////////////////////////////////////////////////////////////////////

KDataStream AntennaLocation::Encode() const
{
    KDataStream stream;

    AntennaLocation::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void AntennaLocation::Encode( KDataStream & stream ) const
{
    stream << KDIS_STREAM m_AntennaLocation
           << KDIS_STREAM m_RelativeAntennaLocation;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AntennaLocation::operator == ( const AntennaLocation & Value ) const
{
    if( m_AntennaLocation           != Value.m_AntennaLocation )         return false;
    if( m_RelativeAntennaLocation   != Value.m_RelativeAntennaLocation ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AntennaLocation::operator != ( const AntennaLocation & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

