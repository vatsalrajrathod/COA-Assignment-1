#include <iostream>
#include <time.h>

using namespace std;

long long fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    for (int i = 0; i < 50; i++) {
        cout << fibonacci_recursive(i) << " ";
    }
    cout << endl;

    clock_gettime(CLOCK_REALTIME, &end);
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << "Time taken by recursion: " << time_taken << " seconds" << endl;

    return 0;
}