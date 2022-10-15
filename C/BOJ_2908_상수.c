#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char num1[4], num2[4], temp;
	int n1, n2;
	
	scanf("%s %s", num1, num2);

	temp = num1[0];
	num1[0] = num1[2];
	num1[2] = temp;

	temp = num2[0];
	num2[0] = num2[2];
	num2[2] = temp;

	n1 = atoi(num1);
	n2 = atoi(num2);

	if (n1 > n2) printf("%d\n", n1);
	else printf("%d\n", n2);
	return 0;
}