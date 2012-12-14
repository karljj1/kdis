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

#include "./Remove_Entity_PDU.h"

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

Remove_Entity_PDU::Remove_Entity_PDU( void )
{
    m_ui8PDUType = Remove_Entity_PDU_Type;
    m_ui16PDULength = REMOVE_ENTITY_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Remove_Entity_PDU::Remove_Entity_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Remove_Entity_PDU::Remove_Entity_PDU( const EntityIdentifier & OrigintatingID, const EntityIdentifier & ReceivingID, KUINT32 RequestID ) :
    Create_Entity_PDU( OrigintatingID, ReceivingID, RequestID )
{
    m_ui8PDUType = Remove_Entity_PDU_Type;
    m_ui16PDULength = REMOVE_ENTITY_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Remove_Entity_PDU::Remove_Entity_PDU( const Simulation_Management_Header & SimMgrHeader, KUINT32 RequestID ) :
    Create_Entity_PDU( SimMgrHeader, RequestID )
{
    m_ui8PDUType = Remove_Entity_PDU_Type;
    m_ui16PDULength = REMOVE_ENTITY_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Remove_Entity_PDU::~Remove_Entity_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

KString Remove_Entity_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Remove Entity PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << "Request ID: " << m_ui32RequestID
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL Remove_Entity_PDU::operator == ( const Remove_Entity_PDU & Value ) const
{
    if( Create_Entity_PDU::operator !=( Value ) ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Remove_Entity_PDU::operator != ( const Remove_Entity_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
