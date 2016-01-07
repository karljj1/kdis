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

#include "./SilentEntitySystem.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

SilentEntitySystem::SilentEntitySystem() :
    m_ui16NumEnts( 0 ),
    m_ui16NumOfAppearanceRecords( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

SilentEntitySystem::SilentEntitySystem( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

SilentEntitySystem::~SilentEntitySystem()
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
    for( ; citr != citrEnd; ++citr )
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


