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

#include "./Resupply_Offer_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Resupply_Offer_PDU::Resupply_Offer_PDU( void )
{
    m_ui8PDUType = Resupply_Offer_PDU_Type;
    m_ui16PDULength = RESUPPLY_OFFER_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Resupply_Offer_PDU::Resupply_Offer_PDU( const EntityIdentifier & ReceivingEntity, const EntityIdentifier & SupplyingEntity ) :
    Resupply_Received_PDU( ReceivingEntity, SupplyingEntity )
{
    m_ui8PDUType = Resupply_Offer_PDU_Type;
    m_ui16PDULength = RESUPPLY_OFFER_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Resupply_Offer_PDU::Resupply_Offer_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Resupply_Offer_PDU::~Resupply_Offer_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

KString Resupply_Offer_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Resupply Offer-\n"
       << IndentString( Logistics_Header::GetAsString(), 1 )
       << "\tNumber Of Supply Types: " << (KUINT16)m_ui8NumSupplyTypes;

    // Now add supplies
    vector<Supplies>::const_iterator citr = m_vSupplies.begin();
    vector<Supplies>::const_iterator citrEnd = m_vSupplies.end();

    // Add supplies to the stream
    for( ; citr != citrEnd; ++citr )
    {
        ss << IndentString( citr->GetAsString(), 1 )
           << "\tQuantity :	" << citr->GetQuantity();
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL Resupply_Offer_PDU::operator == ( const Resupply_Offer_PDU & Value ) const
{
    if( Resupply_Received_PDU::operator !=( Value ) ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Resupply_Offer_PDU::operator != ( const Resupply_Offer_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

