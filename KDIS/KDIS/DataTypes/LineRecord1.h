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
    class:      LineRecord1
    created:    17:08:2009
    author:     Karl Jones

    purpose:    A geometry record representing a line.
    size:       448 bits / 56 octets
*********************************************************************/

#pragma once

#include "./EnvironmentRecord.h"
#include "./WorldCoordinates.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT LineRecord1 : public EnvironmentRecord
{
protected:

    WorldCoordinates m_StartLocation;

    WorldCoordinates m_EndLocation;

public:

    static const KUINT16 LINE_RECORD_1_SIZE = 56;

    LineRecord1( void );

    LineRecord1( KDataStream & stream ) throw( KException );

    LineRecord1( KUINT8 Index, const WorldCoordinates & Start, const WorldCoordinates & End  );

    virtual ~LineRecord1( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LineRecord1::SetLocation
    // Description: Specifies the start and end location of the line.
    // Parameter:   const WorldCoordinates & Start
    // Parameter:   const WorldCoordinates & End
    //************************************
    void SetLocation( const WorldCoordinates & Start, const WorldCoordinates & End );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LineRecord1::SetStartLocation
    //              KDIS::DATA_TYPE::LineRecord1::GetStartLocation
    // Description: Specifies the start location of the line.
    // Parameter:   const WorldCoordinates & L, void
    //************************************
    void SetStartLocation( const WorldCoordinates & L );
    const WorldCoordinates & GetStartLocation() const;
    WorldCoordinates & GetStartLocation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LineRecord1::SetEndLocation
    //              KDIS::DATA_TYPE::LineRecord1::GetEndLocation
    // Description: Specifies the end location of the line.
    // Parameter:   const WorldCoordinates & L, void
    //************************************
    void SetEndLocation( const WorldCoordinates & L );
    const WorldCoordinates & GetEndLocation() const;
    WorldCoordinates & GetEndLocation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LineRecord1::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LineRecord1::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LineRecord1::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const LineRecord1 & Value )const;
    KBOOL operator != ( const LineRecord1 & Value )const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
