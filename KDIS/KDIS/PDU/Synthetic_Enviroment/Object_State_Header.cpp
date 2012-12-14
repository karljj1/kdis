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

Object_State_Header::Object_State_Header( void ) :
    m_ui16UpdateNum( 0 ),
    m_ui8ForceID( 0 )
{
    m_ui8ProtocolFamily = SyntheticEnvironment;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Object_State_Header::Object_State_Header( KDataStream & stream ) throw( KException )
{
    try
    {
        Decode( stream );
    }
    catch ( KException & e )
    {
        throw e;
    }
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

Object_State_Header::~Object_State_Header( void )
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

void Object_State_Header::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < OBJECT_STATE_HEADER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Header::Decode( stream );

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


