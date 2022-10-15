#include <stdio.h>

int fibo(n)
{
	int arr[50];
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < 50; i++) arr[i] = arr[i - 2] + arr[i - 1];
	return arr[n - 1];
}

int main()
{
	int num;
	scanf("%d", &num);
	printf("%d", fibo(num));
	return 0;
}