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

#include "./Create_Entity_PDU.h"

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

Create_Entity_PDU::Create_Entity_PDU()
{
    m_ui8PDUType = Create_Entity_PDU_Type;
    m_ui16PDULength = CREATE_ENTITY_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Create_Entity_PDU::Create_Entity_PDU( const Header & H ) :
	Simulation_Management_Header( H )
{
}

//////////////////////////////////////////////////////////////////////////

Create_Entity_PDU::Create_Entity_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Create_Entity_PDU::Create_Entity_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Simulation_Management_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Create_Entity_PDU::Create_Entity_PDU( const EntityIdentifier & OrigintatingID, const EntityIdentifier & ReceivingID, KUINT32 RequestID ) :
    Simulation_Management_Header( OrigintatingID, ReceivingID ),
    m_ui32RequestID( RequestID )
{
    m_ui8PDUType = Create_Entity_PDU_Type;
    m_ui16PDULength = CREATE_ENTITY_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Create_Entity_PDU::Create_Entity_PDU( const Simulation_Management_Header & SimMgrHeader, KUINT32 RequestID ) :
    Simulation_Management_Header( SimMgrHeader ),
    m_ui32RequestID( RequestID )
{
    m_ui8PDUType = Create_Entity_PDU_Type;
    m_ui16PDULength = CREATE_ENTITY_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Create_Entity_PDU::~Create_Entity_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void Create_Entity_PDU::SetRequestID( KUINT32 ID )
{
    m_ui32RequestID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Create_Entity_PDU::GetRequestID() const
{
    return m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KString Create_Entity_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Create Entity PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << "Request ID: " << m_ui32RequestID
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Create_Entity_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < CREATE_ENTITY_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Simulation_Management_Header::Decode( stream, ignoreHeader );	

    stream >> m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Create_Entity_PDU::Encode() const
{
    KDataStream stream;

    Create_Entity_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Create_Entity_PDU::Encode( KDataStream & stream ) const
{
    Simulation_Management_Header::Encode( stream );
    stream << m_ui32RequestID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Create_Entity_PDU::operator == ( const Create_Entity_PDU & Value ) const
{
    if( Simulation_Management_Header::operator  !=( Value ) )              return false;
    if( m_ui32RequestID                         != Value.m_ui32RequestID ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Create_Entity_PDU::operator != ( const Create_Entity_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

