#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    unsigned long long int previous = 0;
    unsigned long long int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        unsigned long long int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        current = current % 10;
    }

    return current % 10;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
