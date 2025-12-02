import pandas as pd
import matplotlib.pyplot as plt

# Load Merge Sort CSV
merge_df = pd.read_csv("merge_sort_results.csv")

# Plot Merge Sort
plt.figure(figsize=(10,6))
plt.plot(merge_df["Size"], merge_df["AverageComparisons"], label="Merge Sort (Avg Comparisons)", marker='o')
plt.plot(merge_df["Size"], merge_df["nlogn"], label="n log n", linestyle="--")
plt.xlabel("Input Size (n)")
plt.ylabel("Comparisons")
plt.title("Merge Sort Comparisons vs n log n")
plt.legend()
plt.grid(True)
plt.show()
