cmake_minimum_required(VERSION 3.12)
project(Stickies++ CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find FLTK package
find_package(FLTK REQUIRED)

# Include directories
include_directories(${FLTK_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add executable
add_executable(Stickies++ 
    src/main.cpp
    src/NoteWindow.cpp
)

# Link against FLTK libraries
target_link_libraries(Stickies++ ${FLTK_LIBRARIES})

# Add compile options
if(MSVC)
    target_compile_options(Stickies++ PRIVATE /W4)
else()
    target_compile_options(Stickies++ PRIVATE -Wall -Wextra -pedantic)
endif()