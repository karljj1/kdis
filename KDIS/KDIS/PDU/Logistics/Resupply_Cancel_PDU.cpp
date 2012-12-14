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

Resupply_Cancel_PDU::Resupply_Cancel_PDU( void )
{
    m_ui8PDUType = Resupply_Cancel_PDU_Type;
    m_ui16PDULength = RESUPPLY_CANCEL_PDU_SIZE;
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

Resupply_Cancel_PDU::Resupply_Cancel_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Resupply_Cancel_PDU::~Resupply_Cancel_PDU( void )
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

