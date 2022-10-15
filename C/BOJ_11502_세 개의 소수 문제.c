#include <stdio.h>
#include <stdlib.h>

static int count1;

int eratos(int* flag, int n, int* prime) { //0-> true 1->false //소수찾기
	int count = 0;
	flag[0] = 1; flag[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (flag[i] == 0) {
			for (int j = i + i; j < n + 1; j += i) flag[j] = 1;
		}
	}
	for (int i = 2; i < n + 1; i++)
		if (flag[i] == 0) {
			prime[count] = i;
			count++;
		}
	return count;
}

int max_arr(int* arr, int len) {
	int max = 0;
	for (int i = 0; i < len; i++) {
		if (arr[i] > max)max = arr[i];
	}
	return max;
}

void func(int pos, int prime_len, int* ans, int* check, int* prime, int num) {
	int plus = 0;

   if (count1 != 0) return;

	if (pos == 3) {
		for (int i = 0; i < 3; i++)plus += prime[ans[i]];
		if (plus == num) {
			for (int i = 0; i < 3; i++) printf("%d ", prime[ans[i]]);
			printf("\n");
			count1 = 1;
		}
		return;
	}
	for (int i = max_arr(ans, 3); i < prime_len; i++) {
			ans[pos] = i;
			func(pos + 1, prime_len, ans, check, prime, num);
			ans[pos] = 0;
	}
}

int main() {
	int n,T; //n은 숫자, T는 테스트케이스
	int len; //count는 소수의 개수 (소수 배열의 길이)
	int ans[3] = { 0, };
   int *flag, *prime, *check;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		count1 = 0;
      for (int j = 0; j < 3; j++) ans[j] = 0;
		scanf("%d", &n);
		flag = (int*)calloc(sizeof(int), n + 1); //수가 true인지 flase인지 판별하는 배열
		prime = (int*)malloc(sizeof(int) * n);//n이하의 소수 저장하는 배열
		len=eratos(flag, n, prime); //prime에 n이하의 소수 저장되어있음
		check = (int*)calloc(sizeof(int), len);
		func(0, len, ans, check, prime, n);
		if (count1 == 0) printf("0\n");
	}
   free(flag);
   free(prime);
   free(check);
	return 0;
}