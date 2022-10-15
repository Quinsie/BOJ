#include <stdio.h>

int main()
{
	int num, total = 0;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
		total += i;

	printf("%d", total);
	
	return 0;
}