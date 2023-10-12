#
# Sources
#
set(KDIS_TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(KDIS_TESTS_SOURCES
    ${KDIS_TESTS_DIR}/ConversionTests.cpp
    ${KDIS_TESTS_DIR}/DataType_EncodeDecode5.cpp
    ${KDIS_TESTS_DIR}/DataType_EncodeDecode6.cpp
    ${KDIS_TESTS_DIR}/DataType_EncodeDecode7.cpp
    ${KDIS_TESTS_DIR}/PDU_EncodeDecode5.cpp
    ${KDIS_TESTS_DIR}/PDU_EncodeDecode6.cpp
    ${KDIS_TESTS_DIR}/PDU_EncodeDecode7.cpp
    ${KDIS_TESTS_DIR}/PDU_Factory.cpp
    ${KDIS_TESTS_DIR}/PDU_FactoryDecoder5.cpp
    ${KDIS_TESTS_DIR}/PDU_ProtocolFamily5.cpp
    ${KDIS_TESTS_DIR}/PDU_ProtocolFamily6.cpp
    ${KDIS_TESTS_DIR}/PDU_ProtocolFamily7.cpp
)

#
# GoogleTest
#
CPMAddPackage(
  NAME googletest
  GITHUB_REPOSITORY google/googletest
  GIT_TAG v1.12.0
  EXCLUDE_FROM_ALL TRUE
  SYSTEM TRUE
  OPTIONS "INSTALL_GTEST OFF" "gtest_force_shared_crt ON"
)
include(GoogleTest)

#
# Test
#
enable_testing()
add_executable(${PROJECT_NAME}_tests ${KDIS_TESTS_SOURCES})
target_link_libraries(${PROJECT_NAME}_tests PRIVATE GTest::gtest_main KDIS::KDIS)
target_compile_definitions(
  ${PROJECT_NAME}_tests PRIVATE DIS_VERSION=${DIS_VERSION}
                                $<$<BOOL:${KDIS_USE_ENUM_DESCRIPTORS}>:KDIS_USE_ENUM_DESCRIPTORS>
)
# TODO target_compile_options(${PROJECT_NAME}_tests PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
# $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror> )
gtest_discover_tests(${PROJECT_NAME}_tests)
