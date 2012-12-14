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

    EulerAngles( void );

    // In Radians
    EulerAngles( KFLOAT32 Psi, KFLOAT32 Theta, KFLOAT32 Phi );

    EulerAngles( KDataStream & stream ) throw( KException );

    virtual ~EulerAngles( void );

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS

