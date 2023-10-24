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

#include "KDIS/DataTypes/EntityAppearance.hpp"

#include "KDIS/DataTypes/AirPlatformAppearance.hpp"
#include "KDIS/DataTypes/CulturalFeatureAppearance.hpp"
#include "KDIS/DataTypes/EnvironmentalsAppearance.hpp"
#include "KDIS/DataTypes/ExpendableAppearance.hpp"
#include "KDIS/DataTypes/GuidedMunitionsAppearance.hpp"
#include "KDIS/DataTypes/LandPlatformAppearance.hpp"
#include "KDIS/DataTypes/LifeFormAppearance.hpp"
#include "KDIS/DataTypes/NonHumanLifeFormAppearance.hpp"
#include "KDIS/DataTypes/RadioAppearance.hpp"
#include "KDIS/DataTypes/SensorEmitterAppearance.hpp"
#include "KDIS/DataTypes/SpacePlatformAppearance.hpp"
#include "KDIS/DataTypes/SubSurfacePlatformAppearance.hpp"
#include "KDIS/DataTypes/SupplyAppearance.hpp"
#include "KDIS/DataTypes/SurfacePlatformAppearance.hpp"

using namespace KDIS;
using namespace DATA_TYPE;
using namespace ENUMS;
using namespace UTILS;

