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
    class:      NamedLocationIdentifier
    created:    27:06:2008
    author:     Karl Jones

    purpose:    Contaiins information about the discrete positional relationship of the part
                entity with respect to the its host entity.
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::StationName;

class KDIS_EXPORT NamedLocationIdentifier : public DataTypeBase
{
protected:

    KUINT16 m_ui16StnName;

    KUINT16 m_ui16StnNum;

public:

    static const KUINT16 NAMED_LOCATION_ID_SIZE = 4;

    NamedLocationIdentifier( void );

    NamedLocationIdentifier( KDataStream & stream )throw( KException );

    NamedLocationIdentifier( StationName SN,  KUINT16 StationNumber );

    virtual ~NamedLocationIdentifier( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::NamedLocationIdentifier::SetStationName
    //              KDIS::DATA_TYPE::NamedLocationIdentifier::GetStationName
    // Description: Specifies the station name within the host at which the part entity
    //              is located. If the part entity is On Station, this field shall
    //              specify the representation of the part’s location data fields.
    // Parameter:   StationName SN, void
    //************************************
    void SetStationName( StationName SN );
    StationName GetStationName() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::NamedLocationIdentifier::SetStationNumber
    //              KDIS::DATA_TYPE::NamedLocationIdentifier::GetStationNumber
    // Description: Specifies the number of the particular wingstation, cargo hold etc, at
    //              which the part is attached.
    // Parameter:   KUINT16 SN, void
    //************************************
    void SetStationNumber( KUINT16 SN );
    KUINT16 GetStationNumber() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::NamedLocationIdentifier::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::NamedLocationIdentifier::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::NamedLocationIdentifier::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const NamedLocationIdentifier & Value ) const;
    KBOOL operator != ( const NamedLocationIdentifier & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
