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
    class:      AggregateIdentifier
    created:    07/02/2009
    author:     Karl Jones

    purpose:    Aggregate Identifier Field. Used only to provide a unique,
                exercise-wide number to identify aggregates and/or to
                address specific simulation applications.
    size:       48 bits / 6 octets
*********************************************************************/

#pragma once

#include "./SimulationIdentifier.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT AggregateIdentifier : public SimulationIdentifier
{
protected:

    KUINT16 m_ui16AggregateID;

public:

    static const KUINT16 AGGREGATE_IDENTIFER_SIZE = 6;

    AggregateIdentifier( void );

    AggregateIdentifier( KUINT16 SiteID, KUINT16 ApplicatonID, KUINT16 AggregateID );

    AggregateIdentifier( const SimulationIdentifier & SimID, KUINT16 AggregateID );

    AggregateIdentifier( KDataStream & stream ) throw( KException );

    virtual ~AggregateIdentifier( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateIdentifier::SetAggregateID
    //              KDIS::DATA_TYPE::AggregateIdentifier::GetAggregateID
    // Description: Aggregate ID
    // Parameter:   KUINT16 ID, void
    //************************************
    void SetAggregateID( KUINT16 ID );
    KUINT16 GetAggregateID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateIdentifier::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateIdentifier::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::AggregateIdentifier::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const AggregateIdentifier & Value ) const;
    KBOOL operator != ( const AggregateIdentifier & Value ) const;
    KBOOL operator  < ( const AggregateIdentifier & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

