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

/********************************************************************
    class:      Signal_PDU
    DIS:        (5) 1278.1 - 1995
    created:    22/10/2008
    author:     Karl Jones

    purpose:    The Signal PDU contains the content of a radio transmission. 
				This content may be digitized audio, binary data, or an index 
				into a database that defines the signal.
				A Signal PDU shall be issued whenever voice or data is being transmitted.
	
    size:       256 bits / 32 - min size
*********************************************************************/

#pragma once

#include "./Radio_Communications_Header.h"
#include "./../../DataTypes/EncodingScheme.h"
#include <vector>

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Signal_PDU : public Radio_Communications_Header
{
protected:

    KDIS::DATA_TYPE::EncodingScheme m_EncodingScheme;

    KUINT32 m_ui32SampleRate;

    KUINT16 m_ui16DataLength;

    KUINT16 m_ui16Samples;

	std::vector<KOCTET> m_vData;

public:

    static const KUINT16 SIGNAL_PDU_SIZE = 32; // Min Size

    Signal_PDU();

	Signal_PDU( const Header & H );

    Signal_PDU( KDataStream & stream ) throw( KException );

	Signal_PDU( const Header & H, KDataStream & stream ) throw( KException );

    Signal_PDU( const KDIS::DATA_TYPE::EntityIdentifier & ID, KUINT16 RadioID, const KDIS::DATA_TYPE::EncodingScheme & ES,
                KUINT32 SampleRate, KUINT16 Samples, const KOCTET * Data, KUINT16 DataLength );

    virtual ~Signal_PDU();

    //************************************
    // FullName:    KDIS::PDU::Signal_PDU::SetEncodingScheme
    //              KDIS::PDU::Signal_PDU::GetEncodingScheme
    // Description: Encoding scheme used for the data.
    // Parameter:   const EncodingScheme & ES
    //************************************
    void SetEncodingScheme( const KDIS::DATA_TYPE::EncodingScheme & ES );
    const KDIS::DATA_TYPE::EncodingScheme & GetEncodingScheme() const;
    KDIS::DATA_TYPE::EncodingScheme & GetEncodingScheme();

    //************************************
    // FullName:    KDIS::PDU::Signal_PDU::SetSampleRate
    //              KDIS::PDU::Signal_PDU::GetSampleRate
    // Description: sample rate in samples per second if the encoding
    //              class is encoded audio or the data rate in bits
    //              per second for data transmissions.
    //              If the Encoding Class is database index,
    //              this field shall be zero.
    // Parameter:   KUINT32 SR
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
    // Parameter:   KUINT16 S
    //************************************
    void SetSamples( KUINT16 S );
    KUINT16 GetSamples() const;

    //************************************
    // FullName:    KDIS::PDU::Signal_PDU::SetData
    //              KDIS::PDU::Signal_PDU::GetData
    // Description: The data being sent. set function will add
    //              padding so the PDU size is a multiple of 32 bits.
    // Parameter:   KOCTET * D - buffer for writing/reading
    // Parameter:   KUINT16 Length - size of data in BITS(buffer size should be at least the size GetDataLength)
    //************************************
    void SetData( const KOCTET * D, KUINT16 Length );
    void GetData( KOCTET * D, KUINT16 Length ) const throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Signal_PDU::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Signal_PDU::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    // Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

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

} // END namespace PDU
} // END namespace KDIS

