#
# Headers & Sources
#
set(KDIS_EXAMPLES_PDU_PDU_FACTORY_1_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(KDIS_EXAMPLES_PDU_PDU_FACTORY_1_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(KDIS_EXAMPLES_PDU_PDU_FACTORY_1_HEADERS)
set(KDIS_EXAMPLES_PDU_PDU_FACTORY_1_SOURCES ${KDIS_EXAMPLES_PDU_PDU_FACTORY_1_SOURCES_DIR}/main.cpp)

#
# Executable
#
add_executable(
  ${PROJECT_NAME}_examples_pdu_pdu_factory_1 ${KDIS_EXAMPLES_PDU_PDU_FACTORY_1_HEADERS}
                                             ${KDIS_EXAMPLES_PDU_PDU_FACTORY_1_SOURCES}
)
target_link_libraries(${PROJECT_NAME}_examples_pdu_pdu_factory_1 PRIVATE KDIS::KDIS)
target_compile_definitions(
  ${PROJECT_NAME}_examples_pdu_pdu_factory_1
  PRIVATE DIS_VERSION=${DIS_VERSION}
          $<$<BOOL:${KDIS_USE_ENUM_DESCRIPTORS}>:KDIS_USE_ENUM_DESCRIPTORS>
)
# TODO target_compile_options( ${PROJECT_NAME}_examples_pdu_pdu_factory_1 PRIVATE
# $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX> $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic
# -Werror> )
