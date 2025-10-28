# Quick Reference: Rocket Science Essentials

**Source:** Yale University - Rocket Science for Everyone (Coursera)  
**Last Updated:** October 28, 2025

---

## Key Equations

### Orbital Mechanics

| Equation             | Formula                                                     | Description                 |
|----------------------|-------------------------------------------------------------|-----------------------------|
| **Orbital velocity** | \( v = \sqrt{\frac{GM}{r}} \)                               | Circular orbit speed        |
| **Escape velocity**  | \( v_{esc} = \sqrt{\frac{2GM}{r}} = \sqrt{2} v_{orbital} \) | Speed to leave gravity well |
| **Orbital period**   | \( T = 2\pi \sqrt{\frac{r^3}{\mu}} \)                       | Time for one orbit          |
| **Kepler's 3rd Law** | \( T^2 = \frac{4\pi^2}{GM} a^3 \)                           | Period vs. semi-major axis  |

**Constants:**
- \( G = 6.674 \times 10^{-11} \, \text{m}^3\text{kg}^{-1}\text{s}^{-2} \)
- \( M_{Earth} = 5.972 \times 10^{24} \, \text{kg} \)
- \( \mu = GM = 3.986 \times 10^{14} \, \text{m}^3/\text{s}^2 \)
- \( g_0 = 9.81 \, \text{m/s}^2 \)

### Rocket Propulsion

| Equation             | Formula                                                | Description                 |
|----------------------|--------------------------------------------------------|-----------------------------|
| **Thrust**           | \( F = \dot{m} v_e \)                                  | Force from mass flow        |
| **Specific impulse** | \( I_{sp} = \frac{v_e}{g_0} \)                         | Engine efficiency (seconds) |
| **Rocket equation**  | \( \Delta v = v_e \ln\left(\frac{m_0}{m_f}\right) \)   | Tsiolkovsky equation        |
| **Mass ratio**       | \( MR = \frac{m_0}{m_f} = e^{\Delta v / v_e} \)        | Initial to final mass       |
| **Exhaust velocity** | \( v_e = I_{sp} \cdot g_0 \)                           | Effective exhaust speed     |

---

## Typical Values

### Orbital Velocities & Altitudes

| Orbit         | Altitude  | Velocity  | Period   |
|---------------|-----------|-----------|----------|
| **LEO**       | 400 km    | 7.7 km/s  | 92 min   |
| **LEO**       | 2,000 km  | 6.9 km/s  | 127 min  |
| **GPS (MEO)** | 20,200 km | 3.9 km/s  | 12 hours |
| **GEO**       | 35,786 km | 3.1 km/s  | 24 hours |
| **Escape**    | Surface   | 11.2 km/s | N/A      |

### Rocket Performance

| Propellant     | Type       | Isp (s)      | Applications            |
|----------------|------------|--------------|-------------------------|
| Solid (APCP)   | Solid      | 250-280      | Boosters, missiles      |
| RP-1/LOX       | Liquid     | 300-360      | First stages (Falcon 9) |
| LH2/LOX        | Liquid     | 380-450      | Upper stages (Delta IV) |
| Methane/LOX    | Liquid     | 330-380      | Starship, reusability   |
| Hydrazine/N2O4 | Hypergolic | 300-330      | Spacecraft maneuvering  |
| Ion thruster   | Electric   | 3,000-10,000 | Station-keeping         |

### Delta-V Requirements

| Mission             | Δv (km/s) | Notes                        |
|---------------------|-----------|------------------------------|
| LEO from surface    | ~9.0      | Includes gravity/drag losses |
| LEO to GEO          | ~4.0      | Two-burn transfer            |
| LEO to escape       | ~3.2      | From 200 km circular         |
| LEO to Moon surface | ~6.0      | From LEO, includes landing   |
| LEO to Mars         | ~6-8      | Depends on transfer window   |

### Launch Site Velocity Bonus

| Location       | Latitude | Eastward Bonus |
|----------------|----------|----------------|
| Equator        | 0°       | 465 m/s        |
| KSC, Florida   | 28.5°    | 408 m/s        |
| Vandenberg, CA | 34.7°    | 381 m/s        |
| Baikonur       | 45.6°    | 325 m/s        |

---

## Quick Facts

### Orbital Regions

**Low Earth Orbit (LEO):** 160-2,000 km
- Fastest orbital speeds (~7-8 km/s)
- Short periods (90-120 min)
- Atmospheric drag present
- Examples: ISS, Starlink, Hubble

**Medium Earth Orbit (MEO):** 2,000-35,786 km
- GPS constellation at 20,200 km
- 2-12 hour periods
- Van Allen radiation belts

**Geosynchronous Earth Orbit (GEO):** 35,786 km
- 24-hour period
- Geostationary if equatorial and circular
- Communications, weather satellites

### Rocket Types

**Solid:**
- ✅ Simple, reliable, storable
- ❌ Can't throttle or shut down
- Use: Boosters, military missiles

**Liquid:**
- ✅ Throttleable, restartable, higher Isp
- ❌ Complex, plumbing, cryogenics
- Use: Most orbital launchers

### Staging

**Why stage?**
- Exponential rocket equation penalizes dead mass
- Dropping empty tanks improves mass ratio
- 2-3 stages typical for orbital launchers

