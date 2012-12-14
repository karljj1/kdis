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
    class:      PointRecord2
    created:    17:08:2009
    author:     Karl Jones

    purpose:    A geometry record representing a moving point.
    size:       384 bits / 48 octets
*********************************************************************/

#pragma once

#include "./PointRecord1.h"
#include "./Vector.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT PointRecord2 : public PointRecord1
{
protected:

    Vector m_Vel;

    KUINT32 m_ui32Padding;

public:

    static const KUINT16 POINT_RECORD_2_SIZE = 48;

    PointRecord2( void );

    PointRecord2( KDataStream & stream ) throw( KException );

    PointRecord2( KUINT8 Index, const WorldCoordinates & Location, const Vector & Velocity );

    virtual ~PointRecord2( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointRecord2::SetVelocity
    //              KDIS::DATA_TYPE::PointRecord2::GetVelocity
    // Description: Specifies the velocity of the point.
    //              Represented as a Linear Velocity Vector.
    // Parameter:   const Vector & V, void
    //************************************
    void SetVelocity( const Vector & V );
    const Vector & GetVelocity() const;
    Vector & GetVelocity();

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointRecord2::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointRecord2::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointRecord2::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const PointRecord2 & Value )const;
    KBOOL operator != ( const PointRecord2 & Value )const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
