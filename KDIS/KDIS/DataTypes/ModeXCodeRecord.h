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
    class:      ModeXCodeRecord
    DIS:        (7) 1278.1 - 2012
    created:    30/03/2014
    author:     Karl Jones

    purpose:    Base class for many of the Mode Code records, contains the shared properties.

    Size:       16 bits / 2 octets 
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT ModeXCodeRecord : public DataTypeBase
{
protected:
	
	union
	{
		struct
		{
			KUINT16 m_ui16Bits0_2   : 3;
			KUINT16 m_ui16Bits3_5   : 3;
			KUINT16 m_ui16Bits6_8   : 3;
			KUINT16 m_ui16Bits9_11  : 3;
			KUINT16 m_ui16Padding   : 1;
			KUINT16 m_ui16OnOff     : 1;
			KUINT16 m_ui16Dmg       : 1;
			KUINT16 m_ui16MalFnc    : 1;
		};
		KUINT16 m_ui16Code;

	} m_CodeUnion;
	
public:

    static const KUINT16 MODE_X_CODE_RECORD_SIZE = 2; 

    ModeXCodeRecord();

    ModeXCodeRecord( KDataStream & stream ) throw( KException );

    virtual ~ModeXCodeRecord();

	//************************************
    // FullName:    KDIS::DATA_TYPE::ModeXCodeRecord::SetStatus
    //              KDIS::DATA_TYPE::ModeXCodeRecord::GetStatus
    // Description: Indicates whether the device is On (true or Off (false).
    // Parameter:   KBOOL S
    //************************************
	void SetStatus( KBOOL S );
	KBOOL GetStatus() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::ModeXCodeRecord::SetDamaged
    //              KDIS::DATA_TYPE::ModeXCodeRecord::IsDamaged
    // Description: Indicates whether there is damage to the device.
    // Parameter:   KBOOL S
    //************************************
	void SetDamaged( KBOOL D );
	KBOOL IsDamaged() const;
		
	//************************************
    // FullName:    KDIS::DATA_TYPE::ModeXCodeRecord::SetMalfunctioning
    //              KDIS::DATA_TYPE::ModeXCodeRecord::IsMalfunctioning
    // Description: Indicates whether there is damage to the device.
    // Parameter:   KBOOL M
    //************************************
	void SetMalfunctioning( KBOOL M );
	KBOOL IsMalfunctioning() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModeXCodeRecord::GetAsString
    // Description: Returns a string representation 
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModeXCodeRecord::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModeXCodeRecord::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const ModeXCodeRecord & Value ) const;
    KBOOL operator != ( const ModeXCodeRecord & Value ) const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
