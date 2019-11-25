# Minimum version can be no higher than 3.5 as Ubuntu package management uses this version.
cmake_minimum_required(VERSION 3.5)

project (EX05-HashTable)

set(SOURCE_PREFIX "hashtable")
set(EXEC_NAME "HashTable")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wreturn-type -Werror")

if(EXISTS ${CMAKE_HOME_DIRECTORY}/csv15-lib/CMakeLists.txt)
    include(csv15-lib/CMakeLists.txt)
elseif(EXISTS /usr/local/csv15-lib/CMakeLists.txt)
    include(/usr/local/csv15-lib/CMakeLists.txt)
else()
    add_custom_target(add-submodules ALL git clone https://github.com/vc-csv15/csv15-lib.git)
endif()

