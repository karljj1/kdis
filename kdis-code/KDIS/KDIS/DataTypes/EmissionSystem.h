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
    class:      EmissionSystem
    created:    2008/010/19

    author:     Karl Jones

    purpose:    Contains information about a emission system
    size:       160 bits / 20 octets min size
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./EmitterSystem.h"
#include "./Vector.h"
#include "./EmitterBeam.h"
#include <vector>

namespace KDIS {
namespace DATA_TYPE {

using std::vector;

class KDIS_EXPORT EmissionSystem : public DataTypeBase
{
protected:

    KUINT8 m_ui8SystemDataLength;

    KUINT8 m_ui8NumberOfBeams;

    KUINT16 m_ui16Padding;

    EmitterSystem m_EmitterSystemRecord;

    Vector m_Location;

    vector<EmitterBeam> m_vEmitterBeams;

public:

    static const KUINT16 EMISSION_SYSTEM_SIZE = 20; // Min Size

    EmissionSystem( void );

    EmissionSystem( KDataStream & stream )throw( KException );

    EmissionSystem( const EmitterSystem & ESR, const Vector & Location );

    virtual ~EmissionSystem( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmissionSystem::GetSystemDataLength
    // Description: Length of the emission system in 32 bit words.
    //              E.G 1 = 32 bits / 4 octets. Calculated automatically.
    //************************************
    KUINT8 GetSystemDataLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmissionSystem::SetEmitterSystemRecord
    //              KDIS::DATA_TYPE::EmissionSystem::GetEmitterSystemRecord
    // Description: Contains information about a particular emitter system
    // Parameter:   const EmitterSystem & ESR
    //************************************
    void SetEmitterSystemRecord( const EmitterSystem & ESR );
    EmitterSystem GetEmitterSystemRecord() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmissionSystem::SetLocation
    //              KDIS::DATA_TYPE::EmissionSystem::GetLocation
    // Description: Location of antenna beam source with respect to emitting
    //              entity coordinate system. Represented as Entity Coordinate Vector.
    // Parameter:   const Vector & L
    //************************************
    void SetLocation( const Vector & L );
    const Vector & GetLocation() const;
    Vector & GetLocation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmissionSystem::AddEmitterBeam
    //              KDIS::DATA_TYPE::EmissionSystem::SetEmitterBeams
    //              KDIS::DATA_TYPE::EmissionSystem::GetEmitterBeams
    // Description: The emitter beans attached to this system.
    // Parameter:   const EmitterBeam & EB, const vector<EmitterBeam> & Beams
    //************************************
    void AddEmitterBeam( const EmitterBeam & EB );
    void SetEmitterBeams( const vector<EmitterBeam> & Beams );
    const vector<EmitterBeam> & GetEmitterBeams() const;
    void ClearEmitterBeams();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmissionSystem::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmissionSystem::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmissionSystem::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EmissionSystem & Value ) const;
    KBOOL operator != ( const EmissionSystem & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
