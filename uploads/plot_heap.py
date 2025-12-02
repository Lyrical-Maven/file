import pandas as pd
import matplotlib.pyplot as plt

# Load CSV file
heap_df = pd.read_csv("heap_sort_results.csv")

# Plot Heap Sort
plt.figure(figsize=(10,6))
plt.plot(heap_df["Size"], heap_df["AverageComparisons"], label="Heap Sort (Avg Comparisons)", marker='o')
plt.plot(heap_df["Size"], heap_df["nlogn"], label="n log n", linestyle="--")
plt.xlabel("Input Size (n)")
plt.ylabel("Comparisons")
plt.title("Heap Sort Comparisons vs n log n")
plt.legend()
plt.grid(True)
plt.show()
