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

#include "./Event_Report_R_PDU.h"

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

Event_Report_R_PDU::Event_Report_R_PDU( void )
{
    m_ui8PDUType = EventReport_R_PDU_Type;
    m_ui16PDULength = EVENT_REPORT_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Event_Report_R_PDU::Event_Report_R_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Event_Report_R_PDU::Event_Report_R_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID,
                                        EventType ET ) :
    Event_Report_PDU( OriginatingEntityID, ReceivingEntityID, ET )
{
    m_ui8PDUType = EventReport_R_PDU_Type;
    m_ui16PDULength = EVENT_REPORT_R_PDU_SIZE;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
    m_ui8ProtocolFamily = SimulationManagementwithReliability;
}

//////////////////////////////////////////////////////////////////////////

Event_Report_R_PDU::~Event_Report_R_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

KString Event_Report_R_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Event Report-R PDU-\n"
       << Simulation_Management_Header::GetAsString()
       << "Event Type:                 " << GetEnumAsStringEventType( m_ui32EventType )
       << "\nNumber Fixed Datum:         " << m_ui32NumFixedDatum
       << "\nNumber Variable Datum:      " << m_ui32NumVariableDatum
       << "\n";

    ss << "Fixed Datumn";
    vector<FixDtmPtr>::const_iterator citrFixed = m_vFixedDatum.begin();
	vector<FixDtmPtr>::const_iterator citrFixedEnd = m_vFixedDatum.end();
    for( ; citrFixed != citrFixedEnd; ++citrFixed )
    {
        ss << IndentString( ( *citrFixed )->GetAsString() );
    }

	ss << "Variable Datumn";
    vector<VarDtmPtr>::const_iterator citrVar = m_vVariableDatum.begin();
	vector<VarDtmPtr>::const_iterator citrVarEnd = m_vVariableDatum.end();
    for( ; citrVar != citrVarEnd; ++citrVar )
    {
        ss << IndentString( ( *citrVar )->GetAsString() );
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL Event_Report_R_PDU::operator == ( const Event_Report_R_PDU & Value ) const
{
    if( Event_Report_PDU::operator   !=( Value ) ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Event_Report_R_PDU::operator != ( const Event_Report_R_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
