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
    class:      MinePaintScheme
    created:    13/06/2010
    author:     Karl Jones

    purpose:    Represents the Paint Scheme of a mine.
    size:       8 bits / 1 octet
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT MinePaintScheme : public DataTypeBase
{
protected:

    union
    {
        struct
        {
            KUINT8 m_ui8Alg : 2;
            KUINT8 m_ui8Scm : 6;
        };

        KUINT8 m_ui8PntSchm;
    } m_PntScmUnion;

public:

    static const KUINT16 MINE_PAINT_SCHEME_SIZE = 1;

    MinePaintScheme();

    MinePaintScheme( KDIS::DATA_TYPE::ENUMS::MineAlgae A, KDIS::DATA_TYPE::ENUMS::PaintScheme PS );

    MinePaintScheme( KDataStream & stream ) throw( KException );

    virtual ~MinePaintScheme();

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinePaintScheme::SetAlgae
    //              KDIS::DATA_TYPE::MinePaintScheme::GetAlgae
    // Description: The algae build-up on the mine.
    // Parameter:   MineAlgae A
    //************************************
    void SetAlgae( KDIS::DATA_TYPE::ENUMS::MineAlgae A );
    KDIS::DATA_TYPE::ENUMS::MineAlgae GetAlgae() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinePaintScheme::SetPaintScheme
    //              KDIS::DATA_TYPE::MinePaintScheme::GetPaintScheme
    // Description: The paint scheme of the mine.
    // Parameter:   PaintScheme PS
    //************************************
    void SetPaintScheme( KDIS::DATA_TYPE::ENUMS::PaintScheme PS );
    KDIS::DATA_TYPE::ENUMS::PaintScheme GetPaintScheme() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinePaintScheme::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinePaintScheme::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinePaintScheme::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const MinePaintScheme & Value ) const;
    KBOOL operator != ( const MinePaintScheme & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

