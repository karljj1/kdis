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

using KDIS::DATA_TYPE::TimeStamp;
using KDIS::DATA_TYPE::ENUMS::ProtocolVersion;
using KDIS::DATA_TYPE::ENUMS::ProtocolFamily;
using KDIS::DATA_TYPE::ENUMS::PDUType;

class KDIS_EXPORT Header6
{
protected:

    KUINT8 m_ui8ProtocolVersion;

    KUINT8 m_ui8ExerciseID;

    KUINT8 m_ui8PDUType;

    KUINT8 m_ui8ProtocolFamily;

    TimeStamp m_TimeStamp;

    KUINT16 m_ui16PDULength;

	KUINT8 m_ui8Padding1;  // Padding except for Live Entity family which uses it for Sub protocol Number, if DIS version > 6 then used for sub protocol.

    KUINT8 m_ui8Padding2;

public:

    static const KUINT16 HEADER6_PDU_SIZE = 12;

    Header6( void );

    Header6( KDataStream & stream ) throw( KException );

    Header6( ProtocolVersion PV, KUINT8 ExerciseID, PDUType PT, ProtocolFamily PF,
             const TimeStamp & TS, KUINT16 PDULength );

    virtual ~Header6( void );

    //************************************
    // FullName:    KDIS::PDU::Header6::SetProtocolVersion
    //              KDIS::PDU::Header6::GetProtocolVersion
    // Description: DIS protocol version.
	//              In KDIS the version is automatically set by each PDU
    //              to the mimimum version of DIS required to support the current PDU.	
	// Parameter:   ProtocolVersion PV
    //************************************
    void SetProtocolVersion( ProtocolVersion PV );
    ProtocolVersion GetProtocolVersion() const;

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
    void SetPDUType( PDUType Type );
    PDUType GetPDUType() const;

    //************************************
    // FullName:    KDIS::PDU::Header6::SetProtocolFamily
    //              KDIS::PDU::Header6::GetProtocolFamily
    // Description: Family of protocols to which the PDU belongs
    //              Set by PDU automatically.
    //              Only change if you know what you are doing.
    // Parameter:   ProtocolFamily PF
    //************************************
    void SetProtocolFamily( ProtocolFamily PF );
    ProtocolFamily GetProtocolFamily() const;

    //************************************
    // FullName:    KDIS::PDU::Header6::SetTimeStamp
    //              KDIS::PDU::Header6::GetTimeStamp
    // Description: Specifies the time which the data
    //              in the PDU is valid.
    // Parameter:   const TimeStamp & TS
    //************************************
    void SetTimeStamp( const TimeStamp & TS );
    const TimeStamp & GetTimeStamp() const;
    TimeStamp & GetTimeStamp();

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
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::PDU::Header6::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

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

}; // END namespace PDU
}; // END namespace KDIS
