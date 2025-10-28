# Rocket Fundamentals

**Source:** Yale University - Rocket Science for Everyone (Coursera)  
**Last Updated:** October 28, 2025

---

## Table of Contents
1. [Why Rockets?](#why-rockets)
2. [Newton's Laws Applied to Rockets](#newtons-laws-applied-to-rockets)
3. [Airplanes vs. Rockets](#airplanes-vs-rockets)
4. [Types of Chemical Rockets](#types-of-chemical-rockets)
5. [The Rocket Equation](#the-rocket-equation)
6. [Multistage Rockets](#multistage-rockets)
7. [Launch Locations](#launch-locations)
8. [Beyond Chemical Rockets](#beyond-chemical-rockets)

---

## Why Rockets?

Rockets are necessary for space travel because they:
1. **Carry their own oxidizer** - can operate in vacuum
2. **Generate high thrust** - can overcome Earth's gravity
3. **Achieve high velocities** - can reach orbital speeds (7-8 km/s)

**Key principle:** Rockets work by conservation of momentum - expelling mass in one direction creates thrust in the opposite direction.

---

## Newton's Laws Applied to Rockets

### First Law (Inertia)
> An object at rest stays at rest unless acted upon by a force.

- Rockets must overcome gravity and drag to reach orbit
- In space, satellites maintain velocity without thrust (no friction)

### Second Law (F = ma)
> Force equals mass times acceleration.

**Rocket thrust equation:**
\[
F = \frac{dp}{dt} = \frac{d(mv)}{dt}
\]

For constant exhaust velocity:
\[
F = \dot{m} \cdot v_e
\]

Where:
- \( F \) = thrust (Newtons)
- \( \dot{m} \) = mass flow rate (kg/s)
- \( v_e \) = exhaust velocity (m/s)

### Third Law (Action-Reaction)
> For every action, there is an equal and opposite reaction.

- **Action:** Rocket expels hot gas downward
- **Reaction:** Rocket experiences thrust upward
- This works in vacuum because the rocket pushes against its own propellant, not the air

---

## Airplanes vs. Rockets

| Feature                      | Airplane                   | Rocket                     |
|------------------------------|----------------------------|----------------------------|
| **Oxidizer source**          | Atmospheric oxygen         | Carried onboard            |
| **Operating environment**    | Atmosphere only            | Atmosphere + vacuum        |
| **Propulsion**               | Jet engine (air-breathing) | Rocket engine              |
| **Speed limit**              | ~Mach 3-5 (heating/drag)   | Limited by propellant only |
| **Altitude limit**           | ~20-30 km (air density)    | Unlimited                  |
| **Efficiency in atmosphere** | High (uses ambient air)    | Lower (carries oxidizer)   |
| **Efficiency in vacuum**     | Cannot operate             | Most efficient             |

**Key insight:** Airplanes are more efficient in atmosphere, but rockets are the only option for reaching orbital velocities and operating in space.

---

## Types of Chemical Rockets

### Solid Rocket Motors
**Configuration:** Fuel and oxidizer pre-mixed into solid propellant grain

**Advantages:**
- Simple design (fewer moving parts)
- High thrust-to-weight ratio
- Storable for long periods
- Reliable (mature technology)
- Lower cost

**Disadvantages:**
- **Cannot be throttled** (burn rate mostly fixed)
- **Cannot be shut down** once ignited
- Lower specific impulse than liquid rockets
- Grain cracks can cause catastrophic failure

**Examples:**
- Space Shuttle Solid Rocket Boosters (SRBs)
- Ariane 5 boosters
- Military ICBMs

**Common propellants:**
- Ammonium perchlorate (oxidizer) + aluminum powder (fuel) + HTPB rubber (binder)

### Liquid Rocket Engines
**Configuration:** Fuel and oxidizer stored separately, mixed in combustion chamber

**Advantages:**
- **Throttleable** (control propellant flow rates)
- **Can be shut down and restarted**
- Higher specific impulse
- Better performance control
- Reusable designs possible

**Disadvantages:**
- Complex plumbing and valves
- Turbopumps required for high performance
- Some propellants require cryogenic storage
- Higher development cost

**Examples:**
- SpaceX Merlin (RP-1/LOX)
- Space Shuttle Main Engines (LH2/LOX)
- Falcon 9, Atlas V, Saturn V

**Common propellant combinations:**

| Fuel                  | Oxidizer            | Isp (s)  | Notes                                 |
|-----------------------|---------------------|----------|---------------------------------------|
| RP-1 (kerosene)       | LOX (liquid oxygen) | ~300-360 | Dense, storable at reasonable temps   |
| LH2 (liquid hydrogen) | LOX                 | ~380-450 | Highest performance, very low density |
| Methane (CH4)         | LOX                 | ~330-380 | Good balance, Martian ISRU potential  |
| Hydrazine             | N2O4                | ~300-330 | Hypergolic (self-igniting), storable  |

### Hybrid Rockets
**Configuration:** Solid fuel + liquid/gas oxidizer

- Combines advantages of both types
- Safer than solid (oxidizer stored separately)
- Can be throttled via oxidizer flow
- Less common in operational systems

---

## The Rocket Equation

### Tsiolkovsky Rocket Equation

The fundamental equation relating velocity change to propellant mass:

\[
\Delta v = v_e \ln\left(\frac{m_0}{m_f}\right) = I_{sp} \cdot g_0 \cdot \ln\left(\frac{m_0}{m_f}\right)
\]

Where:
- \( \Delta v \) = change in velocity (m/s)
- \( v_e \) = effective exhaust velocity (m/s)
- \( m_0 \) = initial total mass (propellant + structure + payload)
- \( m_f \) = final mass (structure + payload after propellant burned)
- \( I_{sp} \) = specific impulse (seconds)
- \( g_0 \) = standard gravity = 9.81 m/s²

### Specific Impulse (\( I_{sp} \))

**Definition:** Measure of rocket engine efficiency
\[
I_{sp} = \frac{F}{\dot{m} \cdot g_0}
\]

**Physical meaning:** How many seconds one kilogram of propellant can produce one kilogram-force of thrust

**Typical values:**
- Solid rockets: 250-280 s
- Liquid RP-1/LOX: 300-360 s
- Liquid LH2/LOX: 380-450 s
- Ion thrusters: 3,000-10,000 s (but very low thrust)

### Mass Ratio

\[
MR = \frac{m_0}{m_f} = e^{\Delta v / v_e}
\]

**Example calculation for LEO:**
- Required \( \Delta v \approx 9,000 \) m/s
- Rocket with \( I_{sp} = 300 \) s: \( v_e = 300 \times 9.81 = 2,943 \) m/s
- Mass ratio: \( MR = e^{9000/2943} = e^{3.06} \approx 21 \)

**Interpretation:** Need 21 kg initial mass for every 1 kg delivered to orbit (20 kg of propellant per 1 kg payload+structure)

### The Tyranny of the Rocket Equation

**Problem:** Exponential relationship means small increases in \( \Delta v \) require huge increases in propellant

**Implications:**
- Very large propellant fractions needed (typically 85-95%)
- Structural mass becomes critical
- Payload fraction is small (1-5% of total mass)
- Getting to orbit is hard; going to Moon/Mars is much harder

---

## Multistage Rockets

### Why Stage?

**Problem:** Carrying empty tanks and engines reduces efficiency

**Solution:** Drop unnecessary mass as propellant is consumed

### Staging Strategies

#### Serial Staging (Tandem)
- Stages stacked vertically
- Lower stage drops away when exhausted
- Most common configuration
- Examples: Falcon 9, Saturn V, Ariane 5

#### Parallel Staging (Strap-On Boosters)
- Multiple engines fire simultaneously
- Boosters drop when exhausted, core continues
- Examples: Space Shuttle, Atlas V, Ariane 5 (hybrid)

### Staging Mathematics

For a two-stage rocket:
\[
\Delta v_{total} = \Delta v_1 + \Delta v_2 = v_{e1} \ln(MR_1) + v_{e2} \ln(MR_2)
\]

**Key insight:** Can achieve much higher total \( \Delta v \) than single stage

**Example:**
- Single-stage to orbit (SSTO): Requires \( MR \approx 20-25 \) → structurally very difficult
- Two-stage: Each stage \( MR \approx 4-5 \) → much more achievable

### Optimal Staging

The total \( \Delta v \) is maximized when stages have approximately equal \( \Delta v \) contributions (for identical \( I_{sp} \))

**Trade-offs:**
- More stages = better performance but more complexity
- Most launchers use 2-3 stages
- Diminishing returns beyond 3-4 stages

---

## Launch Locations

### Latitude Effects

**Eastward launch bonus (prograde):**
\[
v_{bonus} = v_{Earth} \cos(\text{latitude})
\]

Where \( v_{Earth} \approx 465 \) m/s at equator

**Locations:**
- **Equatorial:** Maximum rotational velocity bonus
  - Kennedy Space Center (KSC), Florida: 28.5°N (~410 m/s bonus)
  - Guiana Space Centre, French Guiana: 5°N (~463 m/s bonus)
  - Sea Launch (ocean platform): 0° (equator)
  
- **Higher latitudes:** Less bonus but better for polar orbits
  - Vandenberg Space Force Base, California: 34.7°N
  - Baikonur, Kazakhstan: 45.6°N
  - Plesetsk, Russia: 62.8°N

### Safety Considerations

Launch sites need:
1. Downrange safety zones (over ocean or unpopulated areas)
2. Orbital plane accessibility
3. Weather considerations
4. Political/territorial factors

**Inclination constraint:**
- Minimum orbital inclination ≈ launch site latitude
- Can launch to higher inclination (costs \( \Delta v \))
- Cannot directly launch to lower inclination

---

## Beyond Chemical Rockets

### Nuclear Thermal Rockets
- Heat propellant (typically hydrogen) with nuclear reactor
- Higher \( I_{sp} \) than chemical (~800-1000 s)
- Moderate thrust
- Challenges: radiation, politics, development cost

### Electric/Ion Propulsion
- Accelerate ions using electromagnetic fields
- Very high \( I_{sp} \) (3,000-10,000 s)
- Very low thrust (millinewtons to Newtons)
- Requires large power source (solar or nuclear)
- Applications: satellite station-keeping, deep space missions
- Examples: Dawn mission, Starlink satellites

### Solar Sails
- Use photon pressure from sunlight
- Infinite \( I_{sp} \) (no propellant)
- Very low acceleration
- Limited by sun distance and sail size

### Theoretical Concepts
- Fusion rockets
- Antimatter rockets
- Beam-powered propulsion
- Space elevators/tethers

---

## Key Takeaways

1. **Rockets work via Newton's Third Law** - momentum conservation
2. **The rocket equation is exponential** - small \( \Delta v \) increases require large propellant mass
3. **Staging is essential** - dropping dead weight improves performance
4. **Chemical rockets dominate launch** - highest thrust-to-weight ratio
5. **Electric propulsion for deep space** - high efficiency, low thrust
6. **Launch location matters** - equatorial launches get rotational velocity bonus

---

## Important Formulas Summary

| Quantity         | Formula                           | Units |
|------------------|-----------------------------------|-------|
| Thrust           | \( F = \dot{m} v_e \)             | N     |
| Specific Impulse | \( I_{sp} = v_e / g_0 \)          | s     |
| Rocket Equation  | \( \Delta v = v_e \ln(m_0/m_f) \) | m/s   |
| Orbital Velocity | \( v = \sqrt{GM/r} \)             | m/s   |
| Escape Velocity  | \( v_{esc} = \sqrt{2GM/r} \)      | m/s   |

---

## References

- Geha, M. (2024). *Rocket Science for Everyone*. Yale University, Coursera. https://www.coursera.org/learn/rocket-science-for-everyone/
- Sutton, G. P., & Biblarz, O. (2016). *Rocket Propulsion Elements*. Wiley.
- Turner, M. J. L. (2009). *Rocket and Spacecraft Propulsion*. Springer.

---

## Next Steps

- [ ] Derive rocket equation from first principles
- [ ] Calculate staging optimization for multi-stage rockets
- [ ] Study propellant chemistry and combustion
- [ ] Explore engine cycles (gas generator, staged combustion, expander)
- [ ] Investigate thrust vector control methods

