// not solved yet. need to resolve.
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

typedef struct fuckswan {
    int x, y;
} fuckswan;

int bfs(vector <string> &table, int column, int row, fuckswan s1, fuckswan s2)
{
    char now;
    int x, y, nx, ny;
    bool flag = false; // if true = que1 to que2, false = que2 to que1
    vector <vector <int>> check(column, vector <int> (row, -1));
    queue <pair <int, int>> que1, que2;

    check[s1.x][s1.y] = 0; check[s2.x][s2.y] = 0;
    que1.push({s1.x, s1.y}); que1.push({s2.x, s2.y}); 
    /* que1 start : swan s1, swan s2
    swan = if next block is X -> check + 1 and push to que2.
    dot = keep check num. */

    while(!que1.empty()) { // first action
        x = que1.front().first; y = que1.front().second;
        now = table[x][y];
        que1.pop();
        for (int i = 0; i < 4; i++) {
            nx = x + dx[i]; ny = y + dy[i];
            if (nx >= 0 && nx < column && ny >= 0 && ny < row) {
                // if new block is number and not same with now block
                if (isdigit(table[nx][ny]) && table[nx][ny] != now) {
                    return max(check[x][y], check[nx][ny]);
                }
                if (check[nx][ny] == -1) { // if not visited
                    if (table[nx][ny] == '.') { // if water
                        check[nx][ny] = check[x][y];
                        table[nx][ny] = now;
                        que1.push({nx, ny});
                    } else if (table[nx][ny] == 'X') { // if ice
                        check[nx][ny] = check[x][y] + 1;
                        table[nx][ny] = now;
                        que2.push({nx, ny}); // push to que2
                    }
                }
            }
        }
    }

    for (int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            if (table[i][j] == '.') {
                for (int k = 0; k < 4; k++) {
                    nx = i + dx[k]; ny = j + dy[k];
                    if (nx >= 0 && nx < column && ny >= 0 && ny < row) {
                        if (table[nx][ny] == 'X') { // if not checked and ice
                            que1.push({nx, ny});
                            que2.push({nx, ny}); // push to que2
                        }
                    }
                }
            }
        }
    }
    while (!que1.empty()) {
        x = que1.front().first; y = que1.front().second;
        que1.pop();
        table[x][y] = '.';
    }

    // starting flag status = false (que2 to que1)
    while (true) {
        if (!flag) { // que2 to que1
            while (!que2.empty()) {
                x = que2.front().first; y = que2.front().second;
                now = table[x][y];
                que2.pop();
                for (int i = 0; i < 4; i++) {
                    nx = x + dx[i]; ny = y + dy[i];
                    if (nx >= 0 && nx < column && ny >= 0 && ny < row) {
                        if (isdigit(now)) { // if nowblock is num
                            if (isdigit(table[nx][ny]) && table[nx][ny] != now) {
                                return max(check[x][y], check[nx][ny]);
                            }
                            if (check[nx][ny] == -1) { // if not visited
                                if (table[nx][ny] == '.') { // if water
                                    check[nx][ny] = check[x][y];
                                    table[nx][ny] = now;
                                    que2.push({nx, ny});
                                } else if (table[nx][ny] == 'X') { // if ice
                                    check[nx][ny] = check[x][y] + 1;
                                    table[nx][ny] = now;
                                    que1.push({nx, ny}); // push to que1
                                }
                            }
                        } else { // if nowblock is water
                            if (table[nx][ny] == 'X') {
                                table[nx][ny] = '.';
                                que1.push({nx, ny});
                            }
                        }
                    }
                }
            }
            flag = true;
        } else { // que1 to que2
            while (!que1.empty()) {
                x = que1.front().first; y = que1.front().second;
                now = table[x][y];
                que1.pop();
                for (int i = 0; i < 4; i++) {
                    nx = x + dx[i]; ny = y + dy[i];
                    if (nx >= 0 && nx < column && ny >= 0 && ny < row) {
                        if (isdigit(now)) { // if nowblock is num
                            if (isdigit(table[nx][ny]) && table[nx][ny] != now) {
                                return max(check[x][y], check[nx][ny]);
                            }
                            if (check[nx][ny] == -1) { // if not visited
                                if (table[nx][ny] == '.') { // if water
                                    check[nx][ny] = check[x][y];
                                    table[nx][ny] = now;
                                    que1.push({nx, ny});
                                } else if (table[nx][ny] == 'X') { // if ice
                                    check[nx][ny] = check[x][y] + 1;
                                    table[nx][ny] = now;
                                    que2.push({nx, ny}); // push to que1
                                }
                            }
                        } else { // if nowblock is water
                            if (table[nx][ny] == 'X') {
                                table[nx][ny] = '.';
                                que2.push({nx, ny});
                            }
                        }
                    }
                }
            }
            flag = false;
        }
        if (que1.empty() && que2.empty()) break;
    }
    return -1; // cannot meet
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int column, row;
    bool flag = false;
    vector <string> table;
    string temp;
    fuckswan s1, s2;

    cin >> column >> row;
    for (int i = 0; i < column; i++) { // make table
        cin >> temp;
        for (int j = 0; j < row; j++) {
            if (temp[j] == 'L') {
                if (!flag) { // swan memo (flag 0 = 1, 1 = 2)
                    s1.x = i; s1.y = j;
                    temp[j] = '1';
                    flag = true;
                } else {
                    s2.x = i; s2.y = j;
                    temp[j] = '2';
                }
            }
        }
        table.emplace_back(temp);
    }

    cout << bfs(table, column, row, s1, s2) << '\n';

	return 0;
}
