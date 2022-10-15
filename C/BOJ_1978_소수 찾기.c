#include <stdio.h>
#include <math.h>

int main()
{
	int row, num, count = 0, flag = 0;
	scanf("%d", &row);
	for (int i = 0; i < row; i++) {
		scanf("%d", &num);
		flag = 0;
		if (num == 1) continue;
		else {
			for (int j = 2; j <= sqrt(num); j++) {
				if (num % j == 0) {
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0) count++;
	}
	printf("%d", count);
	return 0;
}