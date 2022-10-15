#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve()
{
    double w, h, x, y, r, p_x, p_y;
    int p, count;

    cin >> w >> h >> x >> y >> p;
    r = h / 2.0;
    count = 0;
    while (p--) {
        cin >> p_x >> p_y;
        if (x <= p_x && p_x <= x + w && y <= p_y && p_y <= y + h) {
            count++;
            continue;
        }

        if (pow(p_x - x, 2) + pow(p_y - (y + r), 2) <= pow(r, 2)) {
            count++;
            continue;
        }
        if (pow(p_x - (x + w), 2) + pow(p_y - (y + r), 2) <= pow(r, 2)) {
            count++;
            continue;
        }
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
    solve();
    return 0;
}