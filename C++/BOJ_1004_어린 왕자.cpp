#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool cmp_dist(int c_x, int c_y, int x, int y, int r)
{
    return pow(c_x - x, 2) + pow(c_y - y, 2) > pow(r, 2);
}

void solve()
{
    int s_x, s_y, e_x, e_y, planet, x, y, r, count;

    cin >> s_x >> s_y >> e_x >> e_y >> planet;
    count = 0;
    for (int i = 0; i < planet; i++) {
        cin >> x >> y >> r;
        if (cmp_dist(s_x, s_y, x, y, r) != cmp_dist(e_x, e_y, x, y, r)) count++;
    }
    cout << count << '\n';
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
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}