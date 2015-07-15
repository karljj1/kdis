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
    class:      PDU_FactoryLink16
    created:    14/07/2015
    author:     Karl Jones

    purpose:    PDU Factory with added support for Link16.      
*********************************************************************/

#pragma once

#include "KDIS/Extras/PDU_Factory.h"
#include "./../KDefinesLink16.h"

namespace KDIS {
namespace UTILS {

class KDIS_EXPORT_LINK16 PDU_FactoryLink16 : public PDU_Factory
{
public:

    PDU_FactoryLink16();

    ~PDU_FactoryLink16();

    //************************************
    // FullName:    KDIS::UTILS::PDU_FactoryLink16::Decode
    // Description: Checks if the Header belongs to a Link16 PDU before using the default PDU Factory.
    // Parameter:   const Header & H
    // Parameter:   KDataStream & Stream
    //************************************
    virtual std::auto_ptr<KDIS::PDU::Header> Decode( const KDIS::PDU::Header & H, KDataStream & Stream )throw( KException );
};

} // END namespace UTILS
} // END namespace KDIS
