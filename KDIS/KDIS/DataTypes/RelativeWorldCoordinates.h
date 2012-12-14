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
    class:      RelativeWorldCoordinates
    created:    02/07/2010
    author:     Karl Jones

    purpose:    Location of the origin of the LE’s coordinate system.
    size:       64 bits / 8 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./KFIXED.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT RelativeWorldCoordinates: public DataTypeBase
{
protected:

    KUINT16 m_ui16RefPnt;

    KFIXED16_3 m_DelX;

    KFIXED16_3 m_DelY;

    KFIXED16_3 m_DelZ;

public:

    static const KUINT16 RELATVE_WORLD_COORDINATES_SIZE = 8;

    RelativeWorldCoordinates( void );

    RelativeWorldCoordinates( KUINT16 RefPnt, KFIXED16_3 DelX, KFIXED16_3 DelY, KFIXED16_3 DelZ );

    RelativeWorldCoordinates( KDataStream & stream ) throw( KException );

    virtual ~RelativeWorldCoordinates( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::RelativeWorldCoordinates::SetReferencePoint
    //              KDIS::DATA_TYPE::RelativeWorldCoordinates::GetReferencePoint
    // Description: Identifies the number of the reference point against which
    //              e Delta-X, Delta-Y, and Delta-Z distances are calculated.
    // Parameter:   KUINT16 RP
    //************************************
    void SetReferencePoint( KUINT16 RP );
    KUINT16 GetReferencePoint() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RelativeWorldCoordinates::SetDelta
    //              KDIS::DATA_TYPE::RelativeWorldCoordinates::GetDelta
    // Description: The difference between LE’s X, Y and Z direction coordinate and the
    //              X, Y and Z direction coordinate of the reference point.
    // Parameter:   KFIXED16_3
    //************************************
    void SetDeltaX( KFIXED16_3 X );
    KFIXED16_3 GetDeltaX() const;
    void SetDeltaY( KFIXED16_3 Y );
    KFIXED16_3 GetDeltaY() const;
    void SetDeltaZ( KFIXED16_3 X );
    KFIXED16_3 GetDeltaZ() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RelativeWorldCoordinates::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RelativeWorldCoordinates::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::RelativeWorldCoordinates::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const RelativeWorldCoordinates  & Value ) const;
    KBOOL operator != ( const RelativeWorldCoordinates  & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

