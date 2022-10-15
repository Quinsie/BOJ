#include <stdio.h>
#include <string.h>

int main()
{
	char num_1[100], num_2[100], op;
	int zero_num_1, zero_num_2;
	
	scanf("%s", num_1);
	scanf(" %c", &op);
	scanf(" %s", num_2);

	zero_num_1 = strlen(num_1) - 1;
	zero_num_2 = strlen(num_2) - 1;

	if (op == 42) {
		printf("1");
		for (int i = 0; i < zero_num_1 + zero_num_2; i++) printf("0");
	}

	else if (op == 43) {
		if (zero_num_1 > zero_num_2) {
			printf("1");
			for (int i = 0; i < zero_num_1 - zero_num_2 - 1; i++) printf("0");
			printf("1");
			for (int i = 0; i < zero_num_2; i++) printf("0");
		}
		else if (zero_num_1 == zero_num_2) {
			printf("2");
			for (int i = 0; i < zero_num_1; i++) printf("0");
		}
		else {
			printf("1");
			for (int i = 0; i < zero_num_2 - zero_num_1 - 1; i++) printf("0");
			printf("1");
			for (int i = 0; i < zero_num_1; i++) printf("0");
		}
	}
	return 0;
}