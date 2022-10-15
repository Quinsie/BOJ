#include <stdio.h>

int main()
{
	int snack, quantity, money;
	scanf("%d", &snack);
	scanf("%d", &quantity);
	scanf("%d", &money);

	if (snack * quantity >= money) printf("%d", snack * quantity - money);
	else printf("%d", 0);
	return 0;
}