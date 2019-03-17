cmake_minimum_required(VERSION 3.8)

project("AwesomeCppTemplate")
# Example: project("<PROJECT NAME>")

# set(PROJECT_VERSION_MAJOR <MAJOR VERSION>)
# set(PROJECT_VERSION_MINOR <MINOR VERSION>)
# set(PROJECT_VERSION_PATCH <PATCH VERSION>)

set(SRC_FILES src/main.cpp)
# Example: set(SRC_FILES <SOURCE FILES>)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
# find_package(Foo REQUIRED) # FOO_INCLUDE_DIR, FOO_LIBRARIES
# find_package(Boo REQUIRED) # BOO_INCLUDE_DIR, BOO_LIBRARIES

include(functions)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-pedantic")

# include_directories(<PUBLIC HEADER DIRECTORIES>)
add_executable("md5" ${SRC_FILES})
target_compile_features("md5" PRIVATE cxx_std_17)
target_include_directories(md5 PRIVATE include/libfoo)
target_link_libraries("md5" ${CONAN_LIBS})

# OS specific instructions.
if(APPLE)
elseif(WIN32)
    # Windows developer environment specific instructions.
    if(MINGW)
    elseif(MSYS)
    elseif(CYGWIN)
    endif()
elseif(UNIX)
else()
endif()
