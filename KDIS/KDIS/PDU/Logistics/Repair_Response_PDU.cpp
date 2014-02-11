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

Repair_Response_PDU::Repair_Response_PDU() :
    m_ui8Padding( 0 ),
    m_ui16Padding( 0 )
{
    m_ui8PDUType = Repair_Response_PDU_Type;
    m_ui16PDULength = REPAIR_RESPONSE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Repair_Response_PDU::Repair_Response_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Repair_Response_PDU::Repair_Response_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Logistics_Header( H )
{
    Decode( stream, true );
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

Repair_Response_PDU::~Repair_Response_PDU()
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

void Repair_Response_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < REPAIR_RESPONSE_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Logistics_Header::Decode( stream, ignoreHeader );	
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


