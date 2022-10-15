#include <stdio.h>
#include <stdlib.h>

int main()
{
	char input = getchar();
	while (input != EOF) {
		printf("%c", input);
		input = getchar();
	}
	return 0;
}