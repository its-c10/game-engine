cmake_minimum_required(VERSION 3.15...3.30)
project(Tengine VERSION 1.0 
		DESCRIPTION "A very rudementary game engine"
		LANGUAGES CXX)
file(GLOB src
     "src/*.h"
     "src/*.cpp"
)
add_subdirectory(sdl EXCLUDE_FROM_ALL)
include_directories(src)
add_executable(${PROJECT_NAME} ${src})

# SDL2::SDL2main may or may not be available. It is e.g. required by Windows GUI applications
if(TARGET SDL2::SDL2main)
    # It has an implicit dependency on SDL2 functions, so it MUST be added before SDL2::SDL2 (or SDL2::SDL2-static)
		target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main)
endif()

# Link to the actual SDL2 library. SDL2::SDL2 is the shared SDL library, SDL2::SDL2-static is the static SDL libarary.
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)
