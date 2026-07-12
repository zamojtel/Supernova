# Supernova

Programming language and compiler project.

## Building with CMake on Windows

Requirements:

- Visual Studio 2022 with the C++ workload
- CMake 3.23 or newer
- ANTLR4 C++ runtime 4.13.2
- LLVM 18 or newer

Copy `CMakeUserPresets.json.example` to `CMakeUserPresets.json` and update
`ANTLR4_RUNTIME_ROOT` and `LLVM_DIR` for your machine. The user preset is
ignored by Git because it contains machine-specific paths.

Configure and build the Debug version:

```powershell
cmake --preset local-vs2022-x64
cmake --build --preset local-vs2022-x64-debug
```

The executable is created under:

```text
out/build/vs2022-x64/Debug/Antlr_Parser_1.exe
```

The existing Visual Studio solution remains available during the CMake
migration.
