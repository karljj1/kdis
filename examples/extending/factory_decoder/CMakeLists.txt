#
# Sources
#
set(KDIS_EXAMPLES_EXTENDING_FACTORY_DECODER_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(KDIS_EXAMPLES_EXTENDING_FACTORY_DECODER_SOURCES
    ${KDIS_EXAMPLES_EXTENDING_FACTORY_DECODER_SOURCES_DIR}/main.cpp
)

#
# Executable
#
add_executable(
  ${PROJECT_NAME}_examples_extending_factory_decoder
  ${KDIS_EXAMPLES_EXTENDING_FACTORY_DECODER_SOURCES}
)
target_link_libraries(${PROJECT_NAME}_examples_extending_factory_decoder PRIVATE KDIS::KDIS)
target_compile_definitions(
  ${PROJECT_NAME}_examples_extending_factory_decoder
  PRIVATE DIS_VERSION=${DIS_VERSION}
          $<$<BOOL:${KDIS_USE_ENUM_DESCRIPTORS}>:KDIS_USE_ENUM_DESCRIPTORS>
)
# TODO target_compile_options( ${PROJECT_NAME}_examples_extending_factory_decoder PRIVATE
# $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX> $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic
# -Werror> )
