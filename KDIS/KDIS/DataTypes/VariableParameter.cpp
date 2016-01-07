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

#include "./VariableParameter.h"
#include <math.h>

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

VariableParameter::VariableParameter() :
    m_ui8VarParamType( 0 )    
{
	// Clear data
	memset( m_Data, 0, 15 );
}

//////////////////////////////////////////////////////////////////////////

VariableParameter::VariableParameter( VariableParameterType VPT, KUINT8 * Data, KUINT8 DataSize ) throw( KException ) :
	m_ui8VarParamType( VPT )
{
	SetData( Data, DataSize );
}

//////////////////////////////////////////////////////////////////////////

VariableParameter::VariableParameter( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

VariableParameter::~VariableParameter()
{
}

//////////////////////////////////////////////////////////////////////////

void VariableParameter::SetVariableParameterType( VariableParameterType VPT )
{
	m_ui8VarParamType = VPT;
}

//////////////////////////////////////////////////////////////////////////

VariableParameterType VariableParameter::GetVariableParameterType() const
{
	return ( VariableParameterType )m_ui8VarParamType;
}

//////////////////////////////////////////////////////////////////////////

void VariableParameter::SetData( const KUINT8 * D, KUINT8 DataSize ) throw( KException )
{
	if( DataSize > 15 )throw KException( __FUNCTION__, DATA_TYPE_TOO_LARGE );

	// Set
	memcpy( m_Data, D, DataSize );
		
	// Clear extra space
	if( DataSize < 15 )
		memset( m_Data, DataSize, 15 - DataSize );
}

//////////////////////////////////////////////////////////////////////////

const KUINT8 * VariableParameter::GetData() const
{
	return &m_Data[0];
}

//////////////////////////////////////////////////////////////////////////

KUINT8 * VariableParameter::GetData() 
{
	return &m_Data[0];
}

//////////////////////////////////////////////////////////////////////////

KString VariableParameter::GetAsString() const
{
    KStringStream ss;

    // For now we return the datum value as a string.
    ss << "Variable Parameter:"
       << "\n\tType:          " << GetEnumAsStringVariableParameterType( m_ui8VarParamType )
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void VariableParameter::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < VARIABLE_PARAMETER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

	stream >> m_ui8VarParamType;
		
	for( KUINT8 i = 0; i < 15; ++i )
	{
		stream >> m_Data[i];
	}
}

//////////////////////////////////////////////////////////////////////////

KDataStream VariableParameter::Encode() const
{
    KDataStream stream;

    VariableParameter::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void VariableParameter::Encode( KDataStream & stream ) const
{
	stream << m_ui8VarParamType;
		
	for( KUINT8 i = 0; i < 15; ++i )
	{
		stream << m_Data[i];
	}
}

//////////////////////////////////////////////////////////////////////////

KBOOL VariableParameter::operator == ( const VariableParameter & Value ) const
{
    if( m_ui8VarParamType != Value.m_ui8VarParamType ) return false;
    if( memcmp( m_Data, Value.m_Data, 15 ) != 0 ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL VariableParameter::operator != ( const VariableParameter & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

