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
    class:      ModeSTransponderStatus
    DIS:        (7) 1278.1 - 2012
    created:    12/07/2015
    author:     Karl Jones

    purpose:    Mode S transponder status information. 

    Size:       16 bits / 2 octet
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT ModeSTransponderStatus : public DataTypeBase
{
protected:

	union
	{
		struct
		{
			KUINT16 m_ui161SquitterStatus : 1;
			KUINT16 m_ui16SquitterType    : 3;
			KUINT16 m_ui16SquitterRecSrc  : 1;
			KUINT16 m_ui16AirPosRptInd    : 1;
			KUINT16 m_ui16AirVelRptInd    : 1;
			KUINT16 m_ui16SurfPosRptInd   : 1;
			KUINT16 m_ui16IdRptInd        : 1;
			KUINT16 m_ui16EvtDrvRptInd    : 1;
			KUINT16 m_ui16Padding         : 3;
			KUINT16 m_ui16OnOff           : 1;
			KUINT16 m_ui16Dmg             : 1;
			KUINT16 m_ui16MalFnc          : 1;
		};
		KUINT16 m_ui16Status;
	} m_StatusUnion;
		
public:

    static const KUINT16 MODE_S_TRANSPONDER_STATUS_SIZE = 2; 

    ModeSTransponderStatus();

    ModeSTransponderStatus( KDataStream & stream ) throw( KException );

	ModeSTransponderStatus( KBOOL SquitterOn, KDIS::DATA_TYPE::ENUMS::ModeSSquitterType ST, KBOOL RecSrc, KBOOL AirPos, KBOOL AirVel, 
		                    KBOOL SurfPos, KBOOL Id, KBOOL EvntDrv, KBOOL Status, KBOOL Dmg, KBOOL Malfnc );
		
    virtual ~ModeSTransponderStatus();

	//************************************
	// FullName:    KDIS::DATA_TYPE::ModeSTransponderStatus::SetSquitterOn
	//              KDIS::DATA_TYPE::ModeSTransponderStatus::IsSquitterOn
	// Description: Indicates whether the squitter is On (true) or Off (false).
	// Parameter:   KBOOL S
	//************************************
	void SetSquitterOn( KBOOL S );
	KBOOL IsSquitterOn() const;

	//************************************
	// FullName:    KDIS::DATA_TYPE::ModeSTransponderStatus::SetSquitterType
	//              KDIS::DATA_TYPE::ModeSTransponderStatus::GetSquitterType
	// Description: The present Mode 5 transponder antenna selection.
	// Parameter:   KDIS::DATA_TYPE::ENUMS::ModeSSquitterType ST
	//************************************
	void SetSquitterType( KDIS::DATA_TYPE::ENUMS::ModeSSquitterType ST );
	KDIS::DATA_TYPE::ENUMS::ModeSSquitterType GetSquitterType() const;

	//************************************
	// FullName:    KDIS::DATA_TYPE::ModeSTransponderStatus::SetSquitterRecordSource
	//              KDIS::DATA_TYPE::ModeSTransponderStatus::GetSquitterRecordSource
	// Description: Indicates whether the squitter records are only present as Layer 4 IFF Data Records(false) 
	//              or are also included as Layer 5 GICB IFF Data Records(true).
	// Parameter:   KBOOL RS
	//************************************
	void SetSquitterRecordSource( KBOOL RS );
	KBOOL GetSquitterRecordSource() const;

	//************************************
	// FullName:    KDIS::DATA_TYPE::ModeSTransponderStatus::SetAirbornePositionReportIndicator
	//              KDIS::DATA_TYPE::ModeSTransponderStatus::GetAirbornePositionReportIndicator
	// Description: Indicates whether there is a Airborne Position Report IFF Data Record Present.
	// Parameter:   KBOOL RI
	//************************************
	void SetAirbornePositionReportIndicator( KBOOL RI );
	KBOOL GetAirbornePositionReportIndicator() const;

	//************************************
	// FullName:    KDIS::DATA_TYPE::ModeSTransponderStatus::SetAirborneVelocityReportIndicator
	//              KDIS::DATA_TYPE::ModeSTransponderStatus::GetAirborneVelocityReportIndicator
	// Description: Indicates whether there is a Airborne Velocity Report IFF Data Record Present.
	// Parameter:   KBOOL RI
	//************************************
	void SetAirborneVelocityReportIndicator( KBOOL RI );
	KBOOL GetAirborneVelocityReportIndicator() const;

	//************************************
	// FullName:    KDIS::DATA_TYPE::ModeSTransponderStatus::SetSurfacePositionReportIndicator
	//              KDIS::DATA_TYPE::ModeSTransponderStatus::GetSurfacePositionReportIndicator
	// Description: Indicates whether there is a Surface Position Report IFF Data Record Present.
	// Parameter:   KBOOL RI
	//************************************
	void SetSurfacePositionReportIndicator( KBOOL RI );
	KBOOL GetSurfacePositionReportIndicator() const;

	//************************************
	// FullName:    KDIS::DATA_TYPE::ModeSTransponderStatus::SetIdentificationReportIndicator
	//              KDIS::DATA_TYPE::ModeSTransponderStatus::GetIdentificationReportIndicator
	// Description: Indicates whether there is a Id Report IFF Data Record Present.
	// Parameter:   KBOOL RI
	//************************************
	void SetIdentificationReportIndicator( KBOOL RI );
	KBOOL GetIdentificationReportIndicator() const;

	//************************************
	// FullName:    KDIS::DATA_TYPE::ModeSTransponderStatus::SetEventDrivenReportIndicator
	//              KDIS::DATA_TYPE::ModeSTransponderStatus::GetEventDrivenReportIndicator
	// Description: Indicates whether there is a Event-Driven Report IFF Data Record Present.
	// Parameter:   KBOOL RI
	//************************************
	void SetEventDrivenReportIndicator( KBOOL RI );
	KBOOL GetEventDrivenReportIndicator() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::ModeSTransponderStatus::SetStatus
    //              KDIS::DATA_TYPE::ModeSTransponderStatus::GetStatus
    // Description: Indicates whether the Mode S transponder is On (true or Off (false).
    // Parameter:   KBOOL S
    //************************************
	void SetStatus( KBOOL S );
	KBOOL GetStatus() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::ModeSTransponderStatus::SetDamaged
    //              KDIS::DATA_TYPE::ModeSTransponderStatus::IsDamaged
    // Description: Indicates whether there is damage to the Mode S transponder.
    // Parameter:   KBOOL S
    //************************************
	void SetDamaged( KBOOL D );
	KBOOL IsDamaged() const;
		
	//************************************
    // FullName:    KDIS::DATA_TYPE::ModeSTransponderStatus::SetMalfunctioning
    //              KDIS::DATA_TYPE::ModeSTransponderStatus::IsMalfunctioning
    // Description: Indicates whether there is damage to the Mode S transponder.
    // Parameter:   KBOOL M
    //************************************
	void SetMalfunctioning( KBOOL M );
	KBOOL IsMalfunctioning() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModeSTransponderStatus::GetAsString
    // Description: Returns a string representation 
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModeSTransponderStatus::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModeSTransponderStatus::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const ModeSTransponderStatus & Value ) const;
    KBOOL operator != ( const ModeSTransponderStatus & Value ) const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
