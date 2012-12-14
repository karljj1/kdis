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
    class:      FlareState
    created:    07/09/2009
    author:     Karl Jones

    purpose:    Represents a flare state, part of an environment record.
    size:       256 bits / 32 octets
*********************************************************************/

#pragma once

#include "./EnvironmentRecord.h"
#include "./EntityType.h"
#include "./EulerAngles.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT FlareState : public EnvironmentRecord
{
protected:

    KUINT32 m_ui32TSC;

    EntityType m_Src;

    KUINT32 m_ui32NumInt;

    KUINT32 m_ui32NumSrcs;

    KUINT16 m_ui16GeometryIndex;

    KUINT16 m_ui16Padding;

public:

    static const KUINT16 FLARE_STATE_SIZE = 32;

    FlareState( void );

    FlareState( KDataStream & stream ) throw( KException );

    FlareState( KUINT8 Index, KUINT32 TimeSinceCreation, const EntityType & MunitionSource,
                KUINT32 NumberIntensity, KUINT32 NumberOfSources, KUINT16 GeometryIndex );

    virtual ~FlareState( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::FlareState::SetTimeSinceCreation
    //              KDIS::DATA_TYPE::FlareState::GetLGetTimeSinceCreationocation
    // Description: The time elapsed since the flare object was created.
    // Parameter:   KUINT32 TSC
    //************************************
    void SetTimeSinceCreation( KUINT32 TSC );
    KUINT32 GetTimeSinceCreation() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FlareState::SetSource
    //              KDIS::DATA_TYPE::FlareState::GetSource
    // Description: The source of the flare.
    // Parameter:   const EntityType & S
    //************************************
    void SetSource( const EntityType & S );
    const EntityType GetSource() const;
    EntityType GetSource();

    //************************************
    // FullName:    KDIS::DATA_TYPE::FlareState::SetNumberIntensity
    //              KDIS::DATA_TYPE::FlareState::GetNumberIntensity
    // Description: Number Intensity of the flare.
    // Parameter:   KUINT32 NI, void
    //************************************
    void SetNumberIntensity( KUINT32 NI );
    KUINT32 GetNumberIntensity() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FlareState::SetNumberOfSources
    //              KDIS::DATA_TYPE::FlareState::GetNumberOfSources
    // Description: The number of sources that have created the flare object.
    // Parameter:   KUINT32 NOS
    //************************************
    void SetNumberOfSources( KUINT32 NOS );
    KUINT32 GetNumberOfSources() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FlareState::SetGeometryIndex
    //              KDIS::DATA_TYPE::FlareState::GetGeometryIndex
    // Description: The geometry index.
    // Parameter:   KUINT16 GI
    //************************************
    void SetGeometryIndex( KUINT16 GI );
    KUINT16 GetGeometryIndex() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FlareState::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::FlareState::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::FlareState::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const FlareState & Value )const;
    KBOOL operator != ( const FlareState & Value )const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
