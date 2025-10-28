# Personal Propulsion & Flight Systems Roadmap

## Purpose
This project is a long-term, self-directed path toward real competence in:
1. Liquid rocket propulsion, turbomachinery, high-temperature materials, regenerative cooling, and ascent guidance (the "Merlin-class engine / orbital vehicle" world).
2. Long-endurance UAV propulsion and flight systems, including airframes, powerplants, avionics, autonomy, and mission energy economics.

There is no schedule pressure. The goal is depth, safety, and credibility.

I am not trying to illegally build or test a weapon. I am building knowledge, simulation capability, and safe UAV-scale hardware that I can legally fly and measure.

---

## Repository Layout

- `/theory/`
  - Reading notes, derivations, summaries of lectures and textbooks.
  - Propellant chemistry notes, turbopump notes, cooling/materials notes.
  - Mission analysis docs for orbit and for UAV endurance.

- `/sims/`
  - C++ / Python code for:
    - Rocket engine performance estimation (thrust, Isp, mixture ratio).
    - Feed system dynamic models.
    - 6-DOF GNC and ascent-to-orbit simulation.
    - UAV endurance model (range, loiter time).
    - CFD setups and post-processing scripts.
  - Each sim gets its own subfolder with a README, assumptions, and plots.

- `/uav/`
  - Airframe work (wings, spars, composite layups, structural testing).
  - Avionics, logging, flight control, perception experiments.
  - Bench tests and eventually flight tests of propulsion systems.
  - `logs/` subfolder with real telemetry and bench data.

- `/safety_and_limits/`
  - `LEGAL_AND_PERMISSIONS.md` – airspace rules, SHGM notes, storage/handling rules.
  - `RISK_LOG.md` – running list of incidents / near-incidents / lessons.
  - `MATERIALS_NOTES.md` – handling notes for batteries, fuels, resins, pressure vessels.
  - `TEST_PLAN_TEMPLATE.md`
  - `TEST_REPORT_TEMPLATE.md`

This repo is not just code. It’s engineering process.

---

## ARC A — High-Energy Propulsion & GNC (Simulation-First)

### Goal
Become fluent in liquid rocket engines (gas-generator / staged combustion), turbopumps, regenerative cooling, mission Δv budgeting, ascent guidance, and control — at a level where I can write my own simulators and defend my assumptions. I do not need to physically fire anything to reach this level.

### A1. Propulsion Thermodynamics & Combustion Chemistry
**Learn**
- Chamber pressure ↔ mass flow ↔ throat sizing.
- Specific impulse (Isp), characteristic velocity (c*), mixture ratio.
- Basic propellant chemistry (LOX/RP-1, LOX/LH2): flame temperature, coking, storability.

**Deliverables**
- `/sims/rocket_perf/`:
  - Code that, given chamber pressure, mixture ratio, and nozzle expansion ratio, estimates thrust and Isp using ideal compressible flow.
  - Plots: thrust vs chamber pressure, Isp vs mixture ratio.
- `/theory/propellants.md`:
  - Summary of common propellant pairs.
  - Handling concerns and materials compatibility (why LOX eats seals, why RP-1 can coke).
  - I am documenting chemistry, not synthesizing propellants.

Milestone: I can explain, in my own words, why higher chamber pressure helps performance and why it explodes engineering difficulty.

---

### A2. Materials, Cooling, and Thermal Limits
**Learn**
- Regenerative cooling: pumping cold fuel around the chamber throat and nozzle jacket.
- High-temp alloys, copper liners, ablatives.
- Thermal stress, fatigue, erosion, burnthrough.

**Deliverables**
- `/theory/materials_and_cooling.md`:
  - How regen cooling works, what materials are used, why wall thickness is such a big deal.
  - Order-of-magnitude heat flux numbers at the throat.
- `/sims/chamber_cooling_sanitycheck/`:
  - Back-of-envelope calc: assume a chamber wall section with coolant flow. Estimate whether it survives N seconds before exceeding allowable temperature.

Milestone: I can defend why cooling often drives engine architecture, not the other way around.

---

### A3. Feed Systems, Valves, and Turbopumps (No Hot Fire)
**Learn**
- Gas generator vs staged combustion vs electric pump-fed cycles.
- Turbopump concepts: head rise, cavitation, NPSH.
- Valve sequencing and transient pressure spikes during startup/shutdown.

