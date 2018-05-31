# If you don't have the minimum version, it is an error
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# project name with spaces!
project("Organise files")

# enable testing feature
enable_testing()

# we can specify the build type with the following options:
# Debug, Release, RelWithDebInfo or MinSizeRel
set(CMAKE_BUILD_TYPE Debug)

# we can also specify different options depending the compiler
# regard that we have included the option that treats warnings as errors
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror")
    # set(warnings "-Wall -Wextra")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX /EHsc")
endif()

set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ${warnings}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warnings}")
message("Current compilation flags : ${CMAKE_C_FLAGS}")

# we must specify the directory where the header files are stored
include_directories(./include)

# we can also define a variable for the source flies
set(SOURCES src/organise_files.c src/myMath.c)
# OR you may also use a global variable (GLOB) as it accepts wildcards
# file(GLOB SOURCES "src/*.c")

# excutable "my_app" will be created using the source variable
add_executable(my_app ${SOURCES})

# let's define the installation directory. By default, cmake will
# install on the system directory
# UNIX    : /usr/local/
# WINDOWS : C:/Program Files/${PROJECT_NAME}
# To change it, use -DCMAKE_INSTALL_PREFIX=new_directory on cmake
message("Installation directory : ${CMAKE_INSTALL_PREFIX}")
install(TARGETS my_app DESTINATION bin)

# after creating the executable, use 'make test' to perform the tests
add_test(my_app_test my_app)

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
# $ make test
# $ make clean
