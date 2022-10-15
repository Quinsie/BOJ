#include <stdio.h>

int fibo(int n)
{
	if (n < 2) return n;
	int cache[] = { 0, 1, 1 };
	int count = n - 2;
	while (count != 0) {
		cache[0] = cache[1];
		cache[1] = cache[2];
		cache[2] = ((cache[0] % 1000000) + (cache[1] % 1000000)) % 1000000;
		count--;
	}
	return cache[2];
}


int main()
{
	long long num;
	scanf("%lld", &num);
	printf("%d", fibo(num % 1500000));
	return 0;
}