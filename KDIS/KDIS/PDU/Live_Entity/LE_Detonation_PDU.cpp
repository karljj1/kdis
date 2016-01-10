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

#include "./LE_Detonation_PDU.h"
#include <cassert>

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// protected:
//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::checkFlagsAndPDULength()
{
    // Check if the Munition ID field is included and set dependent
    // values accordingly.
    if( GetMunitionEntityIDFlag() )
    {
        // Check if the munition's's site and application values
        // are the same, if they are we don't include them.
        if( m_EntID.GetSiteID() == m_MunitionID.GetSiteID() &&
                m_EntID.GetApplicationID() == m_MunitionID.GetApplicationID() )
        {
            // They match so don't include the fields
            SetMunitionEntityIDSiteAppIncludedFlag( false );
        }
        else
        {
            // They don't match so we need to send these fields.
            SetMunitionEntityIDSiteAppIncludedFlag( true );
        }
    }
    else
    {
        SetMunitionEntityIDSiteAppIncludedFlag( false );
    }

    // Now check the event's site and application values
    if( m_EntID.GetSiteID() == m_EventID.GetSiteID() &&
            m_EntID.GetApplicationID() == m_EventID.GetApplicationID() )
    {
        SetEventIDSiteAppIncludedFlag( false );
    }
    else
    {
        SetEventIDSiteAppIncludedFlag( true );
    }

    // Check if the Event Number field or the Munition Orientation field
    // are set. Make sure that the Flag Octet 2 is set accordingly.
    if( GetMunitionOrientationFlag() || GetEventNumberIncludedFlag() )
    {
        SetFlag2Flag( true );
    }
    else
    {
        SetFlag2Flag( false );
    }

#ifdef _DEBUG
    {
        // Verify PDU length
        const KUINT16 ui16ExpectedPDULength = 32
            + 1*m_DetonationFlag1Union.m_ui8Flag2
            + 4*m_DetonationFlag1Union.m_ui8TargetId
            + (2*m_DetonationFlag1Union.m_ui8MunitionSiteApp + 2)*m_DetonationFlag1Union.m_ui8MunitionId
            + (2*m_DetonationFlag1Union.m_ui8EventSiteAppId + 2)*m_DetonationFlag2Union.m_ui8EventNum
            + 8*(1 - m_DetonationFlag1Union.m_ui8LocationTyp)
            + 6*m_DetonationFlag2Union.m_ui8MunitionOri
            + 4*m_DetonationFlag1Union.m_ui8WarheadFuse
            + 4*m_DetonationFlag1Union.m_ui8QuantRate
            + 6*m_DetonationFlag1Union.m_ui8LocationTyp;
        assert(ui16ExpectedPDULength == m_ui16PDULength);
    }
#endif
}

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

