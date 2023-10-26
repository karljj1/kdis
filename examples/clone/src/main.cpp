#include <KDIS/DataTypes/EntityIdentifier.hpp>
#include <KDIS/PDU/Entity_Info_Interaction/Entity_State_PDU.hpp>
#include <KDIS/PDU/Header.hpp>
#include <cassert>
#include <iostream>
#include <string>
#include <type_traits>

static void print(const std::string &label, const KDIS::PDU::Header &pdu);

int main() {
  // Header
  KDIS::PDU::Header header;
  header.SetExerciseID(1);                       // Update exercise id
  auto header_clone = KDIS::PDU::clone(header);  // Clone
  header_clone->SetExerciseID(2);                // Update exercise id in clone
  assert(header.GetExerciseID() != header_clone->GetExerciseID());
  static_assert(std::is_same<std::unique_ptr<KDIS::PDU::Header>,
                             decltype(header_clone)>::value,
                "header_clone type is std::unique_ptr<KDIS::PDU::Header>");
  ::print("Header", header);
  ::print("Header (clone)", *header_clone.get());

  // Entity State
  KDIS::PDU::Entity_State_PDU entity_state;
  entity_state.SetEntityIdentifier(
      KDIS::DATA_TYPE::EntityIdentifier(1, 2, 3));           // Update entity id
  auto entity_state_clone = KDIS::PDU::clone(entity_state);  // Clone
  entity_state_clone->SetEntityIdentifier(
      KDIS::DATA_TYPE::EntityIdentifier(4, 5, 6));  // Update entity id in clone
  assert(entity_state.GetEntityIdentifier() !=
         entity_state_clone->GetEntityIdentifier());
  static_assert(std::is_same<std::unique_ptr<KDIS::PDU::Entity_State_PDU>,
                             decltype(entity_state_clone)>::value,
                "entity_state_clone type must be "
                "std::unique_ptr<KDIS::PDU::Entity_State_PDU>");
  ::print("Entity State", entity_state);
  ::print("Entity State (clone)", *entity_state_clone.get());

  // From Header
  auto &header_from_entity_state =
      dynamic_cast<const KDIS::PDU::Header &>(entity_state);
  auto header_from_entity_state_clone =
      KDIS::PDU::clone(header_from_entity_state);
  static_assert(std::is_same<std::unique_ptr<KDIS::PDU::Header>,
                             decltype(header_from_entity_state_clone)>::value,
                "header_from_entity_state_clone type must be "
                "std::unique_ptr<KDIS::PDU::Header>");
  ::print("Header (Entity State)", *header_from_entity_state_clone.get());

  return EXIT_SUCCESS;
}

static void print(const std::string &label, const KDIS::PDU::Header &pdu) {
  std::cout << std::endl
            << "----------------------------------------" << std::endl
            << label << ":" << std::endl
            << "----------------------------------------" << std::endl
            << pdu.GetAsString();
}
