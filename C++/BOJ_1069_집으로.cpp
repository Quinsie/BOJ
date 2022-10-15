#include <iostream>
#include <cmath>

using namespace std;

double three_min(double a, double b, double c)
{
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(15);
    cout << fixed;

    double x, y, dist, ans;
    int jump_dist, jump_time, jump_num;

    cin >> x >> y >> jump_dist >> jump_time;
    dist = sqrt(pow(x, 2) + pow(y, 2));

    if (jump_time > jump_dist) { // if jump is inefficient than walk
        cout << dist << "\n";
        return 0;
    }

    jump_num = dist / jump_dist;
    if (jump_num < 0) jump_num = 0;

    ans = 0.0;
    if (!jump_num) { // if jump num is zero (cannot jump)
        ans = dist; // just walk
        ans = min(ans, jump_time + abs(dist - jump_dist)); // walk after overjump
        ans = min(ans, (double)(jump_time * 2));
    } else { // can jump at least one time
        ans += (jump_num - 1) * jump_time;
        dist -= (jump_num - 1) * jump_dist;
        
        ans = three_min(ans + jump_time + abs(dist - jump_dist), ans + jump_time * 2 + abs(dist - jump_dist), ans + jump_time * 2);
    }

    cout << ans << "\n";

    return 0;
}