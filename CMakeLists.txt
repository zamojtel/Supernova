cmake_minimum_required(VERSION 3.23)

project(Supernova LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Prefer a package-manager-provided ANTLR runtime. The custom finder keeps the
# current, manually built Visual Studio runtime usable during the migration.
find_package(antlr4-runtime CONFIG QUIET)

if(TARGET antlr4_static)
    set(SUPERNOVA_ANTLR_TARGET antlr4_static)
elseif(TARGET antlr4_shared)
    set(SUPERNOVA_ANTLR_TARGET antlr4_shared)
else()
    find_package(Antlr4Runtime REQUIRED)
    set(SUPERNOVA_ANTLR_TARGET Antlr4::Runtime)
endif()

find_package(LLVM CONFIG REQUIRED)

if(LLVM_PACKAGE_VERSION VERSION_LESS 18)
    message(FATAL_ERROR
        "Supernova requires LLVM 18 or newer, but found ${LLVM_PACKAGE_VERSION}")
endif()

llvm_map_components_to_libnames(SUPERNOVA_LLVM_LIBRARIES
    Core
    Support
)

add_library(supernova_core STATIC
    SupernovaCore.cpp
    ListNode.cpp
)

target_include_directories(supernova_core PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCLikeLanguage"
)

target_include_directories(supernova_core SYSTEM PUBLIC ${LLVM_INCLUDE_DIRS})
target_link_directories(supernova_core PUBLIC ${LLVM_LIBRARY_DIRS})
target_link_libraries(supernova_core PUBLIC
    ${SUPERNOVA_ANTLR_TARGET}
    ${SUPERNOVA_LLVM_LIBRARIES}
)

if(LLVM_DEFINITIONS)
    separate_arguments(SUPERNOVA_LLVM_DEFINITIONS NATIVE_COMMAND "${LLVM_DEFINITIONS}")
    target_compile_options(supernova_core PUBLIC ${SUPERNOVA_LLVM_DEFINITIONS})
endif()

if(MSVC)
    target_compile_options(supernova_core PRIVATE /W3)
endif()

add_executable(supernova main.cpp)

set_target_properties(supernova PROPERTIES
    OUTPUT_NAME "Antlr_Parser_1"
)

target_link_libraries(supernova PRIVATE supernova_core)

if(MSVC)
    target_compile_options(supernova PRIVATE /W3)
endif()

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES
    main.cpp
    ParserContext.h
    SupernovaCore.cpp
    ListNode.cpp
)

set_property(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" PROPERTY VS_STARTUP_PROJECT supernova)

include(CTest)

if(BUILD_TESTING)
    include(FetchContent)

    # Keep GoogleTest's runtime-library choice consistent with the parent
    # project when building with Visual Studio.
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/52eb8108c5bdec04579160ae17225d66034bd723.zip
    )
    FetchContent_MakeAvailable(googletest)

    add_executable(supernova_tests
        tests/ReferencePtrTests.cpp
    )

    target_link_libraries(supernova_tests PRIVATE
        supernova_core
        GTest::gtest_main
    )

    if(MSVC)
        target_compile_options(supernova_tests PRIVATE /W3)
    endif()

    include(GoogleTest)
    gtest_discover_tests(supernova_tests DISCOVERY_MODE PRE_TEST)

    source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/tests" FILES
        tests/ReferencePtrTests.cpp
    )
endif()
