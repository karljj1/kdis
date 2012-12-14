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
    class:      Articulated_Parts_PDU
    DIS:        (6) 1278.1a - 1998
    created:    17/07/2010
    author:     Karl Jones

    purpose:    Contains information about the articulated and attached parts of a live entity.

    size:       136 bits / 17 octets - Min size
*********************************************************************/

#pragma once

#include "./LE_Header.h"
#include "./../../DataTypes/ArticulationParameters.h"
#include <vector>

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::ArticulationParameters;
using std::vector;

class KDIS_EXPORT Articulated_Parts_PDU : public LE_Header
{
protected:

    KUINT8 m_ui8NumOfArticulationParams;

    vector<ArticulationParameters> m_vArticulationParameters;

public:

    static const KUINT16 ARTICULATED_PARTS_PDU_SIZE = 17; // Min size

    Articulated_Parts_PDU( void );

    Articulated_Parts_PDU( const LE_EntityIdentifier & ID );

    Articulated_Parts_PDU( KDataStream & stream ) throw( KException );

    virtual ~Articulated_Parts_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Articulated_Parts_PDU::GetNumberOfArticulationParams
    // Description: Number of articulation parameters
    //************************************
    KUINT8 GetNumberOfArticulationParams() const;

    //************************************
    // FullName:    KDIS::PDU::Articulated_Parts_PDU::AddArticulationParameter
    //              KDIS::PDU::Articulated_Parts_PDU::SetArticulationParameter
    //              KDIS::PDU::Articulated_Parts_PDU::GetArticulationParameters
    //              KDIS::PDU::Articulated_Parts_PDU::ClearArticulationParameters
    // Description: Add a articulation parameter / Get vector or params
    //              Adding will update the Number Of Articulation Params
    //              field.
    // Parameter:   const ArticulationParameters & AP, const vector<ArticulationParameters> & AP
    //************************************
    void AddArticulationParameter( const ArticulationParameters & AP );
    void SetArticulationParameters( const vector<ArticulationParameters> & AP );
    const vector<ArticulationParameters> & GetArticulationParameters() const;
    void ClearArticulationParameters();

    //************************************
    // FullName:    KDIS::PDU::Articulated_Parts_PDU::GetAsString
    // Description: Returns a string representation of the PDU
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Articulated_Parts_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

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

}; // END namespace PDU
}; // END namespace KDIS
