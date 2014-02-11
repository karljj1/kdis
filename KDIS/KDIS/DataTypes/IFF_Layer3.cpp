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

#include "./IFF_Layer3.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

IFF_Layer3::IFF_Layer3() :
	m_ui32Padding( 0 ),
	m_ui64Padding( 0 ), 
	m_ui16NumIffRecs( 0 )
{
	m_ui8LayerNumber = 2;
	m_ui16LayerLength = IFF_LAYER3_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IFF_Layer3::IFF_Layer3( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

IFF_Layer3::IFF_Layer3( const LayerHeader & H, KDataStream & stream ) throw( KException ) :
	LayerHeader( H )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

IFF_Layer3::~IFF_Layer3()
{
}

//////////////////////////////////////////////////////////////////////////

void IFF_Layer3::SetReportingSimulation( const SimulationIdentifier & RS )
{
	m_RptSim = RS;
}

//////////////////////////////////////////////////////////////////////////

const SimulationIdentifier & IFF_Layer3::GetReportingSimulation() const
{
	return m_RptSim;
}

//////////////////////////////////////////////////////////////////////////

SimulationIdentifier & IFF_Layer3::GetReportingSimulation()
{
	return m_RptSim;
}

//////////////////////////////////////////////////////////////////////////

void IFF_Layer3::SetMode5MessageFormats( const Mode5MessageFormats & MF )
{
	m_MsgFormats = MF;
}

//////////////////////////////////////////////////////////////////////////

const Mode5MessageFormats & IFF_Layer3::GetMode5MessageFormats() const
{
	return m_MsgFormats;
}

//////////////////////////////////////////////////////////////////////////

Mode5MessageFormats & IFF_Layer3::GetMode5MessageFormats()
{
	return m_MsgFormats;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 IFF_Layer3::GetNumberIFFDataRecords() const
{
	return m_ui16NumIffRecs;
}

//////////////////////////////////////////////////////////////////////////

KString IFF_Layer3::GetAsString() const
{
    KStringStream ss;

    //ss << "IFF Layer 2\n"
    //   << IndentString( m_BmDt.GetAsString(), 1 )
    //   << IndentString( m_SOD.GetAsString(), 1 );

    //vector<IFF_ATC_NAVAIDS_FundamentalParameterData>::const_iterator citr = m_vFPD.begin();
    //vector<IFF_ATC_NAVAIDS_FundamentalParameterData>::const_iterator citrEnd = m_vFPD.end();
    //for( ; citr != citrEnd; ++citr )
    //{
    //    ss << citr->GetAsString();
    //}

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void IFF_Layer3::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( stream.GetBufferSize() < IFF_LAYER3_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

 //   m_vFPD.clear();

	if( !ignoreHeader )
	{
		LayerHeader::Decode( stream );
	}

    stream >> KDIS_STREAM m_RptSim
		   >> m_ui32Padding              // Mode 5 Interrogator Basic Data field 0
           >> KDIS_STREAM m_MsgFormats   // Mode 5 Interrogator Basic Data field 1
		   >> m_ui64Padding;             // Mode 5 Interrogator Basic Data field 2

 //   for( KUINT8 i = 0; i < m_SOD.GetNumberOfFundamentalParamSets(); ++i )
 //   {
 //       m_vFPD.push_back( IFF_ATC_NAVAIDS_FundamentalParameterData( stream ) );
 //   }
}

//////////////////////////////////////////////////////////////////////////

KDataStream IFF_Layer3::Encode() const
{
    KDataStream stream;

    IFF_Layer3::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void IFF_Layer3::Encode( KDataStream & stream ) const
{
	LayerHeader::Encode( stream );

    stream << KDIS_STREAM m_RptSim
		   << m_ui32Padding              // Mode 5 Interrogator Basic Data field 0
           << KDIS_STREAM m_MsgFormats   // Mode 5 Interrogator Basic Data field 1
		   << m_ui64Padding;             // Mode 5 Interrogator Basic Data field 2   

    //vector<IFF_ATC_NAVAIDS_FundamentalParameterData>::const_iterator citr = m_vFPD.begin();
    //vector<IFF_ATC_NAVAIDS_FundamentalParameterData>::const_iterator citrEnd = m_vFPD.end();
    //for( ; citr != citrEnd; ++citr )
    //{
    //    citr->Encode( stream );
    //}
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_Layer3::operator == ( const IFF_Layer3 & Value ) const
{
 //   if( LayerHeader::operator !=( Value ) )     return false;    
 //   if( m_BmDt                != Value.m_BmDt ) return false;
 //   if( m_SOD                 != Value.m_SOD )  return false;
	//if( m_vFPD                != Value.m_vFPD ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_Layer3::operator != ( const IFF_Layer3 & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
