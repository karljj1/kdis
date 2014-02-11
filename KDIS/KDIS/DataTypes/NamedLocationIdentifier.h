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
    class:      NamedLocationIdentifier
    created:    27/06/2008
    author:     Karl Jones

    purpose:    Contaiins information about the discrete positional relationship of the part
                entity with respect to the its host entity.
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT NamedLocationIdentifier : public DataTypeBase
{
protected:

    KUINT16 m_ui16StnName;

    KUINT16 m_ui16StnNum;

public:

    static const KUINT16 NAMED_LOCATION_ID_SIZE = 4;

    NamedLocationIdentifier();

    NamedLocationIdentifier( KDataStream & stream )throw( KException );

    NamedLocationIdentifier( KDIS::DATA_TYPE::ENUMS::StationName SN,  KUINT16 StationNumber );

    virtual ~NamedLocationIdentifier();

    //************************************
    // FullName:    KDIS::DATA_TYPE::NamedLocationIdentifier::SetStationName
    //              KDIS::DATA_TYPE::NamedLocationIdentifier::GetStationName
    // Description: Specifies the station name within the host at which the part entity
    //              is located. If the part entity is On Station, this field shall
    //              specify the representation of the part’s location data fields.
    // Parameter:   StationName SN
    //************************************
    void SetStationName( KDIS::DATA_TYPE::ENUMS::StationName SN );
    KDIS::DATA_TYPE::ENUMS::StationName GetStationName() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::NamedLocationIdentifier::SetStationNumber
    //              KDIS::DATA_TYPE::NamedLocationIdentifier::GetStationNumber
    // Description: Specifies the number of the particular wingstation, cargo hold etc, at
    //              which the part is attached.
    // Parameter:   KUINT16 SN
    //************************************
    void SetStationNumber( KUINT16 SN );
    KUINT16 GetStationNumber() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::NamedLocationIdentifier::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::NamedLocationIdentifier::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::NamedLocationIdentifier::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const NamedLocationIdentifier & Value ) const;
    KBOOL operator != ( const NamedLocationIdentifier & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
