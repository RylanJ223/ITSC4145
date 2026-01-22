#!/bin/bash
#SBATCH --job-name=ms_bench
#SBATCH --partition=centaurus
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --time=00:20:00
#SBATCH --output=slurm-%j.out

# simple benchmark runner
# it rebuilds first, then runs powers of 10

module purge

make clean
make

mkdir -p results
OUTFILE="results/results.csv"

echo "n,time_seconds" > "$OUTFILE"

for e in 1 2 3 4 5 6 7 8 9
do
  n=$((10**e))
  echo "running n=$n"
  ./mergesort "$n" >> "$OUTFILE"
done

