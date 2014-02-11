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
    class:      UnderwaterAcousticEmitterBeam
    created:    2009/01/15
    author:     Karl Jones

    purpose:    Contains information about a underwater acoustic emitter beam
    size:       192 bits / 24 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./UnderwaterAcousticFundamentalParameterData.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT UnderwaterAcousticEmitterBeam : public DataTypeBase
{
protected:

    KUINT8 m_ui8BeamDataLength;

    KUINT8 m_ui8BeamIDNumber;

    KUINT16 m_ui16Padding1;

    UnderwaterAcousticFundamentalParameterData m_UAFPD;

public:

    static const KUINT16 UNDERWATER_ACOUSTIC_EMITTER_BEAM_SIZE = 24;

    UnderwaterAcousticEmitterBeam();

    UnderwaterAcousticEmitterBeam( KDataStream & stream )throw( KException );

    UnderwaterAcousticEmitterBeam( KUINT8 ID, const UnderwaterAcousticFundamentalParameterData & UAFPD );

    virtual ~UnderwaterAcousticEmitterBeam();

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterBeam::GetSystemDataLength
    // Description: Length of the emission system in 32 bit words.
    //              E.G 1 = 32 bits 4 octets. Calculated automatically.
    //************************************
    KUINT8 GetBeamDataLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterBeam::SetUnderwaterAcousticEmitterBeamIDNumber
    //              KDIS::DATA_TYPE::UnderwaterAcousticEmitterBeam::GetUnderwaterAcousticEmitterBeamIDNumber
    // Description: Unique ID for emitter beam, Once established for an exercise
    //              no other beam may use this ID.
    // Parameter:   KUINT8 ID, void
    //************************************
    void SetUnderwaterAcousticEmitterBeamIDNumber( KUINT8 ID );
    KUINT8 GetUnderwaterAcousticEmitterBeamIDNumber() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterBeam::SetSSetUnderwaterAcousticFundamentalParameterDataystemType
    //              KDIS::DATA_TYPE::UnderwaterAcousticEmitterBeam::GetUnderwaterAcousticFundamentalParameterData
    // Description: System Type
    // Parameter:   UnderwaterAcousticFundamentalParameterData AEFPD, void
    //************************************
    void SetUnderwaterAcousticFundamentalParameterData( const UnderwaterAcousticFundamentalParameterData & UAFPD );
    const UnderwaterAcousticFundamentalParameterData & GetUnderwaterAcousticFundamentalParameterData() const;
    UnderwaterAcousticFundamentalParameterData & GetUnderwaterAcousticFundamentalParameterData();

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterBeam::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterBeam::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::UnderwaterAcousticEmitterBeam::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const UnderwaterAcousticEmitterBeam & Value ) const;
    KBOOL operator != ( const UnderwaterAcousticEmitterBeam & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS
