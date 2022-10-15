#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    double x, y, s_x, s_y;
    double area = 0.0, now_area;
    vector <pair <double, double>> table;

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> x >> y;
        table.emplace_back(x, y);
    }

    s_x = table[0].first; s_y = table[0].second;
    for (int i = 2; i < num; i++) {
        now_area = 0.0;
        now_area += (table[i - 1].first - s_x) * (table[i].second - s_y);
        now_area -= (table[i].first - s_x) * (table[i - 1].second - s_y);
        now_area /= 2.0;
        area += now_area;
    }

    cout.precision(1);
    cout << fixed;
    area = fabs(area);
    cout << area << "\n";

    return 0;
}