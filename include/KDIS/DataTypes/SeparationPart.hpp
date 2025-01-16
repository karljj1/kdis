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
    class:      SeparationPart
    DIS:        (6) 1278.1A - 1998
    updated:    10/07/2017
    author:     Karl Jones

    purpose:    Communicates separation of an entity from another entity.
                Also provides the capability to specifically identify the
station location on the parent entity that the entity separated from. Examples
include the launch of an air-to-surface missile from the wing station of a
fighter aircraft, the separation of a stage of a multistage missile, and the
separation of a component of a smart weapon.

    size:       128 bits / 16 octets
*********************************************************************/

#if DIS_VERSION > 5
#pragma once

#include "KDIS/DataTypes/EntityIdentifier.hpp"
#include "KDIS/DataTypes/NamedLocationIdentifier.hpp"
#include "KDIS/DataTypes/VariableParameter.hpp"

namespace KDIS {
namespace DATA_TYPE {

using KDIS::DATA_TYPE::ENUMS::PreEntityIndicator;
using KDIS::DATA_TYPE::ENUMS::ReasonForSeparation;

class KDIS_EXPORT SeparationPart : public VariableParameter {
 protected:
  KUINT8 m_ui8Reason;

  KUINT8 m_ui8PreEntIndicator;

  KUINT8 m_ui8Padding;

  EntityIdentifier m_ParentEntId;

  KUINT16 m_ui16Padding;

  NamedLocationIdentifier m_StationLoc;

 public:
  SeparationPart();

  SeparationPart(ReasonForSeparation RFS, PreEntityIndicator PEI,
                 const EntityIdentifier& PEID,
                 const NamedLocationIdentifier& SL);

  SeparationPart(KDataStream& stream);

  virtual ~SeparationPart();

  //************************************
  // FullName:    KDIS::DATA_TYPE::SeparationPart::SetReasonForSeparation
  //              KDIS::DATA_TYPE::SeparationPart::GetReasonForSeparation
  // Description: Indicate the reason for the separation.
  // Parameter:   ReasonForSeparation RFS
  //************************************
  void SetReasonForSeparation(ReasonForSeparation RFS);
  ReasonForSeparation GetReasonForSeparation() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::SeparationPart::SetPreEntityIndicator
  //              KDIS::DATA_TYPE::SeparationPart::GetPreEntityIndicator
  // Description: Indicates whether the entity existed prior to the separation
  // and,
  //              if so, in what manner.
  // Parameter:   PreEntityIndicator PEI
  //************************************
  void SetPreEntityIndicator(PreEntityIndicator PEI);
  PreEntityIndicator GetPreEntityIndicator() const;

  //************************************
  // FullName:    KDIS::PDU::SeparationPart::SetParentEntityId
  //              KDIS::PDU::SeparationPart::GetParentEntityId
  // Description: Entity ID of the parent entity.
  // Parameter:   const EntityIdentifier & PEID
  //************************************
  void SetParentEntityId(const EntityIdentifier& PEID);
  const EntityIdentifier& GetParentEntityId() const;
  EntityIdentifier& GetParentEntityId();

  //************************************
  // FullName:    KDIS::PDU::SeparationPart::SetStationLocation
  //              KDIS::PDU::SeparationPart::GetStationLocation
  // Description: Indicate the station that this entity was attached to prior to
  //              separation if known.
  // Parameter:   const NamedLocationIdentifier & SL
  //************************************
  void SetStationLocation(const NamedLocationIdentifier& SL);
  const NamedLocationIdentifier& GetStationLocation() const;
  NamedLocationIdentifier& GetStationLocation();

  //************************************
  // FullName:    KDIS::DATA_TYPE::SeparationPart::GetAsString
  // Description: Returns a string representation.
  //************************************
  virtual KString GetAsString() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::SeparationPart::Decode
  // Description: Convert From Network Data.
  // Parameter:   KDataStream & stream
  //************************************
  virtual void Decode(KDataStream& stream);

  //************************************
  // FullName:    KDIS::DATA_TYPE::SeparationPart::Encode
  // Description: Convert To Network Data.
  // Parameter:   KDataStream & stream
  //************************************
  virtual KDataStream Encode() const;
  virtual void Encode(KDataStream& stream) const;

  KBOOL operator==(const SeparationPart& Value) const;
  KBOOL operator!=(const SeparationPart& Value) const;
};

}  // namespace DATA_TYPE
}  // END namespace KDIS
#endif  // DIS_VERSION > 5
