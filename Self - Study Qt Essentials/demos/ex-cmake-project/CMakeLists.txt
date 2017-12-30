project(ex-cmake-project)
cmake_minimum_required(VERSION 2.8.11)
# Define sources
aux_source_directory(. SRC_LIST)
# Find headers
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Define Qt module locations
# Qt install folder defined with CMAKE_PREFIX_PATH
find_package(Qt5Widgets)
# Executable to be created
add_executable(${PROJECT_NAME} ${SRC_LIST})
# Link executable to any libraries
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)









