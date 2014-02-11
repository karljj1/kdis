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
    class:      CommunicationsNodeID
    created:    04/12/2010
    author:     Karl Jones

    purpose:    The identification of a communications node is conveyed using
                the Communications Node ID record.
                The combination of Entity ID and Element ID uniquely identify
                an IO communications node within a simulation exercise.

    size:       64 bits / 8 octets
*********************************************************************/

#pragma once

#include "./EntityIdentifier.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT CommunicationsNodeID : public EntityIdentifier
{
protected:

    KUINT16 m_ui16ElementID;

public:

    static const KUINT16 COMMUNICATIONS_NODE_ID_SIZE = 8;

    CommunicationsNodeID();

    CommunicationsNodeID( KDataStream & stream ) throw( KException );

    CommunicationsNodeID( KUINT16 Site, KUINT16 App, KUINT16 Obj, KUINT16 Element );

    CommunicationsNodeID( const SimulationIdentifier & SimID, KUINT16 Obj, KUINT16 Element );

    CommunicationsNodeID( const EntityIdentifier & EntID, KUINT16 Element );

    virtual ~CommunicationsNodeID();

    //************************************
    // FullName:    KDIS::DATA_TYPE::CommunicationsNodeID::SetElementID
    //              KDIS::DATA_TYPE::CommunicationsNodeID::GetElementID
    // Description: Identifies a particular communications element (e.g. radio,
    //              network component, or modem) within a given entity.
    //              If this element is a radio for which a Transmitter PDU
    //              is being issued, this value shall correspond to the Radio
    //              ID in that PDU.
    // Parameter:   KUINT16 ID, void
    //************************************
    void SetElementID( KUINT16 ID );
    KUINT16 GetElementID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::CommunicationsNodeID::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::CommunicationsNodeID::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::CommunicationsNodeID::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const CommunicationsNodeID & Value ) const;
    KBOOL operator != ( const CommunicationsNodeID & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
