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
    class:      LE_EulerAngles
    created:    16/07/2010
    author:     Karl Jones

    purpose:    Stores a vector for the LE family. The values have been reduced from 32 bit
                floats to 8 bit fixed binaries.

                Note: The DIS Standard does not state where the binary point is located in 8
                bit fixed binaries, I have assumed bit 3 like the 16 bit equivalent.
    size:       24 bits / 3 octets
*********************************************************************/

#pragma once

#include "./KFIXED.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT LE_EulerAngles : public DataTypeBase
{
protected:

    KFIXED8_3 m_Psi;

    KFIXED8_3 m_Theta;

    KFIXED8_3 m_Phi;

public:

    static const KUINT16 LE_EULER_ANGLES_SIZE = 3;

    LE_EulerAngles();

    // In Radians
    LE_EulerAngles( KFIXED8_3 Psi, KFIXED8_3 Theta, KFIXED8_3 Phi );

    LE_EulerAngles( KDataStream & stream ) throw( KException );

    virtual ~LE_EulerAngles();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_EulerAngles::SetPsi
    //              KDIS::DATA_TYPE::LE_EulerAngles::GetPsi
    // Description: Radians / Degrees
    // Parameter:   KFIXED8_3, void
    //************************************
    void SetPsiInRadians( KFIXED8_3 Psi );
    KFIXED8_3 GetPsiInRadians() const;
    void SetPsiInDegrees( KFIXED8_3 Psi );
    KFIXED8_3 GetPsiInDegrees() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_EulerAngles::SetTheta
    //              KDIS::DATA_TYPE::LE_EulerAngles::GetTheta
    // Description: Radians / Degrees
    // Parameter:   KFIXED8_3, void
    //************************************
    void SetThetaInRadians( KFIXED8_3 Theta );
    KFIXED8_3 GetThetaInRadians() const;
    void SetThetaInDegrees( KFIXED8_3 Theta );
    KFIXED8_3 GetThetaInDegrees() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_EulerAngles::SetPhi
    //              KDIS::DATA_TYPE::LE_EulerAngles::GetPhi
    // Description: Radians / Degrees
    // Parameter:   KFIXED8_3, void
    //************************************
    void SetPhiInRadians( KFIXED8_3 Phi );
    KFIXED8_3 GetPhiInRadians() const;
    void SetPhiInDegrees( KFIXED8_3 Phi );
    KFIXED8_3 GetPhiInDegrees() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_EulerAngles::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_EulerAngles::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_EulerAngles::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const LE_EulerAngles & Value ) const;
    KBOOL operator != ( const LE_EulerAngles & Value ) const;
    LE_EulerAngles operator * ( const LE_EulerAngles & Value ) const;
    LE_EulerAngles operator * ( KFLOAT64 Value ) const ;
    LE_EulerAngles operator + ( const LE_EulerAngles & Value ) const;
    LE_EulerAngles & operator += ( const LE_EulerAngles & Value );
    LE_EulerAngles operator - ( const LE_EulerAngles & Value ) const;
    LE_EulerAngles & operator -= ( const LE_EulerAngles & Value );

    // Valid values 0 - Psi, 1 - Theta, 2 - Phi. throws OUT_OF_BOUNDS exception for any other value.
    KFIXED8_3 & operator[] ( KUINT16 i ) throw( KException );
    const KFIXED8_3 & operator[] ( KUINT16 i ) const throw( KException );
};

} // END namespace DATA_TYPES
} // END namespace KDIS

