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
    class:      CommunicationsChannelType
    created:    2009/01/24
    author:     Karl Jones

    purpose:    Identifies the type of communications channel
    size:       8 bits / 1 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT CommunicationsChannelType : public DataTypeBase
{
protected:

    union
    {
        struct
        {
            KUINT8 m_ui8Type  : 7;
            KUINT8 m_ui8Class : 1;
        };

        KUINT8 m_ui8CommChannelType;
    };

public:

	static const KUINT16 COMM_CHANNEL_TYPE_SIZE = 1;

    CommunicationsChannelType();

    CommunicationsChannelType( KDataStream & stream ) throw( KException );

    CommunicationsChannelType( KDIS::DATA_TYPE::ENUMS::ChannelType CT, KDIS::DATA_TYPE::ENUMS::ChannelClass CC );

    virtual ~CommunicationsChannelType();

    //************************************
    // FullName:    KDIS::DATA_TYPE::CommunicationsChannelType::SetType
    //              KDIS::DATA_TYPE::CommunicationsChannelType::GetType
    // Description: Type of channel.
    // Parameter:   ChannelType CT, void
    //************************************
    void SetType( KDIS::DATA_TYPE::ENUMS::ChannelType CT );
    KDIS::DATA_TYPE::ENUMS::ChannelType GetType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::CommunicationsChannelType::SetClass
    //              KDIS::DATA_TYPE::CommunicationsChannelType::GetClass
    // Description: Communications class.
    // Parameter:   ChannelClass CC, void
    //************************************
    void SetClass( KDIS::DATA_TYPE::ENUMS::ChannelClass CC );
    KDIS::DATA_TYPE::ENUMS::ChannelClass GetClass() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::CommunicationsChannelType::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::CommunicationsChannelType::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::CommunicationsChannelType::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const CommunicationsChannelType & Value ) const;
    KBOOL operator != ( const CommunicationsChannelType & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

