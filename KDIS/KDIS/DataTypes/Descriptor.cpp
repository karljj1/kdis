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

#include "./Descriptor.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Descriptor::Descriptor() 
{
}

//////////////////////////////////////////////////////////////////////////

Descriptor::Descriptor( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Descriptor::Descriptor( const EntityType & T ) :
    m_Type( T )
{
}

//////////////////////////////////////////////////////////////////////////

Descriptor::~Descriptor()
{
}

//////////////////////////////////////////////////////////////////////////

void Descriptor::SetType( const EntityType & T )
{
    m_Type = T;
}

//////////////////////////////////////////////////////////////////////////

const EntityType & Descriptor::GetType() const
{
    return m_Type;
}

//////////////////////////////////////////////////////////////////////////

EntityType & Descriptor::GetType()
{
    return m_Type;
}

//////////////////////////////////////////////////////////////////////////

KString Descriptor::GetAsString() const
{
    KStringStream ss;

    ss << "Descriptor:"
       << "\n\tType: " << m_Type.GetAsString()
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Descriptor::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < DESCRIPTOR_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> KDIS_STREAM m_Type;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Descriptor::Encode() const
{
    KDataStream stream;

    Descriptor::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Descriptor::Encode( KDataStream & stream ) const
{
    stream << KDIS_STREAM m_Type;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Descriptor::operator == ( const Descriptor & Value ) const
{
    if( m_Type != Value.m_Type ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Descriptor::operator != ( const Descriptor & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


