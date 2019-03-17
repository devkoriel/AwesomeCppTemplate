cmake_minimum_required(VERSION 3.14)

project("MyLS"
        VERSION 0.1.2
        DESCRIPTION "List files."
        HOMEPAGE_URL "https://github.com/devkoriel/AwesomeCppTemplate"
        LANGUAGES CXX)
# project(<PROJECT-NAME>
#        [VERSION <major>[.<minor>[.<patch>[.<tweak>]]]]
#        [DESCRIPTION <project-description-string>]
#        [HOMEPAGE_URL <url-string>]
#        [LANGUAGES <language-name>...])

set(SRC_FILES src/main.cpp)
# Example: set(SRC_FILES <SOURCE FILES>)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

include(functions)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-pedantic")

# include_directories(<PUBLIC HEADER DIRECTORIES>)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost 1.69.0 COMPONENTS filesystem)
if(Boost_FOUND)
    add_executable(myls ${SRC_FILES})
    target_compile_features(myls PRIVATE cxx_std_17)
    target_include_directories(myls PRIVATE include/libfoo)
    target_link_libraries(myls ${CONAN_LIBS})

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
endif()

