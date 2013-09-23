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
    class:      Mode5MessageFormats
    DIS:        (7) 1278.1 - 2012
    created:    23/09/2013
    author:     Karl Jones

    purpose:    Mode 5 Message Formats this Mode 5 transponder is capable of supporting 
	            and could be in a reply to an interrogation. 
				
    Size:       32 bits / 4 octets 
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include <bitset>

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT Mode5MessageFormats : public DataTypeBase
{
protected:

	std::bitset<32> m_msgFormats;	

public:

    static const KUINT16 MODE_5_MESSAGE_FORMATS_SIZE = 4; 

    Mode5MessageFormats();

    Mode5MessageFormats( KDataStream & stream ) throw( KException );

    virtual ~Mode5MessageFormats();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5MessageFormats::etMessageFormatPrese
    //              KDIS::DATA_TYPE::Mode5MessageFormats::IsMessageFormatPresent
	//              KDIS::DATA_TYPE::Mode5MessageFormats::SetMessageFormatPresentFlags
	//              KDIS::DATA_TYPE::Mode5MessageFormats::GetMessageFormatPresentFlags
    // Description: Set/Get the bit/flag to indicate if the message format is present.
    // Parameter:   KUINT8 MF - Message format. Exception thrown if not between 0-31.
	// Parameter:   KBOOL P - Present?
    //************************************
    void SetMessageFormatPresent( KUINT8 MF, KBOOL P ) throw( KException );	
    KBOOL IsMessageFormatPresent( KUINT8 MF ) const throw( KException );
	void SetMessageFormatPresentFlags( KINT32 All );
	KUINT32 GetMessageFormatPresentFlags() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5MessageFormats::GetAsString
    // Description: Returns a string representation
    //              of the PDU.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5MessageFormats::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::Mode5MessageFormats::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Mode5MessageFormats & Value ) const;
    KBOOL operator != ( const Mode5MessageFormats & Value ) const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
