#include <stdio.h>

int main()
{
	int temp, i, min = 0, set = 0;
	int arr[5];
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &temp);
		arr[i] = temp;
	}
	min = arr[0];
	for (i = 0; i < 3; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	set += min;
	min = arr[3];
	for (i = 3; i < 5; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	set += min;
	printf("%d", set - 50);
	return 0;
}