include_guard(GLOBAL)

set(project_dir "${CMAKE_CURRENT_LIST_DIR}/../../")
file(GLOB project_modules ${project_dir}/projects/*)
list(
    APPEND
        CMAKE_MODULE_PATH
        ${project_dir}/kernel
        ${project_dir}/tools/cmake-tool/helpers/
        ${project_dir}/tools/elfloader-tool/
        ${project_modules}
)
include(/host/application_settings.cmake)

set(KernelArch "riscv")
set(KernelPlatform "spike")
set(KernelSel4Arch "riscv")

include(/host/kernel/configs/seL4Config.cmake)
#set(CapDLLoaderMaxObjects 20000 CACHE STRING "" FORCE)
#set(KernelRootCNodeSizeBits 16 CACHE STRING "")

# For the tutorials that do initialize the plat support serial printing they still
# just want to use the kernel debug putchar if it exists
#set(LibSel4PlatSupportUseDebugPutChar true CACHE BOOL "" FORCE)

# Just let the regular abort spin without calling DebugHalt to prevent needless
# confusing output from the kernel for a tutorial
#set(LibSel4MuslcSysDebugHalt FALSE CACHE BOOL "" FORCE)

# Only configure a single domain for the domain scheduler
#set(KernelNumDomains 1 CACHE STRING "" FORCE)

# We must build the debug kernel because the tutorials rely on seL4_DebugPutChar
# and they don't initialize a platsupport driver.
#ApplyCommonReleaseVerificationSettings(FALSE FALSE)

# We will attempt to generate a simulation script, so try and generate a simulation
# compatible configuration
#ApplyCommonSimulationSettings(${KernelSel4Arch})
#if(FORCE_IOMMU)
#    set(KernelIOMMU ON CACHE BOOL "" FORCE)
#endif()

