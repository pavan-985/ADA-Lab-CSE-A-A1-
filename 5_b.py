import matplotlib.pyplot as plt

# Data
n_values = [1000,2000,3000,4000,5000,6000,7000,8000]
time_values = [0.020000, 0.058000, 0.094000, 0.184000, 0.239000, 0.408000, 0.549000, 0.680000]

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(n_values, time_values, marker='o', linestyle='-', color='blue')

# Titles and labels
plt.xlabel('NUMBER Of Items : n')
plt.ylabel('Avg Time taken (in seconds)')
plt.title('Fractional 0/1 knapsack by Dynamic Programing GRAPH')

plt.grid(True)

# Show data point values
for i in range(len(n_values)):
    plt.text(n_values[i], time_values[i] + 0.00001, f"{time_values[i]:.6f}", 
             ha='center', fontsize=8)

plt.tight_layout()
plt.show()
