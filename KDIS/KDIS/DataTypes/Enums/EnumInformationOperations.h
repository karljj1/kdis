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
    EnumInformationOperations
    created:    16/11/2010
    author:     Karl Jones

    purpose:    Enums used for Information Operations from DIS version 7.
*********************************************************************/

#pragma once

#include "./EnumDescriptor.h"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {

/************************************************************************/
/* WarfareType                                                          */
/* Identifies the type of IO warfare                                    */
/* Used In:                                                             */
/*  IO_Action_PDU                                                       */
/************************************************************************/

enum WarfareType
{
    NoWarfareTypeStatement                                            = 0,
    ElectronicWarfare_CW                                              = 1,
    ComputerNetworkOperations_CNO                                     = 2,
    PsychologicalOperations_PSYOPS                                    = 3,
    MilitaryDeception_MILDEC                                          = 4,
    OperationsSecurity_OPSEC                                          = 5
};

KString GetEnumAsStringWarfareType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringWarfareType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* ActionType                                                           */
/* The IO Action Type                                                   */
/* Used In:                                                             */
/*  IO_Action_PDU                                                       */
/************************************************************************/

enum ActionType
{
    NoActionTypeStatement                                             = 0,
    IOAttackProfileData_Parametrics                                   = 1,
    IOAttackComputerEffects                                           = 2
};

KString GetEnumAsStringActionType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringActionType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* ActionPhase                                                          */
/* The IO Action Phase                                                  */
/* Used In:                                                             */
/*  IO_Action_PDU                                                       */
/************************************************************************/

enum ActionPhase
{
    NoActionPhaseStatement                                            = 0,
    StartAttackProfile                                                = 1,
    EndAttackProfile                                                  = 2,
    ContinueAttackProfileWithChanges                                  = 3,
    StartAttackEffects                                                = 4,
    EndAttackEffects                                                  = 5,
    ContinueAttackEffectsWithChanges                                  = 6
};

KString GetEnumAsStringActionPhase( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringActionPhase( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* Standard Variable Type                                               */
/*                                                                      */
/* Used In:                                                             */
/*  StandardVariable                                                    */
/************************************************************************/

enum StandardVariableType
{
    // Directed Energy Types
    DEPrecisionAimpointRecord                                         = 4000,
    DEAreaAimpointRecord                                              = 4001,
    // Information Operations Types
    IOEffectRecord                                                    = 5500,
    IOCommunicationsNodeRecord                                        = 5501
};

KString GetEnumAsStringStandardVariableType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringStandardVariableType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* IOCommunicationsNodeType                                             */
/* Identifies the type of communication node.                           */
/* Used In:                                                             */
/*  IOCommunicationsNodeType                                            */
/************************************************************************/

enum IOCommunicationsNodeType
{
    NoStatementCommunicationsNodeType                                 = 0,
    SenderNodeID                                                      = 1,
    ReceiverNodeID                                                    = 2,
    SenderReceiverNodeID                                              = 3
};

KString GetEnumAsStringIOCommunicationsNodeType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringIOCommunicationsNodeType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* IOStatus                                                             */
/* Indicates whether the IO effect has an effect on the sender, receiver*/
/* ,message(s) or some combination of them.                             */
/* Used In:                                                             */
/*  IOEffect                                                            */
/************************************************************************/

enum IOStatus
{
    NoStatementIOStatus                                               = 0,
    EffectOnSender                                                    = 1,
    EffectOnReceiver                                                  = 2,
    EffectOnSenderAndReceiver                                         = 3,
    EffectOnMessage                                                   = 4,
    EffectOnSenderAndMessage                                          = 5,
    EffectOnReceiverAndMessage                                        = 6,
    EffectOnSenderReceiverAndMessage                                  = 7
};

KString GetEnumAsStringIOStatus( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringIOStatus( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* IOLinkType                                                           */
/* Indicates the IO link type as a logical or physical link or node     */
/* Used In:                                                             */
/*  IOEffect                                                            */
/************************************************************************/

enum IOLinkType
{
    NoStatementIOLinkType                                             = 0,
    LogicalLink                                                       = 1,
    PhysicalNode                                                      = 2,
    PhysicalLink                                                      = 3
};

KString GetEnumAsStringIOLinkType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringIOLinkType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* IOEffectType                                                         */
/* Indicates the IO effect associated with an IO attack.                */
/* Used In:                                                             */
/*  IOEffect                                                            */
/************************************************************************/

enum IOEffectType
{
    NoStatementIOEffectType                                           = 0,
    Denial                                                            = 1,
    Degraded                                                          = 2,
    Disrupt                                                           = 3,
    OtherIOEffectType                                                 = 4,
    TerminateEffect                                                   = 5
};

KString GetEnumAsStringIOEffectType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringIOEffectType( const KString & Value, KINT32 & ValueOut );

/************************************************************************/
/* IOReportType                                                         */
/* Indicates the the type of IO report.                                 */
/* Used In:                                                             */
/*  IO_Report_PDU                                                       */
/************************************************************************/

enum IOReportType
{
    InitialReport                                                     = 1,
    UpdateReport                                                      = 2,
    FinalReport                                                       = 3
};

KString GetEnumAsStringIOReportType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringIOReportType( const KString & Value, KINT32 & ValueOut );

}; // END namespace ENUMS
}; // END namespace DATA_TYPES
}; // END namespace KDIS
