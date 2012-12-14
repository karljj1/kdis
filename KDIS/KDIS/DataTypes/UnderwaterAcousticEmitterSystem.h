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
    class:      UnderwaterAcousticEmitterSystem
    created:    2009/01/06
    author:     Karl Jones

    purpose:    Contains infomation about a particular Underwater Acoustic emitter
    size:       160 bits / 20 octets - min size
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./AcousticEmitterSystem.h"
#include "./Vector.h"
#include "./UnderwaterAcousticEmitterBeam.h"

namespace KDIS {
namespace DATA_TYPE {

using std::vector;

class KDIS_EXPORT UnderwaterAcousticEmitterSystem : public DataTypeBase
{
protected:

    KUINT8 m_ui8EmitterSystemDataLength;

    KUINT8 m_ui8NumBeams;

    KUINT16 m_ui16Padding1;

    AcousticEmitterSystem m_AES;

    Vector m_Location;

    vector<UnderwaterAcousticEmitterBeam> m_vUAEB;

public:

    static const KUINT16 UNDERWATER_ACOUSTIC_EMITTER_SYSTEM_SIZE = 20; // Min Size

    UnderwaterAcousticEmitterSystem( void );

    UnderwaterAcousticEmitterSystem( KDataStream & stream ) throw( KException );

    virtual ~UnderwaterAcousticEmitterSystem( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::GetEmitterSystemDataLength
    // Description: Length of the emitter system in 32 bits words.
    //************************************
    KUINT8 GetEmitterSystemDataLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::GetNumberOfBeams
    // Description: Returns number of beams for the current system
    //************************************
    KUINT8 GetNumberOfBeams() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::SetAcousticEmitterSystem
    //              KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::GetAcousticEmitterSystem
    // Description: Holds infomation about a particular Underwater Acoustic emitter.
    // Parameter:   const AcousticEmitterSystem & AES, void
    //************************************
    void SetAcousticEmitterSystem( const AcousticEmitterSystem & AES );
    const AcousticEmitterSystem & GetAcousticEmitterSystem() const;
    AcousticEmitterSystem & GetAcousticEmitterSystem();

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::SetLocation
    //              KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::GetLocation
    // Description: Location of the acoustic source with respect to emitting
    //              entity coordinate system. Represented as Entity Coordinate Vector.
    // Parameter:   const Vector & L
    //************************************
    void SetLocation( const Vector & L );
    const Vector & GetLocation() const;
    Vector & GetLocation();

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::AddUnderwaterAcousticEmitterBeam
    //              KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::SetUnderwaterAcousticEmitterBeam
    //              KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::GetUnderwaterAcousticEmitterBeam
    //              KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::ClearUnderwaterAcousticEmitterBeams
    // Description: Add a articulation parameter / Get vector or params
    //              Adding will update the Number Of Articulation Params
    //              field.
    // Parameter:   const UnderwaterAcousticEmitterBeam & UAEB, void
    //************************************
    void AddUnderwaterAcousticEmitterBeam( const UnderwaterAcousticEmitterBeam & UAEB );
    void SetUnderwaterAcousticEmitterBeams( const vector<UnderwaterAcousticEmitterBeam> & UAEB );
    const vector<UnderwaterAcousticEmitterBeam> & GetUnderwaterAcousticEmitterBeam() const;
    void ClearUnderwaterAcousticEmitterBeams();

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterSystem::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const UnderwaterAcousticEmitterSystem & Value ) const;
    KBOOL operator != ( const UnderwaterAcousticEmitterSystem & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

