#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int len;
    string s, temp;
    vector <string> v;

    cin >> s;
    len = s.size();
    for (int i = 0; i < len; i++) {
        temp = "";
        for (int j = i; j < len; j++) {
            temp += s[j];
        }
        v.emplace_back(temp);
    }

    sort(v.begin(), v.end());
    for (auto i : v) {
        cout << i << '\n';
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