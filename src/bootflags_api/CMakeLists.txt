cmake_minimum_required(VERSION 2.6)
project(bootflags_api)

set(bootflags_api_source_files
  api_bootflags.cpp
)

# include_directories(${CMAKE_CURRENT_BINARY_DIR}/..)
add_library(bootflags_api ${bootflags_api_source_files})

#target_compile_definitions(bootflags_api PUBLIC -DENABLE_API_BOOTFLAGS)
