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
    class:      RelativeWorldCoordinates
    created:    02/07/2010
    author:     Karl Jones

    purpose:    Location of the origin of the LE’s coordinate system.
    size:       64 bits / 8 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./KFIXED.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT RelativeWorldCoordinates: public DataTypeBase
{
protected:

    KUINT16 m_ui16RefPnt;

    KFIXED16_3 m_DelX;

    KFIXED16_3 m_DelY;

    KFIXED16_3 m_DelZ;

public:

    static const KUINT16 RELATVE_WORLD_COORDINATES_SIZE = 8;

    RelativeWorldCoordinates();

    RelativeWorldCoordinates( KUINT16 RefPnt, KFIXED16_3 DelX, KFIXED16_3 DelY, KFIXED16_3 DelZ );

    RelativeWorldCoordinates( KDataStream & stream ) throw( KException );

    virtual ~RelativeWorldCoordinates();

    //************************************
    // FullName:    KDIS::DATA_TYPE::RelativeWorldCoordinates::SetReferencePoint
    //              KDIS::DATA_TYPE::RelativeWorldCoordinates::GetReferencePoint
    // Description: Identifies the number of the reference point against which
    //              e Delta-X, Delta-Y, and Delta-Z distances are calculated.
    // Parameter:   KUINT16 RP
    //************************************
    void SetReferencePoint( KUINT16 RP );
    KUINT16 GetReferencePoint() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RelativeWorldCoordinates::SetDelta
    //              KDIS::DATA_TYPE::RelativeWorldCoordinates::GetDelta
    // Description: The difference between LE’s X, Y and Z direction coordinate and the
    //              X, Y and Z direction coordinate of the reference point.
    // Parameter:   KFIXED16_3
    //************************************
    void SetDeltaX( KFIXED16_3 X );
    KFIXED16_3 GetDeltaX() const;
    void SetDeltaY( KFIXED16_3 Y );
    KFIXED16_3 GetDeltaY() const;
    void SetDeltaZ( KFIXED16_3 X );
    KFIXED16_3 GetDeltaZ() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RelativeWorldCoordinates::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::RelativeWorldCoordinates::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::RelativeWorldCoordinates::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const RelativeWorldCoordinates  & Value ) const;
    KBOOL operator != ( const RelativeWorldCoordinates  & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

