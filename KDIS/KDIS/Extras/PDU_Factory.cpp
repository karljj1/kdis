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

#include "./PDU_Factory.h"

#include "./../PDU/Entity_Info_Interaction/Entity_State_PDU.h"
#include "./../PDU/Entity_Info_Interaction/Collision_PDU.h"
#include "./../PDU/Warfare/Fire_PDU.h"
#include "./../PDU/Warfare/Detonation_PDU.h"
#include "./../PDU/Logistics/Repair_Complete_PDU.h"
#include "./../PDU/Logistics/Repair_Response_PDU.h"
#include "./../PDU/Logistics/Resupply_Cancel_PDU.h"
#include "./../PDU/Logistics/Resupply_Offer_PDU.h"
#include "./../PDU/Logistics/Resupply_Received_PDU.h"
#include "./../PDU/Logistics/Service_Request_PDU.h"
#include "./../PDU/Simulation_Management/Acknowledge_PDU.h"
#include "./../PDU/Simulation_Management/Action_Request_PDU.h"
#include "./../PDU/Simulation_Management/Action_Response_PDU.h"
#include "./../PDU/Simulation_Management/Comment_PDU.h"
#include "./../PDU/Simulation_Management/Create_Entity_PDU.h"
#include "./../PDU/Simulation_Management/Data_PDU.h"
#include "./../PDU/Simulation_Management/Data_Query_PDU.h"
#include "./../PDU/Simulation_Management/Event_Report_PDU.h"
#include "./../PDU/Simulation_Management/Remove_Entity_PDU.h"
#include "./../PDU/Simulation_Management/Set_Data_PDU.h"
#include "./../PDU/Simulation_Management/Start_Resume_PDU.h"
#include "./../PDU/Simulation_Management/Stop_Freeze_PDU.h"
#include "./../PDU/Distributed_Emission_Regeneration/Designator_PDU.h"
#include "./../PDU/Distributed_Emission_Regeneration/Electromagnetic_Emission_PDU.h"
#include "./../PDU/Radio_Communications/Receiver_PDU.h"
#include "./../PDU/Radio_Communications/Signal_PDU.h"
#include "./../PDU/Radio_Communications/Transmitter_PDU.h"

// The following are DIS version 6 PDUs.
#if DIS_VERSION >= 6
#include "./../PDU/Entity_Info_Interaction/Collision_Elastic_PDU.h"
#include "./../PDU/Radio_Communications/Intercom_Signal_PDU.h"
#include "./../PDU/Radio_Communications//Intercom_Control_PDU.h"
#include "./../PDU/Distributed_Emission_Regeneration/IFF_PDU.h"
#include "./../PDU/Distributed_Emission_Regeneration/Underwater_Acoustic_PDU.h"
#include "./../PDU/Distributed_Emission_Regeneration/SEES_PDU.h"
#include "./../PDU/Entity_Management/Aggregate_State_PDU.h"
#include "./../PDU/Entity_Management/Transfer_Control_Request_PDU.h"
#include "./../PDU/Simulation_Management_With_Reliability/Acknowledge_R_PDU.h"
#include "./../PDU/Simulation_Management_With_Reliability/Action_Request_R_PDU.h"
#include "./../PDU/Simulation_Management_With_Reliability/Action_Response_R_PDU.h"
#include "./../PDU/Simulation_Management_With_Reliability/Comment_R_PDU.h"
#include "./../PDU/Simulation_Management_With_Reliability/Create_Entity_R_PDU.h"
#include "./../PDU/Simulation_Management_With_Reliability//Data_Query_R_PDU.h"
#include "./../PDU/Simulation_Management_With_Reliability/Data_R_PDU.h"
#include "./../PDU/Simulation_Management_With_Reliability/Event_Report_R_PDU.h"
#include "./../PDU/Simulation_Management_With_Reliability/Remove_Entity_R_PDU.h"
#include "./../PDU/Simulation_Management_With_Reliability/Set_Data_R_PDU.h"
#include "./../PDU/Simulation_Management_With_Reliability/Start_Resume_R_PDU.h"
#include "./../PDU/Simulation_Management_With_Reliability/Stop_Freeze_R_PDU.h"
#include "./../PDU/Simulation_Management_With_Reliability/Record_R_PDU.h"
#include "./../PDU/Simulation_Management_With_Reliability/Set_Record_R_PDU.h"
#include "./../PDU/Simulation_Management_With_Reliability/Record_Query_R_PDU.h"
#include "./../PDU/Synthetic_Environment/Environmental_Process_PDU.h"
#include "./../PDU/Synthetic_Environment/Gridded_Data_PDU.h"
#include "./../PDU/Synthetic_Environment/Point_Object_State_PDU.h"
#include "./../PDU/Synthetic_Environment/Linear_Object_State_PDU.h"
#include "./../PDU/Synthetic_Environment/Areal_Object_State_PDU.h"
#include "./../PDU/Entity_Info_Interaction/Entity_State_Update_PDU.h"
#include "./../PDU/Radio_Communications/Intercom_Control_PDU.h"
#include "./../PDU/Radio_Communications/Intercom_Signal_PDU.h"
#include "./../PDU/Entity_Management/Aggregate_State_PDU.h"
#include "./../PDU/Entity_Management/IsGroupOf_PDU.h"
#include "./../PDU/Entity_Management/IsPartOf_PDU.h"
#include "./../PDU/Entity_Management/Transfer_Control_Request_PDU.h"
#include "./../PDU/Minefield/Minefield_State_PDU.h"
#include "./../PDU/Minefield/Minefield_Query_PDU.h"
#include "./../PDU/Minefield/Minefield_Data_PDU.h"
#include "./../PDU/Minefield/Minefield_Response_NACK_PDU.h"
#include "./../PDU/Live_Entity/TSPI_PDU.h"
#include "./../PDU/Live_Entity/Appearance_PDU.h"
#include "./../PDU/Live_Entity/Articulated_Parts_PDU.h"
#include "./../PDU/Live_Entity/LE_Fire_PDU.h"
#include "./../PDU/Live_Entity/LE_Detonation_PDU.h"
#endif

