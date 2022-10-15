#include <stdio.h>

int main()
{
	int num = 0, temp;
	for (int i = 0; i < 5; i++) {
		temp = 0;
		scanf("%d", &temp);
		num += temp;
	}
	printf("%d", num);
	return 0;
}