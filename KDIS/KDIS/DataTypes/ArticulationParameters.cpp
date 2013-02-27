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
    m_ui8ArticulationType( 0 ),
    m_ui8ParmeterChange( 0 ),
    m_ui16AttachementID( 0 ),
    m_ui64ParamValue( 0 )
{
    m_ui32ParamTypeVariantUnion.m_ui32ParamTypeVariant = 0;
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

ArticulationParameters::ArticulationParameters( ArticulationType AT, KUINT8 ParamChangeIndicator,
        KUINT16 AttachID, KUINT32 TypeVariant, KUINT64 Value ) :
    m_ui8ArticulationType( AT ),
    m_ui8ParmeterChange( ParamChangeIndicator ),
    m_ui16AttachementID( AttachID ),
    m_ui64ParamValue( Value )
{
    m_ui32ParamTypeVariantUnion.m_ui32ParamTypeVariant = TypeVariant;
}

//////////////////////////////////////////////////////////////////////////

ArticulationParameters::~ArticulationParameters()
{
}

//////////////////////////////////////////////////////////////////////////

void ArticulationParameters::SetArticulationType( ArticulationType AT )
{
    m_ui8ArticulationType = AT;
}

//////////////////////////////////////////////////////////////////////////

ArticulationType ArticulationParameters::GetArticulationType() const
{
    return ( ArticulationType )m_ui8ArticulationType;
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

void ArticulationParameters::SetTypeVariantLowBits( ArticulatedPartsLowBits VLB )
{
    m_ui32ParamTypeVariantUnion.m_VariantLowBits = VLB;
}

//////////////////////////////////////////////////////////////////////////

ArticulatedPartsLowBits ArticulationParameters::GetTypeVariantLowBits() const
{
    return ( ArticulatedPartsLowBits )m_ui32ParamTypeVariantUnion.m_VariantLowBits;
}

//////////////////////////////////////////////////////////////////////////

void ArticulationParameters::SetTypeVariantHighBits( ArticulatedPartsHighBits VHB )
{
    m_ui32ParamTypeVariantUnion.m_VariantHighBits = VHB;
}

//////////////////////////////////////////////////////////////////////////

ArticulatedPartsHighBits ArticulationParameters::GetTypeVariantHighBits() const
{
    return ( ArticulatedPartsHighBits )m_ui32ParamTypeVariantUnion.m_VariantHighBits;
}

//////////////////////////////////////////////////////////////////////////

void ArticulationParameters::SetTypeVariant( KUINT32 TV )
{
    m_ui32ParamTypeVariantUnion.m_ui32ParamTypeVariant = TV;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 ArticulationParameters::GetTypeVariant() const
{
    return m_ui32ParamTypeVariantUnion.m_ui32ParamTypeVariant;
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
       << "\n\tType:                 " << GetEnumAsStringArticulationType( m_ui8ArticulationType )
       << "\n\tParameter Change:     " << ( KUINT16 )m_ui8ParmeterChange
       << "\n\tAttachement ID:       " << m_ui16AttachementID
       << "\n\tType Low Bits:        " << GetEnumAsStringArticulatedPartsLowBits( m_ui32ParamTypeVariantUnion.m_VariantLowBits )
       << "\n\tType High Bits:       " << GetEnumAsStringArticulatedPartsHighBits( m_ui32ParamTypeVariantUnion.m_VariantHighBits )
       << "\n\tValue:                " << m_ui64ParamValue
       << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void ArticulationParameters::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < ArticulationParameters::ARTICULATION_PARAMETERS_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8ArticulationType
           >> m_ui8ParmeterChange
           >> m_ui16AttachementID
           >> m_ui32ParamTypeVariantUnion.m_ui32ParamTypeVariant
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
    stream << m_ui8ArticulationType
           << m_ui8ParmeterChange
           << m_ui16AttachementID
           << m_ui32ParamTypeVariantUnion.m_ui32ParamTypeVariant
           << m_ui64ParamValue;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ArticulationParameters::operator == ( const ArticulationParameters & Value ) const
{
    if( m_ui8ArticulationType   != Value.m_ui8ArticulationType )  return false;
    if( m_ui8ParmeterChange     != Value.m_ui8ParmeterChange )    return false;
    if( m_ui16AttachementID     != Value.m_ui16AttachementID )    return false;
    if( m_ui32ParamTypeVariantUnion.m_ui32ParamTypeVariant != Value.m_ui32ParamTypeVariantUnion.m_ui32ParamTypeVariant ) return false;
    if( m_ui64ParamValue        != Value.m_ui64ParamValue )       return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL ArticulationParameters::operator != ( const ArticulationParameters & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

