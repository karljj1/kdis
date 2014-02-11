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
    class:      LE_DeadReckoningParameter
    created:    2008/09/18
    author:     Karl Jones

    purpose:    Parameters for dead reckoning the position and orientation
                of the entity. For Live Entities the acceleration and velocity
                vectors are using KFIXED data types.
    size:       56 bits / 7 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./LE_Vector.h"
#include "./LE_EulerAngles.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT LE_DeadReckoningParameter : public DataTypeBase
{
protected:

    KUINT8 m_ui8DeadRecknoningAlgorithm;

    LE_Vector8_3 m_LinearAcceleration;

    LE_Vector8_3 m_AngularVelocity;

public:

    static const KUINT16 LE_DEAD_RECKONING_PARAMETER_SIZE = 7;

    LE_DeadReckoningParameter();

    LE_DeadReckoningParameter( KDataStream & stream ) throw( KException );

    LE_DeadReckoningParameter( KDIS::DATA_TYPE::ENUMS::DeadReckoningAlgorithm DRA, const LE_Vector8_3 & LinearAcceleration,
                               const LE_Vector8_3 & AngularVelocity );

    virtual ~LE_DeadReckoningParameter();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_DeadReckoningParameter::SetDeadReckoningAlgorithm
    //              KDIS::DATA_TYPE::LE_DeadReckoningParameter::GetDeadReckoningAlgorithm
    // Description: Dead Reckoning Algorithm
    // Parameter:   DeadReckoningAlgorithm DRA
    //************************************
    void SetDeadReckoningAlgorithm( KDIS::DATA_TYPE::ENUMS::DeadReckoningAlgorithm DRA );
    KDIS::DATA_TYPE::ENUMS::DeadReckoningAlgorithm GetDeadReckoningAlgorithm() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_DeadReckoningParameter::SetLinearAcceleration
    //              KDIS::DATA_TYPE::LE_DeadReckoningParameter::GetLinearAcceleration
    // Description: Linear acceleration in decimeters per second.
    // Parameter:   const LE_Vector8_3 & LA
    //************************************
    void SetLinearAcceleration( const LE_Vector8_3 & LA );
    const LE_Vector8_3 & GetLinearAcceleration() const;
    LE_Vector8_3 & GetLinearAcceleration();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_DeadReckoningParameter::SetAngularVelocity
    //              KDIS::DATA_TYPE::LE_DeadReckoningParameter::GetAngularVelocity
    // Description: Angular velocity in radians per second.
    // Parameter:   const EulerAngles & AV
    //************************************
    void SetAngularVelocity( const LE_Vector8_3 & AV );
    const LE_Vector8_3 & GetAngularVelocity() const;
    LE_Vector8_3 & GetAngularVelocity();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_DeadReckoningParameter::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_DeadReckoningParameter::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_DeadReckoningParameter::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const LE_DeadReckoningParameter & Value ) const;
    KBOOL operator != ( const LE_DeadReckoningParameter & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
