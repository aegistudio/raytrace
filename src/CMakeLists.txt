add_subdirectory(geometry)

add_library(sdlcanvas sdlcanvas.cpp)
target_link_libraries(sdlcanvas SDL2 geometry)
