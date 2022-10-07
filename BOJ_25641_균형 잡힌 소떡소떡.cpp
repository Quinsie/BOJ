#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, s_num, t_num;
    string s;

    cin >> n >> s;

    s_num = 0; t_num = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 's') s_num++;
        else t_num++;
    }

    for (int i = 0; i < n; i++) {
        if (s_num != 0 && t_num != 0 && s_num == t_num) {
            for (int j = i; j < n; j++) {
                cout << s[j];
            }
            break;
        }
        if (s[i] == 's') s_num--;
        else t_num--;
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