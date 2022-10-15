#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve()
{
    int problem, str_len, start, end, ans;
    char c;
    string str;
    vector <vector <int>> table;

    cin >> str >> problem;
    str_len = str.length();
    table.assign(str_len, vector <int> (26, 0));

    table[0][(int)str[0] - 97]++;
    for (int i = 1; i < str_len; i++) {
        table[i] = table[i - 1];
        table[i][(int)str[i] - 97]++;
    }

    for (int i = 0; i < problem; i++) {
        cin >> c >> start >> end;
        ans = table[end][int(c) - 97] - table[start][int(c) - 97];
        if (start == 0) {
            if (table[0][int(c) - 97]) {
                cout << ans + 1 << '\n';
            } else {
                cout << ans << '\n';
            }
        } else {
            if (table[start][int(c) - 97] == table[start - 1][int(c) - 97]) {
                cout << ans << '\n';
            } else {
                cout << ans + 1 << '\n';
            }
        }
    }
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