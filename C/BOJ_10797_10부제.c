#include <stdio.h>

int main()
{
	int num, temp, count = 0;

	scanf("%d", &num);
	for (int i = 0; i < 5; i++) {
		scanf("%d", &temp);
		if (temp == num) count += 1;
	}
	printf("%d", count);
	return 0;
}