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

#include "./ExplosionDescriptor.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

ExplosionDescriptor::ExplosionDescriptor() :
	m_ui16ExplMat( 0 ),
	m_ui16Padding( 0 ),
	m_f32ExplForce( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

ExplosionDescriptor::ExplosionDescriptor( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

ExplosionDescriptor::ExplosionDescriptor( const EntityType & T, ExplosiveMaterial EM, KFLOAT32 Force ) :
    Descriptor( T ),
	m_ui16ExplMat( EM ),
	m_ui16Padding( 0 ),
	m_f32ExplForce( Force )
{
}

//////////////////////////////////////////////////////////////////////////

ExplosionDescriptor::~ExplosionDescriptor()
{
}

//////////////////////////////////////////////////////////////////////////

void ExplosionDescriptor::SetExplosiveMaterial( ExplosiveMaterial EM )
{
	m_ui16ExplMat = EM;
}

//////////////////////////////////////////////////////////////////////////

ExplosiveMaterial ExplosionDescriptor::GetExplosiveMaterial() const
{
	return ( ExplosiveMaterial )m_ui16ExplMat;
}

//////////////////////////////////////////////////////////////////////////

void ExplosionDescriptor::SetExplosiveForce( KFLOAT32 F )
{
	m_f32ExplForce = F;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 ExplosionDescriptor::GetExplosiveForce() const
{
	return m_f32ExplForce;
}

//////////////////////////////////////////////////////////////////////////

KString ExplosionDescriptor::GetAsString() const
{
    KStringStream ss;

    ss << "Descriptor:"
       << "\n\tType:     " << m_Type.GetAsString()
       << "\tMaterial: "   << GetEnumAsStringExplosiveMaterial( m_ui16ExplMat )
       << "\n\tForce:    " << m_f32ExplForce       
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ExplosionDescriptor::Decode( KDataStream & stream ) throw( KException )
{
	Descriptor::Decode( stream );

    stream >> m_ui16ExplMat
           >> m_ui16Padding
           >> m_f32ExplForce;           
}

//////////////////////////////////////////////////////////////////////////

KDataStream ExplosionDescriptor::Encode() const
{
    KDataStream stream;

    ExplosionDescriptor::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ExplosionDescriptor::Encode( KDataStream & stream ) const
{
	Descriptor::Encode( stream );

    stream << m_ui16ExplMat
           << m_ui16Padding
           << m_f32ExplForce; 
}

//////////////////////////////////////////////////////////////////////////

KBOOL ExplosionDescriptor::operator == ( const ExplosionDescriptor & Value ) const
{
	if( Descriptor::operator != ( Value ) )            return false;
    if( m_ui16ExplMat        != Value.m_ui16ExplMat )  return false;
    if( m_f32ExplForce       != Value.m_f32ExplForce ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ExplosionDescriptor::operator != ( const ExplosionDescriptor & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


