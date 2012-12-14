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

#include "./Articulated_Parts_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace std;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Articulated_Parts_PDU::Articulated_Parts_PDU( void ) :
    m_ui8NumOfArticulationParams( 0 )
{
    m_ui8PDUType = ArticulatedParts_PDU_Type;
    m_ui16PDULength = ARTICULATED_PARTS_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Articulated_Parts_PDU::Articulated_Parts_PDU( const LE_EntityIdentifier & ID ) :
    m_ui8NumOfArticulationParams( 0 )
{
    m_EntID = ID;
    m_ui8PDUType = ArticulatedParts_PDU_Type;
    m_ui16PDULength = ARTICULATED_PARTS_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

Articulated_Parts_PDU::Articulated_Parts_PDU( KDataStream & stream ) throw( KException )
{
    try
    {
        Decode( stream );
    }
    catch ( KException & e )
    {
        throw e;
    }
}

//////////////////////////////////////////////////////////////////////////

Articulated_Parts_PDU::~Articulated_Parts_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Articulated_Parts_PDU::GetNumberOfArticulationParams() const
{
    return m_ui8NumOfArticulationParams;
}

//////////////////////////////////////////////////////////////////////////

void Articulated_Parts_PDU::AddArticulationParameter( const ArticulationParameters & AP )
{
    m_vArticulationParameters.push_back( AP );
    ++m_ui8NumOfArticulationParams;
    m_ui16PDULength += ArticulationParameters::ARTICULATION_PARAMETERS_SIZE;
}

//////////////////////////////////////////////////////////////////////////

void Articulated_Parts_PDU::SetArticulationParameters( const vector<ArticulationParameters> & AP )
{
    m_vArticulationParameters = AP;
    m_ui8NumOfArticulationParams = m_vArticulationParameters.size();
    m_ui16PDULength = ARTICULATED_PARTS_PDU_SIZE + ( m_ui8NumOfArticulationParams * ArticulationParameters::ARTICULATION_PARAMETERS_SIZE );
}

//////////////////////////////////////////////////////////////////////////

void Articulated_Parts_PDU::ClearArticulationParameters()
{
    m_vArticulationParameters.clear();
    m_ui8NumOfArticulationParams = 0;
    m_ui16PDULength = ARTICULATED_PARTS_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

KString Articulated_Parts_PDU::GetAsString() const
{
    KStringStream ss;

    ss << LE_Header::GetAsString()
       << "-Articulated Parts PDU-\n"
       << "Number Of Art Parts: " << ( KUINT16 )m_ui8NumOfArticulationParams << "\n";

    // Articulated parts
    vector<ArticulationParameters>::const_iterator citr = m_vArticulationParameters.begin();
    vector<ArticulationParameters>::const_iterator citrEnd = m_vArticulationParameters.end();
    for( ; citr != citrEnd; ++ citr )
    {
        ss << citr->GetAsString();
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Articulated_Parts_PDU::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ARTICULATED_PARTS_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vArticulationParameters.clear();

    LE_Header::Decode( stream );

    stream >> m_ui8NumOfArticulationParams;

    for( KUINT8 i = 0; i < m_ui8NumOfArticulationParams; ++i )
    {
        m_vArticulationParameters.push_back( ArticulationParameters( stream ) );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream Articulated_Parts_PDU::Encode() const
{
    KDataStream stream;

    Articulated_Parts_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Articulated_Parts_PDU::Encode( KDataStream & stream ) const
{
    LE_Header::Encode( stream );

    stream << m_ui8NumOfArticulationParams;

    // Add the articulated parts
    vector<ArticulationParameters>::const_iterator citr = m_vArticulationParameters.begin();
    vector<ArticulationParameters>::const_iterator citrEnd = m_vArticulationParameters.end();
    for( ; citr != citrEnd; ++ citr )
    {
        citr->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Articulated_Parts_PDU::operator == ( const Articulated_Parts_PDU & Value ) const
{
    if( LE_Header::operator          != ( Value ) )                         return false;
    if( m_ui8NumOfArticulationParams != Value.m_ui8NumOfArticulationParams )return false;
    if( m_vArticulationParameters    != Value.m_vArticulationParameters )   return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Articulated_Parts_PDU::operator != ( const Articulated_Parts_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


