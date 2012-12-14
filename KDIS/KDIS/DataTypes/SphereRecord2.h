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
    class:      SphereRecord2
    created:    18:08:2009
    author:     Karl Jones

    purpose:    A geometry record representing a moving sphere.
    size:       512 bits / 64 octets
*********************************************************************/

#pragma once

#include "./SphereRecord1.h"
#include "./Vector.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT SphereRecord2 : public SphereRecord1
{
protected:

    KFLOAT32 m_f32ddt;

    Vector m_Velocity;

    Vector m_AngularVelocity;

public:

    static const KUINT16 SPHERE_RECORD_2_SIZE = 64;

    SphereRecord2( void );

    SphereRecord2( KDataStream & stream ) throw( KException );

    SphereRecord2( KUINT8 Index, const WorldCoordinates & CentroidLocation, KFLOAT32 Radius,
                   KFLOAT32 DDT, const Vector & Velocity, const Vector & AngularVelocity );

    virtual ~SphereRecord2( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::SphereRecord2::SetDOverDt
    //              KDIS::DATA_TYPE::SphereRecord2::GetDOverDt
    // Description: d(Radius)/dt.
    // Parameter:   KFLOAT32 DDT, void
    //************************************
    void SetDOverDt( KFLOAT32 DDT );
    KFLOAT32 GetDOverDt() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SphereRecord2::SetVelocity
    //              KDIS::DATA_TYPE::SphereRecord2::GetVelocity
    // Description: Specifies the velocity of the sphere.
    //              Represented as a Linear Velocity Vector.
    // Parameter:   const Vector & V, void
    //************************************
    void SetVelocity( const Vector & V );
    const Vector & GetVelocity() const;
    Vector & GetVelocity();

    //************************************
    // FullName:    KDIS::DATA_TYPE::SphereRecord2::SetAngularVelocity
    //              KDIS::DATA_TYPE::SphereRecord2::GetAngularVelocity
    // Description: Specifies the angular velocity of the sphere.
    //              Represented as a Linear Velocity Vector.
    // Parameter:   const Vector & V, void
    //************************************
    void SetAngularVelocity( const Vector & V );
    const Vector & GetAngularVelocity() const;
    Vector & GetAngularVelocity();

    //************************************
    // FullName:    KDIS::DATA_TYPE::SphereRecord2::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SphereRecord2::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::SphereRecord2::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const SphereRecord2 & Value )const;
    KBOOL operator != ( const SphereRecord2 & Value )const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
