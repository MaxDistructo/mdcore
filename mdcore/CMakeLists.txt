add_library(mdcore STATIC
	config_handler.cpp
	json_utils.cpp
	logger.cpp
	utils.cpp
)

find_package(Threads)

target_include_directories(mdcore
	PUBLIC
		${PROJECT_SOURCE_DIR}/include
		${PROJECT_SOURCE_DIR}/lib
	PRIVATE
		${PROJECT_SOURCE_DIR}/include/mdcore
)