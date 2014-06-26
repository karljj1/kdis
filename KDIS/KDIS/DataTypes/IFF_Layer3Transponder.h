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
    class:      IFF_Layer3Transponder
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
#include "./Mode5MessageFormats.h"
#include "./Mode5InterrogatorBasicData.h"
#include "./StandardVariable.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT IFF_Layer3Transponder : public LayerHeader
{
protected:

	//*******************************************************
	// TODO: YOU ARE HERE!!!!
	// TODO: transponder record and encode/decode/getasstring
	// TODO: Then interrogator the same as.
	//*******************************************************

	SimulationIdentifier m_RptSim;

	// Transponder/interrogator in the inherited classes.

	KUINT16 m_ui16Padding;
		
	KUINT16 m_ui16NumIffRecs;

	std::vector<KDIS::DATA_TYPE::StdVarPtr> m_vStdVarRecs;

public:

    static const KUINT16 IFF_LAYER3_SIZE = 28; // Min size

    IFF_Layer3Transponder();

    IFF_Layer3Transponder( KDataStream & stream ) throw( KException );

	IFF_Layer3Transponder( const LayerHeader & H, KDataStream & stream ) throw( KException );

    virtual ~IFF_Layer3Transponder();

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer3Transponder::SetReportingSimulation
    //              KDIS::DATA_TYPE::IFF_Layer3Transponder::GetReportingSimulation
    // Description: The simulation reporting this IFF PDU.
    // Parameter:   const SimulationIdentifier & RS
    //************************************
    void SetReportingSimulation( const SimulationIdentifier & RS );
    const SimulationIdentifier & GetReportingSimulation() const;
    SimulationIdentifier & GetReportingSimulation();
	
    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer3Transponder::SetMode5InterrogatorBasicData
    //              KDIS::DATA_TYPE::IFF_Layer3Transponder::GetMode5InterrogatorBasicData
    // Description: Basic Mode 5 interrogator data that is always required to be transmitted.
    // Parameter:   const Mode5InterrogatorBasicData & IBD
    //************************************
    //void SetMode5InterrogatorBasicData( const Mode5InterrogatorBasicData & IBD );
    //const Mode5InterrogatorBasicData & GetMode5InterrogatorBasicData() const;
    //Mode5InterrogatorBasicData & GetMode5InterrogatorBasicDatan();
		
    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer3Transponder::GetNumberDataRecords
    // Description: The number of IFF Data records in this PDU.
    //************************************
	KUINT16 GetNumberDataRecords() const;

	//************************************
    // FullName:    KDIS::PDU::IFF_Layer3Transponder::AddDataRecord
    //              KDIS::PDU::IFF_Layer3Transponder::SetDataRecords
    //              KDIS::PDU::IFF_Layer3Transponder::GetDataRecords
    //              KDIS::PDU::IFF_Layer3Transponder::ClearDataRecords
    // Description: IFF Data records are used when variable records are required to be included in the layer.
	//              They are identical to Standard Variable Specification record format except that alignment is to
	//              a 32-bit boundary for each IFF Data record instead of to a 64-bit boundary. 
	//              This means the records can not contain 64 bit floats or 64 bit integers.
    // Parameter:   StdVarPtr DR, const vector<StdVarPtr> & DRS
    //************************************
    void AddDataRecord( KDIS::DATA_TYPE::StdVarPtr DR );
	void SetDataRecords( const std::vector<KDIS::DATA_TYPE::StdVarPtr> & DRS );
	const std::vector<KDIS::DATA_TYPE::StdVarPtr> & GetDataRecords() const;
    void ClearDataRecords();
	
    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer3Transponder::GetAsString
    // Description: Returns a string representation 
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer3Transponder::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the layer header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer3Transponder::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const IFF_Layer3Transponder & Value ) const;
    KBOOL operator != ( const IFF_Layer3Transponder & Value ) const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
