# If you don't have the minimum version, it is an error
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project("Create library")

# the header files related to any source will be directly searched
include_directories(./include)

file(GLOB SOURCES "src/*.c")

# excutable "my_app" will be created using the source variable
add_library(my_lib STATIC ${SOURCES})

# To change it, use -DCMAKE_INSTALL_PREFIX=new_directory on cmake
message("Installation directory : ${CMAKE_INSTALL_PREFIX}")
install(TARGETS my_lib DESTINATION lib)

# create a build directory where all compilation is performed
# $ mkdir build
# $ cd build
#
# Set cmake to create a makefile (-G flag) based on the project directory
# (one directory level above).
# $ cmake .. -G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=../
#
# cmake will do all the hard work to create a makefile with neat features
# $ make 
# $ make install
# $ make clean
