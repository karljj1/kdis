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
    class:      RectangularVolumeRecord3
    created:    27:08:2009
    author:     Karl Jones

    purpose:    A geometry record representing a rectangular volume.
    size:       448 bits / 56 octets
*********************************************************************/

#pragma once

#include "./EnvironmentRecord.h"
#include "./WorldCoordinates.h"
#include "./Vector.h"
#include "./EulerAngles.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT RectangularVolumeRecord3 : public EnvironmentRecord
{
protected:

    WorldCoordinates m_CentLocation;

    Vector m_RecLength;

    EulerAngles m_Ori;

public:

    static const KUINT16 RECTANGLE_VOLUME_RECORD_3_SIZE = 56;

    RectangularVolumeRecord3( void );

    RectangularVolumeRecord3( KDataStream & stream ) throw( KException );

    RectangularVolumeRecord3( KUINT8 Index, const WorldCoordinates & CenterLocation, const Vector & RectangleLength,
                              const EulerAngles & Orientation );

    virtual ~RectangularVolumeRecord3( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::RectangularVolumeRecord3::SetCenterLocation
    //              KDIS::DATA_TYPE::RectangularVolumeRecord3::GetCenterLocation
    // Description: Specifies the location of the center of the rectangle.
    // Parameter:   const WorldCoordinates & RL
    //************************************
    void SetCenterLocation( const WorldCoordinates & RL );
    const WorldCoordinates & GetCenterLocation() const;
    WorldCoordinates & GetCenterLocation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::RectangularVolumeRecord3::SetRectangleLength
    //              KDIS::DATA_TYPE::RectangularVolumeRecord3::GetRectangleLength
    // Description: Specifies the length of the rectangle.
    // Parameter:   const Vector & L
    //************************************
    void SetRectangleLength( const Vector & L );
    const Vector & GetRectangleLength() const;
    Vector & GetRectangleLength();

    //************************************
    // FullName:    KDIS::DATA_TYPE::RectangularVolumeRecord3::SetOrientation
    //              KDIS::DATA_TYPE::RectangularVolumeRecord3::GetOrientation
    // Description: Orientation of the rectangle.
    // Parameter:   const EulerAngles & O
    //************************************
    void SetOrientation( const EulerAngles & O );
    const EulerAngles & GetOrientation() const;
    EulerAngles & GetOrientation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::RectangularVolumeRecord3::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RectangularVolumeRecord3::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::RectangularVolumeRecord3::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const RectangularVolumeRecord3 & Value )const;
    KBOOL operator != ( const RectangularVolumeRecord3 & Value )const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
