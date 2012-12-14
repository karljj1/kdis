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

/********************************************************************
    class:      Signal_PDU
    DIS:        (5) 1278.1 - 1995
    created:    22/10/2008
    author:     Karl Jones

    purpose:    The Signal PDU contains the content of a radio transmission. 
				This content may be digitized audio, binary data, or an index 
				into a database that defines the signal.
				A Signal PDU shall be issued whenever voice or data is being transmitted.
				See 5.8.4.3.1 for further details.
	
    size:       256 bits / 32 - min size
*********************************************************************/

#pragma once

#include "./Radio_Communications_Header.h"
#include "./../../DataTypes/EncodingScheme.h"
#include <vector>

namespace KDIS {
namespace PDU {

using KDIS::DATA_TYPE::EntityIdentifier;
using KDIS::DATA_TYPE::EncodingScheme;
using std::vector;

class KDIS_EXPORT Signal_PDU : public Radio_Communications_Header
{
protected:

    EncodingScheme m_EncodingScheme;

    KUINT32 m_ui32SampleRate;

    KUINT16 m_ui16DataLength;

    KUINT16 m_ui16Samples;

    vector<KOCTET> m_vData;

public:

    static const KUINT16 SIGNAL_PDU_SIZE = 32; // Min Size

    Signal_PDU( void );

    Signal_PDU( KDataStream & stream ) throw( KException );

    Signal_PDU( const EntityIdentifier & ID, KUINT16 RadioID, const EncodingScheme & ES,
                KUINT32 SampleRate, KUINT16 Samples, const KOCTET * Data, KUINT16 DataLength );

    virtual ~Signal_PDU( void );

    //************************************
    // FullName:    KDIS::PDU::Signal_PDU::SetEncodingScheme
    //              KDIS::PDU::Signal_PDU::GetEncodingScheme
    // Description: Encoding scheme used for the data.
    // Parameter:   const EncodingScheme & ES, void
    //************************************
    void SetEncodingScheme( const EncodingScheme & ES );
    const EncodingScheme & GetEncodingScheme() const;
    EncodingScheme & GetEncodingScheme();

    //************************************
    // FullName:    KDIS::PDU::Signal_PDU::SetSampleRate
    //              KDIS::PDU::Signal_PDU::GetSampleRate
    // Description: sample rate in samples per second if the encoding
    //              class is encoded audio or the data rate in bits
    //              per second for data transmissions.
    //              If the Encoding Class is database index,
    //              this field shall be zero.
    // Parameter:   KUINT32 SR, void
    //************************************
    void SetSampleRate( KUINT32 SR );
    KUINT32 GetSampleRate() const;

    //************************************
    // FullName:    KDIS::PDU::Signal_PDU::GetSampleRate
    // Description: Returns data length in bits, if encoding class is
    //              database index then the length shall be 96.
    //************************************
    KUINT16 GetDataLength() const;

    //************************************
    // FullName:    KDIS::PDU::Signal_PDU::SetSamples
    //              KDIS::PDU::Signal_PDU::GetSamples
    // Description: Number of samples in PDU
    // Parameter:   KUINT16 S, void
    //************************************
    void SetSamples( KUINT16 S );
    KUINT16 GetSamples() const;

    //************************************
    // FullName:    KDIS::PDU::Signal_PDU::SetData
    //              KDIS::PDU::Signal_PDU::GetData
    // Description: The data being sent. set function will add
    //              padding so the PDU size up to a multiple of 32 bits.
    //              copy data over.
    // Parameter:   KOCTET * D - buffer for writing/reading
    // Parameter:   KUINT16 Length - size of data in BITS(buffer size should be this / 8)
    //************************************
    void SetData( const KOCTET * D, KUINT16 Length );
    void GetData( KOCTET * D, KUINT16 Length ) const throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Signal_PDU::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Signal_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Signal_PDU::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Signal_PDU & Value ) const;
    KBOOL operator != ( const Signal_PDU & Value ) const;
};

}; // END namespace PDU
}; // END namespace KDIS

