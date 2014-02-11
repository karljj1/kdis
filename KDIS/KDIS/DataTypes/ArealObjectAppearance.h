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
    class:      ArealObjectAppearance
    created:    17/03/2010
    author:     Karl Jones

    purpose:    Represents a areal objects appearance.
    size:       48 Bits / 6 Octet
*********************************************************************/

#pragma once

#include "./ObjectAppearance.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT ArealObjectAppearance : public ObjectAppearance
{
protected:

    union
    {
        struct
        {
            KUINT32 m_ui32Breach : 2;
			KUINT32 m_ui32Unused : 14;
            KUINT32 m_ui32Mines  : 16;
        } m_Minefield;

        KUINT32 m_ui32SpecificAppearance;
    } m_SpecificAppearanceUnion;

public:

    static const KUINT16 AREAL_OBJECT_APPEARANCE_SIZE = 6;

    ArealObjectAppearance();

    ArealObjectAppearance( KDataStream & stream ) throw( KException );

    virtual ~ArealObjectAppearance();

    /************************************************************************/
    /* The following appearance values are only for areal's of the type:    */
    /*  Minefield                                                           */
    /************************************************************************/

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArealObjectAppearance::SetBreach
    //              KDIS::DATA_TYPE::ArealObjectAppearance::GetBreach
    // Description: Describes the breached appearance of the object.
    // Parameter:   Breach2bit B, void
    ////************************************
    void SetBreach( KDIS::DATA_TYPE::ENUMS::Breach2bit B );
    KDIS::DATA_TYPE::ENUMS::Breach2bit GetBreach() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArealObjectAppearance::SetMineCount
    //              KDIS::DATA_TYPE::ArealObjectAppearance::GetMineCount
    // Description: The number of mines in the minefield.
    // Parameter:   KUINT16 M, void
    //************************************
    void SetMineCount( KUINT16 M );
    KUINT16 GetMineCount() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArealObjectAppearance::GetAsString
    // Description: Returns a string representation of the appearance
    // Parameter:   const EntityType & EntType
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArealObjectAppearance::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ArealObjectAppearance::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const ArealObjectAppearance & Value ) const;
    KBOOL operator != ( const ArealObjectAppearance & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
