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

Linear_Object_State_PDU::Linear_Object_State_PDU() :
    m_ui8NumSegment( 0 )
{
    m_ui8PDUType = LinearObjectState_PDU_Type;
    m_ui16PDULength = LINEAR_OBJECT_STATE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Linear_Object_State_PDU::Linear_Object_State_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Linear_Object_State_PDU::Linear_Object_State_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Object_State_Header( H )
{
    Decode( stream, true );
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

Linear_Object_State_PDU::~Linear_Object_State_PDU()
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

void Linear_Object_State_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < LINEAR_OBJECT_STATE_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vSegments.clear();

    Object_State_Header::Decode( stream, ignoreHeader );	

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


