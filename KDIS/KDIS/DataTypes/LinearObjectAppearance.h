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

using KDIS::DATA_TYPE::ENUMS::Breach2bit;
using KDIS::DATA_TYPE::ENUMS::VisibleSide;
using KDIS::DATA_TYPE::ENUMS::Chemical;
using std::bitset;

class KDIS_EXPORT LinearObjectAppearance : public ObjectAppearance
{
protected:

    union
    {
        struct
        {
            KUINT32 m_ui32Breach        : 2;
            KUINT32 m_ui32Unused        : 14;
            KUINT32 m_ui32BreachLength  : 8;
            KUINT32 m_ui32BreachLoc     : 8;
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

    LinearObjectAppearance( void );

    LinearObjectAppearance( KDataStream & stream ) throw( KException );

    virtual ~LinearObjectAppearance( void );

    /************************************************************************/
    /* The following appearance values are only for linear's of the type:   */
    /* Tank ditch, and Concertina Wire                                      */
    /************************************************************************/

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearObjectAppearance::SetBreach
    //              KDIS::DATA_TYPE::LinearObjectAppearance::GetBreach
    // Description: Describes the breached appearance of the object.
    // Parameter:   Breach2bit B, void
    //************************************
    void SetBreach( Breach2bit B );
    Breach2bit GetBreach() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearObjectAppearance::SetBreachLength
    //              KDIS::DATA_TYPE::LinearObjectAppearance::GetBreachLength
    // Description: Integer indicating the fixed length in meters of a breached segment.
    // Parameter:   KUINT8 L, void
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
    // Parameter:   const bitset<8> & L, KUINT8 L, void, void
    //************************************
    void SetBreachLocation( const bitset<8> & L );
    void SetBreachLocation( KUINT8 L );
    KUINT8 GetBreachLocation() const;
    bitset<8> GetBreachLocationAsBitset();

    /************************************************************************/
    /* The following appearance values are only for linears of the type:    */
    /* Exhaust Smoke                                                        */
    /************************************************************************/

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearObjectAppearance::SetOpacity
    //              KDIS::DATA_TYPE::LinearObjectAppearance::GetOpacity
    // Description: The percent opacity of the smoke, ranging from 0% opacity to 100%.
    //              Acceptable values are 0 - 100 else throws INVALID_DATA exception.
    // Parameter:   KUINT8 O, void
    //************************************
    void SetOpacity( KUINT8 O ) throw( KException );
    KUINT8 GetOpacity() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearObjectAppearance::SetAttached
    //              KDIS::DATA_TYPE::LinearObjectAppearance::IsAttached
    // Description: Describes whether the smoke is attached to the vehicle.
    // Parameter:   KBOOL A, void
    //************************************
    void SetAttached( KBOOL A );
    KBOOL IsAttached() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearObjectAppearance::SetChemical
    //              KDIS::DATA_TYPE::LinearObjectAppearance::GetChemical
    // Description: The chemical content of the smoke.
    // Parameter:   Chemical C, void
    //************************************
    void SetChemical( Chemical C );
    Chemical GetChemical() const;

    /************************************************************************/
    /* The following appearance values are only for linears of the type:    */
    /* Minefield Lane Marker                                                */
    /************************************************************************/

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearObjectAppearance::SetVisibleSide
    //              KDIS::DATA_TYPE::LinearObjectAppearance::GetVisibleSide
    // Description: Describes the side of the lane marker which is visible.
    // Parameter:   VisibleSide V, void
    //************************************
    void SetVisibleSide( VisibleSide V );
    VisibleSide GetVisibleSide() const;

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS
