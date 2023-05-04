set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/SFML/cmake-modules/")
find_package(Boost 1.82.0)
if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
	add_executable (PongClient "main.cpp" "Client.cpp" "Client.h"     "common.h" "constants.h"            )
endif()

target_link_libraries(PongClient raylib sfml-system sfml-window sfml-graphics sfml-network sfml-audio)