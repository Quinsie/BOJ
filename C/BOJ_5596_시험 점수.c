#include <stdio.h>

int main()
{
	int temp, i, total_1 = 0, total_2 = 0;

	for (i = 0; i < 4; i++) {
		scanf("%d", &temp);
		total_1 += temp;
	}
	for (i = 0; i < 4; i++) {
		scanf("%d", &temp);
		total_2 += temp;
	}

	if (total_1 > total_2)
		printf("%d", total_1);
	else
		printf("%d", total_2);

	return 0;
}