#include <stdio.h>
#include <stdlib.h>

void recursive(int pos, int n, int target, int* ans, int* check, int* num_arr)
{
    int temp = -1;
    if (pos == target) {
        for (int i = 0; i < target; i++) {
            printf("%d ", num_arr[ans[i]]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!check[i] && temp != num_arr[i]) {
            check[i] = 1;
            ans[pos] = i;
            temp = num_arr[i];
            recursive(pos + 1, n, target, ans, check, num_arr);
            check[i] = 0;
            ans[pos] = 0;
        }
    }
}

void bubble(int* arr, int length)
{
    int temp;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, m;
    int *ans, *check, *num_arr;

    scanf("%d %d", &n, &m);
    ans = (int*)calloc(sizeof(int), m);
    check = (int*)calloc(sizeof(int), n);
    num_arr = (int*)calloc(sizeof(int), n);
    for (int i = 0; i < n; i++) scanf("%d", &num_arr[i]);

    bubble(num_arr, n);
    recursive(0, n, m, ans, check, num_arr);

    free(ans);
    free(check);
    free(num_arr);
    return 0;
}