**Types:**
- **Serial:** Vertical stack (Saturn V, Falcon 9)
- **Parallel:** Strap-on boosters (Space Shuttle, Atlas V)

---

## Newton's Laws for Rockets

1. **Inertia:** Objects maintain velocity unless force applied
   - Satellites stay in orbit without thrust

2. **F = ma:** Force equals mass times acceleration
   - Thrust: \( F = \dot{m} v_e \)

3. **Action-Reaction:** Every action has equal opposite reaction
   - Exhaust goes down → rocket goes up
   - **Works in vacuum** (pushes against propellant, not air)

---

## Satellite Systems

### Power
- **Source:** Solar panels (28-32% efficient)
- **Storage:** Lithium-ion batteries
- **LEO challenge:** 30 min eclipse per 90 min orbit

### Communications
- **Frequencies:** VHF → UHF → S → X → Ku → Ka bands
- Higher frequency = more bandwidth, smaller antennas
- **Latency:**
  - LEO: ~5-10 ms
  - GEO: ~240 ms (0.12 s each way)

### Imaging
- **Optical:** Like digital camera, needs sunlight
- **Infrared:** Detects heat, works at night
- **Radar (SAR):** Active, works through clouds
- **Resolution vs altitude:** Lower orbit = better resolution

### Attitude Control
- **Sensors:** Star trackers, sun sensors, gyros
- **Actuators:** Reaction wheels, magnetorquers, thrusters
- **Accuracy:** 0.01-0.1° typical

---

## Common Pitfalls & Misconceptions

❌ **"Satellites escape gravity"**
- ✅ Satellites are always in Earth's gravity, constantly falling

❌ **"Rockets push against air"**
- ✅ Rockets push against their own exhaust (work in vacuum)

❌ **"Getting to space is about altitude"**
- ✅ It's about **velocity** - need ~7.7 km/s horizontal speed

❌ **"More stages always better"**
- ✅ Diminishing returns; complexity increases

❌ **"Bigger engines always better"**
- ✅ Depends on mission; Isp often more important than thrust

---

## Problem-Solving Checklist

### Orbital Problems
1. Identify orbit type (circular/elliptical)
2. Find orbital radius \( r \) (altitude + Earth radius 6,371 km)
3. Apply appropriate formula (velocity, period, energy)
4. Check units (m vs km, s vs hours)

### Rocket Problems
1. Identify known values: \( m_0 \), \( m_f \), \( I_{sp} \), \( \Delta v \)
2. Calculate \( v_e = I_{sp} \times 9.81 \) m/s
3. Apply rocket equation
4. For staging, sum \( \Delta v \) of each stage

### Satellite Design
1. Define mission requirements
2. Select orbit (LEO/MEO/GEO)
3. Size power system (worst-case eclipse)
4. Calculate communication link budget
5. Determine pointing accuracy needs
6. Estimate propellant for lifetime

---

## Useful Conversions

| From    | To          | Multiply by       |
|---------|-------------|-------------------|
| km/s    | m/s         | 1,000             |
| km/s    | mph         | 2,237             |
| km      | Earth radii | 0.000157 (1/6371) |
| degrees | radians     | π/180 = 0.01745   |
| minutes | seconds     | 60                |
| hours   | seconds     | 3,600             |

---

## Resources for Further Study

### Textbooks
- Curtis, H. D. - *Orbital Mechanics for Engineering Students*
- Sutton & Biblarz - *Rocket Propulsion Elements*
- Wertz & Larson - *Space Mission Analysis and Design*

### Online Tools
- **STK (Systems Tool Kit):** Mission planning software
- **GMAT:** NASA's trajectory optimization tool
- **Orbiter:** Free space flight simulator
- **KSP (Kerbal Space Program):** Game with realistic orbital mechanics

### Courses
- MIT OCW: Aeronautics & Astronautics courses
- Stanford: Introduction to Aerospace Engineering
- Coursera: Specializations in aerospace

---

## Quick Derivations

### Why \( v_{escape} = \sqrt{2} v_{orbital} \)?

**Orbital velocity** (kinetic = potential energy for circular orbit):
\[
\frac{1}{2}mv^2 = \frac{GMm}{2r} \quad \Rightarrow \quad v = \sqrt{\frac{GM}{r}}
\]

**Escape velocity** (kinetic ≥ potential energy to reach infinity):
\[
\frac{1}{2}mv^2 \geq \frac{GMm}{r} \quad \Rightarrow \quad v \geq \sqrt{\frac{2GM}{r}} = \sqrt{2} v_{orbital}
\]

### LEO Velocity (~7.7 km/s at 400 km)

\[
r = 6371 + 400 = 6771 \text{ km} = 6.771 \times 10^6 \text{ m}
\]

\[
v = \sqrt{\frac{3.986 \times 10^{14}}{6.771 \times 10^6}} = 7,669 \text{ m/s} \approx 7.7 \text{ km/s}
\]

---

**Remember:** Space is hard not because of altitude, but because of the enormous velocities required!

---

## References

- Geha, M. (2024). *Rocket Science for Everyone*. Yale University, Coursera. https://www.coursera.org/learn/rocket-science-for-everyone/

