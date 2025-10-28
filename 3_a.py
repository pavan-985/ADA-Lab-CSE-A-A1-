import matplotlib.pyplot as plt

# Data
n_values = [100, 200, 300, 400, 500, 600]

time_values = [0.000000, 0.054000, 0.106000, 0.225000, 0.436000, 0.832000]


# Plotting
plt.figure(figsize=(10, 6))
plt.plot(n_values, time_values, marker='o', linestyle='-', color='blue')

# Titles and labels
plt.title('Matrix_Multiplication_Iterative: Matrix Size vs Time Taken')
plt.xlabel('Matrix Size (n)')
plt.ylabel('Time Taken (seconds)')
plt.grid(True)

# Show data point values
for i in range(len(n_values)):
    plt.text(n_values[i], time_values[i] + 0.00001, f"{time_values[i]:.6f}", 
             ha='center', fontsize=8)

plt.tight_layout()
plt.show()
