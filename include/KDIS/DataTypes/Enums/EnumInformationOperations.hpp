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

/********************************************************************
    EnumInformationOperations
    created:    16/11/2010
    author:     Karl Jones

    purpose:    Enums used for Information Operations from DIS version 7.
*********************************************************************/

#pragma once

#include "KDIS/DataTypes/Enums/EnumDescriptor.hpp"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {

/************************************************************************/
/* WarfareType                                                          */
/* Identifies the type of IO warfare                                    */
/* Used In:                                                             */
/*  IO_Action_PDU                                                       */
/************************************************************************/

enum class WarfareType : KUINT16 {
  NoWarfareTypeStatement = 0,
  ElectronicWarfare_CW = 1,
  ComputerNetworkOperations_CNO = 2,
  PsychologicalOperations_PSYOPS = 3,
  MilitaryDeception_MILDEC = 4,
  OperationsSecurity_OPSEC = 5,
  PhysicalAttack = 6
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using
// GetEnumDescriptor<enum>. If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will
// be returned.
KDIS_EXPORT KUINT32 GetEnumSizeWarfareType();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor* GetEnumDescriptorWarfareType(KUINT32 Index);

KDIS_EXPORT KString GetEnumAsStringWarfareType(KINT32 Value);

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringWarfareType(const KString& Value,
                                               KINT32& ValueOut);

/************************************************************************/
/* ActionType                                                           */
/* The IO Action Type                                                   */
/* Used In:                                                             */
/*  IO_Action_PDU                                                       */
/************************************************************************/

enum class ActionType : KUINT16 {
  NoActionTypeStatement = 0,
  IOAttackProfileData_Parametrics = 1,
  IOAttackComputerEffects = 2
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using
// GetEnumDescriptor<enum>. If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will
// be returned.
KDIS_EXPORT KUINT32 GetEnumSizeActionType();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor* GetEnumDescriptorActionType(KUINT32 Index);

KDIS_EXPORT KString GetEnumAsStringActionType(KINT32 Value);

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringActionType(const KString& Value,
                                              KINT32& ValueOut);

/************************************************************************/
/* ActionPhase                                                          */
/* The IO Action Phase                                                  */
/* Used In:                                                             */
/*  IO_Action_PDU                                                       */
/************************************************************************/

enum class ActionPhase : KUINT16 {
  NoActionPhaseStatement = 0,
  StartAttackProfile = 1,
  EndAttackProfile = 2,
  ContinueAttackProfileWithChanges = 3,
  StartAttackEffects = 4,
  EndAttackEffects = 5,
  ContinueAttackEffectsWithChanges = 6
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using
// GetEnumDescriptor<enum>. If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will
// be returned.
KDIS_EXPORT KUINT32 GetEnumSizeActionPhase();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor* GetEnumDescriptorActionPhase(KUINT32 Index);

KDIS_EXPORT KString GetEnumAsStringActionPhase(KINT32 Value);

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringActionPhase(const KString& Value,
                                               KINT32& ValueOut);

/************************************************************************/
/* Standard Variable Type                                               */
/*                                                                      */
/* Used In:                                                             */
/*  StandardVariable                                                    */
/************************************************************************/

enum class StandardVariableType : KUINT32 {
  // Directed Energy Types
  DEPrecisionAimpointRecord = 4000,
  DEAreaAimpointRecord = 4001,
  // Information Operations Types
  IOEffectRecord = 5500,
  IOCommunicationsNodeRecord = 5501
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using
// GetEnumDescriptor<enum>. If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will
// be returned.
KDIS_EXPORT KUINT32 GetEnumSizeStandardVariableType();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor* GetEnumDescriptorStandardVariableType(
    KUINT32 Index);

KDIS_EXPORT KString GetEnumAsStringStandardVariableType(KINT32 Value);

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringStandardVariableType(const KString& Value,
                                                        KINT32& ValueOut);

/************************************************************************/
/* IOCommunicationsNodeType                                             */
/* Identifies the type of communication node.                           */
/* Used In:                                                             */
/*  IOCommunicationsNodeType                                            */
/************************************************************************/

enum class IOCommunicationsNodeType : KUINT8 {
  NoStatementCommunicationsNodeType = 0,
  SenderNodeID = 1,
  ReceiverNodeID = 2,
  SenderReceiverNodeID = 3
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using
// GetEnumDescriptor<enum>. If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will
// be returned.
KDIS_EXPORT KUINT32 GetEnumSizeIOCommunicationsNodeType();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor* GetEnumDescriptorIOCommunicationsNodeType(
    KUINT32 Index);

KDIS_EXPORT KString GetEnumAsStringIOCommunicationsNodeType(KINT32 Value);

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringIOCommunicationsNodeType(
    const KString& Value, KINT32& ValueOut);

/************************************************************************/
/* IOStatus                                                             */
/* Indicates whether the IO effect has an effect on the sender, receiver*/
/* ,message(s) or some combination of them.                             */
/* Used In:                                                             */
/*  IOEffect                                                            */
/************************************************************************/

enum class IOStatus : KUINT8 {
  NoStatementIOStatus = 0,
  EffectOnSender = 1,
  EffectOnReceiver = 2,
  EffectOnSenderAndReceiver = 3,
  EffectOnMessage = 4,
  EffectOnSenderAndMessage = 5,
  EffectOnReceiverAndMessage = 6,
  EffectOnSenderReceiverAndMessage = 7
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using
// GetEnumDescriptor<enum>. If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will
// be returned.
KDIS_EXPORT KUINT32 GetEnumSizeIOStatus();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor* GetEnumDescriptorIOStatus(KUINT32 Index);

KDIS_EXPORT KString GetEnumAsStringIOStatus(KINT32 Value);

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringIOStatus(const KString& Value,
                                            KINT32& ValueOut);

/************************************************************************/
/* IOLinkType                                                           */
/* Indicates the IO link type as a logical or physical link or node     */
/* Used In:                                                             */
/*  IOEffect                                                            */
/************************************************************************/

enum class IOLinkType : KUINT8 {
  NoStatementIOLinkType = 0,
  LogicalLink = 1,
  PhysicalNode = 2,
  PhysicalLink = 3
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using
// GetEnumDescriptor<enum>. If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will
// be returned.
KDIS_EXPORT KUINT32 GetEnumSizeIOLinkType();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor* GetEnumDescriptorIOLinkType(KUINT32 Index);

KDIS_EXPORT KString GetEnumAsStringIOLinkType(KINT32 Value);

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringIOLinkType(const KString& Value,
                                              KINT32& ValueOut);

/************************************************************************/
/* IOEffectType                                                         */
/* Indicates the IO effect associated with an IO attack.                */
/* Used In:                                                             */
/*  IOEffect                                                            */
/************************************************************************/

enum class IOEffectType : KUINT8 {
  NoStatementIOEffectType = 0,
  Denial = 1,
  Degraded = 2,
  Disrupt = 3,
  OtherIOEffectType = 4,
  TerminateEffect = 5
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using
// GetEnumDescriptor<enum>. If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will
// be returned.
KDIS_EXPORT KUINT32 GetEnumSizeIOEffectType();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor* GetEnumDescriptorIOEffectType(KUINT32 Index);

KDIS_EXPORT KString GetEnumAsStringIOEffectType(KINT32 Value);

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringIOEffectType(const KString& Value,
                                                KINT32& ValueOut);

/************************************************************************/
/* IOReportType                                                         */
/* Indicates the the type of IO report.                                 */
/* Used In:                                                             */
/*  IO_Report_PDU                                                       */
/************************************************************************/

enum class IOReportType : KUINT8 {
  InitialReport = 1,
  UpdateReport = 2,
  FinalReport = 3
};

// Returns number of values in the EnumDescriptor for this enum.
// This can be used to iterate through all possible enum values by using
// GetEnumDescriptor<enum>. If KDIS_USE_ENUM_DESCRIPTORS is not set then 0 will
// be returned.
KDIS_EXPORT KUINT32 GetEnumSizeIOReportType();

// Returns the EnumDescriptor value for the specified index.
// Use GetEnumSize<enum> to get the array size.
// If KDIS_USE_ENUM_DESCRIPTORS is not set then NULL will be returned.
KDIS_EXPORT const EnumDescriptor* GetEnumDescriptorIOReportType(KUINT32 Index);

KDIS_EXPORT KString GetEnumAsStringIOReportType(KINT32 Value);

// Returns true if a value was found.
KDIS_EXPORT KBOOL GetEnumFromStringIOReportType(const KString& Value,
                                                KINT32& ValueOut);

}  // END namespace ENUMS
}  // namespace DATA_TYPE
}  // END namespace KDIS
