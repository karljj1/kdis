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
    class:      RectangularVolumeRecord3
    created:    27/08/2009
    author:     Karl Jones

    purpose:    A geometry record representing a rectangular volume.
    size:       448 bits / 56 octets
*********************************************************************/

#pragma once

#include "./EnvironmentRecord.h"
#include "./WorldCoordinates.h"
#include "./Vector.h"
#include "./EulerAngles.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT RectangularVolumeRecord3 : public EnvironmentRecord
{
protected:

    WorldCoordinates m_CentLocation;

    Vector m_RecLength;

    EulerAngles m_Ori;

public:

    static const KUINT16 RECTANGLE_VOLUME_RECORD_3_SIZE = 56;

    RectangularVolumeRecord3();

    RectangularVolumeRecord3( KDataStream & stream ) throw( KException );

    RectangularVolumeRecord3( KUINT8 Index, const WorldCoordinates & CenterLocation, const Vector & RectangleLength,
                              const EulerAngles & Orientation );

    virtual ~RectangularVolumeRecord3();

    //************************************
    // FullName:    KDIS::DATA_TYPE::RectangularVolumeRecord3::SetCenterLocation
    //              KDIS::DATA_TYPE::RectangularVolumeRecord3::GetCenterLocation
    // Description: Specifies the location of the center of the rectangle.
    // Parameter:   const WorldCoordinates & RL
    //************************************
    void SetCenterLocation( const WorldCoordinates & RL );
    const WorldCoordinates & GetCenterLocation() const;
    WorldCoordinates & GetCenterLocation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::RectangularVolumeRecord3::SetRectangleLength
    //              KDIS::DATA_TYPE::RectangularVolumeRecord3::GetRectangleLength
    // Description: Specifies the length of the rectangle.
    // Parameter:   const Vector & L
    //************************************
    void SetRectangleLength( const Vector & L );
    const Vector & GetRectangleLength() const;
    Vector & GetRectangleLength();

    //************************************
    // FullName:    KDIS::DATA_TYPE::RectangularVolumeRecord3::SetOrientation
    //              KDIS::DATA_TYPE::RectangularVolumeRecord3::GetOrientation
    // Description: Orientation of the rectangle.
    // Parameter:   const EulerAngles & O
    //************************************
    void SetOrientation( const EulerAngles & O );
    const EulerAngles & GetOrientation() const;
    EulerAngles & GetOrientation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::RectangularVolumeRecord3::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RectangularVolumeRecord3::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::RectangularVolumeRecord3::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const RectangularVolumeRecord3 & Value )const;
    KBOOL operator != ( const RectangularVolumeRecord3 & Value )const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
