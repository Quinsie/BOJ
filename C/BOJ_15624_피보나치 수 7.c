#include <stdio.h>

int fibo(int n)
{
	if (n < 2) return n;
	int cache[] = { 0, 1, 1 };
	int count = n - 2;
	while (count != 0) {
		cache[0] = cache[1];
		cache[1] = cache[2];
		cache[2] = ((cache[0] % 1000000007) + (cache[1] % 1000000007)) % 1000000007;
		count--;
	}
	return cache[2];
}


int main()
{
	int num;
	scanf("%d", &num);
	printf("%d", fibo(num));
	return 0;
}