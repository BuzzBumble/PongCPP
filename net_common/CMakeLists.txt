find_package(Boost 1.82.0)
if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
endif()

add_library(net_common "packet.h" "packet.cpp" "common.h")