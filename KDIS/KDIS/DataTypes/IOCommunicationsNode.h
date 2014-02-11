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
    class:      IOCommunicationsNode
    created:    21/11/2010
    author:     Karl Jones

    purpose:    Identifies a communications node entity that is part of a
                simulated communications network.
    size:       128 bits / 16 octets
*********************************************************************/

#pragma once

#include "./StandardVariable.h"
#include "./CommunicationsNodeID.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT IOCommunicationsNode : public StandardVariable
{
protected:

    KUINT8 m_ui8CommNodeTyp;

    KUINT8 m_ui8Padding;

    CommunicationsNodeID m_CommID;

public:

    static const KUINT16 IO_COMMUNICATIONS_NODE_SIZE = 16;

    IOCommunicationsNode();

    IOCommunicationsNode( KDataStream & stream ) throw( KException );

    IOCommunicationsNode( KDIS::DATA_TYPE::ENUMS::IOCommunicationsNodeType T, const CommunicationsNodeID & ID );

    virtual ~IOCommunicationsNode();

    //************************************
    // FullName:    KDIS::DATA_TYPE::IOCommunicationsNode::SetIOCommunicationsNodeType
    //              KDIS::DATA_TYPE::IOCommunicationsNode::GetIOCommunicationsNodeType
    // Description: The type of communication node.
    // Parameter:   IOCommunicationsNodeType T
    //************************************
    void SetIOCommunicationsNodeType( KDIS::DATA_TYPE::ENUMS::IOCommunicationsNodeType T );
    KDIS::DATA_TYPE::ENUMS::IOCommunicationsNodeType GetIOCommunicationsNodeType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IOCommunicationsNode::SetCommunicationsNodeID
    //              KDIS::DATA_TYPE::IOCommunicationsNode::GetCommunicationsNodeID
    // Description: The type of communication node.
    // Parameter:   const CommunicationsNodeID & ID
    //************************************
    void SetCommunicationsNodeID( const CommunicationsNodeID & ID );
    const CommunicationsNodeID & GetCommunicationsNodeID() const;
    CommunicationsNodeID & GetCommunicationsNodeID();

    //************************************
    // FullName:    KDIS::DATA_TYPE::IOCommunicationsNode::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::IOCommunicationsNode::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::IOCommunicationsNode::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const IOCommunicationsNode & Value ) const;
    KBOOL operator != ( const IOCommunicationsNode & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
