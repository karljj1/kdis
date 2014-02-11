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
    class:      TimeStamp
    created:    16/10/2008
    author:     Karl Jones

    purpose:    Stores absolute/ relative timestamps.
                Timestamps are used to reduce the error in a simulation.

                A lot of DIS simulators simply ignore timestamps however if error(I.E inaccuracy
                between a entities position and its actual position) is an issue then the timestamp
                can be used to reduce this error.

                Absolute timestamps tend to require the use of very accurate and expesnive clocks which are synchronized.
                Relative timestamps are less accurate and tend to use the computers internal clock.

                The following is taken straight from the DIS standard:
                "To make sure that relative timestamps are synchronized, you need to compare information about a received
                PDU that contains a relative timestamp with the time you are maintaining in your simulation application.
                This is done using software and without any special hardware. It does require that a few packets be observed
                before time is well synchronized. As packets are received, the difference between their relative timestamps
                and the receiver's clock is averaged. This average will correspond to the average latency, and the difference
                represents clock skew. After a few dozen packets, the difference between the observed average and the real
                average latency is around 5ms. After several hundred, the difference is in the 1ms neighborhood. This is not
                as long a time to wait as might be imagined. A dozen ES PDU's per minute are emitted by simulators for
                entities which are stopped. Thus, a few minutes of idle time before the exercise starts provides data for 5ms
                accuracy, and at 1-2 PDU's per second while moving, 1ms accuracy can be had in a matter of minutes.
                Exercises with stricter needs really should use absolute based time."

    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT TimeStamp : public DataTypeBase
{
protected:

    union
    {
        struct
        {
            KUINT32 m_ui32TimeStampType : 1;
            KUINT32 m_ui32Time          : 31;
        };
        KUINT32 m_ui32TimeStamp;
    } m_TimeStampUnion;

    KBOOL m_bAutoCalcRel;

public:

    static const KUINT16 TIME_STAMP_SIZE = 4;

    TimeStamp();

    TimeStamp( KDataStream & stream )throw( KException );

    TimeStamp( KDIS::DATA_TYPE::ENUMS::TimeStampType T, KUINT32 Time, KBOOL AutoCalcRelative = false);

    virtual ~TimeStamp();

    //************************************
    // FullName:    KDIS::DATA_TYPE::TimeStamp::SetTimeStampType
    //              KDIS::DATA_TYPE::TimeStamp::GetTimeStampType
    // Description: Set the time stamp type, Absolute or Relative.
    // Parameter:   TimeStampType T
    //************************************
    void SetTimeStampType( KDIS::DATA_TYPE::ENUMS::TimeStampType T );
    KDIS::DATA_TYPE::ENUMS::TimeStampType GetTimeStampType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::TimeStamp::SetTime
    //              KDIS::DATA_TYPE::TimeStamp::GetTime
    // Description: Time value. Scale of the time is determined
    //              by setting one hour equal to (2^31 - 1), thereby resulting
    //              in each time unit representing 3600 s/( 2^31 - 1 ) = 1.676 micro secs
    //              or 0.000001676 seconds. See EnumHeader.h for further details.
    //              Note: SetTimeStampAutoCalculate to true to allow KDIS to handle the time stamp.
    // Parameter:   TimeStampType T
    //************************************
    void SetTime( KUINT32 T );
    KUINT32 GetTime() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::TimeStamp::SetTimeStampAutoCalculate
    //              KDIS::DATA_TYPE::TimeStamp::IsTimeStampAutoCalculated
    // Description: Do you want the time stamp to be automatically calculated?
    //              Setting this to true will cause CalculateTimeStamp to be called every time
    //              the PDU is encoded.
    // Parameter:   KBOOL A
    //************************************
    void SetTimeStampAutoCalculate( KBOOL A );
    KBOOL IsTimeStampAutoCalculated() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::TimeStamp::CalculateRelativeTimeStamp
    // Description: Automatically calculates the timestamp for this moment in time.
    //************************************
    void CalculateTimeStamp();

    //************************************
    // FullName:    KDIS::DATA_TYPE::TimeStamp::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::TimeStamp::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::TimeStamp::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const TimeStamp & Value ) const;
    KBOOL operator != ( const TimeStamp & Value ) const;

    // Note: No check is made if the time stamps are of the same type.
    KBOOL operator < ( const TimeStamp & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
