# Propulsion Notebook

**Status**: Just Starting | **Approach**: Depth Over Speed

A comprehensive learning and research repository documenting aerospace propulsion systems, orbital mechanics, and unmanned aerial vehicle (UAV) development.

---

## 🎯 Project Goals

This repository tracks a personal journey through aerospace engineering fundamentals, from theoretical understanding to practical implementation:

1. **Master propulsion theory** - Thermodynamics, combustion chemistry, rocket performance
2. **Build simulation tools** - Flight dynamics, trajectory analysis, performance modeling  
3. **Develop UAV systems** - Long-endurance platforms with focus on energy efficiency
4. **Maintain rigorous safety** - Document everything, plan every test, learn from data

---

## 📚 Current Status

### ✅ Completed So Far
- **Introductory Course**: Yale University "Rocket Science for Everyone" (Coursera) - basic overview
- **Initial Notes**: Documented course material on orbital mechanics, rocket basics, and satellites
- **Project Setup**: Directory structure, safety templates, and documentation framework

### Reality Check
This is the **very beginning** of a long learning journey. One introductory course does not make foundations "complete" - it's just the first step. Much more study, simulation work, and hands-on experience needed before claiming any real competency.

### ⏳ Next Steps
- Choose learning path: simulation work (ARC A) or UAV modeling (ARC B)
- Continue deeper study with textbooks and advanced coursework
- Build first simple simulation to practice concepts
- Research local regulations (SHGM UAV requirements)

See [`PROJECT_STATUS.md`](PROJECT_STATUS.md) for detailed progress tracking.

---

## 🗂️ Repository Structure

```
propulsion-notebook/
├── theory/                    # Learning notes, derivations, theory documents
│   ├── quick_reference.md     # Equations, values, and quick facts
│   ├── orbital_mechanics.md   # Orbits and Kepler's laws
│   ├── rocket_fundamentals.md # Rocket equation and staging
│   └── satellite_systems.md   # Satellite design and subsystems
│
├── sims/                      # Simulation code and analysis
│   └── (Planned: rocket_perf, ascent_6dof, uav_endurance, etc.)
│
├── uav/                       # UAV hardware development
│   └── (Planned: airframe, avionics, propulsion bench tests)
│
├── safety_and_limits/         # Safety documentation
│   ├── RISK_LOG.md           # Risk assessment and incident tracking
│   ├── MATERIALS_NOTES.md    # Chemical/material handling guidelines
│   ├── TEST_PLAN_TEMPLATE.md # Pre-test planning template
│   └── TEST_REPORT_TEMPLATE.md # Post-test documentation
│
├── PROJECT_STATUS.md          # Detailed progress tracking
├── ROADMAP.md                 # Long-term learning roadmap
└── README.md                  # This file
```

---

## 🛣️ Learning Roadmap

### ARC A: High-Energy Propulsion & GNC (Simulation-Based)
1. **A1**: Propulsion thermodynamics & combustion chemistry
2. **A2**: Materials, cooling, and thermal limits  
3. **A3**: Feed systems, valves, and turbopumps
4. **A4**: Guidance, Navigation, and Control (GNC)
5. **A5**: Staging and orbital mission modeling

### ARC B: Long-Endurance UAV (Hardware-Based)
1. **B1**: Mission energy budget analysis
2. **B2**: Airframe design & materials
3. **B3**: Avionics, telemetry, and perception
4. **B4**: Propulsion bench testing
5. **B5**: Integrated long-endurance platform

See [`ROADMAP.md`](ROADMAP.md) for complete details.

---

## 🔬 Methodology

### Core Principles
- **Depth over speed**: Understanding fundamentals thoroughly before moving forward
- **Document everything**: Theory notes, simulations, test procedures, results
- **Safety first**: Every test planned and reviewed; risk assessment required
- **Honest assessment**: Learning from failures is more valuable than hiding them

### Documentation Standards
- **Theory**: Cite sources, show derivations, include worked examples
- **Code**: Comments explaining physics, validation against known results
- **Hardware**: Full test plans before any energetic testing
- **Data**: Raw data preserved, analysis methodology documented

---

## ⚠️ Safety Notice

This repository involves research into propulsion systems and energetic materials. All experimental work follows strict safety protocols:

- ✅ Risk assessments completed before any test
- ✅ Appropriate safety equipment and procedures
- ✅ Compliance with local regulations
- ✅ Honest documentation of incidents and near-misses

**DO NOT attempt to recreate any experiments without:**
1. Proper training and supervision
2. Appropriate safety equipment
3. Legal authorization and permits
4. Understanding of the hazards involved

---

## 📖 Key Resources

### Completed Coursework
- [Rocket Science for Everyone](https://www.coursera.org/learn/rocket-science-for-everyone/) - Yale University (Coursera)

### Reference Textbooks
- Curtis, H. D. - *Orbital Mechanics for Engineering Students*
- Sutton & Biblarz - *Rocket Propulsion Elements*
- Wertz & Larson - *Space Mission Analysis and Design*
- Turner, M. J. L. - *Rocket and Spacecraft Propulsion*

### Simulation Tools
- Python (NumPy, SciPy, Matplotlib) for performance modeling
- STK / GMAT for trajectory analysis
- OpenFOAM / SU2 for CFD (planned)

---

## 📝 License & Disclaimer

### License
This repository is shared for educational purposes. Code and documentation are available under the MIT License unless otherwise specified.

### Disclaimer
- This is a **personal learning project**, not affiliated with any institution
- Content is for **educational purposes only**
- No warranties or guarantees of accuracy
- **Experimental propulsion work is inherently dangerous** - proper training and safety measures required
- Author assumes no liability for anyone attempting to replicate any work shown here

---

## 🤝 Contributing

This is a personal learning repository, but if you spot errors in theory notes or have suggestions for safety improvements, feel free to open an issue.

---

## 📬 Contact

For questions or collaboration inquiries related to UAV research and aerospace education.

---

**Last Updated**: October 28, 2025  
**Status**: Foundations complete, ready to begin simulation or hardware work

---

_"Space is hard not because of altitude, but because of the enormous velocities required."_

