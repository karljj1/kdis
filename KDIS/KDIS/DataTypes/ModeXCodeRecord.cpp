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

#include "./ModeXCodeRecord.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

ModeXCodeRecord::ModeXCodeRecord() 
{
	m_CodeUnion.m_ui16Code = 0;
}

//////////////////////////////////////////////////////////////////////////

ModeXCodeRecord::ModeXCodeRecord( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

ModeXCodeRecord::~ModeXCodeRecord()
{
}

//////////////////////////////////////////////////////////////////////////

void ModeXCodeRecord::SetStatus( KBOOL S )
{
	m_CodeUnion.m_ui16OnOff = S;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeXCodeRecord::GetStatus() const
{
	return ( KBOOL )m_CodeUnion.m_ui16OnOff;
}

//////////////////////////////////////////////////////////////////////////

void ModeXCodeRecord::SetDamaged( KBOOL D )
{
	m_CodeUnion.m_ui16Dmg = D;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeXCodeRecord::IsDamaged() const
{
	return ( KBOOL )m_CodeUnion.m_ui16Dmg;
}

//////////////////////////////////////////////////////////////////////////

void ModeXCodeRecord::SetMalfunctioning( KBOOL M )
{
	m_CodeUnion.m_ui16MalFnc = M;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeXCodeRecord::IsMalfunctioning() const
{
	return ( KBOOL )m_CodeUnion.m_ui16MalFnc;
}

//////////////////////////////////////////////////////////////////////////

KString ModeXCodeRecord::GetAsString() const
{
    KStringStream ss;

	ss << "On/Off Status:       " << ( KBOOL )m_CodeUnion.m_ui16OnOff << "\n"
	   << "Damage Status:       " << ( KBOOL )m_CodeUnion.m_ui16Dmg   << "\n"
	   << "Malfunction Status:  " << ( KBOOL )m_CodeUnion.m_ui16MalFnc << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ModeXCodeRecord::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < MODE_X_CODE_RECORD_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );
	stream >> m_CodeUnion.m_ui16Code;
}

//////////////////////////////////////////////////////////////////////////

KDataStream ModeXCodeRecord::Encode() const
{
    KDataStream stream;

    ModeXCodeRecord::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ModeXCodeRecord::Encode( KDataStream & stream ) const
{
	stream << m_CodeUnion.m_ui16Code;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeXCodeRecord::operator == ( const ModeXCodeRecord & Value ) const
{ 
    if( m_CodeUnion.m_ui16Code != Value.m_CodeUnion.m_ui16Code ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ModeXCodeRecord::operator != ( const ModeXCodeRecord & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
