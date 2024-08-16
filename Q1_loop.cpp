#include <iostream>
#include <time.h>

using namespace std;

long long fibonacci_loop(int n) {
    if (n <= 1)
        return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    for (int i = 0; i < 50; i++) {
        cout << fibonacci_loop(i) << " ";
    }
    cout << endl;

    clock_gettime(CLOCK_REALTIME, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << "Time taken by loop: " << time_taken << " seconds" << endl;

    return 0;
}