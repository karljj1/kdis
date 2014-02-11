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

#include "./Articulated_Parts_PDU.h"
#include "./../../DataTypes/ArticulatedPart.h"
#include "./../../DataTypes/AttachedPart.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace std;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Articulated_Parts_PDU::Articulated_Parts_PDU() :
    m_ui8NumOfVariableParams( 0 )
{
    m_ui8PDUType = ArticulatedParts_PDU_Type;
    m_ui16PDULength = ARTICULATED_PARTS_PDU_SIZE;
}
	
//////////////////////////////////////////////////////////////////////////

Articulated_Parts_PDU::Articulated_Parts_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Articulated_Parts_PDU::Articulated_Parts_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	LE_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Articulated_Parts_PDU::Articulated_Parts_PDU( const LE_EntityIdentifier & ID ) :
    m_ui8NumOfVariableParams( 0 )
{
    m_EntID = ID;
    m_ui8PDUType = ArticulatedParts_PDU_Type;
    m_ui16PDULength = ARTICULATED_PARTS_PDU_SIZE;
}


//////////////////////////////////////////////////////////////////////////

Articulated_Parts_PDU::~Articulated_Parts_PDU()
{
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Articulated_Parts_PDU::GetNumberOfVariableParams() const
{
    return m_ui8NumOfVariableParams;
}

//////////////////////////////////////////////////////////////////////////

void Articulated_Parts_PDU::AddVariableParameter( VarPrmPtr VP )
{
    m_vVariableParameters.push_back( VP );
    ++m_ui8NumOfVariableParams;
	m_ui16PDULength += VariableParameter::VARIABLE_PARAMETER_SIZE;
}

//////////////////////////////////////////////////////////////////////////

void Articulated_Parts_PDU::SetVariableParameters( const vector<VarPrmPtr> & VP )
{
    m_vVariableParameters = VP;
    m_ui8NumOfVariableParams = m_vVariableParameters.size();
    m_ui16PDULength = ARTICULATED_PARTS_PDU_SIZE + ( m_ui8NumOfVariableParams * VariableParameter::VARIABLE_PARAMETER_SIZE );
}

//////////////////////////////////////////////////////////////////////////

const vector<VarPrmPtr> & Articulated_Parts_PDU::GetVariableParameters() const
{
    return m_vVariableParameters;
}

//////////////////////////////////////////////////////////////////////////

void Articulated_Parts_PDU::ClearVariableParameters()
{
    m_vVariableParameters.clear();
    m_ui8NumOfVariableParams = 0;
    m_ui16PDULength = ARTICULATED_PARTS_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

KString Articulated_Parts_PDU::GetAsString() const
{
    KStringStream ss;

    ss << LE_Header::GetAsString()
       << "-Articulated Parts PDU-\n"
       << "Number Of Variable Params: " << ( KUINT16 )m_ui8NumOfVariableParams << "\n";

    // Variable params
    vector<VarPrmPtr>::const_iterator citr = m_vVariableParameters.begin();
    vector<VarPrmPtr>::const_iterator citrEnd = m_vVariableParameters.end();
    for( ; citr != citrEnd; ++ citr )
    {
        ss << ( *citr )->GetAsString();
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Articulated_Parts_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < ARTICULATED_PARTS_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    m_vVariableParameters.clear();

    LE_Header::Decode( stream, ignoreHeader );	

    stream >> m_ui8NumOfVariableParams;

	for( KUINT8 i = 0; i < m_ui8NumOfVariableParams; ++i )
	{
		// Save the current write position so we can peek.
		KUINT16 pos = stream.GetCurrentWritePosition();
		KUINT8 paramTyp;

		// Extract the  type then reset the stream.
		stream >> paramTyp;
		stream.SetCurrentWritePosition( pos );

		// Use the factory decoder. 
		VariableParameter * p = VariableParameter::FactoryDecode( paramTyp, stream );

		// Did we find a custom decoder? if not then use the default.
		if( p )
		{
			m_vVariableParameters.push_back( VarPrmPtr( p ) );
		}
		else
		{
			// Default internals
			switch( paramTyp )
			{
				case ArticulatedPartType:				
					m_vVariableParameters.push_back( VarPrmPtr( new ArticulatedPart( stream ) ) );
					break;

				case AttachedPartType:
					m_vVariableParameters.push_back( VarPrmPtr( new AttachedPart( stream ) ) );
					break;

				default:
					m_vVariableParameters.push_back( VarPrmPtr( new VariableParameter( stream ) ) );
					break;
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////

KDataStream Articulated_Parts_PDU::Encode() const
{
    KDataStream stream;

    Articulated_Parts_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Articulated_Parts_PDU::Encode( KDataStream & stream ) const
{
    LE_Header::Encode( stream );

    stream << m_ui8NumOfVariableParams;

    // Add the variable params
    vector<VarPrmPtr>::const_iterator citr = m_vVariableParameters.begin();
    vector<VarPrmPtr>::const_iterator citrEnd = m_vVariableParameters.end();
    for( ; citr != citrEnd; ++ citr )
    {
        ( *citr )->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Articulated_Parts_PDU::operator == ( const Articulated_Parts_PDU & Value ) const
{
    if( LE_Header::operator      != ( Value ) )                     return false;
    if( m_ui8NumOfVariableParams != Value.m_ui8NumOfVariableParams )return false;
    if( m_vVariableParameters    != Value.m_vVariableParameters )   return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Articulated_Parts_PDU::operator != ( const Articulated_Parts_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


