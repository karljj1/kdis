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
    class:      LineRecord2
    created:    17:08:2009
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

    LineRecord2( void );

    LineRecord2( KDataStream & stream ) throw( KException );

    LineRecord2( KUINT8 Index, const WorldCoordinates & StartLoc, const WorldCoordinates & EndLoc,
                 const Vector & StartVel, const Vector & EndVel );

    virtual ~LineRecord2( void );

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS
