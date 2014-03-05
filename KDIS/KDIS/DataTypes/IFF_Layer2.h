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
    class:      IFF_Layer2
    DIS:        (6) 1278.1A - 1998
    created:    20/09/2013
    author:     Karl Jones

    purpose:    Layer 2 emissions data.

    Size:       224 bits / 28 octets - min size
*********************************************************************/

#pragma once

#include "./LayerHeader.h"
#include "./BeamData.h"
#include "./SecondaryOperationalData.h"
#include "./IFF_ATC_NAVAIDS_FundamentalParameterData.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT IFF_Layer2 : public LayerHeader
{
protected:
	
    BeamData m_BmDt;

    SecondaryOperationalData m_SOD;

	std::vector<IFF_ATC_NAVAIDS_FundamentalParameterData> m_vFPD;

public:

    static const KUINT16 IFF_LAYER2_SIZE = 28; // Min size

    IFF_Layer2();

    IFF_Layer2( KDataStream & stream ) throw( KException );

	IFF_Layer2( const LayerHeader & H, KDataStream & stream ) throw( KException );

    IFF_Layer2( const BeamData & BD, const SecondaryOperationalData & SOD,
                const std::vector<IFF_ATC_NAVAIDS_FundamentalParameterData> & FPD );

    virtual ~IFF_Layer2();

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer2::SetBeamData
    //              KDIS::DATA_TYPE::IFF_Layer2::GetBeamData
    // Description: Specifies beam specific data.
    //              If the mainbeam antenna activity of the IFF emitting system before the next
    //              IFF/ATC/NAVAIDS PDU update can be represented by a single beam, then a description of the beam
    //              shall be entered in this record. If multiple beams would be required, then this record
    //              shall be filled with zeroes.
    // Parameter:   const BeamData & BD
    //************************************
    void SetBeamData( const BeamData & BD );
    const BeamData & GetBeamData() const;
    BeamData & GetBeamData();

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer2::SetSecondaryOperationalData
    //              KDIS::DATA_TYPE::IFF_Layer2::GetSecondaryOperationalData
    // Description: Specifies secondary operational data for the IFF/ATC/NAVAIDS emitting system.
    //              Note: This data type holds the number of Fundamental Parameter Data Sets, if you make a
    //              change you will need to make sure the value stays correct.
    // Parameter:   const SecondaryOperationalData & SOD
    //************************************
    void SetSecondaryOperationalData( const SecondaryOperationalData & SOD );
    const SecondaryOperationalData & GetSecondaryOperationalData() const;
    SecondaryOperationalData & GetSecondaryOperationalData();

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer2::AddFundamentalParameterData
    //              KDIS::DATA_TYPE::IFF_Layer2::SetFundamentalParameterData
    //              KDIS::DATA_TYPE::IFF_Layer2::GetFundamentalParameterData
    // Description: Specifies the values of the fundamental energy radiation characteristic
    //              of each emission from the IFF/ATC/NAVAIDS emitting system.
    // Parameter:   const IFF_ATC_NAVAIDS_FundamentalParameterData & FPD, const vector<IFF_ATC_NAVAIDS_FundamentalParameterData> & FPD
    //************************************
    void AddFundamentalParameterData( const KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData & FPD );
	void SetFundamentalParameterData( const std::vector<KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData> & FPD );
	const std::vector<KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData> & GetFundamentalParameterData() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer2::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer2::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the layer header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer2::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const IFF_Layer2 & Value ) const;
    KBOOL operator != ( const IFF_Layer2 & Value ) const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
