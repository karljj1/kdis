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

#include "./IFF_Layer2.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

IFF_Layer2::IFF_Layer2()     
{
	m_ui8LayerNumber = 2;
	m_ui16LayerLength = IFF_LAYER2_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IFF_Layer2::IFF_Layer2( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

IFF_Layer2::IFF_Layer2( const LayerHeader & H, KDataStream & stream ) throw( KException ) :
	LayerHeader( H )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

IFF_Layer2::IFF_Layer2( const BeamData & BD, const SecondaryOperationalData & SOD, const vector<IFF_ATC_NAVAIDS_FundamentalParameterData> & FPD ) :
    m_BmDt( BD ),
    m_SOD( SOD ),
    m_vFPD( FPD )
{
	m_ui8LayerNumber = 2;
	m_ui16LayerLength = IFF_LAYER2_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IFF_Layer2::~IFF_Layer2()
{
}

//////////////////////////////////////////////////////////////////////////

void IFF_Layer2::SetBeamData( const BeamData & BD )
{
    m_BmDt = BD;
}

//////////////////////////////////////////////////////////////////////////

const BeamData & IFF_Layer2::GetBeamData() const
{
    return m_BmDt;
}

//////////////////////////////////////////////////////////////////////////

BeamData & IFF_Layer2::GetBeamData()
{
    return m_BmDt;
}

//////////////////////////////////////////////////////////////////////////

void IFF_Layer2::SetSecondaryOperationalData( const SecondaryOperationalData & SOD )
{
    m_SOD = SOD;
}

//////////////////////////////////////////////////////////////////////////

const SecondaryOperationalData & IFF_Layer2::GetSecondaryOperationalData() const
{
    return m_SOD;
}

//////////////////////////////////////////////////////////////////////////

SecondaryOperationalData & IFF_Layer2::GetSecondaryOperationalData()
{
    return m_SOD;
}

//////////////////////////////////////////////////////////////////////////

void IFF_Layer2::AddFundamentalParameterData( const IFF_ATC_NAVAIDS_FundamentalParameterData & FPD )
{
    m_vFPD.push_back( FPD );
    m_ui16LayerLength += IFF_ATC_NAVAIDS_FundamentalParameterData::IFF_ATC_NAVAIDS_FUNDAMENTAL_PARAMETER_SIZE;
    m_SOD.SetNumberOfFundamentalParamSets( m_vFPD.size() );
}

//////////////////////////////////////////////////////////////////////////

void IFF_Layer2::SetFundamentalParameterData( const vector<IFF_ATC_NAVAIDS_FundamentalParameterData> & FPD )
{
    m_vFPD = FPD;
    m_ui16LayerLength = IFF_LAYER2_SIZE + ( m_vFPD.size() * IFF_ATC_NAVAIDS_FundamentalParameterData::IFF_ATC_NAVAIDS_FUNDAMENTAL_PARAMETER_SIZE );
    m_SOD.SetNumberOfFundamentalParamSets( m_vFPD.size() );
}

//////////////////////////////////////////////////////////////////////////

const vector<IFF_ATC_NAVAIDS_FundamentalParameterData> & IFF_Layer2::GetFundamentalParameterData() const
{
    return m_vFPD;
}

//////////////////////////////////////////////////////////////////////////

KString IFF_Layer2::GetAsString() const
{
    KStringStream ss;

    ss << "IFF Layer 2\n"
       << IndentString( m_BmDt.GetAsString(), 1 )
       << IndentString( m_SOD.GetAsString(), 1 );

    vector<IFF_ATC_NAVAIDS_FundamentalParameterData>::const_iterator citr = m_vFPD.begin();
    vector<IFF_ATC_NAVAIDS_FundamentalParameterData>::const_iterator citrEnd = m_vFPD.end();
    for( ; citr != citrEnd; ++citr )
    {
        ss << citr->GetAsString();
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void IFF_Layer2::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( stream.GetBufferSize() < IFF_LAYER2_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vFPD.clear();

	if( !ignoreHeader )
	{
		LayerHeader::Decode( stream );
	}

    stream >> KDIS_STREAM m_BmDt
           >> KDIS_STREAM m_SOD;

    for( KUINT8 i = 0; i < m_SOD.GetNumberOfFundamentalParamSets(); ++i )
    {
        m_vFPD.push_back( IFF_ATC_NAVAIDS_FundamentalParameterData( stream ) );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream IFF_Layer2::Encode() const
{
    KDataStream stream;

    IFF_Layer2::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void IFF_Layer2::Encode( KDataStream & stream ) const
{
	LayerHeader::Encode( stream );

    stream << KDIS_STREAM m_BmDt
           << KDIS_STREAM m_SOD;

    vector<IFF_ATC_NAVAIDS_FundamentalParameterData>::const_iterator citr = m_vFPD.begin();
    vector<IFF_ATC_NAVAIDS_FundamentalParameterData>::const_iterator citrEnd = m_vFPD.end();
    for( ; citr != citrEnd; ++citr )
    {
        citr->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_Layer2::operator == ( const IFF_Layer2 & Value ) const
{
    if( LayerHeader::operator !=( Value ) )     return false;    
    if( m_BmDt                != Value.m_BmDt ) return false;
    if( m_SOD                 != Value.m_SOD )  return false;
	if( m_vFPD                != Value.m_vFPD ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_Layer2::operator != ( const IFF_Layer2 & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
