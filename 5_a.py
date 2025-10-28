import matplotlib.pyplot as plt

# Data
n_values = [10000,20000,30000,40000,50000,60000,70000,80000]
time_values = [0.000000, 0.016000, 0.015000, 0.000000, 0.016000, 0.017000, 0.008000, 0.000000]

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(n_values, time_values, marker='o', linestyle='-', color='blue')

# Titles and labels
plt.xlabel('NUMBER Of Items : n')
plt.ylabel('Avg Time taken (in seconds)')
plt.title('Fractional knapsack by Greedy method GRAPH')

plt.grid(True)

# Show data point values
for i in range(len(n_values)):
    plt.text(n_values[i], time_values[i] + 0.00001, f"{time_values[i]:.6f}", 
             ha='center', fontsize=8)

plt.tight_layout()
plt.show()
