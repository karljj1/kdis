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
    class:      DataTypeBase
    created:    18/09/2008
    author:     Karl Jones

    purpose:    Base class for all data types, all data types must
                provide a Decode/Encode functionality.
*********************************************************************/

#pragma once

#include "./../KDefines.h"
#include "./Enums/KDISEnums.h"
#include "./../KDataStream.h"
#include "./../Extras/KUtils.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT DataTypeBase
{
public:

    DataTypeBase( void );

    virtual ~DataTypeBase( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::DataTypeBase::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const = 0;

    //************************************
    // FullName:    KDIS::DATA_TYPE::DataTypeBase::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException ) = 0;

    //************************************
    // FullName:    KDIS::DATA_TYPE::DataTypeBase::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const = 0;
    virtual void Encode( KDataStream & stream ) const = 0;

    friend KDataStream & operator >> ( KDataStream & stream, DataTypeBase * DTB )
    {
        DTB->Decode( stream );
        return stream;
    };

    friend KDataStream & operator << ( KDataStream & stream, DataTypeBase * DTB )
    {
        DTB->Encode( stream );
        return stream;
    };

    // For streaming a data type into a KDataStream,
#define KDIS_STREAM ( DataTypeBase * ) &
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
