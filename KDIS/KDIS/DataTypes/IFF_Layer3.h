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

    purpose:    Layer 3 Mode 5 formats.
				Used to convey Mode 5 interrogator and transponder functional data.

    Size:       224 bits / 28 octets - min size
*********************************************************************/

#pragma once

#include "./LayerHeader.h"
#include "./SimulationIdentifier.h"
#include "./Mode5MessageFormats.h"
#include "./Mode5InterrogatorBasicData.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT IFF_Layer3 : public LayerHeader
{
protected:

	SimulationIdentifier m_RptSim;

	// TODO: This is either interrogator or transponder data. 
	Mode5InterrogatorBasicData m_IntBscDta;

	KUINT16 m_ui16Padding;

	// TODO: Look at the interrgator and transponder status to see what the included records are.
	
	
	
	
	// TODO: YOU ARE HERE
	
	KUINT16 m_ui16NumIffRecs;

public:

    static const KUINT16 IFF_LAYER3_SIZE = 28; // Min size

    IFF_Layer3();

    IFF_Layer3( KDataStream & stream ) throw( KException );

	IFF_Layer3( const LayerHeader & H, KDataStream & stream ) throw( KException );

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
    // FullName:    KDIS::DATA_TYPE::IFF_Layer3::SetMode5InterrogatorBasicData
    //              KDIS::DATA_TYPE::IFF_Layer3::GetMode5InterrogatorBasicData
    // Description: Basic Mode 5 interrogator data that is always required to be transmitted.
    // Parameter:   const Mode5InterrogatorBasicData & IBD
    //************************************
    void SetMode5InterrogatorBasicData( const Mode5InterrogatorBasicData & IBD );
    const Mode5InterrogatorBasicData & GetMode5InterrogatorBasicData() const;
    Mode5InterrogatorBasicData & GetMode5InterrogatorBasicDatan();




	

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer3::GetNumberIFFDataRecords
    // Description: The number of IFF Data records in this PDU.
    //************************************
	KUINT16 GetNumberIFFDataRecords() const;

	





    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer3::GetAsString
    // Description: Returns a string representation 
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer3::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the layer header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer3::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const IFF_Layer3 & Value ) const;
    KBOOL operator != ( const IFF_Layer3 & Value ) const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
