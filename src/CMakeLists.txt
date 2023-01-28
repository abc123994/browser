cmake_minimum_required(VERSION 3.12)
project(web)
set(CMAKE_WIN32_EXECUTABLE ON)
set ( CMAKE_AUTOUIC ON )
set ( CMAKE_AUTOMOC ON )
set ( CMAKE_AUTORCC ON )
find_package(Qt6Core REQUIRED)
find_package(Qt6Gui REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6 COMPONENTS WebEngineCore WebEngineWidgets REQUIRED)

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" )
file(GLOB_RECURSE SOURCE_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES} ${SOURCE_HEADERS})

add_executable(web ${SOURCE_FILES} ${SOURCE_HEADERS})

target_link_libraries(web Qt6::Core Qt6::Gui Qt6::Widgets  Qt6::WebEngineCore Qt6::WebEngineWidgets )

