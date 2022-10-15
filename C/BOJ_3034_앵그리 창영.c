#include <stdio.h>
#include <math.h>

int main()
{
	int match, width, height, temp;
	double diagonal;
	scanf("%d %d %d", &match, &width, &height);
	
	diagonal = sqrt(pow(width, 2) + pow(height, 2));

	for (int i = 0; i < match; i++) {
		scanf("%d", &temp);
		if (temp <= diagonal) printf("DA\n");
		else printf("NE\n");
	}
	return 0;
}