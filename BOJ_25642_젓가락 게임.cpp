#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int a, b;
    bool flag;

    cin >> a >> b;

    while (true) {
        b += a;
        if (b >= 5) {
            flag = true;
            break;
        }
        a += b;
        if (a >= 5) {
            flag = false;
            break;
        }
    }

    if (flag) cout << "yt\n";
    else cout << "yj\n";
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