#include <stdio.h>

int main()
{
	int temp, i, total = 0;

	for (i = 0; i < 5; i++) {
		scanf("%d", &temp);
		if (temp < 40) temp = 40;
		total += temp;
	}
	printf("%d", total / 5);

	return 0;
}