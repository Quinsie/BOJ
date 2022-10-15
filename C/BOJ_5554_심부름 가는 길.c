#include <stdio.h>

int main()
{
	int temp, total = 0;
	for (int i = 0; i < 4; i++)
	{
		scanf("%d", &temp);
		total += temp;
	}
	printf("%d\n", total / 60);
	printf("%d\n", total % 60);
	return 0;
}