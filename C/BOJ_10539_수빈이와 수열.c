#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num, temp, now = 0;
	scanf("%d", &num);
	int* arr = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &temp);
		arr[i] = temp * (i + 1);
	}

	for (int j = 0; j < num; j++) {
		temp = arr[j] - now;
		printf("%d ", temp);
		now += temp;
	}
	return 0;
}