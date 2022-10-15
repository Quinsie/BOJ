#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector <vector <int>> move_up(const int& size, int& comp_max, const vector <vector <int>>& table)
{
    int save, len;
    deque <int> dq;
    vector <vector <int>> ret(size, vector <int> (size, 0));

    for (int j = 0; j < size; j++) {
        save = 0;
        for (int i = 0; i < size; i++) {
            comp_max = max(comp_max, table[i][j]);
            if (!save) { // not saved
                if (table[i][j]) { 
                    save = table[i][j];
                    dq.emplace_back(table[i][j]);
                }
            } else { // saved
                if (table[i][j]) { // number exist
                    if (save == table[i][j]) {
                        dq.pop_back();
                        dq.emplace_back(save * 2);
                        save = 0;
                    } else {
                        save = table[i][j];
                        dq.emplace_back(table[i][j]);
                    }
                }
            }
        }
        
        len = dq.size();
        for (int i = 0; i < len; i++) {
            ret[i][j] = dq.front();
            dq.pop_front();
        }
        dq.clear();
    }

    return ret;
}

vector <vector <int>> move_down(const int& size, int& comp_max, const vector <vector <int>>& table)
{
    int save, len, idx;
    deque <int> dq;
    vector <vector <int>> ret(size, vector <int> (size, 0));

    for (int j = 0; j < size; j++) {
        save = 0;
        for (int i = size - 1; i >= 0; i--) {
            comp_max = max(comp_max, table[i][j]);
            if (!save) { // not saved
                if (table[i][j]) { 
                    save = table[i][j];
                    dq.emplace_back(table[i][j]);
                }
            } else { // saved
                if (table[i][j]) { // number exist
                    if (save == table[i][j]) {
                        dq.pop_back();
                        dq.emplace_back(save * 2);
                        save = 0;
                    } else {
                        save = table[i][j];
                        dq.emplace_back(table[i][j]);
                    }
                }
            }
        }
        
        idx = size - 1;
        while (!dq.empty()) {
            ret[idx][j] = dq.front();
            dq.pop_front();
            idx--;
        }
        dq.clear();
    }

    return ret;
}

vector <vector <int>> move_left(const int& size, int& comp_max, const vector <vector <int>>& table)
{
    int save, len;
    deque <int> dq;
    vector <vector <int>> ret(size, vector <int> (size, 0));

    for (int i = 0; i < size; i++) {
        save = 0;
        for (int j = 0; j < size; j++) {
            comp_max = max(comp_max, table[i][j]);
            if (!save) { // not saved
                if (table[i][j]) { 
                    save = table[i][j];
                    dq.emplace_back(table[i][j]);
                }
            } else { // saved
                if (table[i][j]) { // number exist
                    if (save == table[i][j]) {
                        dq.pop_back();
                        dq.emplace_back(save * 2);
                        save = 0;
                    } else {
                        save = table[i][j];
                        dq.emplace_back(table[i][j]);
                    }
                }
            }
        }
        
        len = dq.size();
        for (int j = 0; j < len; j++) {
            ret[i][j] = dq.front();
            dq.pop_front();
        }
        dq.clear();
    }

    return ret;
}

vector <vector <int>> move_right(const int& size, int& comp_max, const vector <vector <int>>& table)
{
    int save, len, idx;
    deque <int> dq;
    vector <vector <int>> ret(size, vector <int> (size, 0));

    for (int i = 0; i < size; i++) {
        save = 0;
        for (int j = size - 1; j >= 0; j--) {
            comp_max = max(comp_max, table[i][j]);
            if (!save) { // not saved
                if (table[i][j]) { 
                    save = table[i][j];
                    dq.emplace_back(table[i][j]);
                }
            } else { // saved
                if (table[i][j]) { // number exist
                    if (save == table[i][j]) {
                        dq.pop_back();
                        dq.emplace_back(save * 2);
                        save = 0;
                    } else {
                        save = table[i][j];
                        dq.emplace_back(table[i][j]);
                    }
                }
            }
        }

        idx = size - 1;
        while (!dq.empty()) {
            ret[i][idx] = dq.front();
            dq.pop_front();
            idx--;
        }
        dq.clear();
    }

    return ret;
}

void recursive(const int& depth, const int& size, int& ans, const vector <vector <int>>& table)
{
    int after_max, expect_max;
    vector <vector <int>> after_move;

    if (depth == 5) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ans = max(ans, table[i][j]);
            }
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (i == 0) {
            after_max = 0;
            after_move = move_up(size, after_max, table);
            if (table == after_move) continue;
            expect_max = after_max * pow(2, 10 - depth - 1);
            if (expect_max > ans) recursive(depth + 1, size, ans, after_move);
        }
        if (i == 1) {
            after_max = 0;
            after_move = move_down(size, after_max, table);
            if (table == after_move) continue;
            expect_max = after_max * pow(2, 10 - depth - 1);
            if (expect_max > ans) recursive(depth + 1, size, ans, after_move);
        }
        if (i == 2) {
            after_max = 0;
            after_move = move_left(size, after_max, table);
            if (table == after_move) continue;
            expect_max = after_max * pow(2, 10 - depth - 1);
            if (expect_max > ans) recursive(depth + 1, size, ans, after_move);
        }
        if (i == 3) {
            after_max = 0;
            after_move = move_right(size, after_max, table);
            if (table == after_move) continue;
            expect_max = after_max * pow(2, 10 - depth - 1);
            if (expect_max > ans) recursive(depth + 1, size, ans, after_move);
        }
    }
}

void solve()
{
    int n, ans;
    vector <vector <int>> table;

    cin >> n;
    table.assign(n, vector <int> (n, 0));
    ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> table[i][j];
            ans = max(ans, table[i][j]);
        }
    }

    recursive(0, n, ans, table);
    cout << ans << '\n';
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