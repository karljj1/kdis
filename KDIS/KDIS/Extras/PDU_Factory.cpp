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
#include "./../PDU/Distributed_Emission_Regeneration/IFF_ATC_NAVAIDS_L1_PDU.h"
#include "./../PDU/Distributed_Emission_Regeneration/IFF_ATC_NAVAIDS_L2_PDU.h"
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
#include "./../PDU/Synthetic_Enviroment/Environmental_Process_PDU.h"
#include "./../PDU/Synthetic_Enviroment/Gridded_Data_PDU.h"
#include "./../PDU/Synthetic_Enviroment/Point_Object_State_PDU.h"
#include "./../PDU/Synthetic_Enviroment/Linear_Object_State_PDU.h"
#include "./../PDU/Synthetic_Enviroment/Areal_Object_State_PDU.h"
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

PDU_Factory::PDU_Factory( void )
{
}

//////////////////////////////////////////////////////////////////////////

PDU_Factory::~PDU_Factory( void )
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
	KUINT16 currentWritePos = Stream.GetCurrentWritePosition();
    Header h( Stream );
    Stream.SetCurrentWritePosition(currentWritePos);
	return Decode( h, Stream );
}

//////////////////////////////////////////////////////////////////////////

auto_ptr<Header> PDU_Factory::Decode( const Header & H, KDataStream & Stream )throw( KException )
{
    switch( H.GetPDUType() )
    {
    case Entity_State_PDU_Type:
        return applyFilters( new Entity_State_PDU( Stream ) );

    case Fire_PDU_Type:
        return applyFilters( new Fire_PDU( Stream ) );

    case Detonation_PDU_Type:
        return applyFilters( new Detonation_PDU( Stream ) );

    case Collision_PDU_Type:
        return applyFilters( new Collision_PDU( Stream ) );

    case Service_Request_PDU_Type:
        return applyFilters( new Service_Request_PDU( Stream ) );

    case Resupply_Offer_PDU_Type:
        return applyFilters( new Resupply_Offer_PDU( Stream ) );

    case Resupply_Received_PDU_Type:
        return applyFilters( new Resupply_Received_PDU( Stream ) );

    case Resupply_Cancel_PDU_Type:
        return applyFilters( new Resupply_Cancel_PDU( Stream ) );

    case Repair_Complete_PDU_Type:
        return applyFilters( new Repair_Complete_PDU( Stream ) );

    case Repair_Response_PDU_Type:
        return applyFilters( new Repair_Response_PDU( Stream ) );

    case Create_Entity_PDU_Type:
        return applyFilters( new Create_Entity_PDU( Stream ) );

    case Remove_Entity_PDU_Type:
        return applyFilters( new Remove_Entity_PDU( Stream ) );

    case Start_Resume_PDU_Type:
        return applyFilters( new Start_Resume_PDU( Stream ) );

    case Stop_Freeze_PDU_Type:
        return applyFilters( new Stop_Freeze_PDU( Stream ) );

    case Acknowledge_PDU_Type:
        return applyFilters( new Acknowledge_PDU( Stream ) );

    case Action_Request_PDU_Type:
        return applyFilters( new Action_Request_PDU( Stream ) );

    case Action_Response_PDU_Type:
        return applyFilters( new Action_Response_PDU( Stream ) );

    case Data_Query_PDU_Type:
        return applyFilters( new Data_Query_PDU( Stream ) );

    case Set_Data_PDU_Type:
        return applyFilters( new Set_Data_PDU( Stream ) );

    case Data_PDU_Type:
        return applyFilters( new Data_PDU( Stream ) );

    case Event_Report_PDU_Type:
        return applyFilters( new Event_Report_PDU( Stream ) );

    case Message_PDU_Type:
        return applyFilters( new Comment_PDU( Stream ) );

    case Electromagnetic_Emission_PDU_Type:
        return applyFilters( new Electromagnetic_Emission_PDU( Stream ) );

    case Designator_PDU_Type:
        return applyFilters( new Designator_PDU( Stream ) );

    case Transmitter_PDU_Type:
        return applyFilters( new Transmitter_PDU( Stream ) );

    case Signal_PDU_Type:
        return applyFilters( new Signal_PDU( Stream ) );

    case Receiver_PDU_Type:
        return applyFilters( new Receiver_PDU( Stream ) );

// The following are DIS version 6 PDUs.
#if DIS_VERSION >= 6

    case Collision_Elastic_PDU_Type:
        return applyFilters( new Collision_Elastic_PDU( Stream ) );

    case IFF_ATC_NAVAIDS_PDU_Type:
        if( Stream.GetBufferSize() > IFF_ATC_NAVAIDS_L1_PDU::IFF_ATC_NAVAIDS_L1_PDU_SIZE )
        {
            return applyFilters( new IFF_ATC_NAVAIDS_L2_PDU( Stream ) );
        }
        else
        {
            return applyFilters( new IFF_ATC_NAVAIDS_L1_PDU( Stream ) );
        }

    case UnderwaterAcoustic_PDU_Type:
        return applyFilters( new Underwater_Acoustic_PDU( Stream ) );

    case SupplementalEmission_EntityState_PDU_Type:
        return applyFilters( new SEES_PDU( Stream ) );

    case IntercomSignal_PDU_Type:
        return applyFilters( new Intercom_Signal_PDU( Stream ) );

    case IntercomControl_PDU_Type:
        return applyFilters( new Intercom_Control_PDU( Stream ) );

    case AggregateState_PDU_Type:
        return applyFilters( new Aggregate_State_PDU( Stream ) );

    case IsGroupOf_PDU_Type:
        return applyFilters( new IsGroupOf_PDU( Stream ) );

    case TransferControl_PDU_Type:
        return applyFilters( new Transfer_Control_Request_PDU( Stream ) );

    case IsPartOf_PDU_Type:
        return applyFilters( new IsPartOf_PDU( Stream ) );

    case MinefieldState_PDU_Type:
        return applyFilters( new Minefield_State_PDU( Stream ) );

    case MinefieldQuery_PDU_Type:
        return applyFilters( new Minefield_Query_PDU( Stream ) );

    case MinefieldData_PDU_Type:
        return applyFilters( new Minefield_Data_PDU( Stream ) );

    case MinefieldResponseNAK_PDU_Type:
        return applyFilters( new Minefield_Response_NACK_PDU( Stream ) );

    case EnvironmentalProcess_PDU_Type:
        return applyFilters( new Environmental_Process_PDU( Stream ) );

    case GriddedData_PDU_Type:
        return applyFilters( new Gridded_Data_PDU( Stream ) );

    case PointObjectState_PDU_Type:
        return applyFilters( new Point_Object_State_PDU( Stream ) );

    case LinearObjectState_PDU_Type:
        return applyFilters( new Linear_Object_State_PDU( Stream ) );

    case ArealObjectState_PDU_Type:
        return applyFilters( new Areal_Object_State_PDU( Stream ) );

    case TSPI_PDU_Type:
        return applyFilters( new TSPI_PDU( Stream ) );

    case Appearance_PDU_Type:
        return applyFilters( new Appearance_PDU( Stream ) );

    case ArticulatedParts_PDU_Type:
        return applyFilters( new Articulated_Parts_PDU( Stream ) );

    case LEFire_PDU_Type:
        return applyFilters( new LE_Fire_PDU( Stream ) );

    case LEDetonation_PDU_Type:
        return applyFilters( new LE_Detonation_PDU( Stream ) );

    case CreateEntity_R_PDU_Type:
        return applyFilters( new Create_Entity_R_PDU( Stream ) );

    case RemoveEntity_R_PDU_Type:
        return applyFilters( new Remove_Entity_R_PDU( Stream ) );

    case Start_Resume_R_PDU_Type:
        return applyFilters( new Start_Resume_R_PDU( Stream ) );

    case Stop_Freeze_R_PDU_Type:
        return applyFilters( new Stop_Freeze_R_PDU( Stream ) );

    case Acknowledge_R_PDU_Type:
        return applyFilters( new Acknowledge_R_PDU( Stream ) );

    case ActionRequest_R_PDU_Type:
        return applyFilters( new Action_Request_R_PDU( Stream ) );

    case ActionResponse_R_PDU_Type:
        return applyFilters( new Action_Response_R_PDU( Stream ) );

    case DataQuery_R_PDU_Type:
        return applyFilters( new Data_Query_R_PDU( Stream ) );

    case SetData_R_PDU_Type:
        return applyFilters( new Set_Data_R_PDU( Stream ) );

    case Data_R_PDU_Type:
        return applyFilters( new Data_R_PDU( Stream ) );

    case EventReport_R_PDU_Type:
        return applyFilters( new Event_Report_R_PDU( Stream ) );

    case Comment_R_PDU_Type:
        return applyFilters( new Comment_R_PDU( Stream ) );

    case Record_R_PDU_Type:
        return applyFilters( new Record_R_PDU( Stream ) );

    case SetRecord_R_PDU_Type:
        return applyFilters( new Set_Record_R_PDU( Stream ) );

    case RecordQuery_R_PDU_Type:
        return applyFilters( new Record_Query_R_PDU( Stream ) );

    case EntityStateUpdate_PDU_Type:
        return applyFilters( new Entity_State_Update_PDU( Stream ) );

	#endif

	// The following are DIS version 7 PDUs.
	#if DIS_VERSION >= 7

	case DirectedEnergyFire_PDU_Type:
		return applyFilters( new Directed_Energy_Fire_PDU( Stream ) );
		
	case EntityDamageStatus_PDU_Type:
		return applyFilters( new Entity_Damage_Status_PDU( Stream ) );

	case IO_Action_PDU_Type:
		return applyFilters( new IO_Action_PDU( Stream ) );

	case IO_Report_PDU_Type:
		return applyFilters( new IO_Report_PDU( Stream ) );

	case Attribute_PDU_Type:
		return applyFilters( new Attribute_PDU( Stream ) );

	#endif
    }

    // We could not decode the PDU
    return auto_ptr<Header>( NULL );
}

//////////////////////////////////////////////////////////////////////////
