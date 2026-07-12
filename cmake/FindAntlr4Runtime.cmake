set(ANTLR4_RUNTIME_ROOT "" CACHE PATH
    "Root of an existing ANTLR4 C++ runtime build or installation")

set(_antlr4_include_hints)
set(_antlr4_debug_library_hints)
set(_antlr4_release_library_hints)

if(ANTLR4_RUNTIME_ROOT)
    list(APPEND _antlr4_include_hints
        "${ANTLR4_RUNTIME_ROOT}/src"
        "${ANTLR4_RUNTIME_ROOT}/include"
        "${ANTLR4_RUNTIME_ROOT}/include/antlr4-runtime"
    )
    list(APPEND _antlr4_debug_library_hints
        "${ANTLR4_RUNTIME_ROOT}/bin/vs-2022/x64/Debug Static"
        "${ANTLR4_RUNTIME_ROOT}/debug/lib"
        "${ANTLR4_RUNTIME_ROOT}/lib"
    )
    list(APPEND _antlr4_release_library_hints
        "${ANTLR4_RUNTIME_ROOT}/bin/vs-2022/x64/Release Static"
        "${ANTLR4_RUNTIME_ROOT}/lib"
    )
endif()

find_path(ANTLR4_RUNTIME_INCLUDE_DIR
    NAMES antlr4-runtime.h
    HINTS ${_antlr4_include_hints}
    PATH_SUFFIXES antlr4-runtime
)

find_library(ANTLR4_RUNTIME_LIBRARY_DEBUG
    NAMES antlr4-runtime
    HINTS ${_antlr4_debug_library_hints}
)

find_library(ANTLR4_RUNTIME_LIBRARY_RELEASE
    NAMES antlr4-runtime
    HINTS ${_antlr4_release_library_hints}
)

if(NOT ANTLR4_RUNTIME_LIBRARY_RELEASE AND ANTLR4_RUNTIME_LIBRARY_DEBUG)
    set(ANTLR4_RUNTIME_LIBRARY_RELEASE "${ANTLR4_RUNTIME_LIBRARY_DEBUG}")
    message(WARNING
        "ANTLR4 release library was not found; using the debug library for all configurations")
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Antlr4Runtime
    REQUIRED_VARS
        ANTLR4_RUNTIME_INCLUDE_DIR
        ANTLR4_RUNTIME_LIBRARY_DEBUG
)

if(Antlr4Runtime_FOUND AND NOT TARGET Antlr4::Runtime)
    add_library(Antlr4::Runtime STATIC IMPORTED)
    set_target_properties(Antlr4::Runtime PROPERTIES
        IMPORTED_LOCATION_DEBUG "${ANTLR4_RUNTIME_LIBRARY_DEBUG}"
        IMPORTED_LOCATION_RELEASE "${ANTLR4_RUNTIME_LIBRARY_RELEASE}"
        MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
        MAP_IMPORTED_CONFIG_MINSIZEREL Release
        INTERFACE_INCLUDE_DIRECTORIES "${ANTLR4_RUNTIME_INCLUDE_DIR}"
    )
endif()

mark_as_advanced(
    ANTLR4_RUNTIME_INCLUDE_DIR
    ANTLR4_RUNTIME_LIBRARY_DEBUG
    ANTLR4_RUNTIME_LIBRARY_RELEASE
)
