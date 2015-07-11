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

#include "./IFF_LayerFormat.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

IFF_LayerFormat::IFF_LayerFormat() :
	m_ui16Padding( 0 ),
	m_ui16NumIffRecs( 0 )	
{
	m_ui8LayerNumber = 3;
	m_ui16LayerLength = IFF_LAYER3_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IFF_LayerFormat::IFF_LayerFormat( const LayerHeader & H ) :
	LayerHeader( H )
{
}

//////////////////////////////////////////////////////////////////////////

IFF_LayerFormat::~IFF_LayerFormat()
{
}

//////////////////////////////////////////////////////////////////////////

void IFF_LayerFormat::SetReportingSimulation( const SimulationIdentifier & RS )
{
	m_RptSim = RS;
}

//////////////////////////////////////////////////////////////////////////

const SimulationIdentifier & IFF_LayerFormat::GetReportingSimulation() const
{
	return m_RptSim;
}

//////////////////////////////////////////////////////////////////////////

SimulationIdentifier & IFF_LayerFormat::GetReportingSimulation()
{
	return m_RptSim;
}

//////////////////////////////////////////////////////////////////////////

void IFF_LayerFormat::AddDataRecord( StdVarPtr DR )
{
	m_vStdVarRecs.push_back( DR );
	++m_ui16NumIffRecs;
    m_ui16LayerLength += DR->GetRecordLength();
}

//////////////////////////////////////////////////////////////////////////

void IFF_LayerFormat::SetDataRecords( const std::vector<StdVarPtr> & DRS )
{
	m_vStdVarRecs = DRS;

    // Reset the PDU length.
	m_ui16LayerLength = IFF_LAYER3_SIZE;

    // Calculate the new length.
    KUINT16 ui16Length = 0;
    vector<StdVarPtr>::const_iterator citr = m_vStdVarRecs.begin();
    vector<StdVarPtr>::const_iterator citrEnd = m_vStdVarRecs.end();
    for( ; citr != citrEnd; ++citr )
    {
        m_ui16LayerLength += ( *citr )->GetRecordLength();
    }

    m_ui16NumIffRecs = m_vStdVarRecs.size();
}

//////////////////////////////////////////////////////////////////////////

const std::vector<StdVarPtr> & IFF_LayerFormat::GetDataRecords() const
{
	return m_vStdVarRecs;
}

//////////////////////////////////////////////////////////////////////////

void IFF_LayerFormat::ClearDataRecords()
{
	// Reset the length.
	m_ui16LayerLength = IFF_LAYER3_SIZE;

    m_vStdVarRecs.clear();
    m_ui16NumIffRecs = 0;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 IFF_LayerFormat::GetNumberDataRecords() const
{
	return m_ui16NumIffRecs;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_LayerFormat::operator == ( const IFF_LayerFormat & Value ) const
{
    if( LayerHeader::operator !=( Value ) )            return false;    
    if( m_RptSim              != Value.m_RptSim )      return false;
    if( m_vStdVarRecs         != Value.m_vStdVarRecs ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_LayerFormat::operator != ( const IFF_LayerFormat & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
