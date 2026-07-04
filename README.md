# PZWorldEd — Unofficial WorldEd Fork

A fork of WorldEd, the world editor for Project Zomboid, extended with B42 support and additional features.

## Features

- **B42 support** — fully compatible with basements, animals, WorldGen, and other B42 additions (256×256 tile cells)
- **Standalone** — does not rely on the Windows registry or a folder in `%USERPROFILE%`; multiple versions can coexist on the same PC
- **InGameMap** — route generation, full building export, built-in Lua engine
- **Biomemap Generator** — based on two images (Main and `_veg`), with automatic tile splitting
- **Dark theme** included by default; custom QSS themes are supported
- **Improved tiles** — better visibility, enhanced Tiles Unpacker with advanced options
- **High-resolution thumbnails** — up to 8192 px for map rendering without external apps

---

## Building on Windows

### Prerequisites

| Tool | Minimum version | Notes |
|------|----------------|-------|
| **CMake** | 3.18 | [cmake.org/download](https://cmake.org/download/) — make sure to add it to `PATH` during installation |
| **Qt 6** | 6.5 | [qt.io](https://www.qt.io/download-qt-installer) — install the **MSVC 2022 64-bit** or **MinGW 64-bit** component |
| **Compiler** | C++17 | Visual Studio 2019/2022 (*Desktop development with C++*) **or** MinGW-w64 (bundled with the Qt installer) |
| **Git** | any | Optional, for cloning |

> Qt 6.5 or newer is required. Qt 5 is not supported.

---

### Step 1 — Clone the repository

```bat
git clone https://github.com/your-org/PZWorldEd.git
cd PZWorldEd
```

---

### Step 2 — Configure with CMake

CMake needs to know where Qt 6 is installed. Pass the path via `-DCMAKE_PREFIX_PATH`.

Replace `C:/Qt/6.x.x/msvc2022_64` with the actual path on your machine
(e.g. `C:/Qt/6.11.1/msvc2022_64` or `D:/Qt/6.9.0/mingw_64`).

**Visual Studio 2022 (recommended)**

```bat
cmake -B build ^
      -DCMAKE_PREFIX_PATH="C:/Qt/6.x.x/msvc2022_64" ^
      -G "Visual Studio 17 2022" -A x64
```

**Visual Studio 2019**

```bat
cmake -B build ^
      -DCMAKE_PREFIX_PATH="C:/Qt/6.x.x/msvc2022_64" ^
      -G "Visual Studio 16 2019" -A x64
```

**MinGW (bundled with Qt installer)**

```bat
cmake -B build ^
      -DCMAKE_PREFIX_PATH="C:/Qt/6.x.x/mingw_64" ^
      -DCMAKE_BUILD_TYPE=Release ^
      -G "MinGW Makefiles"
```

> **Tip — avoid typing the path every time**
>
> Set `CMAKE_PREFIX_PATH` as a persistent environment variable in Windows:
> ```bat
> setx CMAKE_PREFIX_PATH "C:/Qt/6.x.x/msvc2022_64"
> ```
> After that, you can omit `-DCMAKE_PREFIX_PATH` from the cmake command.

---

### Step 3 — Build

```bat
cmake --build build --config Release --parallel
```

The executable is placed at `build/bin/Release/PZWorldEd.exe`.

---

### Step 4 — Run

Before running, Qt DLLs must be on the `PATH` or deployed alongside the executable.
The easiest way during development:

```bat
set PATH=C:/Qt/6.x.x/msvc2022_64/bin;%PATH%
build\bin\Release\PZWorldEd.exe
```

For a distributable build, use `windeployqt`:

```bat
cd build\bin\Release
"C:\Qt\6.x.x\msvc2022_64\bin\windeployqt.exe" PZWorldEd.exe
```

---

## Project structure

```
PZWorldEd/
├── CMakeLists.txt          # Root CMake file
├── src/
│   ├── editor/             # Main application
│   ├── libtiled/           # Tiled map library (static)
│   ├── lua/                # Bundled Lua 5.2 (static)
│   ├── quazip-1.1/         # Bundled QuaZip (static)
│   ├── qtlockedfile/       # Bundled QtLockedFile (static)
│   └── zlib/               # Bundled zlib 1.3.1 (static)
└── build/                  # CMake build directory (not committed)
```

All dependencies except Qt are bundled in source form — no external installs are required beyond Qt itself and a C++ compiler.

---

## License

GPL v2 — see [LICENSE.GPL](LICENSE.GPL).
Qt components — see [LICENSE.QT5](LICENSE.QT5).
