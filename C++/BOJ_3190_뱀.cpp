#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

void solve()
{
    int size, a_num, o_num, x, y, nx, ny, tx, ty, time, dir, i_temp;
    char c_temp;
    vector <vector <int>> table;
    unordered_map <int, char> order;
    queue <pair <int, int>> que;

    cin >> size;
    table.assign(size, vector <int> (size, 0)); // zero = blank

    cin >> a_num;
    for (int i = 0; i < a_num; i++) {
        cin >> x >> y;
        x--; y--;
        table[x][y] = 2; // 2 = apple
    }

    cin >> o_num;
    for (int i = 0; i < o_num; i++) {
        cin >> i_temp >> c_temp;
        cin.ignore();
        order[i_temp] = c_temp;
    }

    table[0][0] = 1; // 1 = snake
    x = 0; y = 0; time = 0; dir = 0;
    while (true) {
        que.push({ x, y });
        time++;
        nx = x + dx[dir]; ny = y + dy[dir];
        if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
            if (table[nx][ny] == 0) { // if blank
                table[nx][ny] = 1;
                x = nx; y = ny;

                tx = que.front().first; ty = que.front().second;
                que.pop();
                table[tx][ty] = 0;
            } else if (table[nx][ny] == 1) { // if snake
                break;
            } else { // if apple
                table[nx][ny] = 1;
                x = nx; y = ny;
            }
        } else {
            break;
        }

        if (order[time] == 'D') {
            dir++;
            if (dir == 4) dir = 0;
        } else if (order[time] == 'L') {
            dir--;
            if (dir == -1) dir = 3;
        }
    }

    cout << time << '\n';
}

void optimize()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    optimize();
    solve();
    return 0;
}