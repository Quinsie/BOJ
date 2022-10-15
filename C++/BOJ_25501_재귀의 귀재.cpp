#include <iostream>
#include <string>

using namespace std;

int recursive(const string& s, const int& left, const int& right, int& ans)
{
    ans++;
    if (left >= right) return 1;
    else if (s[left] != s[right]) return 0;
    else return recursive(s, left + 1, right - 1, ans);
}

void solve()
{
    int length, ans;
    string s;

    cin >> s;
    length = s.size();

    ans = 0;
    cout << recursive(s, 0, length - 1, ans) << ' ';
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
    int t; cin >> t; while (t--) solve();
    return 0;
}