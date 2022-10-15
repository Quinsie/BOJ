#include <stdio.h>

int main()
{
	int num, score = 0, acc = 0;
	scanf("%d", &num);
	
	int arr[101];
	for (int i = 0; i < num; i++) scanf("%d", &arr[i]);
	for (int j = 0; j < num; j++) {
		if (arr[j] == 1) {
			acc++;
			score += acc;
		}
		if (arr[j] == 1 && arr[j + 1] == 0) acc = 0;
		
	}
	printf("%d", score);
	return 0;

}