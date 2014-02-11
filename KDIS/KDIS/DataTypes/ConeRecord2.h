/*********************************************************************
Copyright 2013 Karl Jones
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

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

    ConeRecord2();

    ConeRecord2( KDataStream & stream ) throw( KException );

    ConeRecord2( KUINT8 Index, const WorldCoordinates & VertexLocation, const EulerAngles & Orientation,
                 const Vector & Velocity, const Vector & AngularVelocity, KFLOAT32 Height,
                 KFLOAT32 PeakAngle, KFLOAT32 DHeightOverDt, KFLOAT32 DPeakAngleOverDt );

    virtual ~ConeRecord2();

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

} // END namespace DATA_TYPES
} // END namespace KDIS
