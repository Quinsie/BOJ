#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
 
char map[399][397];
void drawStar(int n, int x, int y) {
 
    int width = 4 * n - 3;
    int height = width + 2;
 
    for (int i = 1; i < width; i++) map[x][y--] = '*';
    for (int i = 1; i < height; i++) map[x++][y] = '*';
    for (int i = 1; i < width; i++) map[x][y++] = '*';
    for (int i = 1; i < height - 2; i++) map[x--][y] = '*';
    
    map[x][y] = '*'; 
    y--;
    map[x][y] = '*';
 
    if (n == 2) {
        map[x][y-1] = '*';
        map[x+1][y-1] = '*';
        map[x+2][y-1] = '*';
        return;
    }
 
    drawStar(n-1, x, y-1);
}
 
int main() {
    int n;
    cin >> n;
 
    if (n == 1) {
        printf("*");
        return 0;
    }
 
    int width = 4 * n - 3;
    int height = width + 2;
 
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = ' ';
        }
    }
 
    int x = 0, y = 4*n - 4;
    
    drawStar(n, x, y);
 
    for (int i = 0; i < height; i++) {
        if (i == 1) {
            printf("*\n");
            continue;
        }
 
        for (int j = 0; j < width; j++) {
            printf("%c", map[i][j]);
        }
        cout << "\n";
    }
    
    return 0;
}