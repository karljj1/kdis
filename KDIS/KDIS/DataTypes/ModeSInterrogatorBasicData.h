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
    class:      ModeSInterrogatorBasicData
    DIS:        (7) 1278.1 - 2012
    created:    11/08/2015
    author:     Karl Jones

    purpose:    Mode S Interrogator Basic Data record is included in the Mode S Interrogator format for Layer 4.

    Size:       192 bits / 24 octets 
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./ModeSInterrogatorStatus.h"
#include "./ModeSLevelsPresent.h"
#include <bitset>

namespace KDIS {
namespace DATA_TYPE {
	
class KDIS_EXPORT ModeSInterrogatorBasicData : public DataTypeBase
{
protected:
	
	ModeSInterrogatorStatus m_Status;

	KUINT8 m_ui8Padding;

	ModeSLevelsPresent m_LvlsPresent;

	KUINT8 m_ui8Padding2;

	KUINT32 m_ui32Padding[5];

public:

    static const KUINT16 MODE_S_INTERROGATOR_BASIC_DATA_SIZE = 24; 

    ModeSInterrogatorBasicData();

	ModeSInterrogatorBasicData( const ModeSInterrogatorStatus & S, const ModeSLevelsPresent & LP );

    ModeSInterrogatorBasicData( KDataStream & stream ) throw( KException );

    virtual ~ModeSInterrogatorBasicData();

	//************************************
	// FullName:    KDIS::DATA_TYPE::ModeSInterrogatorBasicData::SetStatus
	//              KDIS::DATA_TYPE::ModeSInterrogatorBasicData::GetStatus	
	// Description: The Mode 5 Message Formats supported by this Mode 5 interrogator.
	// Parameter:   const ModeSInterrogatorStatus & S
	//************************************
	void SetStatus( const ModeSInterrogatorStatus & S );
	const ModeSInterrogatorStatus & GetStatus() const;
	ModeSInterrogatorStatus & GetStatus();

	//************************************
	// FullName:    KDIS::DATA_TYPE::ModeSInterrogatorBasicData::SetLevelsPresent
	//              KDIS::DATA_TYPE::ModeSInterrogatorBasicData::GetLevelsPresent	
	// Description: All levels that would be able to be responded to for a Mode S interrogation.
	// Parameter:   const ModeSLevelsPresent & LP
	//************************************
	void SetLevelsPresent( const ModeSLevelsPresent & LP );
	const ModeSLevelsPresent & GetLevelsPresent() const;
	ModeSLevelsPresent & GetLevelsPresent();

	//************************************
    // FullName:    KDIS::DATA_TYPE::ModeSInterrogatorBasicData::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModeSInterrogatorBasicData::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModeSInterrogatorBasicData::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const ModeSInterrogatorBasicData & Value ) const;
    KBOOL operator != ( const ModeSInterrogatorBasicData & Value ) const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
