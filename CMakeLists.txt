cmake_minimum_required (VERSION 2.8)
project (Yaml)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( Yaml yaml.cpp )
target_link_libraries( Yaml ${OpenCV_LIBS} )
