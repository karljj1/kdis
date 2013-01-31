/*********************************************************************
Copyright 2013 KDIS
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
    class:      Receiver_PDU
    DIS:        (5) 1278.1 - 1995
    created:    22/10/2008
    author:     Karl Jones

    purpose:    The Receiver PDU may be used to communicate the state of a particular
				radio receiver. 
				Its primary application is in communicating state information to radio
				network monitors, data loggers, and similar applications for use in debugging,
				supervision, and after-action review.

    size:       288 bits / 36
*********************************************************************/

#pragma once

#include "./Radio_Communications_Header.h"
#include "./../../DataTypes/EntityIdentifier.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::ENUMS::TransmitState;

class KDIS_EXPORT Receiver_PDU : public Radio_Communications_Header
{
protected:

    KUINT16 m_ui16ReceiverState;

    KUINT16 m_ui16Padding1;

    KFLOAT32 m_f32RecPwr;

    EntityIdentifier m_TransmitterEntityID;

    KUINT16 m_ui16TransmitterRadioID;

public:

    static const KUINT16 RECEIVER_PDU_SIZE = 36;

    Receiver_PDU( void );

    Receiver_PDU( KDataStream & stream ) throw( KException );

    Receiver_PDU( const EntityIdentifier & ID, KUINT16 RadioID, TransmitState TS,
                  KFLOAT32 ReceivingPower, const EntityIdentifier & TransmitterID,
                  KUINT16 TransmitterRadioID );

    virtual ~Receiver_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Receiver_PDU::SetReceiverState
    //              KDIS::PDU::Receiver_PDU::GetReceiverState
    // Description: Radio Receiver State, on or off.
    // Parameter:   TransmitState TS, void
    //************************************
    void SetReceiverState( TransmitState TS );
    TransmitState GetReceiverState() const;

    //************************************
    // FullName:    KDIS::PDU::Receiver_PDU::SetReceiverPower
    //              KDIS::PDU::Receiver_PDU::GetReceiverPower
    // Description: Radio Receiver power received, after applying
    //              any propagation loss and antenna gain.
    //              In decibel milliwatts.
    // Parameter:   KFLOAT32 RP, void
    //************************************
    void SetReceiverPower( KFLOAT32 RP );
    KFLOAT32 GetReceiverPower() const;

    //************************************
    // FullName:    KDIS::PDU::Receiver_PDU::SetTransmitterEntityID
    //              KDIS::PDU::Receiver_PDU::GetTransmitterEntityID
    // Description: The source of the transmission.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetTransmitterEntityID( const EntityIdentifier & ID );
    const EntityIdentifier & GetTransmitterEntityID() const;
    EntityIdentifier & GetTransmitterEntityID();

    //************************************
    // FullName:    KDIS::PDU::Receiver_PDU::SetTransmitterRadioID
    //              KDIS::PDU::Receiver_PDU::GetTransmitterRadioID
    // Description: Identifies the particular radio within the transmitting
    //              entity.
    // Parameter:   KUINT16 ID, void
    //************************************
    void SetTransmitterRadioID( KUINT16 ID );
    KUINT16 GetTransmitterRadioID() const;

    //************************************
    // FullName:    KDIS::PDU::Receiver_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Receiver_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Receiver_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Receiver_PDU & Value ) const;
    KBOOL operator != ( const Receiver_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS

