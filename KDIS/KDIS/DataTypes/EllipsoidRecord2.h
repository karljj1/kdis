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

    EllipsoidRecord2();

    EllipsoidRecord2( KDataStream & stream ) throw( KException );

    EllipsoidRecord2( KUINT8 Index, const WorldCoordinates & CentroidLocation, const Vector & Sigma, const EulerAngles & Orientation,
                      const Vector & DDT, const Vector & Velocity, const Vector & AngularVelocity );

    virtual ~EllipsoidRecord2();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EllipsoidRecord2::SetDOverDt
    //              KDIS::DATA_TYPE::EllipsoidRecord2::GetDOverDt
    // Description: d(Sigma)/dt.
    // Parameter:   const Vector & S
    //************************************
    void SetDOverDt( const Vector & S );
    const Vector & GetDOverDt() const;
    Vector & GetDOverDt();

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

} // END namespace DATA_TYPES
} // END namespace KDIS
