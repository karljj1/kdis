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
    class:      PerimeterPointCoordinate
    created:    09/05/2010
    author:     Karl Jones

    purpose:    The location of each perimeter point, relative to the Minefield Location field.
    size:       64 bits / 8 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT PerimeterPointCoordinate : public DataTypeBase
{
protected:

    KFLOAT32 m_f32X;

    KFLOAT32 m_f32Y;

public:

    static const KUINT16 PERIMETER_POINT_COORDINATE_SIZE = 8;

    PerimeterPointCoordinate( void );

    PerimeterPointCoordinate( KFLOAT32 X, KFLOAT32 Y );

    PerimeterPointCoordinate( KDataStream & stream ) throw( KException );

    virtual ~PerimeterPointCoordinate( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::PerimeterPointCoordinate::SetX
    //              KDIS::DATA_TYPE::PerimeterPointCoordinate::GetX
    // Description: First Value / X
    // Parameter:   KFLOAT32  X, void
    //************************************
    void SetX( KFLOAT32 X );
    KFLOAT32 GetX() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::PerimeterPointCoordinate::SetY
    //              KDIS::DATA_TYPE::PerimeterPointCoordinate::GetY
    // Description: Second Value / Y
    // Parameter:   KFLOAT32 Y, void
    //************************************
    void SetY( KFLOAT32 Y );
    KFLOAT32 GetY() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::PerimeterPointCoordinate::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::PerimeterPointCoordinate::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::PerimeterPointCoordinate::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const PerimeterPointCoordinate & Value ) const;
    KBOOL operator != ( const PerimeterPointCoordinate & Value ) const;

    // Valid values 0 - X, 1 - Y. throws OUT_OF_BOUNDS exception for any other value.
    KFLOAT32 & operator[] ( KUINT16 i ) throw( KException );
    const KFLOAT32 & operator[]  ( KUINT16 i ) const throw( KException );
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
