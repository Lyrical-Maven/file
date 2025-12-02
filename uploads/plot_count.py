import pandas as pd
import matplotlib.pyplot as plt

# Load CSV file
data = pd.read_csv("countsort_results.csv")

sizes = data["Size"]
avg_comp = data["AverageComparisons"]
nlogn = data["nlogn"]

plt.figure(figsize=(10,6))
plt.plot(sizes, avg_comp, label="Count Sort Avg Comparisons", marker="o")
plt.plot(sizes, nlogn, label="n log n", linestyle="--")

plt.xlabel("Input Size (n)")
plt.ylabel("Comparisons")
plt.title("Count Sort Comparisons vs n log n")
plt.legend()
plt.grid(True)
plt.show()
