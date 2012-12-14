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

/********************************************************************
    EnumSimulationManagement
    created:    14/03/2009
    author:     Karl Jones

    purpose:    Enums used in Simulation Management PDUs
*********************************************************************/

#pragma once

#include "./EnumDescriptor.h"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {

/************************************************************************/
/* RequiredReliabilityService                                           */
/* Describes the type reliability required for a PDU                    */
/* Used In:                                                             */
/*  Transfer_Control_Request PDU                                        */
/*  Create Entity-R PDU                                                 */
/*  Remove Entity-R PDU                                                 */
/*  Start/Resume-R PDU                                                  */
/*  Stop/Freeze-R PDU                                                   */
/*  Action Request-R PDU                                                */
/*  Data Query-R PDU                                                    */
/*  Set Data-R PDU                                                      */
/*  Data-R PDU                                                          */
/*  Record Query-R PDU                                                  */
/*  Set Record-R PDU                                                    */
/*  Record-R PDU                                                        */
/************************************************************************/

enum RequiredReliabilityService
{
    Acknowledged                                                      = 0,
    Unacknowledged                                                    = 1
};

KString GetEnumAsStringRequiredReliabilityService( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringRequiredReliabilityService( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Reason                                                               */
/* Contains Event types                                                 */
/* Used In:                                                             */
/*  Stop Freeze PDU                                                     */
/*  Stop Freeze-R PDU                                                   */
/************************************************************************/

enum StopFreezeReason
{
    OtherStopFreezeReason                                             = 0,
    Recess                                                            = 1,
    Termination                                                       = 2,
    SystemFailure                                                     = 3,
    SecurityViolation                                                 = 4,
    EntityReconstitution                                              = 5,
    StopForReset                                                      = 6,
    StopForRestart                                                    = 7,
    AbortTrainingReturnToTacticalOperations                           = 8
};

KString GetEnumAsStringStopFreezeReason( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringStopFreezeReason( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* FrozenBehavior                                                       */
/* Frozen behavior of entity.                                           */
/* Used In:                                                             */
/*  Stop Freeze PDU                                                     */
/*  Stop Freeze-R PDU                                                   */
/************************************************************************/

// TODO: NOTE.
// NOTE: The frozen behavior is described as a 8 bit boolean array however the
// PDU dictionary ( SISO website ) contains enumeration values. For now I will
// Use enumerations until I have had a chance to further investigate.

enum FrozenBehavior
{
    SimClock                                                          = 0,
    TransmitPDU                                                       = 1,
    ReceivePDU                                                        = 2
};

KString GetEnumAsStringFrozenBehavior( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringFrozenBehavior( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Acknowledge Flag                                                     */
/* Indicates the type of PDU being acknowledged                         */
/* Used In:                                                             */
/*  Acknowledge PDU                                                     */
/*  Acknowledge-R PDU                                                   */
/************************************************************************/

enum AcknowledgeFlag
{
    CreateEntityPDU                                                   = 1,
    RemoveEntityPDU                                                   = 2,
    Start_ResumePDU                                                   = 3,
    Stop_FreezePDU                                                    = 4,
    TransferControlRequest                                            = 5
};

KString GetEnumAsStringAcknowledgeFlag( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringAcknowledgeFlag( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Acknowledge Response Flag                                            */
/* Indicates if the receiving entity is able to comply with the request */
/* Used In:                                                             */
/*  Acknowledge PDU                                                     */
/*  Acknowledge-R PDU                                                   */
/************************************************************************/

enum AcknowledgeResponseFlag
{
    OtherAcknowledgeResponseFlag                                      = 0,
    AbleToComply                                                      = 1,
    UnableToComply                                                    = 2
};

KString GetEnumAsStringAcknowledgeResponseFlag( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringAcknowledgeResponseFlag( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Action ID                                                            */
/* Indicates the type of action requested                               */
/* Used In:                                                             */
/*  Action Request PDU                                                  */
/*  Action Request-R PDU                                                */
/************************************************************************/

enum ActionID
{
    OtherActionID                                                     = 0,
    LocalStorageOfTheRequestedInformation                             = 1,
    InformSMofEvent_RanOutOfAmmunition                                = 2,
    InformSMofEvent_KilledInaAction                                   = 3,
    InformSMofEvent_Damage                                            = 4,
    InformSMofEvent_MobilityDisabled                                  = 5,
    InformSMofEvent_FireDisabled                                      = 6,
    InformSMofEvent_RanOutOfFuel                                      = 7,
    RecallCheckPointData                                              = 8,
    RecallInitialParameters                                           = 9,
    InitiateTether_Lead                                               = 10,
    InitiateTether_Follow                                             = 11,
    Unthether                                                         = 12,
    InitiateServiceStationResupply                                    = 13,
    InitiatetailGateResupply                                          = 14,
    InitiaTehitchLead                                                 = 15,
    InitiaTehitchFollow                                               = 16,
    Unhitch                                                           = 17,
    Mount                                                             = 18,
    Dismount                                                          = 19,
    StartDRC_DailyReadinessCheck                                      = 20,
    StopDRC                                                           = 21,
    DataQuery                                                         = 22,
    StatusRequest                                                     = 23,
    SendObjectStateData                                               = 24,
    Reconstitute                                                      = 25,
    LockSiteConfiguration                                             = 26,
    UnlockSiteConfiguration                                           = 27,
    UpdateSiteConfiguration                                           = 28,
    QuerySiteConfiguration                                            = 29,
    TetheringInformation                                              = 30,
    MountIntent                                                       = 31,
    AcceptSubscription                                                = 33,
    UnSubscribe                                                       = 34,
    TeleportEntity                                                    = 35,
    Changeaggregatestate                                              = 36,
    RequestStartPDU                                                   = 37,
    WakeUpGetReadyForInitialization                                   = 38,
    InitializeInternalparameters                                      = 39,
    SendPlanData                                                      = 40,
    SynchronizeInternalClocks                                         = 41,
    Run                                                               = 42,
    SaveInternalParameters                                            = 43,
    SimulatemalFunction                                               = 44,
    JoinExercise                                                      = 45,
    ResignExercise                                                    = 46,
    TimeAdvance                                                       = 47,
    TACCSFLOSRequest_Type1                                            = 100,
    TACCSFLOSRequest_Type2                                            = 101
};

KString GetEnumAsStringActionID( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringActionID( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Request Status                                                       */
/* Indicates the response to an action request                          */
/* Used In:                                                             */
/*  Action Response PDU                                                 */
/*  Action Response-R PDU                                               */
/************************************************************************/

enum RequestStatus
{
    OtherRequestStatus                                                = 0,
    Pending                                                           = 1,
    Executing                                                         = 2,
    PartiallyComplete                                                 = 3,
    Complete                                                          = 4,
    RequestRejected                                                   = 5,
    ReTransmitRequestNow                                              = 6,
    ReTransmitRequestLater                                            = 7,
    InvalidTimeParameters                                             = 8,
    SimulationTimeExceeded                                            = 9,
    RequestDone                                                       = 10,
    TACCSFLOSReply_Type1                                              = 100,
    TACCSFLOSReply_Type2                                              = 101,
    JoinExerciseRequestRejected                                       = 201
};

KString GetEnumAsStringRequestStatus( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringRequestStatus( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Event Type                                                           */
/* Contains Event types                                                 */
/* Used In:                                                             */
/*  Event Report PDU                                                    */
/*  Record-R PDU                                                        */
/*  Set Record-R PDU                                                    */
/*  Record Query-R PDU                                                  */
/************************************************************************/

enum EventType
{
    OtherEvent                                                        = 0,
    IndirectFireOrCASFire                                             = 10,
    MinefieldEntry                                                    = 11,
    MinefieldDetonation                                               = 12,
    VehicleMasterPowerOn                                              = 13,
    VehicleMasterPowerOff                                             = 14,
    AggregateStateChangeRequested                                     = 15,
    RanOutOfAmmunition                                                = 2,
    KilledInAction                                                    = 3,
    Damage                                                            = 4,
    MobilityDisabled                                                  = 5,
    FireDisabled                                                      = 6,
    RanOutOfFuel                                                      = 7,
    EntityInitialization                                              = 8,
    RequestForIndirectFireOrCASMission                                = 9,
};

KString GetEnumAsStringEventType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringEventType( const KString & Value, KINT32 & ValueOut );

}; // END namespace ENUMS
}; // END namespace DATA_TYPES
}; // END namespace KDIS
