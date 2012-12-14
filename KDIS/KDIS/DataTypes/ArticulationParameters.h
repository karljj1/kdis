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
    class:      ArticulationParameters
    created:    24/09/2008
    author:     Karl Jones

    purpose:    Specification of articulation parameters for moving
                and attached parts.
                In DIS version 7 onwards this data type is known as "Variable Parameters".
    size:       128 bits / 16
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::ArticulationType;
using KDIS::DATA_TYPE::ENUMS::ArticulatedPartsHighBits;
using KDIS::DATA_TYPE::ENUMS::ArticulatedPartsLowBits;

class KDIS_EXPORT ArticulationParameters :  public DataTypeBase
{
protected:

    KUINT8 m_ui8ArticulationType;

    KUINT8 m_ui8ParmeterChange;

    KUINT16 m_ui16AttachementID;

    union
    {
        struct
        {
            KUINT16 m_VariantLowBits;

            KUINT16 m_VariantHighBits;
        };

        KUINT32 m_ui32ParamTypeVariant;
    } m_ui32ParamTypeVariantUnion;

    KUINT64 m_ui64ParamValue;

public:

    static const KUINT16 ARTICULATION_PARAMETERS_SIZE = 16;

    ArticulationParameters( void );

    ArticulationParameters( KDataStream & stream ) throw( KException );

    ArticulationParameters( ArticulationType AT, KUINT8 ParamChangeIndicator,
                            KUINT16 AttachID, KUINT32 TypeVariant, KUINT64 Value );

    virtual ~ArticulationParameters( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulationParameters::SetArticulationType
    //              KDIS::DATA_TYPE::ArticulationParameters::GetArticulationType
    // Description: Type.
    // Parameter:   ArticulationType AT, void
    //************************************
    void SetArticulationType( ArticulationType AT );
    ArticulationType GetArticulationType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulationParameters::SetParameterChangeIndicator
    //              KDIS::DATA_TYPE::ArticulationParameters::GetParameterChangeIndicator
    // Description: Stores change to any articulated part. Set to 0 at sim start and incremented
    //              each time a change occurs, if value > 255 it should be set back to 0.
    // Parameter:   KUINT8 PCI, void
    //************************************
    void SetParameterChangeIndicator( KUINT8 PCI );
    KUINT8 GetParameterChangeIndicator() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulationParameters::SetAttachementID
    //              KDIS::DATA_TYPE::ArticulationParameters::GetAttachementID
    // Description: ID field of the articulated part to which the articulation parameter
    //              is attached. Field shall be 0 if the part is attached directly
    //              to the entity.
    // Parameter:   KUINT16 ID, void
    //************************************
    void SetAttachementID( KUINT16 ID );
    KUINT16 GetAttachementID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulationParameters::SetTypeVariantLowBits
    //              KDIS::DATA_TYPE::ArticulationParameters::GetTypeVariantLowBits
    // Description: Set the low bits value to the entity.
    // Parameter:   ArticulatedPartsLowBits VLB, void
    //************************************
    void SetTypeVariantLowBits( ArticulatedPartsLowBits VLB );
    ArticulatedPartsLowBits GetTypeVariantLowBits() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulationParameters::SetTypeVariantHighBits
    //              KDIS::DATA_TYPE::ArticulationParameters::GetTypeVariantHighBits
    // Description: Set the high bits value to the entity.
    // Parameter:   ArticulatedPartsHighBits VHB, void
    //************************************
    void SetTypeVariantHighBits( ArticulatedPartsHighBits VHB );
    ArticulatedPartsHighBits GetTypeVariantHighBits() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulationParameters::SetTypeVariant
    //              KDIS::DATA_TYPE::ArticulationParameters::GetTypeVariant
    // Description: Depends on Part type, only applies to Articulated parts.
    //              Not used for Attached parts.
    // Parameter:   KUINT32 TV, void
    //************************************
    void SetTypeVariant( KUINT32 TV );
    KUINT32 GetTypeVariant() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulationParameters::SetValue
    //              KDIS::DATA_TYPE::ArticulationParameters::GetValue
    // Description: Value.
    // Parameter:   KUINT64 val, void
    //************************************
    void SetValue( KUINT64 val );
    KUINT64 GetValue() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulationParameters::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulationParameters::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulationParameters::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const ArticulationParameters & Value ) const;
    KBOOL operator != ( const ArticulationParameters & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