// The following are DIS version 7 PDUs.
#if DIS_VERSION >= 7
#include "./../PDU/Entity_Info_Interaction/Attribute_PDU.h"
#include "./../PDU/Information_Operations/IO_Action_PDU.h"
#include "./../PDU/Information_Operations/IO_Report_PDU.h"
#include "./../PDU/Warfare/Directed_Energy_Fire_PDU.h"
#include "./../PDU/Warfare/Entity_Damage_Status_PDU.h"
#endif

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace UTILS;
using namespace PDU;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// protected:
//////////////////////////////////////////////////////////////////////////

auto_ptr<Header> PDU_Factory::applyFilters( Header * H )
{
    // Test all the filters
    vector<PDU_Factory_Filter*>::const_iterator citr = m_vFilters.begin();
    vector<PDU_Factory_Filter*>::const_iterator citrEnd = m_vFilters.end();

    for( ; citr != citrEnd; ++citr )
    {
        if( !( *citr )->ApplyFilter( H ) )
        {
            // The PDU failed a test so return NULL.
            return auto_ptr<Header>( NULL );
        }
    }

    return auto_ptr<Header>( H );
}

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

PDU_Factory::PDU_Factory()
{
}

//////////////////////////////////////////////////////////////////////////

PDU_Factory::~PDU_Factory()
{
    // Delete the filters
    vector<PDU_Factory_Filter*>::iterator itr = m_vFilters.begin();
    vector<PDU_Factory_Filter*>::iterator itrEnd = m_vFilters.end();
    for( ; itr != itrEnd; ++itr )
    {
        delete *itr;
    }
}

//////////////////////////////////////////////////////////////////////////

void PDU_Factory::AddFilter( PDU_Factory_Filter * F )
{
    m_vFilters.push_back( F );
}

//////////////////////////////////////////////////////////////////////////

void PDU_Factory::RemoveFilter( PDU_Factory_Filter * F )
{
    // Check for filter and remove it if we find it.
    vector<PDU_Factory_Filter*>::iterator itr = m_vFilters.begin();
    vector<PDU_Factory_Filter*>::iterator itrEnd = m_vFilters.end();
    for( ; itr != itrEnd; ++itr )
    {
        if( (*itr) == F )
        {
            itr = m_vFilters.erase( itr );
        }
    }
}

//////////////////////////////////////////////////////////////////////////

auto_ptr<Header> PDU_Factory::Decode( KOCTET * Buffer, KUINT16 BufferSize )throw( KException )
{
    KDataStream kd( Buffer, BufferSize );
    return Decode( kd );
}

//////////////////////////////////////////////////////////////////////////

auto_ptr<Header> PDU_Factory::Decode( KDataStream & Stream )throw( KException )
{    
	return Decode( Header( Stream ), Stream );
}

//////////////////////////////////////////////////////////////////////////

