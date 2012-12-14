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
    class:      LE_Vector
    created:    29/07/2010
    author:     Karl Jones

    purpose:    Template Vector class used for Live Entity PDU's.
                Supports KFIXED16_3 and KFIXED8_3 data types.
                To add support for other's see the bottom of the cpp file.
*********************************************************************/

#pragma once

#include "./KFIXED.h"

namespace KDIS {
namespace DATA_TYPE {

template<class Type>
class KDIS_EXPORT LE_Vector : public DataTypeBase
{
protected:

    Type m_X;

    Type m_Y;

    Type m_Z;

public:

    static const KUINT16 LE_VECTOR_SIZE = sizeof( Type ) * 3;

    LE_Vector( void );

    LE_Vector( Type X, Type Y, Type Z );

    LE_Vector( KDataStream & stream ) throw( KException );

    virtual ~LE_Vector( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_Vector::SetX
    //              KDIS::DATA_TYPE::LE_Vector::GetX
    // Description: First Value / X
    // Parameter:   Type  X
    //************************************
    void SetX( Type X );
    Type GetX() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_Vector::SetY
    //              KDIS::DATA_TYPE::LE_Vector::GetY
    // Description: Second Value / Y
    // Parameter:   Type Y
    //************************************
    void SetY( Type Y );
    Type GetY() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_Vector::SetZ
    //              KDIS::DATA_TYPE::LE_Vector::GetZ
    // Description: Third Value / Z
    // Parameter:   Type Z
    //************************************
    void SetZ( Type Z );
    Type GetZ() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_Vector::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_Vector::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_Vector::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const LE_Vector & Value ) const;
    KBOOL operator != ( const LE_Vector & Value ) const;
    LE_Vector operator * ( const LE_Vector & Value ) const;
    LE_Vector operator * ( KFLOAT64 Value ) const;
    LE_Vector operator + ( const LE_Vector & Value ) const;
    LE_Vector & operator += ( const LE_Vector & Value );
    LE_Vector operator - ( const LE_Vector & Value ) const;
    LE_Vector & operator -= ( const LE_Vector & Value );

    // Valid values 0 - X, 1 - Y, 2 - Z. throws OUT_OF_BOUNDS exception for any other value.
    Type & operator[] ( KUINT16 i ) throw( KException );
    const Type & operator[]  ( KUINT16 i ) const throw( KException );
};

// Predefined LE_Vector types.
// LE_Vectorx_y
// x = Size of data type in bits
// y = The position of the binary point.
typedef LE_Vector<KFIXED16_3> LE_Vector8_3;
typedef LE_Vector<KFIXED8_3> LE_Vector16_3;

}; // END namespace DATA_TYPES
}; // END namespace KDIS
