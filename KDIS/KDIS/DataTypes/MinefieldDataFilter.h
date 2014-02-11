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

    MinefieldDataFilter();

    MinefieldDataFilter( KDataStream & stream ) throw( KException );

    MinefieldDataFilter( KBOOL GroundBurialDepthOffset, KBOOL WaterBurialDepthOffset, KBOOL SnowBurialDepthOffset,
                         KBOOL MineOrientation, KBOOL ThermalContrast, KBOOL Reflectance, KBOOL MineEmplacementAge,
                         KBOOL TripDetonationWire, KBOOL Fusing, KBOOL ScalarDetectionCoefficient, KBOOL PaintScheme );

    virtual ~MinefieldDataFilter();

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

} // END namespace DATA_TYPES
} // END namespace KDIS
