cmake_minimum_required(VERSION 2.6)
project(feature_toggles)


# Enable 
option(ENABLE_API_BOOTFLAGS "API for setting bootflags" OFF)
option(WATCHDOG_API "API for directly controlling the watchdog" OFF)

add_executable(feature_toggles main.cpp)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h @ONLY)

if(ENABLE_API_BOOTFLAGS)
    message("Bootflags ON")
    add_subdirectory(bootflags_api)
    target_link_libraries(feature_toggles bootflags_api)
else()
    message("Bootflags OFF")
endif(ENABLE_API_BOOTFLAGS)

install(TARGETS feature_toggles RUNTIME DESTINATION bin)
