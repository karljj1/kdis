#
# Headers & Sources
#
set(KDIS_EXAMPLES_PDU_BUNDLE_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(KDIS_EXAMPLES_PDU_BUNDLE_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(KDIS_EXAMPLES_PDU_BUNDLE_HEADERS ${KDIS_EXAMPLES_PDU_BUNDLE_HEADERS_DIR}/EntityGenerator.hpp)
set(KDIS_EXAMPLES_PDU_BUNDLE_SOURCES ${KDIS_EXAMPLES_PDU_BUNDLE_SOURCES_DIR}/main.cpp)

#
# Executable
#
add_executable(
  ${CMAKE_PROJECT_NAME}_examples_pdu_bundle ${KDIS_EXAMPLES_PDU_BUNDLE_HEADERS}
                                            ${KDIS_EXAMPLES_PDU_BUNDLE_SOURCES}
)
target_include_directories(
  ${CMAKE_PROJECT_NAME}_examples_pdu_bundle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_link_libraries(${CMAKE_PROJECT_NAME}_examples_pdu_bundle PRIVATE KDIS::KDIS)
target_compile_definitions(
  ${CMAKE_PROJECT_NAME}_examples_pdu_bundle
  PRIVATE DIS_VERSION=${DIS_VERSION}
          $<$<BOOL:${KDIS_USE_ENUM_DESCRIPTORS}>:KDIS_USE_ENUM_DESCRIPTORS>
)
# TODO target_compile_options( ${CMAKE_PROJECT_NAME}_examples_pdu_bundle PRIVATE
# $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX> $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic
# -Werror> )
