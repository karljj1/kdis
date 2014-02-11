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

} // END namespace DATA_TYPES
} // END namespace KDIS

