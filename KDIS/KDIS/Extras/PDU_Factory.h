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
    class:      PDU_Factory
    created:    06/12/2008
    author:     Karl Jones

    purpose:    Using a factory design pattern to decode a data stream to
                the correct PDU type.
*********************************************************************/

#pragma once

#include <memory>
#include <vector>
#include "./../PDU/Header.h"
#include "./PDU_Factory_Filters.h"

namespace KDIS {
namespace UTILS {

class KDIS_EXPORT PDU_Factory
{
protected:

    std::vector<PDU_Factory_Filter*> m_vFilters;

    //************************************
    // FullName:    KDIS::UTILS::PDU_Factory::applyFilters
    // Description: Applies the filter/s to the PDU and returns a NULL
    //              pointer if the PDU does not pass all filters.
    // Parameter:   Header * H
    //************************************
    std::auto_ptr<KDIS::PDU::Header> applyFilters( KDIS::PDU::Header * H );

public:

    PDU_Factory();

    ~PDU_Factory();

    //************************************
    // FullName:    KDIS::UTILS::PDU_Factory::AddFilter
    // Description: Add a filter that will be applied to all PDU's.
    //              Note: All filters will be automatically deleted when the PDU factory is deleted.
    // Parameter:   PDU_Factory_Filter * F
    //************************************
    void AddFilter( PDU_Factory_Filter * F );

    //************************************
    // FullName:    KDIS::UTILS::PDU_Factory::RemoveFilter
    // Description: Remove a filter.
    // Parameter:   PDU_Factory_Filters * F
    //************************************
    void RemoveFilter( PDU_Factory_Filter * F );

    //************************************
    // FullName:    KDIS::UTILS::PDU_Factory::Decode
    // Description: Converts a stream of OCTETS into the correct PDU type.
    //              If the PDU type is unknown or not currently
    //              implemented in KDIS a NULL auto_ptr is returned.
    // Parameter:   KOCTET * Buffer
    // Parameter:   KUINT16 BufferSize
    //************************************
    virtual std::auto_ptr<KDIS::PDU::Header> Decode( KOCTET * Buffer, KUINT16 BufferSize )throw( KException );

    //************************************
    // FullName:    KDIS::UTILS::PDU_Factory::Decode
    // Description: Converts data stream into the correct PDU type.
    //              If the PDU type is unknown or not currently
    //              implemented a NULL auto_ptr is returned.
    // Parameter:   KDataStream & Stream
    //************************************
    virtual std::auto_ptr<KDIS::PDU::Header> Decode( KDataStream & Stream )throw( KException );

    //************************************
    // FullName:    KDIS::UTILS::PDU_Factory::Decode
    // Description: Converts data stream into the correct PDU.
    //              This version takes a known PDU and decodes just the body.
    //              Note: If you wanted to add support for your own PDU this would be a great
    //              place to add it, just override this function and check for your PDU first,
    //              if the PDU is not yours then call the parent function.
    // Parameter:   const Header & H
    // Parameter:   KDataStream & Stream
    //************************************
    virtual std::auto_ptr<KDIS::PDU::Header> Decode( const KDIS::PDU::Header & H, KDataStream & Stream )throw( KException );
};

} // END namespace UTILS
} // END namespace KDIS
