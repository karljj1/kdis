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

#include "./ObjectAppearance.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

ObjectAppearance::ObjectAppearance( void )
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

ObjectAppearance::~ObjectAppearance( void )
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
