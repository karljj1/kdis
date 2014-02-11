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
    class:      MinefieldAppearance
    created:    04/05/2010
    author:     Karl Jones

    purpose:    Represents the appearance bits of the Minefield State PDU.
    size:       16 bits / 2 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT MinefieldAppearance : public DataTypeBase
{
protected:

    union
    {
        struct
        {
            KUINT16 m_ui16Type         : 2;
            KUINT16 m_ui16ActiveStatus : 1;
            KUINT16 m_ui16Lane         : 1;
            KUINT16 m_ui16Unused1      : 9;
            KUINT16 m_ui16State        : 1;
            KUINT16 m_ui16Unused       : 2;
        };
        KUINT16 m_ui16App;
    } m_ui16BitUnion;

public:

    static const KUINT16 MINEFIELD_APPEARANCE_SIZE = 2;

    MinefieldAppearance();

    MinefieldAppearance( KDIS::DATA_TYPE::ENUMS::MinefieldType T, KBOOL IsStatusActive, KBOOL IsLaneActive, KBOOL IsStateActive );

    MinefieldAppearance( KDataStream & stream ) throw( KException );

    virtual ~MinefieldAppearance();

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldAppearance::SetMinefieldType
    //              KDIS::DATA_TYPE::MinefieldAppearance::GetMinefieldType
    // Description: The type of mines in the minefield. Anti personnel, anti tank or mixed.
    // Parameter:   MinefieldType T
    //************************************
    void SetMinefieldType( KDIS::DATA_TYPE::ENUMS::MinefieldType T );
    KDIS::DATA_TYPE::ENUMS::MinefieldType GetMinefieldType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldAppearance::SetStatusActive
    //              KDIS::DATA_TYPE::MinefieldAppearance::IsStatusActive
    // Description: Identifies the active status of the minefield.
    //              Note: The DIS standard(SISO-REF-010-2006) specifies 0 for true and 1 for false however they are
    //              flipped internally by KDIS so you can use true and false as you would expect to.
    // Parameter:   KBOOL A
    //************************************
    void SetStatusActive( KBOOL A );
    KBOOL IsStatusActive() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldAppearance::SetLaneActive
    //              KDIS::DATA_TYPE::MinefieldAppearance::IsLaneActive
    // Description: Identifies whether the minefield has an active lane.
    //              Note: The DIS standard(SISO-REF-010-2006) specifies 0 for true and 1 for false however they are
    //              flipped internally by KDIS so you can use true and false as you would expect to.
    // Parameter:   KBOOL A
    //************************************
    void SetLaneActive( KBOOL A );
    KBOOL IsLaneActive() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldAppearance::SetStateActive
    //              KDIS::DATA_TYPE::MinefieldAppearance::IsStateActive
    // Description: Describes the state of the minefield.
    //              Note: The DIS standard(SISO-REF-010-2006) specifies 0 for true and 1 for false however they are
    //              flipped internally by KDIS so you can use true and false as you would expect to.
    // Parameter:   KBOOL A
    //************************************
    void SetStateActive( KBOOL A );
    KBOOL IsStateActive() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldAppearance::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldAppearance::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::MinefieldAppearance::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const MinefieldAppearance & Value ) const;
    KBOOL operator != ( const MinefieldAppearance & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