auto_ptr<Header> PDU_Factory::Decode( const Header & H, KDataStream & Stream )throw( KException )
{
    switch( H.GetPDUType() )
    {
    case Entity_State_PDU_Type:
        return applyFilters( new Entity_State_PDU( H, Stream ) );

    case Fire_PDU_Type:
        return applyFilters( new Fire_PDU( H, Stream ) );

    case Detonation_PDU_Type:
        return applyFilters( new Detonation_PDU( H, Stream ) );

    case Collision_PDU_Type:
        return applyFilters( new Collision_PDU( H, Stream ) );

    case Service_Request_PDU_Type:
        return applyFilters( new Service_Request_PDU( H, Stream ) );

    case Resupply_Offer_PDU_Type:
        return applyFilters( new Resupply_Offer_PDU( H, Stream ) );

    case Resupply_Received_PDU_Type:
        return applyFilters( new Resupply_Received_PDU( H, Stream ) );

    case Resupply_Cancel_PDU_Type:
        return applyFilters( new Resupply_Cancel_PDU( H, Stream ) );

    case Repair_Complete_PDU_Type:
        return applyFilters( new Repair_Complete_PDU( H, Stream ) );

    case Repair_Response_PDU_Type:
        return applyFilters( new Repair_Response_PDU( H, Stream ) );

    case Create_Entity_PDU_Type:
        return applyFilters( new Create_Entity_PDU( H, Stream ) );

    case Remove_Entity_PDU_Type:
        return applyFilters( new Remove_Entity_PDU( H, Stream ) );

    case Start_Resume_PDU_Type:
        return applyFilters( new Start_Resume_PDU( H, Stream ) );

    case Stop_Freeze_PDU_Type:
        return applyFilters( new Stop_Freeze_PDU( H, Stream ) );

    case Acknowledge_PDU_Type:
        return applyFilters( new Acknowledge_PDU( H, Stream ) );

    case Action_Request_PDU_Type:
        return applyFilters( new Action_Request_PDU( H, Stream ) );

    case Action_Response_PDU_Type:
        return applyFilters( new Action_Response_PDU( H, Stream ) );

    case Data_Query_PDU_Type:
        return applyFilters( new Data_Query_PDU( H, Stream ) );

    case Set_Data_PDU_Type:
        return applyFilters( new Set_Data_PDU( H, Stream ) );

    case Data_PDU_Type:
        return applyFilters( new Data_PDU( H, Stream ) );

    case Event_Report_PDU_Type:
        return applyFilters( new Event_Report_PDU( H, Stream ) );

    case Message_PDU_Type:
        return applyFilters( new Comment_PDU( H, Stream ) );

    case Electromagnetic_Emission_PDU_Type:
        return applyFilters( new Electromagnetic_Emission_PDU( H, Stream ) );

    case Designator_PDU_Type:
        return applyFilters( new Designator_PDU( H, Stream ) );

    case Transmitter_PDU_Type:
        return applyFilters( new Transmitter_PDU( H, Stream ) );

    case Signal_PDU_Type:
        return applyFilters( new Signal_PDU( H, Stream ) );

    case Receiver_PDU_Type:
        return applyFilters( new Receiver_PDU( H, Stream ) );

// The following are DIS version 6 PDUs.
#if DIS_VERSION >= 6

    case Collision_Elastic_PDU_Type:
        return applyFilters( new Collision_Elastic_PDU( H, Stream ) );

    case IFF_ATC_NAVAIDS_PDU_Type:
            return applyFilters( new IFF_PDU( H, Stream ) );       

    case UnderwaterAcoustic_PDU_Type:
        return applyFilters( new Underwater_Acoustic_PDU( H, Stream ) );

    case SupplementalEmission_EntityState_PDU_Type:
        return applyFilters( new SEES_PDU( H, Stream ) );

    case IntercomSignal_PDU_Type:
        return applyFilters( new Intercom_Signal_PDU( H, Stream ) );

    case IntercomControl_PDU_Type:
        return applyFilters( new Intercom_Control_PDU( H, Stream ) );

    case AggregateState_PDU_Type:
        return applyFilters( new Aggregate_State_PDU( H, Stream ) );

    case IsGroupOf_PDU_Type:
        return applyFilters( new IsGroupOf_PDU( H, Stream ) );

    case TransferControl_PDU_Type:
        return applyFilters( new Transfer_Control_Request_PDU( H, Stream ) );

    case IsPartOf_PDU_Type:
        return applyFilters( new IsPartOf_PDU( H, Stream ) );

    case MinefieldState_PDU_Type:
        return applyFilters( new Minefield_State_PDU( H, Stream ) );

    case MinefieldQuery_PDU_Type:
        return applyFilters( new Minefield_Query_PDU( H, Stream ) );

    case MinefieldData_PDU_Type:
        return applyFilters( new Minefield_Data_PDU( H, Stream ) );

    case MinefieldResponseNAK_PDU_Type:
        return applyFilters( new Minefield_Response_NACK_PDU( H, Stream ) );

    case EnvironmentalProcess_PDU_Type:
        return applyFilters( new Environmental_Process_PDU( H, Stream ) );

    case GriddedData_PDU_Type:
        return applyFilters( new Gridded_Data_PDU( H, Stream ) );

    case PointObjectState_PDU_Type:
        return applyFilters( new Point_Object_State_PDU( H, Stream ) );

    case LinearObjectState_PDU_Type:
        return applyFilters( new Linear_Object_State_PDU( H, Stream ) );

    case ArealObjectState_PDU_Type:
        return applyFilters( new Areal_Object_State_PDU( H, Stream ) );

    case TSPI_PDU_Type:
        return applyFilters( new TSPI_PDU( H, Stream ) );

    case Appearance_PDU_Type:
        return applyFilters( new Appearance_PDU( H, Stream ) );

    case ArticulatedParts_PDU_Type:
        return applyFilters( new Articulated_Parts_PDU( H, Stream ) );

    case LEFire_PDU_Type:
        return applyFilters( new LE_Fire_PDU( H, Stream ) );

    case LEDetonation_PDU_Type:
        return applyFilters( new LE_Detonation_PDU( H, Stream ) );

    case CreateEntity_R_PDU_Type:
        return applyFilters( new Create_Entity_R_PDU( H, Stream ) );

    case RemoveEntity_R_PDU_Type:
        return applyFilters( new Remove_Entity_R_PDU( H, Stream ) );

    case Start_Resume_R_PDU_Type:
        return applyFilters( new Start_Resume_R_PDU( H, Stream ) );

    case Stop_Freeze_R_PDU_Type:
        return applyFilters( new Stop_Freeze_R_PDU( H, Stream ) );

    case Acknowledge_R_PDU_Type:
        return applyFilters( new Acknowledge_R_PDU( H, Stream ) );

    case ActionRequest_R_PDU_Type:
        return applyFilters( new Action_Request_R_PDU( H, Stream ) );

    case ActionResponse_R_PDU_Type:
        return applyFilters( new Action_Response_R_PDU( H, Stream ) );

    case DataQuery_R_PDU_Type:
        return applyFilters( new Data_Query_R_PDU( H, Stream ) );

    case SetData_R_PDU_Type:
        return applyFilters( new Set_Data_R_PDU( H, Stream ) );

    case Data_R_PDU_Type:
        return applyFilters( new Data_R_PDU( H, Stream ) );

    case EventReport_R_PDU_Type:
        return applyFilters( new Event_Report_R_PDU( H, Stream ) );

    case Comment_R_PDU_Type:
        return applyFilters( new Comment_R_PDU( H, Stream ) );

    case Record_R_PDU_Type:
        return applyFilters( new Record_R_PDU( H, Stream ) );

    case SetRecord_R_PDU_Type:
        return applyFilters( new Set_Record_R_PDU( H, Stream ) );

    case RecordQuery_R_PDU_Type:
        return applyFilters( new Record_Query_R_PDU( H, Stream ) );

    case EntityStateUpdate_PDU_Type:
        return applyFilters( new Entity_State_Update_PDU( H, Stream ) );

	#endif

	// The following are DIS version 7 PDUs.
	#if DIS_VERSION >= 7

	case DirectedEnergyFire_PDU_Type:
		return applyFilters( new Directed_Energy_Fire_PDU( H, Stream ) );
		
	case EntityDamageStatus_PDU_Type:
		return applyFilters( new Entity_Damage_Status_PDU( H, Stream ) );

	case IO_Action_PDU_Type:
		return applyFilters( new IO_Action_PDU( H, Stream ) );

	case IO_Report_PDU_Type:
		return applyFilters( new IO_Report_PDU( H, Stream ) );

	case Attribute_PDU_Type:
		return applyFilters( new Attribute_PDU( H, Stream ) );

	#endif
    }

    // We could not decode the PDU
    return auto_ptr<Header>( NULL );
}

//////////////////////////////////////////////////////////////////////////
