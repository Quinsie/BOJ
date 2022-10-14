#include <bits/stdc++.h>

using namespace std;

void solve()
{
    char temp;
    int size, flag;
    string s;

    getline(cin, s);
    size = s.size();

    for (int i = 0; i < size; i++) {
        if (s[i] >= 65 && s[i] <= 77) {
            cout << (char)(s[i] + 13);
        } else if (s[i] >= 78 && s[i] <= 90) {
            cout << (char)(s[i] - 13);
        } else if (s[i] >= 97 && s[i] <= 109) {
            cout << (char)(s[i] + 13);
        } else if (s[i] >= 110 && s[i] <= 122) {
            cout << (char)(s[i] - 13);
        } else {
            cout << s[i];
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