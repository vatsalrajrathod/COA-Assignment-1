import matplotlib.pyplot as plt

# Matrix sizes
N_vals = [64, 128, 256, 512, 1024]

# Time measurements in seconds
int_times_cpp = [0.003, 0.027, 0.222, 1.689, 17.129]
dbl_times_cpp = [0.004, 0.032, 0.214, 2.073, 34.267]
int_times_py = [0.0002751, 0.0031247, 0.1155558, 0.6021991, 5.1802523]
dbl_times_py = [0.0001233, 0.0460172, 0.0811188, 0.0067067, 0.1888237]

# Create figure
plt.figure(figsize=(10, 6))

# Plotting
plt.plot(N_vals, int_times_cpp, label='C++ Int', marker='o', linestyle='-')
plt.plot(N_vals, dbl_times_cpp, label='C++ Double', marker='o', linestyle='-')
plt.plot(N_vals, int_times_py, label='Python Int', marker='s', linestyle='--')
plt.plot(N_vals, dbl_times_py, label='Python Double', marker='s', linestyle='--')

# Labels and title
plt.xlabel('Matrix Size (N)')
plt.ylabel('Time (s)')
plt.title('Execution Time vs Matrix Size')
plt.legend()
plt.grid(True)

# Show the plot
plt.tight_layout()
plt.show()