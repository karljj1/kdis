/*********************************************************************
KDIS is free software; you can redistribute it and/or modify it under the
terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option)
any later version.

KDIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this library; if not, write to the Free Software Foundation, Inc.,
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

For Further Information Please Contact me at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

/********************************************************************
    class:      Reliability_Header
    DIS:        (6) 1278.1A - 1998
    created:    20:01:2009
    author:     Karl Jones

    purpose:    specifies the required level of reliability service to be
                used for a PDU.
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./../../KDefines.h"
#include "./../../DataTypes/Enums/KDISEnums.h"
#include "./../../KDataStream.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::ENUMS::RequiredReliabilityService;

class KDIS_EXPORT Reliability_Header
{
protected:

    KUINT8 m_ui8ReqRelSrv;

    KUINT16 m_ui16Padding1;

    KUINT8 m_ui8Padding;

public:

    static const KUINT16 RELIABILITY_SIZE = 4;

    Reliability_Header( void );

    Reliability_Header( KDataStream & stream ) throw( KException );

    Reliability_Header( RequiredReliabilityService RRS );

    virtual ~Reliability_Header( void );

    //************************************
    // FullName:    KDIS::PDU::Reliability_Header::SetRequiredReliabilityService
    //              KDIS::PDU::Reliability_Header::GetRequiredReliabilityService
    // Description: specifies the required level of reliability service to be
    //              used for this transaction/PDU.
    // Parameter:   RequiredReliabilityService RRS, void
    //************************************
    void SetRequiredReliabilityService( RequiredReliabilityService RRS );
    RequiredReliabilityService GetRequiredReliabilityService() const;

    //************************************
    // FullName:    KDIS::PDU::Reliability_Header::GetString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Reliability_Header::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Reliability_Header::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Reliability_Header & Value ) const;
    KBOOL operator != ( const Reliability_Header & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
