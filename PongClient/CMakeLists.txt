set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/SFML/cmake-modules/")
find_package(Boost 1.82.0)
if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
	add_executable (PongClient "main.cpp" "Client.cpp" "Client.h"     "common.h" "constants.h"            )
endif()

# target_link_libraries(PongClient PUBLIC net_common "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/net_common")
# target_include_directories(PongClient PUBLIC "${PROJECT_SOURCE_DIR}")