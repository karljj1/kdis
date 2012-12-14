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

using std::vector;

class KDIS_EXPORT GridAxisIrregular : public GridAxisRegular
{
protected:

    KFLOAT64 m_f64CoordScaleXi;

    KFLOAT64 m_f64CoordOffsetXi;

    vector<KUINT16> m_vXiValues;

    vector<KUINT16> m_vui16Padding; // To 64 bit boundary

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisIrregular::GetAsString
    // Description: Calculates and adds padding so that the data type is on a 64 bit boundary.
    //************************************
    void calculatePadding();

public:

#define GRID_AXIS_IRREGULAR 40 // Min size

    GridAxisIrregular( void );

    GridAxisIrregular( KDataStream & stream ) throw( KException );

    // This constructor is used by the Gridded_Data_PDU. In order to know if a grid axis is regular or irregular
    // we must first decode 4 other values before we can get to the AxisType value. So this constructor is here to aid in this process.
    GridAxisIrregular( KFLOAT64 InitialXi, KFLOAT64 FinalXi, KUINT16 PointsXi, KUINT8 InterleafFactor,
                       KUINT8 AxisType, KDataStream & stream );

    GridAxisIrregular( KFLOAT64 InitialXi, KFLOAT64 FinalXi, KUINT16 PointsXi, KUINT8 InterleafFactor,
                       KUINT8 AxisType, KUINT16 InitialIndexXi, KFLOAT64 CoordinateScaleXi,
                       KFLOAT64 CoordinateOffsetXi, const vector<KUINT16> & XiValues );

    virtual ~GridAxisIrregular( void );

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
    void SetXiValues( const vector<KUINT16> & Xi );
    const vector<KUINT16> & GetXiValues() const;
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

}; // END namespace DATA_TYPES
}; // END namespace KDIS

