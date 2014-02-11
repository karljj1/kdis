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

#include "./Areal_Object_State_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace std;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Areal_Object_State_PDU::Areal_Object_State_PDU() :
    m_ui16NumPoints( 0 )
{
    m_ui8PDUType = ArealObjectState_PDU_Type;
    m_ui16PDULength = AREAL_OBJECT_STATE_PDU_SIZE;
    m_ModificationUnion.m_ui8Modifications = 0;
}

//////////////////////////////////////////////////////////////////////////

Areal_Object_State_PDU::Areal_Object_State_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Areal_Object_State_PDU::Areal_Object_State_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Object_State_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Areal_Object_State_PDU::Areal_Object_State_PDU( KUINT8 Modification, const ObjectType & T, const ArealObjectAppearance & A,
        const SimulationIdentifier & RequestorID, const SimulationIdentifier & ReceivingID ) :
    m_ObjTyp( T ),
    m_Apperance( A ),
    m_ui16NumPoints( 0 ),
    m_ReqID( RequestorID ),
    m_RecvID(ReceivingID )
{
    m_ui8PDUType = ArealObjectState_PDU_Type;
    m_ui16PDULength = AREAL_OBJECT_STATE_PDU_SIZE;
    m_ModificationUnion.m_ui8Modifications = Modification;
}

//////////////////////////////////////////////////////////////////////////

Areal_Object_State_PDU::Areal_Object_State_PDU( KUINT8 Modification, const ObjectType & T, const ArealObjectAppearance & A,
        const SimulationIdentifier & RequestorID, const SimulationIdentifier & ReceivingID,
        const std::vector<WorldCoordinates> & Points ) :
    m_ObjTyp( T ),
    m_Apperance( A ),
    m_ui16NumPoints( 0 ),
    m_ReqID( RequestorID ),
    m_RecvID(ReceivingID )
{
    m_ui8PDUType = ArealObjectState_PDU_Type;
    m_ui16PDULength = AREAL_OBJECT_STATE_PDU_SIZE;
    m_ModificationUnion.m_ui8Modifications = Modification;

    SetPoints( Points );
}

//////////////////////////////////////////////////////////////////////////

