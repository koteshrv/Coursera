#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
	vector<long long> f(60);
    long long sum = 0;
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i < 60; ++i)
    {
        f[i] = f[i - 1] + f[i - 2];
    }

    from %= 60;
    to %= 60;

    if (to < from)
        to += 60;
    
    for (int j = from; j <= to; ++j)
       sum += f[j % 60];

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
