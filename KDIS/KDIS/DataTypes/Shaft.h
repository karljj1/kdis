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
    class:      Shaft
    created:    04/01/2009
    author:     Karl Jones

    purpose:    Represents a shaft on a platform.
    size:       64 bits / 8 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"

namespace KDIS {
namespace DATA_TYPE {

class KDIS_EXPORT Shaft : public DataTypeBase
{
protected:

    KINT16 m_i16CurrentRPM;

    KINT16 m_i16OrderedRPM;

    KINT32 m_i32RPMRateOfChange;

public:

    static const KUINT16 SHAFT_SIZE = 8;

    Shaft();

    Shaft( KDataStream & stream ) throw( KException );

    Shaft( KINT16 CurrentRPM, KINT16 OrderedRPM, KINT32 RateOfChange );

    virtual ~Shaft();

    //************************************
    // FullName:    KDIS::DATA_TYPE::Shaft::SetCurrentRPM
    //              KDIS::DATA_TYPE::Shaft::GetCurrentRPM
    // Description: Current speed in RPM of the shaft.
    //              A positive value indicates a clockwise
    //              rotation. Shafts are defined from port to
    //              starboard locations(refrence view is from stern to bow).
    // Parameter:   KINT16 RPM, void
    //************************************
    void SetCurrentRPM( KINT16 RPM );
    KINT16 GetCurrentRPM() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Shaft::SetOrderedRPM
    //              KDIS::DATA_TYPE::Shaft::GetOrderedRPM
    // Description: Current speed in RPM of the shaft.
    //              A positive value indicates a clockwise
    //              rotation. Shafts are defined from port to
    //              starboard locations(refrence view is from stern to bow).
    // Parameter:   KINT16 RPM, void
    //************************************
    void SetOrderedRPM( KINT16 RPM );
    KINT16 GetOrderedRPM() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Shaft::SetRateOfChange
    //              KDIS::DATA_TYPE::Shaft::GetRateOfChange
    // Description: Current speed in RPM of the shaft.
    //              A positive value indicates a clockwise
    //              rotation. Shafts are defined from port to
    //              starboard locations(refrence view is from stern to bow).
    // Parameter:   KINT32 ROC, void
    //************************************
    void SetRateOfChange( KINT32 ROC );
    KINT32 GetRateOfChange() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Shaft::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::Shaft::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::Shaft::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const Shaft & Value ) const;
    KBOOL operator != ( const Shaft & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

