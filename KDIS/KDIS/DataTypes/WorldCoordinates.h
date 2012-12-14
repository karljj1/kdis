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
    class:      WorldCoordinates
    created:    18/08/2008
    author:     Karl Jones

    purpose:    Stores a location vector. WGS84, geocentric
    size:       192 bits / 24 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./Vector.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT WorldCoordinates : public DataTypeBase
{
protected:

    KFLOAT64 m_f64X;

    KFLOAT64 m_f64Y;

    KFLOAT64 m_f64Z;

public:

    static const KUINT16 WORLD_COORDINATES_SIZE = 24;

    WorldCoordinates( void );

    WorldCoordinates( KDataStream & stream ) throw( KException );

    WorldCoordinates( KFLOAT64 X, KFLOAT64 Y, KFLOAT64 Z );

    virtual ~WorldCoordinates( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::WorldCoordinates::SetX
    //              KDIS::DATA_TYPE::WorldCoordinates::GetX
    // Description: X
    // Parameter:   KFLOAT64 X
    //************************************
    void SetX( KFLOAT64 X );
    KFLOAT64 GetX() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::WorldCoordinates::SetY
    //              KDIS::DATA_TYPE::WorldCoordinates::GetY
    // Description: Y
    // Parameter:   KFLOAT64 Y
    //************************************
    void SetY( KFLOAT64 Y );
    KFLOAT64 GetY() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::WorldCoordinates::SetZ
    //              KDIS::DATA_TYPE::WorldCoordinates::GetZ
    // Description: Z
    // Parameter:   KFLOAT64 Z
    //************************************
    void SetZ( KFLOAT64 Z );
    KFLOAT64 GetZ() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::WorldCoordinates::GetDistance
    // Description: Calculates the distance from this WorldCoordinates to an other. 
    //************************************
	KFLOAT64 GetDistance( const WorldCoordinates & Other );

    //************************************
    // FullName:    KDIS::DATA_TYPE::WorldCoordinates::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::WorldCoordinates::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::WorldCoordinates::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const WorldCoordinates & Value ) const;
    KBOOL operator != ( const WorldCoordinates & Value ) const;
    WorldCoordinates operator * ( const WorldCoordinates & Value ) const;
    WorldCoordinates operator * ( KFLOAT64 Value ) const;
    WorldCoordinates operator + ( const WorldCoordinates & Value ) const;
    WorldCoordinates operator + ( const Vector & Value ) const;
    WorldCoordinates & operator += ( const Vector & Value );
    const WorldCoordinates & operator = ( const Vector & Value );
    WorldCoordinates operator - ( const WorldCoordinates & Value ) const;
    WorldCoordinates & operator -= ( const WorldCoordinates & Value );

    // Valid values 0 - X, 1 - Y, 2 - Z. throws OUT_OF_BOUNDS exception for any other value.
    KFLOAT64 & operator[] ( KUINT16 i ) throw( KException );
    const KFLOAT64 & operator[] ( KUINT16 i ) const throw( KException );
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

