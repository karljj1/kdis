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

    OrientationError();

    OrientationError( KFIXED16_8 Azimuth, KFIXED16_8 Elevation, KFIXED16_8 Rotation );

    OrientationError( KDataStream & stream ) throw( KException );

    virtual ~OrientationError();

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

} // END namespace DATA_TYPES
} // END namespace KDIS

