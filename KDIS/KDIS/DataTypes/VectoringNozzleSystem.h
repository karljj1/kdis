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
    class:      VectoringNozzleSystem
    created:    15/01/2009
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

    VectoringNozzleSystem();

    VectoringNozzleSystem( KDataStream & stream ) throw( KException );

    VectoringNozzleSystem( KFLOAT32 HorizontalDeflectionAngle, KFLOAT32 VerticalDeflectionAngle );

    virtual ~VectoringNozzleSystem();

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

} // END namespace DATA_TYPES
} // END namespace KDIS

