find_package(GTest REQUIRED)
if(${GTEST_FOUND})
	set(TEST_SOURCES
		${DIR_TESTS}/ManagerImplTests.cpp)

	add_executable(${TARGET_NAME}Tests ${TEST_SOURCES})
	target_include_directories(${TARGET_NAME}Tests PUBLIC ${GTEST_INCLUDE_DIR} ${DIR_TESTS} PRIVATE ${DIR_HEADERS})
	target_link_libraries(${TARGET_NAME}Tests ${GTEST_BOTH_LIBRARIES} ${TARGET_NAME})
	gtest_add_tests(${TARGET_NAME}Tests "" ${TEST_SOURCES})

	if( NOT ${BUILD_TESTS} )
		set_target_properties( ${TARGET_NAME}Tests PROPERTIES EXCLUDE_FROM_ALL ON )
	endif()
endif()
