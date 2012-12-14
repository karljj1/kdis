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

using KDIS::PDU::Header;
using std::auto_ptr;
using std::vector;

class KDIS_EXPORT PDU_Factory
{
protected:

    vector<PDU_Factory_Filter*> m_vFilters;

    //************************************
    // FullName:    KDIS::UTILS::PDU_Factory::applyFilters
    // Description: Applies the filter/s to the PDU and returns a NULL
    //              pointer if the PDU does not pass all filters.
    // Parameter:   Header * H
    //************************************
    auto_ptr<Header> applyFilters( Header * H );

public:

    PDU_Factory( void );

    ~PDU_Factory( void );

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
    virtual auto_ptr<Header> Decode( KOCTET * Buffer, KUINT16 BufferSize )throw( KException );

    //************************************
    // FullName:    KDIS::UTILS::PDU_Factory::Decode
    // Description: Converts data stream into the correct PDU type.
    //              If the PDU type is unknown or not currently
    //              implemented a NULL auto_ptr is returned.
    // Parameter:   KDataStream & Stream
    //************************************
    virtual auto_ptr<Header> Decode( KDataStream & Stream )throw( KException );

    //************************************
    // FullName:    KDIS::UTILS::PDU_Factory::Decode
    // Description: Converts data stream into the correct PDU.
    //              This version takes a known PDU and decodes the body.
    //              Note: The data stream must still contain the header for propper decoding.
    //              Note: If you wanted to add support for your own PDU this would be a great
    //              place to add it, just override this function and check for your PDU first,
    //              if the PDU is not yours then call the parent function.
    // Parameter:   const Header & H
    // Parameter:   KDataStream & Stream
    //************************************
    virtual auto_ptr<Header> Decode( const Header & H, KDataStream & Stream )throw( KException );
};

}; // End namespace UTILS
}; // End namespace KDIS
