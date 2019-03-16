PROJECT("My ls")
# Example: PROJECT("<PROJECT NAME>")

CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# SET(PROJECT_VERSION_MAJOR <MAJOR VERSION>)
# SET(PROJECT_VERSION_MINOR <MINOR VERSION>)
# SET(PROJECT_VERSION_PATCH <PATCH VERSION>)

SET(CMAKE_CXX_STANDARD 17)

SET(CMAKE_VERBOSE_MAKEFILE true)

SET(OUTPUT_BINARY "myls")
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

SET(Boost_USE_STATIC_LIBS ON)
SET(Boost_USE_STATIC_RUNTIME ON)
FIND_PACKAGE(Boost 1.69.0 COMPONENTS filesystem regex system thread)
IF(Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
    # Example: INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS} <OTHER HEADER DIRECTORIES>)
    ADD_EXECUTABLE(${OUTPUT_BINARY} ${SRC_FILES})
    TARGET_LINK_LIBRARIES(${OUTPUT_BINARY} ${Boost_LIBRARIES})
    # Example: TARGET_LINK_LIBRARIES(${OUTPUT_BINARY} ${Boost_LIBRARIES} <OTHER CONAN LIBS or LIBS>)

    IF(APPLE)
        # macOS's system libraries if you need.
        FIND_LIBRARY(CoreFoundation CoreFoundation)
        FIND_LIBRARY(IOKit IOKit)
        TARGET_LINK_LIBRARIES(${OUTPUT_BINARY} ${CoreFoundation} ${IOKit}) 
    ELSEIF(WIN32)
        # Windows only headers or libraries.
    ELSEIF(UNIX)
        # UNIX OS only headers or libraries.
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    ELSE()
        MESSAGE(FATAL_ERROR "Your operating system is not compatible. CMake will exit.")
    ENDIF()
ELSE()
    MESSAGE(FATAL_ERROR "Boost Not Found.")
ENDIF()
