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

#include "./EnvironmentRecord.h"

// Geometry records available for factory decode
#include "./PointRecord1.h"
#include "./PointRecord2.h"
#include "./LineRecord1.h"
#include "./LineRecord2.h"
#include "./BoundingSphereRecord.h"
#include "./SphereRecord1.h"
#include "./SphereRecord2.h"
#include "./EllipsoidRecord1.h"
#include "./EllipsoidRecord2.h"
#include "./ConeRecord1.h"
#include "./ConeRecord2.h"
#include "./RectangularVolumeRecord1.h"
#include "./RectangularVolumeRecord2.h"
#include "./RectangularVolumeRecord3.h"
#include "./GaussianPlumeRecord.h"
#include "./GaussianPuffRecord.h"

// State records available for factory decode
#include  "./COMBICState.h"
#include  "./FlareState.h"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

EnvironmentRecord::EnvironmentRecord( void ) :
    m_ui32EnvRecTyp( 0 ),
    m_ui16Length( 0 ),
    m_ui8Index( 0 ),
    m_ui8Padding( 0 )
{
}

//////////////////////////////////////////////////////////////////////////

EnvironmentRecord::~EnvironmentRecord( void )
{
}

//////////////////////////////////////////////////////////////////////////

KUINT16 EnvironmentRecord::GetLength() const
{
    return m_ui16Length;
}

//////////////////////////////////////////////////////////////////////////

EnvironmentRecordType EnvironmentRecord::GetEnvironmentRecordType() const
{
    return ( EnvironmentRecordType )m_ui32EnvRecTyp;
}

//////////////////////////////////////////////////////////////////////////

void EnvironmentRecord::SetIndex( KUINT8 I )
{
    m_ui8Index = I;
}

//////////////////////////////////////////////////////////////////////////

KUINT8 EnvironmentRecord::GetIndex() const
{
    return m_ui8Index;
}

//////////////////////////////////////////////////////////////////////////

KString EnvironmentRecord::GetAsString() const
{
    KStringStream ss;

    ss << "Environment Record\n"
       << "\tRecord Type: " << GetEnumAsStringEnvironmentRecordType( m_ui32EnvRecTyp ) << "\n"
       << "\tLength:      " << m_ui16Length                                            << "\n"
       << "\tIndex:       " << ( KUINT16 )m_ui8Index                                   << "\n";

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

EnviromentRecordPtr EnvironmentRecord::FactoryDecodeEnvironmentRecord( KDataStream & stream ) throw( KException )
{
    // We now need to "peak" at the next 4 bytes to determine the Environment Record type,
    // once we have determined the type we need to return the buffers write positon as this
    // field needs to be re-read by the decode function of the derived Environment Record.
    KUINT16 ui16CurrentWritePos = stream.GetCurrentWritePosition();

    KUINT32 ui32RecType;
    stream >> ui32RecType;

    // We now know what type of record we should create, we need to reset the buffer so this value can be re-read.
    stream.SetCurrentWritePosition( ui16CurrentWritePos );

	// Check for a custom decoder, if none if found then use one of our standard data types.
	EnvironmentRecord * pRec = FactoryDecode( ui32RecType, stream );
	if( pRec )
	{
		return EnviromentRecordPtr( pRec );
	}

    switch( ui32RecType )
    {
		//
		// Geometry Records
		//
		case PointRecord1Type:                  return new PointRecord1( stream );
		case PointRecord2Type:                  return new PointRecord2( stream );
		case LineRecord1Type:                   return new LineRecord1( stream );
		case LineRecord2Type:                   return new LineRecord2( stream );
		case BoundingSphereRecordType:          return new BoundingSphereRecord( stream );
		case SphereRecord1Type:                 return new SphereRecord1( stream );
		case SphereRecord2Type:                 return new SphereRecord2( stream );
		case EllipsoidRecord1Type:              return new EllipsoidRecord1( stream );
		case EllipsoidRecord2Type:              return new EllipsoidRecord2( stream );
		case ConeRecord1Type:                   return new ConeRecord1( stream );
		case ConeRecord2Type:                   return new ConeRecord2( stream );
		case UniformGeometryRecordType:         throw KException( __FUNCTION__, UNSUPPORTED_DATATYPE, "UniformGeometryRecordType" ); // We don't know how to decode this type.	    
		case RectangularVolumeRecord1Type:      return new RectangularVolumeRecord1( stream );
		case RectangularVolumeRecord2Type:      return new RectangularVolumeRecord2( stream );
		case GaussianPlumeRecordType:           return new GaussianPlumeRecord( stream );
		case GaussianPuffRecordType:            return new GaussianPuffRecord( stream );
		case RectangularVolumeRecord3Type:      return new RectangularVolumeRecord3( stream );

		//
		// State Records
		//
		case COMBICStateType:                   return new COMBICState( stream );
		case FlareStateType:                    return new FlareState( stream );
		default:                                throw KException( __FUNCTION__, UNSUPPORTED_DATATYPE, ui32RecType ); // We don't know how to decode this type.
    }    
}

//////////////////////////////////////////////////////////////////////////

KBOOL EnvironmentRecord::operator == ( const EnvironmentRecord & Value )const
{
    if( m_ui32EnvRecTyp != Value.m_ui32EnvRecTyp ) return false;
    if( m_ui16Length    != Value.m_ui16Length )    return false;
    if( m_ui8Index      != Value.m_ui8Index )      return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EnvironmentRecord::operator != ( const EnvironmentRecord & Value )const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
