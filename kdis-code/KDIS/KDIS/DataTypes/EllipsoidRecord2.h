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
    class:      EllipsoidRecord2
    created:    18/08/2009
    author:     Karl Jones

    purpose:    A geometry record representing a moving elipsoid.
    size:       768 bits / 96 octets
*********************************************************************/

#pragma once

#include "./EllipsoidRecord1.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT EllipsoidRecord2 : public EllipsoidRecord1
{
protected:

    Vector m_DDT;

    Vector m_Velocity;

    Vector m_AngularVelocity;

    KUINT32 m_ui32Padding;

public:

    static const KUINT16 ELIPSOID_RECORD_2_SIZE = 96;

    EllipsoidRecord2( void );

    EllipsoidRecord2( KDataStream & stream ) throw( KException );

    EllipsoidRecord2( KUINT8 Index, const WorldCoordinates & CentroidLocation, const Vector & Sigma, const EulerAngles & Orientation,
                      const Vector & DDT, const Vector & Velocity, const Vector & AngularVelocity );

    virtual ~EllipsoidRecord2( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EllipsoidRecord2::SetDOverDt
    //              KDIS::DATA_TYPE::EllipsoidRecord2::GetDOverDt
    // Description: d(Sigma)/dt.
    // Parameter:   const Vector & S
    //************************************
    void SetDOverDt( const Vector & S );
    const Vector & GetDOverDt() const;
    Vector & GetSigma();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EllipsoidRecord2::SetVelocity
    //              KDIS::DATA_TYPE::EllipsoidRecord2::GetVelocity
    // Description: Specifies the velocity of the elipsoid.
    //              Represented as a Linear Velocity Vector.
    // Parameter:   const Vector & V, void
    //************************************
    void SetVelocity( const Vector & V );
    const Vector & GetVelocity() const;
    Vector & GetVelocity();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EllipsoidRecord2::SetAngularVelocity
    //              KDIS::DATA_TYPE::EllipsoidRecord2::GetAngularVelocity
    // Description: Specifies the angular velocity of the elipsoid.
    //              Represented as a Linear Velocity Vector.
    // Parameter:   const Vector & V, void
    //************************************
    void SetAngularVelocity( const Vector & V );
    const Vector & GetAngularVelocity() const;
    Vector & GetAngularVelocity();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EllipsoidRecord2::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EllipsoidRecord2::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EllipsoidRecord2::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EllipsoidRecord2 & Value )const;
    KBOOL operator != ( const EllipsoidRecord2 & Value )const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
