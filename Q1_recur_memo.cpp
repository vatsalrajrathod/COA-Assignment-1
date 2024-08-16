#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

long long fibonacci_recursive_memo(int n, vector<long long>& memo) {
    if (n <= 1)
        return n;
    if (memo[n] != -1)
        return memo[n];
    return memo[n] = fibonacci_recursive_memo(n - 1, memo) + fibonacci_recursive_memo(n - 2, memo);
}

int main() {
    vector<long long> memo(50, -1);
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    for (int i = 0; i < 50; i++) {
        cout << fibonacci_recursive_memo(i, memo) << " ";
    }
    cout << endl;

    clock_gettime(CLOCK_REALTIME, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << "Time taken by recursion with memoization: " << time_taken << " seconds" << endl;

    return 0;
}