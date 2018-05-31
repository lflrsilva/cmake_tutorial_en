# If you don't have the minimum version, it is an error
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# project name with spaces!
project("Own library with GSL")

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
# the include directory must contain the complete path. DO NOT use relative
# paths as "../../". So, you must adapt it to your case! 
include_directories(./include
    ~/Developer/learn/cmake/tutorials/06_create_library/include
    /usr/local/Cellar/gsl/2.4/include/gsl)

# you can specify the libraries and the library directory to search
# the same instruction about absolute and relative paths must be performed
# to library directories. Adapt it to your case!
set(GSL_LIBRARY libgsl.a libgslcblas.a libmy_lib.a)
link_directories(/usr/local/Cellar/gsl/2.4/lib
    ~/Developer/learn/cmake/tutorials/06_create_library/lib)
# OR
# find the NAMES libraries on PATH directories stored on a variable
# find_library(GSL_LIBRARY NAMES gsl gslcblas PATH /usr/local/Cellar/gsl/2.4/lib)

# please, mind that it will use only the library needed for this specific
# project. If you specify more libraries and it is not neeeded, cmake will
# neglect it.
message("Current found libraries : ${GSL_LIBRARY}")

# we can also define a variable for the source flies
file(GLOB SOURCES "src/*.c")

# excutable "my_app" will be created using the source variable
add_executable(my_app ${SOURCES})

# if it finds the library files, it will be used to build the executable
if(GSL_LIBRARY)
    target_link_libraries(my_app ${GSL_LIBRARY})
endif()

# let's define the installation directory. By default, cmake will
# install on the system directory
# UNIX    : /usr/local/
# WINDOWS : C:/Program Files/${PROJECT_NAME}
# To change it, use -DCMAKE_INSTALL_PREFIX=new_directory on cmake
message("Installation directory : ${CMAKE_INSTALL_PREFIX}")
install(TARGETS my_app DESTINATION bin)

# after creating the executable, use 'make test' to perform the tests
add_test(my_app_test my_app)

# IMPORTANT! This tutorial is based on an external libray!
# You must have the GNU Scientific Library installed.
# Please adapt the proper directory on lines 29 and 33 (or 36) for your system.
# Refer to https://www.gnu.org/software/gsl/ for more details

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
