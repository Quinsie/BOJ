#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	char num[6], ch;
	int decimal = 0, position = 0;

	scanf("%s", num);
	for (int i = strlen(num) - 1; i >= 0; i--) {
		ch = num[i];
		if (ch >= 48 && ch <= 57) decimal += (ch - 48) * (int)pow(16, position);
		else if (ch >= 65 && ch <= 70) decimal += (ch - (65 - 10)) * (int)pow(16, position);
		position++;
	}
	printf("%d\n", decimal);
	return 0;
}