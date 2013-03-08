/*********************************************************************
Copyright 2013 KDIS
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

#include "./ArticulationParameters.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

ArticulationParameters::ArticulationParameters() :
    m_ui8ParmeterChange( 0 ),
    m_ui16AttachementID( 0 ),
	m_ui32ParamTypeVariant( 0 ),
    m_ui64ParamValue( 0 )
{    
	m_ui8VarParamType = ArticulatedPart;
}

//////////////////////////////////////////////////////////////////////////

ArticulationParameters::ArticulationParameters( KDataStream & stream ) throw( KException )
{
    try
    {
        Decode( stream );
    }
    catch ( KException & e )
    {
        throw e;
    }
}

//////////////////////////////////////////////////////////////////////////

ArticulationParameters::ArticulationParameters( KUINT8 ParamChangeIndicator, KUINT16 AttachID, ArticulatedPartsClass C, 
											    ArticulatedPartsMetric M, KUINT64 Value ) :
    m_ui8ParmeterChange( ParamChangeIndicator ),
    m_ui16AttachementID( AttachID ),	
    m_ui64ParamValue( Value )
{
	m_ui8VarParamType = ArticulatedPart;
	m_ui32ParamTypeVariant = C + M;
}
//////////////////////////////////////////////////////////////////////////

ArticulationParameters::ArticulationParameters( KUINT8 ParamChangeIndicator, KUINT16 AttachID, KUINT32 TypeVariant, KUINT64 Value ) :
    m_ui8ParmeterChange( ParamChangeIndicator ),
    m_ui16AttachementID( AttachID ),
	m_ui32ParamTypeVariant( TypeVariant ),
    m_ui64ParamValue( Value )
{
	m_ui8VarParamType = ArticulatedPart;
}

//////////////////////////////////////////////////////////////////////////

ArticulationParameters::~ArticulationParameters()
{
}

//////////////////////////////////////////////////////////////////////////

void ArticulationParameters::SetParameterChangeIndicator( KUINT8 PCI )
{
    m_ui8ParmeterChange = PCI;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 ArticulationParameters::GetParameterChangeIndicator() const
{
    return m_ui8ParmeterChange;
}

//////////////////////////////////////////////////////////////////////////

void ArticulationParameters::SetAttachementID( KUINT16 ID )
{
    m_ui16AttachementID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 ArticulationParameters::GetAttachementID() const
{
    return m_ui16AttachementID;
}

//////////////////////////////////////////////////////////////////////////

void ArticulationParameters::SetTypeVariantClass( ArticulatedPartsClass C )
{
    m_ui32ParamTypeVariant = C + ( m_ui32ParamTypeVariant % 32 );    
}

//////////////////////////////////////////////////////////////////////////

ArticulatedPartsClass ArticulationParameters::GetTypeVariantClass() const
{
    return ( ArticulatedPartsClass )( m_ui32ParamTypeVariant - ( m_ui32ParamTypeVariant % 32 ) );
}

//////////////////////////////////////////////////////////////////////////

void ArticulationParameters::SetTypeVariantMetric( ArticulatedPartsMetric M )
{
	m_ui32ParamTypeVariant = m_ui32ParamTypeVariant - ( m_ui32ParamTypeVariant % 32 ) + M;    
}

//////////////////////////////////////////////////////////////////////////

ArticulatedPartsMetric ArticulationParameters::GetTypeVariantMetric() const
{
    return ( ArticulatedPartsMetric )( m_ui32ParamTypeVariant % 32 );
}

//////////////////////////////////////////////////////////////////////////

void ArticulationParameters::SetTypeVariant( KUINT32 TV )
{
    m_ui32ParamTypeVariant = TV;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 ArticulationParameters::GetTypeVariant() const
{
    return m_ui32ParamTypeVariant;
}

//////////////////////////////////////////////////////////////////////////

void ArticulationParameters::SetValue( KUINT64 val )
{
    m_ui64ParamValue = val;
}

//////////////////////////////////////////////////////////////////////////

KUINT64 ArticulationParameters::GetValue() const
{
    return m_ui64ParamValue;
}

//////////////////////////////////////////////////////////////////////////

KString ArticulationParameters::GetAsString() const
{
    KStringStream ss;

    ss << "Articulation Parameters:"
       << "\n\tType:                 " << GetEnumAsStringVariableParameterType( m_ui8VarParamType )
       << "\n\tParameter Change:     " << ( KUINT16 )m_ui8ParmeterChange
       << "\n\tAttachement ID:       " << m_ui16AttachementID
       << "\n\tType Metric:          " << GetEnumAsStringArticulatedPartsMetric( GetTypeVariantMetric() )
       << "\n\tType High Bits:       " << GetEnumAsStringArticulatedPartsClass( GetTypeVariantClass() )
       << "\n\tValue:                " << m_ui64ParamValue
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ArticulationParameters::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < VariableParameter::VARIABLE_PARAMETER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8VarParamType
           >> m_ui8ParmeterChange
           >> m_ui16AttachementID
           >> m_ui32ParamTypeVariant
           >> m_ui64ParamValue;
}

//////////////////////////////////////////////////////////////////////////

KDataStream ArticulationParameters::Encode() const
{
    KDataStream stream;

    ArticulationParameters::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ArticulationParameters::Encode( KDataStream & stream ) const
{
    stream << m_ui8VarParamType
           << m_ui8ParmeterChange
           << m_ui16AttachementID
           << m_ui32ParamTypeVariant
           << m_ui64ParamValue;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ArticulationParameters::operator == ( const ArticulationParameters & Value ) const
{
    if( m_ui8VarParamType   != Value.m_ui8VarParamType )  return false;
    if( m_ui8ParmeterChange     != Value.m_ui8ParmeterChange )    return false;
    if( m_ui16AttachementID     != Value.m_ui16AttachementID )    return false;
    if( m_ui32ParamTypeVariant  != Value.m_ui32ParamTypeVariant ) return false;
    if( m_ui64ParamValue        != Value.m_ui64ParamValue )       return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ArticulationParameters::operator != ( const ArticulationParameters & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

