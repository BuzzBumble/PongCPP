set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/SFML/cmake-modules/")
find_package(Boost 1.82.0)
if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
	add_executable (PongClient "main.cpp" "Client.cpp" "Client.h" "Ball.cpp" "Ball.h" "Canvas.cpp" "Canvas.h" "common.h" "constants.h" "Drawable.cpp" "Drawable.h" "GameManager.cpp" "GameManager.h" "Paddle.cpp" "Paddle.h" "Pausable.cpp" "Pausable.h" "VectorHelper.cpp" "VectorHelper.h"  )
endif()

target_link_libraries(PongClient raylib sfml-system sfml-window sfml-graphics sfml-network sfml-audio)