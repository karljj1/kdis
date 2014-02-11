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

#include "./ObjectAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

ObjectAppearance::ObjectAppearance()
{
    m_GeneralAppearanceUnion.m_ui16GeneralAppearance = 0;
}

//////////////////////////////////////////////////////////////////////////

ObjectAppearance::ObjectAppearance( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

ObjectAppearance::ObjectAppearance( KUINT8 PerCent, ObjectDamage OD, KBOOL Predist, KBOOL State,
                                    KBOOL Smoking, KBOOL Flaming ) throw( KException )
{
    if( PerCent > 100 ) throw KException( __FUNCTION__, INVALID_DATA, "PerCent Acceptable values are 0-100." );

    m_GeneralAppearanceUnion.m_ui16PcComp = PerCent;
    m_GeneralAppearanceUnion.m_ui16Dmg = OD;
    m_GeneralAppearanceUnion.m_ui16Predistributed = Predist;
    m_GeneralAppearanceUnion.m_ui16State = State;
    m_GeneralAppearanceUnion.m_ui16Smoking = Smoking;
    m_GeneralAppearanceUnion.m_ui16Flaming = Flaming;
}

//////////////////////////////////////////////////////////////////////////

ObjectAppearance::~ObjectAppearance()
{
}

//////////////////////////////////////////////////////////////////////////

void ObjectAppearance::SetGeneralAppearance( KUINT16 GA )
{
    m_GeneralAppearanceUnion.m_ui16GeneralAppearance = GA;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 ObjectAppearance::GetGeneralAppearance() const
{
    return m_GeneralAppearanceUnion.m_ui16GeneralAppearance;
}

//////////////////////////////////////////////////////////////////////////

void ObjectAppearance::SetPercentageComplete( KUINT8 P ) throw( KException )
{
    if( P > 100 ) throw KException( __FUNCTION__, INVALID_DATA, "Acceptable values are 0-100." );

    m_GeneralAppearanceUnion.m_ui16PcComp = P;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 ObjectAppearance::GetPercentageComplete() const
{
    return m_GeneralAppearanceUnion.m_ui16PcComp;
}

//////////////////////////////////////////////////////////////////////////

void ObjectAppearance::SetDamage( ObjectDamage OD )
{
    m_GeneralAppearanceUnion.m_ui16Dmg = OD;
}

//////////////////////////////////////////////////////////////////////////

ObjectDamage ObjectAppearance::GetDamage() const
{
    return ( ObjectDamage )m_GeneralAppearanceUnion.m_ui16Dmg;
}

//////////////////////////////////////////////////////////////////////////

void ObjectAppearance::SetPredistributed( KBOOL P )
{
    m_GeneralAppearanceUnion.m_ui16Predistributed = P;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ObjectAppearance::IsPredistributed() const
{
    return m_GeneralAppearanceUnion.m_ui16Predistributed;
}

//////////////////////////////////////////////////////////////////////////

void ObjectAppearance::SetState( KBOOL S )
{
    m_GeneralAppearanceUnion.m_ui16State = S;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ObjectAppearance::GetState() const
{
    return m_GeneralAppearanceUnion.m_ui16State;
}

//////////////////////////////////////////////////////////////////////////

void ObjectAppearance::SetSmoking( KBOOL S )
{
    m_GeneralAppearanceUnion.m_ui16Smoking = S;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ObjectAppearance::IsSmoking() const
{
    return m_GeneralAppearanceUnion.m_ui16Smoking;
}

//////////////////////////////////////////////////////////////////////////

void ObjectAppearance::SetFlaming( KBOOL F )
{
    m_GeneralAppearanceUnion.m_ui16Flaming = F;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ObjectAppearance::IsFlaming() const
{
    return m_GeneralAppearanceUnion.m_ui16Flaming;
}

//////////////////////////////////////////////////////////////////////////

KString ObjectAppearance::GetAsString() const
{
    KStringStream ss;

    ss << "Object Appearance:\n"
       << "\tGeneral Appearance:"
       << "\tPercent Complete:  " << m_GeneralAppearanceUnion.m_ui16PcComp         << "\n"
       << "\tDamage:            " << GetEnumAsStringObjectDamage( m_GeneralAppearanceUnion.m_ui16Dmg ) << "\n"
       << "\tPredistributed:    " << m_GeneralAppearanceUnion.m_ui16Predistributed << "\n"
       << "\tState:             " << m_GeneralAppearanceUnion.m_ui16State          << "\n"
       << "\tSmoking:           " << m_GeneralAppearanceUnion.m_ui16Smoking        << "\n"
       << "\tFlaming:           " << m_GeneralAppearanceUnion.m_ui16Flaming        << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ObjectAppearance::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < OBJECT_APPEARANCE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    // Do not swap endian.
    stream >> m_GeneralAppearanceUnion.m_ui8GeneralAppearance[1]
           >> m_GeneralAppearanceUnion.m_ui8GeneralAppearance[0];
}

//////////////////////////////////////////////////////////////////////////

KDataStream ObjectAppearance::Encode() const
{
    KDataStream stream;

    ObjectAppearance::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ObjectAppearance::Encode( KDataStream & stream ) const
{
    // Do not swap endian.
    stream << m_GeneralAppearanceUnion.m_ui8GeneralAppearance[1]
           << m_GeneralAppearanceUnion.m_ui8GeneralAppearance[0];
}

//////////////////////////////////////////////////////////////////////////

KBOOL ObjectAppearance::operator == ( const ObjectAppearance & Value ) const
{
    if( m_GeneralAppearanceUnion.m_ui16GeneralAppearance != Value.m_GeneralAppearanceUnion.m_ui16GeneralAppearance ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ObjectAppearance::operator != ( const ObjectAppearance & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
