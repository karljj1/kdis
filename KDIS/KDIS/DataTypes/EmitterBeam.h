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
    class:      EmitterBeam
    created:    2008/010/19
    author:     Karl Jones

    purpose:    Contains information about a emitter beam
    size:       416 bits / 52 octets min size
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./FundamentalParameterData.h"
#include <vector>
#include "./TrackJamTargetIdentifier.h"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::EmitterFunction;
using KDIS::DATA_TYPE::ENUMS::HighDensityTrackJam;
using std::vector;

class KDIS_EXPORT EmitterBeam : public DataTypeBase
{
protected:

    KUINT8 m_ui8BeamDataLength;

    KUINT8 m_ui8EmitterBeamIDNumber;

    KUINT16 m_ui16BeamParamIndex;

    FundamentalParameterData m_FundamentalParameterData;

    KUINT8 m_ui8BeamFunction;

    KUINT8 m_ui8NumTargetInTrackJamField;

    KUINT8 m_ui8HighDensityTrackJam;

    KUINT8 m_ui8Padding;

    KUINT32 m_ui32JammingModeSequence;

    vector<TrackJamTargetIdentifier> m_vTrackJamTargets;

public:

    static const KUINT16 EMITTER_BEAM_SIZE = 52; // Min Size

    EmitterBeam( void );

    EmitterBeam( KDataStream & stream )throw( KException );

    EmitterBeam( KUINT8 BeamID, KUINT16 BeamParamIndex, const FundamentalParameterData & FPD,
                 EmitterFunction EBF, HighDensityTrackJam HDTJ,
                 KUINT32 JammingModeSequence );

    virtual ~EmitterBeam( void );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterBeam::GetSystemDataLength
    // Description: Length of the emission system in 32 bit words.
    //              E.G 1 = 32 bits / 4 octets. Calculated automatically.
    //************************************
    KUINT8 GetBeamDataLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterBeam::SetEmitterBeamIDNumber
    //              KDIS::DATA_TYPE::EmitterBeam::GetEmitterBeamIDNumber
    // Description: Unique ID for emitter beam, Once established for an exercise
    //              no other beam may use this ID.
    // Parameter:   KUINT8 ID, void
    //************************************
    void SetEmitterBeamIDNumber( KUINT8 ID );
    KUINT8 GetEmitterBeamIDNumber() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterBeam::SetBeamParamIndex
    //              KDIS::DATA_TYPE::EmitterBeam::GetBeamParamIndex
    // Description: Number used by receiving entities in conjunction with the
    //              emitter name field to provide a pointer to the stored
    //              database parameter required to regenerate the beam.
    // Parameter:   KUINT16 BPI, void
    //************************************
    void SetBeamParamIndex( KUINT16 BPI );
    KUINT16 GetBeamParamIndex() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterBeam::SetFundamentalParameterData
    //              KDIS::DATA_TYPE::EmitterBeam::GetFundamentalParameterData
    // Description: Specifies dynamic parameters of the emitter.
    // Parameter:   const FundamentalParameterData & FPD, void
    //************************************
    void SetFundamentalParameterData( const FundamentalParameterData & FPD );
    const FundamentalParameterData & GetFundamentalParameterData() const;
    FundamentalParameterData & GetFundamentalParameterData();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterBeam::SetEmitterBeamFunction
    //              KDIS::DATA_TYPE::EmitterBeam::GetEmitterBeamFunction
    // Description: Specifies the function of a Emitter Beam
    // Parameter:   const EmitterFunction & FPD, void
    //************************************
    void SetEmitterBeamFunction( EmitterFunction EBF );
    EmitterFunction GetEmitterBeamFunction() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterBeam::GetNumTargetInTrackJamField
    // Description: Number of targets being tracked/jammed
    //************************************
    KUINT8 GetNumTargetInTrackJamField() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterBeam::SetHighDensityTrackJam
    //              KDIS::DATA_TYPE::EmitterBeam::GetHighDensityTrackJam
    // Description: Indicates if the receiving simulation application can assume that all
    //              targets, in the scan pattern which the sending emitter can track or
    //              jam are being tracked/jammed/ When selected the system issuing the
    //              PDU shall not include any entities in the track/jam field.
    // Parameter:   const HighDensityTrackJam & HDTJ, void
    //************************************
    void SetHighDensityTrackJam( HighDensityTrackJam HDTJ );
    HighDensityTrackJam GetHighDensityTrackJam() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterBeam::SetJammingModeSequence
    //              KDIS::DATA_TYPE::EmitterBeam::GetJammingModeSequence
    // Description: Used to identify one or more multiple jamming techniques
    //              being applied.
    // Parameter:   KUINT32 JMS, void
    //************************************
    void SetJammingModeSequence( KUINT32 JMS );
    KUINT32 GetJammingModeSequence() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterBeam::AddTrackedJammedTarget
    //              KDIS::DATA_TYPE::EmitterBeam::SetTrackedJammedTargets
    //              KDIS::DATA_TYPE::EmitterBeam::GetTrackedJammedTargets
    //              KDIS::DATA_TYPE::EmitterBeam::ClearTrackedJammedTargets
    // Description: Tacked jammed targets.
    // Parameter:   const TrackJamTargetIdentifier & ID, const vector<TrackJamTargetIdentifier> & ID
    //************************************
    void AddTrackedJammedTarget( const TrackJamTargetIdentifier & ID );
    void SetTrackedJammedTargets( const vector<TrackJamTargetIdentifier> & ID );
    const vector<TrackJamTargetIdentifier> & GetTrackedJammedTargets() const;
    void ClearTrackedJammedTargets();

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterBeam::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterBeam::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::EmitterBeam::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const EmitterBeam & Value ) const;
    KBOOL operator != ( const EmitterBeam & Value ) const;
};

}; // END namespace DATA_TYPES
}; // END namespace KDIS
