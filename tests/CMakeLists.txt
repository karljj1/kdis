# Sources
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

# GoogleTest
CPMAddPackage(
  NAME googletest
  GITHUB_REPOSITORY google/googletest
  GIT_TAG v1.14.0
  EXCLUDE_FROM_ALL ON
  SYSTEM ON
  OPTIONS "INSTALL_GTEST OFF" "gtest_force_shared_crt ON"
)
include(GoogleTest)

# Test
enable_testing()
add_executable(${CMAKE_PROJECT_NAME}_tests ${KDIS_TESTS_SOURCES})
target_link_libraries(${CMAKE_PROJECT_NAME}_tests GTest::gtest_main)
gtest_discover_tests(${CMAKE_PROJECT_NAME}_tests)

if(BUILD_EXAMPLES_TO_LINK_TO_LIB)

  if(EXAMPLES_USE_STATIC_OR_SHARED_LIB MATCHES STATIC)
    target_link_libraries(${PROJECT_TEST_NAME} KDIS_LIB)
  endif(EXAMPLES_USE_STATIC_OR_SHARED_LIB MATCHES STATIC)

  if(EXAMPLES_USE_STATIC_OR_SHARED_LIB MATCHES SHARED)
    target_link_libraries(${PROJECT_TEST_NAME} KDIS_DLL)
    add_definitions(-D "IMPORT_KDIS")
  endif(EXAMPLES_USE_STATIC_OR_SHARED_LIB MATCHES SHARED)

endif(BUILD_EXAMPLES_TO_LINK_TO_LIB)

if(DIS_VERSION MATCHES 6)
  add_definitions(-D "DIS_VERSION=6")
endif(DIS_VERSION MATCHES 6)

if(DIS_VERSION MATCHES 5)
  add_definitions(-D "DIS_VERSION=5")
endif(DIS_VERSION MATCHES 5)

if(DIS_VERSION MATCHES 7)
  add_definitions(-D "DIS_VERSION=7")
endif(DIS_VERSION MATCHES 7)

if(KDIS_USE_ENUM_DESCRIPTORS)
  add_definitions(-D "KDIS_USE_ENUM_DESCRIPTORS")
endif(KDIS_USE_ENUM_DESCRIPTORS)
