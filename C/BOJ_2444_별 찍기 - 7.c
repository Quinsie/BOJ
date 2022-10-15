# include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - i - 1; j++) printf(" ");
		for (int k = 0; k < (i * 2) + 1; k++) printf("*");
		printf("\n");
	}
	
	for (int i = 1; i < num; i++) {
		for (int k = 0; k < i; k++) printf(" ");
		for (int j = 0; j < ((num - i) * 2) - 1; j++) printf("*");
		printf("\n");
	}
	return 0;
}