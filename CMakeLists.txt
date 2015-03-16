cmake_minimum_required(VERSION 2.6)
SET(CMAKE_VERBOSE_MAKEFILE ON)

SET(CMAKE_CXX_FLAGS CACHE STRING "${CMAKE_CXX_FLAGS} -std=c++0x -I -D -fPIC -Wall")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} CACHE STRING "C++ flags" FORCE)

SET(CMAKE_C_FLAGS CACHE STRING "${CMAKE_C_FLAGS} -I -D -fPIC")
set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} CACHE STRING "C flags" FORCE)

SET(CMAKE_CXX_COMPILER "/usr/bin/g++-4.8")
SET(CMAKE_C_COMPILER "/usr/bin/gcc-4.8")

project(ctci-c++)

message("cmake source dir: " ${CMAKE_CURRENT_SOURCE_DIR})

# Ensure that local folder is searched before library folders
include_directories(BEFORE "${PROJECT_SOURCE_DIR}" myADTs)

# Build CppUnitLite
add_subdirectory(CppUnitLite)

# Build myADTs
add_subdirectory(myADTs)

# Build ctci
add_subdirectory(ctci)

# Build Doxygen Documentation
find_package(Doxygen)

find_package(Boost 1.43 COMPONENTS serialization system filesystem thread program_options date_time regex timer chrono)

set(BOOST_LIBRARIES
    ${Boost_SERIALIZATION_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY}
	${Boost_THREAD_LIBRARY} ${Boost_DATE_TIME_LIBRARY} ${Boost_REGEX_LIBRARY} ${Boost_CHRONO_LIBRARY}) #${Boost_TIMER_LIBRARY}
      
if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in 
                   ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../myADTs
    COMMENT "Generating API documentation with Doxygen" VERBATIM
)
endif(DOXYGEN_FOUND)
