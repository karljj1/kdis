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
    class:      Remove_Entity_PDU
    DIS:        (5) 1278.1 - 1995
    created:    2008/09/22
    author:     Karl Jones

    purpose:    Sent when a entity is removed
    size:       224 bits / 28 octets
*********************************************************************/

#pragma once

#include "./Create_Entity_PDU.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Remove_Entity_PDU : public Create_Entity_PDU
{
public:

    static const KUINT16 REMOVE_ENTITY_PDU_SIZE = 28;

    Remove_Entity_PDU();

    Remove_Entity_PDU( KDataStream & stream ) throw( KException );

	Remove_Entity_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Remove_Entity_PDU( const KDIS::DATA_TYPE::EntityIdentifier & OrigintatingID, const KDIS::DATA_TYPE::EntityIdentifier & ReceivingID, KUINT32 RequestID );

    Remove_Entity_PDU( const Simulation_Management_Header & SimMgrHeader, KUINT32 RequestID );

    virtual ~Remove_Entity_PDU();

    //************************************
    // FullName:    KDIS::PDU::Remove_Entity_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    KBOOL operator == ( const Remove_Entity_PDU & Value ) const;
    KBOOL operator != ( const Remove_Entity_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
