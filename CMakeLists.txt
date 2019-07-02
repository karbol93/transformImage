cmake_minimum_required( VERSION 3.7.2 )
project ( opencv_all )

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( transformImage.out transformImage.cpp )
target_link_libraries( transformImage.out ${OpenCV_LIBS})
