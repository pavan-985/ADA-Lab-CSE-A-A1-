import matplotlib.pyplot as plt

# Data
n_values = [10, 50, 100, 500, 1000, 3000, 5000, 6000, 7000, 8000]
time_values = [0.000000, 0.000000, 0.000018, 0.000180, 0.000582, 
               0.005372, 0.014242, 0.019976, 0.027764, 0.040360]

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(n_values, time_values, marker='o', linestyle='-', color='blue')

# Titles and labels
plt.title('selection sort: Array Size vs Time Taken')
plt.xlabel('Array Size (n)')
plt.ylabel('Time Taken (seconds)')
plt.grid(True)

# Show data point values
for i in range(len(n_values)):
    plt.text(n_values[i], time_values[i] + 0.00001, f"{time_values[i]:.6f}", 
             ha='center', fontsize=8)

plt.tight_layout()
plt.show()
