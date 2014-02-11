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
    class:      GridAxisIrregular
    created:    05/11/2009
    author:     Karl Jones

    purpose:    Implementation of the grid axis data type for Irregular (variable spacing) axis data.

    size:       320 bits / 40 octets - min size
*********************************************************************/

#pragma once

#include "./GridAxisRegular.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT GridAxisIrregular : public GridAxisRegular
{
protected:

    KFLOAT64 m_f64CoordScaleXi;

    KFLOAT64 m_f64CoordOffsetXi;

    std::vector<KUINT16> m_vXiValues;

    std::vector<KUINT16> m_vui16Padding; // To 64 bit boundary

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisIrregular::GetAsString
    // Description: Calculates and adds padding so that the data type is on a 64 bit boundary.
    //************************************
    void calculatePadding();

public:

#define GRID_AXIS_IRREGULAR 40 // Min size

    GridAxisIrregular();

    GridAxisIrregular( KDataStream & stream ) throw( KException );

    // This constructor is used by the Gridded_Data_PDU. In order to know if a grid axis is regular or irregular
    // we must first decode 4 other values before we can get to the AxisType value. So this constructor is here to aid in this process.
    GridAxisIrregular( KFLOAT64 InitialXi, KFLOAT64 FinalXi, KUINT16 PointsXi, KUINT8 InterleafFactor,
                       KUINT8 AxisType, KDataStream & stream );

    GridAxisIrregular( KFLOAT64 InitialXi, KFLOAT64 FinalXi, KUINT16 PointsXi, KUINT8 InterleafFactor,
                       KUINT8 AxisType, KUINT16 InitialIndexXi, KFLOAT64 CoordinateScaleXi,
                       KFLOAT64 CoordinateOffsetXi, const std::vector<KUINT16> & XiValues );

    virtual ~GridAxisIrregular();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisIrregular::SetCoordinateScaleXi
    //              KDIS::DATA_TYPE::GridAxisIrregular::GetCoordinateScaleXi
    // Description: Specifies the value that linearly scales the coordinates of the
    //              grid locations for the Xi axis.
    // Parameter:   KFLOAT64 Xi, void
    //************************************
    void SetCoordinateScaleXi( KFLOAT64 Xi );
    KFLOAT64 GetCoordinateScaleXi() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisIrregular::SetCoordinateOffsetXi
    //              KDIS::DATA_TYPE::GridAxisIrregular::GetCoordinateOffsetXi
    // Description: Specifies the constant offset value that shall be applied to the grid locations
    //              for the Xi axis (for example, the Earth radius is the z-axis offset).
    // Parameter:   KFLOAT64 Xi, void
    //************************************
    void SetCoordinateOffsetXi( KFLOAT64 Xi );
    KFLOAT64 GetCoordinateOffsetXi() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisIrregular::AddXiValue
    //              KDIS::DATA_TYPE::GridAxisIrregular::SetXiValues
    //              KDIS::DATA_TYPE::GridAxisIrregular::GetXiValues
    //              KDIS::DATA_TYPE::ClearXiValues
    // Description: Specifies the coordinate values for the Ni grid locations along the
    //              irregular (variable spacing) Xi axis for environmental data values
    //              contained within the PDU.
    //              Note: The Add and Set functions will automatically set NumberOfPointsOnXiAxis to the
    //              correct value.
    // Parameter:   KUINT16 Xi, const vector<KUINT16> & Xi, void
    //************************************
    void AddXiValue( KUINT16 Xi );
    void SetXiValues( const std::vector<KUINT16> & Xi );
    const std::vector<KUINT16> & GetXiValues() const;
    void ClearXiValues();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisIrregular::GetAsString
    // Description: If false then this is in fact a derived GridAxisIrregular instance and can be safely
    //              up cast for access to the additional fields.
    //************************************
    virtual KBOOL IsGridRegular() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisIrregular::GetAsString
    // Description: Returns length in octets, used for determining the PDU length.
    //************************************
    virtual KUINT16 GetLength();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisIrregular::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisIrregular::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisIrregular::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GridAxisIrregular & Value ) const;
    KBOOL operator != ( const GridAxisIrregular & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

