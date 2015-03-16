cmake_minimum_required(VERSION 2.6)    
include_directories("./")
file(GLOB myADTsHeaders "*.h")
file(GLOB myADTsSrcs "*.cpp")

add_library(myADTs STATIC ${myADTsSrcs} ${myADTsHeaders})
    file(GLOB test_srcs "*/test*.cpp")
    foreach(src ${test_srcs})
        get_filename_component(targetName ${src} NAME_WE)
        message("target: " ${targetName})
        add_executable(${targetName} ${src})
        target_link_libraries(${targetName} CppUnitLite ${BOOST_LIBRARIES})
        add_custom_target(${targetName}.run ${targetName} ./${targetName})
        
			add_custom_target(valgrind_${targetName} 
				COMMAND  ${targetName} &
				valgrind
					--leak-check=full
					--show-reachable=yes
					--track-fds=yes
					--error-exitcode=1
					--track-origins=yes
					--tool=memcheck
					#--log-file=${CMAKE_CURRENT_BINARY_DIR}/valgrind.log.${case_name}
					${CMAKE_CURRENT_BINARY_DIR}/${targetName}
				WORKING_DIRECTORY
					${CMAKE_CURRENT_BINARY_DIR}
			)
	endforeach(src)

option(INSTALL_myADTs "Enable/Disable installation of myADTs library" ON)
if (INSTALL_myADTs)
    install(FILES ${myADTsHeaders} DESTINATION include/myADTs)
    install(TARGETS myADTs ARCHIVE DESTINATION lib)
endif(INSTALL_myADTs)
