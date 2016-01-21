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
    created:    27/06/2014
    author:     Karl Jones

    purpose:    Layer 3 Mode 5 transponder functional data.

    Size:       224 bits / 28 octets - min size
*********************************************************************/

#pragma once

#include "./IFF_Layer3.h"
#include "./SimulationIdentifier.h"
#include "./Mode5TransponderBasicData.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT IFF_Layer3Transponder : public IFF_Layer3
{
protected:

    Mode5TransponderBasicData m_BasicData;

public:

    IFF_Layer3Transponder();

    IFF_Layer3Transponder( KDataStream & stream ) throw( KException );

    IFF_Layer3Transponder( const SimulationIdentifier & ReportingSimulation, const Mode5TransponderBasicData & Data,
                           std::vector<StdVarPtr> & Records );

    IFF_Layer3Transponder( const LayerHeader & H, KDataStream & stream ) throw( KException );

    virtual ~IFF_Layer3Transponder();

    //************************************
    // FullName:    KDIS::DATA_TYPE::IFF_Layer3Transponder::SetBasicData
    //              KDIS::DATA_TYPE::IFF_Layer3Transponder::GetBasicData
    // Description: Basic Mode 5 transponder data that is always required to be transmitted.
    // Parameter:   const Mode5TransponderBasicData & BD
    //************************************
    void SetBasicData( const Mode5TransponderBasicData & BD );
    const Mode5TransponderBasicData & GetBasicData() const;
    Mode5TransponderBasicData & GetBasicDatan();

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
