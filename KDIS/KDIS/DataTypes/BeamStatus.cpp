/*********************************************************************
Copyright 2017 Karl Jones
               Dale Marchand
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

#include "./BeamStatus.h"
#include "Enums/EnumEmitter.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using std::endl;

#if DIS_VERSION > 6

namespace
{
const int s_BeamStateBitmask = 0x1;
const int s_PaddingBitmask = 0xfe;
}

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

BeamStatus::BeamStatus() :
  DataTypeBase(),
  m_ui8BeamStatus( 0u )
{
}

//////////////////////////////////////////////////////////////////////////

BeamStatus::BeamStatus( KDataStream & stream ) throw( KException ) :
  DataTypeBase(),
  m_ui8BeamStatus( 0u )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

BeamStatus::BeamStatus( BeamState BS ) :
  DataTypeBase(),
  m_ui8BeamStatus( BS & s_BeamStateBitmask)
{
}

//////////////////////////////////////////////////////////////////////////

BeamStatus::~BeamStatus()
{
}

//////////////////////////////////////////////////////////////////////////

void BeamStatus::SetBeamState( BeamState BS )
{
    m_ui8BeamStatus = (BS & s_BeamStateBitmask);
}

//////////////////////////////////////////////////////////////////////////

BeamState BeamStatus::GetBeamState() const
{
    return static_cast<BeamState>(m_ui8BeamStatus & s_BeamStateBitmask);
}

//////////////////////////////////////////////////////////////////////////

KString BeamStatus::GetAsString() const
{
    KStringStream ss;

    ss << "Beam State:  " << GetEnumAsStringBeamState(m_ui8BeamStatus & s_BeamStateBitmask)  << endl
       << "Padding:     " << static_cast<KUINT16>(m_ui8BeamStatus & s_PaddingBitmask)        << endl;

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void BeamStatus::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < BEAM_STATUS_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui8BeamStatus;
}

//////////////////////////////////////////////////////////////////////////

KDataStream BeamStatus::Encode() const
{
    KDataStream stream;

    BeamStatus::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void BeamStatus::Encode( KDataStream & stream ) const
{
    stream << m_ui8BeamStatus;
}

//////////////////////////////////////////////////////////////////////////

KBOOL BeamStatus::operator == ( const BeamStatus & Value ) const
{
    if( m_ui8BeamStatus     != Value.m_ui8BeamStatus )      return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL BeamStatus::operator != ( const BeamStatus & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////

#endif
