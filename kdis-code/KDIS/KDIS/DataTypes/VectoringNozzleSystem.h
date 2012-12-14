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
    class:      VectoringNozzleSystem
    created:    2009/01/15
    author:     Karl Jones

    purpose:    Contains infomation describin the propulsion system
                of the entity.
    size:       64 bits / 8 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT VectoringNozzleSystem : public DataTypeBase
{
protected:

    KFLOAT32 m_f32HDeflAngle;

    KFLOAT32 m_f32VDeflAngle;

public:

    static const KUINT16 VECTORING_NOZZLE_SYSTEM_SIZE = 8;

    VectoringNozzleSystem( void );

    VectoringNozzleSystem( KDataStream & stream ) throw( KException );

    VectoringNozzleSystem( KFLOAT32 HorizontalDeflectionAngle, KFLOAT32 VerticalDeflectionAngle );

    virtual ~VectoringNozzleSystem( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::VectoringNozzleSystem::SetHorizontalDeflectionAngle
    //              KDIS::DATA_TYPE::VectoringNozzleSystem::GetHorizontalDeflectionAngle
    // Description: Nozzle deflection angle in degrees in the horizontal body axis
    //              of the entity.
    // Parameter:   KFLOAT32  HDA, void
    //************************************
    void SetHorizontalDeflectionAngle( KFLOAT32 HDA );
    KFLOAT32 GetHorizontalDeflectionAngle() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::VectoringNozzleSystem::SetVerticalDeflectionAngle
    //              KDIS::DATA_TYPE::VectoringNozzleSystem::GetVerticalDeflectionAngle
    // Description: Nozzle deflection angle in degrees in the horizontal body axis
    //              of the entity.
    // Parameter:   KFLOAT32 VDA, void
    //************************************
    void SetVerticalDeflectionAngle( KFLOAT32 VDA );
    KFLOAT32 GetVerticalDeflectionAngle() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::VectoringNozzleSystem::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::VectoringNozzleSystem::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::VectoringNozzleSystem::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const VectoringNozzleSystem & Value ) const;
    KBOOL operator != ( const VectoringNozzleSystem & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

