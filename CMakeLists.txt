# find a way to set board to pc
set(TUT_BOARD "pc")
set(TUT_ARCH "x86_64")
include(./projects/sel4-tutorials/settings.cmake)

cmake_minimum_required(VERSION 3.7.2)

# project and language (C)
project(src C ASM)

#sel4_import_kernel()

# name executable and list sourve files required to build it
add_executable(hello-world src/main.c)

# list of libaries to link with application
target_link_libraries(hello-world
    sel4runtime sel4
    muslc utils sel4tutorials
    sel4muslcsys sel4platsupport sel4utils sel4debug)

# tell build system, that application is root task
#include(rootserver)
#DeclareRootserver(hello-world)

configure_file(./projects/sel4-tutorials/tools/expect.py ${CMAKE_BINARY_DIR}/check @ONLY)
include(simulation)
GenerateSimulateScript()
