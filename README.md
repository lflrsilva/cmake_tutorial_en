<!-- Universidade Federal do Rio de Janeiro -->
<!-- Escola de Quimica -->

<!-- Author : Prof. LF Silva -->
<!-- Date   : 03/05/2018 -->

Introduction
============

This is a basic tutorial series for cmake compilation tool. It is required
previous knowledge of basic terminal commands on GNU/Linux and C/C++. This
tutorial is written in English with sole purpose of helping more people. In 
addition, the motivation to write this tutorials was to provide material for 
classes on scientific computing development.

Project structure
=================
Basically, a project for code development can be organized as you want. I 
personally recommend to organize the source and compiled files for both
executables and libraries on a project individually. As such, the main
directory is directly related to the project as the subdirectories are
organized to store related files programmed by the developer. The proposed
subdirectories are:

- bin : where the executables are installed. 
- build : where the compilation files are stored
- include : where the header source files are stored.
- lib : where the libraries are stored.
- src : where the source files are stored.

and CMakeLists.txt is located on the project main directory.

Tutorials
=========
The tutorials must be followed reading the CMakeLists.txt where each command
and its purpose are briefly explained. The complexity of the projects increase
as you advance on the tutorials. For this, previous knownledge of C/C++ and
compiling is required.

Requirements
============
For libraries, the GNU Scientific Library (GSL) is used and it must be
installed on your system. Mind that the directories for the GSL header and 
source files must be adapted to your installation. Please refer to the [GSL
website](https://www.gnu.org/software/gsl/) for more information.

License and usage
=================
This work is licensed under [Creative Commons - CC BY-NC 
4.0](https://creativecommons.org/licenses/by-nc/4.0/).
