#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    if (a < b) return a;
    else return b;
}

int main()
{
    char** table;
    char* temp;
    char now;
    int column, row, w_first, b_first, change, minimum = 10e8;
    scanf("%d %d", &column, &row);

    temp = (char*)malloc(sizeof(char) * (row + 1));
    table = (char**)malloc(sizeof(char*) * column);
    for (int i = 0; i < column; i++){
        table[i] = (char*)malloc(sizeof(char) * row);
    }

    for (int i = 0; i < column; i++){
        scanf("%s", temp);
        for (int j = 0; j < row; j++){
            table[i][j] = temp[j];
        }
    }

    for (int i = 0; i < column - 7; i++){
        for (int j = 0; j < row - 7; j++){

            w_first = 0;
            now = 87; // W = 87, B = 66
            change = 0;
            for (int a = i; a < i + 8; a++){
                if (change / 8 == 1){
                    if (now == 87){
                        now = 66;
                        change = 0;
                    }
                    else{
                        now = 87;
                        change = 0;
                    }
                }
                for (int b = j; b < j + 8; b++){
                    if (table[a][b] != now) w_first++;
                    if (now == 87) now = 66;
                    else if (now == 66) now = 87;
                    change++;
                }
            }

            b_first = 0;
            now = 66;
            change = 0;
            for (int a = i; a < i + 8; a++){
                if (change / 8 == 1){
                    if (now == 66){
                        now = 87;
                        change = 0;
                    }
                    else{
                        now = 66;
                        change = 0;
                    }
                }
                for (int b = j; b < j + 8; b++){
                    if (table[a][b] != now) b_first++;
                    if (now == 66) now = 87;
                    else if (now == 87) now = 66;
                    change++;
                }
            }

            if (min(w_first, b_first) < minimum)
                minimum = min(w_first, b_first);
            
        }
    }

    printf("%d", minimum);
    free(temp);
    for (int i = 0; i < column; i++){
        free(table[i]);
    }
    free(table);
    return 0;
}