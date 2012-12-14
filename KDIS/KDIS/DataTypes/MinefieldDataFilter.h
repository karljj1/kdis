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
    class:      MinefieldDataFilter
    created:    17/05/2010
    author:     Karl Jones

    purpose:    Provides a simple interface to the 32-bit enumeration for the Data Filter
                field of the Minefield Query PDU and the Minefield Data PDU.
                The data filter is used to identify which of the optional fields are
                being requested(Minefield Query PDU) or are present(Minefield Data PDU).
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT MinefieldDataFilter : public DataTypeBase
{
protected:

    union
    {
        struct
        {
            KUINT32 m_ui32GroundOffset : 1;
            KUINT32 m_ui32WaterOffset  : 1;
            KUINT32 m_ui32SnowOffset   : 1;
            KUINT32 m_ui32MineOri      : 1;
            KUINT32 m_ui32ThermalCon   : 1;
            KUINT32 m_ui32Reflectance  : 1;
            KUINT32 m_ui32MineEmpAge   : 1;
            KUINT32 m_ui32TripDetWire  : 1;
            KUINT32 m_ui32Fusing       : 1;
            KUINT32 m_ui32ScalarDet    : 1;
            KUINT32 m_ui32PaintScm     : 1;
            KUINT32 m_ui32Padding      : 21;
        };
        KUINT32 m_ui32Filter;
    } m_FilterUnion;

public:

    static const KUINT16 MINEFIELD_DATA_FILTER_SIZE = 4;

    MinefieldDataFilter( void );

    MinefieldDataFilter( KDataStream & stream ) throw( KException );

    MinefieldDataFilter( KBOOL GroundBurialDepthOffset, KBOOL WaterBurialDepthOffset, KBOOL SnowBurialDepthOffset,
                         KBOOL MineOrientation, KBOOL ThermalContrast, KBOOL Reflectance, KBOOL MineEmplacementAge,
                         KBOOL TripDetonationWire, KBOOL Fusing, KBOOL ScalarDetectionCoefficient, KBOOL PaintScheme );

    virtual ~MinefieldDataFilter( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldDataFilter::SetGroundBurialDepthOffset
    //              KDIS::DATA_TYPE::MinefieldDataFilter::IsGroundBurialDepthOffset
    // Description: Identifies whether Ground Burial Depth Offset data is requested / present.
    //              true(1) - requested, false(0) - not requested.
    // Parameter:   KBOOL B, void
    //************************************
    void SetGroundBurialDepthOffset( KBOOL B );
    KBOOL IsGroundBurialDepthOffset() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldDataFilter::SetWaterBurialDepthOffset
    //              KDIS::DATA_TYPE::MinefieldDataFilter::IsWaterBurialDepthOffset
    // Description: Identifies whether Water Burial Depth Offset data is requested / present.
    //              true(1) - requested, false(0) - not requested.
    // Parameter:   KBOOL B, void
    //************************************
    void SetWaterBurialDepthOffset( KBOOL B );
    KBOOL IsWaterBurialDepthOffset() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldDataFilter::SetSnowBurialDepthOffset
    //              KDIS::DATA_TYPE::MinefieldDataFilter::IsSnowBurialDepthOffset
    // Description: Identifies whether Snow Burial Depth Offset data is requested / present.
    //              true(1) - requested, false(0) - not requested.
    // Parameter:   KBOOL B, void
    //************************************
    void SetSnowBurialDepthOffset( KBOOL B );
    KBOOL IsSnowBurialDepthOffset() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldDataFilter::SetMineOrientation
    //              KDIS::DATA_TYPE::MinefieldDataFilter::IsMineOrientation
    // Description: Identifies whether Mine Orientation data is requested / present.
    //              true(1) - requested, false(0) - not requested.
    // Parameter:   KBOOL B, void
    //************************************
    void SetMineOrientation( KBOOL B );
    KBOOL IsMineOrientation() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldDataFilter::SetThermalContrast
    //              KDIS::DATA_TYPE::MinefieldDataFilter::IsThermalContrast
    // Description: Identifies whether Thermal Contrast data is requested / present.
    //              true(1) - requested, false(0) - not requested.
    // Parameter:   KBOOL B, void
    //************************************
    void SetThermalContrast( KBOOL B );
    KBOOL IsThermalContrast() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldDataFilter::SetReflectance
    //              KDIS::DATA_TYPE::MinefieldDataFilter::IsReflectance
    // Description: Identifies whether Dielectric Constant data is requested / present.
    //              true(1) - requested, false(0) - not requested.
    // Parameter:   KBOOL B, void
    //************************************
    void SetReflectance( KBOOL B );
    KBOOL IsReflectance() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldDataFilter::SetMineEmplacementAge
    //              KDIS::DATA_TYPE::MinefieldDataFilter::IsMineEmplacementAge
    // Description: Identifies whether Mine Emplacement Age data is requested / present.
    //              true(1) - requested, false(0) - not requested.
    // Parameter:   KBOOL B, void
    //************************************
    void SetMineEmplacementAge( KBOOL B );
    KBOOL IsMineEmplacementAge() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldDataFilter::SetTripDetonationWire
    //              KDIS::DATA_TYPE::MinefieldDataFilter::IsTripDetonationWire
    // Description: Identifies whether Trip / Detonation Wire Location data is requested / present.
    //              true(1) - requested, false(0) - not requested.
    // Parameter:   KBOOL B, void
    //************************************
    void SetTripDetonationWire( KBOOL B );
    KBOOL IsTripDetonationWire() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldDataFilter::SetFusing
    //              KDIS::DATA_TYPE::MinefieldDataFilter::IsFusing
    // Description: Identifies whether Fusing data is requested / present.
    //              true(1) - requested, false(0) - not requested.
    // Parameter:   KBOOL B, void
    //************************************
    void SetFusing( KBOOL B );
    KBOOL IsFusing() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldDataFilter::SetScalarDetectionCoefficient
    //              KDIS::DATA_TYPE::MinefieldDataFilter::IsScalarDetectionCoefficient
    // Description: Identifies whether Scalar Detection Coefficient data is requested / present.
    //              true(1) - requested, false(0) - not requested.
    // Parameter:   KBOOL B, void
    //************************************
    void SetScalarDetectionCoefficient( KBOOL B );
    KBOOL IsScalarDetectionCoefficient() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldDataFilter::SetPaintScheme
    //              KDIS::DATA_TYPE::MinefieldDataFilter::IsPaintScheme
    // Description: Identifies whether Paint Scheme data is requested / present.
    //              true(1) - requested, false(0) - not requested.
    // Parameter:   KBOOL B, void
    //************************************
    void SetPaintScheme( KBOOL B );
    KBOOL IsPaintScheme() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldDataFilter::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldDataFilter::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldDataFilter::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const MinefieldDataFilter & Value ) const;
    KBOOL operator != ( const MinefieldDataFilter & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
