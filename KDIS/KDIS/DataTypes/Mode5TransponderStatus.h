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

	// TODO: YOU ARE HERE
	// TODO: NEXT enum for antenna selection

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
			KUINT16 m_ui16OnOffStatus  : 1;
			KUINT16 m_ui16DmgStatus    : 1;
			KUINT16 m_ui16MalfncStatus : 1;
		};
		KUINT16 m_ui16Status;

	} m_StatusUnion;
		
public:

    static const KUINT16 MODE_5_TRANSPONDER_STATUS_SIZE = 2; 

    Mode5TransponderStatus();

    Mode5TransponderStatus( KDataStream & stream ) throw( KException );

	/*Mode5TransponderStatus( KUINT8 IFFMission, KDIS::DATA_TYPE::ENUMS::Mode5MessageFormat MF, 
                             KBOOL OnOffStatus, KBOOL Damaged, KBOOL Malfunction );
*/
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
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderStatus::SetLineTest
    //              KDIS::DATA_TYPE::Mode5TransponderStatus::GetLineTest
    // Description: Indicates whether a line test is in progress(true) or not(false).
    // Parameter:   KBOOL LT 
    //************************************
	void SetLineTest( KBOOL LT ) throw( KException );
	KBOOL GetLineTest() const;

	
    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderStatus::GetAsString
    // Description: Returns a string representation of the PDU.
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
