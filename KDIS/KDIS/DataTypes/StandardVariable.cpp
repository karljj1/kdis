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

StandardVariable::StandardVariable( void ) :
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

StandardVariable::~StandardVariable( void )
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
		case IOCommunicationsNodeRecord : return new IOCommunicationsNode( stream );
		case IOEffectRecord             : return new IOEffect( stream );
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
