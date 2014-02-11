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

#include "./Resupply_Cancel_PDU.h"

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

Resupply_Cancel_PDU::Resupply_Cancel_PDU()
{
    m_ui8PDUType = Resupply_Cancel_PDU_Type;
    m_ui16PDULength = RESUPPLY_CANCEL_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Resupply_Cancel_PDU::Resupply_Cancel_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Resupply_Cancel_PDU::Resupply_Cancel_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Logistics_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Resupply_Cancel_PDU::Resupply_Cancel_PDU( const EntityIdentifier & ReceivingEntity, const EntityIdentifier & SupplyingEntity )
{
    m_ui8PDUType = Resupply_Cancel_PDU_Type;
    m_ui16PDULength = RESUPPLY_CANCEL_PDU_SIZE;
    m_ReceivingEntity = ReceivingEntity;
    m_SupplyingEntity = SupplyingEntity;
}

//////////////////////////////////////////////////////////////////////////

Resupply_Cancel_PDU::~Resupply_Cancel_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

KString Resupply_Cancel_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Resupply Cancel-\n"
       << IndentString( Logistics_Header::GetAsString(), 1 );

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL Resupply_Cancel_PDU::operator == ( const Resupply_Cancel_PDU & Value ) const
{
    if( Logistics_Header::operator !=( Value ) ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Resupply_Cancel_PDU::operator != ( const Resupply_Cancel_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

