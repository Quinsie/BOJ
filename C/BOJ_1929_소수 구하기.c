#include <stdio.h>
#include <stdlib.h>

void eratos(int n, int m)
{
    int count = 0;
    int* check = (int*)calloc(m + 1, sizeof(int));
    check[0] = 1;
    check[1] = 1;

    for (int i = 2; i * i <= m; i++){
        if (check[i] == 0){
            for (int j = i + i; j <= m; j += i) check[j] = 1;
        }
    }

    for (int i = n; i <= m; i++){
        if (check[i] == 0) printf("%d\n", i);
    }

    free(check);
}

int main()
{
    int start, end;
    scanf("%d %d", &start, &end);
    eratos(start, end);
    return 0;
}