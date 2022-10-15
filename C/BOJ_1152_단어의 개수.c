#include <stdio.h>
#include <string.h>

int main()
{
	char sentence[1000001];
	int flag = 0, count = 0;
	gets(sentence);
	
	for (int i = 0; i < strlen(sentence); i++) {
		if (sentence[i] != 32) {
			if (flag == 0) {
				flag = 1;
				count += 1;
			}
		}
		else flag = 0;
	}

	printf("%d", count);
	return 0;
}