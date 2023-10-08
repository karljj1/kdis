#
# Headers & Sources
#
set(KDIS_EXAMPLES_PDU_PDU_FACTORY_2_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(KDIS_EXAMPLES_PDU_PDU_FACTORY_2_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(KDIS_EXAMPLES_PDU_PDU_FACTORY_2_HEADERS)
set(KDIS_EXAMPLES_PDU_PDU_FACTORY_2_SOURCES ${KDIS_EXAMPLES_PDU_PDU_FACTORY_2_SOURCES_DIR}/main.cpp)

#
# Executable
#
add_executable(
  ${CMAKE_PROJECT_NAME}_examples_pdu_pdu_factory_2 ${KDIS_EXAMPLES_PDU_PDU_FACTORY_2_HEADERS}
                                                   ${KDIS_EXAMPLES_PDU_PDU_FACTORY_2_SOURCES}
)
target_link_libraries(${CMAKE_PROJECT_NAME}_examples_pdu_pdu_factory_2 PRIVATE KDIS::KDIS)
target_compile_definitions(
  ${CMAKE_PROJECT_NAME}_examples_pdu_pdu_factory_2
  PRIVATE DIS_VERSION=${DIS_VERSION}
          $<$<BOOL:${KDIS_USE_ENUM_DESCRIPTORS}>:KDIS_USE_ENUM_DESCRIPTORS>
)
# TODO target_compile_options( ${CMAKE_PROJECT_NAME}_examples_pdu_pdu_factory_2 PRIVATE
# $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX> $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic
# -Werror> )
