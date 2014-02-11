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
    class:      Resupply_Received_PDU
    DIS:        (5) 1278.1 - 1995
    created:    2008/09/22
    author:     Karl Jones

    purpose:    Resupply Received PDU
    Size:       224 bits / 28 octets + ( 96 bits / 12 octets * ( number of supplies ) )
*********************************************************************/

#pragma once

#include "./Logistics_Header.h"
#include "./../../DataTypes/Supplies.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Resupply_Received_PDU : public Logistics_Header
{
protected:

    KUINT8 m_ui8NumSupplyTypes;

    KUINT16 m_ui16Padding1;

    KUINT8 m_ui8Padding2;

	std::vector<KDIS::DATA_TYPE::Supplies> m_vSupplies;

public:

    static const KUINT16 RESUPPLY_RECEIVED_PDU_SIZE = 28; // Does not include supply size

    Resupply_Received_PDU();

	Resupply_Received_PDU( const Header & H );

    Resupply_Received_PDU( KDataStream & stream ) throw( KException );

	Resupply_Received_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Resupply_Received_PDU( const KDIS::DATA_TYPE::EntityIdentifier & ReceivingEntity, const KDIS::DATA_TYPE::EntityIdentifier & SupplyingEntity );

    virtual ~Resupply_Received_PDU();

    //************************************
    // FullName:    KDIS::PDU::Resupply_Received_PDU::SetNumberOfSupplyTypes
    //              KDIS::PDU::Resupply_Received_PDU::GetNumberOfSupplyTypes
    // Description: How many supplies are being provided.
    //              This value is calculated automatically by
    //              the number of supplies, only change
    //              if you know what you are doing
    // Parameter:   KUINT8  UI, void
    //************************************
    void SetNumberOfSupplyTypes( KUINT8  UI );
    KUINT8 GetNumberOfSupplyTypes() const;

    //************************************
    // FullName:    KDIS::PDU::Resupply_Received_PDU::AddSupply
    //              KDIS::PDU::Resupply_Received_PDU::SetSupplies
    //              KDIS::PDU::Resupply_Received_PDU::GetSupplies
    // Description: Add a supply, updates Number Of Supply Types and
    //              PDU size fields automatically.
    // Parameter:   const Supplies & S, void
    //************************************
    void AddSupply( const KDIS::DATA_TYPE::Supplies & S );
	void SetSupplies( const std::vector<KDIS::DATA_TYPE::Supplies> & S );
	std::vector<KDIS::DATA_TYPE::Supplies> GetSupplies() const;

    //************************************
    // FullName:    KDIS::PDU::Resupply_Received_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Resupply_Received_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Resupply_Received_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Resupply_Received_PDU & Value ) const;
    KBOOL operator != ( const Resupply_Received_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
