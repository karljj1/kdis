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
    class:      DEAreaAimpoint
    created:    22/04/2013
    author:     Karl Jones

    purpose:   

    size:       xx bits / x octets - xx
*********************************************************************/

#pragma once

#include "./StandardVariable.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT DEAreaAimpoint : public StandardVariable
{
protected:

	KUINT16 m_ui16Padding;

	KUINT16 m_ui16BAPRC;

	KUINT16 m_ui16DETEDRC;

	// TODO: Beam Ant Pattern

	// TODO: DE Target Energy Dep Rec
	
public:

    static const KUINT16 DE_AREA_AIMPOINT_SIZE = 00000000000;

    DEAreaAimpoint();

    DEAreaAimpoint( KDataStream & stream ) throw( KException );

    virtual ~DEAreaAimpoint();

	//************************************
    // FullName:    KDIS::DATA_TYPE::DEAreaAimpoint::GetBeamAntennaPatternCount
    // Description: The count of Beam Antenna Pattern records that are included as part of this record.
    //************************************
	KUINT16 GetBeamAntennaPatternCount() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::DEAreaAimpoint::GetTargetEnergyDepositionCount
    // Description: The count of DE Target Energy Deposition records that are included as part of this record. 
    //************************************
	KUINT16 GetTargetEnergyDepositionCount() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::DEAreaAimpoint::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::DEAreaAimpoint::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::DEAreaAimpoint::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const DEAreaAimpoint & Value ) const;
    KBOOL operator != ( const DEAreaAimpoint & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
