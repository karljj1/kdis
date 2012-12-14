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

#include "./SphereRecord1.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

SphereRecord1::SphereRecord1( void )
{
    m_ui32EnvRecTyp = SphereRecord1Type;
}

//////////////////////////////////////////////////////////////////////////

SphereRecord1::SphereRecord1( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

SphereRecord1::SphereRecord1( KUINT8 Index, const WorldCoordinates & CentroidLocation, KFLOAT32 Radius  ) :
    BoundingSphereRecord( Index, CentroidLocation, Radius )
{
    m_ui32EnvRecTyp = SphereRecord1Type;
}

//////////////////////////////////////////////////////////////////////////

SphereRecord1::~SphereRecord1( void )
{
}

//////////////////////////////////////////////////////////////////////////

KBOOL SphereRecord1::operator == ( const SphereRecord1 & Value )const
{
    if( BoundingSphereRecord::operator !=( Value ) ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SphereRecord1::operator != ( const SphereRecord1 & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
