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

#include "./Repair_Response_PDU.h"

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

Repair_Response_PDU::Repair_Response_PDU( void ) :
    m_ui8Padding( 0 ),
    m_ui16Padding( 0 )
{
    m_ui8PDUType = Repair_Response_PDU_Type;
    m_ui16PDULength = REPAIR_RESPONSE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Repair_Response_PDU::Repair_Response_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Repair_Response_PDU::Repair_Response_PDU( const EntityIdentifier & ReceivingEntityID, const EntityIdentifier & SupplyingEntityID,
        RepairResult RR ) :
    Logistics_Header( ReceivingEntityID, SupplyingEntityID ),
    m_ui8Padding( 0 ),
    m_ui16Padding( 0 ),
    m_ui8RepairResult( RR )
{
    m_ui8PDUType = Repair_Response_PDU_Type;
    m_ui16PDULength = REPAIR_RESPONSE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Repair_Response_PDU::~Repair_Response_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Repair_Response_PDU::SetRepairResult( RepairResult RR )
{
    m_ui8RepairResult = RR;
}

//////////////////////////////////////////////////////////////////////////

RepairResult Repair_Response_PDU::GetRepairResult() const
{
    return ( RepairResult )m_ui8RepairResult;
}

//////////////////////////////////////////////////////////////////////////

KString Repair_Response_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Repair Response PDU-\n"
       << IndentString( Logistics_Header::GetAsString(), 1 )
       << "\tRepair Result:         " << GetEnumAsStringRepairResult( m_ui8RepairResult )
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Repair_Response_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < REPAIR_RESPONSE_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Logistics_Header::Decode( stream );
    stream >> m_ui8RepairResult
           >> m_ui8Padding
           >> m_ui16Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Repair_Response_PDU::Encode() const
{
    KDataStream stream;

    Repair_Response_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Repair_Response_PDU::Encode( KDataStream & stream ) const
{
    Logistics_Header::Encode( stream );
    stream << m_ui8RepairResult
           << m_ui8Padding
           << m_ui16Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Repair_Response_PDU::operator == ( const Repair_Response_PDU & Value ) const
{
    if( Logistics_Header::operator  !=( Value ) )                 return false;
    if( m_ui8RepairResult           != Value.m_ui8RepairResult )  return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Repair_Response_PDU::operator != ( const Repair_Response_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


