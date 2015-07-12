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

    purpose:    

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
			KUINT16 m_ui16IdPosRptInd     : 1;
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

	//ModeSTransponderStatus( KDIS::DATA_TYPE::ENUMS::Mode5Reply R, KBOOL LineTest, KDIS::DATA_TYPE::ENUMS::AntennaSelection AS, KBOOL Crypto,
	  //                      KBOOL LocationIncluded, KBOOL LocationErrorIncluded, KDIS::DATA_TYPE::ENUMS::PlatformType PT, KBOOL Lvl2Included,
        //                    KBOOL Status, KBOOL Dmg, KBOOL Malfnc );
	
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
