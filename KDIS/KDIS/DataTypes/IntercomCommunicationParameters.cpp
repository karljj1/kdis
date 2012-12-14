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

#include "./IntercomCommunicationParameters.h"

//////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;

//////////////////////////////////////////////////////////////////////////
// public:
//////////////////////////////////////////////////////////////////////////

IntercomCommunicationParameters::IntercomCommunicationParameters( void ) :
    m_ui16Length( 0 ),
    m_ui16Type( 0 ),
    m_pRecord( NULL ),
    m_bMemoryManage( false )
{
}

//////////////////////////////////////////////////////////////////////////

IntercomCommunicationParameters::IntercomCommunicationParameters( KDataStream & stream )throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

IntercomCommunicationParameters::IntercomCommunicationParameters( EntityDestinationRecord * EDR ) :
    m_ui16Type( EntityDestinationRecord_Type ),
    m_ui16Length( EntityDestinationRecord::ENTITY_DESTINATION_RECORD_SIZE ),
    m_pRecord( EDR ),
    m_bMemoryManage( false )
{
}

//////////////////////////////////////////////////////////////////////////

IntercomCommunicationParameters::IntercomCommunicationParameters( GroupDestinationRecord * GDR ) :
    m_ui16Type( GroupDestinationRecord_Type ),
    m_ui16Length( GroupDestinationRecord::GROUP_DESTINATION_RECORD_SIZE ),
    m_pRecord( GDR ),
    m_bMemoryManage( false )
{
}

//////////////////////////////////////////////////////////////////////////

IntercomCommunicationParameters::IntercomCommunicationParameters( GroupAssignmentRecord * GAR ) :
    m_ui16Type( GroupAssignmentRecord_Type ),
    m_ui16Length( GroupAssignmentRecord::GROUP_ASSIGNMENT_RECORD_SIZE ),
    m_pRecord( GAR ),
    m_bMemoryManage( false )
{
}

//////////////////////////////////////////////////////////////////////////

IntercomCommunicationParameters::~IntercomCommunicationParameters( void )
{
    if( m_pRecord && m_bMemoryManage )delete m_pRecord;
}

//////////////////////////////////////////////////////////////////////////

AdditionalIntrCommParamType IntercomCommunicationParameters::GetRecordType() const
{
    return ( AdditionalIntrCommParamType )m_ui16Type;
}

//////////////////////////////////////////////////////////////////////////

KUINT16 IntercomCommunicationParameters::GetLength() const
{
    return m_ui16Length;
}

//////////////////////////////////////////////////////////////////////////

void IntercomCommunicationParameters::SetRecord( EntityDestinationRecord * EDR )
{
    if( !EDR )return;

    if( m_pRecord && m_bMemoryManage )delete m_pRecord;

    m_bMemoryManage = false;

    m_ui16Length = EntityDestinationRecord::ENTITY_DESTINATION_RECORD_SIZE;

    m_ui16Type = EntityDestinationRecord_Type;

    m_pRecord = EDR;
}

//////////////////////////////////////////////////////////////////////////

void IntercomCommunicationParameters::SetRecord( GroupDestinationRecord * GDR )
{
    if( !GDR )return;

    if( m_pRecord && m_bMemoryManage )delete m_pRecord;

    m_bMemoryManage = false;

    m_ui16Length = GroupDestinationRecord::GROUP_DESTINATION_RECORD_SIZE;

    m_ui16Type = GroupDestinationRecord_Type;

    m_pRecord = GDR;
}

//////////////////////////////////////////////////////////////////////////

void IntercomCommunicationParameters::SetRecord( GroupAssignmentRecord * GAR )
{
    if( !GAR )return;

    if( m_pRecord && m_bMemoryManage )delete m_pRecord;

    m_bMemoryManage = false;

    m_ui16Length = GroupAssignmentRecord::GROUP_ASSIGNMENT_RECORD_SIZE;

    m_ui16Type = GroupAssignmentRecord_Type;

    m_pRecord = GAR;
}

//////////////////////////////////////////////////////////////////////////

const DataTypeBase * IntercomCommunicationParameters::GetRecord() const
{
    return m_pRecord;
}

//////////////////////////////////////////////////////////////////////////

DataTypeBase * IntercomCommunicationParameters::GetRecord()
{
    return m_pRecord;
}

//////////////////////////////////////////////////////////////////////////

KString IntercomCommunicationParameters::GetAsString() const
{
    KStringStream ss;

    ss << "Intercom Communications Parameter"
       << "\nType:     " << GetEnumAsStringAdditionalIntrCommParamType( m_ui16Type )
       << "\nLength:   " << m_ui16Length
       << m_pRecord->GetAsString();

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

void IntercomCommunicationParameters::Decode( KDataStream & stream ) throw( KException )
{
    if( stream.GetBufferSize() < IntercomCommunicationParameters::INTERCOM_COMMS_PARAM_SIZE )throw KException( __FUNCTION__, NOT_ENOUGH_DATA_IN_BUFFER );

    stream >> m_ui16Type
           >> m_ui16Length;

    if( m_pRecord && m_bMemoryManage )delete m_pRecord;

    m_bMemoryManage = true;

    switch( m_ui16Type )
    {
    case EntityDestinationRecord_Type:
        m_pRecord = new EntityDestinationRecord( stream );
        m_ui16Length = EntityDestinationRecord::ENTITY_DESTINATION_RECORD_SIZE;
        break;

    case GroupDestinationRecord_Type:
        m_pRecord = new GroupDestinationRecord( stream );
        m_ui16Length = GroupDestinationRecord::GROUP_DESTINATION_RECORD_SIZE;
        break;

    case GroupAssignmentRecord_Type:
        m_pRecord = new GroupAssignmentRecord( stream );
        m_ui16Length = GroupAssignmentRecord::GROUP_ASSIGNMENT_RECORD_SIZE;
        break;
    }
}

//////////////////////////////////////////////////////////////////////////

KDataStream IntercomCommunicationParameters::Encode() const
{
    KDataStream stream;

    IntercomCommunicationParameters::Encode( stream );

    return stream;
}

//////////////////////////////////////////////////////////////////////////

void IntercomCommunicationParameters::Encode( KDataStream & stream ) const
{
    stream << m_ui16Type
           << m_ui16Length
           << KDIS_STREAM m_pRecord;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IntercomCommunicationParameters::operator == ( const IntercomCommunicationParameters & Value ) const
{
    if( m_ui16Type   != Value.m_ui16Type )   return false;
    if( m_ui16Length != Value.m_ui16Length ) return false;

    switch( m_ui16Type )
    {
    case EntityDestinationRecord_Type:
    {
        const EntityDestinationRecord *  pl = ( EntityDestinationRecord * )m_pRecord,
                                         *  pr = ( EntityDestinationRecord * )Value.m_pRecord;

        if( *pl != *pr ) return false;
    }
    break;

    case GroupDestinationRecord_Type:
    {
        const GroupDestinationRecord  *  pl = ( GroupDestinationRecord * )m_pRecord,
                                         *  pr = ( GroupDestinationRecord * )Value.m_pRecord;

        if( *pl != *pr ) return false;
    }
    break;

    case GroupAssignmentRecord_Type:
    {
        const GroupAssignmentRecord *  pl = ( GroupAssignmentRecord * )m_pRecord,
                                       *  pr = ( GroupAssignmentRecord * )Value.m_pRecord;

        if( *pl != *pr ) return false;
    }
    break;
    }

    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL IntercomCommunicationParameters::operator != ( const IntercomCommunicationParameters & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
