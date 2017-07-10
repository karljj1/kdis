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

#if DIS_VERSION > 5
#include "./SeparationPart.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

SeparationPart::SeparationPart()  :
    m_ui8Reason(0),
    m_ui8PreEntIndicator(0),
    m_ui8Padding(0),
    m_ui16Padding(0)
{
    m_ui8VarParamType = SeparationPartType;
}

KDIS::DATA_TYPE::SeparationPart::SeparationPart(ReasonForSeparation RFS, PreEntityIndicator PEI, const EntityIdentifier & PEID, const NamedLocationIdentifier & SL) :
    m_ui8Reason(RFS),
    m_ui8PreEntIndicator(PEI),
    m_ui8Padding(0),
    m_ParentEntId(PEID),
    m_ui16Padding(0),
    m_StationLoc(SL)
{
    m_ui8VarParamType = SeparationPartType;
}

//////////////////////////////////////////////////////////////////////////

SeparationPart::SeparationPart( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

SeparationPart::~SeparationPart()
{
}

//////////////////////////////////////////////////////////////////////////

void SeparationPart::SetReasonForSeparation(ReasonForSeparation RFS)
{
    m_ui8Reason = RFS;
}

//////////////////////////////////////////////////////////////////////////

ReasonForSeparation SeparationPart::GetReasonForSeparation() const
{
    return ( ReasonForSeparation )m_ui8Reason;
}

//////////////////////////////////////////////////////////////////////////

void SeparationPart::SetPreEntityIndicator(PreEntityIndicator PEI)
{
    m_ui8PreEntIndicator = PEI;
}

//////////////////////////////////////////////////////////////////////////

PreEntityIndicator SeparationPart::GetPreEntityIndicator() const
{
    return (PreEntityIndicator)m_ui8PreEntIndicator;
}

//////////////////////////////////////////////////////////////////////////

void SeparationPart::SetParentEntityId(const EntityIdentifier & PEID)
{
    m_ParentEntId = PEID;
}

//////////////////////////////////////////////////////////////////////////

const EntityIdentifier & SeparationPart::GetParentEntityId() const
{
    return m_ParentEntId;
}

//////////////////////////////////////////////////////////////////////////

EntityIdentifier & SeparationPart::GetParentEntityId()
{
    return m_ParentEntId;
}

//////////////////////////////////////////////////////////////////////////

void SeparationPart::SetStationLocation(const NamedLocationIdentifier & SL)
{
    m_StationLoc = SL;
}

//////////////////////////////////////////////////////////////////////////

const NamedLocationIdentifier & SeparationPart::GetStationLocation() const
{
    return m_StationLoc;
}

//////////////////////////////////////////////////////////////////////////

NamedLocationIdentifier & SeparationPart::GetStationLocation()
{
    return m_StationLoc;
}

//////////////////////////////////////////////////////////////////////////

KString SeparationPart::GetAsString() const
{
    KStringStream ss;

    ss << "Separation Part:"
        << "\n\ Reason for Separation: " << GetEnumAsStringReasonForSeparation( m_ui8Reason )
        << "\n\tPre-Entity Indicator:  " << GetEnumAsStringPreEntityIndicator( m_ui8PreEntIndicator )
        << "\n\tParent Entity Id:      " << m_ParentEntId.GetAsString()
        << "\n\tStation Location:      " << m_StationLoc.GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void SeparationPart::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < VariableParameter::VARIABLE_PARAMETER_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8VarParamType
           >> m_ui8Reason
           >> m_ui8PreEntIndicator
           >> m_ui8Padding
           >> KDIS_STREAM m_ParentEntId
           >> m_ui16Padding
           >> KDIS_STREAM m_StationLoc;
}

//////////////////////////////////////////////////////////////////////////

KDataStream SeparationPart::Encode() const
{
    KDataStream stream;

    SeparationPart::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void SeparationPart::Encode( KDataStream & stream ) const
{
    stream << m_ui8VarParamType
           << m_ui8Reason
           << m_ui8PreEntIndicator
           << m_ui8Padding
           << KDIS_STREAM m_ParentEntId
           << m_ui16Padding
           << KDIS_STREAM m_StationLoc;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SeparationPart::operator == ( const SeparationPart & Value ) const
{
    if ( m_ui8VarParamType != Value.m_ui8VarParamType)        return false;
    if ( m_ui8Reason != Value.m_ui8Reason )                   return false;
    if ( m_ui8PreEntIndicator != Value.m_ui8PreEntIndicator ) return false;
    if ( m_ParentEntId != Value.m_ParentEntId )               return false;
    if ( m_StationLoc != Value.m_StationLoc )                 return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL SeparationPart::operator != ( const SeparationPart & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

#endif // DIS_VERSION > 5