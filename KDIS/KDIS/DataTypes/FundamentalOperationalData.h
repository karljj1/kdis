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

    FundamentalOperationalData( void );

    FundamentalOperationalData( KDataStream & stream ) throw( KException );

    FundamentalOperationalData( const FundamentalOperationalData_MarkXTransponder & FOD );

    FundamentalOperationalData( const FundamentalOperationalData_MarkXInterrogator & FOD );

    FundamentalOperationalData( const FundamentalOperationalData_Soviet & FOD );

    FundamentalOperationalData( const FundamentalOperationalData_RRB & FOD );

    virtual ~FundamentalOperationalData( void );

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS

