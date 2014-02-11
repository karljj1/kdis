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

    SimulationIdentifier();

    SimulationIdentifier( KUINT16 SiteID, KUINT16 ApplicatonID );

    SimulationIdentifier( KDataStream & stream ) throw( KException );

    virtual ~SimulationIdentifier();

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
    // Parameter:   KUINT16 ID
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
    // Parameter:   KUINT16 ID
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

} // END namespace DATA_TYPES
} // END namespace KDIS

