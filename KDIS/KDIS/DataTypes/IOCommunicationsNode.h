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

using KDIS::DATA_TYPE::ENUMS::IOCommunicationsNodeType;

class KDIS_EXPORT IOCommunicationsNode : public StandardVariable
{
protected:

    KUINT8 m_ui8CommNodeTyp;

    KUINT8 m_ui8Padding;

    CommunicationsNodeID m_CommID;

public:

    static const KUINT16 IO_COMMUNICATIONS_NODE_SIZE = 16;

    IOCommunicationsNode( void );

    IOCommunicationsNode( KDataStream & stream ) throw( KException );

    IOCommunicationsNode( IOCommunicationsNodeType T, const CommunicationsNodeID & ID );

    virtual ~IOCommunicationsNode( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::IOCommunicationsNode::SetIOCommunicationsNodeType
    //              KDIS::DATA_TYPE::IOCommunicationsNode::GetIOCommunicationsNodeType
    // Description: The type of communication node.
    // Parameter:   IOCommunicationsNodeType T
    //************************************
    void SetIOCommunicationsNodeType( IOCommunicationsNodeType T );
    IOCommunicationsNodeType GetIOCommunicationsNodeType() const;

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS
