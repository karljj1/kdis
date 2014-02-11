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

#include "./Detonation_PDU.h"
#include "./../../DataTypes/ArticulatedPart.h"
#include "./../../DataTypes/AttachedPart.h"

#if DIS_VERSION > 6
#include "./../../DataTypes/ExplosionDescriptor.h"
#endif

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

Detonation_PDU::Detonation_PDU() :
    m_ui8NumOfVariableParams( 0 )
{
    m_ui8PDUType = Detonation_PDU_Type;
    m_ui16PDULength = DETONATION_PDU_SIZE;
	SetDescriptor( DescPtr( new MunitionDescriptor() ) );
}

//////////////////////////////////////////////////////////////////////////

Detonation_PDU::Detonation_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream, false );
}

//////////////////////////////////////////////////////////////////////////

Detonation_PDU::Detonation_PDU( const Header & H, KDataStream & stream ) throw( KException ) :
	Warfare_Header( H )
{
    Decode( stream, true );
}

//////////////////////////////////////////////////////////////////////////

Detonation_PDU::Detonation_PDU( const EntityIdentifier & FiringEntID, const EntityIdentifier & TargetEntID,
                                const EntityIdentifier & MunitionID, const EntityIdentifier & EventID ,
                                const Vector & Velocity, const WorldCoordinates & LocationWorldCoords,
                                DescPtr Desc, const Vector & LocationEntityCoords,
                                DetonationResult DetonationResult ) :
    Warfare_Header( FiringEntID, TargetEntID, MunitionID, EventID ),
    m_Velocity( Velocity ),
    m_LocationWorldCoords( LocationWorldCoords ),
    m_LocationEntityCoords( LocationEntityCoords ),
    m_ui8DetonationResult( DetonationResult ),
    m_ui8NumOfVariableParams( 0 ),
    m_ui16Padding1( 0 )
{
    m_ui8PDUType = Detonation_PDU_Type;
    m_ui16PDULength = DETONATION_PDU_SIZE;
	SetDescriptor( Desc );
}

//////////////////////////////////////////////////////////////////////////

Detonation_PDU::Detonation_PDU( const Warfare_Header & WarfareHeader, const Vector & Velocity,
                                const WorldCoordinates & LocationWorldCoords, DescPtr Desc,
                                const Vector & LocationEntityCoords, DetonationResult DetonationResult ) :
    Warfare_Header( WarfareHeader ),
    m_Velocity( Velocity ),
    m_LocationWorldCoords( LocationWorldCoords ),
    m_LocationEntityCoords( LocationEntityCoords ),
    m_ui8DetonationResult( DetonationResult ),
    m_ui8NumOfVariableParams( 0 ),
    m_ui16Padding1( 0 )
{
    m_ui8PDUType = Detonation_PDU_Type;
    m_ui16PDULength = DETONATION_PDU_SIZE;
	SetDescriptor( Desc );
}

//////////////////////////////////////////////////////////////////////////

Detonation_PDU::~Detonation_PDU()
{
}

//////////////////////////////////////////////////////////////////////////
#if DIS_VERSION > 6

void Detonation_PDU::SetPDUStatusDetonationType( DetonationType DT )
{
	m_PDUStatusUnion.m_ui8PDUStatusDTI_RAI_IAI = DT;
}

//////////////////////////////////////////////////////////////////////////

DetonationType Detonation_PDU::GetPDUStatusDetonationType() const
{
	return ( DetonationType )m_PDUStatusUnion.m_ui8PDUStatusDTI_RAI_IAI;
}

#endif
//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::SetVelocity( const Vector & V )
{
    m_Velocity = V;
}

//////////////////////////////////////////////////////////////////////////

