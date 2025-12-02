import pandas as pd
import matplotlib.pyplot as plt

# Load results
data = pd.read_csv("insertion_sort_results.csv")

# Extract columns
sizes = data["Size"]
avg_comparisons = data["AverageComparisons"]
nlogn = data["nlogn"]

# Plot
plt.figure(figsize=(10,6))
plt.plot(sizes, avg_comparisons, label="Insertion Sort Avg Comparisons", marker="o")
plt.plot(sizes, nlogn, label="n log n", linestyle="--")

plt.xlabel("Input Size (n)")
plt.ylabel("Number of Comparisons")
plt.title("Insertion Sort Comparisons vs n log n")
plt.legend()
plt.grid(True)
plt.show()

