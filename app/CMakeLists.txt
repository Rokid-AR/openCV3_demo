# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_VERBOSE_MAKEFILE on)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(opencv_DIR ${CMAKE_SOURCE_DIR}/../opencv_sdk)

include_directories(${opencv_DIR}/native/jni/include)

add_library( gray-process SHARED src/main/cpp/gray-process.cpp )

add_library(lib_opencv SHARED IMPORTED)

set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION ${opencv_DIR}/native/libs/${ANDROID_ABI}/libopencv_java3.so)

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

target_link_libraries( gray-process lib_opencv ${log-lib} )
