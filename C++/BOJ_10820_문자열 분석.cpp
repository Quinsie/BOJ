#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int small, big, number, blank, length;
    string s;
    
    while (getline(cin, s)) {
        length = s.size();
        small = 0; big = 0; number = 0; blank = 0;
        for (int i = 0; i < length; i++) {
            if (s[i] >= 65 && s[i] <= 90) big++;
            else if (s[i] >= 97 && s[i] <= 122) small++;
            else if (s[i] >= 48 && s[i] <= 57) number++;
            else blank++;
        }

        cout << small << ' ' << big << ' ' << number << ' ' << blank << '\n';
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