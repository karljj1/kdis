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
    class:      EntityAppearance
    created:    22/09/2008 - Updated Sept 2016
    author:     Karl Jones

    purpose:    Represents an entity appearance using bit fields.
                This class has had a significant upgrade, I have removed general
                and specific appearance types. Each type now has a single
                appearance type. size:  32 Bits / 4 Octets
*********************************************************************/

#pragma once

#include "KDIS/DataTypes/EntityType.hpp"

namespace KDIS {
namespace DATA_TYPE {

struct LandPlatformAppearance;
struct AirPlatformAppearance;
struct SurfacePlatformAppearance;
struct SubSurfacePlatformAppearance;
struct SpacePlatformAppearance;
struct GuidedMunitionsAppearance;
struct LifeFormAppearance;
struct NonHumanLifeFormAppearance;
struct EnvironmentalsAppearance;
struct CulturalFeatureAppearance;
struct SensorEmitterAppearance;
struct RadioAppearance;
struct ExpendableAppearance;
struct SupplyAppearance;

class KDIS_EXPORT EntityAppearance : public DataTypeBase {
 protected:
  KUINT32 m_Appearance{0};

 public:
  static constexpr KUINT16 ENTITY_APPEARANCE_SIZE{4};

  EntityAppearance() = default;

  EntityAppearance(KDataStream& stream);

  EntityAppearance(const LandPlatformAppearance& A);

  EntityAppearance(const AirPlatformAppearance& A);

  EntityAppearance(const SurfacePlatformAppearance& A);

  EntityAppearance(const SubSurfacePlatformAppearance& A);

  EntityAppearance(const SpacePlatformAppearance& A);

  EntityAppearance(const GuidedMunitionsAppearance& A);

  EntityAppearance(const LifeFormAppearance& A);

  EntityAppearance(const NonHumanLifeFormAppearance& A);

  EntityAppearance(const EnvironmentalsAppearance& A);

  EntityAppearance(const CulturalFeatureAppearance& A);

  EntityAppearance(const SensorEmitterAppearance& A);

  EntityAppearance(const RadioAppearance& A);

  EntityAppearance(const ExpendableAppearance& A);

  EntityAppearance(const SupplyAppearance& A);

