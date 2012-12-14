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

#include "./SilentEntitySystem.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

SilentEntitySystem::SilentEntitySystem( void ) :
    m_ui16NumEnts( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

SilentEntitySystem::SilentEntitySystem( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

SilentEntitySystem::~SilentEntitySystem( void )
{
    m_vEA.clear();
}

//////////////////////////////////////////////////////////////////////////

void SilentEntitySystem::SetNumberOfEntities( KUINT16 NOE )
{
    m_ui16NumEnts = NOE;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 SilentEntitySystem::GetNumberOfEntities() const
{
    return m_ui16NumEnts;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 SilentEntitySystem::GetNumberOfAppearanceRecords() const
{
    return m_ui16NumOfAppearanceRecords;
}

//////////////////////////////////////////////////////////////////////////

void SilentEntitySystem::SetEntityType( const EntityType & A )
{
    m_EntTyp = A;
}

//////////////////////////////////////////////////////////////////////////

const EntityType & SilentEntitySystem::GetEntityType() const
{
    return m_EntTyp;
}

//////////////////////////////////////////////////////////////////////////

EntityType & SilentEntitySystem::GetEntityType()
{
    return m_EntTyp;
}

//////////////////////////////////////////////////////////////////////////

void SilentEntitySystem::AddEntityAppearance( const EntityAppearance & EA ) throw( KException )
{
    if( m_vEA.size() >= m_ui16NumEnts )throw KException( __FUNCTION__, OUT_OF_BOUNDS );


    m_vEA.push_back( EA );
    m_ui16NumOfAppearanceRecords = m_vEA.size();
}

//////////////////////////////////////////////////////////////////////////

void SilentEntitySystem::SetEntityAppearanceList( const vector<EntityAppearance> & EA ) throw( KException )
{
    if( EA.size() >= m_ui16NumEnts )throw KException( __FUNCTION__, OUT_OF_BOUNDS );

    m_vEA = EA;
    m_ui16NumOfAppearanceRecords = m_vEA.size();
}

//////////////////////////////////////////////////////////////////////////

const vector<EntityAppearance> & SilentEntitySystem::GetEntityAppearanceList() const
{
    return m_vEA;
}

//////////////////////////////////////////////////////////////////////////

void SilentEntitySystem::ClearEntityAppearanceList()
{
    m_vEA.clear();
    m_ui16NumOfAppearanceRecords = 0;
}

//////////////////////////////////////////////////////////////////////////

KString SilentEntitySystem::GetAsString() const
{
    KStringStream ss;

    ss << "Silent Entity System:\n"
       << "Number Of Entities:             " << m_ui16NumEnts               << "\n"
       << "Number Of Appearance Records:   " << m_ui16NumOfAppearanceRecords << "\n"
       << m_EntTyp.GetAsString();

    vector<EntityAppearance>::const_iterator citr = m_vEA.begin();
    vector<EntityAppearance>::const_iterator citrEnd = m_vEA.end();

    for( ; citr != citrEnd; ++citr )
    {
        ss << citr->GetAsString( m_EntTyp );
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void SilentEntitySystem::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < SILENT_ENTITY_SYSTEM_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vEA.clear();

    stream >> m_ui16NumEnts
           >> m_ui16NumOfAppearanceRecords
           >> KDIS_STREAM m_EntTyp;

    for( KUINT16 i = 0; i < m_ui16NumOfAppearanceRecords; ++i )
    {
        m_vEA.push_back( EntityAppearance( stream ) );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream SilentEntitySystem::Encode() const
{
    KDataStream stream;

    SilentEntitySystem::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void SilentEntitySystem::Encode( KDataStream & stream ) const
{
    stream << m_ui16NumEnts
           << m_ui16NumOfAppearanceRecords
           << KDIS_STREAM m_EntTyp;

    vector<EntityAppearance>::const_iterator citr = m_vEA.begin();
    vector<EntityAppearance>::const_iterator citrEnd = m_vEA.end();

    for( ; citr != m_vEA.end(); ++citr )
    {
        citr->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL SilentEntitySystem::operator == ( const SilentEntitySystem & Value ) const
{
    if( m_ui16NumEnts                 != Value.m_ui16NumEnts )                return false;
    if( m_ui16NumOfAppearanceRecords  != Value.m_ui16NumOfAppearanceRecords ) return false;
    if( m_EntTyp                      != Value.m_EntTyp )                     return false;
    if( m_vEA                         != Value.m_vEA )                        return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SilentEntitySystem::operator != ( const SilentEntitySystem & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


