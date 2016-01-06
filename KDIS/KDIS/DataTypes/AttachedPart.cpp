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

#include "./AttachedPart.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

AttachedPart::AttachedPart() :
    m_ui8DetachedIndicator( 0 ),
    m_ui16PartAttachedToID( 0 ),
    m_ui32APPT( 0 )
{
    m_ui8VarParamType = AttachedPartType;
}

//////////////////////////////////////////////////////////////////////////

AttachedPart::AttachedPart( KUINT8 DetachedIndicator, KUINT16 PartAttachedToID, AttachedPartParameterType APPT, const EntityType & Type ) :
    m_ui8DetachedIndicator( DetachedIndicator ),
    m_ui16PartAttachedToID( PartAttachedToID ),
    m_ui32APPT( APPT ),
    m_AttachedPartType( Type )
{
    m_ui8VarParamType = AttachedPartType;
}

//////////////////////////////////////////////////////////////////////////

AttachedPart::AttachedPart( KUINT8 DetachedIndicator, KUINT16 PartAttachedToID, KUINT32 APPT, const EntityType & Type ) :
    m_ui8DetachedIndicator( DetachedIndicator ),
    m_ui16PartAttachedToID( PartAttachedToID ),
    m_ui32APPT( APPT ),
    m_AttachedPartType( Type )
{
    m_ui8VarParamType = AttachedPartType;
}

//////////////////////////////////////////////////////////////////////////

AttachedPart::AttachedPart( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

AttachedPart::~AttachedPart()
{
}

//////////////////////////////////////////////////////////////////////////

void AttachedPart::SetDetachedIndicator( KUINT8 DI )
{
    m_ui8DetachedIndicator = DI;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 AttachedPart::GetDetachedIndicator() const
{
    return m_ui8DetachedIndicator;
}

//////////////////////////////////////////////////////////////////////////

void AttachedPart::SetPartAttachedToID( KUINT16 ID )
{
    m_ui16PartAttachedToID = ID;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 AttachedPart::GetPartAttachedToID() const
{
    return m_ui16PartAttachedToID;
}

//////////////////////////////////////////////////////////////////////////

void AttachedPart::SetAttachedPartParameterType( AttachedPartParameterType APPT )
{
    m_ui32APPT = APPT;
}

//////////////////////////////////////////////////////////////////////////

void AttachedPart::SetAttachedPartParameterType( KUINT32 APPT )
{
    m_ui32APPT = APPT;
}

//////////////////////////////////////////////////////////////////////////

AttachedPartParameterType AttachedPart::GetAttachedPartParameterType() const
{
    return ( AttachedPartParameterType )m_ui32APPT;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 AttachedPart::GetAttachedPartParameterTypeInt() const
{
    return m_ui32APPT;
}

//////////////////////////////////////////////////////////////////////////

void AttachedPart::SetAttachedPartType( const EntityType & Type )
{
    m_AttachedPartType = Type;
}

//////////////////////////////////////////////////////////////////////////

const EntityType & AttachedPart::GetAttachedPartType() const
{
    return m_AttachedPartType;
}

//////////////////////////////////////////////////////////////////////////

EntityType & AttachedPart::GetAttachedPartType()
{
    return m_AttachedPartType;
}

//////////////////////////////////////////////////////////////////////////

KString AttachedPart::GetAsString() const
{
    KStringStream ss;

    ss << "Attached Part:"
       << "\n\tDetached:             " << ( m_ui8DetachedIndicator == 0 ? "False" : "True" )
       << "\n\tPart Attached To ID:  " << m_ui16PartAttachedToID
       << "\n\tParameter Type:       " << GetEnumAsStringAttachedPartParameterType( m_ui32APPT )
       << "\n\tType:                 " << m_AttachedPartType.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void AttachedPart::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < VariableParameter::VARIABLE_PARAMETER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8VarParamType
           >> m_ui8DetachedIndicator
           >> m_ui16PartAttachedToID
           >> m_ui32APPT
           >> KDIS_STREAM m_AttachedPartType;
}

//////////////////////////////////////////////////////////////////////////

KDataStream AttachedPart::Encode() const
{
    KDataStream stream;

    AttachedPart::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void AttachedPart::Encode( KDataStream & stream ) const
{
    stream << m_ui8VarParamType
           << m_ui8DetachedIndicator
           << m_ui16PartAttachedToID
           << m_ui32APPT
           << KDIS_STREAM m_AttachedPartType;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AttachedPart::operator == ( const AttachedPart & Value ) const
{
    if( m_ui8DetachedIndicator != Value.m_ui8DetachedIndicator ) return false;
    if( m_ui16PartAttachedToID != Value.m_ui16PartAttachedToID ) return false;
    if( m_ui32APPT             != Value.m_ui32APPT )             return false;
    if( m_AttachedPartType     != Value.m_AttachedPartType )     return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL AttachedPart::operator != ( const AttachedPart & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

