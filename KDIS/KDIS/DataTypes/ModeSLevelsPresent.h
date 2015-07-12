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
    class:      ModeSLevelsPresent
    DIS:        (7) 1278.1 - 2012
    created:    12/08/2015
    author:     Karl Jones

    purpose:    Indicates which Mode S levels this transponder or
				interrogator is able to support. 

    Size:       8 bits / 1 octet
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT ModeSLevelsPresent : public DataTypeBase
{
protected:
	
    union
    {
        struct
        {
			KUINT8 m_ui8Unused1        : 1;
            KUINT8 m_ui8Lvl1           : 1;
			KUINT8 m_ui8Lvl2Elementary : 1;
			KUINT8 m_ui8Lvl2Enhanced   : 1;
			KUINT8 m_ui8Lvl3           : 1;
			KUINT8 m_ui8Lvl4           : 1;
            KUINT8 m_ui8Unused2        : 2;
        };
        KUINT8 m_ui8LevelsPresent;
    } m_LevelsUnion;
	
public:

    static const KUINT16 MODE_S_LEVELS_PRESENT_SIZE = 1; 

    ModeSLevelsPresent();

    ModeSLevelsPresent( KDataStream & stream ) throw( KException );

	ModeSLevelsPresent( KBOOL Lvl1, KBOOL Lvl2Elementary, KBOOL Lvl2Enhanced, KBOOL Lvl3, KBOOL Lvl4 );

    virtual ~ModeSLevelsPresent();


	//************************************
	// FullName:    KDIS::DATA_TYPE::ModeSLevelsPresent::SetLevelPresent
	//              KDIS::DATA_TYPE::ModeSLevelsPresent::IsLevelPresent	
	// Description: Indicates whether the level is present.
	// Parameter:   KBOOL LP
	//************************************
	void SetLevel1Present( KBOOL LP );
	void SetLevel2ElementarySublevelPresent( KBOOL LP );
	void SetLevel2EnhancedSublevelPresent( KBOOL LP );
	void SetLevel3Present( KBOOL LP );
	void SetLevel4Present( KBOOL LP );
	KBOOL IsLevel1Present() const;
	KBOOL IsLevel2ElementarySublevelPresent() const;
	KBOOL IsLevel2EnhancedSublevelPresent() const;
	KBOOL IsLevel3Present() const;
	KBOOL IsLevel4Present() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModeSLevelsPresent::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModeSLevelsPresent::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ModeSLevelsPresent::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const ModeSLevelsPresent & Value ) const;
    KBOOL operator != ( const ModeSLevelsPresent & Value ) const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
