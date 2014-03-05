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
    class:      Mode5TransponderStatus
    DIS:        (7) 1278.1 - 2012
    created:    3/03/2014
    author:     Karl Jones

    purpose:    

    Size:       16 bits / 2 octet
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT Mode5TransponderStatus : public DataTypeBase
{
protected:

	union
	{
		struct
		{
			KUINT16 m_ui16Reply        : 4;
			KUINT16 m_ui16LineTst      : 1;
			KUINT16 m_ui16AntennaSel   : 2;
			KUINT16 m_ui16CryptoCtrl   : 1;
			KUINT16 m_ui16LatLonAltSrc : 1;
			KUINT16 m_ui16LocErrs      : 1;
			KUINT16 m_ui16PlatfrmTyp   : 1;
			KUINT16 m_ui16LvlSel       : 1;
			KUINT16 m_ui16Padding      : 1;
			KUINT16 m_ui16OnOff        : 1;
			KUINT16 m_ui16Dmg          : 1;
			KUINT16 m_ui16MalFnc       : 1;
		};
		KUINT16 m_ui16Status;

	} m_StatusUnion;
		
public:

    static const KUINT16 MODE_5_TRANSPONDER_STATUS_SIZE = 2; 

    Mode5TransponderStatus();

    Mode5TransponderStatus( KDataStream & stream ) throw( KException );

	Mode5TransponderStatus( KDIS::DATA_TYPE::ENUMS::Mode5Reply R, KBOOL LineTest, KDIS::DATA_TYPE::ENUMS::AntennaSelection AS, KBOOL Crypto,
	                        KBOOL LocationIncluded, KBOOL LocationErrorIncluded, KDIS::DATA_TYPE::ENUMS::PlatformType PT, KBOOL Lvl2Included,
                            KBOOL Status, KBOOL Dmg, KBOOL Malfnc );
	
    virtual ~Mode5TransponderStatus();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderStatus::SetReply
    //              KDIS::DATA_TYPE::Mode5TransponderStatus::GetReply
    // Description: Specifies the validity of a reply that would be transmitted 
	//              by a Mode 5 transponder if interrogated.
    // Parameter:   KDIS::DATA_TYPE::ENUMS::Mode5Reply R
    //************************************
	void SetReply( KDIS::DATA_TYPE::ENUMS::Mode5Reply R );
	KDIS::DATA_TYPE::ENUMS::Mode5Reply GetReply() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderStatus::SetLineTestInProgress
    //              KDIS::DATA_TYPE::Mode5TransponderStatus::IsLineTestInProgress
    // Description: Indicates whether a line test is in progress(true) or not(false).
    // Parameter:   KBOOL LT 
    //************************************
	void SetLineTestInProgress( KBOOL LT );
	KBOOL IsLineTestInProgress() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderStatus::SetAntennaSelection
    //              KDIS::DATA_TYPE::Mode5TransponderStatus::GetAntennaSelection
    // Description: The present Mode 5 transponder antenna selection.
    // Parameter:   KDIS::DATA_TYPE::ENUMS::AntennaSelection AS
    //************************************
	void SetAntennaSelection( KDIS::DATA_TYPE::ENUMS::AntennaSelection AS );
	KDIS::DATA_TYPE::ENUMS::AntennaSelection GetAntennaSelection() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderStatus::SetCryptoControlPresent
    //              KDIS::DATA_TYPE::Mode5TransponderStatus::IsCryptoControlPresent
    // Description: Indicate whether the Crypto Control IFF Data record is
	//              included to indicate that pseudo crypto control is present.
    // Parameter:   KBOOL CC
    //************************************
	void SetCryptoControlPresent( KBOOL CC );
	KBOOL IsCryptoControlPresent() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderStatus::SetLocationRecordPresent
    //              KDIS::DATA_TYPE::Mode5TransponderStatus::IsLocationRecordPresent
    // Description: Indicates the source of Mode 5 latitude, longitude, and altitude information. 
	//              Set to Compute Locally (false) or to Mode 5 Transponder Location IFF 
	//              Record Present (true).
    // Parameter:   KBOOL LRP
    //************************************
	void SetLocationRecordPresent( KBOOL LRP );
	KBOOL IsLocationRecordPresent() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderStatus::SetLocationErrorRecordPresent
    //              KDIS::DATA_TYPE::Mode5TransponderStatus::IsLocationErrorRecordPresent
    // Description: Indicates whether there are location errors associated with Mode 5 latitude, 
	//              longitude, or altitude.
	//              Set to No Location Errors (false) or to Transponder Location Error IFF Data 
    //              Record Present(true).
    // Parameter:   KBOOL LERP  
    //************************************
	void SetLocationErrorRecordPresent( KBOOL LERP );
	KBOOL IsLocationErrorRecordPresent() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderStatus::SetPlatformType
    //              KDIS::DATA_TYPE::Mode5TransponderStatus::GetPlatformType
    // Description: Indicate the type of platform (air or ground) that is associated 
	//              this Mode 5 transponder. 
	//              Set as follows:
	//              1) Ground Vehicle (0) if the Entity Type record, Domain field is 
	//              Land (1) regardless of whether the entity is actually a land vehicle or
	//				some other type of land platform.
	//				2) Air Vehicle (1) if the Entity Type record, Domain field is Air (2)
	//				regardless of whether the entity is actually an aircraft or some other 
	//				type of air platform (e.g., a blimp).
    // Parameter:   PlatformType PT
    //************************************	
	void SetPlatformType( KDIS::DATA_TYPE::ENUMS::PlatformType PT );
	KDIS::DATA_TYPE::ENUMS::PlatformType GetPlatformType() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderStatus::SetMode5Level2Included
    //              KDIS::DATA_TYPE::Mode5TransponderStatus::IsMode5Level2Included
    // Description: Indicates whether Mode 5 Level 1 (false) or Mode 5 Level 2 (true) is 
	//              currently selected for this Mode 5 transponder. (The Level 2 selection
	//              includes both Level 1 and Level 2 message formats.)
    // Parameter:   KBOOL M
    //************************************
	void SetMode5Level2Included( KBOOL M );
	KBOOL IsMode5Level2Included() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderStatus::SetStatus
    //              KDIS::DATA_TYPE::Mode5TransponderStatus::GetStatus
    // Description: Indicates whether the Mode 5 transponder is On (true or Off (false).
    // Parameter:   KBOOL S
    //************************************
	void SetStatus( KBOOL S );
	KBOOL GetStatus() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderStatus::SetDamaged
    //              KDIS::DATA_TYPE::Mode5TransponderStatus::IsDamaged
    // Description: Indicates whether there is damage to the Mode 5 transponder.
    // Parameter:   KBOOL S
    //************************************
	void SetDamaged( KBOOL D );
	KBOOL IsDamaged() const;
		
	//************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderStatus::SetMalfunctioning
    //              KDIS::DATA_TYPE::Mode5TransponderStatus::IsMalfunctioning
    // Description: Indicates whether there is damage to the Mode 5 transponder.
    // Parameter:   KBOOL M
    //************************************
	void SetMalfunctioning( KBOOL M );
	KBOOL IsMalfunctioning() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderStatus::GetAsString
    // Description: Returns a string representation 
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderStatus::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderStatus::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Mode5TransponderStatus & Value ) const;
    KBOOL operator != ( const Mode5TransponderStatus & Value ) const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
