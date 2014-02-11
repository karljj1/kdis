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
    class:      ConeRecord1
    created:    19:08:2009
    author:     Karl Jones

    purpose:    A geometry record representing an cone.
    size:       448 bits / 56 octets
*********************************************************************/

#pragma once

#include "./EnvironmentRecord.h"
#include "./WorldCoordinates.h"
#include "./EulerAngles.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT ConeRecord1 : public EnvironmentRecord
{
protected:

    WorldCoordinates m_Loc;

    EulerAngles m_Ori;

    KFLOAT32 m_f32Height;

    KFLOAT32 m_f32PeakAngle;

    KUINT32 m_ui32Padding;

public:

    static const KUINT16 CONE_RECORD_1_SIZE = 56;

    ConeRecord1();

    ConeRecord1( KDataStream & stream ) throw( KException );

    ConeRecord1( KUINT8 Index, const WorldCoordinates & VertexLocation, const EulerAngles & Orientation,
                 KFLOAT32 Height, KFLOAT32 PeakAngle );

    virtual ~ConeRecord1();

    //************************************
    // FullName:    KDIS::DATA_TYPE::ConeRecord1::SetVertexLocation
    //              KDIS::DATA_TYPE::ConeRecord1::GetVertexLocation
    // Description: Specifies the location of the cones vertex.
    // Parameter:   const WorldCoordinates & VL
    //************************************
    void SetVertexLocation( const WorldCoordinates & VL );
    const WorldCoordinates & GetVertexLocation() const;
    WorldCoordinates & GetVertexLocation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::ConeRecord1::SetOrientation
    //              KDIS::DATA_TYPE::ConeRecord1::GetOrientation
    // Description: Orientation for the cone.
    // Parameter:   const EulerAngles & O
    //************************************
    void SetOrientation( const EulerAngles & O );
    const EulerAngles & GetOrientation() const;
    EulerAngles & GetOrientation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::ConeRecord1::SetHeight
    //              KDIS::DATA_TYPE::ConeRecord1::GetHeight
    // Description: Height of the cone in meters.
    // Parameter:   KFLOAT32 H
    //************************************
    void SetHeight( KFLOAT32 H );
    KFLOAT32 GetHeight() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ConeRecord1::SetPeakAngle
    //              KDIS::DATA_TYPE::ConeRecord1::GetPeakAngle
    // Description: The cones peak angle. Measured in radians i presume,
    //              it does not say in SISO-REF-010-2006.
    // Parameter:   KFLOAT32 H
    //************************************
    void SetPeakAngle( KFLOAT32 PA );
    KFLOAT32 GetPeakAngle() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ConeRecord1::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ConeRecord1::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ConeRecord1::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const ConeRecord1 & Value )const;
    KBOOL operator != ( const ConeRecord1 & Value )const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
