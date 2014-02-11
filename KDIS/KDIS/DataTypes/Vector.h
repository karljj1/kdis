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
    class:      Vector
    created:    18/09/2008
    author:     Karl Jones

    purpose:    Stores a vector

                A Vector has 4 different representations:

                1)Entity Coordinate Vector
					Location with respect to a particular entity shall be specified with respect
					to three orthogonal axes whose origin shall be the geometric center of the 
					bounding volume of the entity excluding its articulated and attached parts. 
					The x-axis extends in the positive direction out the front of the entity. 
					The y-axis extends in the positive direction out the right side of the entity 
					as viewed from above, facing in the direction of the positive x-axis. 
					The z-axis extends in the positive direction out the bottom of the entity. 
					Each vector component shall represent meters from the origin.

                2)Linear Acceleration Vector - m/s2
					Represented as a vector with components in either world coordinate system or
					entity’s coordinate system depending on the value in the Dead Reckoning Algorithm
					field. Each vector component shall represent acceleration in meters per second squared.

                3)Linear Velocity Vector - m/s
					Represented as a vector with three components in either world coordinate system or 
					entity’s coordinate system depending on the value in the Dead Reckoning Algorithm 
					field. Each vector component shall represent velocity in meters per second. 

                4)Aggregate dimensions box size

    size:       96 bits / 12 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT Vector : public DataTypeBase
{
protected:

    KFLOAT32 m_f32X;

    KFLOAT32 m_f32Y;

    KFLOAT32 m_f32Z;

public:

    static const KUINT16 VECTOR_SIZE = 12;

    Vector();

    Vector( KFLOAT32 X, KFLOAT32 Y, KFLOAT32 Z );

    Vector( KDataStream & stream ) throw( KException );

    virtual ~Vector();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Vector::SetX
    //              KDIS::DATA_TYPE::Vector::GetX
    // Description: First Value / X
    // Parameter:   KFLOAT32  X
    //************************************
    void SetX( KFLOAT32 X );
    KFLOAT32 GetX() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Vector::SetY
    //              KDIS::DATA_TYPE::Vector::GetY
    // Description: Second Value / Y
    // Parameter:   KFLOAT32 Y
    //************************************
    void SetY( KFLOAT32 Y );
    KFLOAT32 GetY() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Vector::SetZ
    //              KDIS::DATA_TYPE::Vector::GetZ
    // Description: Third Value / Z
    // Parameter:   KFLOAT32 Z
    //************************************
    void SetZ( KFLOAT32 Z );
    KFLOAT32 GetZ() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Vector::Set  
    // Description: Sets x,y and z.
    // Parameter:   KFLOAT32 X
	// Parameter:   KFLOAT32 Y
	// Parameter:   KFLOAT32 Z
    //************************************
	void Set( KFLOAT32 X, KFLOAT32 Y, KFLOAT32 Z );

    //************************************
    // FullName:    KDIS::DATA_TYPE::Vector::GetMagnitude
    // Description: Calculates and returns the magnitude or length.
	//				E.G If the vector represented a velocity then this would be the speed.    
    //************************************
	KFLOAT32 GetMagnitude() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Vector::GetDistance
    // Description: Calculates the distance from this vector to an other. 
    // Parameter:   KFLOAT32 Z
    //************************************
	KFLOAT32 GetDistance( const Vector & Other );

	//************************************
    // FullName:    KDIS::DATA_TYPE::Vector::Lerp
    // Description: Linearly interpolate between From and To by T. 
	//              T should be between 0 and 1(its not checked).
	//              T 0 = From
	//              1 = to 
	//              0.5 = halfway between From and To.
    // Parameter:   const Vector & From
	// Parameter:   const Vector & To
	// Parameter:   KFLOAT32 T  
    //************************************
	static Vector Lerp( const Vector & From, const Vector & To, KFLOAT32 T );
	void Lerp( const Vector & To, KFLOAT32 T );

    //************************************
    // FullName:    KDIS::DATA_TYPE::Vector::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Vector::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::Vector::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Vector & Value ) const;
    KBOOL operator != ( const Vector & Value ) const;
    Vector operator * ( const Vector & Value ) const;
    Vector operator * ( KFLOAT64 Value ) const;
	Vector operator * ( KFLOAT32 Value ) const;
    Vector operator + ( const Vector & Value ) const;
    Vector & operator += ( const Vector & Value );
    Vector operator - ( const Vector & Value ) const;
    Vector & operator -= ( const Vector & Value );

    // Valid values 0 - X, 1 - Y, 2 - Z. throws OUT_OF_BOUNDS exception for any other value.
    KFLOAT32 & operator[] ( KUINT16 i ) throw( KException );
    const KFLOAT32 & operator[]  ( KUINT16 i ) const throw( KException );
};

} // END namespace DATA_TYPES
} // END namespace KDIS
