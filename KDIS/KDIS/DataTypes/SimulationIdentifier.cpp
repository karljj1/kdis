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

#include "./SimulationIdentifier.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

SimulationIdentifier::SimulationIdentifier() :
    m_ui16SiteID( 0 ),
    m_ui16ApplicationID( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

SimulationIdentifier::SimulationIdentifier( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

SimulationIdentifier::SimulationIdentifier( KUINT16 SiteID, KUINT16 ApplicatonID ) :
    m_ui16SiteID( SiteID ),
    m_ui16ApplicationID( ApplicatonID )
{
}

//////////////////////////////////////////////////////////////////////////

SimulationIdentifier::~SimulationIdentifier()
{
}

//////////////////////////////////////////////////////////////////////////

void SimulationIdentifier::SetSiteID( KUINT16 ID )
{
    m_ui16SiteID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 SimulationIdentifier::GetSiteID() const
{
    return m_ui16SiteID;
}

//////////////////////////////////////////////////////////////////////////

void SimulationIdentifier::SetApplicationID( KUINT16 ID )
{
    m_ui16ApplicationID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 SimulationIdentifier::GetApplicationID() const
{
    return m_ui16ApplicationID;
}

//////////////////////////////////////////////////////////////////////////

KString SimulationIdentifier::GetAsString() const
{
    KStringStream ss;

    ss << "Site:        " << m_ui16SiteID           << "\n"
       << "Application: " << m_ui16ApplicationID    << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void SimulationIdentifier::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < SIMULATION_IDENTIFIER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16SiteID
           >> m_ui16ApplicationID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream SimulationIdentifier::Encode() const
{
    KDataStream stream;

    SimulationIdentifier::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void SimulationIdentifier::Encode( KDataStream & stream ) const
{
    stream << m_ui16SiteID
           << m_ui16ApplicationID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SimulationIdentifier::operator == ( const SimulationIdentifier & Value ) const
{
    if( m_ui16SiteID        != Value.m_ui16SiteID )         return false;
    if( m_ui16ApplicationID != Value.m_ui16ApplicationID )  return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SimulationIdentifier::operator != ( const SimulationIdentifier & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

KBOOL SimulationIdentifier::operator <  ( const SimulationIdentifier & Value ) const
{
    // We will bit shift all fields into a single KUINT64, this will generate a new unique value which we can then use for comparison.
    // bits 0-15  = SiteID
    // bits 16-31 = ApplicationID
    // bits 32-63 = 0
    KUINT64 ui64ThisCmpVal = 0, ui64OtherCmpVal = 0;

    ui64ThisCmpVal = m_ui16SiteID | ( KUINT64 )m_ui16ApplicationID << 16;
    ui64OtherCmpVal = Value.m_ui16SiteID | ( KUINT64 )Value.m_ui16ApplicationID << 16;

    return ui64ThisCmpVal < ui64OtherCmpVal;
}

//////////////////////////////////////////////////////////////////////////
