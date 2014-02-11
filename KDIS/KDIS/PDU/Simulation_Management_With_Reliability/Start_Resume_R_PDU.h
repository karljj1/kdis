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
    class:      Start_Resume_R_PDU
    DIS:        (6) 1278.1A - 1998
    created:    21:03:2009
    author:     Karl Jones

    purpose:    Indicates a start resume status to the entity/exercise
    size:       384 bits / 48 octets
*********************************************************************/

#pragma once

#include "./../Simulation_Management/Start_Resume_PDU.h"
#include "./Reliability_Header.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Start_Resume_R_PDU : public Start_Resume_PDU,
                                       public Reliability_Header
{
public:

    static const KUINT16 START_RESUME_R_PDU_SIZE = 48;

    Start_Resume_R_PDU();

    Start_Resume_R_PDU( KDataStream & stream ) throw( KException );

	Start_Resume_R_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Start_Resume_R_PDU( const KDIS::DATA_TYPE::EntityIdentifier & ReceivingEntity, const KDIS::DATA_TYPE::EntityIdentifier & SupplyingEntity, const KDIS::DATA_TYPE::ClockTime & RealWorldTime,
		const KDIS::DATA_TYPE::ClockTime & SimTime, KUINT32 ReqID, KDIS::DATA_TYPE::ENUMS::RequiredReliabilityService RRS );

    Start_Resume_R_PDU( const Simulation_Management_Header & SimMgrHeader, const KDIS::DATA_TYPE::ClockTime & RealWorldTime,
		const KDIS::DATA_TYPE::ClockTime & SimTime, KUINT32 ReqID, KDIS::DATA_TYPE::ENUMS::RequiredReliabilityService RRS  );

    virtual ~Start_Resume_R_PDU();

    //************************************
    // FullName:    KDIS::PDU::Start_Resume_R_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Start_Resume_R_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Start_Resume_R_PDU::Encode
    // Description: Convert To Network Data.
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Start_Resume_R_PDU & Value ) const;
    KBOOL operator != ( const Start_Resume_R_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
