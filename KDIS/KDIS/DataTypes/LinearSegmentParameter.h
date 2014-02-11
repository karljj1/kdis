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
    class:      LinearSegmentParameter
    created:    15/03/2010
    author:     Karl Jones

    purpose:    The specification of an individual segment of a linear
                segment synthetic environment object.
    size:       448 bits / 56 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./LinearObjectAppearance.h"
#include "./WorldCoordinates.h"
#include "./EulerAngles.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT LinearSegmentParameter : public DataTypeBase
{
protected:

    KUINT8 m_ui8SegNum;

    union
    {
        struct
        {
            KUINT8 m_ui8LocBit : 1;
            KUINT8 m_ui8OriBit : 1;
            KUINT8 m_ui8Unused : 6;
        };

        KUINT8 m_ui8Modifications;
    } m_ModificationUnion;

    LinearObjectAppearance m_ObjApr;

    WorldCoordinates m_Loc;

    EulerAngles m_Ori;

    KUINT16 m_ui16Length;

    KUINT16 m_ui16Width;

    KUINT16 m_ui16Height;

    KUINT16 m_ui16Depth;

    KUINT32 m_ui32Padding;

public:

    static const KUINT16 LINEAR_SEGMENT_PARAMETER_SIZE = 56;

    LinearSegmentParameter();

    LinearSegmentParameter( KDataStream & stream )throw( KException );

    LinearSegmentParameter( KUINT8 SegNum, KUINT8 Mod, const LinearObjectAppearance & A,
                            const WorldCoordinates & Loc, const EulerAngles & Ori,
                            KUINT16 Length, KUINT16 Width, KUINT16 Height, KUINT16 Depth );

    virtual ~LinearSegmentParameter();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearSegmentParameter::SetLinearSegmentParameterType
    //              KDIS::DATA_TYPE::LinearSegmentParameter::GetLinearSegmentParameterType
    // Description: Identifies the individual segment of the linear segment.
    // Parameter:   LinearSegmentParameterType T, void
    //************************************
    void SetSegmentNumber( KUINT8 N );
    KUINT8 GetSegmentNumber() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearSegmentParameter::SetModification
    //              KDIS::DATA_TYPE::LinearSegmentParameter::GetModification
    //              KDIS::DATA_TYPE::LinearSegmentParameter::SetModificationLocation
    //              KDIS::DATA_TYPE::LinearSegmentParameter::IsModificationLocation
    //              KDIS::DATA_TYPE::LinearSegmentParameter::SetModificationOrientation
    //              KDIS::DATA_TYPE::LinearSegmentParameter::IsModificationOrientation
    // Description: Identifies whether a modification has been made to the segment's
    //              location or orientation. Modification is represented by a single 8 bit unsigned int, where
    //              bit 0 is the location modified flag and bit 1 is the orientation flag. A value of 1(true)
    //              indicates the field has been changed.
    //              You can also set these values using SetModificationLocation and SetModificationOrientation.
    //              All values are set to false(0) by default.
    // Parameter:   KUINT8 M, KBOOL M = true
    //************************************
    void SetModification( KUINT8 M );
    KUINT8 GetModification() const;
    void SetModificationLocation( KBOOL M = true );
    KBOOL IsModificationLocation() const;
    void SetModificationOrientation( KBOOL M = true );
    KBOOL IsModificationOrientation() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearSegmentParameter::SetLinearObjectAppearance
    //              KDIS::DATA_TYPE::LinearSegmentParameter::GetLinearObjectAppearance
    // Description: The dynamic appearance attributes of the segment.
    // Parameter:   const LinearObjectAppearance & L , void
    //************************************
    void SetLinearObjectAppearance( const LinearObjectAppearance & L );
    const LinearObjectAppearance & GetLinearObjectAppearance() const;
    LinearObjectAppearance & GetLinearObjectAppearance();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearSegmentParameter::SetLocation
    //              KDIS::DATA_TYPE::LinearSegmentParameter::GetLocation
    // Description: The location of the linear segment.
    // Parameter:   const WorldCoordinates & L , void
    //************************************
    void SetLocation( const WorldCoordinates & L );
    const WorldCoordinates & GetLocation() const;
    WorldCoordinates & GetLocation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearSegmentParameter::SetLocation
    //              KDIS::DATA_TYPE::LinearSegmentParameter::GetLocation
    // Description: The orientation of the linear segment about the segment location.
    // Parameter:   const EulerAngles & O , void
    //************************************
    void SetOrientation( const EulerAngles & O );
    const EulerAngles & GetOrientation() const;
    EulerAngles & GetOrientation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearSegmentParameter::SetLength
    //              KDIS::DATA_TYPE::LinearSegmentParameter::GetLength
    // Description: The length of the linear segment, in meters, extending in the positive X direction.
    // Parameter:   KUINT16 L , void
    //************************************
    void SetLength( KUINT16 L );
    KUINT16 GetLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearSegmentParameter::SetWidth
    //              KDIS::DATA_TYPE::LinearSegmentParameter::GetWidth
    // Description: The total width of the linear segment, in meters. One-half of the width shall extend
    //              in the positive Y direction, and one-half of the width shall extend
    //              in the negative Y direction.
    // Parameter:   KUINT16 W , void
    //************************************
    void SetWidth( KUINT16 W );
    KUINT16 GetWidth() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearSegmentParameter::SetHeight
    //              KDIS::DATA_TYPE::LinearSegmentParameter::GetHeight
    // Description: The height of the linear segment, in meters, above ground level.
    // Parameter:   KUINT16 H , void
    //************************************
    void SetHeight( KUINT16 H );
    KUINT16 GetHeight() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearSegmentParameter::SetDepth
    //              KDIS::DATA_TYPE::LinearSegmentParameter::GetDepth
    // Description: The depth of the linear segment, in meters, below ground level.
    // Parameter:   KUINT16 D , void
    //************************************
    void SetDepth( KUINT16 D );
    KUINT16 GetDepth() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearSegmentParameter::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearSegmentParameter::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LinearSegmentParameter::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const LinearSegmentParameter & Value ) const;
    KBOOL operator != ( const LinearSegmentParameter & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
