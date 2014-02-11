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
    class:      Articulated_Parts_PDU
    DIS:        (6) 1278.1a - 1998
    created:    17/07/2010
    author:     Karl Jones

    purpose:    Contains information about the articulated and attached parts of a live entity.

    size:       136 bits / 17 octets - Min size
*********************************************************************/

#pragma once

#include "./LE_Header.h"
#include "./../../DataTypes/VariableParameter.h"
#include <vector>

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Articulated_Parts_PDU : public LE_Header
{
protected:

    KUINT8 m_ui8NumOfVariableParams;

	std::vector<KDIS::DATA_TYPE::VarPrmPtr> m_vVariableParameters;

public:

    static const KUINT16 ARTICULATED_PARTS_PDU_SIZE = 17; // Min size

    Articulated_Parts_PDU();

	Articulated_Parts_PDU( KDataStream & stream ) throw( KException );

	Articulated_Parts_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Articulated_Parts_PDU( const KDIS::DATA_TYPE::LE_EntityIdentifier & ID );

    virtual ~Articulated_Parts_PDU();

    //************************************
    // FullName:    KDIS::PDU::Articulated_Parts_PDU::GetNumberOfVariableParams
    // Description: Number of variable parameters.
    //************************************
    KUINT8 GetNumberOfVariableParams() const;

    //************************************
    // FullName:    KDIS::PDU::Articulated_Parts_PDU::AddVariableParameter
    //              KDIS::PDU::Articulated_Parts_PDU::SetVariableParameter
    //              KDIS::PDU::Articulated_Parts_PDU::GetVariableParameters
    //              KDIS::PDU::Articulated_Parts_PDU::ClearVariableParameters
    // Description: Information associated with an entity or detonation, not otherwise accounted
    //	            for in a PDU such as Articulated and Attached Parts.
    //              See VariableParameter for supported/implemented types.
    // Parameter:   VarPrmPtr VP, vector<VarPrmPtr> & VP
    //************************************
    void AddVariableParameter( KDIS::DATA_TYPE::VarPrmPtr VP );
	void SetVariableParameters( const std::vector<KDIS::DATA_TYPE::VarPrmPtr> & VP );
	const std::vector<KDIS::DATA_TYPE::VarPrmPtr> & GetVariableParameters() const;
    void ClearVariableParameters();

    //************************************
    // FullName:    KDIS::PDU::Articulated_Parts_PDU::GetAsString
    // Description: Returns a string representation of the PDU
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Articulated_Parts_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Articulated_Parts_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Articulated_Parts_PDU & Value ) const;
    KBOOL operator != ( const Articulated_Parts_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
