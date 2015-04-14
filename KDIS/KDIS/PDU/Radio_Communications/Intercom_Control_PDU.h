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
    class:      Intercom_Control_PDU
    DIS:        (6) 1278.1A - 1998
    created:    24/02/2009
    author:     Karl Jones

    purpose:    Contains detailed information about the state of an intercom
                device and the actions it is requesting of another intercom
                device or the response to a requested action.

    size:       320 bits / 40 - min size
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/CommunicationsChannelType.h"
#include "./../../DataTypes/EntityIdentifier.h"
#include "./../../DataTypes/IntercomCommunicationParameters.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::CommunicationsChannelType;
using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::IntercomCommunicationParameters;
using KDIS::DATA_TYPE::ENUMS::TransmitLineState;
using KDIS::DATA_TYPE::ENUMS::ControlType;
using KDIS::DATA_TYPE::ENUMS::LineStateCommand;
using std::vector;

class KDIS_EXPORT Intercom_Control_PDU : public Header
{
protected:

    KUINT8 m_ui8CtrlTyp;

    KDIS::DATA_TYPE::CommunicationsChannelType m_CommChannelType;

    KDIS::DATA_TYPE::EntityIdentifier m_SrcEnt;

    KUINT16 m_ui16SrcCommDevID;

    KUINT8 m_ui8SrcLineID;

    KUINT8 m_ui8TransmitPriority;

    KUINT8 m_ui8TransmitLineState;

    KUINT8 m_ui8Command;

    KDIS::DATA_TYPE::EntityIdentifier m_MstrEntID;

    KUINT16 m_ui16MstrCommDeviceID;

    KUINT16 m_ui16MstrChannelID;

    KUINT32 m_ui32IntrParamLen;

	std::vector<KDIS::DATA_TYPE::IntercomCommunicationParameters> m_vICP;

public:

    static const KUINT16 INTERCOM_CONTROL_PDU_SIZE = 40; // Min Size

    Intercom_Control_PDU();

    Intercom_Control_PDU( KDataStream & stream ) throw( KException );

	Intercom_Control_PDU( const Header & H, KDataStream & stream ) throw( KException );

    virtual ~Intercom_Control_PDU();

    //************************************
    // FullName:    KDIS::PDU::Intercom_Control_PDU::SetControlType
    //              KDIS::PDU::Intercom_Control_PDU::GetControlType
    // Description: Identifies the type of control requested.
    // Parameter:   ControlType CT
    //************************************
    void SetControlType( KDIS::DATA_TYPE::ENUMS::ControlType CT );
    KDIS::DATA_TYPE::ENUMS::ControlType GetControlType() const;

    //************************************
    // FullName:    KDIS::PDU::Intercom_Control_PDU::SetCommunicationsChannelType
    //              KDIS::PDU::Intercom_Control_PDU::GetCommunicationsChannelType
    // Description: Identifies the Communications Channel Type, class & type.
    // Parameter:   const CommunicationsChannelType & CCT
	//************************************
    void SetCommunicationsChannelType( const KDIS::DATA_TYPE::CommunicationsChannelType & CCT );
    const KDIS::DATA_TYPE::CommunicationsChannelType & GetCommunicationsChannelType() const;
    KDIS::DATA_TYPE::CommunicationsChannelType & GetCommunicationsChannelType();

    //************************************
    // FullName:    KDIS::PDU::Intercom_Control_PDU::SetSourceEntityID
    //              KDIS::PDU::Intercom_Control_PDU::GetSourceEntityID
    // Description: Entity that is the source of the radio intercom transmission.
    //              This Entity ID can be for either the entity that contains/owns
    //              the intercom device or the intercom device itself.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetSourceEntityID ( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetSourceEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetSourceEntityID();

    //************************************
    // FullName:    KDIS::PDU::Intercom_Control_PDU::SetSourceCommDeviceID
    //              KDIS::PDU::Intercom_Control_PDU::GetSourceCommDeviceID
    // Description: Identifies the specific intercom device being interfaced
    //              and/or simulated within an entity.
    //              All devices on an entity must have a unique ID.
    //              Set to 0 if the entity does not have a simulated device.
    // Parameter:   KUINT16 ID
    //************************************
    void SetSourceCommDeviceID( KUINT16 ID );
    KUINT16 GetSourceCommDeviceID() const;

    //************************************
    // FullName:    KDIS::PDU::Intercom_Control_PDU::SetSourceLineID
    //              KDIS::PDU::Intercom_Control_PDU::GetSourceLineID
    // Description: Identifies the line number to which this intercom control refers.
    //              E.G. For a intercom device with a single line the value would be 1.
    // Parameter:   KUINT8 ID
    //************************************
    void SetSourceLineID( KUINT8 ID );
    KUINT8 GetSourceLineID() const;

