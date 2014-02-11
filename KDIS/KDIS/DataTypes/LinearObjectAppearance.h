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
    class:      LinearObjectAppearance
    created:    15/03/2010
    author:     Karl Jones

    purpose:    Represents a linear objects appearance.
    size:       48 Bits / 6 Octet
*********************************************************************/

#pragma once

#include "./ObjectAppearance.h"
#include <bitset>

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT LinearObjectAppearance : public ObjectAppearance
{
protected:

    union
    {
        struct
        {
            KUINT32 m_ui32Breach       : 2;
            KUINT32 m_ui32Unused       : 14;
            KUINT32 m_ui32BreachLength : 8;
            KUINT32 m_ui32BreachLoc    : 8;
        } m_TankDitchConcertinaWire;

        struct
        {
            KUINT32 m_ui32Opacity  : 8;
            KUINT32 m_ui32Attached : 1;
            KUINT32 m_ui32Chemical : 2;
            KUINT32 m_ui32Unused   : 21;
        } m_ExhaustSmoke;

        struct
        {
            KUINT32 m_ui32VisibleSide : 2;
            KUINT32 m_ui32Unused      : 30;
        } m_MinefieldLaneMarker;

        KUINT32 m_ui32SpecificAppearance;
    } m_SpecificAppearanceUnion;

public:

    static const KUINT16 LINEAR_OBJECT_APPEARANCE_SIZE = 6;

    LinearObjectAppearance();

    LinearObjectAppearance( KDataStream & stream ) throw( KException );

    virtual ~LinearObjectAppearance();

    /************************************************************************/
    /* The following appearance values are only for linear's of the type:   */
    /* Tank ditch, and Concertina Wire                                      */
    /************************************************************************/

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearObjectAppearance::SetBreach
    //              KDIS::DATA_TYPE::LinearObjectAppearance::GetBreach
    // Description: Describes the breached appearance of the object.
    // Parameter:   Breach2bit B
    //************************************
    void SetBreach( KDIS::DATA_TYPE::ENUMS::Breach2bit B );
    KDIS::DATA_TYPE::ENUMS::Breach2bit GetBreach() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearObjectAppearance::SetBreachLength
    //              KDIS::DATA_TYPE::LinearObjectAppearance::GetBreachLength
    // Description: Integer indicating the fixed length in meters of a breached segment.
    // Parameter:   KUINT8 L
    //************************************
    void SetBreachLength( KUINT8 L );
    KUINT8 GetBreachLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearObjectAppearance::SetBreachLocation
    //              KDIS::DATA_TYPE::LinearObjectAppearance::GetBreachLocation
    //              KDIS::DATA_TYPE::LinearObjectAppearance::GetBreachLocationAsBitset
    // Description: Each bit indicates whether its associated segment is breached or not.
    //              Bit 40+i indicates whether the portion of the segment beginning at the
    //              segment origin + (i*Breach Length) and extending i* Breach
    //              Length meters is breached or not.
    //              For each bit:
    //              0  Associated portion of segment is not breached
    //              1  Associated portion of segment is breached
    // Parameter:   const bitset<8> & L, KUINT8 L
    //************************************
	void SetBreachLocation( const std::bitset<8> & L );
    void SetBreachLocation( KUINT8 L );
    KUINT8 GetBreachLocation() const;
	std::bitset<8> GetBreachLocationAsBitset();

    /************************************************************************/
    /* The following appearance values are only for linears of the type:    */
    /* Exhaust Smoke                                                        */
    /************************************************************************/

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearObjectAppearance::SetOpacity
    //              KDIS::DATA_TYPE::LinearObjectAppearance::GetOpacity
    // Description: The percent opacity of the smoke, ranging from 0% opacity to 100%.
    //              Acceptable values are 0 - 100 else throws INVALID_DATA exception.
    // Parameter:   KUINT8 O
    //************************************
    void SetOpacity( KUINT8 O ) throw( KException );
    KUINT8 GetOpacity() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearObjectAppearance::SetAttached
    //              KDIS::DATA_TYPE::LinearObjectAppearance::IsAttached
    // Description: Describes whether the smoke is attached to the vehicle.
    // Parameter:   KBOOL A
    //************************************
    void SetAttached( KBOOL A );
    KBOOL IsAttached() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearObjectAppearance::SetChemical
    //              KDIS::DATA_TYPE::LinearObjectAppearance::GetChemical
    // Description: The chemical content of the smoke.
    // Parameter:   Chemical C
    //************************************
    void SetChemical( KDIS::DATA_TYPE::ENUMS::Chemical C );
    KDIS::DATA_TYPE::ENUMS::Chemical GetChemical() const;

    /************************************************************************/
    /* The following appearance values are only for linears of the type:    */
    /* Minefield Lane Marker                                                */
    /************************************************************************/

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearObjectAppearance::SetVisibleSide
    //              KDIS::DATA_TYPE::LinearObjectAppearance::GetVisibleSide
    // Description: Describes the side of the lane marker which is visible.
    // Parameter:   VisibleSide V
    //************************************
    void SetVisibleSide( KDIS::DATA_TYPE::ENUMS::VisibleSide V );
    KDIS::DATA_TYPE::ENUMS::VisibleSide GetVisibleSide() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearObjectAppearance::GetAsString
    // Description: Returns a string representation of the appearance
    // Parameter:   const EntityType & EntType
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearObjectAppearance::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearObjectAppearance::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const LinearObjectAppearance & Value ) const;
    KBOOL operator != ( const LinearObjectAppearance & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
