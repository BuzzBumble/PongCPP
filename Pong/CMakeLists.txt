add_executable (Pong 
"Game.h" "Game.cpp"  
"Paddle.h" "Paddle.cpp"
"common.h" 
"Ball.h" "Ball.cpp" 
"VectorHelper.h"  "VectorHelper.cpp"
"GameManager.h" "GameManager.cpp" 
"Canvas.h" "Canvas.cpp" 
"Pausable.h" "Pausable.cpp" 
 "Drawable.h" "Drawable.cpp" 
"constants.h")

target_link_libraries(Pong raylib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Pong PROPERTY CXX_STANDARD 20)
endif()
