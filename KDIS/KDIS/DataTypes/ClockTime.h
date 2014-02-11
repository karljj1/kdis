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
    class:      ClockTime
    created:    18/09/2008
    author:     Karl Jones

    purpose:    Time measurements that surpass 1 hour are represented
                by ClockTime. Time represented are either real world (UTC)
                or simulation time.
    size:       64 bits / 8 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT ClockTime : public DataTypeBase
{
protected:

    KINT32 m_i32Hour;

    KUINT32 m_ui32TimePastHour;

public:

    static const KUINT16 CLOCK_TIME_SIZE = 8;

    ClockTime();

    ClockTime( KINT32 Hour, KUINT32 TimePastHour );

    ClockTime( KDataStream & stream ) throw( KException );

    virtual ~ClockTime();

    //************************************
    // FullName:    KDIS::DATA_TYPE::ClockTime::SetHour
    //              KDIS::DATA_TYPE::ClockTime::GetHour
    // Description: Time.
    // Parameter:   KINT32 H, void
    //************************************
    void SetHour( KINT32 H );
    KINT32 GetHour() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ClockTime::SetTimePastHour
    //              KDIS::DATA_TYPE::ClockTime::GetTimePastHour
    // Description: Time Past Hour. The time past the hour field.
    // Parameter:   KFLOAT32 Z, void
    //************************************
    void SetTimePastHour( KUINT32 TPH );
    KUINT32 GetTimePastHour() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ClockTime::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::ClockTime::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::ClockTime::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const ClockTime & Value ) const;
    KBOOL operator != ( const ClockTime & Value ) const;
    KBOOL operator  < ( const ClockTime & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

