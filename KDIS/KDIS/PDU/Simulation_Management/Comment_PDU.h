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

/*********************************************************************
    class:      Comment_PDU
    DIS:        (5) 1278.1 - 1995
    created:    08/10/2008
    author:     Karl Jones

    purpose:    Arbitrary message (E.G char strings) shall be entered into the data
                stream by using a comment PDU. For use as comment, test message, error etc.
    size:       256 bits/ 32 octets - not including fix and var datum sizes
*********************************************************************/

#pragma once

#include "./Simulation_Management_Header.h"
#include "./../../DataTypes/FixedDatum.h"
#include "./../../DataTypes/VariableDatum.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::FixedDatum;
using KDIS::DATA_TYPE::FixDtmPtr;
using KDIS::DATA_TYPE::VariableDatum;
using KDIS::DATA_TYPE::VarDtmPtr;
using std::vector;

class KDIS_EXPORT Comment_PDU : public Simulation_Management_Header
{
protected:

    KUINT32 m_ui32NumFixedDatum;

    KUINT32 m_ui32NumVariableDatum;

	std::vector<KDIS::DATA_TYPE::FixDtmPtr> m_vFixedDatum;

	std::vector<KDIS::DATA_TYPE::VarDtmPtr> m_vVariableDatum;

public:

    static const KUINT16 COMMENT_PDU_SIZE = 32; // Min size

    Comment_PDU();

	Comment_PDU( const Header & H );

    Comment_PDU( KDataStream & stream ) throw( KException );

	Comment_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Comment_PDU( const KDIS::DATA_TYPE::EntityIdentifier & OriginatingEntityID, const KDIS::DATA_TYPE::EntityIdentifier & ReceivingEntityID );

    virtual ~Comment_PDU();

    //************************************
    // FullName:    KDIS::PDU::Comment_PDU::GetNumberFIxedDatum
    // Description: Returns number of fixed datum records
    //************************************
    KUINT32 GetNumberFIxedDatum() const;

    //************************************
    // FullName:    KDIS::PDU::Comment_PDU::GetNumberVariableDatum
    // Description: Returns number of variable datum records
    //************************************
    KUINT32 GetNumberVariableDatum() const;

    //************************************
    // FullName:    KDIS::PDU::Comment_PDU::AddFixedDatum
    //              KDIS::PDU::Comment_PDU::SetFixedDatum
    //              KDIS::PDU::Comment_PDU::GetFixedDatum
    // Description: Add, get fixed datums
    // Parameter:   FixedDatum FD, const vector<FixDtmPtr> & FD
    //************************************
    void AddFixedDatum( KDIS::DATA_TYPE::FixDtmPtr FD );
	void SetFixedDatum( const std::vector<KDIS::DATA_TYPE::FixDtmPtr> & FD );
	const std::vector<FixDtmPtr> & GetFixedDatum() const;

    //************************************
    // FullName:    KDIS::PDU::Comment_PDU::AddVariableDatum
    //              KDIS::PDU::Comment_PDU::SetVariableDatum
    //              KDIS::PDU::Comment_PDU::GetVariableDatum
    // Description: Add, get variable datums
    // Parameter:   VarDtmPtr VD, const vector<VarDtmPtr> & VD
    //************************************
    void AddVariableDatum( KDIS::DATA_TYPE::VarDtmPtr VD );
	void SetVariableDatum( const std::vector<KDIS::DATA_TYPE::VarDtmPtr> & VD );
	const std::vector<VarDtmPtr> & GetVariableDatum() const;

    //************************************
    // FullName:    KDIS::PDU::Comment_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Comment_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Comment_PDU::Encode
    // Description: Convert To Network Data.
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Comment_PDU & Value ) const;
    KBOOL operator != ( const Comment_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
