cmake_minimum_required(VERSION 3.7.2)

include(settings.cmake)

project(Hello C ASM) # create a new C project called 'init' 

#cdl_pp(${CMAKE_CURRENT_SOURCE_DIR}/.manifest.obj cdl_pp_target
#  ELF "threads"
#  CFILE "${CMAKE_CURRENT_BINARY_DIR}/cspace_threads.c"
#)

add_executable(Hello src/cspace_threads.c src/main.c src/io.c src/io.h src/capabilities.c src/capabilities.h) # add files to our project. Paths are relative to this file.

target_link_libraries(Hello
		sel4platsupport
		sel4muslcsys
                sel4 
                utils
		)

# Set this image as the rootserver
DeclareRootserver(Hello)
#include(simulation)
#GenerateSimulateScript()
