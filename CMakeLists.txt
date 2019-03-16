PROJECT("AwesomeCppTemplate")
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

SET(PROJECT_VERSION_MAJOR 1)
SET(PROJECT_VERSION_MINOR 2)
SET(PROJECT_VERSION_PATCH 3)

SET(CMAKE_CXX_STANDARD 17)

SET(CMAKE_VERBOSE_MAKEFILE true)

SET(OUTPUT_BINARY "md5")
SET(SRC_FILES main.cpp)

SET(CMAKE_C_COMPILER clang)
SET(CMAKE_CXX_COMPILER clang++)

INCLUDE(functions.cmake)
INCLUDE(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
CONAN_BASIC_SETUP()

enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-pedantic")

INCLUDE_DIRECTORIES(headers)
ADD_EXECUTABLE(${OUTPUT_BINARY} ${SRC_FILES})
TARGET_LINK_LIBRARIES(${OUTPUT_BINARY} ${CONAN_LIBS})

IF(APPLE)
    FIND_LIBRARY(CoreFoundation CoreFoundation)
    FIND_LIBRARY(IOKit IOKit)
    TARGET_LINK_LIBRARIES(${OUTPUT_BINARY} ${CoreFoundation} ${IOKit}) 
ELSEIF(WIN32)
ELSEIF(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
ELSE()
    MESSAGE(FATAL_ERROR "Your operating system is not compatible with MODI Studio Daemon. CMake will exit.")
ENDIF()
