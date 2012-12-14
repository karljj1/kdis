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

using KDIS::DATA_TYPE::ENUMS::ChannelType;
using KDIS::DATA_TYPE::ENUMS::ChannelClass;

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

#define COMM_CHANNEL_TYPE 1

    CommunicationsChannelType( void );

    CommunicationsChannelType( KDataStream & stream ) throw( KException );

    CommunicationsChannelType( ChannelType CT, ChannelClass CC );

    virtual ~CommunicationsChannelType( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::CommunicationsChannelType::SetType
    //              KDIS::DATA_TYPE::CommunicationsChannelType::GetType
    // Description: Type of channel.
    // Parameter:   ChannelType CT, void
    //************************************
    void SetType( ChannelType CT );
    ChannelType GetType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::CommunicationsChannelType::SetClass
    //              KDIS::DATA_TYPE::CommunicationsChannelType::GetClass
    // Description: Communications class.
    // Parameter:   ChannelClass CC, void
    //************************************
    void SetClass( ChannelClass CC );
    ChannelClass GetClass() const;

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS

