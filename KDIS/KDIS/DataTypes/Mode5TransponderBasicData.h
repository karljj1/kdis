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
    class:      Mode5TransponderBasicData
    DIS:        (7) 1278.1 - 2012
    created:    10/05/2014
    author:     Karl Jones

    purpose:    Included in the Mode 5 Transponder format for Layer 3 of the IFF PDU.

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

class KDIS_EXPORT Mode5TransponderBasicData : public DataTypeBase
{
protected:

    Mode5TransponderStatus m_Status;

    KUINT16 m_ui16PIN;

    KUINT32 m_ui32MsgFormats;

    EnhancedMode1Code m_EM1Code;

    KUINT16 m_ui16NationalOrigin;

    Mode5TransponderSupplementalData m_SupplementalData;

    KUINT8 m_ui8NavSrc;

    KUINT8 m_ui8FigMerit;

    KUINT8 m_ui8Padding;

public:

    static const KUINT16 MODE_5_TRANSPONDER_BASIC_DATA_SIZE = 16;

    Mode5TransponderBasicData();

    Mode5TransponderBasicData( const Mode5TransponderStatus & S, KUINT16 PersonalIdentificationNumber, KUINT32 MsgFormats,
                               const EnhancedMode1Code & EMC1, KUINT16 NationalOrigin, Mode5TransponderSupplementalData SD,
                               KDIS::DATA_TYPE::ENUMS::NavigationSource NS, KUINT8 FigureOfMerit );

    Mode5TransponderBasicData( KDataStream & stream ) throw( KException );

    virtual ~Mode5TransponderBasicData();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderBasicData::SetStatus
    //              KDIS::DATA_TYPE::Mode5TransponderBasicData::GetStatus
    // Description: The Mode 5 Message Formats supported by this Mode 5 transponder.
    // Parameter:   const InterrogatorStatus & S
    //************************************
    void SetStatus( const Mode5TransponderStatus & S );
    const Mode5TransponderStatus & GetStatus() const;
    Mode5TransponderStatus & GetStatus();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderBasicData::SetPersonalIdentificationNumber
    //              KDIS::DATA_TYPE::Mode5TransponderBasicData::GetPersonalIdentificationNumber
    // Description: Uniquely identifies the platform carrying this Mode 5 transponder.
    //              Should be a number in the range 00 000 octal to 37 777 octal.
    // Parameter:   KUINT16 PIN
    //************************************
    void SetPersonalIdentificationNumber( KUINT16 PIN );
    KUINT16 GetPersonalIdentificationNumber() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderBasicData::SetMessageFormatsPresent
    //              KDIS::DATA_TYPE::Mode5TransponderBasicData::GetMessageFormatsPresentBitSet
    //              KDIS::DATA_TYPE::Mode5TransponderBasicData::GetMessageFormatsPresent
    // Description:	When a Mode 5 transponder is in the Regeneration Mode, the included message
    //              formats shall be those that this Mode 5 transponder is capable of supporting
    //              and could be in a reply to a Mode 5 interrogation.
    //              The Message Formats Status field of the Mode 5 Transponder Status record
    //              is set to Capability (0) in this case. When a Mode 5 transponder is in the
    //              Interactive Mode, the requirements specified in Interactive Basic Mode 5 IFF
    //              Data record are applicable.
    // Parameter:   KUINT32 MFP, const std::bitset<32> & MFP
    //************************************
    void SetMessageFormatsPresent( KUINT32 MFP );
    void SetMessageFormatsPresent( const std::bitset<32> & MFP );
    const std::bitset<32> GetMessageFormatsPresentBitSet() const;
    KUINT32 GetMessageFormatsPresent();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderBasicData::SetEnhancedMode1Code
    //              KDIS::DATA_TYPE::Mode5TransponderBasicData::GetEnhancedMode1Code
    // Description: Mode 5 Enhanced Mode 1 information.
    // Parameter:   const EnhancedMode1Code & EMC1
    //************************************
    void SetEnhancedMode1Code( const EnhancedMode1Code & EMC1 );
    const EnhancedMode1Code & GetEnhancedMode1Code() const;
    EnhancedMode1Code & GetEnhancedMode1Code();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderBasicData::SetNationalOrigin
    //              KDIS::DATA_TYPE::Mode5TransponderBasicData::GetNationalOrigin
    // Description: The national origin is the country that owns the platform
    //              carrying a Mode 5 transponder. NOTE—The National Origin is
    //              not the same as the Country field enumerations contained in Entity Type
    //              records. For simulations that have modeled Mode 5 (e.g., Mark XIIA)
    //              transponders based on the original AIMS 03-1000, the AIMS 03-1000A
    //              standard contains instructions on how to set separate National Origin and
    //              Mission Code values to equate tothe present National Origin field.
    // Parameter:   KUINT16 NO
    //************************************
    void SetNationalOrigin( KUINT16 NO );
    KUINT16 GetNationalOrigin() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderBasicData::SetSupplementalData
    //              KDIS::DATA_TYPE::Mode5TransponderBasicData::GetSupplementalData
    // Description: Supplemental data for a Mode 5 transponder.
    // Parameter:   Mode5TransponderSupplementalData SD
    //************************************
    void SetSupplementalData( Mode5TransponderSupplementalData SD );
    Mode5TransponderSupplementalData GetSupplementalData() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderBasicData::SetNavigationSource
    //              KDIS::DATA_TYPE::Mode5TransponderBasicData::GetNavigationSource
    // Description: Navigation source for this transponder.
    // Parameter:   KDIS::DATA_TYPE::ENUMS::NavigationSource NS
    //************************************
    void SetNavigationSource( KDIS::DATA_TYPE::ENUMS::NavigationSource NS );
    KDIS::DATA_TYPE::ENUMS::NavigationSource GetNavigationSource() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderBasicData::SetFigureOfMerit
    //              KDIS::DATA_TYPE::Mode5TransponderBasicData::GetFigureOfMerit
    // Description: The figure of merit is a quantity used to characterize the performance of the device.
    //              Valid values 0-31 else INVALID_DATA exception thrown.
    // Parameter:   KUINT8 FOM
    //************************************
    void SetFigureOfMerit( KUINT8 FOM ) throw( KException );
    KUINT8 GetFigureOfMerit() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderBasicData::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderBasicData::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5TransponderBasicData::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Mode5TransponderBasicData & Value ) const;
    KBOOL operator != ( const Mode5TransponderBasicData & Value ) const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
