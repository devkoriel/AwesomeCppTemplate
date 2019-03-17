project("AwesomeCppTemplate")
# Example: project("<PROJECT NAME>")

cmake_minimum_required(VERSION 3.8)

# set(PROJECT_VERSION_MAJOR <MAJOR VERSION>)
# set(PROJECT_VERSION_MINOR <MINOR VERSION>)
# set(PROJECT_VERSION_PATCH <PATCH VERSION>)

set(CMAKE_VERBOSE_MAKEFILE true)

set(OUTPUT_BINARY "md5")
# Example: set(OUTPUT_BINARY "<BINARY NAME>")
set(SRC_FILES src/main.cpp)
# Example: set(SRC_FILES <SOURCE FILES>)

include(functions.cmake)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-pedantic")

# include_directories(<PUBLIC HEADER DIRECTORIES>)
add_executable(${OUTPUT_BINARY} ${SRC_FILES})
target_compile_features(${OUTPUT_BINARY} PRIVATE cxx_std_17)
target_include_directories(md5 PRIVATE include/libfoo)
target_link_libraries(${OUTPUT_BINARY} ${CONAN_LIBS})

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
