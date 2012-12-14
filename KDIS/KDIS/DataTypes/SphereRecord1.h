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

/********************************************************************
    class:      SphereRecord1
    created:    18:08:2009
    author:     Karl Jones

    purpose:    A geometry record representing a sphere.
    size:       320 bits / 40 octets
*********************************************************************/

#pragma once

#include "./BoundingSphereRecord.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT SphereRecord1 : public BoundingSphereRecord
{
public:

    SphereRecord1( void );

    SphereRecord1( KDataStream & stream ) throw( KException );

    SphereRecord1( KUINT8 Index, const WorldCoordinates & CentroidLocation, KFLOAT32 Radius  );

    virtual ~SphereRecord1( void );

    KBOOL operator == ( const SphereRecord1 & Value )const;
    KBOOL operator != ( const SphereRecord1 & Value )const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
