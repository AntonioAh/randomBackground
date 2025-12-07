cmake_minimum_required(VERSION 3.23)

project(SproutsProject)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_executable(randomBackground)
target_sources(randomBackground
  PRIVATE
    main.cpp
)
target_compile_options(randomBackground PRIVATE -Wall -Wextra)




add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)


# Link to the actual SDL3 library.
target_link_libraries(randomBackground PRIVATE SDL3::SDL3)