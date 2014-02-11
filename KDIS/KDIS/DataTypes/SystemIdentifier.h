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

    SystemIdentifier();

    SystemIdentifier( KDIS::DATA_TYPE::ENUMS::SystemType T, KDIS::DATA_TYPE::ENUMS::SystemName N, KDIS::DATA_TYPE::ENUMS::SystemMode M, 
		              KBOOL ChangeIndicator, KBOOL AltMode4 = false, KBOOL AltModeC = false );

    SystemIdentifier( KDataStream & stream ) throw( KException );

    virtual ~SystemIdentifier();

    //************************************
    // FullName:    KDIS::DATA_TYPE::SystemIdentifier::SetSystemType
    //              KDIS::DATA_TYPE::SystemIdentifier::GetSystemType
    // Description: System Type
    // Parameter:   SystemType T
    //************************************
    void SetSystemType( KDIS::DATA_TYPE::ENUMS::SystemType T );
    KDIS::DATA_TYPE::ENUMS::SystemType GetSystemType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SystemIdentifier::SetSystemName
    //              KDIS::DATA_TYPE::SystemIdentifier::GetSystemName
    // Description: A particular named type of system
    // Parameter:   SystemName ID
    //************************************
    void SetSystemName( KDIS::DATA_TYPE::ENUMS::SystemName N );
    KDIS::DATA_TYPE::ENUMS::SystemName GetSystemName() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SystemIdentifier::SetSystemMode
    //              KDIS::DATA_TYPE::SystemIdentifier::GetSystemMode
    // Description: Mode of operation for the named system.
    // Parameter:   SystemMode M
    //************************************
    void SetSystemMode( KDIS::DATA_TYPE::ENUMS::SystemMode M );
    KDIS::DATA_TYPE::ENUMS::SystemMode GetSystemMode() const;

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

} // END namespace DATA_TYPES
} // END namespace KDIS

