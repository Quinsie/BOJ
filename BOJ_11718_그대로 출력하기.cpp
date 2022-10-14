#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    string str;
    while (true) {
        getline(cin, str);
        if (cin.eof()) break;
        cout << str << '\n';
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