#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef vector <vector <int>> vvi;
typedef vector <vector <bool>> vvb;

const int dx[4] = { 0, 0, 1, -1 };
const int dy[4] = { 1, -1, 0, 0 };

void dfs(int& out_count, int x, int y, int size, vvi table, vvb& check)
{
    int nx, ny;
    out_count++;

    check[x][y] = true; // dfs는 상관 없을듯
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i]; ny = y + dy[i];
        if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
            if (table[nx][ny] && !check[nx][ny]) {
                dfs(out_count, nx, ny, size, table, check);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int size, out_count;
    string temp;
    vector <int> ans;
    vvi table;
    vvb check;

    cin >> size;
    table.assign(size, vector <int> (size));
    check.assign(size, vector <bool> (size, false));

    for (int i = 0; i < size; i++) {
        cin >> temp;
        for (int j = 0; j < size; j++) {
            table[i][j] = (int)temp[j] - 48;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (table[i][j] && !check[i][j]) {
                out_count = 0;
                dfs(out_count, i, j, size, table, check);
                ans.emplace_back(out_count);
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i << "\n";
    }
    
    return 0;
}