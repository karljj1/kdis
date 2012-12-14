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
    class:      SecondaryOperationalData
    created:    2009/03/27
    author:     Karl Jones

    purpose:    Conatains additional data for the IFF/ATC/NAVAIDS emitting
                system and the number of fundamental parameter data sets.
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include <vector>

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT SecondaryOperationalData : public DataTypeBase
{
protected:

    KUINT8 m_ui8Param1;

    KUINT8 m_ui8Param2;

    KUINT16 m_ui16NumFundParamSets;

public:

    static const KUINT16 SECONDARY_OPERATIONAL_DATA_SIZE = 4;

    SecondaryOperationalData( void );

    SecondaryOperationalData( KDataStream & stream ) throw( KException );

    SecondaryOperationalData( KUINT8 Param1, KUINT8 Param2, KUINT16 NumFundParamSets );

    virtual ~SecondaryOperationalData( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::SecondaryOperationalData::SetParameter1
    //              KDIS::DATA_TYPE::SecondaryOperationalData::GetParameter1
    // Description: Operational parameter 1. Represented as an enumeration, only
    //              0 is currently defined as Other.
    // Parameter:   const KUINT8 P, void
    //************************************
    void SetParameter1( KUINT8 P );
    KUINT8 GetParameter1() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SecondaryOperationalData::SetParameter2
    //              KDIS::DATA_TYPE::SecondaryOperationalData::GetParameter2
    // Description: Operational parameter 2. Represented as an enumeration, only
    //              0 is currently defined as Other.
    // Parameter:   const KUINT8 P, void
    //************************************
    void SetParameter2( KUINT8 P );
    KUINT8 GetParameter2() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SecondaryOperationalData::SetNumberOfFundamentalParamSets
    //              KDIS::DATA_TYPE::SecondaryOperationalData::GetNumberOfFundamentalParamSets
    // Description: Returns number of Fundamental Parameter Data Sets
    // Paramter:    KUINT8 NFPDS, void
    //************************************
    void SetNumberOfFundamentalParamSets( KUINT8 NFPDS );
    KUINT16 GetNumberOfFundamentalParamSets() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SecondaryOperationalData::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SecondaryOperationalData::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::SecondaryOperationalData::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const SecondaryOperationalData & Value ) const;
    KBOOL operator != ( const SecondaryOperationalData & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

