#include <stdio.h>

int main()
{
	int h, m, plus;
	scanf("%d %d", &h, &m);
	scanf("%d", &plus);

	m += plus;
	while (m >= 60)
	{
		m -= 60;
		h += 1;
	}
	while (h >= 24)
		h -= 24;

	printf("%d %d", h, m);
	return 0;
}