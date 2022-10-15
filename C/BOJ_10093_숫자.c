#include <stdio.h>

int main()
{
	unsigned long long start, end;
	scanf("%llu %llu", &start, &end);
	if (start < end) {
		printf("%llu\n", end - start - 1);
		for (unsigned long long i = start + 1; i < end; i++) printf("%llu ", i);
	}
	else if (end < start) {
		printf("%llu\n", start - end - 1);
		for (unsigned long long i = end + 1; i < start; i++) printf("%llu ", i);
	}
	else printf("0");
	return 0;
}