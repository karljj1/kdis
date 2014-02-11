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

Resupply_Offer_PDU::Resupply_Offer_PDU()
{
    m_ui8PDUType = Resupply_Offer_PDU_Type;
    m_ui16PDULength = RESUPPLY_OFFER_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Resupply_Offer_PDU::Resupply_Offer_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Resupply_Offer_PDU::Resupply_Offer_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Resupply_Received_PDU( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Resupply_Offer_PDU::Resupply_Offer_PDU( const EntityIdentifier & ReceivingEntity, const EntityIdentifier & SupplyingEntity ) :
    Resupply_Received_PDU( ReceivingEntity, SupplyingEntity )
{
    m_ui8PDUType = Resupply_Offer_PDU_Type;
    m_ui16PDULength = RESUPPLY_OFFER_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Resupply_Offer_PDU::~Resupply_Offer_PDU()
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

