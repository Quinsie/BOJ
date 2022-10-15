# include <stdio.h>

int main()
{
	int people = 0, on, off, max = 0;
	for (int i = 0; i < 4; i++) {
		scanf("%d %d", &off, &on);
		people += on;
		people -= off;
		if (people > max) max = people;
	}
	printf("%d", max);
	return 0;
}