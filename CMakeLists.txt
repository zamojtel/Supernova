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

add_executable(supernova
    main.cpp
    ListNode.cpp
)

set_target_properties(supernova PROPERTIES
    OUTPUT_NAME "Antlr_Parser_1"
)

target_include_directories(supernova PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/GeneratedCLikeLanguage"
)

target_include_directories(supernova SYSTEM PRIVATE ${LLVM_INCLUDE_DIRS})
target_link_directories(supernova PRIVATE ${LLVM_LIBRARY_DIRS})
target_link_libraries(supernova PRIVATE ${SUPERNOVA_ANTLR_TARGET})

if(LLVM_DEFINITIONS)
    separate_arguments(SUPERNOVA_LLVM_DEFINITIONS NATIVE_COMMAND "${LLVM_DEFINITIONS}")
    target_compile_options(supernova PRIVATE ${SUPERNOVA_LLVM_DEFINITIONS})
endif()

if(MSVC)
    target_compile_options(supernova PRIVATE /W3)
endif()

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES
    main.cpp
    ListNode.cpp
)

set_property(DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" PROPERTY VS_STARTUP_PROJECT supernova)
