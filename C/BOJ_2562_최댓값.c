#include <stdio.h>

int main()
{
	int arr[9], max = 0, count = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] > max) {
			max = arr[i];
			count = i;
		}
	}
	printf("%d\n%d", max, count + 1);
}