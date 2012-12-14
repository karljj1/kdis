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
    class:      AcousticEmitterSystem
    created:    06/01/2009
    author:     Karl Jones

    purpose:    Contains information about a particular Underwater Acoustic emitter
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::AcousticSystemName;
using KDIS::DATA_TYPE::ENUMS::AcousticSystemFunction;

class KDIS_EXPORT AcousticEmitterSystem : public DataTypeBase
{
protected:

    KUINT16 m_ui16EmitterName;

    KUINT8 m_ui8Function;

    KUINT8 m_ui8EmitterIDNumber;

public:

    static const KUINT16 ACOUSTIC_EMITTER_SYSTEM_SIZE = 4;

    AcousticEmitterSystem( void );

    AcousticEmitterSystem( KDataStream & stream ) throw( KException );

    AcousticEmitterSystem( AcousticSystemName ASN, AcousticSystemFunction ASF, KUINT8 ID );

    virtual ~AcousticEmitterSystem( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::AcousticEmitterSystem::SetName
    //              KDIS::DATA_TYPE::AcousticEmitterSystem::GetName
    // Description: Specifies the system for the particular emitter
    // Parameter:   AcousticSystemName ASN, void
    //************************************
    void SetName( AcousticSystemName ASN );
    AcousticSystemName GetName() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AcousticEmitterSystem::SetFunction
    //              KDIS::DATA_TYPE::AcousticEmitterSystem::GetFunction
    // Description: Specifies the function of the emitter system
    // Parameter:   AcousticSystemFunction ASF, void
    //************************************
    void SetFunction( AcousticSystemFunction ASF );
    AcousticSystemFunction GetFunction() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AcousticEmitterSystem::SetEmitterID
    //              KDIS::DATA_TYPE::AcousticEmitterSystem::GetEmitterID
    // Description: ID of the emitter. Used for identifying multiple emitters on a
    //              single entity. Numbering of systems shall begin with 1.
    // Parameter:   KUINT8 ID, void
    //************************************
    void SetEmitterID( KUINT8 ID );
    KUINT8 GetEmitterID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AcousticEmitterSystem::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::AcousticEmitterSystem::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::AcousticEmitterSystem::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const AcousticEmitterSystem & Value ) const;
    KBOOL operator != ( const AcousticEmitterSystem & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS

