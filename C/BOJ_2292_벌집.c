#include <stdio.h>
int main(void)
{
	int N;
	int count = 0;
	int house = 1;
	scanf("%d", &N);

	if (N == 1)
		printf("%d",N);

	else
	{
		while (1)
		{
			N -= house;
		    house = 6 * count;
		    count++;

		    if (N <= house)
		    {
		    	printf("%d", count);
		    	break;
		    }
		}
	}
	return 0;
}