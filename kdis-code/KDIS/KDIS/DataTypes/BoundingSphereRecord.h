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
    class:      BoundingSphereRecord
    created:    18:08:2009
    author:     Karl Jones

    purpose:    A geometry record representing a bounding sphere.
    size:       320 bits / 40 octets
*********************************************************************/

#pragma once

#include "./EnvironmentRecord.h"
#include "./WorldCoordinates.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT BoundingSphereRecord : public EnvironmentRecord
{
protected:

    WorldCoordinates m_CentLocation;

    KFLOAT32 m_f32Rad;

    KUINT32 m_ui32Padding;

public:

    static const KUINT16 BOUNDING_SPHERE_RECORD_SIZE = 40;

    BoundingSphereRecord( void );

    BoundingSphereRecord( KDataStream & stream ) throw( KException );

    BoundingSphereRecord( KUINT8 Index, const WorldCoordinates & CentroidLocation, KFLOAT32 Radius );

    virtual ~BoundingSphereRecord( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::BoundingSphereRecord::SetCentroidLocation
    //              KDIS::DATA_TYPE::BoundingSphereRecord::GetCentroidLocation
    // Description: Specifies the location of the center of the sphere.
    // Parameter:   const WorldCoordinates & CL
    //************************************
    void SetCentroidLocation( const WorldCoordinates & CL );
    const WorldCoordinates & GetCentroidLocation() const;
    WorldCoordinates & GetCentroidLocation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::BoundingSphereRecord::SetRadius
    //              KDIS::DATA_TYPE::BoundingSphereRecord::GetRadius
    // Description: Specifies the radius of the spehere in meters.
    // Parameter:   KFLOAT32 R
    //************************************
    void SetRadius( KFLOAT32 R );
    KFLOAT32 GetRadius() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::BoundingSphereRecord::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::BoundingSphereRecord::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::BoundingSphereRecord::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const BoundingSphereRecord & Value )const;
    KBOOL operator != ( const BoundingSphereRecord & Value )const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
