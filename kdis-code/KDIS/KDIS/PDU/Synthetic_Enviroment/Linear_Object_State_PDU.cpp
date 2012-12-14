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

#include "./Linear_Object_State_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace std;
using namespace UTILS;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Linear_Object_State_PDU::Linear_Object_State_PDU( void ) :
    m_ui8NumSegment( 0 )
{
    m_ui8PDUType = LinearObjectState_PDU_Type;
    m_ui16PDULength = LINEAR_OBJECT_STATE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Linear_Object_State_PDU::Linear_Object_State_PDU( KDataStream & stream ) throw( KException )
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

Linear_Object_State_PDU::Linear_Object_State_PDU( const EntityIdentifier & ObjID, const EntityIdentifier & RefObjID , KUINT16 UpdateNum,
        ForceID FI, const SimulationIdentifier & ReqID, const SimulationIdentifier & RecvID,
        const ObjectType & O ) :
    Object_State_Header( ObjID, RefObjID, UpdateNum, FI ),
    m_ReqID( ReqID ),
    m_RecvID( RecvID ),
    m_ObjTyp( O ),
    m_ui8NumSegment( 0 )
{
    m_ui8PDUType = LinearObjectState_PDU_Type;
    m_ui16PDULength = LINEAR_OBJECT_STATE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Linear_Object_State_PDU::Linear_Object_State_PDU( const EntityIdentifier & ObjID, const EntityIdentifier & RefObjID , KUINT16 UpdateNum,
        ForceID FI, const SimulationIdentifier & ReqID, const SimulationIdentifier & RecvID,
        const ObjectType & O, std::vector<LinearSegmentParameter> & Segments ) :
    Object_State_Header( ObjID, RefObjID, UpdateNum, FI ),
    m_ReqID( ReqID ),
    m_RecvID( RecvID ),
    m_ObjTyp( O ),
    m_ui8NumSegment( 0 )
{
    m_ui8PDUType = LinearObjectState_PDU_Type;
    m_ui16PDULength = LINEAR_OBJECT_STATE_PDU_SIZE;
    SetLinearSegmentParameters( Segments );
}

//////////////////////////////////////////////////////////////////////////

Linear_Object_State_PDU::~Linear_Object_State_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Linear_Object_State_PDU::GetNumberOfSegments() const
{
    return m_ui8NumSegment;
}

//////////////////////////////////////////////////////////////////////////

void Linear_Object_State_PDU::SetRequestorSimulationID( const SimulationIdentifier & ID )
{
    m_ReqID = ID;
}

//////////////////////////////////////////////////////////////////////////

const SimulationIdentifier & Linear_Object_State_PDU::GetRequestorSimulationID() const
{
    return m_ReqID;
}

//////////////////////////////////////////////////////////////////////////

SimulationIdentifier & Linear_Object_State_PDU::GetRequestorSimulationID()
{
    return m_ReqID;
}

//////////////////////////////////////////////////////////////////////////

void Linear_Object_State_PDU::SetReceivingSimulationID( const SimulationIdentifier & ID )
{
    m_RecvID = ID;
}

//////////////////////////////////////////////////////////////////////////

const SimulationIdentifier & Linear_Object_State_PDU::GetReceivingSimulationID() const
{
    return m_RecvID;
}

//////////////////////////////////////////////////////////////////////////

SimulationIdentifier & Linear_Object_State_PDU::GetReceivingSimulationID()
{
    return m_RecvID;
}

//////////////////////////////////////////////////////////////////////////

void Linear_Object_State_PDU::SetObjectType( const ObjectType & O )
{
    m_ObjTyp = O;
}

//////////////////////////////////////////////////////////////////////////

const ObjectType & Linear_Object_State_PDU::GetObjectType() const
{
    return m_ObjTyp;
}

//////////////////////////////////////////////////////////////////////////

ObjectType & Linear_Object_State_PDU::GetObjectType()
{
    return m_ObjTyp;
}

//////////////////////////////////////////////////////////////////////////

void Linear_Object_State_PDU::AddLinearSegmentParameter( const LinearSegmentParameter & L )
{
    m_ui16PDULength += LinearSegmentParameter::LINEAR_SEGMENT_PARAMETER_SIZE;
    m_vSegments.push_back( L );
    ++m_ui8NumSegment;
}

//////////////////////////////////////////////////////////////////////////

void Linear_Object_State_PDU::SetLinearSegmentParameters( const vector<LinearSegmentParameter> & L )
{
    m_ui8NumSegment = L.size();
    m_ui16PDULength = LINEAR_OBJECT_STATE_PDU_SIZE + ( LinearSegmentParameter::LINEAR_SEGMENT_PARAMETER_SIZE * m_ui8NumSegment );
    m_vSegments = L;
}

//////////////////////////////////////////////////////////////////////////

const vector<LinearSegmentParameter> & Linear_Object_State_PDU::GetLinearSegmentParameters() const
{
    return m_vSegments;
}

//////////////////////////////////////////////////////////////////////////

KString Linear_Object_State_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Linear Object State PDU-\n"
       << Object_State_Header::GetAsString()
       << "Number Of Segments: " << ( KUINT16 )m_ui8NumSegment
       << "Requestor ID:\n"  << IndentString( m_ReqID.GetAsString(), 1 )
       << "Receiving ID:\n"  << IndentString( m_RecvID.GetAsString(), 1 )
       << "Object Type:  "   << m_ObjTyp.GetAsString();

    vector<LinearSegmentParameter>::const_iterator citr = m_vSegments.begin();
    std::vector<LinearSegmentParameter>::const_iterator citrEnd = m_vSegments.end();
    for( ; citr != citrEnd; ++citr )
    {
        ss << citr->GetAsString();
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Linear_Object_State_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < LINEAR_OBJECT_STATE_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vSegments.clear();

    Object_State_Header::Decode( stream );

    stream >> m_ui8NumSegment
           >> KDIS_STREAM m_ReqID
           >> KDIS_STREAM m_RecvID
           >> KDIS_STREAM m_ObjTyp;

    for( KUINT8 i = 0; i < m_ui8NumSegment; ++i )
    {
        m_vSegments.push_back( LinearSegmentParameter( stream ) );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Linear_Object_State_PDU::Encode() const
{
    KDataStream stream;

    Linear_Object_State_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Linear_Object_State_PDU::Encode( KDataStream & stream ) const
{
    Object_State_Header::Encode( stream );

    stream << m_ui8NumSegment
           << KDIS_STREAM m_ReqID
           << KDIS_STREAM m_RecvID
           << KDIS_STREAM m_ObjTyp;

    vector<LinearSegmentParameter>::const_iterator citr = m_vSegments.begin();
    std::vector<LinearSegmentParameter>::const_iterator citrEnd = m_vSegments.end();
    for( ; citr != citrEnd; ++citr )
    {
        citr->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Linear_Object_State_PDU::operator == ( const Linear_Object_State_PDU & Value ) const
{
    if( Object_State_Header::operator  != ( Value ) )             return false;
    if( m_ui8NumSegment                != Value.m_ui8NumSegment ) return false;
    if( m_ReqID                        != Value.m_ReqID )         return false;
    if( m_RecvID                       != Value.m_RecvID )        return false;
    if( m_ObjTyp                       != Value.m_ObjTyp )        return false;
    if( m_vSegments                    != Value.m_vSegments )     return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Linear_Object_State_PDU::operator != ( const Linear_Object_State_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


