#include <stdio.h>

int main()
{
	int length, num, m;
	long long total = 0;
	scanf("%d", &length);

	for (int i = 0; i < length; i++)
	{
		scanf("%d", &num);
		total += num;
	}

	m = total - (long long)length * (length - 1) / 2LL;
	printf("%d", m);
	
	return 0;
}