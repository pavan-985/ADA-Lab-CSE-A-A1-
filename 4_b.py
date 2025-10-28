import matplotlib.pyplot as plt

# Data
n_values = [10,20,30,40,50]
time_values = [0.000000, 0.016000, 0.032000, 1.077000, 122.574000, 
               ]

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(n_values, time_values, marker='o', linestyle='-', color='blue')

# Titles and labels
plt.title('Fibonacci Series(Recursive): nth no vs Time Taken')
plt.xlabel('nth no (n)')
plt.ylabel('Time Taken (seconds)')
plt.grid(True)

# Show data point values
for i in range(len(n_values)):
    plt.text(n_values[i], time_values[i] + 0.00001, f"{time_values[i]:.6f}", 
             ha='center', fontsize=8)

plt.tight_layout()
plt.show()