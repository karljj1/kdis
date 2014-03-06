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

#include "./EnhancedMode1Code.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

EnhancedMode1Code::EnhancedMode1Code() 
{
	m_CodeUnion.m_ui16Code = 0;
}

//////////////////////////////////////////////////////////////////////////

EnhancedMode1Code::EnhancedMode1Code( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

EnhancedMode1Code::~EnhancedMode1Code()
{
}

//////////////////////////////////////////////////////////////////////////








//////////////////////////////////////////////////////////////////////////

KString EnhancedMode1Code::GetAsString() const
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

void EnhancedMode1Code::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ENHANCED_MODE_1_CODE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

 //   m_vFPD.clear();


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

KDataStream EnhancedMode1Code::Encode() const
{
    KDataStream stream;

    EnhancedMode1Code::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void EnhancedMode1Code::Encode( KDataStream & stream ) const
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

KBOOL EnhancedMode1Code::operator == ( const EnhancedMode1Code & Value ) const
{
 //   if( LayerHeader::operator !=( Value ) )     return false;    
 //   if( m_BmDt                != Value.m_BmDt ) return false;
 //   if( m_SOD                 != Value.m_SOD )  return false;
	//if( m_vFPD                != Value.m_vFPD ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EnhancedMode1Code::operator != ( const EnhancedMode1Code & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
