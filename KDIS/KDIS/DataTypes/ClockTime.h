/*********************************************************************

KDIS is free software; you can redistribute it and/or modify it under the
terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option)
any later version.

KDIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this library; if not, write to the Free Software Foundation, Inc.,
59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.

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

    ClockTime( void );

    ClockTime( KINT32 Hour, KUINT32 TimePastHour );

    ClockTime( KDataStream & stream ) throw( KException );

    virtual ~ClockTime( void );

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS

