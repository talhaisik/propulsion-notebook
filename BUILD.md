# Building the Project

## Prerequisites

- **C++ Compiler**: GCC 7+, Clang 5+, or MSVC 2017+
- **CMake**: Version 3.15 or higher
- **Python 3.7+**: For analysis scripts (optional)

## Quick Start

### Windows (PowerShell)

```powershell
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build
cmake --build . --config Release

# Run example
.\examples\Release\basic_calculations.exe
```

### Linux/macOS

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build
cmake --build .

# Run example
./examples/basic_calculations
```

## Build Options

Configure with options:

```bash
cmake .. -DBUILD_TESTS=ON -DBUILD_EXAMPLES=ON
```

Available options:
- `BUILD_TESTS` - Build unit tests (default: ON)
- `BUILD_EXAMPLES` - Build example programs (default: ON)
- `CMAKE_BUILD_TYPE` - Debug/Release (default: Release)

## IDE Integration

### Visual Studio Code
1. Install CMake Tools extension
2. Open folder in VS Code
3. Select kit (compiler)
4. Build with Ctrl+Shift+B

### Visual Studio
```powershell
cmake .. -G "Visual Studio 17 2022"
```
Then open `PropulsionNotebook.sln`

### CLion
Just open the project folder - CLion auto-detects CMake.

## Library Usage in Your Code

The library is header-only for now, so just include the headers:

```cpp
#include <propulsion/orbital.hpp>
#include <propulsion/rocket.hpp>
```

When building your own programs:
```cmake
find_package(PropulsionNotebook REQUIRED)
target_link_libraries(your_target PRIVATE Propulsion::Library)
```

## Troubleshooting

### "CMake version too old"
Update CMake to 3.15 or newer.

### Compiler not found
Specify compiler explicitly:
```bash
cmake .. -DCMAKE_CXX_COMPILER=g++
```

### Python scripts not working
Install dependencies:
```bash
pip install -r scripts/requirements.txt
```

## Running Tests

When tests are implemented:
```bash
cd build
ctest --output-on-failure
```

---

**Next Steps**: See [`lib/README.md`](lib/README.md) for library documentation.

