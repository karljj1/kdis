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
    class:      GaussianPuffRecord
    created:    27:08:2009
    author:     Karl Jones

    purpose:    A geometry record representing a gaussian puff.
    size:       960 bits / 120 octets
*********************************************************************/

#pragma once

#include "./EnvironmentRecord.h"
#include "./WorldCoordinates.h"
#include "./EulerAngles.h"
#include "./Vector.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT GaussianPuffRecord : public EnvironmentRecord
{
protected:

    WorldCoordinates m_PuffLocation;

    WorldCoordinates m_OrigLocation;

    Vector m_Sigma;

    Vector m_DDTSigma;

    EulerAngles m_Ori;

    Vector m_Velocity;

    Vector m_AngularVelocity;

    KFLOAT32 m_f32CentHeight;

public:

    static const KUINT16 GAUSSIAN_PUFF_RECORD_SIZE = 120;

    GaussianPuffRecord( void );

    GaussianPuffRecord( KDataStream & stream ) throw( KException );

    GaussianPuffRecord( KUINT8 Index, const WorldCoordinates & PuffLocation, const WorldCoordinates & OriginationLocation,
                        const Vector & Sigma, const Vector & DDT, const EulerAngles & Orientation, const Vector & Velocity,
                        const Vector & AngularVelocity, KFLOAT32 CentroidHeight );

    virtual ~GaussianPuffRecord( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPuffRecord::SetPuffLocation
    //              KDIS::DATA_TYPE::GaussianPuffRecord::GetPuffLocation
    // Description: Specifies the location of the puff.
    // Parameter:   const WorldCoordinates & L, void
    //************************************
    void SetPuffLocation( const WorldCoordinates & L );
    const WorldCoordinates & GetPuffLocation() const;
    WorldCoordinates & GetPuffLocation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPuffRecord::SetOriginationLocation
    //              KDIS::DATA_TYPE::GaussianPuffRecord::GetOriginationLocation
    // Description: Specifies the origination location of the puff.
    // Parameter:   const WorldCoordinates & L, void
    //************************************
    void SetOriginationLocation( const WorldCoordinates & L );
    const WorldCoordinates & GetOriginationLocation() const;
    WorldCoordinates & GetOriginationLocation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPuffRecord::SetSigma
    //              KDIS::DATA_TYPE::GaussianPuffRecord::GetSigma
    // Description: X, Y, Z sigma for the gaussian puff.
    // Parameter:   const Vector & S, void
    //************************************
    void SetSigma( const Vector & S );
    const Vector & GetSigma() const;
    Vector & GetSigma();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPuffRecord::SetDOverDtSigma
    //              KDIS::DATA_TYPE::GaussianPuffRecord::GetDOverDtSigma
    // Description: d(Sigma)/dt
    // Parameter:   const Vector & S, void
    //************************************
    void SetDOverDtSigma( const Vector & S );
    const Vector & GetDOverDtSigma() const;
    Vector & GetDOverDtSigma();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPuffRecord::SetOrientation
    //              KDIS::DATA_TYPE::GaussianPuffRecord::GetOrientation
    // Description: Orientation of the puff.
    // Parameter:   const EulerAngles & O
    //************************************
    void SetOrientation( const EulerAngles & O );
    const EulerAngles & GetOrientation() const;
    EulerAngles & GetOrientation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPuffRecord::SetVelocity
    //              KDIS::DATA_TYPE::GaussianPuffRecord::GetVelocity
    // Description: Specifies the velocity of the puff.
    //              Represented as a Linear Velocity Vector.
    // Parameter:   const Vector & V, void
    //************************************
    void SetVelocity( const Vector & V );
    const Vector & GetVelocity() const;
    Vector & GetVelocity();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPuffRecord::SetAngularVelocity
    //              KDIS::DATA_TYPE::GaussianPuffRecord::GetAngularVelocity
    // Description: Specifies the angular velocity of the puff.
    //              Represented as a Linear Velocity Vector.
    // Parameter:   const Vector & V, void
    //************************************
    void SetAngularVelocity( const Vector & V );
    const Vector & GetAngularVelocity() const;
    Vector & GetAngularVelocity();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPuffRecord::SetCentroidHeight
    //              KDIS::DATA_TYPE::GaussianPuffRecord::GetCentroidHeight
    // Description: Specifies the centroid height of the puff in meters.
    // Parameter:   const KFLOAT32 H, void
    //************************************
    void SetCentroidHeight( KFLOAT32 H );
    KFLOAT32 GetCentroidHeight() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPuffRecord::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPuffRecord::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPuffRecord::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GaussianPuffRecord & Value )const;
    KBOOL operator != ( const GaussianPuffRecord & Value )const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
