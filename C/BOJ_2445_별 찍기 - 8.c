# include <stdio.h>

int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < i + 1; j++) printf("*");
		for (int k = 2; k < (num - i) * 2; k++) printf(" ");
		for (int l = 0; l < i + 1; l++) printf("*");
		printf("\n");
	}
	for (int i = 0; i < num; i++) {
		for (int j = 1; j < num - i; j++) printf("*");
		for (int k = 0; k < (i * 2) + 2; k++) printf(" ");
		for (int l = 1; l < num - i; l++) printf("*");
		printf("\n");
	}
	return 0;
}