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
    class:      AntennaLocation
    created:    2008/10/21

    author:     Karl Jones

    purpose:    Specifies location of antennas radiating portion in world
                coordinates and entity coordinates.
    size:       288 bits / 36 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./WorldCoordinates.h"
#include "./Vector.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT AntennaLocation : public DataTypeBase
{
protected:

    WorldCoordinates m_AntennaLocation;

    Vector m_RelativeAntennaLocation;

public:

    static const KUINT16 ANTENNA_LOCATION_SIZE = 36;

    AntennaLocation();

    AntennaLocation( KDataStream & stream )throw( KException );

    AntennaLocation( const WorldCoordinates & Location, const Vector & RelativeLocation );

    virtual ~AntennaLocation();

    //************************************
    // FullName:    KDIS::DataTypes::AntennaLocation::SetAntennaLocation
    //              KDIS::DataTypes::AntennaLocation::GetAntennaLocation
    // Description: Antenna world location
    // Parameter:   const WorldCoordinates & AL
    //************************************
    void SetAntennaLocation( const WorldCoordinates & AL );
    const WorldCoordinates & GetAntennaLocation() const;
    WorldCoordinates & GetAntennaLocation();

    //************************************
    // FullName:    KDIS::DataTypes::SetRelativeAntennaLocation
    //              KDIS::DataTypes::GetRelativeAntennaLocation
    // Description: Antenna entity location. Represented as Entity Coordinate Vector
    // Parameter:   const Vector & RAL
    //************************************
    void SetRelativeAntennaLocation( const Vector & RAL );
    const Vector & GetRelativeAntennaLocation() const;
    Vector & GetRelativeAntennaLocation();

    //************************************
    // FullName:    KDIS::DataTypes::AntennaLocation::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DataTypes::AntennaLocation::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DataTypes::AntennaLocation::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const AntennaLocation & Value ) const;
    KBOOL operator != ( const AntennaLocation & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
