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

#include "./LE_Fire_PDU.h"
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

void LE_Fire_PDU::checkFlagsAndPDULength()
{
    // Check if Munition ID field is included and set dependent
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

#ifdef _DEBUG
    {
        // Verify PDU length
        const KUINT16 ui16ExpectedPDULength = 35 
            + (4*m_FireFlagUnion.m_ui8TargetId) 
            + ((2*m_FireFlagUnion.m_ui8MunitionSiteApp + 2)*m_FireFlagUnion.m_ui8MunitionId) 
            + (2*m_FireFlagUnion.m_ui8EventSiteAppId) 
            + (8*m_FireFlagUnion.m_ui8Location) 
            + (4*m_FireFlagUnion.m_ui8WarheadFuse) 
            + (4*m_FireFlagUnion.m_ui8QuantRate);
        assert(ui16ExpectedPDULength == m_ui16PDULength);
    }
#endif
}

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

LE_Fire_PDU::LE_Fire_PDU() :
    m_ui16Range( 0 )
{
    m_FireFlagUnion.m_ui8Flag = 0;
    m_ui8PDUType = LEFire_PDU_Type;
    m_ui16PDULength = LE_FIRE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

LE_Fire_PDU::LE_Fire_PDU( const LE_EntityIdentifier & ID ) :
    m_ui16Range( 0 )
{
    m_EntID = ID;
    m_FireFlagUnion.m_ui8Flag = 0;
    m_ui8PDUType = LEFire_PDU_Type;
    m_ui16PDULength = LE_FIRE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

LE_Fire_PDU::LE_Fire_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

LE_Fire_PDU::LE_Fire_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	LE_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

LE_Fire_PDU::~LE_Fire_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void LE_Fire_PDU::SetTargetEntityIDFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_FireFlagUnion.m_ui8TargetId )return;

    m_FireFlagUnion.m_ui8TargetId = F;

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

KBOOL LE_Fire_PDU::GetTargetEntityIDFlag() const
{
    return m_FireFlagUnion.m_ui8TargetId;
}

//////////////////////////////////////////////////////////////////////////

void LE_Fire_PDU::SetMunitionEntityIDFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_FireFlagUnion.m_ui8MunitionId )return;

    m_FireFlagUnion.m_ui8MunitionId = F;

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

KBOOL LE_Fire_PDU::GetMunitionEntityIDFlag() const
{
    return m_FireFlagUnion.m_ui8MunitionId;
}

//////////////////////////////////////////////////////////////////////////

void LE_Fire_PDU::SetMunitionEntityIDSiteAppIncludedFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_FireFlagUnion.m_ui8MunitionSiteApp )return;

    m_FireFlagUnion.m_ui8MunitionSiteApp = F;

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

KBOOL LE_Fire_PDU::GetMunitionEntityIDSiteAppIncludedFlag() const
{
    return m_FireFlagUnion.m_ui8MunitionSiteApp;
}

//////////////////////////////////////////////////////////////////////////

void LE_Fire_PDU::SetEventIDSiteAppIncludedFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_FireFlagUnion.m_ui8EventSiteAppId )return;

    m_FireFlagUnion.m_ui8EventSiteAppId = F;

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

KBOOL LE_Fire_PDU::GetEventIDSiteAppIncludedFlag() const
{
    return m_FireFlagUnion.m_ui8EventSiteAppId;
}

//////////////////////////////////////////////////////////////////////////

void LE_Fire_PDU::SetWarheadFuseFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_FireFlagUnion.m_ui8WarheadFuse )return;

    m_FireFlagUnion.m_ui8WarheadFuse = F;

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

KBOOL LE_Fire_PDU::GetWarheadFuseFlag() const
{
    return m_FireFlagUnion.m_ui8WarheadFuse;
}

//////////////////////////////////////////////////////////////////////////

void LE_Fire_PDU::SetQuantityRateFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_FireFlagUnion.m_ui8QuantRate )return;

    m_FireFlagUnion.m_ui8QuantRate = F;

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

KBOOL LE_Fire_PDU::GetQuantityRateFlag() const
{
    return m_FireFlagUnion.m_ui8QuantRate;
}

//////////////////////////////////////////////////////////////////////////

