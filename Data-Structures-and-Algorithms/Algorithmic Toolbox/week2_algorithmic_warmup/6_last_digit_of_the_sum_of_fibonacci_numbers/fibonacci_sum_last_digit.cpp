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


long long fibonacci_sum_naive(long long n, long long m) {

    int a = 0, b = 1, fib;
    
    if (n <= 1)
        return n;
    
    int sum = 1;
    for(int i = 2; i <= n; i++){
		fib = (a + b) % m;
		sum = sum + fib;
		a = b;
		b = fib;
		
	}

    return sum % m;
}

int main() {
    long long n = 0;
    std::cin >> n;
    long long rem = n % PisanoPeriod(10);
    //std::cout << rem << std::endl;
    std::cout << fibonacci_sum_naive(rem, 10);
}
