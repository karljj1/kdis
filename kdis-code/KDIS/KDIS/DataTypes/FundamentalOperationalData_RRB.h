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
    class:      FundamentalOperationalData_RRB
    created:    2008/12/07
    author:     Karl Jones

    purpose:    Specifies Fundamental Operational Data for system 5 =
                RRB Transponder

    size:       128 bits / 16 octets
*********************************************************************/

#pragma once

#include "./../KDefines.h"
#include "./Enums/KDISEnums.h"

namespace KDIS {
namespace DATA_TYPE {

struct KDIS_EXPORT FundamentalOperationalData_RRB
{
protected:

    union
    {
        struct
        {
            KUINT8 m_ui8SystemOnOff : 1;
            KUINT8 m_ui8Param1      : 1;
            KUINT8 m_ui8Param2      : 1;
            KUINT8 m_ui8Param3      : 1;
            KUINT8 m_ui8Param4      : 1;
            KUINT8 m_ui8Param5      : 1;
            KUINT8 m_ui8Param6      : 1;
            KUINT8 m_ui8OpsStatus   : 1;
        };

        KUINT8 m_ui8SystemStatus;
    };

    KUINT8 m_ui8AltParam4; // Not used

    union
    {
        struct
        {
            KUINT8 m_ui8NotUsed1 : 1;
            KUINT8 m_ui8Layer1   : 1;
            KUINT8 m_ui8Layer2   : 1;
            KUINT8 m_ui8NotUsed2 : 5;
        };

        KUINT8 m_ui8InfoLayers;
    };

    KUINT8 m_ui8Modifier; // Not used

    union
    {
        struct
        {
            KUINT16 m_ui16ResponseCode              : 5;
            KUINT16 m_ui16ResponseNotUsed1          : 6;
            KUINT16 m_ui16ResponsePowerReduction    : 1;
            KUINT16 m_ui16ResponseRadarEnhancement  : 1;
            KUINT16 m_ui16ResponseStatus            : 1;
            KUINT16 m_ui16ResponseDmg               : 1;
            KUINT16 m_ui16ResponseMalfunction       : 1;
        };

        KUINT16 m_ui16Param1; // Parameter 1 - RRB Response
    };

    KUINT16 m_ui16Param2; // Not used

    KUINT16 m_ui16Param3; // Not used

    KUINT16 m_ui16Param4; // Not used

    KUINT16 m_ui16Param5; // Not used

    KUINT16 m_ui16Param6; // Not used

public:

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_RRB::SetSystemStatus
    //              KDIS::DATA_TYPE::FundamentalOperationalData_RRB::GetSystemStatus
    // Description: Specifies whether the entire system is operational
    //              and which modes it is capable of.
    // Parameter:   KBOOL, void
    //************************************
    void SetSystemStatus( KBOOL IsSystemOn, KBOOL IsParam1Capable, KBOOL IsParam2Capable,
                          KBOOL IsParam3Capable, KBOOL IsParam4Capable, KBOOL IsParam5Capable,
                          KBOOL IsParam6Capable, KBOOL IsOperational );
    void SetSystemStatusSystemOn( KBOOL IsSystemOn );
    void SetSystemStatusParam1Capable( KBOOL IsParamCapable );
    void SetSystemStatusParam2Capable( KBOOL IsParamCapable );
    void SetSystemStatusParam3Capable( KBOOL IsParamCapable );
    void SetSystemStatusParam4Capable( KBOOL IsParamCapable );
    void SetSystemStatusParam5Capable( KBOOL IsParamCapable );
    void SetSystemStatusParam6Capable( KBOOL IsParamCapable );
    void SetSystemStatusIsOperational( KBOOL IsOperational );
    KBOOL GetSystemStatusSystemOn() const;
    KBOOL GetSystemStatusParam1Capable() const;
    KBOOL GetSystemStatusParam2Capable() const;
    KBOOL GetSystemStatusParam3Capable() const;
    KBOOL GetSystemStatusParam4Capable() const;
    KBOOL GetSystemStatusParam5Capable() const;
    KBOOL GetSystemStatusParam6Capable() const;
    KBOOL GetSystemStatusIsOperational() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_RRB::SetInfomationLayer
    //              KDIS::DATA_TYPE::FundamentalOperationalData_RRB::IsInfomationLayerPresent
    // Description: Used for an alternative representation of parameter 4
    // Parameter:   KBOOL, void
    //************************************
    void SetInfomationLayersPresence( KBOOL IsLayer1Present, KBOOL IsLayer2Present );
    void SetInfomationLayer1( KBOOL IsPresent );
    void SetInfomationLayer2( KBOOL IsPresent );
    KBOOL IsInfomationLayer1Present() const;
    KBOOL IsInfomationLayer2Present() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FundamentalOperationalData_RRB::SetResponse
    //              KDIS::DATA_TYPE::FundamentalOperationalData_RRB::GetResponse
    // Description: Parameter 1 data - RRB Response
    //              Note RRB codes are not octal codes. The complete RRB
    //              code is stored as a decimal number in the specified bits
    // Parameter:   KBOOL, void, KUINT8
    //************************************
    void SetResponse( KUINT8 Code, KBOOL PowerReduction, KBOOL RadarEnhancement,
                      KBOOL IsStatusOn, KBOOL IsDamaged, KBOOL IsMalfunctioning );
    void SetResponseCode( KUINT8 C );
    void SetResponsePowerReduction( KBOOL PR );
    void SetResponseRadarEnhancement( KBOOL RE );
    void SetResponseStatus( KBOOL IsOn );
    void SetResponseDamage( KBOOL IsDamaged );
    void SetResponseMalfunction( KBOOL IsMalfunctioning );
    KUINT8 GetResponseCode() const;
    KBOOL GetResponsePowerReduction() const;
    KBOOL GetResponseRadarEnhancement() const;
    KBOOL IsResponseStatusOn() const;
    KBOOL IsResponseDamaged() const;
    KBOOL IsResponseMalfunctioning() const;

    KBOOL operator == ( const FundamentalOperationalData_RRB & Value ) const;
    KBOOL operator != ( const FundamentalOperationalData_RRB & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

