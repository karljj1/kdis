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

using KDIS::DATA_TYPE::ENUMS::MineAlgae;
using KDIS::DATA_TYPE::ENUMS::PaintScheme;

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

    MinePaintScheme( void );

    MinePaintScheme( MineAlgae A, PaintScheme PS );

    MinePaintScheme( KDataStream & stream ) throw( KException );

    virtual ~MinePaintScheme( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinePaintScheme::SetAlgae
    //              KDIS::DATA_TYPE::MinePaintScheme::GetAlgae
    // Description: The algae build-up on the mine.
    // Parameter:   MineAlgae A
    //************************************
    void SetAlgae( MineAlgae A );
    MineAlgae GetAlgae() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinePaintScheme::SetPaintScheme
    //              KDIS::DATA_TYPE::MinePaintScheme::GetPaintScheme
    // Description: The paint scheme of the mine.
    // Parameter:   PaintScheme PS
    //************************************
    void SetPaintScheme( PaintScheme PS );
    PaintScheme GetPaintScheme() const;

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS

