#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

void fibonacci_loop_memo(vector<long long>& memo) {
    memo[0] = 0;
    memo[1] = 1;
    for (int i = 2; i < 50; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
}

int main() {
    vector<long long> memo(50);
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    fibonacci_loop_memo(memo);
    for (int i = 0; i < 50; i++) {
        cout << memo[i] << " ";
    }
    cout << endl;

    clock_gettime(CLOCK_REALTIME, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << "Time taken by loop with memoization: " << time_taken << " seconds" << endl;

    return 0;
}