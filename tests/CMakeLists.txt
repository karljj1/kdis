enable_testing()

#
# Sources
#
set(KDIS_TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(KDIS_TESTS_SOURCES ${KDIS_TESTS_DIR}/ConversionTests.cpp ${KDIS_TESTS_DIR}/PDU_Factory.cpp
                       ${KDIS_TESTS_DIR}/PDU_Clone.cpp
)
list(APPEND KDIS_TESTS_SOURCES ${KDIS_TESTS_DIR}/DataType_Enums.cpp
                               ${KDIS_TESTS_DIR}/Extras.cpp
                               ${KDIS_TESTS_DIR}/KDataStreamTests.cpp
                               ${KDIS_TESTS_DIR}/util.cpp)
# DIS 5
list(APPEND KDIS_TESTS_SOURCES ${KDIS_TESTS_DIR}/DataType_EncodeDecode5.cpp
     ${KDIS_TESTS_DIR}/PDU_EncodeDecode5.cpp ${KDIS_TESTS_DIR}/PDU_FactoryDecoder5.cpp
     ${KDIS_TESTS_DIR}/PDU_ProtocolFamily5.cpp
)
# DIS 6
if(DIS_VERSION GREATER_EQUAL 6)
  list(APPEND KDIS_TESTS_SOURCES ${KDIS_TESTS_DIR}/DataType_EncodeDecode6.cpp
       ${KDIS_TESTS_DIR}/PDU_EncodeDecode6.cpp ${KDIS_TESTS_DIR}/PDU_ProtocolFamily6.cpp
  )
endif()
# DIS 7
if(DIS_VERSION GREATER_EQUAL 7)
  list(APPEND KDIS_TESTS_SOURCES ${KDIS_TESTS_DIR}/DataType_EncodeDecode7.cpp
       ${KDIS_TESTS_DIR}/PDU_EncodeDecode7.cpp ${KDIS_TESTS_DIR}/PDU_ProtocolFamily7.cpp
  )
endif()

#
# Test
#
add_executable(${PROJECT_NAME}_tests ${KDIS_TESTS_SOURCES})
target_link_libraries(
  ${PROJECT_NAME}_tests PRIVATE GTest::gtest_main ${PROJECT_NAME}::${PROJECT_NAME}
)
target_compile_definitions(
  ${PROJECT_NAME}_tests PRIVATE DIS_VERSION=${DIS_VERSION}
                                $<$<BOOL:${KDIS_USE_ENUM_DESCRIPTORS}>:KDIS_USE_ENUM_DESCRIPTORS>
)
# TODO target_compile_options(${PROJECT_NAME}_tests PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
# $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror> )

#
# Copy
#
if(BUILD_SHARED_LIBS AND WIN32)
  # Copy libraries
  add_custom_command(
    TARGET ${PROJECT_NAME}_tests
    POST_BUILD
    COMMAND
      ${CMAKE_COMMAND} -E
      $<IF:$<BOOL:$<TARGET_RUNTIME_DLLS:${PROJECT_NAME}_tests>>,copy_if_different,true>
      $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}_tests> $<TARGET_FILE_DIR:${PROJECT_NAME}_tests>
    COMMAND_EXPAND_LISTS VERBATIM
  )
endif()

#
# GoogleTest
#
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_tests
  DISCOVERY_TIMEOUT 20)  # default is 5 seconds

#
# Coverage
#
if(KDIS_BUILD_TESTS_COVERAGE)
  append_coverage_compiler_flags_to_target(${PROJECT_NAME})
  append_coverage_compiler_flags_to_target(${PROJECT_NAME}_tests)
  setup_target_for_coverage_lcov(
    NAME
    ${PROJECT_NAME}_coverage
    EXECUTABLE
    ${PROJECT_NAME}_tests
    DEPENDENCIES
    ${PROJECT_NAME}_tests
    ${PROJECT_NAME}::${PROJECT_NAME}
    # TODO Check
    LCOV_ARGS
    "--no-external"
    "--ignore-errors"
    "mismatch,mismatch"
    "--ignore-errors"
    "negative,negative"
    "--ignore-errors"
    "unused,unused"
    "--ignore-errors"
    "empty,empty"
    "--ignore-errors"
    "version,version"
    EXCLUDE
    "build/*"
    "examples/*"
    "tests/*"
  )
endif()
