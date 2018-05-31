# you can define a minimum version for cmake
cmake_minimum_required(VERSION 2.8)

# cmake is default to CXX projects. If you don't have a CXX compiler
# you will need to specify it (we'll see if later).

# the name of your project - choose any
# if there is a space on the name, use "quotes here"
project(mariazinha)

# add_executable(TARGET sources) will create a TARGET executable using
# the source files. Header files are handled automatically and does not
# need to be specified.

# excutable "my_app" will be created using "example.cpp" code
add_executable(my_app basic_example.cpp)

# create a build directory where all compilation is performed
# $ mkdir build
# $ cd build
#
# Set cmake to create a makefile (-G flag) based on the project directory
# (one directory level above).
# $ cmake -G "Unix Makefiles" ..
#
# cmake will do all the hard work to create a makefile with neat features
# $ make VERBOSE=1
# $ make clean

# after compilation, you can install the executable on a specific
# directory "bin" inside (default system)
# 
# use "cmake .. -DCMAKE_INSTALL_PREFIX=../install" to specify install
# directory
# install(TARGETS my_app DESTINATION bin)
