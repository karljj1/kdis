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

#include "./StandardVariable.h"

// Implemented child classes used by the factory decode function.
#include "./IOCommunicationsNode.h"
#include "./IOEffect.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

StandardVariable::StandardVariable() :
    m_ui32Type( 0 ),
    m_ui16Length( STANDARD_VARIABLE_SIZE )
{
}

//////////////////////////////////////////////////////////////////////////

StandardVariable::StandardVariable( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

StandardVariable::~StandardVariable()
{
}

//////////////////////////////////////////////////////////////////////////

StandardVariableType StandardVariable::GetStandardVariableType() const
{
    return ( StandardVariableType )m_ui32Type;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 StandardVariable::GetRecordLength() const
{
    return m_ui16Length;
}

//////////////////////////////////////////////////////////////////////////

KString StandardVariable::GetAsString() const
{
    KStringStream ss;

    ss << "Standard Variable:"
       << "\n\tType:    " << GetEnumAsStringStandardVariableType( m_ui32Type )
       << "\n\tLength:  " << m_ui16Length
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

StdVarPtr StandardVariable::FactoryDecodeStandardVariable(  KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < STANDARD_VARIABLE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    // We want to peek at the next data and then roll back for a full decode.
    KUINT16 savePos = stream.GetCurrentWritePosition();

    // First decode the header so we can determine what type of record we are dealing with.
    StandardVariable recordHeader( stream );

    // Reset stream
    stream.SetCurrentWritePosition( savePos );

	// First check for a custom decoder.
	StandardVariable * p = FactoryDecode( recordHeader.GetStandardVariableType(), stream );

	if( p )
	{
		return StdVarPtr( p );
	}

	// Check for a KDIS implementation of the type.
    switch( recordHeader.GetStandardVariableType() )
    {
		case IOCommunicationsNodeRecord   : return new IOCommunicationsNode( stream );
		case IOEffectRecord               : return new IOEffect( stream );

		// TODO: DE Records
		//case DEPrecisionAimpointRecord        : return new IOEffect( stream );
		//case DEAreaAimpointRecord             : return new IOEffect( stream );
    }

    /*****************************************************************

    We could choose to ignore the record. To do so uncomment the following
    and comment out the exception throwing.

    // Move the buffer to the next readable data.
    stream.SetCurrentWritePosition( ui16SavePos + recordHeader.GetRecordLength() );
    return 0; // make sure the null ptr is handled.

    *****************************************************************/

    // We could not decode the StandardVariable child class. We will treat this as an error.	
	KStringStream ss;
	ss << "Unsupported StandardVariable type(" << recordHeader.GetStandardVariableType() << ").";
	throw KException( __FUNCTION__, UNSUPPORTED_DATATYPE, ss.str() );
}

//////////////////////////////////////////////////////////////////////////

void StandardVariable::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < STANDARD_VARIABLE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui32Type
           >> m_ui16Length;
}

//////////////////////////////////////////////////////////////////////////

KDataStream StandardVariable::Encode() const
{
    KDataStream stream;

    StandardVariable::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void StandardVariable::Encode( KDataStream & stream ) const
{
    stream << m_ui32Type
           << m_ui16Length;
}

//////////////////////////////////////////////////////////////////////////

KBOOL StandardVariable::operator == ( const StandardVariable & Value ) const
{
    if( m_ui32Type   != Value.m_ui32Type )   return false;
    if( m_ui16Length != Value.m_ui16Length ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL StandardVariable::operator != ( const StandardVariable & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
