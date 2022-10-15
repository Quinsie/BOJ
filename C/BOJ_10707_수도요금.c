#include <stdio.h>

int main()
{
	int arr[5];
	for (int i = 0; i < 5; i++)
		scanf("%d", &arr[i]);
	
	int com_x, com_y;
	com_x = arr[0] * arr[4];
	if (arr[4] > arr[2])
		com_y = arr[1] + arr[3] * (arr[4] - arr[2]);
	else
		com_y = arr[1];

	if (com_x > com_y)
		printf("%d", com_y);
	else
		printf("%d", com_x);

	return 0;
}