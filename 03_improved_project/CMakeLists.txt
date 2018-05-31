# If you don't have the minimum version, it is an error
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# project name with spaces!
project("Improved project")

# enable testing feature
enable_testing()

# excutable "my_app" will be created using the source files
# the header file will be automatically included
add_executable(my_app using_libraries.c myMath.c)

# after creating the executable, use 'make test' to perform the tests
add_test(my_app_test my_app)

# create a build directory where all compilation is performed
# $ mkdir build
# $ cd build
#
# Set cmake to create a makefile (-G flag) based on the project directory
# (one directory level above).
# $ cmake -G "Unix Makefiles" ..
#
# cmake will do all the hard work to create a makefile with neat features
# $ make 
# $ make test
# $ make clean
