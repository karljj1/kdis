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
    class:      IFF_Layer3
    DIS:        (7) 1278.1 - 2012
    created:    23/09/2013
    author:     Karl Jones

    purpose:    Base class for Layer 3 Mode 5 interrogator and transponder functional data.
	            Note: The Layer 1 System Type field isused to determine whether Layer 3 
				represents a Mode 5 capable interrogator or transponder.

    Size:       224 bits / 28 octets - min size
*********************************************************************/

#pragma once

#include "./LayerHeader.h"
#include "./SimulationIdentifier.h"
#include "./StandardVariable.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT IFF_Layer3 : public LayerHeader
{
protected:

	SimulationIdentifier m_RptSim;

	// Transponder/interrogator in the inherited classes.

	KUINT16 m_ui16Padding;
		
	KUINT16 m_ui16NumIffRecs;

	std::vector<KDIS::DATA_TYPE::StdVarPtr> m_vStdVarRecs;

public:

    static const KUINT16 IFF_LAYER3_SIZE = 28; // Min size

    IFF_Layer3();

	IFF_Layer3( const LayerHeader & H );

    virtual ~IFF_Layer3();

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer3::SetReportingSimulation
    //              KDIS::DATA_TYPE::IFF_Layer3::GetReportingSimulation
    // Description: The simulation reporting this IFF PDU.
    // Parameter:   const SimulationIdentifier & RS
    //************************************
    void SetReportingSimulation( const SimulationIdentifier & RS );
    const SimulationIdentifier & GetReportingSimulation() const;
    SimulationIdentifier & GetReportingSimulation();
			
    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer3::GetNumberDataRecords
    // Description: The number of IFF Data records in this PDU.
    //************************************
	KUINT16 GetNumberDataRecords() const;

	//************************************
    // FullName:    KDIS::PDU::IFF_Layer3::AddDataRecord
    //              KDIS::PDU::IFF_Layer3::SetDataRecords
    //              KDIS::PDU::IFF_Layer3::GetDataRecords
    //              KDIS::PDU::IFF_Layer3::ClearDataRecords
    // Description: IFF Data records are used when variable records are required to be included in the layer.
	//              They are identical to Standard Variable Specification record format except that alignment is to
	//              a 32-bit boundary for each IFF Data record instead of to a 64-bit boundary. 
	//              This means the records can not contain 64 bit floats or 64 bit integers.
	//              See B.2.1.1 of IEEE 1278.1-2012 for a full list of supported records (Note: I have not implmented them all yet but do plan to).
    // Parameter:   StdVarPtr DR, const vector<StdVarPtr> & DRS
    //************************************
    void AddDataRecord( StdVarPtr DR );
	void SetDataRecords( const std::vector<StdVarPtr> & DRS );
	const std::vector<StdVarPtr> & GetDataRecords() const;
    void ClearDataRecords();

    KBOOL operator == ( const IFF_Layer3 & Value ) const;
    KBOOL operator != ( const IFF_Layer3 & Value ) const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
