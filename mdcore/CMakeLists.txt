add_library(mdcore STATIC
	config_handler.cpp
	json_utils.cpp
	c/logger.cpp
	c/cutils.cpp
	std/logger.cpp
	std/utils.cpp
	logger_handler.cpp
	list.cpp
)

find_package(Threads)

target_include_directories(mdcore
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
		${PROJECT_BINARY_DIR}/nlohmann_json/include
)