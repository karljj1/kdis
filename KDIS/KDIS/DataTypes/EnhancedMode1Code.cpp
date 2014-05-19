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

#include "./EnhancedMode1Code.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

EnhancedMode1Code::EnhancedMode1Code() 
{
	m_CodeUnion.m_ui16Code = 0;
}

//////////////////////////////////////////////////////////////////////////

EnhancedMode1Code::EnhancedMode1Code( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

EnhancedMode1Code::~EnhancedMode1Code()
{
}

//////////////////////////////////////////////////////////////////////////

void EnhancedMode1Code::SetCodeElement1( KUINT8 CE )
{
	m_CodeUnion.m_ui16Bits0_2 = CE;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 EnhancedMode1Code::GetCodeElement1()
{
	return m_CodeUnion.m_ui16Bits0_2;
}
	
//////////////////////////////////////////////////////////////////////////

void EnhancedMode1Code::SetCodeElement2( KUINT8 CE )
{
	m_CodeUnion.m_ui16Bits3_5 = CE;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 EnhancedMode1Code::GetCodeElement2()
{
	return m_CodeUnion.m_ui16Bits3_5;
}
	
//////////////////////////////////////////////////////////////////////////

void EnhancedMode1Code::SetCodeElement3( KUINT8 CE )
{
	m_CodeUnion.m_ui16Bits6_8 = CE;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 EnhancedMode1Code::GetCodeElement3()
{
	return m_CodeUnion.m_ui16Bits6_8;
}

//////////////////////////////////////////////////////////////////////////
	
void EnhancedMode1Code::SetCodeElement4( KUINT8 CE )
{
	m_CodeUnion.m_ui16Bits9_11 = CE;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 EnhancedMode1Code::GetCodeElement4()
{
	return m_CodeUnion.m_ui16Bits9_11;
}

//////////////////////////////////////////////////////////////////////////

KString EnhancedMode1Code::GetAsString() const
{
    KStringStream ss;

    ss << "Enhanced Mode 1 Code: " << m_CodeUnion.m_ui16Bits9_11
		                           << m_CodeUnion.m_ui16Bits6_8 
								   << m_CodeUnion.m_ui16Bits3_5 
								   << m_CodeUnion.m_ui16Bits0_2 
								   << "\n"
	   << IndentString( ModeXCodeRecord::GetAsString(), 1 );
 
    return ss.str();
}

//////////////////////////////////////////////////////////////////////////