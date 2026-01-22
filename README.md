# ITSC 4145 - Assignment 1 (Merge Sort + Centaurus Bench)

This repo has a basic merge sort in C++ and a way to benchmark it on Centaurus.

## Files
- `mergesort.cpp` : merges sort + timing, prints 
- `Makefile` : builds with `make`
- `benchmark.sbatch` : script for slurm that runs n = 10^1 ... 10^9
- `plot.py` : makes a log/log plot from results
- `results/results.csv` : outputs data
- `results/plot.png` : plots image

## Build
On Linux (Centaurus or local):
```bash
make clean
make
