#include <stdio.h>
#include <stdlib.h>

int max_arr(int* arr, int length)
{
    int maximum = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] > maximum) maximum = arr[i];
    }
    return maximum;
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

void recursive(int pos, int* dwarf, int* ans, int* check)
{
    static int sum = 0, flag = 0;

    if (flag == 1) return;

    if (pos == 7)
    {
        if (sum != 100) return;
        else {
            for (int i = 0; i < 7; i++){
                printf("%d\n", dwarf[ans[i]]);
            }
            flag = 1;
            return;
        }
    }

    for (int i = max_arr(ans, 7); i < 9; i++){
        if (!check[i]){
            check[i] = 1;
            ans[pos] = i;
            sum += dwarf[i];
            recursive(pos + 1, dwarf, ans, check);
            check[i] = 0;
            ans[pos] = 0;
            sum -= dwarf[i];
        }
    }
}
int main()
{
    int *dwarf, *check, *ans;

    dwarf = (int*)calloc(sizeof(int), 9);
    check = (int*)calloc(sizeof(int), 9);
    ans = (int*)calloc(sizeof(int), 7);

    for (int i = 0; i < 9; i++) scanf("%d", &dwarf[i]);
    bubble(dwarf, 9);
    recursive(0, dwarf, check, ans);

    free(dwarf);
    free(check);
    free(ans);
    return 0;
}