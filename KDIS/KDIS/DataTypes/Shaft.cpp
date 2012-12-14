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

#include "./Shaft.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

Shaft::Shaft( void ) :
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

Shaft::~Shaft( void )
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
