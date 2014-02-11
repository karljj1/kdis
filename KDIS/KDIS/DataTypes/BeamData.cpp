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

#include "./BeamData.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

BeamData::BeamData() :
    m_f32AziCtr( 0 ),
    m_f32AziSwp( 0 ),
    m_f32EleCtr( 0 ),
    m_f32EleSwp( 0 ),
    m_f32SwpSyn( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

BeamData::BeamData( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

BeamData::BeamData( KFLOAT32 AziCtr, KFLOAT32 AziSwp, KFLOAT32 EleCtr,
                    KFLOAT32 EleSwp, KFLOAT32 SwpSyn ) :
    m_f32AziCtr( AziCtr ),
    m_f32AziSwp( AziSwp ),
    m_f32EleCtr( EleCtr ),
    m_f32EleSwp( EleSwp ),
    m_f32SwpSyn( SwpSyn )
{
}

//////////////////////////////////////////////////////////////////////////

BeamData::~BeamData()
{
}

//////////////////////////////////////////////////////////////////////////

void BeamData::SetAzimuthCenter( KFLOAT32 AC )
{
    m_f32AziCtr = AC;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 BeamData::GetAzimuthCenter()const
{
    return m_f32AziCtr;
}

//////////////////////////////////////////////////////////////////////////

void BeamData::SetAzimuthSweep( KFLOAT32 AS )
{
    m_f32AziSwp= AS;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 BeamData::GetAzimuthSweep()const
{
    return m_f32AziSwp;
}

//////////////////////////////////////////////////////////////////////////

void BeamData::SetElevationCenter( KFLOAT32 EC )
{
    m_f32EleCtr = EC;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 BeamData::GetElevationCenter()const
{
    return m_f32EleCtr;
}

//////////////////////////////////////////////////////////////////////////

void BeamData::SetElevationSweep( KFLOAT32 ES )
{
    m_f32EleSwp = ES;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 BeamData::GetElevationSweep()const
{
    return m_f32EleSwp;
}

//////////////////////////////////////////////////////////////////////////

void BeamData::SetBeamSweepSync( KFLOAT32 BSS )
{
    m_f32SwpSyn = BSS;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 BeamData::GetBeamSweepSync()const
{
    return m_f32SwpSyn;
}

//////////////////////////////////////////////////////////////////////////

KString BeamData::GetAsString() const
{
    KStringStream ss;

    ss << "BeamData:"
       << "\n\tAzimuth Center:    " << m_f32AziCtr
       << "\n\tAzimuth Sweep:     " << m_f32AziSwp
       << "\n\tElevation Center:  " << m_f32EleCtr
       << "\n\tElevation Sweep:   " << m_f32EleSwp
       << "\n\tBeam Sweep Sync:   " << m_f32SwpSyn
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void BeamData::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < BEAM_DATA_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_f32AziCtr
           >> m_f32AziSwp
           >> m_f32EleCtr
           >> m_f32EleSwp
           >> m_f32SwpSyn;
}

//////////////////////////////////////////////////////////////////////////

KDataStream BeamData::Encode() const
{
    KDataStream stream;

    BeamData::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void BeamData::Encode( KDataStream & stream ) const
{
    stream << m_f32AziCtr
           << m_f32AziSwp
           << m_f32EleCtr
           << m_f32EleSwp
           << m_f32SwpSyn;
}

//////////////////////////////////////////////////////////////////////////

KBOOL BeamData::operator == ( const BeamData & Value ) const
{
    if( m_f32AziCtr != Value.m_f32AziCtr ) return false;
    if( m_f32AziSwp != Value.m_f32AziSwp ) return false;
    if( m_f32EleCtr != Value.m_f32EleCtr ) return false;
    if( m_f32SwpSyn != Value.m_f32SwpSyn ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL BeamData::operator != ( const BeamData & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

