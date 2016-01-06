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

#include "./ArticulatedPart.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

ArticulatedPart::ArticulatedPart() :
    m_ui8ParmeterChange( 0 ),
    m_ui16AttachementID( 0 ),
    m_ui32ParamTypeVariant( 0 ),
    m_f32ParamValue( 0 ),
    m_ui32Padding( 0 )
{    
    m_ui8VarParamType = ArticulatedPartType;
}

//////////////////////////////////////////////////////////////////////////

ArticulatedPart::ArticulatedPart( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

ArticulatedPart::ArticulatedPart( KUINT8 ParamChangeIndicator, KUINT16 AttachID, ArticulatedPartsClass C, 
                                                ArticulatedPartsMetric M, KFLOAT32 Value ) :
    m_ui8ParmeterChange( ParamChangeIndicator ),
    m_ui16AttachementID( AttachID ),	
    m_f32ParamValue( Value ),
    m_ui32Padding( 0 )
{
    m_ui8VarParamType = ArticulatedPartType;
    m_ui32ParamTypeVariant = C + M;
}
//////////////////////////////////////////////////////////////////////////

ArticulatedPart::ArticulatedPart( KUINT8 ParamChangeIndicator, KUINT16 AttachID, KUINT32 TypeVariant, KFLOAT32 Value ) :
    m_ui8ParmeterChange( ParamChangeIndicator ),
    m_ui16AttachementID( AttachID ),
    m_ui32ParamTypeVariant( TypeVariant ),
    m_f32ParamValue( Value ),
    m_ui32Padding( 0 )
{
    m_ui8VarParamType = ArticulatedPartType;
}

//////////////////////////////////////////////////////////////////////////

ArticulatedPart::~ArticulatedPart()
{
}

//////////////////////////////////////////////////////////////////////////

void ArticulatedPart::SetParameterChangeIndicator( KUINT8 PCI )
{
    m_ui8ParmeterChange = PCI;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 ArticulatedPart::GetParameterChangeIndicator() const
{
    return m_ui8ParmeterChange;
}

//////////////////////////////////////////////////////////////////////////

void ArticulatedPart::SetAttachementID( KUINT16 ID )
{
    m_ui16AttachementID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 ArticulatedPart::GetAttachementID() const
{
    return m_ui16AttachementID;
}

//////////////////////////////////////////////////////////////////////////

void ArticulatedPart::SetTypeVariantClass( ArticulatedPartsClass C )
{
    m_ui32ParamTypeVariant = C + ( m_ui32ParamTypeVariant % 32 );    
}

//////////////////////////////////////////////////////////////////////////

ArticulatedPartsClass ArticulatedPart::GetTypeVariantClass() const
{
    return ( ArticulatedPartsClass )( m_ui32ParamTypeVariant - ( m_ui32ParamTypeVariant % 32 ) );
}

//////////////////////////////////////////////////////////////////////////

void ArticulatedPart::SetTypeVariantMetric( ArticulatedPartsMetric M )
{
    m_ui32ParamTypeVariant = m_ui32ParamTypeVariant - ( m_ui32ParamTypeVariant % 32 ) + M;    
}

//////////////////////////////////////////////////////////////////////////

ArticulatedPartsMetric ArticulatedPart::GetTypeVariantMetric() const
{
    return ( ArticulatedPartsMetric )( m_ui32ParamTypeVariant % 32 );
}

//////////////////////////////////////////////////////////////////////////

void ArticulatedPart::SetTypeVariant( KUINT32 TV )
{
    m_ui32ParamTypeVariant = TV;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 ArticulatedPart::GetTypeVariant() const
{
    return m_ui32ParamTypeVariant;
}

//////////////////////////////////////////////////////////////////////////

void ArticulatedPart::SetValue( KFLOAT32 val )
{
    m_f32ParamValue = val;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 ArticulatedPart::GetValue() const
{
    return m_f32ParamValue;
}

//////////////////////////////////////////////////////////////////////////

KString ArticulatedPart::GetAsString() const
{
    KStringStream ss;

    ss << "Articulation Parameters:"
       << "\n\tParameter Change:     " << ( KUINT16 )m_ui8ParmeterChange
       << "\n\tAttachement ID:       " << m_ui16AttachementID
       << "\n\tType Metric:          " << GetEnumAsStringArticulatedPartsMetric( GetTypeVariantMetric() )
       << "\n\tType High Bits:       " << GetEnumAsStringArticulatedPartsClass( GetTypeVariantClass() )
       << "\n\tValue:                " << m_f32ParamValue
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ArticulatedPart::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < VariableParameter::VARIABLE_PARAMETER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8VarParamType
           >> m_ui8ParmeterChange
           >> m_ui16AttachementID
           >> m_ui32ParamTypeVariant
           >> m_f32ParamValue
           >> m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream ArticulatedPart::Encode() const
{
    KDataStream stream;

    ArticulatedPart::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void ArticulatedPart::Encode( KDataStream & stream ) const
{
    stream << m_ui8VarParamType
           << m_ui8ParmeterChange
           << m_ui16AttachementID
           << m_ui32ParamTypeVariant
           << m_f32ParamValue
           << m_ui32Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ArticulatedPart::operator == ( const ArticulatedPart & Value ) const
{
    if( m_ui8VarParamType      != Value.m_ui8VarParamType )      return false;
    if( m_ui8ParmeterChange    != Value.m_ui8ParmeterChange )    return false;
    if( m_ui16AttachementID    != Value.m_ui16AttachementID )    return false;
    if( m_ui32ParamTypeVariant != Value.m_ui32ParamTypeVariant ) return false;
    if( m_f32ParamValue        != Value.m_f32ParamValue )        return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ArticulatedPart::operator != ( const ArticulatedPart & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

