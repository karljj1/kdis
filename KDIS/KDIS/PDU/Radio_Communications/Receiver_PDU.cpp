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

#include "./Receiver_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Receiver_PDU::Receiver_PDU( void ) :
	m_ui16ReceiverState( 0 ),    
	m_ui16Padding1( 0 ),
	m_f32RecPwr( 0 ),
	m_ui16TransmitterRadioID( 0 )
{
    m_ui8PDUType = Receiver_PDU_Type;
    m_ui16PDULength = RECEIVER_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Receiver_PDU::Receiver_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Receiver_PDU::Receiver_PDU( const EntityIdentifier & ID, KUINT16 RadioID, TransmitState TS,
                            KFLOAT32 ReceivingPower, const EntityIdentifier & TransmitterID,
                            KUINT16 TransmitterRadioID ) :
    Radio_Communications_Header( ID, RadioID ),
    m_ui16ReceiverState( TS ),
    m_ui16Padding1( 0 ),
    m_f32RecPwr( ReceivingPower ),
    m_TransmitterEntityID( TransmitterID ),
    m_ui16TransmitterRadioID( TransmitterRadioID )
{
    m_ui8PDUType = Receiver_PDU_Type;
    m_ui16PDULength = RECEIVER_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Receiver_PDU::~Receiver_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

void Receiver_PDU::SetReceiverState( TransmitState TS )
{
    m_ui16ReceiverState = TS;
}

//////////////////////////////////////////////////////////////////////////

TransmitState Receiver_PDU::GetReceiverState() const
{
    return ( TransmitState )m_ui16ReceiverState;
}

//////////////////////////////////////////////////////////////////////////

void Receiver_PDU::SetReceiverPower( KFLOAT32 RP )
{
    m_f32RecPwr = RP;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Receiver_PDU::GetReceiverPower() const
{
    return m_f32RecPwr;
}

//////////////////////////////////////////////////////////////////////////

void Receiver_PDU::SetTransmitterEntityID( const EntityIdentifier & ID )
{
    m_TransmitterEntityID = ID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & Receiver_PDU::GetTransmitterEntityID() const
{
    return m_TransmitterEntityID;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & Receiver_PDU::GetTransmitterEntityID()
{
    return m_TransmitterEntityID;
}

//////////////////////////////////////////////////////////////////////////

void Receiver_PDU::SetTransmitterRadioID( KUINT16 ID )
{
    m_ui16TransmitterRadioID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 Receiver_PDU::GetTransmitterRadioID() const
{
    return m_ui16TransmitterRadioID;
}

//////////////////////////////////////////////////////////////////////////

KString Receiver_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Receiver PDU-\n"
       << Radio_Communications_Header::GetAsString()
       << "Receiver State: " << GetEnumAsStringTransmitState( m_ui16ReceiverState ) << "\n"
       << "Receiver Power: " << m_f32RecPwr << "\n"
       << m_TransmitterEntityID.GetAsString()
       << "Transmitter Radio ID: " << m_ui16TransmitterRadioID << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Receiver_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < RECEIVER_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Radio_Communications_Header::Decode( stream );

    stream >> m_ui16ReceiverState
           >> m_ui16Padding1
           >> m_f32RecPwr
           >> KDIS_STREAM m_TransmitterEntityID
           >> m_ui16TransmitterRadioID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Receiver_PDU::Encode() const
{
    KDataStream stream;

    Radio_Communications_Header::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Receiver_PDU::Encode( KDataStream & stream ) const
{
    Radio_Communications_Header::Encode( stream );

    stream << m_ui16ReceiverState
           << m_ui16Padding1
           << m_f32RecPwr
           << KDIS_STREAM m_TransmitterEntityID
           << m_ui16TransmitterRadioID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Receiver_PDU::operator == ( const Receiver_PDU & Value ) const
{
    if( Radio_Communications_Header::operator   !=( Value ) )                       return false;
    if( m_ui16ReceiverState                     != Value.m_ui16ReceiverState )      return false;
    if( m_f32RecPwr                             != Value.m_f32RecPwr )              return false;
    if( m_TransmitterEntityID                   != Value.m_TransmitterEntityID )    return false;
    if( m_ui16TransmitterRadioID                != Value.m_ui16TransmitterRadioID ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Receiver_PDU::operator != ( const Receiver_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

