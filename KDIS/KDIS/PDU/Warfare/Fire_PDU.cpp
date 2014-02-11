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

#include "./Fire_PDU.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace PDU;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

Fire_PDU::Fire_PDU()
{
    m_ui8PDUType = Fire_PDU_Type;
    m_ui16PDULength = FIRE_PDU_SIZE;
	SetDescriptor( DescPtr( new MunitionDescriptor() ) );
}

//////////////////////////////////////////////////////////////////////////

Fire_PDU::Fire_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Fire_PDU::Fire_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Warfare_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Fire_PDU::Fire_PDU( const Warfare_Header & WarfareHeader, KUINT32 FireMissionIndex, const WorldCoordinates & Location,
                    DescPtr Desc, const Vector & Velocity, KFLOAT32 Range ) :
    Warfare_Header( WarfareHeader ),
    m_ui32FireMissionIndex( FireMissionIndex ),
    m_Location( Location ),
    m_Velocity( Velocity ),
    m_f32Range( Range )
{
    m_ui8PDUType = Fire_PDU_Type;
    m_ui16PDULength = FIRE_PDU_SIZE;
	SetDescriptor( Desc );
}

//////////////////////////////////////////////////////////////////////////

Fire_PDU::Fire_PDU( const EntityIdentifier & FiringEntID, const EntityIdentifier & TargetEntID, const EntityIdentifier & MunitionID,
                    const EntityIdentifier & EventID, KUINT32 FireMissionIndex, const WorldCoordinates & Location,
                    DescPtr Desc, const Vector & Velocity, KFLOAT32 Range ) :
    Warfare_Header( FiringEntID, TargetEntID, MunitionID, EventID ),
    m_ui32FireMissionIndex( FireMissionIndex ),
    m_Location( Location ),
    m_Velocity( Velocity ),
    m_f32Range( Range )
{
    m_ui8PDUType = Fire_PDU_Type;
    m_ui16PDULength = FIRE_PDU_SIZE;
	SetDescriptor( Desc );
}

//////////////////////////////////////////////////////////////////////////

Fire_PDU::~Fire_PDU()
{
}

//////////////////////////////////////////////////////////////////////////
#if DIS_VERSION > 6

void Fire_PDU::SetPDUStatusFireType( FireType FT )
{
	m_PDUStatusUnion.m_ui8PDUStatusFTI = FT;
}

//////////////////////////////////////////////////////////////////////////

FireType Fire_PDU::GetPDUStatusFireType() const
{
	return ( FireType )m_PDUStatusUnion.m_ui8PDUStatusFTI;
}

#endif
//////////////////////////////////////////////////////////////////////////

void Fire_PDU::SetFireMissionIndex( KUINT32 FMI )
{
    m_ui32FireMissionIndex = FMI;
}

//////////////////////////////////////////////////////////////////////////

KUINT32 Fire_PDU::GetFireMissionIndex() const
{
    return m_ui32FireMissionIndex;
}

//////////////////////////////////////////////////////////////////////////

