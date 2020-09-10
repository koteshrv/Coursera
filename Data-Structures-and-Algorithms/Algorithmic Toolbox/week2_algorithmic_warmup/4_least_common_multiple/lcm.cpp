#include <iostream>

//  a x b = LCM(a, b) * GCD (a, b)

//   LCM(a, b) = (a x b) / GCD(a, b) 


unsigned long long int gcd_naive(int a, int b) {
	if(b == 0)
		return a;

	return gcd_naive(b, a % b);
		
}
		


unsigned long long int lcm_naive(int a, int b) {
	return (a / gcd_naive(a, b)) * b;
}

int main() {
  unsigned long long int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
