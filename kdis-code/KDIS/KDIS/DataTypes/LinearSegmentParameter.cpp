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

#include "./LinearSegmentParameter.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

LinearSegmentParameter::LinearSegmentParameter( void ) :
    m_ui8SegNum( 0 ),
    m_ui16Length( 0 ),
    m_ui16Width( 0 ),
    m_ui16Height( 0 ),
    m_ui16Depth( 0 ),
    m_ui32Padding( 0 )
{
    m_ModificationUnion.m_ui8Modifications = 0;
}

//////////////////////////////////////////////////////////////////////////

LinearSegmentParameter::LinearSegmentParameter( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

LinearSegmentParameter::LinearSegmentParameter( KUINT8 SegNum, KUINT8 Mod, const LinearObjectAppearance & A,
        const WorldCoordinates & Loc, const EulerAngles & Ori,
        KUINT16 Length, KUINT16 Width, KUINT16 Height, KUINT16 Depth ) :
    m_ui8SegNum( SegNum ),
    m_ObjApr( A ),
    m_Loc( Loc ),
    m_Ori( Ori ),
    m_ui16Length( Length ),
    m_ui16Width( Width ),
    m_ui16Height( Height ),
    m_ui16Depth( Depth ),
    m_ui32Padding( 0 )
{
    m_ModificationUnion.m_ui8Modifications = Mod;
}

//////////////////////////////////////////////////////////////////////////

LinearSegmentParameter::~LinearSegmentParameter( void )
{
}

//////////////////////////////////////////////////////////////////////////

void LinearSegmentParameter::SetSegmentNumber( KUINT8 N )
{
    m_ui8SegNum = N;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 LinearSegmentParameter::GetSegmentNumber() const
{
    return m_ui8SegNum;
}

//////////////////////////////////////////////////////////////////////////

void LinearSegmentParameter::SetModification( KUINT8 M )
{
    m_ModificationUnion.m_ui8Modifications = M;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 LinearSegmentParameter::GetModification() const
{
    return m_ModificationUnion.m_ui8Modifications;
}

//////////////////////////////////////////////////////////////////////////

void LinearSegmentParameter::SetModificationLocation( KBOOL M /*= true*/ )
{
    m_ModificationUnion.m_ui8LocBit = M;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LinearSegmentParameter::IsModificationLocation() const
{
    return m_ModificationUnion.m_ui8LocBit;
}

//////////////////////////////////////////////////////////////////////////

void LinearSegmentParameter::SetModificationOrientation( KBOOL M /*= true*/ )
{
    m_ModificationUnion.m_ui8OriBit = M;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LinearSegmentParameter::IsModificationOrientation() const
{
    return m_ModificationUnion.m_ui8OriBit;
}

//////////////////////////////////////////////////////////////////////////

void LinearSegmentParameter::SetLinearObjectAppearance( const LinearObjectAppearance & L )
{
    m_ObjApr = L;
}

//////////////////////////////////////////////////////////////////////////

const LinearObjectAppearance & LinearSegmentParameter::GetLinearObjectAppearance() const
{
    return m_ObjApr;
}

//////////////////////////////////////////////////////////////////////////

LinearObjectAppearance & LinearSegmentParameter::GetLinearObjectAppearance()
{
    return m_ObjApr;
}

//////////////////////////////////////////////////////////////////////////

void LinearSegmentParameter::SetLocation( const WorldCoordinates & L )
{
    m_Loc = L;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & LinearSegmentParameter::GetLocation() const
{
    return m_Loc;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & LinearSegmentParameter::GetLocation()
{
    return m_Loc;
}

//////////////////////////////////////////////////////////////////////////

void LinearSegmentParameter::SetOrientation( const EulerAngles & O )
{
    m_Ori = O;
}

//////////////////////////////////////////////////////////////////////////

const EulerAngles & LinearSegmentParameter::GetOrientation() const
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

EulerAngles & LinearSegmentParameter::GetOrientation()
{
    return m_Ori;
}

//////////////////////////////////////////////////////////////////////////

void LinearSegmentParameter::SetLength( KUINT16 L )
{
    m_ui16Length = L;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 LinearSegmentParameter::GetLength() const
{
    return m_ui16Length;
}

//////////////////////////////////////////////////////////////////////////

void LinearSegmentParameter::SetWidth( KUINT16 W )
{
    m_ui16Width = W;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 LinearSegmentParameter::GetWidth() const
{
    return m_ui16Width;
}

//////////////////////////////////////////////////////////////////////////

void LinearSegmentParameter::SetHeight( KUINT16 H )
{
    m_ui16Height = H;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 LinearSegmentParameter::GetHeight() const
{
    return m_ui16Height;
}

//////////////////////////////////////////////////////////////////////////

void LinearSegmentParameter::SetDepth( KUINT16 D )
{
    m_ui16Depth = D;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 LinearSegmentParameter::GetDepth() const
{
    return m_ui16Depth;
}

//////////////////////////////////////////////////////////////////////////

KString LinearSegmentParameter::GetAsString() const
{
    KStringStream ss;

    ss << "LinearSegmentParameter:\n"
       << "\tSegment Number:  " << ( KUINT16 )m_ui8SegNum                     << "\n"
       << "\tModification:\n"
       << "\t\tLocation:      " << ( KUINT16 )m_ModificationUnion.m_ui8LocBit << "\n"
       << "\t\tOrientation:   " << ( KUINT16 )m_ModificationUnion.m_ui8OriBit << "\n"
       << IndentString( m_ObjApr.GetAsString(), 1 )
       << "\tLocation:		  " << m_Loc.GetAsString()
       << "\tOrientation:     " << m_Ori.GetAsString()
       << "\tLength:		  " << m_ui16Length                                 << "\n"
       << "\tWidth:			  " << m_ui16Width                                  << "\n"
       << "\tHeight:		  " << m_ui16Height                                 << "\n"
       << "\tDepth:			  " << m_ui16Depth                                  << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void LinearSegmentParameter::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < LINEAR_SEGMENT_PARAMETER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8SegNum
           >> m_ModificationUnion.m_ui8Modifications
           >> KDIS_STREAM m_ObjApr
           >> KDIS_STREAM m_Loc
           >> KDIS_STREAM m_Ori
           >> m_ui16Length
           >> m_ui16Width
           >> m_ui16Height
           >> m_ui16Depth
           >> m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream LinearSegmentParameter::Encode() const
{
    KDataStream stream;

    LinearSegmentParameter::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void LinearSegmentParameter::Encode( KDataStream & stream ) const
{
    stream << m_ui8SegNum
           << m_ModificationUnion.m_ui8Modifications
           << KDIS_STREAM m_ObjApr
           << KDIS_STREAM m_Loc
           << KDIS_STREAM m_Ori
           << m_ui16Length
           << m_ui16Width
           << m_ui16Height
           << m_ui16Depth
           << m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LinearSegmentParameter::operator == ( const LinearSegmentParameter & Value ) const
{
    if( m_ui8SegNum                            != Value.m_ui8SegNum )                            return false;
    if( m_ModificationUnion.m_ui8Modifications != Value.m_ModificationUnion.m_ui8Modifications ) return false;
    if( m_ObjApr                               != Value.m_ObjApr )                               return false;
    if( m_Loc                                  != Value.m_Loc )                                  return false;
    if( m_Ori                                  != Value.m_Ori )                                  return false;
    if( m_ui16Length                           != Value.m_ui16Length )                           return false;
    if( m_ui16Width                            != Value.m_ui16Width )                            return false;
    if( m_ui16Height                           != Value.m_ui16Height )                           return false;
    if( m_ui16Depth                            != Value.m_ui16Depth )                            return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL LinearSegmentParameter::operator != ( const LinearSegmentParameter & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
