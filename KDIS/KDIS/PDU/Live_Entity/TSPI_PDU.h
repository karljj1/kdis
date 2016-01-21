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
    class:      TSPI_PDU
    DIS:        (6) 1278.1a - 1998
    created:    30/06/2010
    author:     Karl Jones

    purpose:    Time Space Position Information(TSPI).
                The TSPI PDU shall communicate information about a LE’s state vector.
                This PDU includes state information that is necessary for the receiving
                simulation applications to represent the issuing LE’s location and
                movement in its own simulation.

    size:       200 bits / 25 octets - Min size
*********************************************************************/

#pragma once

#include "./LE_Header.h"
#include "./../../DataTypes/RelativeWorldCoordinates.h"
#include "./../../DataTypes/LE_Vector.h"
#include "./../../DataTypes/LE_EulerAngles.h"
#include "./../../DataTypes/PositionError.h"
#include "./../../DataTypes/OrientationError.h"
#include "./../../DataTypes/LE_DeadReckoningParameter.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT TSPI_PDU : public LE_Header
{
protected:

    union
    {
        struct
        {
            KUINT8 m_ui8LinVel   : 1;
            KUINT8 m_ui8Ori      : 1;
            KUINT8 m_ui8PosErr   : 1;
            KUINT8 m_ui8OriErr   : 1;
            KUINT8 m_ui8DRM      : 1;
            KUINT8 m_ui8Spd      : 1;
            KUINT8 m_ui8Data     : 1;
            KUINT8 m_ui8Reserved : 1;
        };
        KUINT8 m_ui8Flag;
    } m_TSPIFlagUnion;

    KDIS::DATA_TYPE::RelativeWorldCoordinates m_Loc;

    KDIS::DATA_TYPE::LE_Vector16_3 m_LinVel;

    KDIS::DATA_TYPE::LE_EulerAngles m_Ori;

    KDIS::DATA_TYPE::PositionError m_PosErr;

    KDIS::DATA_TYPE::OrientationError m_OriErr;

    KDIS::DATA_TYPE::LE_DeadReckoningParameter m_DeadReckoningParameter;

    KDIS::DATA_TYPE::KFIXED16_3 m_MeasureSpd;

    KUINT8 m_ui8SSDLen;

    std::vector<KOCTET> m_vSSD;

public:

    static const KUINT16 TSPI_PDU_SIZE = 25; // Min size, not including optional fields

    TSPI_PDU();

    TSPI_PDU( KDataStream & stream ) throw( KException );

    TSPI_PDU( const Header & H, KDataStream & stream ) throw( KException );

    TSPI_PDU( const KDIS::DATA_TYPE::LE_EntityIdentifier & ID );

    virtual ~TSPI_PDU();

    //************************************
    // FullName:    KDIS::PDU::TSPI_PDU::SetEntityLinearVelocityFlag
    //              KDIS::PDU::TSPI_PDU::GetEntityLinearVelocityFlag
    //              KDIS::PDU::TSPI_PDU::SetEntityOrientationFlag
    //              KDIS::PDU::TSPI_PDU::GetEntityOrientationFlag
    //              KDIS::PDU::TSPI_PDU::SetPositionErrorFlag
    //              KDIS::PDU::TSPI_PDU::GetPositionErrorFlag
    //              KDIS::PDU::TSPI_PDU::SetOrientationErrorFlag
    //              KDIS::PDU::TSPI_PDU::GetOrientationErrorFlag
    //              KDIS::PDU::TSPI_PDU::SetDeadReckoningParameterFlag
    //              KDIS::PDU::TSPI_PDU::GetDeadReckoningParameterFlag
    //              KDIS::PDU::TSPI_PDU::SetMeasuredSpeedFlag
    //              KDIS::PDU::TSPI_PDU::GetMeasuredSpeedFlag
    //              KDIS::PDU::TSPI_PDU::SetSystemSpecificDataFlag
    //              KDIS::PDU::TSPI_PDU::GetSystemSpecificDataFlag
    // Description: These flags are used to indicate which optional fields are
    //              included in the PDU. When setting one of the optional fields the
    //              flag will also be set to true automatically.
    // Parameter:   KBOOL F
    //************************************
    void SetEntityLinearVelocityFlag( KBOOL F );
    KBOOL GetEntityLinearVelocityFlag() const;
    void SetEntityOrientationFlag( KBOOL F );
    KBOOL GetEntityOrientationFlag() const;
    void SetPositionErrorFlag( KBOOL F );
    KBOOL GetPositionErrorFlag() const;
    void SetOrientationErrorFlag( KBOOL F );
    KBOOL GetOrientationErrorFlag() const;
    void SetDeadReckoningParameterFlag( KBOOL F );
    KBOOL GetDeadReckoningParameterFlag() const;
    void SetMeasuredSpeedFlag( KBOOL F );
    KBOOL GetMeasuredSpeedFlag() const;
    void SetSystemSpecificDataFlag( KBOOL F );
    KBOOL GetSystemSpecificDataFlag() const;

    //************************************
    // FullName:    KDIS::PDU::TSPI_PDU::SetEntityLocation
    //              KDIS::PDU::TSPI_PDU::GetEntityLocation
    // Description: The entity’s physical location in the real world.
    //              Each delta distance component shall represent distance in decimeters.
    // Parameter:   const RelativeWorldCoordinates & L
    //************************************
    void SetEntityLocation( const KDIS::DATA_TYPE::RelativeWorldCoordinates & L );
    const KDIS::DATA_TYPE::RelativeWorldCoordinates & GetEntityLocation() const;
    KDIS::DATA_TYPE::RelativeWorldCoordinates & GetEntityLocation();

    //************************************
    // FullName:    KDIS::PDU::TSPI_PDU::SetEntityLinearVelocity
    //              KDIS::PDU::TSPI_PDU::GetEntityLinearVelocity
    // Description: Optional field. Specifies an entity’s linear velocity.
    //              The coordinate system for an entity’s linear velocity depends on the dead
    //              reckoning algorithm used. Each vector component shall represent velocity
    //              in decimeters per second.
    //              Note: Setting this value will also cause the relevant flag to be set to true.
    // Parameter:   const LE_Vector16_3 & V
    //************************************
    void SetEntityLinearVelocity( const KDIS::DATA_TYPE::LE_Vector16_3 & V );
    const KDIS::DATA_TYPE::LE_Vector16_3 & GetEntityLinearVelocity() const;
    KDIS::DATA_TYPE::LE_Vector16_3 & GetEntityLinearVelocity();

    //************************************
    // FullName:    KDIS::PDU::TSPI_PDU::SetEntityLinearOrientation
    //              KDIS::PDU::TSPI_PDU::GetEntityLinearOrientation
    // Description: Optional field. The entity’s orientation.
    //              Note: Setting this value will also cause the relevant flag to be set to true.
    // Parameter:   const LE_EulerAngles & O
    //************************************
    void SetEntityLinearOrientation( const KDIS::DATA_TYPE::LE_EulerAngles & O );
    const KDIS::DATA_TYPE::LE_EulerAngles & GetEntityLinearOrientation() const;
    KDIS::DATA_TYPE::LE_EulerAngles & GetEntityLinearOrientation();

    //************************************
    // FullName:    KDIS::PDU::TSPI_PDU::SetPositionError
    //              KDIS::PDU::TSPI_PDU::GetPositionError
    // Description: Optional field. Specifies the potential horizontal and vertical
    //              position error of the reporting entity.
    //              Note: Setting this value will also cause the relevant flag to be set to true.
    // Parameter:   const PositionError & PE
    //************************************
    void SetPositionError( const KDIS::DATA_TYPE::PositionError & PE );
    const KDIS::DATA_TYPE::PositionError & GetPositionError() const;
    KDIS::DATA_TYPE::PositionError & GetPositionError();

    //************************************
    // FullName:    KDIS::PDU::TSPI_PDU::SetOrientationError
    //              KDIS::PDU::TSPI_PDU::GetOrientationError
    // Description: Optional field. Specifies the potential orientation error of the reporting entity.
    //              Note: Setting this value will also cause the relevant flag to be set to true.
    // Parameter:   const OrientationError & OE
    //************************************
    void SetOrientationError( const KDIS::DATA_TYPE::OrientationError & OE );
    const KDIS::DATA_TYPE::OrientationError & GetOrientationError() const;
    KDIS::DATA_TYPE::OrientationError & GetOrientationError();

    //************************************
    // FullName:    KDIS::PDU::TSPI_PDU::SetDeadReckoningParameter
    //              KDIS::PDU::TSPI_PDU::GetDeadReckoningParameter
    // Description: Optional field. Dead reckoning algorithm in use, entity linear acceleration (optional based
    //              on dead reckoning algorithm in use), and entity angular velocity (optional
    //              based on dead reckoning algorithm in use) shall be included as part of the
    //              dead reckoning parameters. If the Dead Reckoning Parameters field is not
    //              included in the PDU, the recipient shall assume the use of a linear
    //              dead reckoning algorithm [DRM (FPW)] and shall assume all angular velocity
    //              and linear acceleration parameters to be zero.
    //              Note: Setting this value will also cause the relevant flag to be set to true.
    // Parameter:   const DeadReckoningParameter & DRP
    //************************************
    void SetDeadReckoningParameter( const KDIS::DATA_TYPE::LE_DeadReckoningParameter & DRP );
    const KDIS::DATA_TYPE::LE_DeadReckoningParameter & GetDeadReckoningParameter() const;
    KDIS::DATA_TYPE::LE_DeadReckoningParameter & GetDeadReckoningParameter();

    //************************************
    // FullName:    KDIS::PDU::TSPI_PDU::SetMeasuredSpeed
    //              KDIS::PDU::TSPI_PDU::GetMeasuredSpeed
    // Description: Optional field. Specifies the entity’s own measurement of speed (e.g., air speed for aircraft).
    //              Speed in deci-meters per second.
    //              Note: The position of the binary point is not defined in the standard for
    //              this parameter so I have assumed it is 3.
    //              Note: Setting this value will also cause the relevant flag to be set to true.
    // Parameter:   KFIXED16_3 S
    //************************************
    void SetMeasuredSpeed( KDIS::DATA_TYPE::KFIXED16_3 S );
    KDIS::DATA_TYPE::KFIXED16_3 GetMeasuredSpeed() const;

    //************************************
    // FullName:    KDIS::PDU::TSPI_PDU::GetSystemSpecificDataLength
    // Description: The number of octets of system-specific data stored in this PDU.
    //************************************
    KUINT8 GetSystemSpecificDataLength() const;

    //************************************
    // FullName:    KDIS::PDU::TSPI_PDU::SetSystemSpecificData
    //              KDIS::PDU::TSPI_PDU::SetSystemSpecificData
    //              KDIS::PDU::TSPI_PDU::ClearSystemSpecificData
    // Description: Optional. User-defined data.
    //              The contents of this field are arbitrary and outside the bounds of the DIS specification
    //              with the exception that no data shall be transmitted in this field that duplicates or can be derived
    //              from the data transmitted in this or other LE Information/Interaction PDU.
    //              Note: Setting this value will also cause the relevant flag to be set to true.
    // Parameter:   const vector<KOCTET> & SSD, const KOCTET * Data
    // Parameter:   KUINT8 Length
    //************************************
    void SetSystemSpecificData( const std::vector<KOCTET> & SSD );
    void SetSystemSpecificData( const KOCTET * Data, KUINT8 Length );
    const std::vector<KOCTET> & GetSystemSpecificData() const;
    void ClearSystemSpecificData();

    //************************************
    // FullName:    KDIS::PDU::TSPI_PDU::GetAsString
    // Description: Returns a string representation of the PDU
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::TSPI_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::TSPI_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const TSPI_PDU & Value ) const;
    KBOOL operator != ( const TSPI_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
