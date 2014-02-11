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
    class:      LE_EntityIdentifier
    created:    30/06/2010
    author:     Karl Jones

    purpose:    Entity Identifier Field found in Live Entity (LE) PDU's.
                The site and application id's have been reduced to 8 bits from 16.

    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT LE_EntityIdentifier : public DataTypeBase
{
protected:

    KUINT8 m_ui8SiteID;

    KUINT8 m_ui8ApplicationID;

    KUINT16 m_ui16EntityID;

public:

    static const KUINT16 LE_ENTITY_IDENTIFER_SIZE = 4;

    LE_EntityIdentifier();

    LE_EntityIdentifier( KUINT8 SiteID, KUINT8 ApplicatonID, KUINT16 EntityID );

    LE_EntityIdentifier( KDataStream & stream ) throw( KException );

    virtual ~LE_EntityIdentifier();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_EntityIdentifier::SetSiteID
    //              KDIS::DATA_TYPE::LE_EntityIdentifier::GetSiteID
    // Description: Site ID for Live Entity EntityIdentifier's.
    // Parameter:   KUINT8 ID
    //************************************
    void SetSiteID( KUINT8 ID );
    KUINT8 GetSiteID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_EntityIdentifier::SetApplicationID
    //              KDIS::DATA_TYPE::LE_EntityIdentifier::GetApplicationID
    // Description: Application ID for Live Entity EntityIdentifier's.
    // Parameter:   KUINT8 ID
    //************************************
    void SetApplicationID( KUINT8 ID );
    KUINT8 GetApplicationID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_EntityIdentifier::SetEntityID
    //              KDIS::DATA_TYPE::LE_EntityIdentifier::GetEntityID
    // Description: Entity ID, also known as Object ID, Process Numbers and
    //              Reference Number in DIS version 7.
    // Parameter:   KUINT16 ID
    //************************************
    void SetEntityID( KUINT16 ID );
    KUINT16 GetEntityID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_EntityIdentifier::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_EntityIdentifier::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LE_EntityIdentifier::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const LE_EntityIdentifier & Value ) const;
    KBOOL operator != ( const LE_EntityIdentifier & Value ) const;
    KBOOL operator <  ( const LE_EntityIdentifier & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

