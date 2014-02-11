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
    class:      LineRecord2
    created:    17/08/2009
    author:     Karl Jones

    purpose:    A geometry record representing a moving line.
    size:       640 bits / 80 octets
*********************************************************************/

#pragma once

#include "./LineRecord1.h"
#include "./Vector.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT LineRecord2 : public LineRecord1
{
protected:

    Vector m_StartVel;

    Vector m_EndVel;

public:

    static const KUINT16 LINE_RECORD_2_SIZE = 80;

    LineRecord2();

    LineRecord2( KDataStream & stream ) throw( KException );

    LineRecord2( KUINT8 Index, const WorldCoordinates & StartLoc, const WorldCoordinates & EndLoc,
                 const Vector & StartVel, const Vector & EndVel );

    virtual ~LineRecord2();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LineRecord2::SetVelocity
    // Description: Specifies the start and end velocity of the line.
    //              Represented as a Linear Velocity Vector.
    // Parameter:   const Vector & Start
    // Parameter:   const Vector & End
    //************************************
    void SetVelocity( const Vector & Start, const Vector & End );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LineRecord2::SetStartVelocity
    //              KDIS::DATA_TYPE::LineRecord2::GetStartVelocity
    // Description: Specifies the start velocity of the line.
    //              Represented as a Linear Velocity Vector.
    // Parameter:   const Vector & V, void
    //************************************
    void SetStartVelocity( const Vector & V);
    const Vector & GetStartVelocity() const;
    Vector & GetStartVelocity();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LineRecord2::SetEndVelocity
    //              KDIS::DATA_TYPE::LineRecord2::GetEndVelocity
    // Description: Specifies the end velocity of the line.
    //              Represented as a Linear Velocity Vector.
    // Parameter:   const Vector & V, void
    //************************************
    void SetEndVelocity( const Vector & V );
    const Vector & GetEndVelocity() const;
    Vector & GetEndVelocity();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LineRecord2::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LineRecord2::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LineRecord2::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const LineRecord2 & Value )const;
    KBOOL operator != ( const LineRecord2 & Value )const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
