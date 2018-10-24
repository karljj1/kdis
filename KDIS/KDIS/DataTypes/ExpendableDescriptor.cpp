/*********************************************************************
Copyright 2018 Karl Jones
               Todd Klasik
               GBL Systems Corporation
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

#include "./ExpendableDescriptor.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

ExpendableDescriptor::ExpendableDescriptor() :
    m_ui64Padding(0)
{
}

//////////////////////////////////////////////////////////////////////////

ExpendableDescriptor::ExpendableDescriptor( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

ExpendableDescriptor::ExpendableDescriptor( const EntityType & T) :
    Descriptor( T ),
    m_ui64Padding(0)
{
}

//////////////////////////////////////////////////////////////////////////

ExpendableDescriptor::~ExpendableDescriptor()
{
}

//////////////////////////////////////////////////////////////////////////

void ExpendableDescriptor::Decode( KDataStream & stream ) throw( KException )
{
	Descriptor::Decode( stream );

    stream >> m_ui64Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream ExpendableDescriptor::Encode() const
{
    KDataStream stream;

    ExpendableDescriptor::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ExpendableDescriptor::Encode( KDataStream & stream ) const
{
	Descriptor::Encode( stream );

    stream << m_ui64Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ExpendableDescriptor::operator == ( const ExpendableDescriptor & Value ) const
{
	if( Descriptor::operator != ( Value ) )            return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ExpendableDescriptor::operator != ( const ExpendableDescriptor & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