  virtual ~EntityAppearance() = default;

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetData
  //              KDIS::DATA_TYPE::EntityAppearance::GetData
  // Description: This is the raw appearance field. Each bit is interpreted
  //              differently depending on the appearance type.
  //              You will likely never need to touch this value unless
  //              something is missing from one of my appearance types or you
  //              are using a field in a non-standard way.
  // Parameter:   KUINT32 D
  //************************************
  void SetData(KUINT32 D);
  KUINT32 GetData() const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance
  //              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceAsLandPlatform
  // Description: Get/Set the appearance data as a land platform.
  // Parameter:   const LandPlatformAppearance & A
  //************************************
  void SetAppearance(const LandPlatformAppearance& A);
  const LandPlatformAppearance& GetAppearanceAsLandPlatform() const;
  LandPlatformAppearance& GetAppearanceAsLandPlatform();

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance
  //              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceAsAirPlatform
  // Description: Get/Set the appearance data as a air platform.
  // Parameter:   const AirPlatformAppearance & A
  //************************************
  void SetAppearance(const AirPlatformAppearance& A);
  const AirPlatformAppearance& GetAppearanceAsAirPlatform() const;
  AirPlatformAppearance& GetAppearanceAsAirPlatform();

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance
  //              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceAsSurfacePlatform
  // Description: Get/Set the appearance data as a surface platform.
  // Parameter:   const SurfacePlatformAppearance & A
  //************************************
  void SetAppearance(const SurfacePlatformAppearance& A);
  const SurfacePlatformAppearance& GetAppearanceAsSurfacePlatform() const;
  SurfacePlatformAppearance& GetAppearanceAsSurfacePlatform();

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance
  //              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceAsSubsurfacePlatform
  // Description: Get/Set the appearance data as subsurface platform.
  // Parameter:   const SubSurfacePlatformAppearance & A
  //************************************
  void SetAppearance(const SubSurfacePlatformAppearance& A);
  const SubSurfacePlatformAppearance& GetAppearanceAsSubsurfacePlatform() const;
  SubSurfacePlatformAppearance& GetAppearanceAsSubsurfacePlatform();

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance
  //              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceAsSpacePlatform
  // Description: Get/Set the appearance data as space platform.
  // Parameter:   const SpacePlatformAppearance & A
  //************************************
  void SetAppearance(const SpacePlatformAppearance& A);
  const SpacePlatformAppearance& GetAppearanceAsSpacePlatform() const;
  SpacePlatformAppearance& GetAppearanceAsSpacePlatform();

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance
  //              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceAsGuidedMunitions
  // Description: Get/Set the appearance data as guided munitions.
  // Parameter:   const GuidedMunitionsAppearance & A
  //************************************
  void SetAppearance(const GuidedMunitionsAppearance& A);
  const GuidedMunitionsAppearance& GetAppearanceAsGuidedMunitions() const;
  GuidedMunitionsAppearance& GetAppearanceAsGuidedMunitions();

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance
  //              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceAsLifeForm
  // Description: Get/Set the appearance data as life form.
  // Parameter:   const LifeFormAppearance & A
  //************************************
  void SetAppearance(const LifeFormAppearance& A);
  const LifeFormAppearance& GetAppearanceAsLifeForm() const;
  LifeFormAppearance& GetAppearanceAsLifeForm();

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance
  //              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceAsNonHumanLifeForm
  // Description: Get/Set the appearance data as life form.
  // Parameter:   const NonHumanLifeFormAppearance & A
  //************************************
  void SetAppearance(const NonHumanLifeFormAppearance& A);
  const NonHumanLifeFormAppearance& GetAppearanceAsNonHumanLifeForm() const;
  NonHumanLifeFormAppearance& GetAppearanceAsNonHumanLifeForm();

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance
  //              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceEnvironmentals
  // Description: Get/Set the appearance data as environmental.
  // Parameter:   const EnvironmentalsAppearance & A
  //************************************
  void SetAppearance(const EnvironmentalsAppearance& A);
  const EnvironmentalsAppearance& GetAppearanceEnvironmentals() const;
  EnvironmentalsAppearance& GetAppearanceEnvironmentals();

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance
  //              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceCultural
  // Description: Get/Set the appearance data as cultural feature.
  // Parameter:   const CulturalFeatureAppearance & A
  //************************************
  void SetAppearance(const CulturalFeatureAppearance& A);
  const CulturalFeatureAppearance& GetAppearanceCultural() const;
  CulturalFeatureAppearance& GetAppearanceCultural();

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance
  //              KDIS::DATA_TYPE::EntityAppearance::GetSensorEmitter
  // Description: Get/Set the appearance data as a Sensor/Emitter.
  // Parameter:   const SensorEmitterAppearance & A
  //************************************
  void SetAppearance(const SensorEmitterAppearance& A);
  const SensorEmitterAppearance& GetSensorEmitter() const;
  SensorEmitterAppearance& GetSensorEmitter();

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance
  //              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceAsRadio
  // Description: Get/Set the appearance data as life form.
  // Parameter:   const RadioAppearance & A
  //************************************
  void SetAppearance(const RadioAppearance& A);
  const RadioAppearance& GetAppearanceAsRadio() const;
  RadioAppearance& GetAppearanceAsRadio();

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance
  //              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceAsExpendable
  // Description: Get/Set the appearance data as life form.
  // Parameter:   const ExpendableAppearance & A
  //************************************
  void SetAppearance(const ExpendableAppearance& A);
  const ExpendableAppearance& GetAppearanceAsExpendable() const;
  ExpendableAppearance& GetAppearanceAsExpendable();

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::SetAppearance
  //              KDIS::DATA_TYPE::EntityAppearance::GetAppearanceAsSupply
  // Description: Get/Set the appearance data as life form.
  // Parameter:   const SupplyAppearance & A
  //************************************
  void SetAppearance(const SupplyAppearance& A);
  const SupplyAppearance& GetAppearanceAsSupply() const;
  SupplyAppearance& GetAppearanceAsSupply();

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::GetAsString
  // Description: Returns a string representation of the appearance.
  //              This version just returns the data as an integer.
  // Parameter:   const EntityType & EntType
  //************************************
  KString GetAsString() const override;

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::GetAsString
  // Description: Returns a string representation of the appearance based on
  // type. Parameter:   const EntityType & EntType
  //************************************
  KString GetAsString(const EntityType& EntType) const;

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::Decode
  // Description: Convert From Network Data.
  // Parameter:   KDataStream & stream
  //************************************
  void Decode(KDataStream& stream) override;

  //************************************
  // FullName:    KDIS::DATA_TYPE::EntityAppearance::Encode
  // Description: Convert To Network Data.
  // Parameter:   KDataStream & stream
  //************************************
  KDataStream Encode() const override;
  void Encode(KDataStream& stream) const override;

  KBOOL operator==(const EntityAppearance& Value) const;
  KBOOL operator!=(const EntityAppearance& Value) const;
};

}  // namespace DATA_TYPE
}  // END namespace KDIS
