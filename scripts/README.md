# Analysis Scripts

Python scripts for analyzing C++ simulation output and generating visualizations.

## Purpose

C++ code handles the heavy computation; Python handles analysis and plotting.

## Typical Workflow

```bash
# 1. Run C++ simulation (generates CSV/text output)
./build/sims/rocket_perf --output results/trajectory.csv

# 2. Analyze and visualize with Python
python scripts/plot_trajectory.py results/trajectory.csv
```

## Planned Scripts

- [ ] `plot_trajectory.py` - Visualize orbital trajectories
- [ ] `analyze_performance.py` - Rocket performance analysis
- [ ] `compare_stages.py` - Multi-stage configuration comparison
- [ ] `mission_stats.py` - Generate mission statistics
- [ ] `jupyter_helpers.py` - Helper functions for notebooks

## Requirements

Create a `requirements.txt` when adding Python dependencies:

```
numpy
matplotlib
pandas
scipy
```

Install with:
```bash
pip install -r requirements.txt
```

## Development Guidelines

- Keep scripts simple and focused
- Document input/output formats
- Generate publication-quality plots
- Save results alongside data (e.g., `trajectory.csv` → `trajectory.png`)

---

**Note**: Python is for post-processing only, not real-time simulation.

