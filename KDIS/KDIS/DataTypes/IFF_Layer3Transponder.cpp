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

#include "./IFF_Layer3Transponder.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

IFF_Layer3Transponder::IFF_Layer3Transponder() :
	m_ui16Padding( 0 ),
	m_ui16NumIffRecs( 0 )	
{
	m_ui8LayerNumber = 2;
	m_ui16LayerLength = IFF_LAYER3_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IFF_Layer3Transponder::IFF_Layer3Transponder( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

IFF_Layer3Transponder::IFF_Layer3Transponder( const LayerHeader & H, KDataStream & stream ) throw( KException ) :
	LayerHeader( H )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

IFF_Layer3Transponder::~IFF_Layer3Transponder()
{
}

//////////////////////////////////////////////////////////////////////////

void IFF_Layer3Transponder::SetReportingSimulation( const SimulationIdentifier & RS )
{
	m_RptSim = RS;
}

//////////////////////////////////////////////////////////////////////////

const SimulationIdentifier & IFF_Layer3Transponder::GetReportingSimulation() const
{
	return m_RptSim;
}

//////////////////////////////////////////////////////////////////////////

SimulationIdentifier & IFF_Layer3Transponder::GetReportingSimulation()
{
	return m_RptSim;
}

//////////////////////////////////////////////////////////////////////////

void IFF_Layer3Transponder::AddDataRecord( KDIS::DATA_TYPE::StdVarPtr DR )
{
	m_vStdVarRecs.push_back( DR );
	++m_ui16NumIffRecs;
    m_ui16LayerLength += DR->GetRecordLength();
}

//////////////////////////////////////////////////////////////////////////

void IFF_Layer3Transponder::SetDataRecords( const std::vector<KDIS::DATA_TYPE::StdVarPtr> & DRS )
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

const std::vector<KDIS::DATA_TYPE::StdVarPtr> & IFF_Layer3Transponder::GetDataRecords() const
{
	return m_vStdVarRecs;
}

//////////////////////////////////////////////////////////////////////////

void IFF_Layer3Transponder::ClearDataRecords()
{
	// Reset the length.
	m_ui16LayerLength = IFF_LAYER3_SIZE;

    m_vStdVarRecs.clear();
    m_ui16NumIffRecs = 0;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 IFF_Layer3Transponder::GetNumberDataRecords() const
{
	return m_ui16NumIffRecs;
}

//////////////////////////////////////////////////////////////////////////

KString IFF_Layer3Transponder::GetAsString() const
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

void IFF_Layer3Transponder::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( stream.GetBufferSize() < IFF_LAYER3_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vStdVarRecs.clear();

	if( !ignoreHeader )
	{
		LayerHeader::Decode( stream );
	}



	    // Use the factory decode function for each standard variable
    /*for( KUINT16 i = 0; i < m_ui16NumStdVarRec; ++i )
    {
        m_vStdVarRecs.push_back( StandardVariable::FactoryDecodeStandardVariable( stream ) );
    }
*/

    //stream >> KDIS_STREAM m_RptSim
	//	   >> m_ui32Padding              // Mode 5 Interrogator Basic Data field 0
   //        >> KDIS_STREAM m_MsgFormats   // Mode 5 Interrogator Basic Data field 1
	//	   >> m_ui64Padding;             // Mode 5 Interrogator Basic Data field 2

 //   for( KUINT8 i = 0; i < m_SOD.GetNumberOfFundamentalParamSets(); ++i )
 //   {
 //       m_vFPD.push_back( IFF_ATC_NAVAIDS_FundamentalParameterData( stream ) );
 //   }
}

//////////////////////////////////////////////////////////////////////////

KDataStream IFF_Layer3Transponder::Encode() const
{
    KDataStream stream;

    IFF_Layer3Transponder::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void IFF_Layer3Transponder::Encode( KDataStream & stream ) const
{
	LayerHeader::Encode( stream );

   // stream << KDIS_STREAM m_RptSim
	//	   << m_ui32Padding              // Mode 5 Interrogator Basic Data field 0
   //        << KDIS_STREAM m_MsgFormats   // Mode 5 Interrogator Basic Data field 1
	//	   << m_ui64Padding;             // Mode 5 Interrogator Basic Data field 2   

    //vector<IFF_ATC_NAVAIDS_FundamentalParameterData>::const_iterator citr = m_vFPD.begin();
    //vector<IFF_ATC_NAVAIDS_FundamentalParameterData>::const_iterator citrEnd = m_vFPD.end();
    //for( ; citr != citrEnd; ++citr )
    //{
    //    citr->Encode( stream );
    //}
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_Layer3Transponder::operator == ( const IFF_Layer3Transponder & Value ) const
{
 //   if( LayerHeader::operator !=( Value ) )     return false;    
 //   if( m_BmDt                != Value.m_BmDt ) return false;
 //   if( m_SOD                 != Value.m_SOD )  return false;
	//if( m_vFPD                != Value.m_vFPD ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_Layer3Transponder::operator != ( const IFF_Layer3Transponder & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
