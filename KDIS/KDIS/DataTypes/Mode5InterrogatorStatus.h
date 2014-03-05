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
    class:      Mode5InterrogatorStatus
    DIS:        (7) 1278.1 - 2012
    created:    30/09/2013
    author:     Karl Jones

    purpose:    Provides Mode 5 interrogator information.
	            Knowledge of AIMS 03-1000A, and specific interrogator model specifications are
                required to properly implement these fields.

    Size:       8 bits / 1 octet
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT Mode5InterrogatorStatus : public DataTypeBase
{
protected:
		
    union
    {
        struct
        {
            KUINT8 m_ui8IffMis  : 3;
			KUINT8 m_ui8MsgFrmt : 1;
            KUINT8 m_ui8Padding : 1;
			KUINT8 m_ui8OnOff   : 1;
			KUINT8 m_ui8Dmg     : 1;
			KUINT8 m_ui8MalFnc  : 1;
        };
        KUINT8 m_ui8Status;
    } m_StatusUnion;

public:

    static const KUINT16 MODE_5_INTERROGATOR_STATUS_SIZE = 1; 

    Mode5InterrogatorStatus();

    Mode5InterrogatorStatus( KDataStream & stream ) throw( KException );

	Mode5InterrogatorStatus( KUINT8 IFFMission, KDIS::DATA_TYPE::ENUMS::Mode5MessageFormat MF, 
                             KBOOL OnOffStatus, KBOOL Damaged, KBOOL Malfunction );

    virtual ~Mode5InterrogatorStatus();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5InterrogatorStatus::SetIFFMission
    //              KDIS::DATA_TYPE::Mode5InterrogatorStatus::GetIFFMIssion
    // Description: 3 bit enum field used to identify the IFF mission of this Mode 5 interrogator.
	//              Refer to AIMS 03-1000A to determine the applicable IFF mission.
    // Parameter:   KUINT8 IFFM	- Exception thrown if greater than 7.
    //************************************
	void SetIFFMission( KUINT8 IFFM ) throw( KException );
	KUINT8 GetIFFMIssion() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5InterrogatorStatus::SetMode5MessageFormat
    //              KDIS::DATA_TYPE::Mode5InterrogatorStatus::GetMode5MessageFormat	
    // Description: Indicates whether the Mode 5 Message Formats record is a Capability or 
	//              an Active Interrogation.
    // Parameter:   KDIS::DATA_TYPE::ENUMS::Mode5MessageFormat MF
    //************************************
	void SetMode5MessageFormat( KDIS::DATA_TYPE::ENUMS::Mode5MessageFormat MF );
	KDIS::DATA_TYPE::ENUMS::Mode5MessageFormat GetMode5MessageFormat() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::Mode5InterrogatorStatus::SetOnOffStatus
    //              KDIS::DATA_TYPE::Mode5InterrogatorStatus::GetOnOffStatus	
    // Description: Indicates whether the Mode 5 interrogation capability is On(true) or Off (false).
    // Parameter:   KBOOL OOS
    //************************************
	void SetOnOffStatus( KBOOL OOS );
	KBOOL GetOnOffStatus() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::Mode5InterrogatorStatus::SetDamaged
    //              KDIS::DATA_TYPE::Mode5InterrogatorStatus::IsDamaged	
    // Description: Indicate whether there is damage to the Mode 5 interrogation capability.
	// Parameter:   KBOOL D - Damaged(true) / not damaged(false).
    //************************************
	void SetDamaged( KBOOL D );
	KBOOL IsDamaged() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::Mode5InterrogatorStatus::SetMalfunction
    //              KDIS::DATA_TYPE::Mode5InterrogatorStatus::HasMalfunction	
    // Description: Indicate whether there is a malfunction of the Mode 5 interrogation capability. 
	// Parameter:   KBOOL M - Malfunction(true) / No Malfunction(false).
    //************************************
	void SetMalfunction( KBOOL M );
	KBOOL HasMalfunction() const;
	
    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5InterrogatorStatus::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5InterrogatorStatus::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5InterrogatorStatus::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Mode5InterrogatorStatus & Value ) const;
    KBOOL operator != ( const Mode5InterrogatorStatus & Value ) const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
