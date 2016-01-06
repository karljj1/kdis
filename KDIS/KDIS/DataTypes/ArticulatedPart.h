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
    class:      ArticulatedPart
    updated:    08/03/2013
    author:     Karl Jones

    purpose:    The Articulated Part VP record is used to represent the state of the movable parts of an entity.
                Examples of movable parts include the turret on a tank and the periscope on a submarine.
                An Articulated Part VP record shall represent the value of only one parameter of a movable,
                or articulated, part. Thus, it may require multiple Articulated Part VP records to describe
                the state of a single articulated part.

    size:       128 bits / 16 octets
*********************************************************************/

#pragma once

#include "./VariableParameter.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT ArticulatedPart : public VariableParameter
{
protected:

    KUINT8 m_ui8ParmeterChange;

    KUINT16 m_ui16AttachementID;

    KUINT32 m_ui32ParamTypeVariant;

    KFLOAT32 m_f32ParamValue;

    KUINT32 m_ui32Padding;

public:

    ArticulatedPart();

    ArticulatedPart( KDataStream & stream ) throw( KException );

    ArticulatedPart( KUINT8 ParamChangeIndicator, KUINT16 AttachID, KDIS::DATA_TYPE::ENUMS::ArticulatedPartsClass C,
                     KDIS::DATA_TYPE::ENUMS::ArticulatedPartsMetric M, KFLOAT32 Value );

    ArticulatedPart( KUINT8 ParamChangeIndicator, KUINT16 AttachID, KUINT32 TypeVariant, KFLOAT32 Value );

    virtual ~ArticulatedPart();

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulatedPart::SetParameterChangeIndicator
    //              KDIS::DATA_TYPE::ArticulatedPart::GetParameterChangeIndicator
    // Description: Stores change to any articulated part. Set to 0 at sim start and incremented
    //              each time a change occurs, if value > 255 it should be set back to 0.
    // Parameter:   KUINT8 PCI
    //************************************
    void SetParameterChangeIndicator( KUINT8 PCI );
    KUINT8 GetParameterChangeIndicator() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulatedPart::SetAttachementID
    //              KDIS::DATA_TYPE::ArticulatedPart::GetAttachementID
    // Description: ID field of the articulated part to which the articulation parameter
    //              is attached. Field shall be 0 if the part is attached directly
    //              to the entity.
    // Parameter:   KUINT16 ID
    //************************************
    void SetAttachementID( KUINT16 ID );
    KUINT16 GetAttachementID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulatedPart::SetTypeVariantClass
    //              KDIS::DATA_TYPE::ArticulatedPart::GetTypeVariantClass
    // Description: Identifies a particular articulated part on a given entity type.
    // Parameter:   ArticulatedPartsClass C
    //************************************
    void SetTypeVariantClass( KDIS::DATA_TYPE::ENUMS::ArticulatedPartsClass C );
    KDIS::DATA_TYPE::ENUMS::ArticulatedPartsClass GetTypeVariantClass() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulatedPart::SetTypeVariantMetric
    //              KDIS::DATA_TYPE::ArticulatedPart::GetTypeVariantMetric
    // Description: Identifies the transformation to be applied to the articulated part.
    //              Recommended type of metric:
    //			       Horizontal control surfaces  -  Elevation
    //                 Vertical control surfaces    -  Azimuth
    //                 Extendible items             -  Extension
    //                 Fixed path items             -  Position
    //                 Turrets                      -  Azimuth
    //                 Guns                         -  Elevation
    //                 Movable missile launcher     -  Azimuth and elevation
    // Parameter:   ArticulatedPartsMetric M
    //************************************
    void SetTypeVariantMetric( KDIS::DATA_TYPE::ENUMS::ArticulatedPartsMetric M );
    KDIS::DATA_TYPE::ENUMS::ArticulatedPartsMetric GetTypeVariantMetric() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulatedPart::SetTypeVariant
    //              KDIS::DATA_TYPE::ArticulatedPart::GetTypeVariant
    // Description: TV = Metric + Class.
    // Parameter:   KUINT32 TV
    //************************************
    void SetTypeVariant( KUINT32 TV );
    KUINT32 GetTypeVariant() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulatedPart::SetValue
    //              KDIS::DATA_TYPE::ArticulatedPart::GetValue
    // Description: Value.
    // Parameter:   KFLOAT32 val
    //************************************
    void SetValue( KFLOAT32 val );
    KFLOAT32 GetValue() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulatedPart::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulatedPart::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArticulatedPart::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const ArticulatedPart & Value ) const;
    KBOOL operator != ( const ArticulatedPart & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