**Deliverables**
- `/sims/feed_system_dyn/`:
  - Time-step simulation of tank → valve → line volume → chamber inlet pressure using an inert working fluid model.
  - Abort logic: "if inlet pressure < X for Y ms, shut down."
- `/theory/turbopump_notes.md`:
  - Why cavitation kills you.
  - Why suction conditions drive tank pressurization requirements.

Milestone: I can sketch a startup timeline for a gas-generator LOX/RP-1 engine and call out failure modes in each 100 ms segment.

---

### A4. GNC (Guidance, Navigation, and Control)
**Learn**
- 6-DOF rigid body dynamics for a rocket stage.
- PID / basic control for thrust vectoring.
- State estimation (IMU + possibly GPS later → Kalman filter intuition).
- Gravity turn and pitch program.

**Deliverables**
- `/sims/ascent_6dof/`:
  - C++ sim of a single stage with thrust vector control.
  - Simple atmosphere model + gravity.
  - Controller tries to follow a commanded pitch vs time profile.
  - Plots: attitude error over time, velocity vs time, altitude vs time.
- `/theory/gnc_overview.md`:
  - What sensors I assume exist.
  - What state I estimate.
  - How thrust vector control closes the loop.

Milestone: I can answer “How does the vehicle know where it's pointing, and how does it correct if it's off?”

---

### A5. Staging and Orbital Mission Modeling
**Learn**
- Δv budgeting including gravity + drag losses.
- Mass fraction reality, staging logic, payload fraction.
- GNC handoff between stages.

**Deliverables**
- `/sims/ascent_to_orbit/`:
  - Two-stage ascent sim:
    - Stage 1 burn, MECO, separation.
    - Stage 2 ignition, orbital insertion.
  - Outputs: altitude vs time, velocity vs time, remaining mass vs time.
- `/theory/orbital_stack.md`:
  - “My notional 2-stage LOX/RP-1 launcher.”
  - Chamber pressure assumptions, mixture ratios, T/W ratios, structural mass fractions.
  - Honest statement: “Can/Can’t reach LEO with these numbers.”

Milestone: I have a defensible “paper rocket” to orbit with plots and numbers, not vibes.

---

## ARC B — Long-Endurance UAV Propulsion & Flight Systems (Hands-On)

### Goal
Design, build, and test legal, safe UAV-scale airframes and propulsion systems optimized for multi-hour endurance and persistent sensing. Capture real flight and bench data, and iterate like an engineer (test plan → test → test report → next change).

This is the arc that actually touches hardware.

---

### B1. Mission Energy Budget
**Learn**
- Propeller efficiency and advance ratio.
- Motor efficiency curves and ESC losses.
- Airframe drag vs cruise speed.
- Battery specific energy (Wh/kg), fuel energy density (MJ/kg), hybrid-electric concepts.

**Deliverables**
- `/sims/uav_endurance_model/`:
  - Code that, given:
    - vehicle mass
    - estimated drag at cruise
    - propulsive efficiency
    - stored energy (battery or fuel+generator)
    - cruise speed and altitude
  - returns: expected loiter time and range.
- `/uav/energy_sources.md`:
  - Notes on Li-ion / LiPo battery chemistry (C-rates, thermal runaway risk, safe handling).
  - Notes on small gasoline/kerosene use as range extenders.
  - Safety handling and storage practices.

Milestone: I can say “With this airframe and this powerplant, realistic endurance is X hours at Y m/s,” and show the math.

---

### B2. Airframe & Materials
**Learn**
- Composite layups: fiberglass/epoxy skins, carbon spars.
- Wing loading, bending, torsion.
- Mounting payloads (camera, comms) without shaking them to death.
- Field-repair philosophy (patchability matters more than perfection).

**Deliverables**
- `/uav/airframe_v1/`:
  - CAD or sketches of a wing / fuselage concept.
  - Bill of materials (foam core, carbon tube, epoxy system).
- Basic static load test:
  - Hang weight from a prototype spar or wing section.
  - Record load vs deflection.
  - Store data + photo + failure mode description in `/uav/tests/airframe_load_test_YYYYMMDD/TEST_REPORT.md`, using the template from `/safety_and_limits/`.

Milestone: I have physically characterized something I built, not just eyeballed it.

---

