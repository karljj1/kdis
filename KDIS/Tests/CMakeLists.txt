IF(BUILD_TESTS)
	set(PROJECT_NAME_STR KDIS)

	add_subdirectory(gtest)
	enable_testing()
	set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_tests)
	include_directories(${GTEST_INCLUDE_DIRS} ${COMMON_INCLUDES})	
	file(GLOB TEST_SRC_FILES UnitTests/*.cpp)
	add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
	add_dependencies(${PROJECT_TEST_NAME} googletest)

if(NOT WIN32)
    target_link_libraries(${PROJECT_TEST_NAME}
        ${GTEST_LIBS_DIR}/libgtest.a
        ${GTEST_LIBS_DIR}/libgtest_main.a
        )
else()
    target_link_libraries(${PROJECT_TEST_NAME}
        debug ${GTEST_LIBS_DIR}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
        optimized ${GTEST_LIBS_DIR}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
        )
    target_link_libraries(${PROJECT_TEST_NAME}
        debug ${GTEST_LIBS_DIR}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_FIND_LIBRARY_SUFFIXES}
        optimized ${GTEST_LIBS_DIR}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_FIND_LIBRARY_SUFFIXES}
        )
endif()

target_link_libraries(${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT})

add_test(test1 ${PROJECT_TEST_NAME})

ENDIF(BUILD_TESTS)


