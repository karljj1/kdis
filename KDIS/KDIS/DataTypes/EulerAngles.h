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
    class:      EulerAngles
    created:    18/0/2008
    author:     Karl Jones

    purpose:    Stores a vector
    size:       96 bits / 12 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT EulerAngles : public DataTypeBase
{
protected:

    KFLOAT32 m_f32Psi;

    KFLOAT32 m_f32Theta;

    KFLOAT32 m_f32Phi;

public:

    static const KUINT16 EULER_ANGLES_SIZE = 12;

    EulerAngles();

    // In Radians
    EulerAngles( KFLOAT32 Psi, KFLOAT32 Theta, KFLOAT32 Phi );

    EulerAngles( KDataStream & stream ) throw( KException );

    virtual ~EulerAngles();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EulerAngles::SetPsi
    //              KDIS::DATA_TYPE::EulerAngles::GetPsi
    // Description: Radians / Degrees
    // Parameter:   KFLOAT32 Psi
    //************************************
    void SetPsiInRadians( KFLOAT32 Psi );
    KFLOAT32 GetPsiInRadians() const;
    void SetPsiInDegrees( KFLOAT32 Psi );
    KFLOAT32 GetPsiInDegrees() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EulerAngles::SetTheta
    //              KDIS::DATA_TYPE::EulerAngles::GetTheta
    // Description: Radians / Degrees
    // Parameter:   KFLOAT32 Theta
    //************************************
    void SetThetaInRadians( KFLOAT32 Theta );
    KFLOAT32 GetThetaInRadians() const;
    void SetThetaInDegrees( KFLOAT32 Theta );
    KFLOAT32 GetThetaInDegrees() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EulerAngles::SetPhi
    //              KDIS::DATA_TYPE::EulerAngles::GetPhi
    // Description: Radians / Degrees
    // Parameter:   KFLOAT32 Phi
    //************************************
    void SetPhiInRadians( KFLOAT32 Phi );
    KFLOAT32 GetPhiInRadians() const;
    void SetPhiInDegrees( KFLOAT32 Phi );
    KFLOAT32 GetPhiInDegrees() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EulerAngles::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EulerAngles::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EulerAngles::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EulerAngles & Value ) const;
    KBOOL operator != ( const EulerAngles & Value ) const;
    EulerAngles operator * ( const EulerAngles & Value ) const;
    EulerAngles operator * ( KFLOAT64 Value ) const ;
    EulerAngles operator + ( const EulerAngles & Value ) const;
    EulerAngles & operator += ( const EulerAngles & Value );
    EulerAngles operator - ( const EulerAngles & Value ) const;
    EulerAngles & operator -= ( const EulerAngles & Value );

    // Valid values 0 - Psi, 1 - Theta, 2 - Phi. throws OUT_OF_BOUNDS exception for any other value.
    KFLOAT32 & operator[] ( KUINT16 i ) throw( KException );
    const KFLOAT32 & operator[] ( KUINT16 i ) const throw( KException );
};

} // END namespace DATA_TYPES
} // END namespace KDIS

