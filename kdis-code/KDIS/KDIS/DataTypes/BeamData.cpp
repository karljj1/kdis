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

#include "./BeamData.h"

using namespace KDIS;
using namespace DATA_TYPE;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

BeamData::BeamData( void ) :
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

BeamData::~BeamData( void )
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

