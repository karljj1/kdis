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

    EmitterBeam();

    EmitterBeam( KDataStream & stream )throw( KException );

    EmitterBeam( KUINT8 BeamID, KUINT16 BeamParamIndex, const FundamentalParameterData & FPD,
                 EmitterFunction EBF, HighDensityTrackJam HDTJ,
                 KUINT32 JammingModeSequence );

    virtual ~EmitterBeam();

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

} // END namespace DATA_TYPES
} // END namespace KDIS
