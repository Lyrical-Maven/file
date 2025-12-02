import pandas as pd
import matplotlib.pyplot as plt

# Choose which result file to plot
filename = "bubble_sort_results.csv"
algo_name = "Bubble Sort"              

# Load CSV
df = pd.read_csv(filename)

# Plot
plt.figure(figsize=(10,6))
plt.plot(df["Size"], df["AverageComparisons"], label=f"{algo_name} (Avg Comparisons)", marker='o')
plt.plot(df["Size"], df["nlogn"], label="n log n", linestyle="--")
plt.xlabel("Input Size (n)")
plt.ylabel("Comparisons")
plt.title(f"{algo_name} Comparisons vs n log n")
plt.legend()
plt.grid(True)
plt.show()
