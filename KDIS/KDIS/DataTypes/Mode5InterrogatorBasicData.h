/*********************************************************************
Copyright 2013 KDIS
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
    class:      Mode5InterrogatorBasicData
    DIS:        (7) 1278.1 - 2012
    created:    30/09/2013
    author:     Karl Jones

    purpose:    Included in the Mode 5 Interrogator format for Layer 3 of the IFF PDU.

    Size:       128 bits / 16 octets 
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT Mode5InterrogatorBasicData : public DataTypeBase
{
protected:

	// TODO: YOU ARE HERE!!!!
	// Mode5InterrogatorStatus

public:

    static const KUINT16 MODE_5_INTERROGATOR_BASIC_DATA_SIZE = 16; 

    Mode5InterrogatorBasicData();

    Mode5InterrogatorBasicData( KDataStream & stream ) throw( KException );

    virtual ~Mode5InterrogatorBasicData();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5InterrogatorBasicData::etMessageFormatPrese
    //              KDIS::DATA_TYPE::Mode5InterrogatorBasicData::IsMessageFormatPresent
	//              KDIS::DATA_TYPE::Mode5InterrogatorBasicData::SetMessageFormatPresentFlags
	//              KDIS::DATA_TYPE::Mode5InterrogatorBasicData::GetMessageFormatPresentFlags
    // Description: Set/Get the bit/flag to indicate if the message format is present.
    // Parameter:   KUINT8 MF - Message format. Exception thrown if not between 0-31.
	// Parameter:   KBOOL P - Present?
    //************************************
 //   void SetMessageFormatPresent( KUINT8 MF, KBOOL P ) throw( KException );	
 //   KBOOL IsMessageFormatPresent( KUINT8 MF ) const throw( KException );
	//void SetMessageFormatPresentFlags( KINT32 All );
	//KUINT32 GetMessageFormatPresentFlags() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5InterrogatorBasicData::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5InterrogatorBasicData::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5InterrogatorBasicData::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Mode5InterrogatorBasicData & Value ) const;
    KBOOL operator != ( const Mode5InterrogatorBasicData & Value ) const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
