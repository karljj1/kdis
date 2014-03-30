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

    purpose:    Mode 5 Enhanced Mode 1 information. 

    Size:       16 bits / 2 octets 
*********************************************************************/

#pragma once

#include "./ModeXCodeRecord.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT EnhancedMode1Code : public ModeXCodeRecord
{
public:

    EnhancedMode1Code();

    EnhancedMode1Code( KDataStream & stream ) throw( KException );

    virtual ~EnhancedMode1Code();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EnhancedMode1Code::SetCodeElement1
    //              KDIS::DATA_TYPE::EnhancedMode1Code::GetCodeElement1
    // Description: Element 1 of the Enhanced Mode 1 code also known as Code Element D.
	//              Value must be between 0-7.
    // Parameter:   KUINT8 CE
    //************************************
    void SetCodeElement1( KUINT8 CE );    
    KUINT8 GetCodeElement1();
	
    //************************************
    // FullName:    KDIS::DATA_TYPE::EnhancedMode1Code::SetCodeElement2
    //              KDIS::DATA_TYPE::EnhancedMode1Code::GetCodeElement2
    // Description: Element 2 of the Enhanced Mode 1 code also known as Code Element C.
	//              Value must be between 0-7.
    // Parameter:   KUINT8 CE
    //************************************
    void SetCodeElement2( KUINT8 CE );    
    KUINT8 GetCodeElement2();
	
    //************************************
    // FullName:    KDIS::DATA_TYPE::EnhancedMode1Code::SetCodeElement3
    //              KDIS::DATA_TYPE::EnhancedMode1Code::GetCodeElement3
    // Description: Element 3 of the Enhanced Mode 1 code also known as Code Element B.
	//              Value must be between 0-7.
    // Parameter:   KUINT8 CE
    //************************************
    void SetCodeElement3( KUINT8 CE );    
    KUINT8 GetCodeElement3();
	
    //************************************
    // FullName:    KDIS::DATA_TYPE::EnhancedMode1Code::SetCodeElement4
    //              KDIS::DATA_TYPE::EnhancedMode1Code::GetCodeElement4
    // Description: Element 4 of the Enhanced Mode 1 code also known as Code Element A.
	//              Value must be between 0-7.
    // Parameter:   KUINT8 CE
    //************************************
    void SetCodeElement4( KUINT8 CE );    
    KUINT8 GetCodeElement4();
	
    //************************************
    // FullName:    KDIS::DATA_TYPE::EnhancedMode1Code::GetAsString
    // Description: Returns a string representation 
    //************************************
    virtual KString GetAsString() const;
};

} // END namespace DATA_TYPE
} // END namespace KDIS
