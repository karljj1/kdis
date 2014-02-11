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
    class:      GridAxisRegular
    created:    26/10/2009
    author:     Karl Jones

    purpose:    The Grid Axis Descriptor record provides detailed information about each grid axes and grid location
                coordinates for environmental state variables for use in the Gridded Data PDU.
                This record provides for the representation of grids with constant spacing or variable spacing.
                This record shall contain information about the coordinate of the origin and endpoint of the axis,
                the number of grid points along the axis, the inter leaf    factor, the axis type, number of axis
                grid points and the coordinate scale factor, the coordinate offset value, and the grid location coordinates.

                In the following descriptions, domain shall refer to the entire volume for which gridded data are to be transmitted.
                This region shall be defined by specifying the origin and endpoint for each grid axis. Use of x, y, and
                z to denote the three coordinates of a grid point is for convenience and does not imply the sole use of Cartesian
                coordinates. A more general coordinate representation (x1, x2, x3) or xi is used in the tables to provide
                generality. Since a region may be sufficiently large to require distribution via multiple Gridded Data PDUs,
                any reference to PDU refers to data contained only within the current Gridded Data PDU. Volumetric gridded
                data shall be transmitted over multiple Gridded Data PDUs with each PDU containing data for subsets
                of the volume selected by horizontal, vertical, or volume sampling.

    size:       192 bits / 24 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT GridAxisRegular : public DataTypeBase
{
protected:

    KFLOAT64 m_f64DomainInitialXi;

    KFLOAT64 m_f64DomainFinalXi;

    KUINT16 m_ui16DomainPointsXi;

    KUINT8 m_ui8InterleafFactor;

    KUINT8 m_ui8AxisType;

    KUINT16 m_ui16NumPoints;

    KUINT16 m_ui16InitialIndex;

public:

#define GRID_AXIS_REGULAR 24

    GridAxisRegular();

    GridAxisRegular( KDataStream & stream ) throw( KException );

    // This constructor is used by the Gridded_Data_PDU. In order to know if a grid axis is regular or irregular
    // we must first decode 4 other values before we can get to the AxisType value. So this constructor is here to aid in this process.
    GridAxisRegular( KFLOAT64 InitialXi, KFLOAT64 FinalXi, KUINT16 PointsXi, KUINT8 InterleafFactor,
                     KUINT8 AxisType, KDataStream & stream );

    GridAxisRegular( KFLOAT64 InitialXi, KFLOAT64 FinalXi, KUINT16 PointsXi, KUINT8 InterleafFactor,
                     KUINT8 AxisType, KUINT16 NumPoints, KUINT16 InitialIndexXi );

    virtual ~GridAxisRegular();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisRegular::SetDomainInitialXi
    //              KDIS::DATA_TYPE::GridAxisRegular::GetDomainInitialXi
    // Description: Specifies the coordinate of the origin (or initial value) for the Xi axis
    //              for the environmental state variable data contained within the bounding domain.
    // Parameter:   KFLOAT64 Xi, void
    //************************************
    void SetDomainInitialXi( KFLOAT64 Xi );
    KFLOAT64 GetDomainInitialXi() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisRegular::SetDomainFinalXi
    //              KDIS::DATA_TYPE::GridAxisRegular::GetDomainFinalXi
    // Description: Specifies the coordinate of the endpoint (or Final value) for the Xi axis
    //              for the environmental state variable data contained within the bounding domain.
    // Parameter:   KFLOAT64 Xi, void
    //************************************
    void SetDomainFinalXi( KFLOAT64 Xi );
    KFLOAT64 GetDomainFinalXi() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisRegular::SetDomainPointsXi
    //              KDIS::DATA_TYPE::GridAxisRegular::GetDomainPoints
    // Description: Specifies the number of grid points along the Xi domain axis for the environmental
    //              state variable data.
    //              This number may exceed the number of points along an axis for a single Gridded
    //              Data PDU if there are multiple PDUs being issued to contain all the data.
    // Parameter:   KUINT16 Xi, void
    //************************************
    void SetDomainPointsXi( KUINT16 Xi );
    KUINT16 GetDomainPoints() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisRegular::SetInterleafFactor
    //              KDIS::DATA_TYPE::GridAxisRegular::GetInterleafFactor
    // Description: Specifies the inter leaf factor along a domain (grid) axis.
    //              A value of one shall indicate no sub-sampling (interleaving), while values
    //              greater than one shall indicate the sampling frequency along an axis.
    // Parameter:   KUINT8 IF, void
    //************************************
    void SetInterleafFactor( KUINT8 IF );
    KUINT8 GetInterleafFactor() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisRegular::SetAxisType
    //              KDIS::DATA_TYPE::GridAxisRegular::GetAxisType
    // Description: Specifies the type of grid axis represented.
    //              A value of zero shall indicate a grid axis with constant grid
    //              spacing (a regular axis), while a value of one shall indicate
    //              a grid axis with variable grid spacing (an irregular axis).
    // Parameter:   KUINT8 AT, void
    //************************************
    void SetAxisType( KUINT8 AT );
    KUINT8 GetAxisType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisRegular::SetNumberOfPointsOnXiAxis
    //              KDIS::DATA_TYPE::GridAxisRegular::GetNumberOfPointsOnXiAxis
    // Description: Specifies the number of grid locations along the Xi axis for the
    //              environmental state variable data contained within the current PDU.
    // Parameter:   KUINT16 NP, void
    //************************************
    void SetNumberOfPointsOnXiAxis( KUINT16 NP );
    KUINT16 GetNumberOfPointsOnXiAxis() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisRegular::SetInitialIndexXi
    //              KDIS::DATA_TYPE::GridAxisRegular::GetInitialIndexXi
    // Description: Specifies the index of the initial grid point for the current PDU
    //              along the Xi domain axis. A value of zero shall indicate that the
    //              PDU grid and the domain grid have the same initial point.
    // Parameter:   KUINT16 I, void
    //************************************
    void SetInitialIndexXi( KUINT16 I );
    KUINT16 GetInitialIndexXi() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisRegular::GetAsString
    // Description: If false then this is in fact a derived GridAxisIrregular instance and can be safely
    //              up cast for access to the additional fields.
    //************************************
    virtual KBOOL IsGridRegular() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisRegular::GetAsString
    // Description: Returns length in octets, used for determining the PDU length.
    //************************************
    virtual KUINT16 GetLength();

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisRegular::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisRegular::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::GridAxisRegular::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const GridAxisRegular & Value ) const;
    KBOOL operator != ( const GridAxisRegular & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

