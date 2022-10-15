#include <stdio.h>

int main()
{
	int arr[4];
	for (int i = 0; i < 4; i++)
		scanf("%d", &arr[i]);

	int case1, case2;
	case1 = arr[2] + arr[1];
	case2 = arr[0] + arr[3];

	if (case1 > case2) printf("%d", case2);
	else printf("%d", case1);

	return 0;
}