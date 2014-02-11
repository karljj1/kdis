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

    PositionError();

    PositionError( KFIXED16_8 Horizontal, KFIXED16_8 Vertical );

    PositionError( KDataStream & stream ) throw( KException );

    virtual ~PositionError();

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

} // END namespace DATA_TYPES
} // END namespace KDIS

