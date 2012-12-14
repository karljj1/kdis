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

}; // END namespace ENUMS
}; // END namespace DATA_TYPES
}; // END namespace KDIS
}; // END namespace LINK16