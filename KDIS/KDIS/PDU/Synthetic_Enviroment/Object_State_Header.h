/*********************************************************************
Copyright 2013 KDIS
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
    class:      Object_State_Header
    DIS:        (6) 1278.1a - 1998
    created:    07/12/2009
    author:     Karl Jones

    purpose:    Common attributes for point, linear and areal objects

    size:       216 bits / 27 octets
*********************************************************************/

#pragma once

#include "./../Header.h"
#include "./../../DataTypes/EntityIdentifier.h"

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::ENUMS::ForceID;

class KDIS_EXPORT Object_State_Header : public Header
{
protected:

    EntityIdentifier m_ObjID;

    EntityIdentifier m_RefObjID;

    KUINT16 m_ui16UpdateNum;

    KUINT8 m_ui8ForceID;

public:

    static const KUINT16 OBJECT_STATE_HEADER_SIZE = 27;

    Object_State_Header();

    Object_State_Header( KDataStream & stream ) throw( KException );

    Object_State_Header( const EntityIdentifier & ObjID, const EntityIdentifier & RefObjID ,
                         KUINT16 UpdateNum, ForceID FI );

    virtual ~Object_State_Header();

    //************************************
    // FullName:    KDIS::PDU::Object_State_Header::SetObjectID
    //              KDIS::PDU::Object_State_Header::GetObjectID
    // Description: The unique identification of the object in the SE.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetObjectID( const EntityIdentifier & ID );
    const EntityIdentifier & GetObjectID() const;
    EntityIdentifier & GetObjectID();

    //************************************
    // FullName:    KDIS::PDU::Object_State_Header::SetReferencedObjectID
    //              KDIS::PDU::Object_State_Header::GetReferencedObjectID
    // Description: The unique identification of the object with which this
    //              state object is associated with.
    // Parameter:   const EntityIdentifier & ID, void
    //************************************
    void SetReferencedObjectID( const EntityIdentifier & ID );
    const EntityIdentifier & GetReferencedObjectID() const;
    EntityIdentifier & GetReferencedObjectID();

    //************************************
    // FullName:    KDIS::PDU::Object_State_Header::SetUpdateNumber
    //              KDIS::PDU::Object_State_Header::GetUpdateNumber
    // Description: This field shall represent the unique update number, starting with 1,
    //              of each state transition of an individual object.
    // Parameter:   KUINT16 U, void
    //************************************
    void SetUpdateNumber( KUINT16 U );
    KUINT16 GetUpdateNumber() const;

    //************************************
    // FullName:    KDIS::PDU::Object_State_Header::SetForceID
    //              KDIS::PDU::Object_State_Header::GetForceID
    // Description: Identifies the force that created or modified the object.
    // Parameter:   ForceID ID, void
    //************************************
    void SetForceID( ForceID ID );
    ForceID GetForceID() const;

    //************************************
    // FullName:    KDIS::PDU::Object_State_Header::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Object_State_Header::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Object_State_Header::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Object_State_Header & Value ) const;
    KBOOL operator != ( const Object_State_Header & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
