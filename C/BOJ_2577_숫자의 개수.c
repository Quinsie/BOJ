#include <stdio.h>
#include <string.h>

int main()
{
	char string[20];
	int num = 1, temp, arr[10] = { 0, };

	for (int i = 0; i < 3; i++) {
		scanf("%d", &temp);
		num *= temp;
	}

	sprintf(string, "%d", num);

	for (int i = 0; i < strlen(string); i++) {
		temp = (int)string[i] - 48;
		arr[temp] += 1;
	}

	for (int i = 0; i < 10; i++) printf("%d\n", arr[i]);

	return 0;
}