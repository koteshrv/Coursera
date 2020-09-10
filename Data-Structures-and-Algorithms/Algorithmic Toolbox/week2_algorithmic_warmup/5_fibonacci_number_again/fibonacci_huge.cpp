#include <iostream>

long long int PisanoPeriod(long long int m)
{
    int a = 0;
    int b = 1;
    int c,d;

    int i = 1;
    while(1)
    {
        i++;
        c = (a + b) % m;
        d = (c + b) % m;

        if (c ==0  && d == 1)
            return i;

        a = b;
        b = c;
    }
}


long long get_fibonacci_huge_naive(long long n, long long m) {

    int a = 0, b = 1, fib;
    
    if (n <= 1)
        return n;
    
    for(int i = 2; i <= n; i++){
		fib = (a + b) % m;
		a = b;
		b = fib;
	}

    return fib % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    long long rem = n % PisanoPeriod(m);
    std::cout << get_fibonacci_huge_naive(rem, m) << '\n';
}