//////////////////////////////////////////////////////////////////////////
// Public:
//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance() : m_Appearance(0) {}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance(KDataStream& stream) { Decode(stream); }

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance(const LandPlatformAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance(const AirPlatformAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance(const SurfacePlatformAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance(const SubSurfacePlatformAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance(const SpacePlatformAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance(const GuidedMunitionsAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance(const LifeFormAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance(const NonHumanLifeFormAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance(const EnvironmentalsAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance(const CulturalFeatureAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance(const SensorEmitterAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance(const RadioAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance(const ExpendableAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::EntityAppearance(const SupplyAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

EntityAppearance::~EntityAppearance() {}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetData(KUINT32 D) {
  m_Appearance = reinterpret_cast<const KUINT32&>(D);
}

//////////////////////////////////////////////////////////////////////////

KUINT32 EntityAppearance::GetData() const { return m_Appearance; }

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance(const LandPlatformAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

const LandPlatformAppearance& EntityAppearance::GetAppearanceAsLandPlatform()
    const {
  return reinterpret_cast<const LandPlatformAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

LandPlatformAppearance& EntityAppearance::GetAppearanceAsLandPlatform() {
  return reinterpret_cast<LandPlatformAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance(const AirPlatformAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

const AirPlatformAppearance& EntityAppearance::GetAppearanceAsAirPlatform()
    const {
  return reinterpret_cast<const AirPlatformAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

AirPlatformAppearance& EntityAppearance::GetAppearanceAsAirPlatform() {
  return reinterpret_cast<AirPlatformAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance(const SurfacePlatformAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

const SurfacePlatformAppearance&
EntityAppearance::GetAppearanceAsSurfacePlatform() const {
  return reinterpret_cast<const SurfacePlatformAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

SurfacePlatformAppearance& EntityAppearance::GetAppearanceAsSurfacePlatform() {
  return reinterpret_cast<SurfacePlatformAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance(const SubSurfacePlatformAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

const SubSurfacePlatformAppearance&
EntityAppearance::GetAppearanceAsSubsurfacePlatform() const {
  return reinterpret_cast<const SubSurfacePlatformAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

SubSurfacePlatformAppearance&
EntityAppearance::GetAppearanceAsSubsurfacePlatform() {
  return reinterpret_cast<SubSurfacePlatformAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance(const SpacePlatformAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

const SpacePlatformAppearance& EntityAppearance::GetAppearanceAsSpacePlatform()
    const {
  return reinterpret_cast<const SpacePlatformAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

SpacePlatformAppearance& EntityAppearance::GetAppearanceAsSpacePlatform() {
  return reinterpret_cast<SpacePlatformAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance(const GuidedMunitionsAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

const GuidedMunitionsAppearance&
EntityAppearance::GetAppearanceAsGuidedMuntions() const {
  return reinterpret_cast<const GuidedMunitionsAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

GuidedMunitionsAppearance& EntityAppearance::GetAppearanceAsGuidedMuntions() {
  return reinterpret_cast<GuidedMunitionsAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance(const LifeFormAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

const LifeFormAppearance& EntityAppearance::GetAppearanceAsLifeForm() const {
  return reinterpret_cast<const LifeFormAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

LifeFormAppearance& EntityAppearance::GetAppearanceAsLifeForm() {
  return reinterpret_cast<LifeFormAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance(const NonHumanLifeFormAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

const NonHumanLifeFormAppearance&
EntityAppearance::GetAppearanceAsNonHumanLifeForm() const {
  return reinterpret_cast<const NonHumanLifeFormAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

NonHumanLifeFormAppearance&
EntityAppearance::GetAppearanceAsNonHumanLifeForm() {
  return reinterpret_cast<NonHumanLifeFormAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance(const EnvironmentalsAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

const EnvironmentalsAppearance& EntityAppearance::GetAppearanceEnvironmentals()
    const {
  return reinterpret_cast<const EnvironmentalsAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

EnvironmentalsAppearance& EntityAppearance::GetAppearanceEnvironmentals() {
  return reinterpret_cast<EnvironmentalsAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance(const CulturalFeatureAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

const CulturalFeatureAppearance& EntityAppearance::GetAppearanceCultural()
    const {
  return reinterpret_cast<const CulturalFeatureAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

CulturalFeatureAppearance& EntityAppearance::GetAppearanceCultural() {
  return reinterpret_cast<CulturalFeatureAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance(const SensorEmitterAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

const SensorEmitterAppearance& EntityAppearance::GetSensorEmitter() const {
  return reinterpret_cast<const SensorEmitterAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

SensorEmitterAppearance& EntityAppearance::GetSensorEmitter() {
  return reinterpret_cast<SensorEmitterAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance(const RadioAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

const RadioAppearance& EntityAppearance::GetAppearanceAsRadio() const {
  return reinterpret_cast<const RadioAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

RadioAppearance& EntityAppearance::GetAppearanceAsRadio() {
  return reinterpret_cast<RadioAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance(const ExpendableAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

const ExpendableAppearance& EntityAppearance::GetAppearanceAsExpendable()
    const {
  return reinterpret_cast<const ExpendableAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

ExpendableAppearance& EntityAppearance::GetAppearanceAsExpendable() {
  return reinterpret_cast<ExpendableAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::SetAppearance(const SupplyAppearance& A) {
  m_Appearance = reinterpret_cast<const KUINT32&>(A);
}

//////////////////////////////////////////////////////////////////////////

const SupplyAppearance& EntityAppearance::GetAppearanceAsSupply() const {
  return reinterpret_cast<const SupplyAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

SupplyAppearance& EntityAppearance::GetAppearanceAsSupply() {
  return reinterpret_cast<SupplyAppearance&>(m_Appearance);
}

//////////////////////////////////////////////////////////////////////////

KString EntityAppearance::GetAsString() const {
  KStringStream ss;

  ss << "Entity Appearance Data: " << m_Appearance << "\n";

  return ss.str();
}

//////////////////////////////////////////////////////////////////////////

KString EntityAppearance::GetAsString(const EntityType& EntType) const {
  switch (EntType.GetEntityKind()) {
    case Platform:
      switch (EntType.GetDomain()) {
        case Land:
          return GetAppearanceAsLandPlatform().GetAsString();
        case Air:
          return GetAppearanceAsAirPlatform().GetAsString();
        case Surface:
          return GetAppearanceAsSurfacePlatform().GetAsString();
        case Subsurface:
          return GetAppearanceAsSubsurfacePlatform().GetAsString();
        case Space:
          return GetAppearanceAsSpacePlatform().GetAsString();
      }

    case Munition:
      return GetAppearanceAsGuidedMuntions().GetAsString();

    case Lifeform: {
      if (EntType.GetCategory() >=
          200)  // SISO-REF-010-2016-v22. Lifeform category values 200 and above
                // are non-human.
        return GetAppearanceAsNonHumanLifeForm().GetAsString();
      else
        return GetAppearanceAsLifeForm().GetAsString();
    } break;

    case Environmental:
      return GetAppearanceEnvironmentals().GetAsString();

    case Culturalfeature:
      return GetAppearanceCultural().GetAsString();

    case SensorEmitter:
      return GetSensorEmitter().GetAsString();

    case Radio:
      return GetAppearanceAsRadio().GetAsString();

    case Expendable:
      return GetAppearanceAsExpendable().GetAsString();

    case Supply:
      return GetAppearanceAsSupply().GetAsString();
  }

  // Fall back
  return GetAsString();
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::Decode(KDataStream& stream) {
  if (stream.GetBufferSize() < ENTITY_APPEARANCE_SIZE)
    throw KException(ErrorCode::NOT_ENOUGH_DATA_IN_BUFFER, __FUNCTION__);

  stream >> m_Appearance;
}

//////////////////////////////////////////////////////////////////////////

KDataStream EntityAppearance::Encode() const {
  KDataStream stream;

  EntityAppearance::Encode(stream);

  return stream;
}

//////////////////////////////////////////////////////////////////////////

void EntityAppearance::Encode(KDataStream& stream) const {
  stream << m_Appearance;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityAppearance::operator==(const EntityAppearance& Value) const {
  if (m_Appearance != Value.m_Appearance) return false;
  return true;
}

//////////////////////////////////////////////////////////////////////////

KBOOL EntityAppearance::operator!=(const EntityAppearance& Value) const {
  return !(*this == Value);
}

//////////////////////////////////////////////////////////////////////////
