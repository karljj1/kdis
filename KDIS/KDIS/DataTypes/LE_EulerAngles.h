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

    LE_EulerAngles( void );

    // In Radians
    LE_EulerAngles( KFIXED8_3 Psi, KFIXED8_3 Theta, KFIXED8_3 Phi );

    LE_EulerAngles( KDataStream & stream ) throw( KException );

    virtual ~LE_EulerAngles( void );

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS

