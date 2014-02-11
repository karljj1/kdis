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
    class:      GaussianPlumeRecord
    created:    17:08:2009
    author:     Karl Jones

    purpose:    A geometry record representing a gaussian plume.
    size:       704 bits / 88 octets
*********************************************************************/

#pragma once

#include "./EnvironmentRecord.h"
#include "./WorldCoordinates.h"
#include "./EulerAngles.h"
#include "./Vector.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT GaussianPlumeRecord : public EnvironmentRecord
{
protected:

    WorldCoordinates m_SrcLocation;

    EulerAngles m_Ori;

    Vector m_PlumeLWH;

    Vector m_DDTLEH;

    KFLOAT32 m_f32LdEdgeCenHght;

    Vector m_LdEdgeVel;

    KUINT32 m_ui32Padding;

public:

    static const KUINT16 GAUSSIAN_PLUME_RECORD_SIZE = 88;

    GaussianPlumeRecord();

    GaussianPlumeRecord( KDataStream & stream ) throw( KException );

    GaussianPlumeRecord( KUINT8 Index, const WorldCoordinates & Location, const EulerAngles & Orientation,
                         const Vector & LWH, const Vector & DDT, KFLOAT32 LECH, const Vector & LEV );

    virtual ~GaussianPlumeRecord();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPlumeRecord::SetSourceLocation
    //              KDIS::DATA_TYPE::GaussianPlumeRecord::GetSourceLocation
    // Description: Specifies the plumes location.
    // Parameter:   const WorldCoordinates & L, void
    //************************************
    void SetSourceLocation( const WorldCoordinates & L );
    const WorldCoordinates & GetSourceLocation() const;
    WorldCoordinates & GetSourceLocation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPlumeRecord::SetOrientation
    //              KDIS::DATA_TYPE::GaussianPlumeRecord::GetOrientation
    // Description: Orientation of the plume.
    // Parameter:   const EulerAngles & O
    //************************************
    void SetOrientation( const EulerAngles & O );
    const EulerAngles & GetOrientation() const;
    EulerAngles & GetOrientation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPlumeRecord::SetPlumeLengthWidthHeight
    //              KDIS::DATA_TYPE::GaussianPlumeRecord::GetPlumeLengthWidthHeight
    // Description: The length, width and height of the plume in meters.
    //              X = Length, Y = Width, Z = Height
    // Parameter:   const Vector & LWH
    //************************************
    void SetPlumeLengthWidthHeight( const Vector & LWH );
    const Vector & GetPlumeLengthWidthHeight() const;
    Vector & GetPlumeLengthWidthHeight();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPlumeRecord::SetPlumeLengthWidthHeight
    //              KDIS::DATA_TYPE::GaussianPlumeRecord::GetPlumeLengthWidthHeight
    // Description: The length, width and height of the plume in meters.
    //              X = d(Plume Length)/dt
    //              Y = d(Plume Width)/dt
    //              Z = d(Plume Height)/dt
    // Parameter:   const Vector & DDT
    //************************************
    void SetDOverDtLengthWidthHeight( const Vector & DDT );
    const Vector & GetDOverDtLengthWidthHeight() const;
    Vector & GetDOverDtLengthWidthHeight();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPlumeRecord::SetLeadingEdgeCentroidHeight
    //              KDIS::DATA_TYPE::GaussianPlumeRecord::GetLeadingEdgeCentroidHeight
    // Description: The leading edge centroid height in meters.
    // Parameter:   KFLOAT32 LECH, void
    //************************************
    void SetLeadingEdgeCentroidHeight( KFLOAT32 LECH );
    KFLOAT32 GetLeadingEdgeCentroidHeight() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPlumeRecord::SetLeadingEdgeVelocity
    //              KDIS::DATA_TYPE::GaussianPlumeRecord::GetLeadingEdgeVelocity
    // Description: Specifies the velocity of the leading edge of the plume.
    //              Represented as a Linear Velocity Vector.
    // Parameter:   const Vector & DDT
    //************************************
    void SetLeadingEdgeVelocity( const Vector & LEV );
    const Vector & GetLeadingEdgeVelocity() const;
    Vector & GetLeadingEdgeVelocity();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPlumeRecord::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPlumeRecord::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GaussianPlumeRecord::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GaussianPlumeRecord & Value )const;
    KBOOL operator != ( const GaussianPlumeRecord & Value )const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
