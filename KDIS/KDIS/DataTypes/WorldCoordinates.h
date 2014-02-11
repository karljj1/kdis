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
    class:      WorldCoordinates
    created:    18/08/2008
    author:     Karl Jones

    purpose:    World coordinate system.     
				Using a right-handed, geocentric Cartesian coordinate system.
				The origin of the coordinate system is the centroid of the World 
				Geodetic System 1984 (WGS 84) reference frame.
				Scale is 1 unit equals 1m.

    size:       192 bits / 24 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./Vector.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT WorldCoordinates : public DataTypeBase
{
protected:

    KFLOAT64 m_f64X;

    KFLOAT64 m_f64Y;

    KFLOAT64 m_f64Z;

public:

    static const KUINT16 WORLD_COORDINATES_SIZE = 24;

    WorldCoordinates();

    WorldCoordinates( KDataStream & stream ) throw( KException );

    WorldCoordinates( KFLOAT64 X, KFLOAT64 Y, KFLOAT64 Z );

    virtual ~WorldCoordinates();

    //************************************
    // FullName:    KDIS::DATA_TYPE::WorldCoordinates::SetX
    //              KDIS::DATA_TYPE::WorldCoordinates::GetX
    // Description: X
    // Parameter:   KFLOAT64 X
    //************************************
    void SetX( KFLOAT64 X );
    KFLOAT64 GetX() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::WorldCoordinates::SetY
    //              KDIS::DATA_TYPE::WorldCoordinates::GetY
    // Description: Y
    // Parameter:   KFLOAT64 Y
    //************************************
    void SetY( KFLOAT64 Y );
    KFLOAT64 GetY() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::WorldCoordinates::SetZ
    //              KDIS::DATA_TYPE::WorldCoordinates::GetZ
    // Description: Z
    // Parameter:   KFLOAT64 Z
    //************************************
    void SetZ( KFLOAT64 Z );
    KFLOAT64 GetZ() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::WorldCoordinates::Set  
    // Description: Sets x,y and z.
    // Parameter:   KFLOAT64 X
	// Parameter:   KFLOAT64 Y
	// Parameter:   KFLOAT64 Z
    //************************************
	void Set( KFLOAT64 X, KFLOAT64 Y, KFLOAT64 Z );

    //************************************
    // FullName:    KDIS::DATA_TYPE::WorldCoordinates::GetDistance
    // Description: Calculates the distance from this WorldCoordinates to an other. 
    //************************************
	KFLOAT64 GetDistance( const WorldCoordinates & Other );

	//************************************
    // FullName:    KDIS::DATA_TYPE::WorldCoordinates::Lerp
    // Description: Linearly interpolate between From and To by T. 
	//              T should be between 0 and 1(its not checked).
	//              T 0 = From
	//              1 = to 
	//              0.5 = halfway between From and To.
    // Parameter:   const WorldCoordinates & From
	// Parameter:   const WorldCoordinates & To
	// Parameter:   KFLOAT32 T  
    //************************************
	static WorldCoordinates Lerp( const WorldCoordinates & From, const WorldCoordinates & To, KFLOAT32 T );
	void Lerp( const WorldCoordinates & To, KFLOAT32 T );

    //************************************
    // FullName:    KDIS::DATA_TYPE::WorldCoordinates::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::WorldCoordinates::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::WorldCoordinates::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const WorldCoordinates & Value ) const;
    KBOOL operator != ( const WorldCoordinates & Value ) const;
    WorldCoordinates operator * ( const WorldCoordinates & Value ) const;
    WorldCoordinates operator * ( KFLOAT64 Value ) const;
	WorldCoordinates operator * ( KFLOAT32 Value ) const;
    WorldCoordinates operator + ( const WorldCoordinates & Value ) const;
    WorldCoordinates operator + ( const Vector & Value ) const;
    WorldCoordinates & operator += ( const Vector & Value );
    const WorldCoordinates & operator = ( const Vector & Value );
    WorldCoordinates operator - ( const WorldCoordinates & Value ) const;
    WorldCoordinates & operator -= ( const WorldCoordinates & Value );

    // Valid values 0 - X, 1 - Y, 2 - Z. throws OUT_OF_BOUNDS exception for any other value.
    KFLOAT64 & operator[] ( KUINT16 i ) throw( KException );
    const KFLOAT64 & operator[] ( KUINT16 i ) const throw( KException );
};

} // END namespace DATA_TYPES
} // END namespace KDIS

