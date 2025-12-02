import pandas as pd
import matplotlib.pyplot as plt

# Load Selection Sort CSV
selection_df = pd.read_csv("selection_sort_results.csv")

# Plot Selection Sort
plt.figure(figsize=(10,6))
plt.plot(selection_df["Size"], selection_df["AverageComparisons"], label="Selection Sort (Avg Comparisons)", marker='o', color='r')
plt.plot(selection_df["Size"], selection_df["nlogn"], label="n log n", linestyle="--", color='g')
plt.xlabel("Input Size (n)")
plt.ylabel("Comparisons")
plt.title("Selection Sort Comparisons vs n log n")
plt.legend()
plt.grid(True)
plt.show()
