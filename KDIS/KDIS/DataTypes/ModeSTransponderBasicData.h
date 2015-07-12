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
    class:      ModeSTransponderBasicData
    DIS:        (7) 1278.1 - 2012
    created:    12/07/2015
    author:     Karl Jones

    purpose:    Included in the Mode S Transponder format for Layer 4 of the IFF PDU.

    Size:       128 bits / 16 octets 
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./EntityIdentifier.h"
#include "./Mode5TransponderStatus.h"
#include "./EnhancedMode1Code.h" 
#include "./Mode5TransponderSupplementalData.h"
#include <bitset>

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT ModeSTransponderBasicData : public DataTypeBase
{
protected:
/*
	Mode5TransponderStatus m_Status;

	KUINT16 m_ui16PIN;

	KUINT32 m_ui32MsgFormats;

	EnhancedMode1Code m_EM1Code;

	KUINT16 m_ui16NationalOrigin;

	Mode5TransponderSupplementalData m_SupplementalData;

	KUINT8 m_ui8NavSrc;

	KUINT8 m_ui8FigMerit;

	KUINT8 m_ui8Padding;
*/
public:

    static const KUINT16 MODE_5_TRANSPONDER_BASIC_DATA_SIZE = 16; 

    ModeSTransponderBasicData();

	//ModeSTransponderBasicData( const Mode5TransponderStatus & S, KUINT16 PersonalIdentificationNumber, KUINT32 MsgFormats,
	//	                       const EnhancedMode1Code & EMC1, KUINT16 NationalOrigin, Mode5TransponderSupplementalData SD,
	//						   KDIS::DATA_TYPE::ENUMS::NavigationSource NS, KUINT8 FigureOfMerit );

    ModeSTransponderBasicData( KDataStream & stream ) throw( KException );

    virtual ~ModeSTransponderBasicData();

	//************************************
    // FullName:    KDIS::DATA_TYPE::ModeSTransponderBasicData::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModeSTransponderBasicData::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModeSTransponderBasicData::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const ModeSTransponderBasicData & Value ) const;
    KBOOL operator != ( const ModeSTransponderBasicData & Value ) const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
