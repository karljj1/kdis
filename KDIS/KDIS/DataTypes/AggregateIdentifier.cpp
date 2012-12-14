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

#include "./AggregateIdentifier.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

AggregateIdentifier::AggregateIdentifier( void ) :
    m_ui16AggregateID( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

AggregateIdentifier::AggregateIdentifier( KUINT16 SiteID, KUINT16 ApplicatonID, KUINT16 AggregateID ) :
    SimulationIdentifier( SiteID, ApplicatonID ),
    m_ui16AggregateID( AggregateID )
{
}

//////////////////////////////////////////////////////////////////////////

AggregateIdentifier::AggregateIdentifier( const SimulationIdentifier & SimID, KUINT16 AggregateID ) :
    SimulationIdentifier( SimID ),
    m_ui16AggregateID( AggregateID )
{
}

//////////////////////////////////////////////////////////////////////////

AggregateIdentifier::AggregateIdentifier( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

AggregateIdentifier::~AggregateIdentifier( void )
{
}

//////////////////////////////////////////////////////////////////////////

void AggregateIdentifier::SetAggregateID( KUINT16 ID )
{
    m_ui16AggregateID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 AggregateIdentifier::GetAggregateID() const
{
    return m_ui16AggregateID;
}

//////////////////////////////////////////////////////////////////////////

KString AggregateIdentifier::GetAsString() const
{
    KStringStream ss;

    ss << SimulationIdentifier::GetAsString()
       << "Aggregate:   " << m_ui16AggregateID      << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void AggregateIdentifier::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < AGGREGATE_IDENTIFER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    SimulationIdentifier::Decode( stream );
    stream >> m_ui16AggregateID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream AggregateIdentifier::Encode() const
{
    KDataStream stream;

    AggregateIdentifier::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void AggregateIdentifier::Encode( KDataStream & stream ) const
{
    SimulationIdentifier::Encode( stream );
    stream << m_ui16AggregateID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AggregateIdentifier::operator == ( const AggregateIdentifier & Value ) const
{
    if( SimulationIdentifier::operator !=( Value ) )   return false;
    if( m_ui16AggregateID != Value.m_ui16AggregateID ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AggregateIdentifier::operator != ( const AggregateIdentifier & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

KBOOL AggregateIdentifier::operator < ( const AggregateIdentifier & Value ) const
{
    // We will bit shift all 3 fields into a single KUINT64, this will generate a new unique value which we can then use for comparison.
    // bits 0-15  = SiteID
    // bits 16-31 = ApplicationID
    // bits 32-47 = AggregateID
    // bits 48-63 = 0
    KUINT64 ui64ThisCmpVal = 0, ui64OtherCmpVal = 0;

    ui64ThisCmpVal = m_ui16SiteID | ( KUINT64 )m_ui16ApplicationID << 16 | ( KUINT64 )m_ui16AggregateID << 32;
    ui64OtherCmpVal = Value.m_ui16SiteID | ( KUINT64 )Value.m_ui16ApplicationID << 16 | ( KUINT64 )Value.m_ui16AggregateID << 32;

    return ui64ThisCmpVal < ui64OtherCmpVal;
}

//////////////////////////////////////////////////////////////////////////
