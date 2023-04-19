add_executable (Pong "Game.cpp" "Game.h" "Paddle.cpp" "Paddle.h" "Drawable.h" "common.h" "Ball.h" "Ball.cpp" "VectorHelper.cpp" "VectorHelper.h" "GameManager.h" "GameManager.cpp" "Canvas.cpp" "Canvas.h")

target_link_libraries(${PROJECT_NAME} raylib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Pong PROPERTY CXX_STANDARD 20)
endif()
