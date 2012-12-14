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
    class:      SimulationIdentifier
    created:    2009/11/24
    author:     Karl Jones

    purpose:    Simulation Identifier. Site and Application number.
                Also known as the Simulation Address record in DIS 7.

                Note: If you are looking for the DIS 7 Simulation Identifier(the one with the extra 16 bits)
                then see EntityIdentifier.

    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT SimulationIdentifier : public DataTypeBase
{
protected:

    KUINT16 m_ui16SiteID;

    KUINT16 m_ui16ApplicationID;

public:

    static const KUINT16 SIMULATION_IDENTIFIER_SIZE = 4;

    SimulationIdentifier( void );

    SimulationIdentifier( KUINT16 SiteID, KUINT16 ApplicatonID );

    SimulationIdentifier( KDataStream & stream ) throw( KException );

    virtual ~SimulationIdentifier( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::SimulationIdentifier::SetSiteID
    //              KDIS::DATA_TYPE::SimulationIdentifier::GetSiteID
    // Description: Site ID.
    //              A site is defined as a facility, installation, organizational unit or a geographic
    //              location that has one or more simulation applications capable of participating in a
    //              distributed event. A facility, installation, organizational unit or geographic location
    //              may have multiple sites associated with it.
    //              Each site participating in an event (e.g., training exercise, experiment, test) shall be
    //              assigned a unique Site Number that is different from any other site that is part of the same event.
    //              A simulation site is a site that generates simulated objects based on simulated data. A live site
    //              is a site that is associated with producing live objects from live sources such as producing
    //              entities representing live aircraft flying in a live training range. A simulation associated
    //              with a live site may issue Live Entity PDUs (e.g., the TSPI PDU) for the live objects or may
    //              issue Entity State PDUs for them.
    // Parameter:   KUINT16 ID, void
    //************************************
    void SetSiteID( KUINT16 ID );
    KUINT16 GetSiteID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SimulationIdentifier::SetApplicationID
    //              KDIS::DATA_TYPE::SimulationIdentifier::GetApplicationID
    // Description: Application ID.
    //              An application is defined as a software program that is used to generate and process
    //              distributed simulation data including live, virtual and constructive data.
    //              Each application participating in an event (e.g., training exercise) shall be
    //              assigned a unique Application Number for the site with which the application is associated.
    // Parameter:   KUINT16 ID, void
    //************************************
    void SetApplicationID( KUINT16 ID );
    KUINT16 GetApplicationID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SimulationIdentifier::GetAsString
    // Description: Returns a string representation.
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::SimulationIdentifier::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::SimulationIdentifier::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const SimulationIdentifier & Value ) const;
    KBOOL operator != ( const SimulationIdentifier & Value ) const;
    KBOOL operator <  ( const SimulationIdentifier & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

