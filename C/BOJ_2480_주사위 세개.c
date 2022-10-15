#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
    
	if (a == b && b == c)
        printf("1%d000", a);
	else if (a == b || a == c)
        printf("1%d00", a);
	else if (b == c)
        printf("1%d00", b);
	else
        printf("%d00", a > (b > c ? b : c) ? a : (b > c ? b : c));
    
    return 0;
}