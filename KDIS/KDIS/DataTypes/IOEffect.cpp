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

#include "./IOEffect.h"

//////////////////////////////////////////////////////////////////////////

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

IOEffect::IOEffect( void ) :
    m_ui8Status( 0 ),
    m_ui8LnkTyp( 0 ),
    m_ui8Eff( 0 ),
    m_ui8EffDtyCyc( 0 ),
    m_ui16EffDur( 0 ),
    m_ui16Proc( 0 ),
    m_ui16Padding( 0 )
{
    m_ui32Type = IOEffectRecord;
    m_ui16Length = IO_EFFECT_TYPE_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IOEffect::IOEffect( IOStatus S, IOLinkType LT, IOEffectType ET, KUINT8 DutyCycle,
                    KUINT16 Duration, KUINT16 Process ) throw( KException ) :
    m_ui8Status( S ),
    m_ui8LnkTyp( LT ),
    m_ui8Eff( ET ),
    m_ui8EffDtyCyc( 0 ),
    m_ui16EffDur( Duration ),
    m_ui16Proc( Process ),
    m_ui16Padding( 0 )
{
    // Set duty cycle, may cause exception if the value is not valid.
    SetEffectDutyCycle( DutyCycle );

    m_ui32Type = IOEffectRecord;
    m_ui16Length = IO_EFFECT_TYPE_SIZE;
}

//////////////////////////////////////////////////////////////////////////

IOEffect::IOEffect( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

IOEffect::~IOEffect( void )
{
}

//////////////////////////////////////////////////////////////////////////

void IOEffect::SetStatus( IOStatus S )
{
    m_ui8Status = S;
}

//////////////////////////////////////////////////////////////////////////

IOStatus IOEffect::GetStatus() const
{
    return ( IOStatus )m_ui8Status;
}

//////////////////////////////////////////////////////////////////////////

void IOEffect::SetLinkType( IOLinkType LT )
{
    m_ui8LnkTyp = LT;
}

//////////////////////////////////////////////////////////////////////////

IOLinkType IOEffect::GetLinkType() const
{
    return ( IOLinkType )m_ui8LnkTyp;
}

//////////////////////////////////////////////////////////////////////////

void IOEffect::SetEffectType( IOEffectType ET )
{
    m_ui8Eff = ET;
}

//////////////////////////////////////////////////////////////////////////

IOEffectType IOEffect::GetEffectType() const
{
    return ( IOEffectType )m_ui8Eff;
}

//////////////////////////////////////////////////////////////////////////

void IOEffect::SetEffectDutyCycle( KUINT8 EDC ) throw( KException )
{
    if( EDC > 100 )throw KException( __FUNCTION__, OUT_OF_BOUNDS, "Invalid Effect Duty Cycle value. Must be between 0-100." );

    m_ui8EffDtyCyc = EDC;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 IOEffect::GetEffectDutyCycle() const
{
    return m_ui8EffDtyCyc;
}

//////////////////////////////////////////////////////////////////////////

void IOEffect::SetEffectDuration( KUINT16 ED )
{
    m_ui16EffDur = ED;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 IOEffect::GetEffectDuration() const
{
    return m_ui16EffDur;
}

//////////////////////////////////////////////////////////////////////////

void IOEffect::SetProcess( KUINT16 P )
{
    m_ui16Proc = P;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 IOEffect::GetProcess() const
{
    return m_ui16Proc;
}

//////////////////////////////////////////////////////////////////////////

KString IOEffect::GetAsString() const
{
    KStringStream ss;

    ss << StandardVariable::GetAsString()
       << "Status:            " << GetEnumAsStringIOStatus( m_ui8Status )    << "\n"
       << "Link Type:         " << GetEnumAsStringIOLinkType( m_ui8LnkTyp )  << "\n"
       << "Effect:            " << GetEnumAsStringIOEffectType( m_ui8Eff )   << "\n"
       << "Effect Duty Cycle: " << m_ui8EffDtyCyc                            << "%\n"
       << "Effect Duration:   " << m_ui16EffDur                              << " seconds\n"
       << "Process:           " << m_ui16Proc                                << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void IOEffect::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < IO_EFFECT_TYPE_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    StandardVariable::Decode( stream );

    stream >> m_ui8Status
           >> m_ui8LnkTyp
           >> m_ui8Eff
           >> m_ui8EffDtyCyc
           >> m_ui16EffDur
           >> m_ui16Proc
           >> m_ui16Padding;
}

//////////////////////////////////////////////////////////////////////////

KDataStream IOEffect::Encode() const
{
    KDataStream stream;

    IOEffect::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void IOEffect::Encode( KDataStream & stream ) const
{
    StandardVariable::Encode( stream );

    stream << m_ui8Status
           << m_ui8LnkTyp
           << m_ui8Eff
           << m_ui8EffDtyCyc
           << m_ui16EffDur
           << m_ui16Proc
           << m_ui16Padding;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IOEffect::operator == ( const IOEffect & Value ) const
{
    if( StandardVariable::operator  !=( Value ) )               return false;
    if( m_ui8Status                 != Value.m_ui8Status )      return false;
    if( m_ui8LnkTyp                 != Value.m_ui8LnkTyp )      return false;
    if( m_ui8Eff                    != Value.m_ui8Eff )         return false;
    if( m_ui8EffDtyCyc              != Value.m_ui8EffDtyCyc )   return false;
    if( m_ui16EffDur                != Value.m_ui16EffDur )     return false;
    if( m_ui16Proc                  != Value.m_ui16Proc )       return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IOEffect::operator != ( const IOEffect & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
