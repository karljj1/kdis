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

#include "./DEAreaAimpoint.h"


//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

DEAreaAimpoint::DEAreaAimpoint() :
	m_ui16Padding( 0 ),
	m_ui16BAPRC( 0 ),
	m_ui16DETEDRC( 0 )
{
	m_ui32Type = DEAreaAimpointRecord;
}

//////////////////////////////////////////////////////////////////////////

DEAreaAimpoint::DEAreaAimpoint( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

DEAreaAimpoint::~DEAreaAimpoint()
{
}

//////////////////////////////////////////////////////////////////////////

KUINT16 DEAreaAimpoint::GetBeamAntennaPatternCount() const
{
	return m_ui16BAPRC;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 DEAreaAimpoint::GetTargetEnergyDepositionCount() const
{
	return m_ui16DETEDRC;
}

//////////////////////////////////////////////////////////////////////////

KString DEAreaAimpoint::GetAsString() const
{
    KStringStream ss;

    //ss << "Standard Variable:"
    //   << "\n\tType:    " << GetEnumAsStringStandardVariableType( m_ui32Type )
    //   << "\n\tLength:  " << m_ui16Length
    //   << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void DEAreaAimpoint::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < STANDARD_VARIABLE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    //stream >> m_ui32Type
    //       >> m_ui16Length;
}

//////////////////////////////////////////////////////////////////////////

KDataStream DEAreaAimpoint::Encode() const
{
    KDataStream stream;

    DEAreaAimpoint::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void DEAreaAimpoint::Encode( KDataStream & stream ) const
{
    //stream << m_ui32Type
    //       << m_ui16Length;
}

//////////////////////////////////////////////////////////////////////////

KBOOL DEAreaAimpoint::operator == ( const DEAreaAimpoint & Value ) const
{
    //if( m_ui32Type   != Value.m_ui32Type )   return false;
    //if( m_ui16Length != Value.m_ui16Length ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL DEAreaAimpoint::operator != ( const DEAreaAimpoint & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
