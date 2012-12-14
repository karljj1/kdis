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

    ConeRecord1( void );

    ConeRecord1( KDataStream & stream ) throw( KException );

    ConeRecord1( KUINT8 Index, const WorldCoordinates & VertexLocation, const EulerAngles & Orientation,
                 KFLOAT32 Height, KFLOAT32 PeakAngle );

    virtual ~ConeRecord1( void );

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS
