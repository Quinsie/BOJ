#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int bfs(int* chart, int length)
{
    int pos, new_pos, count;
    bool* check;
    queue <pair <int, int>> que;

    check = new bool[length]{false};
    check[0] = true;
    que.push({0, 0});

    while (!que.empty()) {
        pos = que.front().first; count = que.front().second;
        que.pop();
        if (pos == length - 1) return count;

        for (int i = 1; i <= chart[pos]; i++) {
            new_pos = pos + i;
            if (new_pos < length && !check[new_pos]) {
                check[new_pos] = true;
                que.push({new_pos, count + 1});
            }
        }
    }

    delete[] check;
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tile, temp;
    int* table;

    cin >> tile;
    table = new int[tile];
    for (int i = 0; i < tile; i++) cin >> table[i];
    cout << bfs(table, tile);

    delete[] table;
    return 0;
}