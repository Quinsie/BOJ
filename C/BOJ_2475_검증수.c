#include <stdio.h>

int main()
{
	int temp, total = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &temp);
		total += temp * temp;
	}
	printf("%d", total % 10);
	return 0;
}