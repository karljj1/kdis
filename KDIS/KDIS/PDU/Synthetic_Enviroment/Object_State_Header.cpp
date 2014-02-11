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

#include "./Object_State_Header.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Object_State_Header::Object_State_Header() :
    m_ui16UpdateNum( 0 ),
    m_ui8ForceID( 0 )
{
    m_ui8ProtocolFamily = SyntheticEnvironment;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Object_State_Header::Object_State_Header( const Header & H ) :
	Header( H ),
	m_ui16UpdateNum( 0 ),
    m_ui8ForceID( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

Object_State_Header::Object_State_Header( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Object_State_Header::Object_State_Header( const Header & H, KDataStream & stream ) throw( KException ) :
	Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Object_State_Header::Object_State_Header( const EntityIdentifier & ObjID, const EntityIdentifier & RefObjID ,
        KUINT16 UpdateNum, ForceID FI ) :
    m_ObjID( ObjID ),
    m_RefObjID( RefObjID ),
    m_ui16UpdateNum( UpdateNum ),
    m_ui8ForceID( FI )
{
    m_ui8ProtocolFamily = SyntheticEnvironment;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Object_State_Header::~Object_State_Header()
{
}

//////////////////////////////////////////////////////////////////////////

void Object_State_Header::SetObjectID( const EntityIdentifier & ID )
{
    m_ObjID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Object_State_Header::GetObjectID() const
{
    return m_ObjID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Object_State_Header::GetObjectID()
{
    return m_ObjID;
}

//////////////////////////////////////////////////////////////////////////

void Object_State_Header::SetReferencedObjectID( const EntityIdentifier & ID )
{
    m_RefObjID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Object_State_Header::GetReferencedObjectID() const
{
    return m_RefObjID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Object_State_Header::GetReferencedObjectID()
{
    return m_RefObjID;
}

//////////////////////////////////////////////////////////////////////////

void Object_State_Header::SetUpdateNumber( KUINT16 U )
{
    m_ui16UpdateNum = U;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Object_State_Header::GetUpdateNumber() const
{
    return m_ui16UpdateNum;
}

//////////////////////////////////////////////////////////////////////////

void Object_State_Header::SetForceID( ForceID ID )
{
    m_ui8ForceID = ID;
}

//////////////////////////////////////////////////////////////////////////

ForceID Object_State_Header::GetForceID() const
{
    return ( ForceID )m_ui8ForceID;
}

//////////////////////////////////////////////////////////////////////////

KString Object_State_Header::GetAsString() const
{
    KStringStream ss;

    // We will let the derived pdu get the header string so they can insert their
    // name between the header values and these.
    ss << "Object ID:\n"
       << m_ObjID.GetAsString()
       << "Referenced Object ID:\n"
       << m_RefObjID.GetAsString()
       << "Update Number: " << m_ui16UpdateNum                        << "\n"
       << "Force ID:      " << GetEnumAsStringForceID( m_ui8ForceID ) << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Object_State_Header::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < OBJECT_STATE_HEADER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_ObjID
           >> KDIS_STREAM m_RefObjID
           >> m_ui16UpdateNum
           >> m_ui8ForceID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Object_State_Header::Encode() const
{
    KDataStream stream;

    Object_State_Header::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Object_State_Header::Encode( KDataStream & stream ) const
{
    Header::Encode( stream );

    stream << KDIS_STREAM m_ObjID
           << KDIS_STREAM m_RefObjID
           << m_ui16UpdateNum
           << m_ui8ForceID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Object_State_Header::operator == ( const Object_State_Header & Value ) const
{
    if( Header::operator != ( Value ) )             return false;
    if( m_ObjID          != Value.m_ObjID )         return false;
    if( m_RefObjID       != Value.m_RefObjID )      return false;
    if( m_ui16UpdateNum  != Value.m_ui16UpdateNum ) return false;
    if( m_ui8ForceID     != Value.m_ui8ForceID )    return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Object_State_Header::operator != ( const Object_State_Header & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