### B3. Avionics, Telemetry, and Perception
**Learn**
- IMU + barometer + GPS logging.
- Basic flight controller loops: stabilize attitude, then hold velocity/altitude.
- Telemetry recording for post-flight plots.
- Camera stabilization / simple onboard CV (e.g. horizon detection, ground target tracking).

**Deliverables**
- `/uav/avionics_logger/`:
  - A simple microcontroller or SBC setup that logs:
    - pitch/roll/yaw (or accel/gyro at least),
    - GPS (if available),
    - battery voltage/current draw.
  - A script/notebook to plot that data after flight.
- `/uav/logs/flight_0001/`:
  - Raw log.
  - `TEST_REPORT.md` with:
    - Objective of flight.
    - Configuration.
    - Results (plots).
    - Issues observed.
    - Next changes.

Milestone: I can show someone a flight profile (altitude vs time, current draw vs time) from my own platform.

---

### B4. Propulsion Bench Testing
**Learn**
- Motor/prop matching.
- ESC heating and wiring limits.
- Thrust stand basics (even a DIY load cell rig).
- Hybrid-electric architecture concept: small combustion engine → generator → battery buffer → prop motor.

**Deliverables**
- `/uav/propulsion_bench_001/`:
  - Ground test of a propulsion pod:
    - Measure thrust, RPM, current draw, and temperatures at several throttle points.
  - Use `TEST_PLAN_TEMPLATE.md` before running and `TEST_REPORT_TEMPLATE.md` after.
- Update `/sims/uav_endurance_model/` with real measured efficiency instead of guessed efficiency.

Milestone: I can say “At 60% throttle we draw N amps, produce M newtons thrust, and motor temp stabilizes at T°C,” with plots to prove it.

---

### B5. Iterative Long-Endurance Platform
**Goal**
- Integrate airframe + avionics + propulsion pod.
- Do progressively longer, safe flights in legal airspace.
- Treat every flight like an engineering test.

**Deliverables**
- `/uav/platform_v1/`:
  - Current full aircraft configuration (airframe, powerplant, mass breakdown, avionics stack).
  - Latest endurance estimate vs actual measured endurance.
  - Known problems and next experiments.

Milestone: Achieve a flight with honest multi-hour loiter capability, or a clear path (with data) toward that goal.

This is the “this is real” moment.

---

## Safety, Legal, and Boundaries

All work observes:
- Airspace and test permissions (tracked in `/safety_and_limits/LEGAL_AND_PERMISSIONS.md`).
- Chemical/material handling discipline for batteries, fuels, resins, pressure systems.
- No synthesis, storage, or testing of energetic rocket propellants. Studying propellants on paper is allowed. Mixing or firing without licensed facilities and formal approval is not.
- No design, testing, or tuning of systems whose primary intended purpose is as a weapon. The UAV work is framed and executed as persistent sensing / endurance / ISR / comms relay / SAR support.

Every physical test (bench or flight) produces:
- A `TEST_PLAN.md` checked in _before_ the test.
- A `TEST_REPORT.md` checked in _after_ the test.
- An update in `RISK_LOG.md` if anything even slightly sketchy happened (overheating, structural crack, unstable control, near-loss of vehicle, etc.).

This is not bureaucracy. This is what makes this work defensible and repeatable.

---

## Long-Term Success Criteria (2–3 Year Horizon)

By following this roadmap, success looks like:

1. **Propulsion Literacy**
   - I can walk through how a gas-generator-cycle LOX/RP-1 engine works, including turbopumps, cooling, sequencing, and structural/thermal limits.
   - I have my own engine/thrust performance code and can generate thrust/Isp curves I believe.

2. **GNC Competence**
   - I have a working 6-DOF ascent simulation with guidance logic, staging, and orbital insertion modeling.
   - I can explain attitude control and state estimation in plain language.

3. **Mission-Level Thinking**
   - I can produce an honest orbital mission budget with realistic mass fractions and delta-v, and argue whether it closes.

4. **UAV Platform with Real Flight Hours**
   - I have built, tested, and instrumented a UAV platform with multi-hour endurance aspirations.
   - I have logs, power budgets, thermal data, and failure reports under version control.

5. **Safety Culture**
   - I can show a regulator, mentor, or future employer that I treat flight systems, chemistry, materials, and testing with discipline.

This is the point: deep simulation + honest hardware + safety mindset.

---

_Last updated: 2025-10-26_
