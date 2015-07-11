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
    class:      ModeSInterrogatorStatus
    DIS:        (7) 1278.1 - 2012
    created:    11/08/2015
    author:     Karl Jones

    purpose:    Indicates the status of an interrogator to interrogate Mode S.

    Size:       8 bits / 1 octet
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT ModeSInterrogatorStatus : public DataTypeBase
{
protected:
	
    union
    {
        struct
        {
            KUINT8 m_ui8OnOff    : 1;
			KUINT8 m_ui8Transmit : 3;
            KUINT8 m_ui8Dmg      : 1;
			KUINT8 m_ui8MalFnc   : 1;
			KUINT8 m_ui8Padding  : 2;
        };
        KUINT8 m_ui8Status;
    } m_StatusUnion;

public:

    static const KUINT16 MODE_S_INTERROGATOR_STATUS_SIZE = 1; 

    ModeSInterrogatorStatus();

    ModeSInterrogatorStatus( KDataStream & stream ) throw( KException );

	ModeSInterrogatorStatus( KBOOL OnOffStatus, KDIS::DATA_TYPE::ENUMS::ModeSInterrogatorStatusTransmitState TS,
		                     KBOOL Damaged, KBOOL Malfunction );

    virtual ~ModeSInterrogatorStatus();

	//************************************
	// FullName:    KDIS::DATA_TYPE::ModeSInterrogatorStatus::SetOnOffStatus
	//              KDIS::DATA_TYPE::ModeSInterrogatorStatus::GetOnOffStatus	
	// Description: Indicates whether the Mode S interrogation capability is On(true) or Off (false).
	// Parameter:   KBOOL OOS
	//************************************
	void SetOnOffStatus( KBOOL OOS );
	KBOOL GetOnOffStatus() const;
	
	//************************************
	// FullName:    KDIS::DATA_TYPE::ModeSInterrogatorStatus::SetOnOffStatus
	//              KDIS::DATA_TYPE::ModeSInterrogatorStatus::GetOnOffStatus	
	// Description: Indicates the state of the Mode S interrogator.
	// Parameter:   ModeSInterrogatorStatusTransmitState TS
	//************************************
	void SetTransmitState( KDIS::DATA_TYPE::ENUMS::ModeSInterrogatorStatusTransmitState TS );
	KDIS::DATA_TYPE::ENUMS::ModeSInterrogatorStatusTransmitState GetTransmitState() const;

	//************************************
	// FullName:    KDIS::DATA_TYPE::ModeSInterrogatorStatus::SetDamaged
	//              KDIS::DATA_TYPE::ModeSInterrogatorStatus::IsDamaged	
	// Description: Indicate whether there is damage to the Mode S interrogation capability.
	// Parameter:   KBOOL D - Damaged(true) / not damaged(false).
	//************************************
	void SetDamaged( KBOOL D );
	KBOOL IsDamaged() const;

	//************************************
	// FullName:    KDIS::DATA_TYPE::ModeSInterrogatorStatus::SetMalfunction
	//              KDIS::DATA_TYPE::ModeSInterrogatorStatus::HasMalfunction	
	// Description: Indicate whether there is a malfunction of the Mode s interrogation capability. 
	// Parameter:   KBOOL M - Malfunction(true) / No Malfunction(false).
	//************************************
	void SetMalfunction( KBOOL M );
	KBOOL HasMalfunction() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModeSInterrogatorStatus::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModeSInterrogatorStatus::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModeSInterrogatorStatus::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const ModeSInterrogatorStatus & Value ) const;
    KBOOL operator != ( const ModeSInterrogatorStatus & Value ) const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
