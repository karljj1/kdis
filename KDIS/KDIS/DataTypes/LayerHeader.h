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
    class:      LayerHeader
    created:    2008/12/07
    author:     Karl Jones

    purpose:    Identifies the additional layer number, layer-specific
                information and the length of the layer.

    size:       32 bits / 4 octets
*********************************************************************/

#pragma once

#include "./DataTypeBase.h"
#include "./../Extras/KRef_Ptr.h"

namespace KDIS {
namespace DATA_TYPE {

/************************************************************************/
// Define the type of pointer we are using for LayerHeader Records,
// do we want a weak reference or a ref counter?
// By default we use a ref pointer, however if you want to use a standard
// pointer or one of your own then simply change it below.
/************************************************************************/
class LayerHeader;
typedef KDIS::UTILS::KRef_Ptr<LayerHeader> LyrHdrPtr; // Ref counter
//typedef VaLayerHeaderLyrHdrPtr; // Weak ref	

class KDIS_EXPORT LayerHeader : public DataTypeBase
{
protected:

    KUINT8 m_ui8LayerNumber;

    KUINT8 m_ui8LayerSpecificInfo;

    KUINT16 m_ui16LayerLength;

public:

    static const KUINT16 LAYER_HEADER_SIZE = 4;

    LayerHeader();

    LayerHeader( KDataStream & stream ) throw( KException );

    LayerHeader( KUINT8 LayerNumber, KUINT8 LayerSpecificInfo, KUINT16 LayerLength );

    virtual ~LayerHeader();

    //************************************
    // FullName:    KDIS::DATA_TYPE::LayerHeader::SetLayerNumber
    //              KDIS::DATA_TYPE::LayerHeader::GetLayerNumber
    // Description: Identifies the layer.
    // Parameter:   KUINT8 LN
    //************************************
    void SetLayerNumber( KUINT8 LN );
    KUINT8 GetLayerNumber() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LayerHeader::SetLayerSpecificInfomation
    //              KDIS::DATA_TYPE::LayerHeader::GetLayerSpecificInfomation
    // Description: This value varies by system type and layer number. Represented by an
    //              enumeration however no values has been defined(as of SISO-REF-10-2006) other than 0 = Other.
    // Parameter:   KUINT8 LSI
    //************************************
    void SetLayerSpecificInfomation( KUINT8 LSI );
    KUINT8 GetLayerSpecificInfomation() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LayerHeader::SetLayerLength
    //              KDIS::DATA_TYPE::LayerHeader::GetLayerLength
    // Description: Specifies the length in octets of the layer including the layer header.
    // Parameter:   KUINT16 L
    //************************************
    void SetLayerLength( KUINT16 L );
    KUINT16 GetLayerLength() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LayerHeader::GetAsString
    // Description: Returns a string representation
    //************************************
    virtual KString GetAsString() const;

    //************************************
    // FullName:    KDIS::DATA_TYPE::LayerHeader::Decode
    // Description: Convert From Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual void Decode( KDataStream & stream ) throw( KException );

    //************************************
    // FullName:    KDIS::DATA_TYPE::LayerHeader::Encode
    // Description: Convert To Network Data.
    // Parameter:   KDataStream & stream
    //************************************
    virtual KDataStream Encode() const;
    virtual void Encode( KDataStream & stream ) const;

    KBOOL operator == ( const LayerHeader & Value ) const;
    KBOOL operator != ( const LayerHeader & Value ) const;
};

} // END namespace DATA_TYPES
} // END namespace KDIS

