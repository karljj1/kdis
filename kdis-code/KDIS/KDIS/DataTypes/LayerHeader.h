/*********************************************************************
KDIS is free software; you can redistribute it and/or modify it under the
terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option)
any later version.

KDIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should hav received a copy of the GNU Lesser General Public License along
with this library; if not, write to the Free Software Foundation, Inc.,
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

For Further Information Please Contact me at
Karljj1@yahoo.com
http://p.sf.net/kdis/UserGuide
*********************************************************************/

/********************************************************************
    class:      LayerHeader
    created:    2008/12/07
    author:     Karl Jones

    purpose:    Identifies the additional layer number, layer-specific
                information and the length of the layer.

    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT LayerHeader : public DataTypeBase
{
protected:

    KUINT8 m_ui8LayerNumber;

    KUINT8 m_ui8LayerSpecificInfo;

    KUINT16 m_ui16LayerLength;

public:

    static const KUINT16 LAYER_HEADER_SIZE = 4;

    LayerHeader( void );

    LayerHeader( KDataStream & stream ) throw( KException );

    LayerHeader( KUINT8 LayerNumber, KUINT8 LayerSpecificInfo, KUINT16 LayerLength );

    virtual ~LayerHeader( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LayerHeader::SetLayerNumber
    //              KDIS::DATA_TYPE::LayerHeader::GetLayerNumber
    // Description: Identifies the layer.
    // Parameter:   KUINT8 LN, void
    //************************************
    void SetLayerNumber( KUINT8 LN );
    KUINT8 GetLayerNumber() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LayerHeader::SetLayerSpecificInfomation
    //              KDIS::DATA_TYPE::LayerHeader::GetLayerSpecificInfomation
    // Description: This value varies by system type and layer number. Represented by an
    //              enumeration however no values has been defined(as of SISO-REF-10-2006) other than 0 = Other.
    // Parameter:   KUINT8 LSI, void
    //************************************
    void SetLayerSpecificInfomation( KUINT8 LSI );
    KUINT8 GetLayerSpecificInfomation() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LayerHeader::SetLayerLength
    //              KDIS::DATA_TYPE::LayerHeader::GetLayerLength
    // Description: Specifies the length in octets of the layer including the layer header.
    // Parameter:   KUINT16 L, void
    //************************************
    void SetLayerLength( KUINT16 L );
    KUINT16 GetLayerLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LayerHeader::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LayerHeader::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LayerHeader::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const LayerHeader & Value ) const;
    KBOOL operator != ( const LayerHeader & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

