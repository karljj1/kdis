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
    class:      BoundingSphereRecord
    created:    18:08:2009
    author:     Karl Jones

    purpose:    A geometry record representing a bounding sphere.
    size:       320 bits / 40 octets
*********************************************************************/

#pragma once

#include "./EnvironmentRecord.h"
#include "./WorldCoordinates.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT BoundingSphereRecord : public EnvironmentRecord
{
protected:

    WorldCoordinates m_CentLocation;

    KFLOAT32 m_f32Rad;

    KUINT32 m_ui32Padding;

public:

    static const KUINT16 BOUNDING_SPHERE_RECORD_SIZE = 40;

    BoundingSphereRecord();

    BoundingSphereRecord( KDataStream & stream ) throw( KException );

    BoundingSphereRecord( KUINT8 Index, const WorldCoordinates & CentroidLocation, KFLOAT32 Radius );

    virtual ~BoundingSphereRecord();

    //************************************
    // FullName:    KDIS::DATA_TYPE::BoundingSphereRecord::SetCentroidLocation
    //              KDIS::DATA_TYPE::BoundingSphereRecord::GetCentroidLocation
    // Description: Specifies the location of the center of the sphere.
    // Parameter:   const WorldCoordinates & CL
    //************************************
    void SetCentroidLocation( const WorldCoordinates & CL );
    const WorldCoordinates & GetCentroidLocation() const;
    WorldCoordinates & GetCentroidLocation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::BoundingSphereRecord::SetRadius
    //              KDIS::DATA_TYPE::BoundingSphereRecord::GetRadius
    // Description: Specifies the radius of the spehere in meters.
    // Parameter:   KFLOAT32 R
    //************************************
    void SetRadius( KFLOAT32 R );
    KFLOAT32 GetRadius() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::BoundingSphereRecord::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::BoundingSphereRecord::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::BoundingSphereRecord::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const BoundingSphereRecord & Value )const;
    KBOOL operator != ( const BoundingSphereRecord & Value )const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
