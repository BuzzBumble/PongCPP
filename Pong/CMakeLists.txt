# CMakeList.txt : CMake project for Game, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Pong "Game.cpp" "Game.h" "Paddle.cpp" "Paddle.h" "Drawable.h" "common.h")

target_link_libraries(${PROJECT_NAME} raylib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Pong PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
