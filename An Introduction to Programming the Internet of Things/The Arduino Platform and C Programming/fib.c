#include <stdio.h>

int main(){
	int fib[6];
	fib[0] = 0;
	fib[1] = 1;
	
	for(int i = 2; i <= 5; i++)
		fib[i] = fib[i - 2] + fib[i - 1];
		
	for(int i = 0; i < 6; i++)
		printf("%d\n", fib[i]);
		
	return 0;
}
