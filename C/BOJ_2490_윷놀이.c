# include <stdio.h>

int main()
{
	for (int i = 0; i < 3; i++) {
		int one = 0, zero = 0, temp;
		for (int j = 0; j < 4; j++) {
			scanf("%d", &temp);
			if (temp == 0) zero += 1;
			else one += 1;
		}
		if (one == 4) printf("E\n");
		else if (one == 3) printf("A\n");
		else if (one == 2) printf("B\n");
		else if (one == 1) printf("C\n");
		else printf("D\n");
	}
	return 0;
}