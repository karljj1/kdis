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
    class:      Intercom_Signal_PDU
    DIS:        (6) 1278.1A - 1998
    created:    2009/02/24
    author:     Karl Jones

    purpose:    Contains actual transmission of intercom voice/data
                Note this PDU structure is identical to the Signal_PDU

    size:       256 bits / 32 - min size
*********************************************************************/

#pragma once

#include "./Signal_PDU.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::EncodingScheme;

class KDIS_EXPORT Intercom_Signal_PDU : public Signal_PDU
{
protected:

public:

    Intercom_Signal_PDU( void );

    Intercom_Signal_PDU( KDataStream & stream ) throw( KException );

    Intercom_Signal_PDU( const EntityIdentifier & ID, KUINT16 RadioID, const EncodingScheme & ES,
                         KUINT32 SampleRate, KUINT16 Samples, const KOCTET * Data, KUINT16 DataLength );

    virtual ~Intercom_Signal_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Intercom_Signal_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    KBOOL operator == ( const Intercom_Signal_PDU & Value ) const;
    KBOOL operator != ( const Intercom_Signal_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS

