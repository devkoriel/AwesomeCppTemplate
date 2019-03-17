PROJECT("AwesomeCppTemplate")
# Example: PROJECT("<PROJECT NAME>")

CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# SET(PROJECT_VERSION_MAJOR <MAJOR VERSION>)
# SET(PROJECT_VERSION_MINOR <MINOR VERSION>)
# SET(PROJECT_VERSION_PATCH <PATCH VERSION>)

SET(CMAKE_CXX_STANDARD 17)

SET(CMAKE_VERBOSE_MAKEFILE true)

SET(OUTPUT_BINARY "md5")
# Example: SET(OUTPUT_BINARY "<BINARY NAME>")
SET(SRC_FILES src/main.cpp)
# Example: SET(SRC_FILES <SOURCE FILES>)

SET(CMAKE_C_COMPILER clang)
SET(CMAKE_CXX_COMPILER clang++)

INCLUDE(functions.cmake)
INCLUDE(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
CONAN_BASIC_SETUP()

enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-pedantic")

INCLUDE_DIRECTORIES(include/libfoo)
# Example: INCLUDE_DIRECTORIES(<HEADER DIRECTORIES>)
ADD_EXECUTABLE(${OUTPUT_BINARY} ${SRC_FILES})
TARGET_LINK_LIBRARIES(${OUTPUT_BINARY} ${CONAN_LIBS})

IF(APPLE)
    # macOS only headers or libraries.
    # FIND_LIBRARY(CoreFoundation CoreFoundation)
    # FIND_LIBRARY(IOKit IOKit)
    # TARGET_LINK_LIBRARIES(${OUTPUT_BINARY} ${CoreFoundation} ${IOKit}) 
ELSEIF(WIN32)
    # Windows only headers or libraries.
ELSEIF(UNIX)
    # UNIX OS only headers or libraries.
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
ELSE()
    MESSAGE(FATAL_ERROR "Your operating system is not compatible. CMake will exit.")
ENDIF()
