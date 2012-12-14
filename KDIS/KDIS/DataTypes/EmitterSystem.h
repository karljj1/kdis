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
    class:      EmitterSystem
    created:    2008/09/18
    author:     Karl Jones

    purpose:    Contains information about a emitter system
    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::EmitterName;
using KDIS::DATA_TYPE::ENUMS::EmitterFunction;

class KDIS_EXPORT EmitterSystem : public DataTypeBase
{
protected:

    KUINT16 m_ui16EmitterName;

    KUINT8 m_ui8Function;

    KUINT8 m_ui8EmitterIDNumber;

public:

    static const KUINT16 EMITTER_SYSTEM_SIZE = 4;

    EmitterSystem( void );

    EmitterSystem( KDataStream & stream )throw( KException );

    EmitterSystem( EmitterName EN, EmitterFunction F, KUINT8 ID );

    virtual ~EmitterSystem( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterSystem::SetEmitterName
    //              KDIS::DATA_TYPE::EmitterSystem::GetEmitterName
    // Description: Emitter name
    // Parameter:   EmitterName EN, void
    //************************************
    void SetEmitterName( EmitterName EN );
    EmitterName GetEmitterName() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterSystem::SetFunction
    //              KDIS::DATA_TYPE::EmitterSystem::GetFunction
    // Description: Emitter function
    // Parameter:   EmitterFunction F, void
    //************************************
    void SetFunction( EmitterFunction F );
    EmitterFunction GetFunction() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterSystem::SetEmitterID
    //              KDIS::DATA_TYPE::EmitterSystem::GetEmitterID
    // Description: ID of the emitter
    // Parameter:   KUINT8 ID, void
    //************************************
    void SetEmitterID( KUINT8 ID );
    KUINT8 GetEmitterID() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterSystem::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterSystem::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterSystem::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EmitterSystem & Value ) const;
    KBOOL operator != ( const EmitterSystem & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
