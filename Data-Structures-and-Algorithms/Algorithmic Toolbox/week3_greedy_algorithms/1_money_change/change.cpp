#include <iostream>

int get_change(int m) {
	//write your code here
	int oneCoins, fiveCoins, tenCoins;
  
	tenCoins = m / 10;
	m = m - (tenCoins * 10);
	fiveCoins = m / 5;
	m = m - (fiveCoins * 5);
	oneCoins = m ;
		
	int n = oneCoins + fiveCoins + tenCoins;
	
	return n;
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
	return 0;
	
}
