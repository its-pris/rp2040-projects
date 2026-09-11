# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.3.0)
set(toolchainVersion 15_2_Rel1)
set(picotoolVersion 2.3.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Light-Intensity-Meter C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# ---- Analog (AO pin) version ----
add_executable(Light-Intensity-Meter-analog Light-Intensity-Meter-analog.c)

pico_set_program_name(Light-Intensity-Meter-analog "Light-Intensity-Meter-analog")
pico_set_program_version(Light-Intensity-Meter-analog "0.1")

pico_enable_stdio_uart(Light-Intensity-Meter-analog 0)
pico_enable_stdio_usb(Light-Intensity-Meter-analog 1)

target_link_libraries(Light-Intensity-Meter-analog
        pico_stdlib
        hardware_adc)

target_include_directories(Light-Intensity-Meter-analog PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(Light-Intensity-Meter-analog)

# ---- Digital (DO pin) version ----
add_executable(Light-Intensity-Meter-digital Light-Intensity-Meter-digital.c)

pico_set_program_name(Light-Intensity-Meter-digital "Light-Intensity-Meter-digital")
pico_set_program_version(Light-Intensity-Meter-digital "0.1")

pico_enable_stdio_uart(Light-Intensity-Meter-digital 0)
pico_enable_stdio_usb(Light-Intensity-Meter-digital 1)

target_link_libraries(Light-Intensity-Meter-digital
        pico_stdlib
        hardware_adc)

target_include_directories(Light-Intensity-Meter-digital PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(Light-Intensity-Meter-digital)