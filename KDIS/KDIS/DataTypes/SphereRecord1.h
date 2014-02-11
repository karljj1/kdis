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

/********************************************************************
    class:      SphereRecord1
    created:    18/08/2009
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

    SphereRecord1();

    SphereRecord1( KDataStream & stream ) throw( KException );

    SphereRecord1( KUINT8 Index, const WorldCoordinates & CentroidLocation, KFLOAT32 Radius  );

    virtual ~SphereRecord1();

    KBOOL operator == ( const SphereRecord1 & Value )const;
    KBOOL operator != ( const SphereRecord1 & Value )const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
