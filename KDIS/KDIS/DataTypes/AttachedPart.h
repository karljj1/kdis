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
    class:      AttachedPart
    updated:    08/03/2013
    author:     Karl Jones

    purpose:    

    size:       128 bits / 16 octets
*********************************************************************/

#pragma once

#include "./VariableParameter.h"
#include "./EntityType.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT AttachedPart : public VariableParameter
{
protected:

	KUINT8 m_ui8DetachedIndicator;
	
	KUINT16 m_ui16PartAttachedToID;

    KUINT32 m_ui32ParamTypeVariant;

	EntityType m_AttachedPartType;

public:

    AttachedPart();

    AttachedPart( KDataStream & stream ) throw( KException );

    virtual ~AttachedPart();

	//************************************
    // FullName:    KDIS::DATA_TYPE::AttachedPart::SetDetachedIndicator
    //              KDIS::DATA_TYPE::AttachedPart::GetDetachedIndicator
    // Description: Indicates whether an attached part is attached or detached. 
	//              This field shall be set to Attached(0) to indicate the part 
	//              is attached and to Detached(1) if the part becomes detached.
    // Parameter:   KUINT8 DI
    //************************************
	void SetDetachedIndicator( KUINT8 DI );
	KUINT8 GetDetachedIndicator() const;

	//************************************
    // FullName:    KDIS::DATA_TYPE::AttachedPart::SetPartAttachedToID
    //              KDIS::DATA_TYPE::AttachedPart::GetPartAttachedToID
    // Description: The identification of the articulated or attached part to
	//              which this attached part is attached.
	//              Should contain the value zero if the attached part is
	//              attached directly to the entity.
    // Parameter:   KUINT16 ID
    //************************************
	void SetPartAttachedToID( KUINT16 ID );
	KUINT16 GetPartAttachedToID() const;










    //************************************
    // FullName:    KDIS::DATA_TYPE::AttachedPart::SetTypeVariant
    //              KDIS::DATA_TYPE::AttachedPart::GetTypeVariant
    // Description: 
    // Parameter:   KUINT32 TV
    //************************************
    void SetTypeVariant( KUINT32 TV );
    KUINT32 GetTypeVariant() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AttachedPart::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AttachedPart::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::AttachedPart::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const AttachedPart & Value ) const;
    KBOOL operator != ( const AttachedPart & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
