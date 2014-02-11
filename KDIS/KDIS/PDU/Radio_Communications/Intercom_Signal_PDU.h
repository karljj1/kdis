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

class KDIS_EXPORT Intercom_Signal_PDU : public Signal_PDU
{
protected:

public:

    Intercom_Signal_PDU();

    Intercom_Signal_PDU( KDataStream & stream ) throw( KException );

	Intercom_Signal_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Intercom_Signal_PDU( const KDIS::DATA_TYPE::EntityIdentifier & ID, KUINT16 RadioID, const KDIS::DATA_TYPE::EncodingScheme & ES,
                         KUINT32 SampleRate, KUINT16 Samples, const KOCTET * Data, KUINT16 DataLength );

    virtual ~Intercom_Signal_PDU();

    //************************************
    // FullName:    KDIS::PDU::Intercom_Signal_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    KBOOL operator == ( const Intercom_Signal_PDU & Value ) const;
    KBOOL operator != ( const Intercom_Signal_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS

