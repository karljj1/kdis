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

#include "./IOCommunicationsNode.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

IOCommunicationsNode::IOCommunicationsNode() :
    m_ui8CommNodeTyp( 0 ),
    m_ui8Padding( 0 )
{
    m_ui32Type = IOCommunicationsNodeRecord;
    m_ui16Length = IO_COMMUNICATIONS_NODE_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IOCommunicationsNode::IOCommunicationsNode( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

IOCommunicationsNode::IOCommunicationsNode( IOCommunicationsNodeType T, const CommunicationsNodeID & ID ) :
    m_ui8CommNodeTyp( T ),
    m_ui8Padding( 0 ),
    m_CommID( ID )
{
    m_ui32Type = IOCommunicationsNodeRecord;
    m_ui16Length = IO_COMMUNICATIONS_NODE_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IOCommunicationsNode::~IOCommunicationsNode()
{
}

//////////////////////////////////////////////////////////////////////////

void IOCommunicationsNode::SetIOCommunicationsNodeType( IOCommunicationsNodeType T )
{
    m_ui8CommNodeTyp = T;
}

//////////////////////////////////////////////////////////////////////////

IOCommunicationsNodeType IOCommunicationsNode::GetIOCommunicationsNodeType() const
{
    return ( IOCommunicationsNodeType )m_ui8CommNodeTyp;
}

//////////////////////////////////////////////////////////////////////////

void IOCommunicationsNode::SetCommunicationsNodeID( const CommunicationsNodeID & ID )
{
    m_CommID = ID;
}

//////////////////////////////////////////////////////////////////////////

const CommunicationsNodeID & IOCommunicationsNode::GetCommunicationsNodeID() const
{
    return m_CommID;
}

//////////////////////////////////////////////////////////////////////////

CommunicationsNodeID & IOCommunicationsNode::GetCommunicationsNodeID()
{
    return m_CommID;
}

//////////////////////////////////////////////////////////////////////////

KString IOCommunicationsNode::GetAsString() const
{
    KStringStream ss;

    ss << StandardVariable::GetAsString()
       << "Node Type: " << GetEnumAsStringIOCommunicationsNodeType( m_ui8CommNodeTyp ) << "\n"
       << m_CommID.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void IOCommunicationsNode::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < STANDARD_VARIABLE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    StandardVariable::Decode( stream );

    stream >> m_ui8CommNodeTyp
           >> m_ui8Padding
           >> KDIS_STREAM m_CommID;
}

//////////////////////////////////////////////////////////////////////////

KDataStream IOCommunicationsNode::Encode() const
{
    KDataStream stream;

    IOCommunicationsNode::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void IOCommunicationsNode::Encode( KDataStream & stream ) const
{
    StandardVariable::Encode( stream );

    stream << m_ui8CommNodeTyp
           << m_ui8Padding
           << KDIS_STREAM m_CommID;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IOCommunicationsNode::operator == ( const IOCommunicationsNode & Value ) const
{
    if( StandardVariable::operator  !=( Value ) )               return false;
    if( m_ui8CommNodeTyp            != Value.m_ui8CommNodeTyp ) return false;
    if( m_CommID                    != Value.m_CommID )         return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IOCommunicationsNode::operator != ( const IOCommunicationsNode & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