const Vector & Detonation_PDU::GetVelocity() const
{
    return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////

Vector & Detonation_PDU::GetVelocity()
{
    return m_Velocity;
}

//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::SetLocationInWorldCoords( const WorldCoordinates & L )
{
    m_LocationWorldCoords = L;
}

//////////////////////////////////////////////////////////////////////////

const WorldCoordinates & Detonation_PDU::GetLocationInWorldCoords() const
{
    return m_LocationWorldCoords;
}

//////////////////////////////////////////////////////////////////////////

WorldCoordinates & Detonation_PDU::GetLocationInWorldCoords()
{
    return m_LocationWorldCoords;
}

//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::SetDescriptor( DescPtr D )
{
	m_pDescriptor = D;

	#if DIS_VERSION > 6 
	
	// Determine the FTI
	if( dynamic_cast<MunitionDescriptor*>( m_pDescriptor.GetPtr() ) )
	{
		m_PDUStatusUnion.m_ui8PDUStatusDTI_RAI_IAI = MunitionDTI;
	}
	else if( dynamic_cast<ExpendableDescriptor*>( m_pDescriptor.GetPtr() ) )
	{
		m_PDUStatusUnion.m_ui8PDUStatusDTI_RAI_IAI = ExpendableDTI;		
		m_ui8ProtocolVersion = IEEE_1278_1_2012; // We are using a DIS 7 feature now.
	}
	else
	{
		m_PDUStatusUnion.m_ui8PDUStatusDTI_RAI_IAI = NonMunitionExplosionDTI;		
		m_ui8ProtocolVersion = IEEE_1278_1_2012; // We are using a DIS 7 feature now.
	}

	#endif
}

//////////////////////////////////////////////////////////////////////////

const DescPtr Detonation_PDU::GetDescriptor() const
{
	return m_pDescriptor;
}

//////////////////////////////////////////////////////////////////////////

DescPtr Detonation_PDU::GetDescriptor()
{
	return m_pDescriptor;
}

//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::SetLocationInEntityCoords( const Vector & L )
{
    m_LocationEntityCoords = L;
}

//////////////////////////////////////////////////////////////////////////

const Vector & Detonation_PDU::GetLocationInEntityCoords() const
{
    return m_LocationEntityCoords;
}

//////////////////////////////////////////////////////////////////////////

Vector & Detonation_PDU::GetLocationInEntityCoords()
{
    return m_LocationEntityCoords;
}

//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::SetDetonationResult( DetonationResult DR )
{
    m_ui8DetonationResult = DR;
}

//////////////////////////////////////////////////////////////////////////

DetonationResult Detonation_PDU::GetDetonationResult() const
{
    return ( DetonationResult )m_ui8DetonationResult;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 Detonation_PDU::GetNumberOfVariableParams() const
{
    return m_ui8NumOfVariableParams;
}

//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::AddVariableParameter( VarPrmPtr VP )
{
    m_vVariableParameters.push_back( VP );
    ++m_ui8NumOfVariableParams;
	m_ui16PDULength += VariableParameter::VARIABLE_PARAMETER_SIZE;
}

//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::SetVariableParameters( const vector<VarPrmPtr> & VP )
{
    m_vVariableParameters = VP;
    m_ui8NumOfVariableParams = m_vVariableParameters.size();
    m_ui16PDULength = DETONATION_PDU_SIZE + ( m_ui8NumOfVariableParams * VariableParameter::VARIABLE_PARAMETER_SIZE );
}

//////////////////////////////////////////////////////////////////////////

const vector<VarPrmPtr> & Detonation_PDU::GetVariableParameters() const
{
    return m_vVariableParameters;
}

//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::ClearVariableParameters()
{
    m_vVariableParameters.clear();
    m_ui8NumOfVariableParams = 0;
    m_ui16PDULength = DETONATION_PDU_SIZE;
}

//////////////////////////////////////////////////////////////////////////

KString Detonation_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Detonation PDU-\n"
       << Warfare_Header::GetAsString()
       << "Velocity:                 " << m_Velocity.GetAsString()
       << "World Location:           " << m_LocationWorldCoords.GetAsString()
	   << m_pDescriptor->GetAsString()
       << "Entity Location:          " << m_LocationEntityCoords.GetAsString()
       << "Detonation Result:        " << GetEnumAsStringDetonationResult( m_ui8DetonationResult ) << "\n"
       << "Num Articulation Params:  " << ( KUINT16 )m_ui8NumOfVariableParams
       << "\n";

    // Add the articulated parts
    vector<VarPrmPtr>::const_iterator citr = m_vVariableParameters.begin();
    vector<VarPrmPtr>::const_iterator citrEnd = m_vVariableParameters.end();
    for( ; citr != citrEnd; ++ citr )
    {
        ss << IndentString( ( *citr )->GetAsString(), 1 );
    }

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::Decode( KDataStream & stream, bool ignoreHeader /*= true*/ ) throw( KException )
{
    if( ( stream.GetBufferSize() + ( ignoreHeader ? Header::HEADER6_PDU_SIZE : 0 ) ) < DETONATION_PDU_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

	m_vVariableParameters.clear();

    Warfare_Header::Decode( stream, ignoreHeader );	

    stream >> KDIS_STREAM m_Velocity
           >> KDIS_STREAM m_LocationWorldCoords;

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
		if( m_PDUStatusUnion.m_ui8PDUStatusDTI_RAI_IAI == MunitionDTI ) // Munition
		{
			// Create a descriptor if the desc is null or the incorrect type
			if( !m_pDescriptor.GetPtr() || !dynamic_cast<MunitionDescriptor*>( m_pDescriptor.GetPtr() ) )
			{
				m_pDescriptor = DescPtr( new MunitionDescriptor() );
			}				
		}
		else if( m_PDUStatusUnion.m_ui8PDUStatusDTI_RAI_IAI == ExpendableDTI ) // Expendable
		{
			// Create a descriptor if the desc is null or the incorrect type
			if( !m_pDescriptor.GetPtr() || !dynamic_cast<ExpendableDescriptor*>( m_pDescriptor.GetPtr() ) )
			{
				m_pDescriptor = DescPtr( new ExpendableDescriptor() );
			}
		}
		else // Explosion
		{
			// Create a descriptor if the desc is null or the incorrect type
			if( !m_pDescriptor.GetPtr() || !dynamic_cast<ExplosionDescriptor*>( m_pDescriptor.GetPtr() ) )
			{
				m_pDescriptor = DescPtr( new ExplosionDescriptor() );
			}
		}
	}
	#endif

    m_pDescriptor->Decode( stream );

    stream >> KDIS_STREAM m_LocationEntityCoords
           >> m_ui8DetonationResult
           >> m_ui8NumOfVariableParams
           >> m_ui16Padding1;

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

KDataStream Detonation_PDU::Encode() const
{
    KDataStream stream;

    Detonation_PDU::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void Detonation_PDU::Encode( KDataStream & stream ) const
{
    Warfare_Header::Encode( stream );

    stream << KDIS_STREAM m_Velocity
           << KDIS_STREAM m_LocationWorldCoords;

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

    stream << KDIS_STREAM m_LocationEntityCoords
           << m_ui8DetonationResult
           << m_ui8NumOfVariableParams
           << m_ui16Padding1;

    // Add the variable params
    vector<VarPrmPtr>::const_iterator citr = m_vVariableParameters.begin();
    vector<VarPrmPtr>::const_iterator citrEnd = m_vVariableParameters.end();
    for( ; citr != citrEnd; ++ citr )
    {
        ( *citr )->Encode( stream );
    }
}

//////////////////////////////////////////////////////////////////////////

KBOOL Detonation_PDU::operator == ( const Detonation_PDU & Value ) const
{
    if( Warfare_Header::operator !=( Value ) )                       return false;
    if( m_Velocity               != Value.m_Velocity )               return false;
    if( m_LocationWorldCoords    != Value.m_LocationWorldCoords )    return false;
    if( *m_pDescriptor           != *Value.m_pDescriptor )          return false;
    if( m_LocationEntityCoords   != Value.m_LocationEntityCoords )   return false;
    if( m_ui8DetonationResult    != Value.m_ui8DetonationResult )    return false;
    if( m_ui8NumOfVariableParams != Value.m_ui8NumOfVariableParams ) return false;
    if( m_vVariableParameters    != Value.m_vVariableParameters )    return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Detonation_PDU::operator != ( const Detonation_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////


