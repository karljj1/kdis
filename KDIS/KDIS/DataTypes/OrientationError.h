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
    class:      OrientationError
    created:    29/07/2010
    author:     Karl Jones

    purpose:    The error components that are associated with the orientation
                measurement for an entity. These errors are measured in radians.

                The binary point is defined by the sub-protocol, but for the
                purposes of this standard the binary point shall be 8
                (i.e., the least significant bit shall represent 0.0039062 radians).

    size:       48 bits / 6 octets
*********************************************************************/

#pragma once

#include "./KFIXED.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT OrientationError : public DataTypeBase
{
protected:

    KFIXED16_8 m_AziErr;

    KFIXED16_8 m_ElvErr;

    KFIXED16_8 m_RotErr;

public:

    static const KUINT16 ORIENTATION_ERROR_SIZE = 6;

    OrientationError( void );

    OrientationError( KFIXED16_8 Azimuth, KFIXED16_8 Elevation, KFIXED16_8 Rotation );

    OrientationError( KDataStream & stream ) throw( KException );

    virtual ~OrientationError( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::OrientationError::SetAzimuthError
    //              KDIS::DATA_TYPE::OrientationError::GetAzimuthError
    // Description: Azimuth orientation error in radians.
    // Parameter:   KFIXED16_8 AE
    //************************************
    void SetAzimuthError( KFIXED16_8 AE );
    KFIXED16_8 GetAzimuthError() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::OrientationError::SetElevationError
    //              KDIS::DATA_TYPE::OrientationError::GetElevationError
    // Description: Elevation orientation error in radians.
    // Parameter:   KFIXED16_8 EE
    //************************************
    void SetElevationError( KFIXED16_8 EE );
    KFIXED16_8 GetElevationError() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::OrientationError::SetRotationError
    //              KDIS::DATA_TYPE::OrientationError::GetRotationError
    // Description: Rotation orientation error in radians.
    // Parameter:   KFIXED16_8 RE
    //************************************
    void SetRotationError( KFIXED16_8 RE );
    KFIXED16_8 GetRotationError() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::OrientationError::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::DataTypeBase::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::OrientationError::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const OrientationError & Value ) const;
    KBOOL operator != ( const OrientationError & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

