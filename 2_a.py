import matplotlib.pyplot as plt

# Data
n_values = [10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000, 8000]
time_values = [0.000000, 0.000011, 0.000017, 0.000062, 0.000128, 
               0.000344, 0.000556, 0.000674, 0.000833, 0.000915]

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(n_values, time_values, marker='o', linestyle='-', color='blue')

# Titles and labels
plt.title('Merge sort: Array Size vs Time Taken')
plt.xlabel('Array Size (n)')
plt.ylabel('Time Taken (seconds)')
plt.grid(True)

# Show data point values
for i in range(len(n_values)):
    plt.text(n_values[i], time_values[i] + 0.00001, f"{time_values[i]:.6f}", 
             ha='center', fontsize=8)

plt.tight_layout()
plt.show()
