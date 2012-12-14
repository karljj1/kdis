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

/*********************************************************************
    class:      Comment_PDU
    DIS:        (5) 1278.1 - 1995
    created:    08/10/2008
    author:     Karl Jones

    purpose:    Arbitrary message (E.G char strings) shall be entered into the data
                stream by using a comment PDU. For use as comment, test message, error etc.
    size:       256 bits/ 32 octets - not including fix and var datum sizes
*********************************************************************/

#pragma once

#include "./Simulation_Management_Header.h"
#include "./../../DataTypes/FixedDatum.h"
#include "./../../DataTypes/VariableDatum.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::FixedDatum;
using KDIS::DATA_TYPE::FixDtmPtr;
using KDIS::DATA_TYPE::VariableDatum;
using KDIS::DATA_TYPE::VarDtmPtr;
using std::vector;

class KDIS_EXPORT Comment_PDU : public Simulation_Management_Header
{
protected:

    KUINT32 m_ui32NumFixedDatum;

    KUINT32 m_ui32NumVariableDatum;

    vector<FixDtmPtr> m_vFixedDatum;

    vector<VarDtmPtr> m_vVariableDatum;

public:

    static const KUINT16 COMMENT_PDU_SIZE = 32; // Min size

    Comment_PDU( void );

    Comment_PDU( KDataStream & stream ) throw( KException );

    Comment_PDU( const EntityIdentifier & OriginatingEntityID, const EntityIdentifier & ReceivingEntityID );

    virtual ~Comment_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Comment_PDU::GetNumberFIxedDatum
    // Description: Returns number of fixed datum records
    //************************************
    KUINT32 GetNumberFIxedDatum() const;

    //************************************
    // FullName:    KDIS::PDU::Comment_PDU::GetNumberVariableDatum
    // Description: Returns number of variable datum records
    //************************************
    KUINT32 GetNumberVariableDatum() const;

    //************************************
    // FullName:    KDIS::PDU::Comment_PDU::AddFixedDatum
    //              KDIS::PDU::Comment_PDU::SetFixedDatum
    //              KDIS::PDU::Comment_PDU::GetFixedDatum
    // Description: Add, get fixed datums
    // Parameter:   FixedDatum FD, const vector<FixDtmPtr> & FD
    //************************************
    void AddFixedDatum( FixDtmPtr FD );
    void SetFixedDatum( const vector<FixDtmPtr> & FD );
    const vector<FixDtmPtr> & GetFixedDatum() const;

    //************************************
    // FullName:    KDIS::PDU::Comment_PDU::AddVariableDatum
    //              KDIS::PDU::Comment_PDU::SetVariableDatum
    //              KDIS::PDU::Comment_PDU::GetVariableDatum
    // Description: Add, get variable datums
    // Parameter:   VarDtmPtr VD, const vector<VarDtmPtr> & VD
    //************************************
    void AddVariableDatum( VarDtmPtr VD );
    void SetVariableDatum( const vector<VarDtmPtr> & VD );
    const vector<VarDtmPtr> & GetVariableDatum() const;

    //************************************
    // FullName:    KDIS::PDU::Comment_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Comment_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Comment_PDU::Encode
    // Description: Convert To Network Data.
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Comment_PDU & Value ) const;
    KBOOL operator != ( const Comment_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS
