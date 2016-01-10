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

#include "./Appearance_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Appearance_PDU::Appearance_PDU()
{
    m_AppearanceFlag1Union.m_ui8Flag = 0;
    m_AppearanceFlag2Union.m_ui8Flag = 0;
    m_ui8PDUType = Appearance_PDU_Type;
    m_ui16PDULength = APPEARANCE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Appearance_PDU::Appearance_PDU( const LE_EntityIdentifier & ID )
{
    m_EntID = ID;
    m_AppearanceFlag1Union.m_ui8Flag = 0;
    m_AppearanceFlag2Union.m_ui8Flag = 0;
    m_ui8PDUType = Appearance_PDU_Type;
    m_ui16PDULength = APPEARANCE_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Appearance_PDU::Appearance_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Appearance_PDU::Appearance_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
    LE_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Appearance_PDU::~Appearance_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetForceIDFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_AppearanceFlag1Union.m_ui8ForceId )return;

    m_AppearanceFlag1Union.m_ui8ForceId = F;

    if( F )
    {
        m_ui16PDULength += 1; // 1 = Size of force id
    }
    else
    {
        m_ui16PDULength -= 1;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Appearance_PDU::GetForceIDFlag() const
{
    return m_AppearanceFlag1Union.m_ui8ForceId;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetEntityTypeFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_AppearanceFlag1Union.m_ui8Typ )return;

    m_AppearanceFlag1Union.m_ui8Typ = F;

    if( F )
    {
        m_ui16PDULength += EntityType::ENTITY_TYPE_SIZE;
    }
    else
    {
        m_ui16PDULength -= EntityType::ENTITY_TYPE_SIZE;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Appearance_PDU::GetEntityTypeFlag() const
{
    return m_AppearanceFlag1Union.m_ui8Typ;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetAlternateEntityTypeFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_AppearanceFlag1Union.m_ui8AltTyp )return;

    m_AppearanceFlag1Union.m_ui8AltTyp = F;

    if( F )
    {
        m_ui16PDULength += EntityType::ENTITY_TYPE_SIZE;
    }
    else
    {
        m_ui16PDULength -= EntityType::ENTITY_TYPE_SIZE;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Appearance_PDU::GetAlternateEntityTypeFlag() const
{
    return m_AppearanceFlag1Union.m_ui8AltTyp;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetEntityMarkingFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_AppearanceFlag1Union.m_ui8Mark )return;

    m_AppearanceFlag1Union.m_ui8Mark = F;

    if( F )
    {
        m_ui16PDULength += EntityMarking::ENTITY_MARKING_SIZE;
    }
    else
    {
        m_ui16PDULength -= EntityMarking::ENTITY_MARKING_SIZE;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Appearance_PDU::GetEntityMarkingFlag() const
{
    return m_AppearanceFlag1Union.m_ui8Mark;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetCapabilitiesFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_AppearanceFlag1Union.m_ui8Cap )return;

    m_AppearanceFlag1Union.m_ui8Cap = F;

    if( F )
    {
        m_ui16PDULength += EntityCapabilities::ENTITY_CAPABILITIES_SIZE;
    }
    else
    {
        m_ui16PDULength -= EntityCapabilities::ENTITY_CAPABILITIES_SIZE;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Appearance_PDU::GetCapabilitiesFlag() const
{
    return m_AppearanceFlag1Union.m_ui8Cap;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetAppearanceVisualFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_AppearanceFlag1Union.m_ui8Vis )return;

    m_AppearanceFlag1Union.m_ui8Vis = F;

    if( F )
    {
        m_ui16PDULength += EntityAppearance::ENTITY_APPEARANCE_SIZE;
    }
    else
    {
        m_ui16PDULength -= EntityAppearance::ENTITY_APPEARANCE_SIZE;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Appearance_PDU::GetAppearanceVisualFlag() const
{
    return m_AppearanceFlag1Union.m_ui8Vis;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetAppearanceIRFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_AppearanceFlag1Union.m_ui8IR )return;

    m_AppearanceFlag1Union.m_ui8IR = F;

    if( F )
    {
        m_ui16PDULength += EntityAppearance::ENTITY_APPEARANCE_SIZE;
    }
    else
    {
        m_ui16PDULength -= EntityAppearance::ENTITY_APPEARANCE_SIZE;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Appearance_PDU::GetAppearanceIRFlag() const
{
    return m_AppearanceFlag1Union.m_ui8IR;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetFlag2Flag( KBOOL F )
{
    if( ( KUINT8 )F == m_AppearanceFlag1Union.m_ui8Flag2 )return;

    m_AppearanceFlag1Union.m_ui8Flag2 = F;

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

KBOOL Appearance_PDU::GetFlag2Flag() const
{
    return m_AppearanceFlag1Union.m_ui8Flag2;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetAppearanceEMFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_AppearanceFlag2Union.m_ui8EM )return;

    m_AppearanceFlag2Union.m_ui8EM = F;

    if( F )
    {
        SetFlag2Flag( F );
        m_ui16PDULength += EntityAppearance::ENTITY_APPEARANCE_SIZE;
    }
    else
    {
        m_ui16PDULength -= EntityAppearance::ENTITY_APPEARANCE_SIZE;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Appearance_PDU::GetAppearanceEMFlag() const
{
    return m_AppearanceFlag2Union.m_ui8EM;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetAppearanceAudioFlag( KBOOL F )
{
    if( ( KUINT8 )F == m_AppearanceFlag2Union.m_ui8Audio )return;

    m_AppearanceFlag2Union.m_ui8Audio = F;

    if( F )
    {
        SetFlag2Flag( F );
        m_ui16PDULength += EntityAppearance::ENTITY_APPEARANCE_SIZE;
    }
    else
    {
        m_ui16PDULength -= EntityAppearance::ENTITY_APPEARANCE_SIZE;
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Appearance_PDU::GetAppearanceAudioFlag() const
{
    return m_AppearanceFlag2Union.m_ui8Audio;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetForceID( ForceID ID )
{
    SetForceIDFlag( true );
    m_ui8ForceID = ID;
}

//////////////////////////////////////////////////////////////////////////

ForceID Appearance_PDU::GetForceID() const
{
    return ( ForceID )m_ui8ForceID;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetEntityType( const EntityType & Type )
{
    SetEntityTypeFlag( true );
    m_EntityType = Type;
}

//////////////////////////////////////////////////////////////////////////

const EntityType & Appearance_PDU::GetEntityType() const
{
    return m_EntityType;
}

//////////////////////////////////////////////////////////////////////////

EntityType & Appearance_PDU::GetEntityType()
{
    return m_EntityType;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetAltEntityType( const EntityType & Type )
{
    SetAlternateEntityTypeFlag( true );
    m_AltEntityType = Type;
}

//////////////////////////////////////////////////////////////////////////

const EntityType & Appearance_PDU::GetAltEntityType() const
{
    return m_AltEntityType;
}

//////////////////////////////////////////////////////////////////////////

EntityType & Appearance_PDU::GetAltEntityType()
{
    return m_AltEntityType;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetEntityMarking( const EntityMarking & EM )
{
    SetEntityMarkingFlag( true );
    m_EntityMarking = EM;
}

//////////////////////////////////////////////////////////////////////////

const EntityMarking & Appearance_PDU::GetEntityMarking() const
{
    return m_EntityMarking;
}

//////////////////////////////////////////////////////////////////////////

EntityMarking & Appearance_PDU::GetEntityMarking()
{
    return m_EntityMarking;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetEntityCapabilities( const EntityCapabilities & EC )
{
    SetCapabilitiesFlag( true );
    m_EntityCapabilities = EC;
}

//////////////////////////////////////////////////////////////////////////

const EntityCapabilities & Appearance_PDU::GetEntityCapabilities() const
{
    return m_EntityCapabilities;
}

//////////////////////////////////////////////////////////////////////////

EntityCapabilities & Appearance_PDU::GetEntityCapabilities()
{
    return m_EntityCapabilities;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetAppearanceVisual( const EntityAppearance & V )
{
    SetAppearanceVisualFlag( true );
    m_VisApp = V;
}

//////////////////////////////////////////////////////////////////////////

const EntityAppearance & Appearance_PDU::GetAppearanceVisual() const
{
    return m_VisApp;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance & Appearance_PDU::GetAppearanceVisual()
{
    return m_VisApp;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetAppearanceIR( const EntityAppearance & IR )
{
    SetAppearanceIRFlag( true );
    m_IRApp = IR;
}

//////////////////////////////////////////////////////////////////////////

const EntityAppearance & Appearance_PDU::GetAppearanceIR() const
{
    return m_IRApp;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance & Appearance_PDU::GetAppearanceIR()
{
    return m_IRApp;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetAppearanceEM( const EntityAppearance & EM )
{
    SetAppearanceEMFlag( true );
    m_EMApp = EM;
}

//////////////////////////////////////////////////////////////////////////

const EntityAppearance & Appearance_PDU::GetAppearanceEM() const
{
    return m_EMApp;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance & Appearance_PDU::GetAppearanceEM()
{
    return m_EMApp;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::SetAppearanceAudio( const EntityAppearance & A )
{
    SetAppearanceAudioFlag( true );
    m_AudApp = A;
}

//////////////////////////////////////////////////////////////////////////

const EntityAppearance & Appearance_PDU::GetAppearanceAudio() const
{
    return m_AudApp;
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance & Appearance_PDU::GetAppearanceAudio()
{
    return m_AudApp;
}

//////////////////////////////////////////////////////////////////////////

KString Appearance_PDU::GetAsString() const
{
    KStringStream ss;

    ss << LE_Header::GetAsString()
       << "-Appearance PDU-\n"
       << "Optional Field Flags:\n"
       << "\tForce ID:              " << GetEnumAsStringForceID( m_AppearanceFlag1Union.m_ui8ForceId ) << "\n"
       << "\tEntity Type:           " << ( KUINT16 )m_AppearanceFlag1Union.m_ui8Typ    << "\n"
       << "\tAlternate Entity Type: " << ( KUINT16 )m_AppearanceFlag1Union.m_ui8AltTyp << "\n"
       << "\tEntity Marking:        " << ( KUINT16 )m_AppearanceFlag1Union.m_ui8Mark   << "\n"
       << "\tCapabilities:          " << ( KUINT16 )m_AppearanceFlag1Union.m_ui8Cap    << "\n"
       << "\tAppearance-Visual:     " << ( KUINT16 )m_AppearanceFlag1Union.m_ui8Vis    << "\n"
       << "\tAppearance-IR:         " << ( KUINT16 )m_AppearanceFlag1Union.m_ui8IR     << "\n"
       << "\tFlag2:                 " << ( KUINT16 )m_AppearanceFlag1Union.m_ui8Flag2  << "\n"
       << "\tAppearance-EM:         " << ( KUINT16 )m_AppearanceFlag2Union.m_ui8EM     << "\n"
       << "\tAppearance-Audio:      " << ( KUINT16 )m_AppearanceFlag2Union.m_ui8Audio  << "\n";

    if (m_AppearanceFlag1Union.m_ui8Flag2)
    {
        ss << "\tAppearance-EM:         " << (KUINT16)m_AppearanceFlag2Union.m_ui8EM << "\n"
           << "\tAppearance-Audio:      " << (KUINT16)m_AppearanceFlag2Union.m_ui8Audio << "\n";
    }

    if( m_AppearanceFlag1Union.m_ui8ForceId )
    {
        ss << "Force ID:          " << GetEnumAsStringForceID( m_ui8ForceID ) << "\n";
    }

    if( m_AppearanceFlag1Union.m_ui8Typ )
    {
        ss << "Entity Type:         " << m_EntityType.GetAsString();
    }

    if( m_AppearanceFlag1Union.m_ui8AltTyp )
    {
        ss << "Alternate Entity Type:         " << m_AltEntityType.GetAsString();
    }

    if( m_AppearanceFlag1Union.m_ui8Mark )
    {
        ss << m_EntityMarking.GetAsString();
    }

    if( m_AppearanceFlag1Union.m_ui8Cap )
    {
        ss << m_EntityCapabilities.GetAsString();
    }

    if( m_AppearanceFlag1Union.m_ui8Vis )
    {
        ss << "Appearance-Visual:\n" << IndentString( m_VisApp.GetAsString( m_EntityType ), 1 );
    }

    if( m_AppearanceFlag1Union.m_ui8IR )
    {
        ss << "Appearance-IR:\n" << IndentString( m_IRApp.GetAsString( m_EntityType ), 1 );
    }

    if( m_AppearanceFlag1Union.m_ui8Flag2 )
    {
        if( m_AppearanceFlag2Union.m_ui8EM )
        {
            ss << "Appearance-EM:\n" << IndentString( m_EMApp.GetAsString( m_EntityType ), 1 );
        }

        if( m_AppearanceFlag2Union.m_ui8Audio )
        {
            ss << "Appearance-Audio:\n" << IndentString( m_AudApp.GetAsString( m_EntityType ), 1 );
        }
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < APPEARANCE_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    LE_Header::Decode( stream, ignoreHeader );

    // Reset flags
    m_AppearanceFlag1Union.m_ui8Flag = 0;
    m_AppearanceFlag2Union.m_ui8Flag = 0;

    stream >> m_AppearanceFlag1Union.m_ui8Flag;

    if( m_AppearanceFlag1Union.m_ui8Flag2 )
    {
        stream >> m_AppearanceFlag2Union.m_ui8Flag;
    }

    if( m_AppearanceFlag1Union.m_ui8ForceId )
    {
        stream >> m_ui8ForceID;
    }

    if( m_AppearanceFlag1Union.m_ui8Typ )
    {
        stream >> KDIS_STREAM m_EntityType;
    }

    if( m_AppearanceFlag1Union.m_ui8AltTyp )
    {
        stream >> KDIS_STREAM m_AltEntityType;
    }

    if( m_AppearanceFlag1Union.m_ui8Mark )
    {
        stream >> KDIS_STREAM m_EntityMarking;
    }

    if( m_AppearanceFlag1Union.m_ui8Cap )
    {
        stream >> KDIS_STREAM m_EntityCapabilities;
    }

    if( m_AppearanceFlag1Union.m_ui8Vis )
    {
        stream >> KDIS_STREAM m_VisApp;
    }

    if( m_AppearanceFlag1Union.m_ui8IR )
    {
        stream >> KDIS_STREAM m_IRApp;
    }

    if( m_AppearanceFlag1Union.m_ui8Flag2 )
    {
        if( m_AppearanceFlag2Union.m_ui8EM )
        {
            stream >> KDIS_STREAM m_EMApp;
        }

        if( m_AppearanceFlag2Union.m_ui8Audio )
        {
            stream >> KDIS_STREAM m_AudApp;
        }
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Appearance_PDU::Encode() const
{
    KDataStream stream;

    Appearance_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Appearance_PDU::Encode( KDataStream & stream ) const
{
    LE_Header::Encode( stream );

    stream << m_AppearanceFlag1Union.m_ui8Flag;

    if( m_AppearanceFlag1Union.m_ui8Flag2 )
    {
        stream << m_AppearanceFlag2Union.m_ui8Flag;
    }

    if( m_AppearanceFlag1Union.m_ui8ForceId )
    {
        stream << m_ui8ForceID;
    }

    if( m_AppearanceFlag1Union.m_ui8Typ )
    {
        stream << KDIS_STREAM m_EntityType;
    }

    if( m_AppearanceFlag1Union.m_ui8AltTyp )
    {
        stream << KDIS_STREAM m_AltEntityType;
    }

    if( m_AppearanceFlag1Union.m_ui8Mark )
    {
        stream << KDIS_STREAM m_EntityMarking;
    }

    if( m_AppearanceFlag1Union.m_ui8Cap )
    {
        stream << KDIS_STREAM m_EntityCapabilities;
    }

    if( m_AppearanceFlag1Union.m_ui8Vis )
    {
        stream << KDIS_STREAM m_VisApp;
    }

    if( m_AppearanceFlag1Union.m_ui8IR )
    {
        stream << KDIS_STREAM m_IRApp;
    }

    if( m_AppearanceFlag1Union.m_ui8Flag2 )
    {
        if( m_AppearanceFlag2Union.m_ui8EM )
        {
            stream << KDIS_STREAM m_EMApp;
        }

        if( m_AppearanceFlag2Union.m_ui8Audio )
        {
            stream << KDIS_STREAM m_AudApp;
        }
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Appearance_PDU::operator == ( const Appearance_PDU & Value ) const
{
    if( LE_Header::operator              != ( Value ) )                             return false;
    if( m_AppearanceFlag1Union.m_ui8Flag != Value.m_AppearanceFlag1Union.m_ui8Flag )return false;
    if( m_AppearanceFlag2Union.m_ui8Flag != Value.m_AppearanceFlag2Union.m_ui8Flag )return false;
    if( m_ui8ForceID                     != Value.m_ui8ForceID )                    return false;
    if( m_EntityType                     != Value.m_EntityType )                    return false;
    if( m_AltEntityType                  != Value.m_AltEntityType )                 return false;
    if( m_EntityMarking                  != Value.m_EntityMarking )                 return false;
    if( m_EntityCapabilities             != Value.m_EntityCapabilities )            return false;
    if( m_VisApp                         != Value.m_VisApp )                        return false;
    if( m_IRApp                          != Value.m_IRApp )                         return false;
    if( m_EMApp                          != Value.m_EMApp )                         return false;
    if( m_AudApp                         != Value.m_AudApp )                        return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Appearance_PDU::operator != ( const Appearance_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


