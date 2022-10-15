#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int length, total = 0;
	scanf("%d", &length);
	char* num = (char*)malloc((length + 1) * sizeof(char));
	scanf("%s", num);

	for (int i = 0; i < length; i++)
		total += (int)num[i] - 48;

	printf("%d\n", total);
	return 0;
}