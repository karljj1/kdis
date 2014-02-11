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
	EnumLink16
	created:	23/10/2008
	author:		Karl Jones

	purpose:	Enums for Link16 simulations
*********************************************************************/

#pragma once

#include "KDIS/DataTypes/Enums/EnumDescriptor.h"

namespace KDIS {
namespace DATA_TYPE {
namespace ENUMS {
namespace LINK16 {

/************************************************************************/
/* Time Slot Allocation Mode											*/
/* Used In:																*/
/*	Link16_Transmitter_PDU												*/
/************************************************************************/

enum TimeSlotAllocationMode
{
	TSA0															  = 0,
	TSA1															  = 1,
	TSA2															  = 2,
	TSA3															  = 3,
	TSA4															  = 4
};

KString GetEnumAsStringTimeSlotAllocationMode( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringTimeSlotAllocationMode( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Transmitting Terminal Primary Mode									*/
/* Primary mode of operation of the transmitting terminal.				*/
/* Used In:																*/
/*	Link16_Transmitter_PDU												*/
/************************************************************************/

enum TransmittingTerminalPrimaryMode
{
	NTR																  = 1,
	JTIDS_Unit_Participant											  = 2
};

KString GetEnumAsStringTransmittingTerminalPrimaryMode( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringTransmittingTerminalPrimaryMode( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Transmitting Terminal Secondary Mode									*/
/* Secondary mode of operation of the transmitting terminal.			*/
/* Used In:																*/
/*	Link16_Transmitter_PDU												*/
/************************************************************************/

enum TransmittingTerminalSecondaryMode
{
	NoTransmittingTerminalSecondaryMode								  = 0,
	NetPositionReference											  = 1,
	PrimaryNavigationController										  = 2,
	SecondaryNavigationController									  = 3
};

KString GetEnumAsStringTransmittingTerminalSecondaryMode( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringTransmittingTerminalSecondaryMode( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Synchronization State												*/
/* Used In:																*/
/*	Link16_Transmitter_PDU												*/
/************************************************************************/

enum SynchronizationState
{
	CoarseSynchronization											  = 0,
	FineSynchronization												  = 1
};

KString GetEnumAsStringSynchronizationState( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringSynchronizationState( const KString & Value, KINT32 & ValueOut ); 

/************************************************************************/
/* Link 16 Message Type													*/
/* Used In:																*/
/*	Link16_Signal_PDU													*/
/************************************************************************/

enum Link16MessageType
{
	JTIDS_Header_Messages										      = 0,
	RTT_A_B															  = 1,
	RTT_Reply														  = 2,
	JTIDS_Voice_CVSD												  = 3,
	JTIDS_Voice_LPC10												  = 4,
	JTIDS_Voice_LPC12												  = 5,
	JTIDS_LET														  = 6,
	VMF																  = 7
};

KString GetEnumAsStringLink16MessageType( KINT32 Value );

// Returns true if a value was found.
KBOOL GetEnumFromStringLink16MessageType( const KString & Value, KINT32 & ValueOut ); 

} // END namespace ENUMS
} // END namespace DATA_TYPES
} // END namespace KDIS
} // END namespace LINK16