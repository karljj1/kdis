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

#include "./IO_Report_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

IO_Report_PDU::IO_Report_PDU( void ) :
    m_ui16SimSrc( 0 ),
    m_ui8RptTyp( 0 ),
    m_ui32Padding( 0 ),
    m_ui16NumStdVarRec( 0 )
{
    m_ui8PDUType = IO_Report_PDU_Type;
    m_ui16PDULength = IO_REPORT_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IO_Report_PDU::IO_Report_PDU( const EntityIdentifier & OrigID, KUINT16 SimSrc, IOReportType RT,
                              const EntityIdentifier & AtkID, const EntityIdentifier & TgtID ) :
    IO_Header( OrigID ),
    m_ui16SimSrc( SimSrc ),
    m_ui8RptTyp( RT ),
    m_ui32Padding( 0 ),
    m_AtkEntityID( AtkID ),
    m_TgtEntityID( TgtID ),
    m_ui16NumStdVarRec( 0 )
{
    m_ui8PDUType = IO_Report_PDU_Type;
    m_ui16PDULength = IO_REPORT_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IO_Report_PDU::IO_Report_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

IO_Report_PDU::~IO_Report_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

void IO_Report_PDU::SetSimulationSource( KUINT16 SS )
{
    m_ui16SimSrc = SS;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 IO_Report_PDU::GetSimulationSource() const
{
    return m_ui16SimSrc;
}

//////////////////////////////////////////////////////////////////////////

void IO_Report_PDU::SetReportType( IOReportType RT )
{
    m_ui8RptTyp = RT;
}

//////////////////////////////////////////////////////////////////////////

IOReportType IO_Report_PDU::GetReportType() const
{
    return ( IOReportType )m_ui8RptTyp;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & IO_Report_PDU::GetAttackerEntityID()
{
    return m_AtkEntityID;
}

//////////////////////////////////////////////////////////////////////////

void IO_Report_PDU::SetPrimaryTargetEntityID( const EntityIdentifier & ID )
{
    m_TgtEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & IO_Report_PDU::GetPrimaryTargetEntityID() const
{
    return m_TgtEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & IO_Report_PDU::GetPrimaryTargetEntityID()
{
    return m_TgtEntityID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 IO_Report_PDU::GetNumberOfIORecords() const
{
    return m_ui16NumStdVarRec;
}

//////////////////////////////////////////////////////////////////////////

void IO_Report_PDU::AddStandardVariableRecord( StdVarPtr SVR )
{
    m_vStdVarRecs.push_back( SVR );
    ++m_ui16NumStdVarRec;
    m_ui16PDULength += SVR->GetRecordLength();
}

//////////////////////////////////////////////////////////////////////////

void IO_Report_PDU::SetStandardVariableRecords( const vector<StdVarPtr> & SVR )
{
    m_vStdVarRecs = SVR;

    // Reset the PDU length.
    m_ui16PDULength = IO_REPORT_PDU_SIZE;

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

const vector<StdVarPtr> & IO_Report_PDU::GetStandardVariableRecords() const
{
    return m_vStdVarRecs;
}

//////////////////////////////////////////////////////////////////////////

void IO_Report_PDU::ClearStandardVariableRecords()
{
    // Reset the PDU length.
    m_ui16PDULength = IO_REPORT_PDU_SIZE;

    m_vStdVarRecs.clear();
    m_ui16NumStdVarRec = 0;
}

//////////////////////////////////////////////////////////////////////////

KString IO_Report_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-IO Report PDU-"
       << IO_Header::GetAsString()
       << "Simulation Source: " << m_ui16SimSrc
       << "\nReport     Type: " << GetEnumAsStringIOReportType( m_ui8RptTyp )
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

void IO_Report_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < IO_REPORT_PDU_SIZE  )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vStdVarRecs.clear();

    IO_Header::Decode( stream );

    stream >> m_ui16SimSrc
           >> m_ui8RptTyp
           >> KDIS_STREAM m_AtkEntityID
           >> KDIS_STREAM m_TgtEntityID
           >> m_ui32Padding
           >> m_ui16NumStdVarRec;

    // Use the factory decode function for each standard variable
    for( KUINT16 i = 0; i < m_ui16NumStdVarRec; ++i )
    {
        m_vStdVarRecs.push_back( StandardVariable::FactoryDecodeStandardVariable( stream ) );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream IO_Report_PDU::Encode() const
{
    KDataStream stream;

    IO_Report_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void IO_Report_PDU::Encode( KDataStream & stream ) const
{
    IO_Header::Encode( stream );

    stream << m_ui16SimSrc
           << m_ui8RptTyp
           << KDIS_STREAM m_AtkEntityID
           << KDIS_STREAM m_TgtEntityID
           << m_ui32Padding
           << m_ui16NumStdVarRec;

    vector<StdVarPtr>::const_iterator citr = m_vStdVarRecs.begin();
    vector<StdVarPtr>::const_iterator citrEnd = m_vStdVarRecs.end();
    for( ; citr != citrEnd; ++citr )
    {
        ( *citr )->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL IO_Report_PDU::operator == ( const IO_Report_PDU & Value ) const
{
    if( IO_Header::operator !=( Value ) )                 return false;
    if( m_ui16SimSrc        != Value.m_ui16SimSrc )       return false;
    if( m_ui8RptTyp         != Value.m_ui8RptTyp )        return false;
    if( m_AtkEntityID       != Value.m_AtkEntityID )      return false;
    if( m_TgtEntityID       != Value.m_TgtEntityID )      return false;
    if( m_ui16NumStdVarRec  != Value.m_ui16NumStdVarRec ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IO_Report_PDU::operator != ( const IO_Report_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