LE_Detonation_PDU::LE_Detonation_PDU() :
    m_ui8DetonationResult( 0 )
{
    m_DetonationFlag1Union.m_ui8Flag = 0;
    m_DetonationFlag2Union.m_ui8Flag = 0;
    m_ui8PDUType = LEDetonation_PDU_Type;
    m_ui16PDULength = LE_DETONATION_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

LE_Detonation_PDU::LE_Detonation_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

LE_Detonation_PDU::LE_Detonation_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
    LE_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

LE_Detonation_PDU::LE_Detonation_PDU( const LE_EntityIdentifier & ID ) :
    m_ui8DetonationResult( 0 )
{
    m_EntID = ID;
    m_DetonationFlag1Union.m_ui8Flag = 0;
    m_DetonationFlag2Union.m_ui8Flag = 0;
    m_ui8PDUType = LEDetonation_PDU_Type;
    m_ui16PDULength = LE_DETONATION_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

LE_Detonation_PDU::~LE_Detonation_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetTargetEntityIDFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_DetonationFlag1Union.m_ui8TargetId )return;

    m_DetonationFlag1Union.m_ui8TargetId = F;

    if( F )
    {
        m_ui16PDULength += LE_EntityIdentifier::LE_ENTITY_IDENTIFER_SIZE;
    }
    else
    {
        m_ui16PDULength -= LE_EntityIdentifier::LE_ENTITY_IDENTIFER_SIZE;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Detonation_PDU::GetTargetEntityIDFlag() const
{
    return m_DetonationFlag1Union.m_ui8TargetId;
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetMunitionEntityIDFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_DetonationFlag1Union.m_ui8MunitionId )return;

    m_DetonationFlag1Union.m_ui8MunitionId = F;

    if( F )
    {
        m_ui16PDULength += 2; // 2 = This flag only indicates the entity id field is included.
    }
    else
    {
        m_ui16PDULength -= 2;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Detonation_PDU::GetMunitionEntityIDFlag() const
{
    return m_DetonationFlag1Union.m_ui8MunitionId;
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetMunitionEntityIDSiteAppIncludedFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_DetonationFlag1Union.m_ui8MunitionSiteApp )return;

    m_DetonationFlag1Union.m_ui8MunitionSiteApp = F;

    if( F )
    {
        m_ui16PDULength += 2; // 2 = This flag indicates the site and application fields are included.
    }
    else
    {
        m_ui16PDULength -= 2;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Detonation_PDU::GetMunitionEntityIDSiteAppIncludedFlag() const
{
    return m_DetonationFlag1Union.m_ui8MunitionSiteApp;
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetEventIDSiteAppIncludedFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_DetonationFlag1Union.m_ui8EventSiteAppId )return;

    m_DetonationFlag1Union.m_ui8EventSiteAppId = F;

    if( F )
    {
        m_ui16PDULength += 2; // 2 = This flag indicates the site and application fields are included.
    }
    else
    {
        m_ui16PDULength -= 2;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Detonation_PDU::GetEventIDSiteAppIncludedFlag() const
{
    return m_DetonationFlag1Union.m_ui8EventSiteAppId;
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetWarheadFuseFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_DetonationFlag1Union.m_ui8WarheadFuse )return;

    m_DetonationFlag1Union.m_ui8WarheadFuse = F;

    if( F )
    {
        m_ui16PDULength += 4; // 4 = size of warhead and fuse fields in the Munition Descriptor.
    }
    else
    {
        m_ui16PDULength -= 4;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Detonation_PDU::GetWarheadFuseFlag() const
{
    return m_DetonationFlag1Union.m_ui8WarheadFuse;
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetQuantityRateFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_DetonationFlag1Union.m_ui8QuantRate )return;

    m_DetonationFlag1Union.m_ui8QuantRate = F;

    if( F )
    {
        m_ui16PDULength += 4; // 4 = size of quantity and  fields in the Munition Descriptor.
    }
    else
    {
        m_ui16PDULength -= 4;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Detonation_PDU::GetQuantityRateFlag() const
{
    return m_DetonationFlag1Union.m_ui8QuantRate;
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetLocationInEntityCoordinatesFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_DetonationFlag1Union.m_ui8LocationTyp )return;

    m_DetonationFlag1Union.m_ui8LocationTyp = F;

    if( F )
    {
        m_ui16PDULength -= RelativeWorldCoordinates::RELATVE_WORLD_COORDINATES_SIZE;
        m_ui16PDULength += LE_Vector16_3::LE_VECTOR_SIZE;
    }
    else
    {
        m_ui16PDULength += RelativeWorldCoordinates::RELATVE_WORLD_COORDINATES_SIZE;
        m_ui16PDULength -= LE_Vector16_3::LE_VECTOR_SIZE;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Detonation_PDU::GetLocationInEntityCoordinatesFlag() const
{
    return m_DetonationFlag1Union.m_ui8LocationTyp;
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetFlag2Flag( KBOOL F )
{
    if( ( KUINT8 )F == m_DetonationFlag1Union.m_ui8Flag2 )return;

    m_DetonationFlag1Union.m_ui8Flag2 = F;

    if( F )
    {
        m_ui16PDULength += 1; // 1 = size of flag 2 field
    }
    else
    {
        m_ui16PDULength -= 1;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Detonation_PDU::GetFlag2Flag() const
{
    return m_DetonationFlag1Union.m_ui8Flag2;
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetMunitionOrientationFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_DetonationFlag2Union.m_ui8MunitionOri )return;

    m_DetonationFlag2Union.m_ui8MunitionOri = F;

    SetFlag2Flag( m_DetonationFlag2Union.m_ui8Flag != 0 );

    if( F )
    {
        m_ui16PDULength += LE_Vector16_3::LE_VECTOR_SIZE;
    }
    else
    {
        m_ui16PDULength -= LE_Vector16_3::LE_VECTOR_SIZE;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Detonation_PDU::GetMunitionOrientationFlag() const
{
    return m_DetonationFlag2Union.m_ui8MunitionOri;
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetEventNumberIncludedFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_DetonationFlag2Union.m_ui8EventNum )return;

    m_DetonationFlag2Union.m_ui8EventNum = F;

    SetFlag2Flag( m_DetonationFlag2Union.m_ui8Flag != 0 );

    if( F )
    {
        m_ui16PDULength += 2; // 2 = size of event number field
    }
    else
    {
        m_ui16PDULength -= 2;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Detonation_PDU::GetEventNumberIncludedFlag() const
{
    return m_DetonationFlag2Union.m_ui8EventNum;
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetTargetEntityID( const LE_EntityIdentifier & ID )
{
    SetTargetEntityIDFlag( true );
    m_TargetID = ID;
}

//////////////////////////////////////////////////////////////////////////

const LE_EntityIdentifier & LE_Detonation_PDU::GetTargetEntityID() const
{
    return m_TargetID;
}

//////////////////////////////////////////////////////////////////////////

LE_EntityIdentifier & LE_Detonation_PDU::GetTargetEntityID()
{
    return m_TargetID;
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetMunitionEntityID( const LE_EntityIdentifier & ID )
{
    SetMunitionEntityIDFlag( true );
    m_MunitionID = ID;

    // Check if the firing entity's site and application values
    // are the same, if they are we don't include them.
    if( m_EntID.GetSiteID() == ID.GetSiteID() &&
            m_EntID.GetApplicationID() == ID.GetApplicationID() )
    {
        // They match so don't include the fields
        SetMunitionEntityIDSiteAppIncludedFlag( false );
    }
    else
    {
        // They don't match so we need to send these fields.
        SetMunitionEntityIDSiteAppIncludedFlag( true );
    }
}

//////////////////////////////////////////////////////////////////////////

const LE_EntityIdentifier & LE_Detonation_PDU::GetMunitionEntityID() const
{
    return m_MunitionID;
}

//////////////////////////////////////////////////////////////////////////

LE_EntityIdentifier & LE_Detonation_PDU::GetMunitionEntityID()
{
    return m_MunitionID;
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetEventID( const LE_EntityIdentifier & ID )
{
    SetEventNumberIncludedFlag( true );
    m_EventID = ID;

    // Check if the id's site and application values
    // are the same, if they are we don't include them.
    if( m_EntID.GetSiteID() == ID.GetSiteID() &&
            m_EntID.GetApplicationID() == ID.GetApplicationID() )
    {
        // They match so don't include the fields
        SetEventIDSiteAppIncludedFlag( false );
    }
    else
    {
        // They don't match so we need to send these fields.
        SetEventIDSiteAppIncludedFlag( true );
    }
}

//////////////////////////////////////////////////////////////////////////

const LE_EntityIdentifier & LE_Detonation_PDU::GetEventID() const
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

LE_EntityIdentifier & LE_Detonation_PDU::GetEventID()
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetLocation( const LE_Vector16_3 & L  )
{
    SetLocationEntityCoordinates( L );
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetLocation( const RelativeWorldCoordinates & L  )
{
    SetLocationWorldCoordinates( L );
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetLocationEntityCoordinates( const LE_Vector16_3 & L )
{
    SetLocationInEntityCoordinatesFlag( true );
    m_LocEntCoord = L;
}

//////////////////////////////////////////////////////////////////////////

const LE_Vector16_3 & LE_Detonation_PDU::GetLocationEntityCoordinates() const
{
    return m_LocEntCoord;
}

//////////////////////////////////////////////////////////////////////////

LE_Vector16_3 & LE_Detonation_PDU::GetLocationEntityCoordinates()
{
    return m_LocEntCoord;
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetLocationWorldCoordinates( const RelativeWorldCoordinates & L )
{
    SetLocationInEntityCoordinatesFlag( false );
    m_LocWrldCoord = L;
}

//////////////////////////////////////////////////////////////////////////

const RelativeWorldCoordinates & LE_Detonation_PDU::GetLocationWorldCoordinates() const
{
    return m_LocWrldCoord;
}

//////////////////////////////////////////////////////////////////////////

RelativeWorldCoordinates & LE_Detonation_PDU::GetLocationWorldCoordinates()
{
    return m_LocWrldCoord;
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetVelocity( const LE_Vector16_3 & V )
{
    m_Vel = V;
}

//////////////////////////////////////////////////////////////////////////

const LE_Vector16_3 & LE_Detonation_PDU::GetVelocity() const
{
    return m_Vel;
}

//////////////////////////////////////////////////////////////////////////

LE_Vector16_3 & LE_Detonation_PDU::GetVelocity()
{
    return m_Vel;
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetMunitionOrientation( const LE_EulerAngles & O )
{
    SetMunitionOrientationFlag( true );
    m_Ori = O;
}

//////////////////////////////////////////////////////////////////////////

const LE_EulerAngles & LE_Detonation_PDU::GetMunitionOrientation() const
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

LE_EulerAngles & LE_Detonation_PDU::GetMunitionOrientation()
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetMunitionDescriptor( const MunitionDescriptor & MD )
{
    m_MunitionDesc = MD;
}

//////////////////////////////////////////////////////////////////////////

const MunitionDescriptor & LE_Detonation_PDU::GetMunitionDescriptor() const
{
    return m_MunitionDesc;
}

//////////////////////////////////////////////////////////////////////////

MunitionDescriptor & LE_Detonation_PDU::GetMunitionDescriptor()
{
    return m_MunitionDesc;
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::SetDetonationResult( DetonationResult DR )
{
    m_ui8DetonationResult = DR;
}

//////////////////////////////////////////////////////////////////////////

DetonationResult LE_Detonation_PDU::GetDetonationResult() const
{
    return ( DetonationResult )m_ui8DetonationResult;
}

//////////////////////////////////////////////////////////////////////////

KString LE_Detonation_PDU::GetAsString() const
{
    KStringStream ss;

    ss << LE_Header::GetAsString()
       << "-LE Detonation PDU-\n"
       << "Optional Field Flags:\n"
       << "\tTarget ID:                            " << ( KUINT16 )m_DetonationFlag1Union.m_ui8TargetId        << "\n"
       << "\tMunition ID:                          " << ( KUINT16 )m_DetonationFlag1Union.m_ui8MunitionId      << "\n"
       << "\tMunition Site & Application Included: " << ( KUINT16 )m_DetonationFlag1Union.m_ui8MunitionSiteApp << "\n"
       << "\tEvent Site & Application Included:    " << ( KUINT16 )m_DetonationFlag1Union.m_ui8EventSiteAppId  << "\n"
       << "\tWarhead & Fuse Included:              " << ( KUINT16 )m_DetonationFlag1Union.m_ui8WarheadFuse     << "\n"
       << "\tQuantity & Rate Included:             " << ( KUINT16 )m_DetonationFlag1Union.m_ui8QuantRate       << "\n"
       << "\tLocation In Entity Coordinates:       " << ( KUINT16 )m_DetonationFlag1Union.m_ui8LocationTyp     << "\n"
       << "\tFlag 2:                               " << ( KUINT16 )m_DetonationFlag1Union.m_ui8Flag2           << "\n";
    
    if (m_DetonationFlag1Union.m_ui8Flag2)
    {
        ss << "\tMunition Orientation:                 " << (KUINT16)m_DetonationFlag2Union.m_ui8MunitionOri   << "\n"
           << "\tEvent Number:                         " << (KUINT16)m_DetonationFlag2Union.m_ui8EventNum      << "\n";
    }

    if( m_DetonationFlag1Union.m_ui8TargetId )
    {
        ss << "Target ID: " << m_TargetID.GetAsString();
    }

    if( m_DetonationFlag1Union.m_ui8MunitionId )
    {
        ss << "Munition ID: " << m_MunitionID.GetAsString();
    }

    if( ( m_DetonationFlag1Union.m_ui8Flag2 && m_DetonationFlag2Union.m_ui8EventNum ) || m_DetonationFlag1Union.m_ui8EventSiteAppId )
    {
        ss << "Event ID: " << m_EventID.GetAsString();
    }

    ss << m_MunitionDesc.GetAsString();

    if( m_DetonationFlag1Union.m_ui8LocationTyp )
    {
        ss << "Location(Entity Coordinates): " << m_LocEntCoord.GetAsString();
    }
    else
    {
        ss << "Location(World Coordinates):\n" << IndentString( m_LocWrldCoord.GetAsString(), 1 );
    }

    ss << "Velocity: " << m_Vel.GetAsString();

    if( m_DetonationFlag1Union.m_ui8Flag2 && m_DetonationFlag2Union.m_ui8MunitionOri )
    {
        ss << "Munition Orienation: " << m_Ori.GetAsString();
    }

    ss << m_MunitionDesc.GetAsString()
       << GetEnumAsStringDetonationResult( m_ui8DetonationResult )
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < LE_DETONATION_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    LE_Header::Decode( stream, ignoreHeader );

    stream >> m_DetonationFlag1Union.m_ui8Flag;

    // F7: Flag Octet 2
    if( m_DetonationFlag1Union.m_ui8Flag2 )
    {
        stream >> m_DetonationFlag2Union.m_ui8Flag;
    }
    else
    {
        // Make sure no flags are set in Flag Octet 2
        m_DetonationFlag2Union.m_ui8Flag = 0;
    }

    // F0: Target Entity ID
    if( m_DetonationFlag1Union.m_ui8TargetId )
    {
        stream >> KDIS_STREAM m_TargetID;
    }

    KUINT16 tmp = 0;

    // F2: Munition ID
    if( m_DetonationFlag1Union.m_ui8MunitionId )
    {
        // F1: Site Number and Application Number
        if( m_DetonationFlag1Union.m_ui8MunitionSiteApp )
        {
            stream >> KDIS_STREAM m_MunitionID;
        }
        else
        {
            // We cant use the standard encode/decode functions here as not all fields are included.

            // The Firing Entities site and application id are the same so lets copy them over
            m_MunitionID = m_EntID;

            stream >> tmp;
            m_MunitionID.SetEntityID( tmp );
        }
    }

    // G1: Event Number
    if( m_DetonationFlag2Union.m_ui8EventNum )
    {
        // F3: Event ID
        if( m_DetonationFlag1Union.m_ui8EventSiteAppId )
        {
            stream >> KDIS_STREAM m_EventID;
        }
        else
        {
            // We cant use the standard encode/decode functions here as not all fields are included.

            // The Firing Entities site and application id are the same so lets copy them over
            m_EventID = m_EntID;

            stream >> tmp;
            m_EventID.SetEntityID( tmp );
        }
    }

    // F6: Is the location in world coordinates?
    if( !m_DetonationFlag1Union.m_ui8LocationTyp ) // false means location is in world coords
    {
        stream >> KDIS_STREAM m_LocWrldCoord;
    }

    // Velocity
    stream >> KDIS_STREAM m_Vel;

    // G0: Munition Orientation
    if( m_DetonationFlag2Union.m_ui8MunitionOri )
    {
        stream >> KDIS_STREAM m_Ori;
    }

    // Munition Descriptor
    m_MunitionDesc.SetType( EntityType( stream ) );
    // F4: Warhead and Fuse fields of the Munition Descriptor record
    if( m_DetonationFlag1Union.m_ui8WarheadFuse )
    {
        stream >> tmp;
        m_MunitionDesc.SetWarhead( ( WarheadType )tmp );

        stream >> tmp;
        m_MunitionDesc.SetFuse( ( FuseType )tmp );
    }
    // F5: Quantity and Rate fields of the Munition Descriptor record
    if( m_DetonationFlag1Union.m_ui8QuantRate )
    {
        stream >> tmp;
        m_MunitionDesc.SetQuantity( tmp );

        stream >> tmp;
        m_MunitionDesc.SetRate( tmp );
    }

    // F6: Is the location in entity coordinates?
    if( m_DetonationFlag1Union.m_ui8LocationTyp ) // true means location is in entity coords
    {
        stream >> KDIS_STREAM m_LocEntCoord;
    }

    // Detonation Result
    stream >> m_ui8DetonationResult;
}

////////////////////////////////////////////////////////////////////////////

KDataStream LE_Detonation_PDU::Encode() const
{
    KDataStream stream;

    LE_Detonation_PDU::Encode( stream );

    return stream;
}

////////////////////////////////////////////////////////////////////////////

void LE_Detonation_PDU::Encode( KDataStream & stream ) const
{
    // We need to cast away the const so we can check the flag values are correct
    // Must check the flags before encoding the header since PDU length may change
    LE_Detonation_PDU * self = const_cast<LE_Detonation_PDU*>( this );
    self->checkFlagsAndPDULength();

    LE_Header::Encode( stream );

    stream << m_DetonationFlag1Union.m_ui8Flag;

    // F7: Flag Octet 2
    if( m_DetonationFlag1Union.m_ui8Flag2 )
    {
        stream << m_DetonationFlag2Union.m_ui8Flag;
    }

    // F0: Target Entity ID
    if( m_DetonationFlag1Union.m_ui8TargetId )
    {
        stream << KDIS_STREAM m_TargetID;
    }

    // F2: Munition ID
    if( m_DetonationFlag1Union.m_ui8MunitionId )
    {
        // F1: Site Number and Application Number
        if( m_DetonationFlag1Union.m_ui8MunitionSiteApp )
        {
            stream << KDIS_STREAM m_MunitionID;
        }
        else
        {
            // We cant use the standard encode/decode functions here as not all fields are included.
            stream << m_MunitionID.GetEntityID();
        }
    }

    // G1: Event Number
    if( m_DetonationFlag2Union.m_ui8EventNum )
    {
        // F3: Event ID
        if( m_DetonationFlag1Union.m_ui8EventSiteAppId )
        {
            stream << KDIS_STREAM m_EventID;
        }
        else
        {
            // We cant use the standard encode/decode functions here as not all fields are included.
            stream << m_EventID.GetEntityID();
        }
    }

    // F6: Is the location in world coordinates?
    if( !m_DetonationFlag1Union.m_ui8LocationTyp ) // false means location is in world coords
    {
        stream << KDIS_STREAM m_LocWrldCoord;
    }

    // Velocity
    stream << KDIS_STREAM m_Vel;

    // G0: Munition Orientation
    if( m_DetonationFlag2Union.m_ui8MunitionOri )
    {
        stream << KDIS_STREAM m_Ori;
    }

    // Munition Descriptor
    stream << KDIS_STREAM m_MunitionDesc.GetType();
    // F4: Warhead and Fuse fields of the Munition Descriptor record
    if( m_DetonationFlag1Union.m_ui8WarheadFuse )
    {
        stream << ( KUINT16 )m_MunitionDesc.GetWarhead()
               << ( KUINT16 )m_MunitionDesc.GetFuse();
    }
    // F5: Quantity and Rate fields of the Munition Descriptor record
    if( m_DetonationFlag1Union.m_ui8QuantRate )
    {
        stream << m_MunitionDesc.GetQuantity()
               << m_MunitionDesc.GetRate();
    }

    // Is the location in entity coordinates?
    if( m_DetonationFlag1Union.m_ui8LocationTyp ) // true means location is in entity coords
    {
        stream << KDIS_STREAM m_LocEntCoord;
    }

    // Detonation Result
    stream << m_ui8DetonationResult;

    assert(stream.GetBufferSize() == m_ui16PDULength);
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Detonation_PDU::operator == ( const LE_Detonation_PDU & Value ) const
{
    if( LE_Header::operator              != ( Value ) )                              return false;
    if( m_DetonationFlag1Union.m_ui8Flag != Value.m_DetonationFlag1Union.m_ui8Flag ) return false;
    if( m_DetonationFlag2Union.m_ui8Flag != Value.m_DetonationFlag2Union.m_ui8Flag ) return false;
    if( m_TargetID                       != Value.m_TargetID )                       return false;
    if( m_MunitionID                     != Value.m_MunitionID )                     return false;
    if( m_EventID                        != Value.m_EventID )                        return false;
    if( m_LocEntCoord                    != Value.m_LocEntCoord )                    return false;
    if( m_LocWrldCoord                   != Value.m_LocWrldCoord )                   return false;
    if( m_Vel                            != Value.m_Vel )                            return false;
    if( m_MunitionDesc                   != Value.m_MunitionDesc )                   return false;
    if( m_Ori                            != Value.m_Ori )                            return false;
    if( m_ui8DetonationResult            != Value.m_ui8DetonationResult )            return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Detonation_PDU::operator != ( const LE_Detonation_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

