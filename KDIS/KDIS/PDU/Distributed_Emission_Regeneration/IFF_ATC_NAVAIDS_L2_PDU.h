/*********************************************************************
Copyright 2013 KDIS
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
    class:      IFF_ATC_NAVAIDS_L2_PDU
    DIS:        (6) 1278.1A - 1998
    created:    2008/12/13
    author:     Karl Jones

    purpose:    When present, layer 2 shall follow layer 1.

    Size:       736 bits / 92 octets
*********************************************************************/

#pragma once

#include "./IFF_ATC_NAVAIDS_L1_PDU.h"
#include "./../../DataTypes/LayerHeader.h"
#include "./../../DataTypes/BeamData.h"
#include "./../../DataTypes/SecondaryOperationalData.h"
#include "./../../DataTypes/IFF_ATC_NAVAIDS_FundamentalParameterData.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::LayerHeader;
using KDIS::DATA_TYPE::BeamData;
using KDIS::DATA_TYPE::SecondaryOperationalData;
using KDIS::DATA_TYPE::IFF_ATC_NAVAIDS_FundamentalParameterData;
using std::vector;

class KDIS_EXPORT IFF_ATC_NAVAIDS_L2_PDU : public IFF_ATC_NAVAIDS_L1_PDU
{
protected:

    LayerHeader m_LyrHdr;

    BeamData m_BmDt;

    SecondaryOperationalData m_SOD;

    vector<IFF_ATC_NAVAIDS_FundamentalParameterData> m_vFPD;

public:

    static const KUINT16 IFF_ATC_NAVAIDS_L2_PDU_SIZE = 92; // Min size

    IFF_ATC_NAVAIDS_L2_PDU();

    IFF_ATC_NAVAIDS_L2_PDU( KDataStream & stream ) throw( KException );

    IFF_ATC_NAVAIDS_L2_PDU( const EntityIdentifier & EmittingID, const EntityIdentifier & EventID, const Vector & Location, const SystemIdentifier & ID,
                            const FundamentalOperationalData & FOD, const LayerHeader & LH,const BeamData & BD, const SecondaryOperationalData & SOD,
                            const vector<IFF_ATC_NAVAIDS_FundamentalParameterData> & FPD );

    IFF_ATC_NAVAIDS_L2_PDU( const IFF_ATC_NAVAIDS_L1_PDU & PDU, const LayerHeader & LH,const BeamData & BD, const SecondaryOperationalData & SOD,
                            const vector<IFF_ATC_NAVAIDS_FundamentalParameterData> & FPD );

    virtual ~IFF_ATC_NAVAIDS_L2_PDU();

    //************************************
    // FullName:    KDIS::PDU::IFF_ATC_NAVAIDS_L2_PDU::SetLayerHeader
    //              KDIS::PDU::IFF_ATC_NAVAIDS_L2_PDU::GetLayerHeader
    // Description: Contains information regarding the layer.
    //              Note Layer Number and Layer length are set automatically and layer
    //              specific information is undefined so it is safe to let this record manage itself.
    // Parameter:   const LayerHeader & LH, void
    //************************************
    void SetLayerHeader( const LayerHeader & LH );
    const LayerHeader & GetLayerHeader() const;
    LayerHeader & GetLayerHeader();

    //************************************
    // FullName:    KDIS::PDU::IFF_ATC_NAVAIDS_L2_PDU::SetBeamData
    //              KDIS::PDU::IFF_ATC_NAVAIDS_L2_PDU::GetBeamData
    // Description: Specifies beam specific data.
    //              If the mainbeam antenna activity of the IFF emitting system before the next
    //              IFF/ATC/NAVAIDS PDU update can be represented by a single beam, then a description of the beam
    //              shall be entered in this record. If multiple beams would be required, then this record
    //              shall be filled with zeroes.
    // Parameter:   const LayerHeader & LH, void
    //************************************
    void SetBeamData( const BeamData & BD );
    const BeamData & GetBeamData() const;
    BeamData & GetBeamData();

    //************************************
    // FullName:    KDIS::PDU::IFF_ATC_NAVAIDS_L2_PDU::SetSecondaryOperationalData
    //              KDIS::PDU::IFF_ATC_NAVAIDS_L2_PDU::GetSecondaryOperationalData
    // Description: Specifies secondary operational data for the IFF/ATC/NAVAIDS emitting system.
    //              Note: This data type holds the number of Fundamental Parameter Data Sets, if you make a
    //              change you will need to make sure the value stays correct.
    // Parameter:   const SecondaryOperationalData & SOD, void
    //************************************
    void SetSecondaryOperationalData( const SecondaryOperationalData & SOD );
    const SecondaryOperationalData & GetSecondaryOperationalData() const;
    SecondaryOperationalData & GetSecondaryOperationalData();

    //************************************
    // FullName:    KDIS::PDU::IFF_ATC_NAVAIDS_L2_PDU::AddFundamentalParameterData
    //              KDIS::PDU::IFF_ATC_NAVAIDS_L2_PDU::SetFundamentalParameterData
    //              KDIS::PDU::IFF_ATC_NAVAIDS_L2_PDU::GetFundamentalParameterData
    // Description: Specifies the values of the fundamental energy radiation characteristic
    //              of each emission from the IFF/ATC/NAVAIDS emitting system.
    // Parameter:   const IFF_ATC_NAVAIDS_FundamentalParameterData & FPD, const vector<IFF_ATC_NAVAIDS_FundamentalParameterData> & FPD, void
    //************************************
    void AddFundamentalParameterData( const IFF_ATC_NAVAIDS_FundamentalParameterData & FPD );
    void SetFundamentalParameterData( const vector<IFF_ATC_NAVAIDS_FundamentalParameterData> & FPD );
    const vector<IFF_ATC_NAVAIDS_FundamentalParameterData> & GetFundamentalParameterData() const;

    //************************************
    // FullName:    KDIS::PDU::IFF_ATC_NAVAIDS_L2_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::IFF_ATC_NAVAIDS_L2_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::IFF_ATC_NAVAIDS_L2_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const IFF_ATC_NAVAIDS_L2_PDU & Value ) const;
    KBOOL operator != ( const IFF_ATC_NAVAIDS_L2_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
