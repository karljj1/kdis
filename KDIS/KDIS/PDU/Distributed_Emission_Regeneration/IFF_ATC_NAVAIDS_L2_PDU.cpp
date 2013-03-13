/*********************************************************************
Copyright 2013 KDIS
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

#include "./IFF_ATC_NAVAIDS_L2_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

IFF_ATC_NAVAIDS_L2_PDU::IFF_ATC_NAVAIDS_L2_PDU() :
    m_LyrHdr( 2, 0, IFF_ATC_NAVAIDS_L2_PDU_SIZE - IFF_ATC_NAVAIDS_L1_PDU_SIZE )
{
    m_ui16PDULength = IFF_ATC_NAVAIDS_L2_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IFF_ATC_NAVAIDS_L2_PDU::IFF_ATC_NAVAIDS_L2_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

IFF_ATC_NAVAIDS_L2_PDU::IFF_ATC_NAVAIDS_L2_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	IFF_ATC_NAVAIDS_L1_PDU( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

IFF_ATC_NAVAIDS_L2_PDU::IFF_ATC_NAVAIDS_L2_PDU( const EntityIdentifier & EmittingID, const EntityIdentifier & EventID, const Vector & Location, const SystemIdentifier & ID,
        const FundamentalOperationalData & FOD, const LayerHeader & LH,const BeamData & BD, const SecondaryOperationalData & SOD,
        const vector<IFF_ATC_NAVAIDS_FundamentalParameterData> & FPD ) :
    IFF_ATC_NAVAIDS_L1_PDU( EmittingID, EventID, Location, ID, FOD ),
    m_LyrHdr( LH ),
    m_BmDt( BD ),
    m_SOD( SOD ),
    m_vFPD( FPD )
{
    m_ui16PDULength = IFF_ATC_NAVAIDS_L2_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IFF_ATC_NAVAIDS_L2_PDU::IFF_ATC_NAVAIDS_L2_PDU( const IFF_ATC_NAVAIDS_L1_PDU & PDU, const LayerHeader & LH,const BeamData & BD, const SecondaryOperationalData & SOD,
        const vector<IFF_ATC_NAVAIDS_FundamentalParameterData> & FPD ) :
    m_LyrHdr( LH ),
    m_BmDt( BD ),
    m_SOD( SOD ),
    m_vFPD( FPD )
{
    m_ui16PDULength = IFF_ATC_NAVAIDS_L2_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IFF_ATC_NAVAIDS_L2_PDU::~IFF_ATC_NAVAIDS_L2_PDU()
{
    m_vFPD.clear();
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_L2_PDU::SetLayerHeader( const LayerHeader & LH )
{
    m_LyrHdr = LH;
}

//////////////////////////////////////////////////////////////////////////

const LayerHeader & IFF_ATC_NAVAIDS_L2_PDU::GetLayerHeader() const
{
    return m_LyrHdr;
}

//////////////////////////////////////////////////////////////////////////

LayerHeader & IFF_ATC_NAVAIDS_L2_PDU::GetLayerHeader()
{
    return m_LyrHdr;
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_L2_PDU::SetBeamData( const BeamData & BD )
{
    m_BmDt = BD;
}

//////////////////////////////////////////////////////////////////////////

const BeamData & IFF_ATC_NAVAIDS_L2_PDU::GetBeamData() const
{
    return m_BmDt;
}

//////////////////////////////////////////////////////////////////////////

BeamData & IFF_ATC_NAVAIDS_L2_PDU::GetBeamData()
{
    return m_BmDt;
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_L2_PDU::SetSecondaryOperationalData( const SecondaryOperationalData & SOD )
{
    m_SOD = SOD;
}

//////////////////////////////////////////////////////////////////////////

const SecondaryOperationalData & IFF_ATC_NAVAIDS_L2_PDU::GetSecondaryOperationalData() const
{
    return m_SOD;
}

//////////////////////////////////////////////////////////////////////////

SecondaryOperationalData & IFF_ATC_NAVAIDS_L2_PDU::GetSecondaryOperationalData()
{
    return m_SOD;
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_L2_PDU::AddFundamentalParameterData( const IFF_ATC_NAVAIDS_FundamentalParameterData & FPD )
{
    m_vFPD.push_back( FPD );

    m_ui16PDULength += IFF_ATC_NAVAIDS_FundamentalParameterData::IFF_ATC_NAVAIDS_FUNDAMENTAL_PARAMETER_SIZE;
    m_LyrHdr.SetLayerLength( m_ui16PDULength - IFF_ATC_NAVAIDS_L1_PDU_SIZE );

    m_SOD.SetNumberOfFundamentalParamSets( m_vFPD.size() );
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_L2_PDU::SetFundamentalParameterData( const vector<IFF_ATC_NAVAIDS_FundamentalParameterData> & FPD )
{
    m_vFPD = FPD;

    m_ui16PDULength = IFF_ATC_NAVAIDS_L2_PDU_SIZE + ( m_vFPD.size() * IFF_ATC_NAVAIDS_FundamentalParameterData::IFF_ATC_NAVAIDS_FUNDAMENTAL_PARAMETER_SIZE );
    m_LyrHdr.SetLayerLength( m_ui16PDULength - IFF_ATC_NAVAIDS_L1_PDU_SIZE );

    m_SOD.SetNumberOfFundamentalParamSets( m_vFPD.size() );
}

//////////////////////////////////////////////////////////////////////////

const vector<IFF_ATC_NAVAIDS_FundamentalParameterData> & IFF_ATC_NAVAIDS_L2_PDU::GetFundamentalParameterData() const
{
    return m_vFPD;
}

//////////////////////////////////////////////////////////////////////////

KString IFF_ATC_NAVAIDS_L2_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-IFF/ATC/NAVAIDS Layer 2 PDU-\n"
       << "Emitting Entity ID:\n"
       << IndentString( m_EmittingEntityID.GetAsString(), 1 )
       << "Event ID:\n"
       << IndentString( m_EventID.GetAsString(), 1 )
       << "Location:    " << m_Location.GetAsString()
       << m_SystemID.GetAsString()
       << m_FOD.GetAsString()
       << m_LyrHdr.GetAsString()
       << m_BmDt.GetAsString()
       << m_SOD.GetAsString();

    vector<IFF_ATC_NAVAIDS_FundamentalParameterData>::const_iterator citr = m_vFPD.begin();
    vector<IFF_ATC_NAVAIDS_FundamentalParameterData>::const_iterator citrEnd = m_vFPD.end();

    for( ; citr != citrEnd; ++citr )
    {
        ss << citr->GetAsString();
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_L2_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < IFF_ATC_NAVAIDS_L2_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vFPD.clear();

    IFF_ATC_NAVAIDS_L1_PDU::Decode( stream, ignoreHeader );

    stream >> KDIS_STREAM m_LyrHdr
           >> KDIS_STREAM m_BmDt
           >> KDIS_STREAM m_SOD;

    for( KUINT8 i = 0; i < m_SOD.GetNumberOfFundamentalParamSets(); ++i )
    {
        m_vFPD.push_back( IFF_ATC_NAVAIDS_FundamentalParameterData( stream ) );
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream IFF_ATC_NAVAIDS_L2_PDU::Encode() const
{
    KDataStream stream;

    IFF_ATC_NAVAIDS_L2_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void IFF_ATC_NAVAIDS_L2_PDU::Encode( KDataStream & stream ) const
{
    IFF_ATC_NAVAIDS_L1_PDU::Encode( stream );

    stream << KDIS_STREAM m_LyrHdr
           << KDIS_STREAM m_BmDt
           << KDIS_STREAM m_SOD;

    vector<IFF_ATC_NAVAIDS_FundamentalParameterData>::const_iterator citr = m_vFPD.begin();
    vector<IFF_ATC_NAVAIDS_FundamentalParameterData>::const_iterator citrEnd = m_vFPD.end();

    for( ; citr != citrEnd; ++citr )
    {
        citr->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_ATC_NAVAIDS_L2_PDU::operator == ( const IFF_ATC_NAVAIDS_L2_PDU & Value ) const
{
    if( IFF_ATC_NAVAIDS_L1_PDU::operator  !=( Value ) )       return false;
    if( m_LyrHdr                          != Value.m_LyrHdr ) return false;
    if( m_BmDt                            != Value.m_BmDt )   return false;
    if( m_SOD                             != Value.m_SOD )    return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IFF_ATC_NAVAIDS_L2_PDU::operator != ( const IFF_ATC_NAVAIDS_L2_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
