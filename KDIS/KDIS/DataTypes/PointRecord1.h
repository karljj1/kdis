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
    class:      PointRecord1
    created:    17:08:2009
    author:     Karl Jones

    purpose:    A geometry record representing a point.
    size:       256 bits / 32 octets
*********************************************************************/

#pragma once

#include "./EnvironmentRecord.h"
#include "./WorldCoordinates.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT PointRecord1 : public EnvironmentRecord
{
protected:

    WorldCoordinates m_Location;

public:

    static const KUINT16 POINT_RECORD_1_SIZE = 32;

    PointRecord1( void );

    PointRecord1( KDataStream & stream ) throw( KException );

    PointRecord1( KUINT8 Index, const WorldCoordinates & Location );

    virtual ~PointRecord1( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointRecord1::SetLocation
    //              KDIS::DATA_TYPE::PointRecord1::GetLocation
    // Description: Specifies the points location.
    // Parameter:   const WorldCoordinates & L, void
    //************************************
    void SetLocation( const WorldCoordinates & L );
    const WorldCoordinates & GetLocation() const;
    WorldCoordinates & GetLocation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointRecord1::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointRecord1::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointRecord1::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const PointRecord1 & Value )const;
    KBOOL operator != ( const PointRecord1 & Value )const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
