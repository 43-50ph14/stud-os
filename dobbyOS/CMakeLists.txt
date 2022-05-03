### SeL4_101 CMakeLists.txt ###
cmake_minimum_required(VERSION 3.7.2)

#message(STATUS "Femur print " ${KernelX86Sel4Arch_all_strings})

#if (${PLATFORM} IN_LIST KernelRiscVSel4Arch_all_strings)
if (${PLATFORM} IN_LIST KernelRiscVPlatform_all_strings)
#if (${PLATFORM} IN_LIST ${KernelX86Sel4Arch_all_strings} ${KernelARMPlatform_all_strings}
        set(KernelArch riscv CACHE STRING "" FORCE)
        set(KernelRiscVSel4Arch riscv64 CACHE STRING "" FORCE)
endif()


include(tools/cmake-tool/default-CMakeLists.txt)
if(SIMULATION)
        ApplyCommonSimulationSettings("riscv64")
else()
        if(KernelArchX86)
                set(KernelIOMMU ON CACHE BOOL "" FORCE)
        endif()
endif()

# We must build the debug kernel because the tutorials rely on seL4_DebugPutChar
# and they don't initialize a platsupport driver.
ApplyCommonReleaseVerificationSettings(FALSE FALSE)

GenerateSimulateScript()
