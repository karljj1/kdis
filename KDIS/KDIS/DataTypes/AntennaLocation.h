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
    class:      AntennaLocation
    created:    2008/10/21

    author:     Karl Jones

    purpose:    Specifies location of antennas radiating portion in world
                coordinates and entity coordinates.
    size:       288 bits / 36 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./WorldCoordinates.h"
#include "./Vector.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT AntennaLocation : public DataTypeBase
{
protected:

    WorldCoordinates m_AntennaLocation;

    Vector m_RelativeAntennaLocation;

public:

    static const KUINT16 ANTENNA_LOCATION_SIZE = 36;

    AntennaLocation( void );

    AntennaLocation( KDataStream & stream )throw( KException );

    AntennaLocation( const WorldCoordinates & Location, const Vector & RelativeLocation );

    virtual ~AntennaLocation( void );

    //************************************
    // FullName:    KDIS::DataTypes::AntennaLocation::SetAntennaLocation
    //              KDIS::DataTypes::AntennaLocation::GetAntennaLocation
    // Description: Antenna world location
    // Parameter:   const WorldCoordinates & AL
    //************************************
    void SetAntennaLocation( const WorldCoordinates & AL );
    const WorldCoordinates & GetAntennaLocation() const;
    WorldCoordinates & GetAntennaLocation();

    //************************************
    // FullName:    KDIS::DataTypes::SetRelativeAntennaLocation
    //              KDIS::DataTypes::GetRelativeAntennaLocation
    // Description: Antenna entity location. Represented as Entity Coordinate Vector
    // Parameter:   const Vector & RAL
    //************************************
    void SetRelativeAntennaLocation( const Vector & RAL );
    const Vector & GetRelativeAntennaLocation() const;
    Vector & GetRelativeAntennaLocation();

    //************************************
    // FullName:    KDIS::DataTypes::AntennaLocation::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DataTypes::AntennaLocation::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DataTypes::AntennaLocation::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const AntennaLocation & Value ) const;
    KBOOL operator != ( const AntennaLocation & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
