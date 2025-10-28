import matplotlib.pyplot as plt
# Data from your input
n_values = [10,50,100,500,1000,3000,5000,6000,7000,8000]
time_values = [0.000000,0.000000,0.000000,0.000000,0.000000,0.000004,0.000009,0.000009,0.000006,0.000014]
# Plotting
plt.figure(figsize=(10, 6))
plt.plot(n_values, time_values, marker='o', linestyle='-', color='blue')
# Titles and labels
plt.title('Linear Search: Array Size vs Time Taken')
plt.xlabel('Array Size (n)')
plt.ylabel('Time Taken (seconds)')

plt.grid(True)
# Show data point values
for i in range(len(n_values)):
 plt.text(n_values[i], time_values[i] + 0.00002, f"{time_values[i]:.6f}", ha='center',
fontsize=8)
# Show the plot1st
plt.tight_layout()
plt.show() 