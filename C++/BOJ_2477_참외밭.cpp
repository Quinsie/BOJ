#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int k, area, ans, temp;
    vector <pair <int, int>> table(6);

    cin >> k;
    for (int i = 0; i < 6; i++) {
        cin >> table[i].first >> table[i].second;
    }

    area = -1;
    ans = -1;
    for (int i = 0; i < 6; i++) {
        temp = table[i].second * table[(i + 1) % 6].second;
        if (area == -1 || temp > area) {
            area = temp;
            ans = area - table[(i + 3) % 6].second * table[(i + 4) % 6].second;
        }
    }

    cout << ans * k << '\n';
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