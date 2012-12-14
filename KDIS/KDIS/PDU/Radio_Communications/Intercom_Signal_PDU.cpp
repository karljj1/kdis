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

#include "./Intercom_Signal_PDU.h"

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

Intercom_Signal_PDU::Intercom_Signal_PDU( void )
{
    m_ui8PDUType = IntercomSignal_PDU_Type;
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Intercom_Signal_PDU::Intercom_Signal_PDU( KDataStream & stream ) throw( KException )
{
    Decode( stream );
}

//////////////////////////////////////////////////////////////////////////

Intercom_Signal_PDU::Intercom_Signal_PDU( const EntityIdentifier & ID, KUINT16 RadioID, const EncodingScheme & ES,
        KUINT32 SampleRate, KUINT16 Samples, const KOCTET * Data, KUINT16 DataLength ) :
    Signal_PDU( ID, RadioID, ES,SampleRate, Samples, Data, DataLength )
{
    m_ui8PDUType = IntercomSignal_PDU_Type;
    SetData( Data, DataLength );
    m_ui8ProtocolVersion = IEEE_1278_1A_1998;
}

//////////////////////////////////////////////////////////////////////////

Intercom_Signal_PDU::~Intercom_Signal_PDU( void )
{
}

//////////////////////////////////////////////////////////////////////////

KString Intercom_Signal_PDU::GetAsString() const
{
    KStringStream ss;

    ss << Header::GetAsString()
       << "-Intercom Signal PDU-\n"
       << Radio_Communications_Header::GetAsString()
       << m_EncodingScheme.GetAsString()
       << "Sample Rate:        " << m_ui32SampleRate << "\n"
       << "Data Length:        " << m_ui16DataLength << "\n"
       << "Samples:			" << m_ui16Samples     << "\n";

    // Data is not printed as we don't know what the data is.

    return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KBOOL Intercom_Signal_PDU::operator == ( const Intercom_Signal_PDU & Value ) const
{
    if( Signal_PDU::operator !=( Value ) ) return false;
    return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL Intercom_Signal_PDU::operator != ( const Intercom_Signal_PDU & Value ) const
{
    return !( *this == Value );
}

//////////////////////////////////////////////////////////////////////////
