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

