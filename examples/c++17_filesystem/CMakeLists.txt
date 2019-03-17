cmake_minimum_required(VERSION 3.14)

project("MyLSC++FS"
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

enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-pedantic")

# include_directories(<PUBLIC HEADER DIRECTORIES>)
add_executable(myls ${SRC_FILES})
target_compile_features(myls PRIVATE cxx_std_17)
target_link_libraries(myls "c++fs")

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
