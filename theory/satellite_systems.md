# Satellite Systems

**Source:** Yale University - Rocket Science for Everyone (Coursera)  
**Last Updated:** October 28, 2025

---

## Table of Contents
1. [Satellite Components Overview](#satellite-components-overview)
2. [Electrical Power Systems](#electrical-power-systems)
3. [Communication Systems](#communication-systems)
4. [Imaging Systems](#imaging-systems)
5. [Satellite Subsystems](#satellite-subsystems)
6. [Mission Examples](#mission-examples)

---

## Satellite Components Overview

A satellite consists of two main parts:

### 1. Bus (Spacecraft Platform)
The infrastructure that keeps the satellite operational:
- Power system
- Propulsion
- Thermal control
- Attitude determination and control
- Communication
- Structure

### 2. Payload
The mission-specific equipment that performs the satellite's primary function:
- Scientific instruments
- Communication transponders
- Imaging cameras
- GPS transmitters
- etc.

**Design philosophy:** Separate bus from payload for modularity and reusability

---

## Electrical Power Systems

### Solar Panels

**How they work:**
- Photovoltaic cells convert sunlight → electricity
- Silicon semiconductor creates voltage when photons strike it
- Typical efficiency: 28-32%

**Configuration:**
- **Body-mounted panels:** Fixed to satellite body
  - Simpler, lighter
  - Used for small satellites or those with favorable orientations
  
- **Deployable arrays:** Unfold after launch
  - Higher power capacity
  - Can track the sun
  - Used on most large satellites

**Sun-tracking:**
- Arrays rotate to maintain perpendicular angle to sunlight
- Maximizes power generation
- Requires motors/gimbals

### Power Generation by Orbit

**LEO satellites:**
- Orbit period: ~90 minutes
- Sunlight: ~60 minutes
- Eclipse: ~30 minutes in Earth's shadow
- Must store energy for eclipse periods

**GEO satellites:**
- Constant sunlight most of year
- Brief eclipse periods during equinoxes (~45 minutes max)
- Easier power management

### Energy Storage

**Batteries:**
- Lithium-ion most common (replacing older NiH2)
- Store energy during sunlit portions
- Discharge during eclipse
- Sized for depth-of-discharge (DoD) and cycle life

**Power budget:**
\[
P_{solar} \times t_{sun} \geq P_{load} \times t_{orbit} + P_{losses}
\]

### Typical Power Levels

| Satellite Type       | Power Range |
|----------------------|-------------|
| CubeSats (1U-3U)     | 2-10 W      |
| Small LEO satellites | 50-200 W    |
| Large LEO (ISS)      | ~120 kW     |
| GEO communications   | 5-20 kW     |

---

## Communication Systems

### Radio Frequency (RF) Basics

**Electromagnetic spectrum usage:**
- VHF/UHF: 30 MHz - 3 GHz (telemetry, command)
- L-band: 1-2 GHz (GPS, mobile communications)
- S-band: 2-4 GHz (telemetry, Earth observation data)
- X-band: 8-12 GHz (high-rate science data, radar)
- Ku-band: 12-18 GHz (satellite TV, broadband)
- Ka-band: 26-40 GHz (high-rate communications)

**Higher frequency trade-offs:**
- **Advantages:** More bandwidth, smaller antennas, better data rates
- **Disadvantages:** More atmospheric attenuation, rain fade, tighter pointing requirements

### Satellite Communication Components

**Onboard:**
1. **Antenna:** Transmit/receive signals
   - Omnidirectional: simple, low gain, used for telemetry
   - Directional (dishes/patches): high gain, point at ground stations
   
2. **Transponder:** Receives uplink signal, amplifies, frequency-shifts, transmits downlink
   
3. **Transmitter:** Power amplifier (typically traveling wave tube amplifier - TWTA)

**Ground station:**
- Large parabolic dish antennas (tracking satellites)
- Transmitter for uplink commands
- Receiver for downlink data
- Tracking system to follow satellite

### Link Budget

The power budget for a communication link:

\[
P_{received} = P_{transmitted} + G_{tx} - L_{path} - L_{atmospheric} + G_{rx}
\]

Where (in dB):
- \( P_{transmitted} \) = transmitter power
- \( G_{tx} \) = transmit antenna gain
- \( L_{path} \) = free-space path loss (increases with distance and frequency)
- \( L_{atmospheric} \) = atmospheric attenuation
- \( G_{rx} \) = receive antenna gain

**Free-space path loss:**
\[
L = 20 \log_{10}(d) + 20 \log_{10}(f) + 32.45 \text{ dB}
\]
(where \( d \) is distance in km, \( f \) is frequency in MHz)

### Communication Challenges by Orbit

**LEO:**
- Short contact windows (~10 minutes per pass)
- Requires multiple ground stations or relay satellites
- Doppler shift due to high relative velocity
- Lower path loss (closer to Earth)

**GEO:**
- Continuous contact (no handoffs)
- High latency (~240 ms round-trip)
- Higher path loss (35,786 km altitude)
- One satellite covers ~1/3 of Earth

**MEO (GPS):**
- 4+ satellites always visible
- One-way communication (broadcast)
- Moderate path loss

---

## Imaging Systems

### Types of Imaging

#### 1. Optical/Visual Imaging
- Uses visible light spectrum
- Similar to digital cameras on Earth
- **Resolution:** Limited by diffraction and detector size
- **Applications:** Earth observation, reconnaissance, mapping

**Diffraction limit (Rayleigh criterion):**
\[
\theta = 1.22 \frac{\lambda}{D}
\]

Where:
- \( \theta \) = angular resolution (radians)
- \( \lambda \) = wavelength of light
- \( D \) = aperture diameter

**Ground resolution:**
\[
\text{GSD} = \theta \times h = 1.22 \frac{\lambda h}{D}
\]
(GSD = ground sample distance, \( h \) = altitude)

**Example:** 
- Satellite at 500 km altitude
- Telescope aperture: 0.5 m
- Visible light: \( \lambda = 550 \) nm
- Resolution: \( \theta = 1.34 \times 10^{-6} \) rad
- GSD ≈ 0.67 m

#### 2. Infrared Imaging
- Detects heat/thermal radiation
- Can operate day and night
- Useful for:
  - Weather monitoring
  - Fire detection
  - Sea surface temperature
  - Military applications

#### 3. Radar Imaging (SAR - Synthetic Aperture Radar)
- Active system (provides its own illumination)
- Works through clouds, at night
- Measures surface roughness and texture
- Applications:
  - Topography mapping
  - Ice monitoring
  - Ocean surface observation
  - Change detection

**Synthetic aperture concept:**
- Uses satellite motion to synthesize large antenna
- Achieves high resolution from small physical antenna

#### 4. Multispectral/Hyperspectral
- Captures many wavelength bands simultaneously
- Can identify materials by spectral signature
- Applications:
  - Agriculture (crop health)
  - Geology (mineral identification)
  - Environmental monitoring

### Resolution Trade-offs

Better resolution requires:
- Larger aperture (heavier, more expensive)
- Lower orbit (more drag, shorter lifetime)
- Slower revisit time (narrower swath)

**Types of resolution:**
1. **Spatial:** Ground sample distance (e.g., 30 cm/pixel)
2. **Spectral:** Number and width of wavelength bands
3. **Temporal:** How often same location is imaged (revisit time)
4. **Radiometric:** Sensitivity to brightness differences (bit depth)

### Notable Earth Observation Satellites

| Satellite   | Resolution | Orbit           | Purpose                  |
|-------------|------------|-----------------|--------------------------|
| Landsat 8-9 | 15-30 m    | LEO (705 km)    | Land monitoring          |
| Sentinel-2  | 10 m       | LEO (786 km)    | Environmental monitoring |
| WorldView-3 | 0.31 m     | LEO (617 km)    | Commercial imaging       |
| GOES        | ~1 km      | GEO (35,786 km) | Weather                  |

---

## Satellite Subsystems

### 1. Attitude Determination and Control System (ADCS)

**Sensors (determine orientation):**
- Sun sensors
- Star trackers (most accurate)
- Magnetometers
- GPS receivers
- Gyroscopes/IMUs

**Actuators (change orientation):**
- **Reaction wheels:** Spin up/down to transfer angular momentum
- **Magnetorquers:** Interact with Earth's magnetic field
- **Thrusters:** For rapid reorientation or momentum desaturation
- **Gravity gradient stabilization:** Passive, uses tidal forces

**Pointing accuracy requirements:**
- Communication satellites: ±0.1° (keep antenna pointed at Earth)
- Imaging satellites: ±0.01° or better
- Science missions: arc-seconds to milli-arc-seconds

### 2. Thermal Control

Maintain acceptable temperature range for electronics and instruments

**Heat sources:**
- Solar radiation
- Albedo (sunlight reflected from Earth)
- Earth's infrared emission
- Internal electronics

**Cooling methods:**
- Radiators (emit heat as infrared)
- Multi-layer insulation (MLI blankets)
- Heaters for cold periods
- Louvers (variable radiator area)
- Heat pipes

**Temperature extremes:**
- Sunlit side: +120°C
- Eclipse/shadow side: -150°C
- Must maintain electronics at -20°C to +50°C typically

### 3. Propulsion

**Purpose:**
- Orbit insertion
- Station-keeping (counteract perturbations)
- Orbit adjustments
- Attitude control
- End-of-life deorbit

**Types:**
- **Chemical:** High thrust, limited Isp, used for orbit insertion
  - Monopropellant (hydrazine): Isp ~230 s
  - Bipropellant: Isp ~300-320 s
  
- **Electric:** Low thrust, high Isp, used for station-keeping
  - Hall effect thrusters
  - Ion engines
  - Isp ~1,500-3,000 s

### 4. Command and Data Handling (C&DH)

- Onboard computer
- Data storage
- Command execution
- Housekeeping telemetry
- Fault protection and autonomy

**Data rates:**
- Uplink (commands): Few kbps
- Downlink (telemetry): kbps to Mbps
- Science data: Mbps to Gbps (high-resolution imaging)

---

## Mission Examples

### 1. Sputnik (1957)
- **First artificial satellite**
- Mass: 83.6 kg
- Orbit: LEO, 215 × 939 km
- Payload: Radio transmitter (beep signals)
- Duration: 3 months
- **Significance:** Started space age, proved orbital mechanics

### 2. SWOT (Surface Water and Ocean Topography)
- **Launch:** 2022
- **Mission:** Measure Earth's surface water
- **Orbit:** Sun-synchronous LEO (891 km)
- **Payload:** Ka-band Radar Interferometer (KaRIn)
- **Applications:**
  - Ocean circulation and sea level
  - Freshwater storage in lakes and reservoirs
  - River discharge monitoring
  - Climate change impacts

### 3. UVEX (Ultraviolet Explorer)
- **Planned mission** (Future)
- **Purpose:** UV astronomy
- **Orbit:** LEO
- **Science goals:**
  - Survey UV sky
  - Study stellar explosions
  - Characterize massive stars
  - Time-domain astronomy

---

## Key Takeaways

1. **Satellites are systems of systems** - must balance power, mass, pointing, thermal, communications
2. **Solar panels are primary power source** - sized for worst-case eclipse scenario
3. **Communication links are power-limited** - distance, frequency, and antenna size drive design
4. **Imaging resolution trades with coverage and revisit time**
5. **Subsystems must work together** - interdisciplinary engineering challenge
6. **Mission design drives satellite design** - LEO vs GEO vs MEO determines architecture

---

## Design Considerations

**Key questions for any satellite mission:**
1. What orbit best serves the mission? (LEO/MEO/GEO, inclination, altitude)
2. What power is needed? (Size solar arrays and batteries)
3. What data rates are required? (Size communication system)
4. What pointing accuracy is needed? (ADCS complexity)
5. How much propellant for station-keeping? (Lifetime vs mass)
6. What thermal environment? (Active/passive cooling)
7. Launch vehicle constraints? (Mass, volume, fairing size)

---

## References

- Geha, M. (2024). *Rocket Science for Everyone*. Yale University, Coursera. https://www.coursera.org/learn/rocket-science-for-everyone/
- Wertz, J. R., & Larson, W. J. (Eds.). (1999). *Space Mission Analysis and Design*. Microcosm Press.
- Fortescue, P., Swinerd, G., & Stark, J. (2011). *Spacecraft Systems Engineering*. Wiley.

---

## Next Steps

- [ ] Study specific subsystem designs in detail (ADCS, thermal, etc.)
- [ ] Explore mission design tools (STK, GMAT)
- [ ] Calculate link budgets for real missions
- [ ] Investigate CubeSat standards and commercial off-the-shelf components
- [ ] Review recent satellite missions and technologies

