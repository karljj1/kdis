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

#include "./Remove_Entity_R_PDU.h"

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

Remove_Entity_R_PDU::Remove_Entity_R_PDU()
{
    m_ui8PDUType = RemoveEntity_R_PDU_Type;
    m_ui16PDULength = REMOVE_ENTITY_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Remove_Entity_R_PDU::Remove_Entity_R_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Remove_Entity_R_PDU::Remove_Entity_R_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Create_Entity_R_PDU( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Remove_Entity_R_PDU::Remove_Entity_R_PDU( const EntityIdentifier & OrigintatingID, const EntityIdentifier & ReceivingID,
        KUINT32 RequestID, RequiredReliabilityService RRS ) :
    Create_Entity_R_PDU( OrigintatingID, ReceivingID, RequestID, RRS )
{
    m_ui8PDUType = RemoveEntity_R_PDU_Type;
    m_ui16PDULength = REMOVE_ENTITY_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Remove_Entity_R_PDU::Remove_Entity_R_PDU( const Simulation_Management_Header & SimMgrHeader, KUINT32 RequestID,
        RequiredReliabilityService RRS ) :
    Create_Entity_R_PDU( SimMgrHeader, RequestID, RRS )
{
    m_ui8PDUType = RemoveEntity_R_PDU_Type;
    m_ui16PDULength = REMOVE_ENTITY_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Remove_Entity_R_PDU::~Remove_Entity_R_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

KString Remove_Entity_R_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Remove Entity-R PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << Reliability_Header::GetAsString()
       << "Request ID: " << m_ui32RequestID
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL Remove_Entity_R_PDU::operator == ( const Remove_Entity_R_PDU & Value ) const
{
    if( Create_Entity_R_PDU::operator !=( Value ) ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Remove_Entity_R_PDU::operator != ( const Remove_Entity_R_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