void Fire_PDU::SetLocation( const WorldCoordinates & L )
{
    m_Location = L;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & Fire_PDU::GetLocation() const
{
    return m_Location;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & Fire_PDU::GetLocation()
{
    return m_Location;
}

//////////////////////////////////////////////////////////////////////////

void Fire_PDU::SetDescriptor( DescPtr D )
{
	m_pDescriptor = D;

	#if DIS_VERSION > 6 
	
	// Determine the FTI
	if( dynamic_cast<MunitionDescriptor*>( m_pDescriptor.GetPtr() ) )
	{
		m_PDUStatusUnion.m_ui8PDUStatusFTI = MunitionFTI;
	}
	else
	{
		m_PDUStatusUnion.m_ui8PDUStatusFTI = ExpendableFTI;		
		m_ui8ProtocolVersion = IEEE_1278_1_2012; // We are using a DIS 7 feature now.
	}

	#endif
}

//////////////////////////////////////////////////////////////////////////

const DescPtr Fire_PDU::GetDescriptor() const
{
	return m_pDescriptor;
}

//////////////////////////////////////////////////////////////////////////

DescPtr Fire_PDU::GetDescriptor()
{
	return m_pDescriptor;
}

//////////////////////////////////////////////////////////////////////////

void Fire_PDU::SetVelocity( const Vector & V )
{
    m_Velocity = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & Fire_PDU::GetVelocity() const
{
    return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////

Vector & Fire_PDU::GetVelocity()
{
    return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////

void Fire_PDU::SetRange( KFLOAT32 R )
{
    m_f32Range = R;
}

//////////////////////////////////////////////////////////////////////////

KFLOAT32 Fire_PDU::GetRange() const
{
    return m_f32Range;
}

//////////////////////////////////////////////////////////////////////////

KString Fire_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Fire PDU-\n"
       << Warfare_Header::GetAsString()
       << "Fire Mission Index:  " << m_ui32FireMissionIndex  << "\n"
       << "World Location:      " << m_Location.GetAsString()
       << m_pDescriptor->GetAsString()
       << "Velocity:            " << m_Velocity.GetAsString()
       << "Range:               " << m_f32Range             << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Fire_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < FIRE_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    Warfare_Header::Decode( stream, ignoreHeader );	

    stream >> m_ui32FireMissionIndex
           >> KDIS_STREAM m_Location;

	#if DIS_VERSION < 7 

	if( !m_pDescriptor.GetPtr() )
	{
		m_pDescriptor = DescPtr( new MunitionDescriptor() );
	}	

	#else

	// If the protocol version is not 7 then treat it as a MunitionDesc
	if( m_ui8ProtocolVersion < 7 )
	{
		if( !m_pDescriptor.GetPtr() )
		{
			m_pDescriptor = DescPtr( new MunitionDescriptor() );
		}	
	}
	else // DIS 7 
	{	
		if( m_PDUStatusUnion.m_ui8PDUStatusFTI == MunitionFTI )
		{
			// Create a descriptor if the desc is null or the incorrect type
			if( !m_pDescriptor.GetPtr() || !dynamic_cast<MunitionDescriptor*>( m_pDescriptor.GetPtr() ) )
			{
				m_pDescriptor = DescPtr( new MunitionDescriptor() );
			}				
		}
		else
		{
			// Create a descriptor if the desc is null or the incorrect type
			if( !m_pDescriptor.GetPtr() || !dynamic_cast<ExpendableDescriptor*>( m_pDescriptor.GetPtr() ) )
			{
				m_pDescriptor = DescPtr( new ExpendableDescriptor() );
			}
		}
	}
	#endif

    m_pDescriptor->Decode( stream );

	stream >> KDIS_STREAM m_Velocity
           >> m_f32Range;
}

//////////////////////////////////////////////////////////////////////////

KDataStream Fire_PDU::Encode() const
{
    KDataStream stream;

    Fire_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Fire_PDU::Encode( KDataStream & stream ) const
{
    Warfare_Header::Encode( stream );
    stream << m_ui32FireMissionIndex
           << KDIS_STREAM m_Location;
	
	if( !m_pDescriptor.GetPtr() )
	{
		// Create a temp to fill the buffer.
		MunitionDescriptor md;
		stream << KDIS_STREAM md;		
	}		
	else
	{
		m_pDescriptor->Encode( stream );
	}	

    stream << KDIS_STREAM m_Velocity
           << m_f32Range;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Fire_PDU::operator == ( const Fire_PDU & Value ) const
{
    if( Warfare_Header::operator !=( Value ) )                      return false;
    if( m_ui32FireMissionIndex   != Value.m_ui32FireMissionIndex )  return false;
    if( m_Location               != Value.m_Location )              return false;
    if( *m_pDescriptor           != *Value.m_pDescriptor )          return false;
    if( m_Velocity               != Value.m_Velocity )              return false;
    if( m_f32Range               != Value.m_f32Range )              return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Fire_PDU::operator != ( const Fire_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////







