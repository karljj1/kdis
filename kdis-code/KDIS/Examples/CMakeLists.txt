
#Debug suffix
SET(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "The debug postfix") 

#Add the example directories
ADD_SUBDIRECTORY(Building)

IF(BUILD_EXAMPLES)
	ADD_SUBDIRECTORY(Extending)
	ADD_SUBDIRECTORY(Logging)
	ADD_SUBDIRECTORY(Network)
	ADD_SUBDIRECTORY(PDU)
ENDIF(BUILD_EXAMPLES)

#We need to link to the rt library for the function clock_gettime in TimeStamp.cpp when using Linux.
IF( CMAKE_SYSTEM MATCHES "Linux" )
	FIND_LIBRARY( RT_LIBRARY rt )
ENDIF( CMAKE_SYSTEM MATCHES "Linux" )


