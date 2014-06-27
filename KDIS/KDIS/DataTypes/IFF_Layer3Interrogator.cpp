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

#include "./IFF_Layer3Interrogator.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

IFF_Layer3Interrogator::IFF_Layer3Interrogator() 
{
}

//////////////////////////////////////////////////////////////////////////

IFF_Layer3Interrogator::IFF_Layer3Interrogator( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

IFF_Layer3Interrogator::IFF_Layer3Interrogator( const SimulationIdentifier & ReportingSimulation, const Mode5InterrogatorBasicData & Data,
                                              std::vector<StdVarPtr> & Records ) 
{
	m_RptSim = ReportingSimulation;
	m_BasicData = Data;
	SetDataRecords( Records );
}

//////////////////////////////////////////////////////////////////////////

IFF_Layer3Interrogator::IFF_Layer3Interrogator( const LayerHeader & H, KDataStream & stream ) throw( KException ) :
	IFF_Layer3( H )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

IFF_Layer3Interrogator::~IFF_Layer3Interrogator()
{
}

//////////////////////////////////////////////////////////////////////////

void IFF_Layer3Interrogator::SetBasicData( const Mode5InterrogatorBasicData & BD )
{
	m_BasicData = BD;
}

//////////////////////////////////////////////////////////////////////////
const Mode5InterrogatorBasicData & IFF_Layer3Interrogator::GetBasicData() const
{
	return m_BasicData;
}

//////////////////////////////////////////////////////////////////////////

Mode5InterrogatorBasicData & IFF_Layer3Interrogator::GetBasicDatan()
{
	return m_BasicData;
}

//////////////////////////////////////////////////////////////////////////

KString IFF_Layer3Interrogator::GetAsString() const
{
    KStringStream ss;

    ss << "IFF Layer 3 Interrogator\n"
		<< LayerHeader::GetAsString()
		<< "Reporting Simulation: " << m_RptSim.GetAsString()
		<< "Basic Data: "           << m_BasicData.GetAsString() 
		<< "Num IFF Records: "      << m_ui16NumIffRecs 
		<< "\nIFF Records:\n";

    vector<KDIS::DATA_TYPE::StdVarPtr>::const_iterator citr = m_vStdVarRecs.begin();
    vector<KDIS::DATA_TYPE::StdVarPtr>::const_iterator citrEnd = m_vStdVarRecs.end();
    for( ; citr != citrEnd; ++citr )
    {
		ss << ( *citr )->GetAsString();
    }	

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void IFF_Layer3Interrogator::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( stream.GetBufferSize() < IFF_LAYER3_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vStdVarRecs.clear();

	if( !ignoreHeader )
	{
		LayerHeader::Decode( stream );
	}

	stream >> KDIS_STREAM m_RptSim
		   >> KDIS_STREAM m_BasicData
		   >> m_ui16Padding
		   >> m_ui16NumIffRecs;

	// Use the factory decode function for each standard variable
    for( KUINT16 i = 0; i < m_ui16NumIffRecs; ++i )
    {
        m_vStdVarRecs.push_back( StandardVariable::FactoryDecodeStandardVariable( stream ) );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream IFF_Layer3Interrogator::Encode() const
{
    KDataStream stream;

    IFF_Layer3Interrogator::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void IFF_Layer3Interrogator::Encode( KDataStream & stream ) const
{
	LayerHeader::Encode( stream );

    stream << KDIS_STREAM m_RptSim
	       << KDIS_STREAM m_BasicData
		   << m_ui16Padding
		   << m_ui16NumIffRecs;

    vector<KDIS::DATA_TYPE::StdVarPtr>::const_iterator citr = m_vStdVarRecs.begin();
    vector<KDIS::DATA_TYPE::StdVarPtr>::const_iterator citrEnd = m_vStdVarRecs.end();
    for( ; citr != citrEnd; ++citr )
    {
        ( *citr )->Encode( stream );
    }	
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_Layer3Interrogator::operator == ( const IFF_Layer3Interrogator & Value ) const
{
    if( IFF_Layer3::operator !=( Value ) )          return false;    
    if( m_BasicData          != Value.m_BasicData ) return false; 
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_Layer3Interrogator::operator != ( const IFF_Layer3Interrogator & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
