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
    class:      PointObjectAppearance
    created:    17/02/2010
    author:     Karl Jones

    purpose:    Represents a point objects appearance.
    size:       48 Bits / 6 Octet
*********************************************************************/

#pragma once

#include "./ObjectAppearance.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT PointObjectAppearance : public ObjectAppearance
{
protected:

    union
    {
        struct
        {
            KUINT32 m_ui32Breach : 2;
            KUINT32 m_ui32Unused : 30;
        } m_LogCribAbatisVehicleDefiladeInf;

        struct
        {
            KUINT32 m_ui32Opacity  : 8;
            KUINT32 m_ui32Size     : 8;
            KUINT32 m_ui32Height   : 8;
            KUINT32 m_ui32NumBurst : 6;
            KUINT32 m_ui32Chemical : 2;

        } m_AirBurstGroundBurst;

        struct
        {
            KUINT32 m_ui32Size   : 8;
            KUINT32 m_ui32Unused : 24;

        } m_Crater;

        struct
        {
            KUINT32 m_ui32NumSeg : 8;
            KUINT32 m_ui32Unused : 24;
        } m_RibbonBridge;

        KUINT32 m_ui32SpecificAppearance;
    } m_SpecificAppearanceUnion;

public:

    static const KUINT16 POINT_OBJECT_APPEARANCE_SIZE = 6;

    PointObjectAppearance();

    PointObjectAppearance( KDataStream & stream ) throw( KException );

    virtual ~PointObjectAppearance();

    /************************************************************************/
    /* The following appearance values are only for points of the type:     */
    /* Log crib, Abatis, Vehicle defilade, and Infantry fighting position   */
    /************************************************************************/

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointObjectAppearance::SetBreach
    //              KDIS::DATA_TYPE::PointObjectAppearance::GetBreach
    // Description: Describes the breached appearance of the object.
    // Parameter:   Breach2bit B
    //************************************
    void SetBreach( KDIS::DATA_TYPE::ENUMS::Breach2bit B );
    KDIS::DATA_TYPE::ENUMS::Breach2bit GetBreach() const;

    /************************************************************************/
    /* The following appearance values are only for points of the type:     */
    /* Air burst, Ground burst                                              */
    /************************************************************************/

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointObjectAppearance::SetOpacity
    //              KDIS::DATA_TYPE::PointObjectAppearance::GetOpacity
    // Description: The percent opacity of the smoke, ranging from 0% opacity to 100%.
    //              Acceptable values are 0 - 100 else throws INVALID_DATA exception.
    // Parameter:   KUINT8 O
    //************************************
    void SetOpacity( KUINT8 O ) throw( KException );
    KUINT8 GetOpacity() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointObjectAppearance::SetBurstSize
    //              KDIS::DATA_TYPE::PointObjectAppearance::GetBurstSize
    // Description: Indicates the radius of the cylinder which approximates
    //              an individual burst. The Point Object Location field
    //              indicates the center of the bottom of the cylinder
    //              for individual bursts. For multiple bursts, the center
    //              bottom of each cylinder is calculated based on the model
    //              used to represent the multiple bursts.
    // Parameter:   KUINT8 S
    //************************************
    void SetBurstSize( KUINT8 S );
    KUINT8 GetBurstSize() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointObjectAppearance::SetHeight
    //              KDIS::DATA_TYPE::PointObjectAppearance::GetHeight
    // Description: The height of the cylinder which approximates an individual burst.
    //              The Point Object Location field indicates the center of the bottom
    //              of the cylinder for individual bursts. For multiple bursts,
    //              the center bottom of each cylinder is calculated based on the
    //              model used to represent the multiple bursts.
    // Parameter:   KUINT8 H
    //************************************
    void SetHeight( KUINT8 H );
    KUINT8 GetHeight() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointObjectAppearance::SetNumBursts
    //              KDIS::DATA_TYPE::PointObjectAppearance::GetNumBursts
    // Description: Number of bursts in the instance of tactical smoke.
    //              Acceptable values are 0 - 63.
    // Parameter:   KUINT8 H
    //************************************
    void SetNumBursts( KUINT8 N );
    KUINT8 GetNumBursts() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointObjectAppearance::SetChemical
    //              KDIS::DATA_TYPE::PointObjectAppearance::GetChemical
    // Description: The chemical content of the smoke.
    // Parameter:   Chemical C
    //************************************
    void SetChemical( KDIS::DATA_TYPE::ENUMS::Chemical C );
    KDIS::DATA_TYPE::ENUMS::Chemical GetChemical() const;

    /************************************************************************/
    /* The following appearance values are only for points of the type:     */
    /* Crater                                                               */
    /************************************************************************/

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointObjectAppearance::SetCraterSize
    //              KDIS::DATA_TYPE::PointObjectAppearance::GetCraterSize
    // Description: The diameter of the crater, where the center of the
    //              crater is at the Point Object Location.
    // Parameter:   KUINT8 S
    //************************************
    void SetCraterSize( KUINT8 S );
    KUINT8 GetCraterSize() const;

    /************************************************************************/
    /* The following appearance values are only for points of the type:     */
    /* Ribbon Bridge                                                        */
    /************************************************************************/

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointObjectAppearance::SetNumSegments
    //              KDIS::DATA_TYPE::PointObjectAppearance::GetNumSegments
    // Description: The number of segments composing the ribbon bridge.
    // Parameter:   KUINT8 N
    //************************************
    void SetNumSegments( KUINT8 N );
    KUINT8 GetNumSegments() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointObjectAppearance::GetAsString
    // Description: Returns a string representation of the appearance
    // Parameter:   const EntityType & EntType
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointObjectAppearance::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::PointObjectAppearance::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const PointObjectAppearance & Value ) const;
    KBOOL operator != ( const PointObjectAppearance & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
