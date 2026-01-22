import csv
import matplotlib.pyplot as plt

x = []
y = []

with open("results/results.csv", "r", newline="") as f:
    reader = csv.reader(f)
    header = next(reader, None)  
    for row in reader:
        if not row:
            continue
        x.append(int(row[0]))
        y.append(float(row[1]))

plt.figure()
plt.plot(x, y, marker="o")

plt.xscale("log")
plt.yscale("log")

plt.xlabel("n (array size)")
plt.ylabel("time (seconds)")
plt.title("Merge sort benchmark (Centaurus)")
plt.grid(True)

plt.savefig("results/plot.png", dpi=200)
plt.show()
