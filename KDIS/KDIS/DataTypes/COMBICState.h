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
    class:      COMBICState
    created:    07:09:2009
    author:     Karl Jones

    purpose:    COMBIC(Combined Obscuration Model for Battlefield Induced Contaminants).
                This represents an area of airborne dust, smoke, and debris
                that can reduce visual and infrared wavelengths.
    size:       512 bits / 64 octets
*********************************************************************/

#pragma once

#include "./EnvironmentRecord.h"
#include "./EntityType.h"
#include "./EulerAngles.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT COMBICState : public EnvironmentRecord
{
protected:

    KUINT32 m_ui32TSC;

    EntityType m_MunSrc;

    KUINT32 m_ui32NumSrcs;

    KUINT16 m_ui16GeometryIndex;

    KUINT16 m_ui16Padding;

    KUINT32 m_ui32SrcType;

    KFLOAT32 m_f32BarrageRate;

    KFLOAT32 m_f32BarrageDuration;

    KFLOAT32 m_f32BarrageCrosswindLength;

    KFLOAT32 m_f32BarrageDownwindLength;

    EulerAngles m_DetVel;

    KUINT32 m_ui32Padding;

public:

    static const KUINT16 COMBIC_STATE_SIZE = 64;

    COMBICState( void );

    COMBICState( KDataStream & stream ) throw( KException );

    COMBICState( KUINT8 Index, KUINT32 TimeSinceCreation, const EntityType & MunitionSource,
                 KUINT32 NumberOfSources, KUINT16 GeometryIndex, KUINT32 SourceType,
                 KFLOAT32 BarrageRate, KFLOAT32 BarrageDuration, KFLOAT32 BarrageCrosswindLength,
                 KFLOAT32 BarrageDownwindLength, const EulerAngles & DetonationVelocity );

    virtual ~COMBICState( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::COMBICState::SetTimeSinceCreation
    //              KDIS::DATA_TYPE::COMBICState::GetLGetTimeSinceCreationocation
    // Description: The time elapsed since the COMBIC object was created.
    // Parameter:   KUINT32 TSC, void
    //************************************
    void SetTimeSinceCreation( KUINT32 TSC );
    KUINT32 GetTimeSinceCreation() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::COMBICState::SetMunitionSource
    //              KDIS::DATA_TYPE::COMBICState::GetMunitionSource
    // Description: The source of the COMBIC object.
    // Parameter:   const EntityType & MS, void
    //************************************
    void SetMunitionSource( const EntityType & MS );
    const EntityType GetMunitionSource() const;
    EntityType GetMunitionSource();

    //************************************
    // FullName:    KDIS::DATA_TYPE::COMBICState::SetNumberOfSources
    //              KDIS::DATA_TYPE::COMBICState::GetNumberOfSources
    // Description: The number of sources that have created the COMBIC object.
    // Parameter:   KUINT32 NOS, void
    //************************************
    void SetNumberOfSources( KUINT32 NOS );
    KUINT32 GetNumberOfSources() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::COMBICState::SetGeometryIndex
    //              KDIS::DATA_TYPE::COMBICState::GetGeometryIndex
    // Description: The geometry index.
    // Parameter:   KUINT16 GI, void
    //************************************
    void SetGeometryIndex( KUINT16 GI );
    KUINT16 GetGeometryIndex() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::COMBICState::SetSourceType
    //              KDIS::DATA_TYPE::COMBICState::GetSourceType
    // Description: Source Type
    // Parameter:   KUINT32 ST, void
    //************************************
    void SetSourceType( KUINT32 ST );
    KUINT32 GetSourceType() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::COMBICState::SetBarrageRate
    //              KDIS::DATA_TYPE::COMBICState::GetBarrageRate
    // Description: Barrage Rate
    // Parameter:   KFLOAT32 BR, void
    //************************************
    void SetBarrageRate( KFLOAT32 BR );
    KFLOAT32 GetBarrageRate() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::COMBICState::SetBarrageDuration
    //              KDIS::DATA_TYPE::COMBICState::GetBarrageDuration
    // Description: Barrage Duration
    // Parameter:   KFLOAT32 BD, void
    //************************************
    void SetBarrageDuration( KFLOAT32 BD );
    KFLOAT32 GetBarrageDuration() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::COMBICState::SetBarrageCrosswindLength
    //              KDIS::DATA_TYPE::COMBICState::GetBarrageCrosswindLength
    // Description: Barrage Crosswind Length
    // Parameter:   KFLOAT32 BCL, void
    //************************************
    void SetBarrageCrosswindLength( KFLOAT32 BCL );
    KFLOAT32 GetBarrageCrosswindLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::COMBICState::SetBarrageDownwindLength
    //              KDIS::DATA_TYPE::COMBICState::GetBarrageDownwindLength
    // Description: Barrage Downwind Length
    // Parameter:   KFLOAT32 BCL, void
    //************************************
    void SetBarrageDownwindLength( KFLOAT32 BDL );
    KFLOAT32 GetBarrageDownwindLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::COMBICState::SetDetonationVelocity
    //              KDIS::DATA_TYPE::COMBICState::GetDetonationVelocity
    // Description: Detonation Velocity
    // Parameter:   KFLOAT32 BCL, void
    //************************************
    void SetDetonationVelocity( const EulerAngles & DV );
    const EulerAngles & GetDetonationVelocity() const;
    EulerAngles & GetDetonationVelocity();

    //************************************
    // FullName:    KDIS::DATA_TYPE::COMBICState::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::COMBICState::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::COMBICState::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const COMBICState & Value )const;
    KBOOL operator != ( const COMBICState & Value )const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
