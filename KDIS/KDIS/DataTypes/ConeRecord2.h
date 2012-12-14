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
    class:      ConeRecord2
    created:    21:08:2009
    author:     Karl Jones

    purpose:    A geometry record representing a moving cone.
    size:       704 bits / 88 octets
*********************************************************************/

#pragma once

#include "./ConeRecord1.h"
#include "./Vector.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT ConeRecord2 : public ConeRecord1
{
protected:

    Vector m_Velocity;

    Vector m_AngularVelocity;

    KFLOAT32 m_f32ddtHeight;

    KFLOAT32 m_f32ddtPeak;

public:

    static const KUINT16 CONE_RECORD_2_SIZE = 88;

    ConeRecord2( void );

    ConeRecord2( KDataStream & stream ) throw( KException );

    ConeRecord2( KUINT8 Index, const WorldCoordinates & VertexLocation, const EulerAngles & Orientation,
                 const Vector & Velocity, const Vector & AngularVelocity, KFLOAT32 Height,
                 KFLOAT32 PeakAngle, KFLOAT32 DHeightOverDt, KFLOAT32 DPeakAngleOverDt );

    virtual ~ConeRecord2( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ConeRecord2::SetVelocity
    //              KDIS::DATA_TYPE::ConeRecord2::GetVelocity
    // Description: Specifies the velocity of the cone.
    //              Represented as a Linear Velocity Vector.
    // Parameter:   const Vector & V, void
    //************************************
    void SetVelocity( const Vector & V );
    const Vector & GetVelocity() const;
    Vector & GetVelocity();

    //************************************
    // FullName:    KDIS::DATA_TYPE::ConeRecord2::SetAngularVelocity
    //              KDIS::DATA_TYPE::ConeRecord2::GetAngularVelocity
    // Description: Specifies the angular velocity of the cone.
    //              Represented as a Linear Velocity Vector.
    // Parameter:   const Vector & V, void
    //************************************
    void SetAngularVelocity( const Vector & V );
    const Vector & GetAngularVelocity() const;
    Vector & GetAngularVelocity();

    //************************************
    // FullName:    KDIS::DATA_TYPE::ConeRecord2::SetDHeightOverDt
    //              KDIS::DATA_TYPE::ConeRecord2::GetDHeightOverDt
    // Description: d(Height)/dt.
    // Parameter:   KFLOAT32 DDT, void
    //************************************
    void SetDHeightOverDt( KFLOAT32 DDT );
    KFLOAT32 GetDHeightOverDt() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ConeRecord2::SetDPeakAngleOverDt
    //              KDIS::DATA_TYPE::ConeRecord2::GetDPeakAngleOverDt
    // Description: d(Peak Angle)/dt.
    // Parameter:   KFLOAT32 DDT, void
    //************************************
    void SetDPeakAngleOverDt( KFLOAT32 DDT );
    KFLOAT32 GetDPeakAngleOverDt() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ConeRecord2::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ConeRecord2::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ConeRecord2::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const ConeRecord2 & Value )const;
    KBOOL operator != ( const ConeRecord2 & Value )const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
