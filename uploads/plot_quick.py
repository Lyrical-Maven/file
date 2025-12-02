import pandas as pd
import matplotlib.pyplot as plt

# Load Quick Sort results
df = pd.read_csv("quick_sort_results.csv")

plt.figure(figsize=(10,6))
plt.plot(df["Size"], df["AverageComparisons"], label="Quick Sort (Avg Comparisons)", marker='o')
plt.plot(df["Size"], df["nlogn"], label="n log n", linestyle="--", color="orange")
plt.xlabel("Input Size (n)")
plt.ylabel("Comparisons")
plt.title("Quick Sort Comparisons vs n log n")
plt.legend()
plt.grid(True)
plt.show()