    //************************************
    // FullName:    KDIS::PDU::Intercom_Control_PDU::SetTransmitPriority
    //              KDIS::PDU::Intercom_Control_PDU::GetTransmitPriority
    // Description: Identifies the priority of this message relative to transmissions
    //              from other intercom devices on the same channel.
    //              The value 0 is reserved.
    //              1 = highest priority, 255 = lowest priority.
    // Parameter:   KUINT8 TP
    //************************************
    void SetTransmitPriority( KUINT8 TP );
    KUINT8 GetTransmitPriority() const;

    //************************************
    // FullName:    KDIS::PDU::Intercom_Control_PDU::SetTransmitLineState
    //              KDIS::PDU::Intercom_Control_PDU::GetTransmitLineState
    // Description: Identify the current transmit state of the line at the intercom
    //              source.
    // Parameter:   TransmitLineState TLS
    //************************************
    void SetTransmitLineState( KDIS::DATA_TYPE::ENUMS::TransmitLineState TLS );
    KDIS::DATA_TYPE::ENUMS::TransmitLineState GetTransmitLineState() const;

    //************************************
    // FullName:    KDIS::PDU::Intercom_Control_PDU::SetLineStateCommand
    //              KDIS::PDU::Intercom_Control_PDU::GetLineStateCommand
    // Description: When the Control Type of the Intercom Control PDU is
    //              request or acknowledge, this field shall specify the
    //              detailed type requested. Otherwise set to 0.
    // Parameter:   LineStateCommand LSC
    //************************************
    void SetLineStateCommand( KDIS::DATA_TYPE::ENUMS::LineStateCommand LSC );
    KDIS::DATA_TYPE::ENUMS::LineStateCommand GetLineStateCommand() const;

    //************************************
    // FullName:    KDIS::PDU::Intercom_Control_PDU::SetMasterEntityID
    //              KDIS::PDU::Intercom_Control_PDU::GetMasterEntityID
    // Description: Entity that has created this intercom channel.
    // Parameter:   const EntityIdentifier & ID
    //************************************
    void SetMasterEntityID ( const KDIS::DATA_TYPE::EntityIdentifier & ID );
    const KDIS::DATA_TYPE::EntityIdentifier & GetMasterEntityID() const;
    KDIS::DATA_TYPE::EntityIdentifier & GetMasterEntityID();

    //************************************
    // FullName:    KDIS::PDU::Intercom_Control_PDU::SetMasterCommDeviceID
    //              KDIS::PDU::Intercom_Control_PDU::GetMasterCommDeviceID
    // Description: Identifies the specific intercom device that has created
    //              this intercom channel.
    //              When identifying a particular intercom device, the Master
    //              Communications Device ID shall be greater than or equal to one.
    //              The Master Communications Device ID field ID shall contain the
    //              value zero only when the entity creating this channel does not have,
    //              or does not wish to associate this channel with, an intercom device.
    //              All intercom units associated with a particular site/application/entity
    //              are numbered to provide unique identification.
    // Parameter:   KUINT16 ID
    //************************************
    void SetMasterCommDeviceID( KUINT16 ID );
    KUINT16 GetMasterCommDeviceID() const;

    //************************************
    // FullName:    KDIS::PDU::Intercom_Control_PDU::SetMasterChannelID
    //              KDIS::PDU::Intercom_Control_PDU::GetMasterChannelID
    // Description: Identifies a unique intercom channel created by this Master Entity
    //              ID and Master Communications Device ID pair.
    // Parameter:   KUINT16 ID
    //************************************
    void SetMasterChannelID( KUINT16 ID );
    KUINT16 GetMasterChannelID() const;

    //************************************
    // FullName:    KDIS::PDU::Intercom_Control_PDU::SetMasterChannelID
    // Description: Length of all optional Intercom parameters, in octets.
    //************************************
    KUINT32 GetIntercomParametersLength() const;

    //************************************
    // FullName:    KDIS::PDU::Intercom_Control_PDU::AddIntercomCommunicationParameters
    //              KDIS::PDU::Intercom_Control_PDU::SetIntercomCommunicationParameters
    //              KDIS::PDU::Intercom_Control_PDU::GetIntercomCommunicationParameters
    // Description: Add a Intercom Communication Parameter / Get vector or params.
    // Parameter:   const IntercomCommunicationParameters & ICP
    //************************************
    void AddIntercomCommunicationParameters( const KDIS::DATA_TYPE::IntercomCommunicationParameters & ICP );
	void SetIntercomCommunicationParameters( const std::vector<KDIS::DATA_TYPE::IntercomCommunicationParameters> & ICP );
	const std::vector<KDIS::DATA_TYPE::IntercomCommunicationParameters> & GetIntercomCommunicationParameters() const;

    //************************************
    // FullName:    KDIS::PDU::Intercom_Control_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Intercom_Control_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Intercom_Control_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Intercom_Control_PDU & Value ) const;
    KBOOL operator != ( const Intercom_Control_PDU & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS

