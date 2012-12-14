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

#include "./AntennaLocation.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

AntennaLocation::AntennaLocation( void )
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

AntennaLocation::~AntennaLocation( void )
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

