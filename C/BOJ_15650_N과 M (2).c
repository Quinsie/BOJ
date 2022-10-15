#include <stdio.h>
#include <stdlib.h>

int max_arr(int* arr, int length)
{
    int maximum = 0;
    for (int i = 0; i < length; i++){
        if (arr[i] > maximum) maximum = arr[i];
    }
    return maximum;
}

void recursive(int pos, int target, int length, int* ans, int* check)
{
    if (pos == target)
    {
        for (int i = 0; i < target; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }

    for (int i = max_arr(ans, target); i < length; i++){
        if (!check[i]){
            check[i] = 1;
            ans[pos] = i + 1;
            recursive(pos + 1, target, length, ans, check);
            check[i] = 0;
            ans[pos] = 0;
        }
    }
}

int main()
{
    int n, m;
    int *ans, *check;
    scanf("%d %d", &n, &m);

    ans = (int*)calloc(sizeof(int), m);
    check = (int*)calloc(sizeof(int), n);

    recursive(0, m, n, ans, check);
    
    free(ans);
    free(check);
    
    return 0;
}