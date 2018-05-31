#
#  IMPORTANT!!
#  You must execute this example as a cmake script
#  $ cmake -P CMakeLists.txt 
#

# Let's begin with a personal message
message("You are about to learn more about cmake!")

# you can also define variables as text and use it
set(MY_NAME "LF")
# to use the variable, you need to express as ${}
message("Hello, ${MY_NAME}! Time to roll!")

# data structure for variables is also possible
set(LF_NAME "LF Silva")
set(LF_WORK "Professor")
set(PERSON "LF")
message("${${PERSON}_NAME} works as ${${PERSON}_WORK}")
message(" ")

# there are specific variables set by cmake. There goes a few that
# may be useful.
message("CMake command      : ${CMAKE_COMMAND}")
message("CMake version      : ${CMAKE_VERSION}")
message("CMake patch version: ${CMAKE_PATCH_VERSION}")
message("System host name   : ${CMAKE_HOST_SYSTEM_NAME}")
message("Project directory  : ${CMAKE_BINARY_DIR}")
message(" ")
# Compiler variables would be available when using compiling a project.
# For script mode, these variables are empty.
# message("Compiler           : ${CMAKE_CXX_COMPILER_ID}")
# message("Compiler C flags   : ${CMAKE_C_FLAGS}")
# message("Compiler CXX flags : ${CMAKE_CXX_FLAGS}")
# message("Libraries path     : ${CMAKE_LIBRARY_PATH}")

# cmake also have flow control commands
# we are using default cmake variables here
if(WIN32)
    message("You are using Windows (32 or 64 bits).")
elseif(APPLE)
    message("You are using an Apple plataform (macOS, iOS, tvOS or watchOS)")
elseif(UNIX)
    message("You are using a Unix or Unix-like system")
endif()
message(" ")

# cmake can loop over a condition
set(A "1")
set(B "1")
while(A LESS "100")
    # Print A
    message("${A}")
    # Use a math expression using the numeric values of A and B
    # and store the result in T
    math(EXPR T "${A} + ${B}")
    # update B and T
    set(A "${B}")
    set(B "${T}")
endwhile()
message(" ")

# we can also work with lists separating the arguments with ;
set(ARGS "EXPR;GS;1 + 3")

# and we can execute or message it
math(${ARGS})
message(${GS})

message("${ARGS}")

# and we can list each item separatelly
foreach(IT ${ARGS})
    message("${IT}")
endforeach()

# You can also work with functions, macros and include other script fles
# but this complexity is out of scope of this tutorial. You may find more
# informations on the references below.

# this tutorial was based on the awsome work in
# http://preshing.com/20170522/learn-cmakes-scripting-language-in-15-minutes/

# for more information about cmake variables
# https://cmake.org/cmake/help/latest/manual/cmake-variables.7.html#id1

# for more information about cmake commands
# https://cmake.org/cmake/help/latest/manual/cmake-commands.7.html
# https://cmake.org/cmake/help/latest/command/if.html
# https://cmake.org/cmake/help/latest/command/while.html
# https://cmake.org/cmake/help/latest/command/foreach.html

