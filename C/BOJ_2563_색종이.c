#include <stdio.h>

int main()
{
    int x, y, num, count = 0, table[100][100] = { 0, };
    scanf("%d", &num);
    for (int i = 0; i < num; i++){
        scanf("%d %d", &x, &y);
        for (int j = x - 1; j < x + 9; j++){
            for (int k = y - 1; k < y + 9; k++){
                table[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if (table[i][j] == 1) count++;
        }
    }

    printf("%d\n", count);
    return 0;
}