cmake_minimum_required(VERSION 3.0.0)
project(gtest_builder C CXX)
include(ExternalProject)

ExternalProject_Add(googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.10.0.zip
    URL_HASH SHA1=9ea36bf6dd6383beab405fd619bdce05e66a6535
    CMAKE_ARGS -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs
               -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
               -DCMAKE_CXX_FLAGS=${MSVC_COMPILER_DEFS}
               -Dgtest_force_shared_crt=ON
               -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER} 
               -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
     PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
# Disable install step
    INSTALL_COMMAND ""
)

# Specify include dir
ExternalProject_Get_Property(googletest source_dir)
set(GTEST_INCLUDE_DIRS ${source_dir}/googletest/include PARENT_SCOPE)

# Specify MainTest's link libraries
ExternalProject_Get_Property(googletest binary_dir)
set(GTEST_LIBS_DIR ${binary_dir}/lib PARENT_SCOPE)
