#include <stdio.h>
#include <string.h>

void reverse(char* arr)
{
	int temp, length = strlen(arr);
	for (int i = 0; i < length / 2; i++) {
		temp = arr[i];
		arr[i] = arr[length - i - 1];
		arr[length - i - 1] = temp;
	}
}

int main()
{
	char num1[10002] = { 0, }, num2[10002] = { 0, }, result[10002] = { 0, };
	int length, sum = 0, up = 0;
	scanf("%s %s", num1, num2);

	reverse(num1);
	reverse(num2);

	if (strlen(num1) > strlen(num2)) length = strlen(num1);
	else length = strlen(num2);

	for (int i = 0; i < length; i++) {
		sum = (num1[i] - 48) + (num2[i] - 48) + up;

		if (sum < 0) sum += 48;
		if (sum > 9) up = 1;
		else up = 0;

		result[i] = (sum % 10) + 48;
	}

	if (up == 1) result[length] = 49;
	reverse(result);

	printf("%s\n", result);
	return 0;
}