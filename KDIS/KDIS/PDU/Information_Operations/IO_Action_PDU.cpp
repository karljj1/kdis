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

#include "./IO_Action_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

IO_Action_PDU::IO_Action_PDU( void ) :
    m_ui32ReqId( 0 ),
    m_ui16WrTyp( 0 ),
    m_ui16SimSrc( 0 ),
    m_ui16ActTyp( 0 ),
    m_ui16ActPhs( 0 ),
    m_ui32Padding( 0 ),
    m_ui16Padding( 0 ),
    m_ui16NumStdVarRec( 0 )
{
    m_ui8PDUType = IO_Action_PDU_Type;
    m_ui16PDULength = IO_ACTION_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IO_Action_PDU::IO_Action_PDU( const EntityIdentifier & OrigID, const EntityIdentifier & RecvID, KUINT32 ReqID,
                              WarfareType WT, KUINT16 SimSrc, ActionType AT, ActionPhase AP,
                              const EntityIdentifier & AtkID, const EntityIdentifier & TgtID ) :
    IO_Header( OrigID ),
    m_RecEntityID( RecvID ),
    m_ui32ReqId( ReqID ),
    m_ui16WrTyp( WT ),
    m_ui16SimSrc( SimSrc ),
    m_ui16ActTyp( AT ),
    m_ui16ActPhs( AP ),
    m_ui32Padding( 0 ),
    m_AtkEntityID( AtkID ),
    m_TgtEntityID( TgtID ),
    m_ui16Padding( 0 ),
    m_ui16NumStdVarRec( 0 )
{
    m_ui8PDUType = IO_Action_PDU_Type;
    m_ui16PDULength = IO_ACTION_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IO_Action_PDU::IO_Action_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

IO_Action_PDU::~IO_Action_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

void IO_Action_PDU::SetReceivingEntityID( const EntityIdentifier & ID )
{
    m_RecEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & IO_Action_PDU::GetReceivingEntityID() const
{
    return m_RecEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & IO_Action_PDU::GetReceivingEntityID()
{
    return m_RecEntityID;
}

//////////////////////////////////////////////////////////////////////////

void IO_Action_PDU::SetRequestID( KUINT32 ID )
{
    m_ui32ReqId = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 IO_Action_PDU::GetRequestID() const
{
    return m_ui32ReqId;
}

//////////////////////////////////////////////////////////////////////////

void IO_Action_PDU::SetWarfareType( WarfareType WT )
{
    m_ui16WrTyp = WT;
}

//////////////////////////////////////////////////////////////////////////

WarfareType IO_Action_PDU::GetWarfareType() const
{
    return ( WarfareType )m_ui16WrTyp;
}

//////////////////////////////////////////////////////////////////////////

void IO_Action_PDU::SetSimulationSource( KUINT16 SS )
{
    m_ui16SimSrc = SS;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 IO_Action_PDU::GetSimulationSource() const
{
    return m_ui16SimSrc;
}

//////////////////////////////////////////////////////////////////////////

void IO_Action_PDU::SetActionType( ActionType AT )
{
    m_ui16ActTyp = AT;
}

//////////////////////////////////////////////////////////////////////////

ActionType IO_Action_PDU::GetActionType() const
{
    return ( ActionType )m_ui16ActTyp;
}

//////////////////////////////////////////////////////////////////////////

void IO_Action_PDU::SetActionPhase( ActionPhase AP )
{
    m_ui16ActPhs = AP;
}

//////////////////////////////////////////////////////////////////////////

ActionPhase IO_Action_PDU::GetActionPhase() const
{
    return ( ActionPhase )m_ui16ActPhs;
}

//////////////////////////////////////////////////////////////////////////

void IO_Action_PDU::SetAttackerEntityID( const EntityIdentifier & ID )
{
    m_AtkEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & IO_Action_PDU::GetAttackerEntityID() const
{
    return m_AtkEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & IO_Action_PDU::GetAttackerEntityID()
{
    return m_AtkEntityID;
}

//////////////////////////////////////////////////////////////////////////

void IO_Action_PDU::SetPrimaryTargetEntityID( const EntityIdentifier & ID )
{
    m_TgtEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & IO_Action_PDU::GetPrimaryTargetEntityID() const
{
    return m_TgtEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & IO_Action_PDU::GetPrimaryTargetEntityID()
{
    return m_TgtEntityID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 IO_Action_PDU::GetNumberOfIORecords() const
{
    return m_ui16NumStdVarRec;
}

//////////////////////////////////////////////////////////////////////////

void IO_Action_PDU::AddStandardVariableRecord( StdVarPtr SVR )
{
    m_vStdVarRecs.push_back( SVR );
    ++m_ui16NumStdVarRec;
    m_ui16PDULength += SVR->GetRecordLength();
}

//////////////////////////////////////////////////////////////////////////

void IO_Action_PDU::SetStandardVariableRecords( const vector<StdVarPtr> & SVR )
{
    m_vStdVarRecs = SVR;

    // Reset the PDU length.
    m_ui16PDULength = IO_ACTION_PDU_SIZE;

    // Calculate the new pdu length.
    KUINT16 ui16Length = 0;
    vector<StdVarPtr>::const_iterator citr = m_vStdVarRecs.begin();
    vector<StdVarPtr>::const_iterator citrEnd = m_vStdVarRecs.end();
    for( ; citr != citrEnd; ++citr )
    {
        m_ui16PDULength += ( *citr )->GetRecordLength();
    }

    m_ui16NumStdVarRec = m_vStdVarRecs.size();
}

//////////////////////////////////////////////////////////////////////////

const vector<StdVarPtr> & IO_Action_PDU::GetStandardVariableRecords() const
{
    return m_vStdVarRecs;
}

//////////////////////////////////////////////////////////////////////////

void IO_Action_PDU::ClearStandardVariableRecords()
{
    // Reset the PDU length.
    m_ui16PDULength = IO_ACTION_PDU_SIZE;

    m_vStdVarRecs.clear();
    m_ui16NumStdVarRec = 0;
}

//////////////////////////////////////////////////////////////////////////

KString IO_Action_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-IO Action PDU-"
       << IO_Header::GetAsString()
       << "Receiving Entity ID:\n"
       << IndentString( m_RecEntityID.GetAsString(), 1 )
       << "Request ID:   "        << m_ui32ReqId
       << "Warfare Type: "        << GetEnumAsStringWarfareType( m_ui16WrTyp )
       << "\nSimulation Source: " << m_ui16SimSrc
       << "\nAction Type: "       << GetEnumAsStringActionType( m_ui16ActTyp )
       << "\nAction Phase: "      << GetEnumAsStringActionPhase( m_ui16ActPhs )
       << "\nAttacker ID:\n"
       << IndentString( m_AtkEntityID.GetAsString(), 1 )
       << "Primary Target ID:\n"
       << IndentString( m_TgtEntityID.GetAsString(), 1 )
       << "Number of standard variable records: " << m_ui16NumStdVarRec
       << "\nStandard Variables:\n";

    vector<StdVarPtr>::const_iterator citr = m_vStdVarRecs.begin();
    vector<StdVarPtr>::const_iterator citrEnd = m_vStdVarRecs.end();
    for( ; citr != citrEnd; ++citr )
    {
        ss << ( *citr )->GetAsString();
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void IO_Action_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < IO_ACTION_PDU_SIZE  )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vStdVarRecs.clear();

    IO_Header::Decode( stream );

    stream >> KDIS_STREAM m_RecEntityID
           >> m_ui32ReqId
           >> m_ui16WrTyp
           >> m_ui16SimSrc
           >> m_ui16ActTyp
           >> m_ui16ActPhs
           >> m_ui32Padding
           >> KDIS_STREAM m_AtkEntityID
           >> KDIS_STREAM m_TgtEntityID
           >> m_ui16Padding
           >> m_ui16NumStdVarRec;

    // Use the factory decode function for each standard variable
    for( KUINT16 i = 0; i < m_ui16NumStdVarRec; ++i )
    {
        m_vStdVarRecs.push_back( StandardVariable::FactoryDecodeStandardVariable( stream ) );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream IO_Action_PDU::Encode() const
{
    KDataStream stream;

    IO_Action_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void IO_Action_PDU::Encode( KDataStream & stream ) const
{
    IO_Header::Encode( stream );

    stream << KDIS_STREAM m_RecEntityID
           << m_ui32ReqId
           << m_ui16WrTyp
           << m_ui16SimSrc
           << m_ui16ActTyp
           << m_ui16ActPhs
           << m_ui32Padding
           << KDIS_STREAM m_AtkEntityID
           << KDIS_STREAM m_TgtEntityID
           << m_ui16Padding
           << m_ui16NumStdVarRec;

    vector<StdVarPtr>::const_iterator citr = m_vStdVarRecs.begin();
    vector<StdVarPtr>::const_iterator citrEnd = m_vStdVarRecs.end();
    for( ; citr != citrEnd; ++citr )
    {
        ( *citr )->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL IO_Action_PDU::operator == ( const IO_Action_PDU & Value ) const
{
    if( IO_Header::operator !=( Value ) )                 return false;
    if( m_RecEntityID       != Value.m_RecEntityID )      return false;
    if( m_ui32ReqId         != Value.m_ui32ReqId )        return false;
    if( m_ui16WrTyp         != Value.m_ui16WrTyp )        return false;
    if( m_ui16SimSrc        != Value.m_ui16SimSrc )       return false;
    if( m_ui16ActTyp        != Value.m_ui16ActTyp )       return false;
    if( m_ui16ActPhs        != Value.m_ui16ActPhs )       return false;
    if( m_AtkEntityID       != Value.m_AtkEntityID )      return false;
    if( m_TgtEntityID       != Value.m_TgtEntityID )      return false;
    if( m_ui16NumStdVarRec  != Value.m_ui16NumStdVarRec ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IO_Action_PDU::operator != ( const IO_Action_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


