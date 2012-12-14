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
    class:      PositionError
    created:    21/07/2010
    author:     Karl Jones

    purpose:    The error components that are associated with the location
                measurement for an entity. These errors are measured in
                entity-centered tangent planes.
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./KFIXED.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT PositionError : public DataTypeBase
{
protected:

    KFIXED16_8 m_HorzErr;

    KFIXED16_8 m_VertErr;

public:

    static const KUINT16 POSITION_ERROR_SIZE = 4;

    PositionError( void );

    PositionError( KFIXED16_8 Horizontal, KFIXED16_8 Vertical );

    PositionError( KDataStream & stream ) throw( KException );

    virtual ~PositionError( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::PositionError::SetHorizontalError
    //              KDIS::DATA_TYPE::PositionError::GetHorizontalError
    // Description: The error components that are associated with the
    //              location measurement  for an entity. These errors
    //              are measured in entity-centered tangent planes.
    // Parameter:   KFIXED16_8 HE
    //************************************
    void SetHorizontalError( KFIXED16_8 HE );
    KFIXED16_8 GetHorizontalError() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::PositionError::SetVerticalError
    //              KDIS::DATA_TYPE::PositionError::GetVerticalError
    // Description: The error components that are associated with the
    //              location measurement  for an entity. These errors
    //              are measured in entity-centered tangent planes.
    // Parameter:   KFIXED16_8 VE
    //************************************
    void SetVerticalError( KFIXED16_8 VE );
    KFIXED16_8 GetVerticalError() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::PositionError::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::DataTypeBase::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::PositionError::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const PositionError & Value ) const;
    KBOOL operator != ( const PositionError & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

