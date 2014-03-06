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
    class:      EnhancedMode1Code
    DIS:        (7) 1278.1 - 2012
    created:    6/03/2014
    author:     Karl Jones

    purpose:    

    Size:       16 bits / 2 octets 
*********************************************************************/

#pragma once

#include "./LayerHeader.h"
#include "./SimulationIdentifier.h"
#include "./Mode5MessageFormats.h"
#include "./Mode5InterrogatorBasicData.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT EnhancedMode1Code : public LayerHeader
{
protected:
	
	// TODO: YOU ARE HERE. Look at Mode 1 Code. Changes needed to FOD?
	// A lot of classes have the on/off, dmg and mal func bits. Maybe put it into one base class?

	union
	{
		struct
		{
			KUINT16 m_ui16Element1 : 3;
			KUINT16 m_ui16Element2 : 3;
			KUINT16 m_ui16Element3 : 3;
			KUINT16 m_ui16Element4 : 3;
			KUINT16 m_ui16Padding  : 1;
			KUINT16 m_ui16OnOff    : 1;
			KUINT16 m_ui16Dmg      : 1;
			KUINT16 m_ui16MalFnc   : 1;
		};
		KUINT16 m_ui16Code;

	} m_CodeUnion;
	
public:

    static const KUINT16 ENHANCED_MODE_1_CODE_SIZE = 2; 

    EnhancedMode1Code();

    EnhancedMode1Code( KDataStream & stream ) throw( KException );

    virtual ~EnhancedMode1Code();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnhancedMode1Code::SetReportingSimulation
    //              KDIS::DATA_TYPE::EnhancedMode1Code::GetReportingSimulation
    // Description: The simulation reporting this IFF PDU.
    // Parameter:   const SimulationIdentifier & RS
    //************************************
    //void SetReportingSimulation( const SimulationIdentifier & RS );
    //const SimulationIdentifier & GetReportingSimulation() const;
    //SimulationIdentifier & GetReportingSimulation();
	







    //************************************
    // FullName:    KDIS::DATA_TYPE::EnhancedMode1Code::GetAsString
    // Description: Returns a string representation 
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnhancedMode1Code::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnhancedMode1Code::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EnhancedMode1Code & Value ) const;
    KBOOL operator != ( const EnhancedMode1Code & Value ) const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
