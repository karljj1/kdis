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
    class:      SystemIdentifier
    created:    05/12/2008
    author:     Karl Jones

    purpose:    Identifier for IFF/ATC/NAVADIS systems.
                Shall specify the change status of the PDU,
                the system type, name and mode.
    size:       48 bits / 6 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::SystemType;
using KDIS::DATA_TYPE::ENUMS::SystemName;
using KDIS::DATA_TYPE::ENUMS::SystemMode;

class KDIS_EXPORT SystemIdentifier : public DataTypeBase
{
protected:

    KUINT16 m_ui16SystemType;

    KUINT16 m_ui16SystemName;

    KUINT8 m_ui8SystemMode;

    union
    {
        struct
        {
            KUINT8 m_ui8ChangeIndicator : 1;
            KUINT8 m_ui8AltMode4        : 1;
            KUINT8 m_ui8AltModeC        : 1;
            // Bits 3-7 not used
        };

        KUINT8 m_ui8ChangeOptions;
    };

public:

    static const KUINT16 SYSTEM_IDENTIFER_SIZE = 6;

    SystemIdentifier( void );

    SystemIdentifier( SystemType T, SystemName N, SystemMode M, KBOOL ChangeIndicator,
                      KBOOL AltMode4 = false, KBOOL AltModeC = false );

    SystemIdentifier( KDataStream & stream ) throw( KException );

    virtual ~SystemIdentifier( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::SystemIdentifier::SetSystemType
    //              KDIS::DATA_TYPE::SystemIdentifier::GetSystemType
    // Description: System Type
    // Parameter:   SystemType T
    //************************************
    void SetSystemType( SystemType T );
    SystemType GetSystemType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SystemIdentifier::SetSystemName
    //              KDIS::DATA_TYPE::SystemIdentifier::GetSystemName
    // Description: A particular named type of system
    // Parameter:   SystemName ID
    //************************************
    void SetSystemName( SystemName N );
    SystemName GetSystemName() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SystemIdentifier::SetSystemMode
    //              KDIS::DATA_TYPE::SystemIdentifier::GetSystemMode
    // Description: Mode of operation for the named system.
    // Parameter:   SystemMode M
    //************************************
    void SetSystemMode( SystemMode M );
    SystemMode GetSystemMode() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SystemIdentifier::SetChangeOptions
    //              KDIS::DATA_TYPE::SystemIdentifier::GetChangeOptions
    // Description: Used to specifiy the status of the PDU(existence of
    //              changes from previous indicators for alternative fields etc).
    //              Note: Alternative Mode 4 and Alternative Mode C changes
    //              only apply to Mark X/XII/ATCRBS/MODE S Transponder and
    //              Mark X/XII/ATCRBS/MODE S Interrogator systems.
    // Parameter:   KBOOL ChangeIndicator
    // Parameter:   KBOOL AltMode4
    // Parameter:   KBOOL AltModeC
    //************************************
    void SetChangeOptions( KBOOL ChangeIndicator, KBOOL AltMode4, KBOOL AltModeC );
    void SetChangeIndicator( KBOOL CI );
    void SetAltMode4( KBOOL AM );
    void SetAltModeC( KBOOL AM );
    KBOOL GetChangeIndicator() const;
    KBOOL GetAltMode4() const;
    KBOOL GetAltModeC() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SystemIdentifier::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::SystemIdentifier::DataTypeBase::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::SystemIdentifier::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const SystemIdentifier & Value ) const;
    KBOOL operator != ( const SystemIdentifier & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

