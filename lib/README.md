# Propulsion Library

Core C++ library providing aerospace propulsion and flight dynamics calculations.

## Structure

```
lib/
├── include/              # Public header files
│   ├── propulsion/      # Core physics modules
│   │   ├── orbital.hpp  # Orbital mechanics
│   │   └── rocket.hpp   # Rocket performance
│   ├── simulation/      # Simulation components (planned)
│   └── mission/         # Mission analysis (planned)
├── src/                  # Implementation files (when needed)
└── tests/                # Unit tests (planned)
```

## Current Status

**Implemented:**
- ✅ Basic orbital mechanics (velocity, period, escape velocity)
- ✅ Tsiolkovsky rocket equation and related calculations
- ✅ Header-only library for rapid prototyping

**Planned:**
- [ ] Multi-stage rocket calculations
- [ ] Atmospheric models
- [ ] Trajectory integration
- [ ] Propellant properties
- [ ] Unit tests with Catch2 or Google Test

## Usage

All functionality is currently header-only. Include what you need:

```cpp
#include <propulsion/orbital.hpp>
#include <propulsion/rocket.hpp>
#include <iostream>

int main() {
    // Calculate LEO orbital velocity at 400 km altitude
    double altitude = 400e3;  // meters
    double r = propulsion::orbital::radius_from_altitude(altitude);
    double v = propulsion::orbital::orbital_velocity(
        propulsion::orbital::MU_EARTH, r
    );
    
    std::cout << "LEO velocity at " << altitude/1000 << " km: "
              << v/1000 << " km/s\n";
    
    // Calculate delta-v for a rocket stage
    double dv = propulsion::rocket::delta_v(
        10000,  // m0 (kg)
        2000,   // mf (kg)
        300     // Isp (s)
    );
    
    std::cout << "Delta-v: " << dv/1000 << " km/s\n";
    
    return 0;
}
```

## Building

With CMake from project root:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Design Philosophy

- **Header-only initially**: Fast iteration, easy to use
- **Well-documented**: Every function has clear documentation
- **Unit-tested**: Validate against known values (when tests added)
- **Industry-ready**: Code quality suitable for portfolio/employment

## Contributing to the Library

When adding new functionality:

1. **Document thoroughly**: Use Doxygen-style comments
2. **Include references**: Cite equations/textbooks
3. **Add examples**: Show typical usage
4. **Validate**: Compare against known results or other tools
5. **Test**: Unit tests for each function (when test framework added)

---

**Note**: This is a learning project. Code is shared for educational purposes. No warranties for accuracy or correctness.

