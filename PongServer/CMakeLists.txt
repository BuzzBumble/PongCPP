find_package(Boost 1.82.0)
if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
	add_executable (PongServer "Server.cpp" "Server.h" "main.cpp" "constants.h" "Vector2.h" "Vector2.cpp" )
endif()

target_link_libraries(PongServer PUBLIC net_common)
target_include_directories(PongServer PUBLIC "${PROJECT_SOURCE_DIR}")