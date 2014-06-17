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
    class:      Mode5TransponderSupplementalData
    DIS:        (7) 1278.1 - 2012
    created:    23/05/2014
    author:     Karl Jones

    purpose:    Provides supplemental data related to a Mode 5 transponder.

    Size:       8 bits / 1 octet
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT Mode5TransponderSupplementalData : public DataTypeBase
{
protected:
	
	union
	{
		struct
		{
			KUINT8 m_ui8SquitterStatus     : 1;
			KUINT8 m_ui8Lvl2SquitterStatus : 1;
			KUINT8 m_ui8IFFMission         : 3;
			KUINT8 m_ui8Padding            : 3;

		};
		KUINT8 m_ui8SupplementalData;
	} m_SupplementalDataUnion;

public:

    static const KUINT16 MODE_5_TRANSPONDER_SUPPLEMENTAL_DATA_SIZE = 1; 

    Mode5TransponderSupplementalData();

	Mode5TransponderSupplementalData( KBOOL Squitter, KBOOL Lvl2Squitter, KUINT8 IFFMission ) throw( KException );

    Mode5TransponderSupplementalData( KDataStream & stream ) throw( KException );

    virtual ~Mode5TransponderSupplementalData();

	//************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderSupplementalData::SetSquitter
    //              KDIS::DATA_TYPE::Mode5TransponderSupplementalData::GetHasAntiHandlingDevice
    // Description: Indicates if the Mode 5 squitter is On(true) or Off(false).
    // Parameter:   KBOOL S
    //************************************
    void SetSquitter( KBOOL S );
    KBOOL GetSquitter() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderSupplementalData::vel2Squitter(
    //              KDIS::DATA_TYPE::Mode5TransponderSupplementalData::GetLevel2Squitter
    // Description: Indicates if the Level 2 Mode 5 squitter Enabled(true) or Disabled(false).
    // Parameter:   KBOOL L2S
    //************************************
	void SetLevel2Squitter( KBOOL L2S );
    KBOOL GetLevel2Squitter() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderSupplementalData::SetIFFMission
    //              KDIS::DATA_TYPE::Mode5TransponderSupplementalData::GetIFFMission
    // Description: Identifies the IFF mission of this Mode 5 transponder. 
	//              Throws DATA_TYPE_TOO_LARGE exception if value is greater than 7.
    // Parameter:   KUINT8 IFFM 
    //************************************
	void SetIFFMission( KUINT8 IFFM ) throw( KException );
    KUINT8 GetIFFMission() const;
	
	//************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderSupplementalData::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderSupplementalData::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderSupplementalData::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Mode5TransponderSupplementalData & Value ) const;
    KBOOL operator != ( const Mode5TransponderSupplementalData & Value ) const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
