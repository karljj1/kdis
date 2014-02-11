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
    class:      FundamentalOperationalData
    created:    07/12/2008
    author:     Karl Jones

    purpose:    Specifies certain basic operational data for a emitting
                system.
    size:       128 bits / 16 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./FundamentalOperationalData_MarkXTransponder.h"
#include "./FundamentalOperationalData_MarkXInterrogator.h"
#include "./FundamentalOperationalData_Soviet.h"
#include "./FundamentalOperationalData_RRB.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT FundamentalOperationalData : public DataTypeBase
{
protected:

    union
    {
        struct
        {
            KUINT8 m_ui8SystemStatus;
            KUINT8 m_ui8AltParam4;
            KUINT8 m_ui8InfoLayers;
            KUINT8 m_ui8Modifier;
            KUINT16 m_ui16Param1;
            KUINT16 m_ui16Param2;
            KUINT16 m_ui16Param3;
            KUINT16 m_ui16Param4;
            KUINT16 m_ui16Param5;
            KUINT16 m_ui16Param6;
        };

        FundamentalOperationalData_MarkXTransponder m_FODSystemMarkTransponder;
        FundamentalOperationalData_MarkXInterrogator m_FODSystemMarkInterrogator;
        FundamentalOperationalData_Soviet m_FODSystemSoviet;
        FundamentalOperationalData_RRB m_FODSystemRRB;
    };

public:

    static const KUINT16 FUNDAMENTAL_OPERATIONAL_DATA_SIZE = 16;

    FundamentalOperationalData();

    FundamentalOperationalData( KDataStream & stream ) throw( KException );

    FundamentalOperationalData( const FundamentalOperationalData_MarkXTransponder & FOD );

    FundamentalOperationalData( const FundamentalOperationalData_MarkXInterrogator & FOD );

    FundamentalOperationalData( const FundamentalOperationalData_Soviet & FOD );

    FundamentalOperationalData( const FundamentalOperationalData_RRB & FOD );

    virtual ~FundamentalOperationalData();

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData::SetFundamentalOperationalData
    //              KDIS::DATA_TYPE::FundamentalOperationalData::GetFundamentalOperationalData
    // Description: Sets/Gets Fundamental Operational Data for a specific system.
    // Parameter:   FundamentalOperationalData_X FOD
    //************************************
    void SetFundamentalOperationalData_MarkXTransponder( const FundamentalOperationalData_MarkXTransponder & FOD );
    void SetFundamentalOperationalData_MarkXInterrogator( const FundamentalOperationalData_MarkXInterrogator & FOD );
    void SetFundamentalOperationalData_Soviet( const FundamentalOperationalData_Soviet & FOD );
    void SetFundamentalOperationalData_RRB( const FundamentalOperationalData_RRB & FOD );
    const FundamentalOperationalData_MarkXTransponder & GetSetFundamentalOperationalData_MarkXTransponder() const;
    FundamentalOperationalData_MarkXTransponder & GetSetFundamentalOperationalData_MarkXTransponder();
    const FundamentalOperationalData_MarkXInterrogator & GetFundamentalOperationalData_MarkXInterrogator() const;
    FundamentalOperationalData_MarkXInterrogator & GetFundamentalOperationalData_MarkXInterrogator();
    const FundamentalOperationalData_Soviet & GetFundamentalOperationalData_Soviet() const;
    FundamentalOperationalData_Soviet & GetFundamentalOperationalData_Soviet();
    const FundamentalOperationalData_RRB & GetFundamentalOperationalData_RRB() const;
    FundamentalOperationalData_RRB & GetFundamentalOperationalData_RRB();

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const FundamentalOperationalData & Value ) const;
    KBOOL operator != ( const FundamentalOperationalData & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

