#include <stdio.h>

int main()
{
	char string[1000001], maxchar;
	int alp[26] = { 0, }, max = 0, count = 0, size = 0;
	scanf("%s", string);
	
	while (string[size] != '\0') size++;

	for (int i = 0; i < size; i++) {
		if (string[i] > 90) alp[string[i] - 97] += 1;
		else alp[string[i] - 65] += 1;
	}

	for (int i = 0; i < 26; i++) {
		if (alp[i] > max) {
			max = alp[i];
			maxchar = i + 65;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (alp[i] == max) count++;
	}

	if (count != 1) printf("?\n");
	else printf("%c\n", maxchar);
	
	return 0;
}