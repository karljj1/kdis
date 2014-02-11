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
    class:      Header6
    DIS:        (5) 1278.1 - 1995
    created:    03/02/2011
    author:     Karl Jones

    purpose:    PDU Header. Contains infomation used to identify
                the PDU type that is represented by the datagram.
				This header contains all features upto DIS version 6(1278.1a),
				for DIS 7 features use Header7.
    Size:       96 bits / 12 octets
*********************************************************************/

#pragma once

#include "./../KDefines.h"
#include "./../DataTypes/Enums/KDISEnums.h"
#include "./../KEncodersDecoders.h"
#include "./../KDataStream.h"
#include "./../DataTypes/TimeStamp.h"
#include "./../Extras/KUtils.h"

namespace KDIS {
namespace PDU {

class KDIS_EXPORT Header6
{
protected:

    KUINT8 m_ui8ProtocolVersion;

    KUINT8 m_ui8ExerciseID;

    KUINT8 m_ui8PDUType;

    KUINT8 m_ui8ProtocolFamily;

    KDIS::DATA_TYPE::TimeStamp m_TimeStamp;

    KUINT16 m_ui16PDULength;

	KUINT8 m_ui8Padding1;  // Padding except for Live Entity family which uses it for Sub protocol Number, if DIS version > 6 then used for sub protocol.

    KUINT8 m_ui8Padding2;

public:

    static const KUINT16 HEADER6_PDU_SIZE = 12;

    Header6();

    Header6( KDataStream & stream ) throw( KException );

    Header6( KDIS::DATA_TYPE::ENUMS::ProtocolVersion PV, KUINT8 ExerciseID, KDIS::DATA_TYPE::ENUMS::PDUType PT,
		     KDIS::DATA_TYPE::ENUMS::ProtocolFamily PF, const KDIS::DATA_TYPE::TimeStamp & TS, KUINT16 PDULength );

    virtual ~Header6();

    //************************************
    // FullName:    KDIS::PDU::Header6::SetProtocolVersion
    //              KDIS::PDU::Header6::GetProtocolVersion
    // Description: DIS protocol version.
	//              In KDIS the version is automatically set by each PDU
    //              to the mimimum version of DIS required to support the current PDU.	
	// Parameter:   ProtocolVersion PV
    //************************************
    void SetProtocolVersion( KDIS::DATA_TYPE::ENUMS::ProtocolVersion PV );
    KDIS::DATA_TYPE::ENUMS::ProtocolVersion GetProtocolVersion() const;

    //************************************
    // FullName:    KDIS::PDU::Header6::SetExerciseID
    //              KDIS::PDU::Header6::GetExerciseID
    // Description: Unique to each exercise being
    //              conducted simultaneously.
    // Parameter:   KUINT8 ID
    //************************************
    void SetExerciseID( KUINT8 EID );
    KUINT8 GetExerciseID() const;

    //************************************
    // FullName:    KDIS::PDU::Header6::SetPDUType
    //              KDIS::PDU::Header6::GetPDUType
    // Description: The type of PDU. Set by PDU automatically.
    //              Only change if you know what you are doing.
    // Parameter:   PDUType Type
    //************************************
    void SetPDUType( KDIS::DATA_TYPE::ENUMS::PDUType Type );
    KDIS::DATA_TYPE::ENUMS::PDUType GetPDUType() const;

    //************************************
    // FullName:    KDIS::PDU::Header6::SetProtocolFamily
    //              KDIS::PDU::Header6::GetProtocolFamily
    // Description: Family of protocols to which the PDU belongs
    //              Set by PDU automatically.
    //              Only change if you know what you are doing.
    // Parameter:   ProtocolFamily PF
    //************************************
    void SetProtocolFamily( KDIS::DATA_TYPE::ENUMS::ProtocolFamily PF );
    KDIS::DATA_TYPE::ENUMS::ProtocolFamily GetProtocolFamily() const;

    //************************************
    // FullName:    KDIS::PDU::Header6::SetTimeStamp
    //              KDIS::PDU::Header6::GetTimeStamp
    // Description: Specifies the time which the data
    //              in the PDU is valid.
    // Parameter:   const TimeStamp & TS
    //************************************
    void SetTimeStamp( const KDIS::DATA_TYPE::TimeStamp & TS );
    const KDIS::DATA_TYPE::TimeStamp & GetTimeStamp() const;
    KDIS::DATA_TYPE::TimeStamp & GetTimeStamp();

    //************************************
    // FullName:    KDIS::PDU::Header6::SetPDULength
    //              KDIS::PDU::Header6::GetPDULength
    // Description: Specified the length of the PDU
    //              in KOCTETs( 8 bits = 1 octet ). This value
    //              will be set by each PDU, you should
    //              not have to set this value manually.
    // Parameter:   KUINT16 PDUL
    //************************************
    void SetPDULength( KUINT16 PDUL );
    KUINT16 GetPDULength() const;

    //************************************
    // FullName:    KDIS::PDU::Header6::GetAsString
    // Description: Returns a string representation of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Header6::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
	// Parameter:   bool ignoreHeader = false - Decode the header from the stream? 
    //************************************
    virtual void Decode( KDataStream & stream, bool ignoreHeader = false ) throw( KException );

    //************************************
    // FullName:    KDIS::PDU::Header6::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    friend KDataStream & operator >> ( KDataStream & stream, Header6 * H )
    {
        H->Decode( stream );
        return stream;
    };

    friend KDataStream & operator << ( KDataStream & stream, Header6 * H )
    {
        H->Encode( stream );
        return stream;
    };

    KBOOL operator == ( const Header6 & Value ) const;
    KBOOL operator != ( const Header6 & Value ) const;
};

} // END namespace PDU
} // END namespace KDIS
