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

    UnderwaterAcousticEmitterBeam( void );

    UnderwaterAcousticEmitterBeam( KDataStream & stream )throw( KException );

    UnderwaterAcousticEmitterBeam( KUINT8 ID, const UnderwaterAcousticFundamentalParameterData & UAFPD );

    virtual ~UnderwaterAcousticEmitterBeam( void );

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

}; // END namespace DATA_TYPES
}; // END namespace KDIS
