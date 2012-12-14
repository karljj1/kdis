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
    class:      EllipsoidRecord1
    created:    18:08:2009
    author:     Karl Jones

    purpose:    A geometry record representing an elipsoid.
    size:       448 bits / 56 octets
*********************************************************************/

#pragma once

#include "./EnvironmentRecord.h"
#include "./WorldCoordinates.h"
#include "./EulerAngles.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT EllipsoidRecord1 : public EnvironmentRecord
{
protected:

    WorldCoordinates m_CentLocation;

    Vector m_Sigma;

    EulerAngles m_Ori;

public:

    static const KUINT16 ELIPSOID_RECORD_1_SIZE = 56;

    EllipsoidRecord1( void );

    EllipsoidRecord1( KDataStream & stream ) throw( KException );

    EllipsoidRecord1( KUINT8 Index, const WorldCoordinates & CentroidLocation,
                      const Vector & Sigma, const EulerAngles & Orientation );

    virtual ~EllipsoidRecord1( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EllipsoidRecord1::SetCentroidLocation
    //              KDIS::DATA_TYPE::EllipsoidRecord1::GetCentroidLocation
    // Description: Specifies the location of the center of the sphere.
    // Parameter:   const WorldCoordinates & CL
    //************************************
    void SetCentroidLocation( const WorldCoordinates & CL );
    const WorldCoordinates & GetCentroidLocation() const;
    WorldCoordinates & GetCentroidLocation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EllipsoidRecord1::SetSigma
    //              KDIS::DATA_TYPE::EllipsoidRecord1::GetSigma
    // Description: Sigma (X, Y, Z) for the ellipsoid.
    // Parameter:   const Vector & S
    //************************************
    void SetSigma( const Vector & S );
    const Vector & GetSigma() const;
    Vector & GetSigma();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EllipsoidRecord1::SetOrientation
    //              KDIS::DATA_TYPE::EllipsoidRecord1::GetOrientation
    // Description: Orientation for the ellipsoid.
    // Parameter:   const EulerAngles & O
    //************************************
    void SetOrientation( const EulerAngles & O );
    const EulerAngles & GetOrientation() const;
    EulerAngles & GetOrientation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EllipsoidRecord1::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EllipsoidRecord1::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EllipsoidRecord1::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EllipsoidRecord1 & Value )const;
    KBOOL operator != ( const EllipsoidRecord1 & Value )const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