void LE_Fire_PDU::SetLocationFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_FireFlagUnion.m_ui8Location )return;

    m_FireFlagUnion.m_ui8Location = F;

    if( F )
    {
        m_ui16PDULength += RelativeWorldCoordinates::RELATVE_WORLD_COORDINATES_SIZE;
    }
    else
    {
        m_ui16PDULength -= RelativeWorldCoordinates::RELATVE_WORLD_COORDINATES_SIZE;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Fire_PDU::GetLocationFlag() const
{
    return m_FireFlagUnion.m_ui8Location;
}

//////////////////////////////////////////////////////////////////////////

void LE_Fire_PDU::SetTargetEntityID( const LE_EntityIdentifier & ID )
{
    SetTargetEntityIDFlag( true );
    m_TargetID = ID;
}

//////////////////////////////////////////////////////////////////////////

const LE_EntityIdentifier & LE_Fire_PDU::GetTargetEntityID() const
{
    return m_TargetID;
}

//////////////////////////////////////////////////////////////////////////

LE_EntityIdentifier & LE_Fire_PDU::GetTargetEntityID()
{
    return m_TargetID;
}

//////////////////////////////////////////////////////////////////////////

void LE_Fire_PDU::SetMunitionEntityID( const LE_EntityIdentifier & ID )
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

const LE_EntityIdentifier & LE_Fire_PDU::GetMunitionEntityID() const
{
    return m_MunitionID;
}

//////////////////////////////////////////////////////////////////////////

LE_EntityIdentifier & LE_Fire_PDU::GetMunitionEntityID()
{
    return m_MunitionID;
}

//////////////////////////////////////////////////////////////////////////

void LE_Fire_PDU::SetEventID( const LE_EntityIdentifier & ID )
{
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

const LE_EntityIdentifier & LE_Fire_PDU::GetEventID() const
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

LE_EntityIdentifier & LE_Fire_PDU::GetEventID()
{
    return m_EventID;
}

//////////////////////////////////////////////////////////////////////////

void LE_Fire_PDU::SetLocation( const RelativeWorldCoordinates & L )
{
    SetLocationFlag( true );
    m_Loc = L;
}

//////////////////////////////////////////////////////////////////////////

const RelativeWorldCoordinates & LE_Fire_PDU::GetLocation() const
{
    return m_Loc;
}

//////////////////////////////////////////////////////////////////////////

RelativeWorldCoordinates & LE_Fire_PDU::GetLocation()
{
    return m_Loc;
}

//////////////////////////////////////////////////////////////////////////

void LE_Fire_PDU::SetMunitionDescriptor( const MunitionDescriptor & MD )
{
    m_MunitionDesc = MD;
}

//////////////////////////////////////////////////////////////////////////

const MunitionDescriptor & LE_Fire_PDU::GetMunitionDescriptor() const
{
    return m_MunitionDesc;
}

//////////////////////////////////////////////////////////////////////////

MunitionDescriptor & LE_Fire_PDU::GetMunitionDescriptor()
{
    return m_MunitionDesc;
}

//////////////////////////////////////////////////////////////////////////

void LE_Fire_PDU::SetVelocity( const LE_Vector16_3 & V )
{
    m_Vel = V;
}

//////////////////////////////////////////////////////////////////////////

const LE_Vector16_3 & LE_Fire_PDU::GetVelocity() const
{
    return m_Vel;
}

//////////////////////////////////////////////////////////////////////////

LE_Vector16_3 & LE_Fire_PDU::GetVelocity()
{
    return m_Vel;
}

//////////////////////////////////////////////////////////////////////////

void LE_Fire_PDU::SetRange( KUINT16 R )
{
    m_ui16Range = R;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 LE_Fire_PDU::GetRange() const
{
    return m_ui16Range;
}

//////////////////////////////////////////////////////////////////////////

KString LE_Fire_PDU::GetAsString() const
{
    KStringStream ss;

    ss << LE_Header::GetAsString()
       << "-LE Fire PDU-\n"
       << "Optional Field Flags:\n"
       << "\tTarget ID:							   " << ( KUINT16 )m_FireFlagUnion.m_ui8TargetId         << "\n"
       << "\tMunition ID:						   " << ( KUINT16 )m_FireFlagUnion.m_ui8MunitionId       << "\n"
       << "\tMunition Site & Application Included: " << ( KUINT16 )m_FireFlagUnion.m_ui8MunitionSiteApp  << "\n"
       << "\tEvent Site & Application Included:    " << ( KUINT16 )m_FireFlagUnion.m_ui8EventSiteAppId   << "\n"
       << "\tWarhead & Fuse Included:			   " << ( KUINT16 )m_FireFlagUnion.m_ui8WarheadFuse      << "\n"
       << "\tQuantity & Rate Included:			   " << ( KUINT16 )m_FireFlagUnion.m_ui8QuantRate        << "\n"
       << "\tLocation:							   " << ( KUINT16 )m_FireFlagUnion.m_ui8Location         << "\n";

    if( m_FireFlagUnion.m_ui8TargetId )
    {
        ss << "Target ID: " << m_TargetID.GetAsString();
    }

    if( m_FireFlagUnion.m_ui8MunitionId )
    {
        ss << "Munition ID: " << m_MunitionID.GetAsString();
    }

    ss << "Event ID: " << m_EventID.GetAsString()
       << m_MunitionDesc.GetAsString()
       << m_Loc.GetAsString()
       << "Velocity: " << m_Vel.GetAsString()
       << "Range: " << m_ui16Range
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void LE_Fire_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < LE_FIRE_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    LE_Header::Decode( stream, ignoreHeader );	

    stream >> m_FireFlagUnion.m_ui8Flag;

    // F0: Target Entity ID
    if( m_FireFlagUnion.m_ui8TargetId )
    {
        stream >> KDIS_STREAM m_TargetID;
    }

    KUINT16 tmp = 0;

    // F2: Munition ID
    if( m_FireFlagUnion.m_ui8MunitionId )
    {
        // F1: Site Number and Application Number
        if( m_FireFlagUnion.m_ui8MunitionSiteApp )
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

    // F3: Event ID
    if( m_FireFlagUnion.m_ui8EventSiteAppId )
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

    // F6: Location
    if( m_FireFlagUnion.m_ui8Location )
    {
        stream >> KDIS_STREAM m_Loc;
    }

    // Munition Descriptor
    m_MunitionDesc.SetType( EntityType( stream ) );
    // F4: Warhead and Fuse fields of the Munition Descriptor record
    if( m_FireFlagUnion.m_ui8WarheadFuse )
    {
        stream >> tmp;
        m_MunitionDesc.SetWarhead( ( WarheadType )tmp );

        stream >> tmp;
        m_MunitionDesc.SetFuse( ( FuseType )tmp );
    }
    // F5: Quantity and Rate fields of the Munition Descriptor record
    if( m_FireFlagUnion.m_ui8QuantRate )
    {
        stream >> tmp;
        m_MunitionDesc.SetQuantity( tmp );

        stream >> tmp;
        m_MunitionDesc.SetRate( tmp );
    }

    // Velocity and Range
    stream >> KDIS_STREAM m_Vel
           >> m_ui16Range;
}

////////////////////////////////////////////////////////////////////////////

KDataStream LE_Fire_PDU::Encode() const
{
    KDataStream stream;

    LE_Fire_PDU::Encode( stream );

    return stream;
}

////////////////////////////////////////////////////////////////////////////

void LE_Fire_PDU::Encode( KDataStream & stream ) const
{
    // We need to cast away the const so we can check the flag values are correct
    // Must check the flags before encoding the header since PDU length may change
    LE_Fire_PDU * self = const_cast<LE_Fire_PDU*>( this );
    self->checkFlagsAndPDULength();

    LE_Header::Encode( stream );

    stream << m_FireFlagUnion.m_ui8Flag;

    // F0: Target Entity ID
    if( m_FireFlagUnion.m_ui8TargetId )
    {
        stream << KDIS_STREAM m_TargetID;
    }

    // F2: Munition ID
    if( m_FireFlagUnion.m_ui8MunitionId )
    {
        // F1: Site Number and Application Number
        if( m_FireFlagUnion.m_ui8MunitionSiteApp )
        {
            stream << KDIS_STREAM m_MunitionID;
        }
        else
        {
            // We cant use the standard encode/decode functions here as not all fields are included.
            stream << m_MunitionID.GetEntityID();
        }
    }

    // F3: Event ID
    if( m_FireFlagUnion.m_ui8EventSiteAppId )
    {
        stream << KDIS_STREAM m_EventID;
    }
    else
    {
        // We cant use the standard encode/decode functions here as not all fields are included.
        stream << m_EventID.GetEntityID();
    }

    // F6: Location
    if( m_FireFlagUnion.m_ui8Location )
    {
        stream << KDIS_STREAM m_Loc;
    }

    // Munition
    stream << KDIS_STREAM m_MunitionDesc.GetType();
    // F4: Warhead and Fuse fields of the Munition Descriptor record
    if( m_FireFlagUnion.m_ui8WarheadFuse )
    {
        stream << ( KUINT16 )m_MunitionDesc.GetWarhead()
               << ( KUINT16 )m_MunitionDesc.GetFuse();
    }
    // F5: Quantity and Rate fields of the Munition Descriptor record
    if( m_FireFlagUnion.m_ui8QuantRate )
    {
        stream << m_MunitionDesc.GetQuantity()
               << m_MunitionDesc.GetRate();
    }

    // Velocity and Range
    stream << KDIS_STREAM m_Vel
           << m_ui16Range;

    assert(stream.GetBufferSize() == m_ui16PDULength);
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Fire_PDU::operator == ( const LE_Fire_PDU & Value ) const
{
    if( LE_Header::operator       != ( Value ) )                      return false;
    if( m_FireFlagUnion.m_ui8Flag != Value.m_FireFlagUnion.m_ui8Flag )return false;
    if( m_TargetID                != Value.m_TargetID )               return false;
    if( m_MunitionID              != Value.m_MunitionID )             return false;
    if( m_EventID                 != Value.m_EventID )                return false;
    if( m_MunitionDesc            != Value.m_MunitionDesc )           return false;
    if( m_Loc                     != Value.m_Loc )                    return false;
    if( m_Vel                     != Value.m_Vel )                    return false;
    if( m_ui16Range               != Value.m_ui16Range )              return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LE_Fire_PDU::operator != ( const LE_Fire_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


