#include <stdio.h>

int main()
{
	int arr_1[4];
	for (int i = 0; i < 4; i++) scanf("%d", &arr_1[i]);

	int arr_2[] = {arr_1[0], arr_1[2] - arr_1[0], arr_1[1], arr_1[3] - arr_1[1]};
	int min = arr_2[0];
	for (int i = 1; i < 4; i++) {
		if (arr_2[i] < min) min = arr_2[i];
	}
	printf("%d", min);

	return 0;
}