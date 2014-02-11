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
    class:      DeadReckoningParameter
    created:    2008/09/18
    author:     Karl Jones

    purpose:    Parameters for dead reckoning the position and orientation
                of the entity.
    size:       320 bits / 40 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./Vector.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT DeadReckoningParameter : public DataTypeBase
{
protected:

    KUINT8 m_ui8DeadRecknoningAlgorithm;

    KOCTET m_OtherParams[15]; // Undefined

    Vector m_LinearAcceleration;

    Vector m_AngularVelocity;

public:

    static const KUINT16 DEAD_RECKONING_PARAMETER_SIZE = 40;

    DeadReckoningParameter();

    DeadReckoningParameter( KDataStream & stream ) throw( KException );

    DeadReckoningParameter( KDIS::DATA_TYPE::ENUMS::DeadReckoningAlgorithm DRA, const Vector & LinearAcceleration,
                            const Vector & AngularVelocity );

    virtual ~DeadReckoningParameter();

    //************************************
    // FullName:    KDIS::DATA_TYPE::DeadReckoningParameter::SetDeadReckoningAlgorithm
    //              KDIS::DATA_TYPE::DeadReckoningParameter::GetDeadReckoningAlgorithm
    // Description: Dead Reckoning Algorithm
    // Parameter:   DeadReckoningAlgorithm DRA
    //************************************
    void SetDeadReckoningAlgorithm( KDIS::DATA_TYPE::ENUMS::DeadReckoningAlgorithm DRA );
    KDIS::DATA_TYPE::ENUMS::DeadReckoningAlgorithm GetDeadReckoningAlgorithm() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::DeadReckoningParameter::SetLinearAcceleration
    //              KDIS::DATA_TYPE::DeadReckoningParameter::GetLinearAcceleration
    // Description: Linear Acceleration in m/s.
    // Parameter:   const Vector & LA
    //************************************
    void SetLinearAcceleration( const Vector & LA );
    const Vector & GetLinearAcceleration() const;
    Vector & GetLinearAcceleration();

    //************************************
    // FullName:    KDIS::DATA_TYPE::DeadReckoningParameter::SetAngularVelocity
    //              KDIS::DATA_TYPE::DeadReckoningParameter::GetAngularVelocity
    // Description: Angular Velocity
    // Parameter:   const EulerAngles & AV
    //************************************
    void SetAngularVelocity( const Vector & AV );
    const Vector & GetAngularVelocity() const;
    Vector & GetAngularVelocity();

    //************************************
    // FullName:    KDIS::DATA_TYPE::DeadReckoningParameter::SetQuatAxis
    //              KDIS::DATA_TYPE::DeadReckoningParameter::GetQuatAxis
    // Description: Updated DIS - Geometric Interpretation of Orientation Dead Reckoning / Quaternion axis
    // Parameter:   const EulerAngles & AV
    //************************************
    void SetQuatAxis( const Vector & QA );
    const Vector GetQuatAxis() const;
    Vector GetQuatAxis();

    //************************************
    // FullName:    KDIS::DATA_TYPE::DeadReckoningParameter::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::DeadReckoningParameter::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::DeadReckoningParameter::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const DeadReckoningParameter & Value ) const;
    KBOOL operator != ( const DeadReckoningParameter & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
