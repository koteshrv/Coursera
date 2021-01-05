#include <iostream>
#include <vector>
using std::vector;

int fibonacci_sum_squares_naive(long long n) {
    vector<long long> f(60);
    long long sum = 0;
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i < 60; ++i)
    {
        f[i] = f[i - 1] + f[i - 2];
        //std::cout << f[i] << "\n";
    }
    //std::cout <<"*******************************" << "\n";

    n %= 60;
    
    for (int j = 0; j <= n; ++j){
       sum += (f[j] % 10) * (f[j] % 10);
       sum %= 10;
       //std::cout << sum << "\n";
   }

    return sum % 10;
    }



int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
