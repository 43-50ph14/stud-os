cmake_minimum_required(VERSION 3.7.2)

include(settings.cmake)

project(Hello C) # create a new C project called 'init' 

add_executable(Hello src/main.c src/io.c src/io.h src/capabilities.c src/capabilities.h) # add files to our project. Paths are relative to this file.

target_link_libraries(Hello
		sel4platsupport
		sel4muslcsys
		)

# Set this image as the rootserver
DeclareRootserver(Hello)
#include(simulation)
#GenerateSimulateScript()
