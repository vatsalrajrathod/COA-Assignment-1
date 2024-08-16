import numpy as np
import time

# Function for matrix multiplication with integers
def multiply_matrices_int(A, B):
    return np.dot(A, B)

# Function for matrix multiplication with doubles
def multiply_matrices_double(A, B):
    return np.dot(A, B)

def measure_time_and_performance(size):
    # Initialize matrices for integers
    A_int = np.ones((size, size), dtype=int)
    B_int = np.ones((size, size), dtype=int) * 2

    C_int = np.zeros((size, size), dtype=int)
    
    start_time_total = time.time()
    
    start_time_meat = time.time()
    C_int = multiply_matrices_int(A_int, B_int)
    end_time_meat = time.time()

    end_time_total = time.time()

    meat_duration = (end_time_meat - start_time_meat) * 1000  # in milliseconds
    total_duration = (end_time_total - start_time_total) * 1000  # in milliseconds

    proportion = (meat_duration / total_duration) * 100

    print(f"Integer Matrix Size {size}x{size}: {meat_duration:.4f} ms ({proportion:.2f}% of total time {total_duration:.4f} ms)")

    # Initialize matrices for doubles
    A_double = np.ones((size, size), dtype=float)
    B_double = np.ones((size, size), dtype=float) * 2.0

    C_double = np.zeros((size, size), dtype=float)
    
    start_time_total = time.time()
    
    start_time_meat = time.time()
    C_double = multiply_matrices_double(A_double, B_double)
    end_time_meat = time.time()

    end_time_total = time.time()

    meat_duration = (end_time_meat - start_time_meat) * 1000  # in milliseconds
    total_duration = (end_time_total - start_time_total) * 1000  # in milliseconds

    proportion = (meat_duration / total_duration) * 100

    print(f"Double Matrix Size {size}x{size}: {meat_duration:.4f} ms ({proportion:.2f}% of total time {total_duration:.4f} ms)")

def main():
    sizes = [64, 128, 256, 512, 1024]
    for size in sizes:
        measure_time_and_performance(size)

if _name_ == "_main_":
    main()