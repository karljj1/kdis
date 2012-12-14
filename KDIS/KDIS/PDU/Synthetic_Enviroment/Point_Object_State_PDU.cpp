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

#include "./Point_Object_State_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Point_Object_State_PDU::Point_Object_State_PDU( void ) :
    m_ui16Padding( 0 ),
    m_ui32Padding1( 0 )
{
    m_ModificationUnion.m_ui8Modifications = 0;
    m_ui8PDUType = PointObjectState_PDU_Type;
    m_ui16PDULength = POINT_OBJECT_STATE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Point_Object_State_PDU::Point_Object_State_PDU( KDataStream & stream ) throw( KException )
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

Point_Object_State_PDU::Point_Object_State_PDU( const EntityIdentifier & ObjID, const EntityIdentifier & RefObjID , KUINT16 UpdateNum,
        ForceID FI, const ObjectType & O, const WorldCoordinates & Loc, const EulerAngles & Ori,
        const PointObjectAppearance & P, const SimulationIdentifier & ReqID,
        const SimulationIdentifier & RecvID ) :
    Object_State_Header( ObjID, RefObjID, UpdateNum, FI ),
    m_ObjTyp( O ),
    m_Loc( Loc ),
    m_Ori( Ori ),
    m_Apperance( P ),
    m_ui16Padding( 0 ),
    m_ui32Padding1( 0 ),
    m_ReqID( ReqID ),
    m_RecvID( RecvID )
{
    m_ModificationUnion.m_ui8Modifications = 0;
    m_ui8PDUType = PointObjectState_PDU_Type;
    m_ui16PDULength = POINT_OBJECT_STATE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Point_Object_State_PDU::~Point_Object_State_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Point_Object_State_PDU::SetModification( KUINT8 M )
{
    m_ModificationUnion.m_ui8Modifications = M;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Point_Object_State_PDU::GetModification() const
{
    return m_ModificationUnion.m_ui8Modifications;
}

//////////////////////////////////////////////////////////////////////////

void Point_Object_State_PDU::SetModificationLocation( KBOOL M /*= true*/ )
{
    m_ModificationUnion.m_ui8LocBit = M;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Point_Object_State_PDU::IsModificationLocation() const
{
    return m_ModificationUnion.m_ui8LocBit;
}

//////////////////////////////////////////////////////////////////////////

void Point_Object_State_PDU::SetModificationOrientation( KBOOL M /*= true*/ )
{
    m_ModificationUnion.m_ui8OriBit = M;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Point_Object_State_PDU::IsModificationOrientation() const
{
    return m_ModificationUnion.m_ui8OriBit;
}

//////////////////////////////////////////////////////////////////////////

void Point_Object_State_PDU::SetObjectType( const ObjectType & O )
{
    m_ObjTyp = O;
}

//////////////////////////////////////////////////////////////////////////

const ObjectType & Point_Object_State_PDU::GetObjectType() const
{
    return m_ObjTyp;
}

//////////////////////////////////////////////////////////////////////////

ObjectType & Point_Object_State_PDU::GetObjectType()
{
    return m_ObjTyp;
}

//////////////////////////////////////////////////////////////////////////

void Point_Object_State_PDU::SetLocation( const WorldCoordinates & L )
{
    m_Loc = L;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & Point_Object_State_PDU::GetLocation() const
{
    return m_Loc;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & Point_Object_State_PDU::GetLocation()
{
    return m_Loc;
}

//////////////////////////////////////////////////////////////////////////

void Point_Object_State_PDU::SetOrientation( const EulerAngles & O )
{
    m_Ori = O;
}

//////////////////////////////////////////////////////////////////////////

const EulerAngles & Point_Object_State_PDU::GetOrientation() const
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles & Point_Object_State_PDU::GetOrientation()
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

void Point_Object_State_PDU::SetRequestorSimulationID( const SimulationIdentifier & ID )
{
    m_ReqID = ID;
}

//////////////////////////////////////////////////////////////////////////

const SimulationIdentifier & Point_Object_State_PDU::GetRequestorSimulationID() const
{
    return m_ReqID;
}

//////////////////////////////////////////////////////////////////////////

SimulationIdentifier & Point_Object_State_PDU::GetRequestorSimulationID()
{
    return m_ReqID;
}

//////////////////////////////////////////////////////////////////////////

void Point_Object_State_PDU::SetReceivingSimulationID( const SimulationIdentifier & ID )
{
    m_RecvID = ID;
}

//////////////////////////////////////////////////////////////////////////

const SimulationIdentifier & Point_Object_State_PDU::GetReceivingSimulationID() const
{
    return m_RecvID;
}

//////////////////////////////////////////////////////////////////////////

SimulationIdentifier & Point_Object_State_PDU::GetReceivingSimulationID()
{
    return m_RecvID;
}

//////////////////////////////////////////////////////////////////////////

void Point_Object_State_PDU::SetObjectAppearance( const PointObjectAppearance & A )
{
    m_Apperance = A;
}

//////////////////////////////////////////////////////////////////////////

const PointObjectAppearance & Point_Object_State_PDU::GetObjectAppearance() const
{
    return m_Apperance;
}

//////////////////////////////////////////////////////////////////////////

PointObjectAppearance & Point_Object_State_PDU::GetObjectAppearance()
{
    return m_Apperance;
}

//////////////////////////////////////////////////////////////////////////

KString Point_Object_State_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Point Object State PDU-\n"
       << Object_State_Header::GetAsString()
       << "Modification:\n"
       << "\tLocation:     " << ( KUINT16 )m_ModificationUnion.m_ui8LocBit << "\n"
       << "\tOrientation:  " << ( KUINT16 )m_ModificationUnion.m_ui8OriBit << "\n"
       << "Object Type:  "   << m_ObjTyp.GetAsString()
       << "Location:     "   << m_Loc.GetAsString()
       << "Orientation:  "   << m_Ori.GetAsString()
       << "Requestor ID:\n"  << IndentString( m_ReqID.GetAsString(), 1 )
       << m_Apperance.GetAsString()
       << "Receiving ID:\n"  << IndentString( m_RecvID.GetAsString(), 1 );

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Point_Object_State_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < POINT_OBJECT_STATE_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Object_State_Header::Decode( stream );

    stream >> m_ModificationUnion.m_ui8Modifications
           >> KDIS_STREAM m_ObjTyp
           >> KDIS_STREAM m_Loc
           >> KDIS_STREAM m_Ori
           >> KDIS_STREAM m_Apperance
           >> m_ui16Padding
           >> KDIS_STREAM m_ReqID
           >> KDIS_STREAM m_RecvID
           >> m_ui32Padding1;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Point_Object_State_PDU::Encode() const
{
    KDataStream stream;

    Point_Object_State_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Point_Object_State_PDU::Encode( KDataStream & stream ) const
{
    Object_State_Header::Encode( stream );

    stream << m_ModificationUnion.m_ui8Modifications
           << KDIS_STREAM m_ObjTyp
           << KDIS_STREAM m_Loc
           << KDIS_STREAM m_Ori
           << KDIS_STREAM m_Apperance
           << m_ui16Padding
           << KDIS_STREAM m_ReqID
           << KDIS_STREAM m_RecvID
           << m_ui32Padding1;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Point_Object_State_PDU::operator == ( const Point_Object_State_PDU & Value ) const
{
    if( Object_State_Header::operator  != ( Value ) )     return false;
    if( m_ModificationUnion.m_ui8Modifications != Value.m_ModificationUnion.m_ui8Modifications ) return false;
    if( m_ObjTyp            != Value.m_ObjTyp )           return false;
    if( m_Loc               != Value.m_Loc )              return false;
    if( m_Ori               != Value.m_Ori )              return false;
    if( m_Apperance         != Value.m_Apperance )        return false;
    if( m_ReqID             != Value.m_ReqID )            return false;
    if( m_RecvID            != Value.m_RecvID )           return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Point_Object_State_PDU::operator != ( const Point_Object_State_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


