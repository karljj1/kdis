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
    class:      Reliability_Header
    DIS:        (6) 1278.1A - 1998
    created:    20:01:2009
    author:     Karl Jones

    purpose:    specifies the required level of reliability service to be
                used for a PDU.
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./../../KDefines.h"
#include "./../../DataTypes/Enums/KDISEnums.h"
#include "./../../KDataStream.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Reliability_Header
{
protected:

    KUINT8 m_ui8ReqRelSrv;

    KUINT16 m_ui16Padding1;

    KUINT8 m_ui8Padding;

public:

    static const KUINT16 RELIABILITY_SIZE = 4;

    Reliability_Header();

    Reliability_Header( KDataStream & stream ) throw( KException );

    Reliability_Header( KDIS::DATA_TYPE::ENUMS::RequiredReliabilityService RRS );

    virtual ~Reliability_Header();

    //************************************
    // FullName:    KDIS::PDU::Reliability_Header::SetRequiredReliabilityService
    //              KDIS::PDU::Reliability_Header::GetRequiredReliabilityService
    // Description: specifies the required level of reliability service to be
    //              used for this transaction/PDU.
    // Parameter:   RequiredReliabilityService RRS
    //************************************
    void SetRequiredReliabilityService( KDIS::DATA_TYPE::ENUMS::RequiredReliabilityService RRS );
    KDIS::DATA_TYPE::ENUMS::RequiredReliabilityService GetRequiredReliabilityService() const;

    //************************************
    // FullName:    KDIS::PDU::Reliability_Header::GetString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Reliability_Header::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Reliability_Header::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Reliability_Header & Value ) const;
    KBOOL operator != ( const Reliability_Header & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
