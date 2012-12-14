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
    class:      Shaft
    created:    2009/01/04
    author:     Karl Jones

    purpose:    Represents a shaft on a platform.
    size:       64 bits / 8 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT Shaft : public DataTypeBase
{
protected:

    KINT16 m_i16CurrentRPM;

    KINT16 m_i16OrderedRPM;

    KINT32 m_i32RPMRateOfChange;

public:

    static const KUINT16 SHAFT_SIZE = 8;

    Shaft( void );

    Shaft( KDataStream & stream ) throw( KException );

    Shaft( KINT16 CurrentRPM, KINT16 OrderedRPM, KINT32 RateOfChange );

    virtual ~Shaft( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::Shaft::SetCurrentRPM
    //              KDIS::DATA_TYPE::Shaft::GetCurrentRPM
    // Description: Current speed in RPM of the shaft.
    //              A positive value indicates a clockwise
    //              rotation. Shafts are defined from port to
    //              starboard locations(refrence view is from stern to bow).
    // Parameter:   KINT16 RPM, void
    //************************************
    void SetCurrentRPM( KINT16 RPM );
    KINT16 GetCurrentRPM() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Shaft::SetOrderedRPM
    //              KDIS::DATA_TYPE::Shaft::GetOrderedRPM
    // Description: Current speed in RPM of the shaft.
    //              A positive value indicates a clockwise
    //              rotation. Shafts are defined from port to
    //              starboard locations(refrence view is from stern to bow).
    // Parameter:   KINT16 RPM, void
    //************************************
    void SetOrderedRPM( KINT16 RPM );
    KINT16 GetOrderedRPM() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Shaft::SetRateOfChange
    //              KDIS::DATA_TYPE::Shaft::GetRateOfChange
    // Description: Current speed in RPM of the shaft.
    //              A positive value indicates a clockwise
    //              rotation. Shafts are defined from port to
    //              starboard locations(refrence view is from stern to bow).
    // Parameter:   KINT32 ROC, void
    //************************************
    void SetRateOfChange( KINT32 ROC );
    KINT32 GetRateOfChange() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Shaft::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Shaft::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::Shaft::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Shaft & Value ) const;
    KBOOL operator != ( const Shaft & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

