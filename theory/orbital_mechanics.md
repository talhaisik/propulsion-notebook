# Orbital Mechanics

**Source:** Yale University - Rocket Science for Everyone (Coursera)  
**Last Updated:** October 28, 2025

---

## Table of Contents
1. [What is an Orbit?](#what-is-an-orbit)
2. [Where Does Space Start?](#where-does-space-start)
3. [Kepler's Laws](#keplers-laws)
4. [Orbital Regions](#orbital-regions)
5. [Special Orbits](#special-orbits)
6. [Getting Into Orbit](#getting-into-orbit)

---

## What is an Orbit?

An orbit is a curved path of an object around a point in space. For satellites around Earth, this is a continuous free-fall where the satellite's forward velocity prevents it from crashing into Earth.

**Key Concept:** Orbiting is essentially "falling sideways" - the satellite falls toward Earth but has enough horizontal velocity to keep missing it.

---

## Where Does Space Start?

### Karman Line
- **Altitude:** 100 km (62 miles) above sea level
- **Significance:** Internationally recognized boundary where Earth's atmosphere becomes too thin for conventional aircraft to maintain flight
- Below this line: aerodynamic lift dominates
- Above this line: orbital mechanics dominates

---

## Kepler's Laws

Johannes Kepler's three laws describe planetary and satellite motion:

### First Law (Law of Ellipses)
> All orbits are ellipses with the central body at one focus.

- **Circle:** Special case where both foci are at the same point
- **Ellipse parameters:**
  - Semi-major axis \( a \): half the longest diameter
  - Semi-minor axis \( b \): half the shortest diameter
  - Eccentricity \( e \): measure of how "stretched" the ellipse is
    - \( e = 0 \): perfect circle
    - \( 0 < e < 1 \): ellipse
    - \( e = 1 \): parabola (escape trajectory)

### Second Law (Law of Equal Areas)
> A line joining a planet/satellite to the Sun/Earth sweeps out equal areas in equal times.

**Implications:**
- Satellites move **faster** when closer to Earth (at perigee)
- Satellites move **slower** when farther from Earth (at apogee)

### Third Law (Law of Periods)
> The square of the orbital period is proportional to the cube of the semi-major axis.

\[
T^2 = \frac{4\pi^2}{GM} a^3
\]

Where:
- \( T \) = orbital period (seconds)
- \( G \) = gravitational constant = \( 6.674 \times 10^{-11} \, \text{m}^3\text{kg}^{-1}\text{s}^{-2} \)
- \( M \) = mass of Earth = \( 5.972 \times 10^{24} \, \text{kg} \)
- \( a \) = semi-major axis (meters)

**Simplified for circular Earth orbits:**
\[
T = 2\pi \sqrt{\frac{r^3}{\mu}}
\]
where \( r \) is orbital radius and \( \mu = GM = 3.986 \times 10^{14} \, \text{m}^3/\text{s}^2 \)

---

## Orbital Regions

### Low Earth Orbit (LEO)
- **Altitude:** 160 km - 2,000 km above Earth's surface
- **Orbital period:** ~90-120 minutes
- **Velocity:** ~7-8 km/s
- **Examples:**
  - International Space Station (ISS): ~400 km
  - Starlink satellites: ~550 km
  - Hubble Space Telescope: ~540 km
- **Advantages:**
  - Lower cost to reach
  - Better resolution for Earth observation
  - Lower communication latency
- **Challenges:**
  - Atmospheric drag (requires periodic boosts)
  - Limited coverage time over any location
  - Radiation exposure (passes through Van Allen belts)

### Medium Earth Orbit (MEO)
- **Altitude:** 2,000 km - 35,786 km
- **Orbital period:** 2-12 hours
- **Examples:**
  - GPS constellation: ~20,200 km altitude, 12-hour period
  - Galileo (European GPS): ~23,222 km
- **GPS Configuration:**
  - 24+ satellites in 6 orbital planes
  - 4 satellites per plane
  - At least 4 satellites visible from any point on Earth
  - Provides positioning through time-of-flight measurements

### Geosynchronous Earth Orbit (GEO)
- **Altitude:** 35,786 km (exactly)
- **Orbital period:** 24 hours (matches Earth's rotation)
- **Velocity:** ~3 km/s
- **Geostationary orbit:** Special case of GEO
  - Equatorial orbit (\( i = 0° \))
  - Appears stationary from Earth's surface
- **Examples:**
  - Communication satellites (DirecTV, satellite internet)
  - Weather satellites (GOES)
  - Early warning systems
- **Advantages:**
  - Constant coverage of ~1/3 of Earth
  - Fixed ground antennas (no tracking needed)
- **Challenges:**
  - High launch cost (most fuel required)
  - High latency (~240 ms round-trip)
  - Limited "slots" available
  - Signal strength issues at high latitudes

---

## Special Orbits

### Polar Orbit
- **Inclination:** ~90° (passes over both poles)
- **Coverage:** Eventually covers entire Earth surface as planet rotates beneath
- **Applications:**
  - Earth observation
  - Reconnaissance
  - Weather monitoring
  - Scientific missions

### Sun-Synchronous Orbit (SSO)
- **Type:** Special polar orbit that precesses with Earth's orbit around the Sun
- **Inclination:** Typically 96-98° (retrograde)
- **Key Feature:** Satellite passes over the same point on Earth at the same local solar time
- **Applications:**
  - Earth imaging with consistent lighting
  - Climate monitoring
  - Agricultural surveys
- **Typical altitude:** 600-800 km

### Cislunar Space
- **Definition:** Region between Earth and Moon
- **Distance:** ~384,400 km to Moon
- **Special points:** Lagrange points (L1-L5)
  - Gravitationally stable or semi-stable locations
  - L2 used for space telescopes (James Webb Space Telescope)

---

## Getting Into Orbit

### Velocity Requirements

**Orbital velocity** (circular orbit):
\[
v = \sqrt{\frac{GM}{r}}
\]

For LEO at ~400 km altitude:
\[
v \approx 7.7 \, \text{km/s} \approx 17,200 \, \text{mph}
\]

**Escape velocity** (leaving Earth's gravity):
\[
v_{escape} = \sqrt{\frac{2GM}{r}} = \sqrt{2} \cdot v_{orbital}
\]

At Earth's surface:
\[
v_{escape} \approx 11.2 \, \text{km/s} \approx 25,000 \, \text{mph}
\]

### Delta-V (\( \Delta v \))
- **Definition:** Change in velocity required for a maneuver
- Total \( \Delta v \) budget determines mission feasibility
- Example LEO insertion from surface: ~9-10 km/s
  - Orbital velocity: 7.7 km/s
  - Additional for gravity losses: ~1.5 km/s
  - Additional for drag losses: ~0.3-0.5 km/s

### Launch Process
1. **Vertical ascent** - Clear launch tower and dense atmosphere
2. **Gravity turn** - Gradually pitch over toward horizontal
3. **Atmospheric exit** - Above 100 km (Karman line)
4. **Orbital insertion** - Achieve required horizontal velocity
5. **Circularization** (if needed) - Adjust orbit shape at apogee/perigee

---

## Key Takeaways

1. **Orbital mechanics is governed by gravity and Newton's/Kepler's laws**
2. **Different orbital regions serve different purposes:**
   - LEO: Earth observation, crewed missions
   - MEO: Navigation (GPS)
   - GEO: Communications, weather
3. **Getting to orbit requires ~7-8 km/s horizontal velocity, not just altitude**
4. **Orbital design is about trade-offs:** cost vs. coverage vs. latency vs. resolution

---

## References

- Geha, M. (2024). *Rocket Science for Everyone*. Yale University, Coursera. https://www.coursera.org/learn/rocket-science-for-everyone/
- Curtis, H. D. (2014). *Orbital Mechanics for Engineering Students*. Butterworth-Heinemann.

---

## Next Steps

- [ ] Study orbital transfer maneuvers (Hohmann transfers)
- [ ] Calculate specific \( \Delta v \) budgets for missions
- [ ] Explore perturbations (J2, atmospheric drag, solar pressure)
- [ ] Investigate station-keeping requirements