Areal_Object_State_PDU::~Areal_Object_State_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void Areal_Object_State_PDU::SetModification( KUINT8 M )
{
    m_ModificationUnion.m_ui8Modifications = M;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Areal_Object_State_PDU::GetModification() const
{
    return m_ModificationUnion.m_ui8Modifications;
}

//////////////////////////////////////////////////////////////////////////

void Areal_Object_State_PDU::SetModificationLocation( KBOOL M /*= true*/ )
{
    m_ModificationUnion.m_ui8LocBit = M;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Areal_Object_State_PDU::IsModificationLocation() const
{
    return m_ModificationUnion.m_ui8LocBit;
}

//////////////////////////////////////////////////////////////////////////

void Areal_Object_State_PDU::SetObjectType( const ObjectType & O )
{
    m_ObjTyp = O;
}

//////////////////////////////////////////////////////////////////////////

const ObjectType & Areal_Object_State_PDU::GetObjectType() const
{
    return m_ObjTyp;
}

//////////////////////////////////////////////////////////////////////////

ObjectType & Areal_Object_State_PDU::GetObjectType()
{
    return m_ObjTyp;
}

//////////////////////////////////////////////////////////////////////////

void Areal_Object_State_PDU::SetObjectAppearance( const ArealObjectAppearance & A )
{
    m_Apperance = A;
}

//////////////////////////////////////////////////////////////////////////

const ArealObjectAppearance & Areal_Object_State_PDU::GetObjectAppearance() const
{
    return m_Apperance;
}

//////////////////////////////////////////////////////////////////////////

ArealObjectAppearance & Areal_Object_State_PDU::GetObjectAppearance()
{
    return m_Apperance;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Areal_Object_State_PDU::GetNumberOfPoints() const
{
    return m_ui16NumPoints;
}

//////////////////////////////////////////////////////////////////////////

void Areal_Object_State_PDU::SetRequestorSimulationID( const SimulationIdentifier & ID )
{
    m_ReqID = ID;
}

//////////////////////////////////////////////////////////////////////////

const SimulationIdentifier & Areal_Object_State_PDU::GetRequestorSimulationID() const
{
    return m_ReqID;
}

//////////////////////////////////////////////////////////////////////////

SimulationIdentifier & Areal_Object_State_PDU::GetRequestorSimulationID()
{
    return m_ReqID;
}

//////////////////////////////////////////////////////////////////////////

void Areal_Object_State_PDU::SetReceivingSimulationID( const SimulationIdentifier & ID )
{
    m_RecvID = ID;
}

//////////////////////////////////////////////////////////////////////////

const SimulationIdentifier & Areal_Object_State_PDU::GetReceivingSimulationID() const
{
    return m_RecvID;
}

//////////////////////////////////////////////////////////////////////////

SimulationIdentifier & Areal_Object_State_PDU::GetReceivingSimulationID()
{
    return m_RecvID;
}

//////////////////////////////////////////////////////////////////////////

void Areal_Object_State_PDU::AddPoint( const WorldCoordinates & P )
{
    m_ui16PDULength += WorldCoordinates::WORLD_COORDINATES_SIZE;
    m_vPoints.push_back( P );
    ++m_ui16NumPoints;
}

//////////////////////////////////////////////////////////////////////////

void Areal_Object_State_PDU::SetPoints( const vector<WorldCoordinates> & P )
{
    m_ui16NumPoints = P.size();
    m_ui16PDULength = ArealObjectAppearance::AREAL_OBJECT_APPEARANCE_SIZE + ( WorldCoordinates::WORLD_COORDINATES_SIZE * m_ui16NumPoints );
    m_vPoints = P;
}

//////////////////////////////////////////////////////////////////////////

const vector<WorldCoordinates> & Areal_Object_State_PDU::GetPoints() const
{
    return m_vPoints;
}

//////////////////////////////////////////////////////////////////////////

KString Areal_Object_State_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Areal Object State PDU-\n"
       << Object_State_Header::GetAsString()
       << "Modification:\n"
       << "\tLocation: " << ( KUINT16 )m_ModificationUnion.m_ui8LocBit << "\n"
       << "Object Type: " << m_ObjTyp.GetAsString()
       << m_Apperance.GetAsString()
       << "Number Of Points: " << m_ui16NumPoints << "\n"
       << "Requestor ID:\n" << IndentString( m_ReqID.GetAsString(), 1 )
       << "Receiving ID:\n" << IndentString( m_RecvID.GetAsString(), 1 );

    vector<WorldCoordinates>::const_iterator citr = m_vPoints.begin();
    vector<WorldCoordinates>::const_iterator citrEnd = m_vPoints.end();
    for( ; citr != citrEnd; ++citr )
    {
        ss << "Point Location: " << citr->GetAsString();
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Areal_Object_State_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < AREAL_OBJECT_STATE_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vPoints.clear();

    Object_State_Header::Decode( stream, ignoreHeader );	

    stream >> m_ModificationUnion.m_ui8Modifications
           >> KDIS_STREAM m_ObjTyp
           >> KDIS_STREAM m_Apperance
           >> m_ui16NumPoints
           >> KDIS_STREAM m_ReqID
           >> KDIS_STREAM m_RecvID;

    for( KUINT16 i = 0; i < m_ui16NumPoints; ++i )
    {
        m_vPoints.push_back( WorldCoordinates( stream ) );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Areal_Object_State_PDU::Encode() const
{
    KDataStream stream;

    Areal_Object_State_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Areal_Object_State_PDU::Encode( KDataStream & stream ) const
{
    Object_State_Header::Encode( stream );

    stream << m_ModificationUnion.m_ui8Modifications
           << KDIS_STREAM m_ObjTyp
           << KDIS_STREAM m_Apperance
           << m_ui16NumPoints
           << KDIS_STREAM m_ReqID
           << KDIS_STREAM m_RecvID;

    vector<WorldCoordinates>::const_iterator citr = m_vPoints.begin();
    vector<WorldCoordinates>::const_iterator citrEnd = m_vPoints.end();
    for( ; citr != citrEnd; ++citr )
    {
        citr->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Areal_Object_State_PDU::operator == ( const Areal_Object_State_PDU & Value ) const
{
    if( Object_State_Header::operator          != ( Value ) )             return false;
    if( m_ModificationUnion.m_ui8Modifications != Value.m_ModificationUnion.m_ui8Modifications ) return false;
    if( m_ObjTyp                               != Value.m_ObjTyp )        return false;
    if( m_Apperance                            != Value.m_Apperance )     return false;
    if( m_ui16NumPoints                        != Value.m_ui16NumPoints ) return false;
    if( m_ReqID                                != Value.m_ReqID )         return false;
    if( m_RecvID                               != Value.m_RecvID )        return false;
    if( m_vPoints                              != Value.m_vPoints )       return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Areal_Object_State_PDU::operator != ( const Areal_Object_State_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


