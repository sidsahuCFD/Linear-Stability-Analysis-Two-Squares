# Linear-Stability-Analysis-Two-Squares
Linear Stability Analysis of the chaotic flow around two square cylinders

# Linear Stability Analysis of Flow Past Two Side-by-Side Squares

This repository contains a workflow for **linear stability analysis** of the incompressible Navier–Stokes equations around the **two square cylinders** base flow. The method uses **ARPACK** (via `scipy.sparse.linalg.eigs`) together with a **modified `pimpleFoam`** linearised solver on **OpenFOAM v10**. ARPACK requires repeated applications of the linearised operator, so the linearised Navier–Stokes equations are advanced in time multiple times to assemble the Krylov subspace.

---

## Key Components

- **OpenFOAM 10 (custom solver)**  
  A modified version of `pimpleFoam` that advances the **linearised** NS equations around a provided base flow.

- **`eig.py` (Python driver)**  
  Orchestrates repeated runs of the linearised solver and interfaces with OpenFOAM case files. It calls `scipy.sparse.linalg.eigs` (ARPACK) to compute eigenvalues/eigenmodes.  
  > **Important:** ARPACK settings (e.g., `k`, `sigma`, `which`, `maxiter`, `tol`) are set **inside** `eig.py`.  
  > The **time interval** for each linearised run must **match** the values in OpenFOAM’s `system/controlDict` (e.g., `deltaT`, `endTime`, `writeInterval`).

- **`SC_eig.sh` (HPC batch script)**  
  Submission script for a remote HPC cluster. It calls `eig.py`, which in turn manages iterative linearised runs and the ARPACK solve.

---

## Repository Structure

├── case/ # OpenFOAM case (0/, constant/, system/)
│ ├── 0/
│ ├── constant/
│ └── system/
├── solvers/ 
├── eig.py # Python ARPACK driver (calls eigs())
├── SC_eig.sh # HPC submission script (calls eig.py)
└── README.md



---

## Requirements

- **OpenFOAM v10** (case compatible with your modified linearised `pimpleFoam`)
- **Python 3.9+** with:
  - `numpy`
  - `scipy`  (for `scipy.sparse.linalg.eigs`)
  - optional: `mpi4py` / `matplotlib` if your workflow uses them
- **HPC environment** (for `SC_eig.sh`): adapt module loads, queues, and `mpirun` to your cluster.

---

## Setup

1. **Build / make the linearised solver** (if not already available):
   ```bash
   # Example; adjust for your environment
   cd solver
   wmake


