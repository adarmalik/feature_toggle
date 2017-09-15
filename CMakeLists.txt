cmake_minimum_required(VERSION 2.6)
project(feature_toggles)

OPTION(BOOTFLAGSAPI "API for setting bootflags" OFF)

add_executable(feature_toggles main.cpp)

if(BOOTFLAGSAPI)
    MESSAGE("Bootflags ON")
    add_subdirectory(bootflags_api)
    target_link_libraries(feature_toggles bootflags_api)
else()
    MESSAGE("Bootflags OFF")
endif(BOOTFLAGSAPI)

install(TARGETS feature_toggles RUNTIME DESTINATION bin)
