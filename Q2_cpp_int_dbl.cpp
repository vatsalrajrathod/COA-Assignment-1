#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function for matrix multiplication with integers
void multiplyMatricesInt(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &C, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function for matrix multiplication with doubles
void multiplyMatricesDouble(const vector<vector<double>> &A, const vector<vector<double>> &B, vector<vector<double>> &C, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    vector<int> sizes = {64, 128, 256, 512, 1024};
    
    for (int N : sizes) {
        // Initialize matrices for integers
        vector<vector<int>> A(N, vector<int>(N, 1));
        vector<vector<int>> B(N, vector<int>(N, 2));
        vector<vector<int>> C(N, vector<int>(N, 0));

        // Record total start time
        auto total_start = high_resolution_clock::now();

        // Record start time for meat portion
        auto meat_start = high_resolution_clock::now();

        // Matrix multiplication with integers
        multiplyMatricesInt(A, B, C, N);

        // Record end time for meat portion
        auto meat_stop = high_resolution_clock::now();

        // Record total end time
        auto total_stop = high_resolution_clock::now();

        // Calculate durations
        auto meat_duration = duration_cast<milliseconds>(meat_stop - meat_start);
        auto total_duration = duration_cast<milliseconds>(total_stop - total_start);

        // Calculate proportion of meat portion
        double proportion = (double)meat_duration.count() / total_duration.count() * 100;

        cout << "Integer Matrix Size " << N << "x" << N << ": " << meat_duration.count() << " ms (" << proportion << "% of total time " << total_duration.count() << " ms)" << endl;

        // Initialize matrices for doubles
        vector<vector<double>> A_double(N, vector<double>(N, 1.0));
        vector<vector<double>> B_double(N, vector<double>(N, 2.0));
        vector<vector<double>> C_double(N, vector<double>(N, 0.0));

        // Record total start time
        total_start = high_resolution_clock::now();

        // Record start time for meat portion
        meat_start = high_resolution_clock::now();

        // Matrix multiplication with doubles
        multiplyMatricesDouble(A_double, B_double, C_double, N);

        // Record end time for meat portion
        meat_stop = high_resolution_clock::now();

        // Record total end time
        total_stop = high_resolution_clock::now();

        // Calculate durations
        meat_duration = duration_cast<milliseconds>(meat_stop - meat_start);
        total_duration = duration_cast<milliseconds>(total_stop - total_start);

        // Calculate proportion of meat portion
        proportion = (double)meat_duration.count() / total_duration.count() * 100;

        cout << "Double Matrix Size " << N << "x" << N << ": " << meat_duration.count() << " ms (" << proportion << "% of total time " << total_duration.count() << " ms)" << endl;
    }

    return 0;
}