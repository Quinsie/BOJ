#include <iostream>
#include <vector>

using namespace std;

void cut(int x, int y, int size, vector <vector <int>>& table, int& white, int& blue)
{
    int start, count;
    
    start = table[x][y];
    count = 0;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (table[x + i][y + j] != start) {
                count++;
            }
            if (count) break;
        }
        if (count) break;
    }
    
    if (!count) {
        if (start == 0) white++;
        else blue++;
    } else {
        cut(x, y, size / 2, table, white, blue);
        cut(x, y + (size / 2), size / 2, table, white, blue);
        cut(x + (size / 2), y, size / 2, table, white, blue);
        cut(x + (size / 2), y + (size / 2), size / 2, table, white, blue);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int size, white, blue;
    vector <vector <int>> table;
    
    cin >> size;
    for (int i = 0; i < size; i++) {
        table.emplace_back(vector <int> (size, 0));
        for (int j = 0; j < size; j++) {
            cin >> table[i][j];
        }
    }
    
    white = 0; blue = 0;
    cut(0, 0, size, table, white, blue);
    cout << white << '\n' << blue << '\n';

    return 0;
}
