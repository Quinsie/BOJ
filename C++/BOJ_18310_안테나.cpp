#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp;
    vector <int> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.emplace_back(temp);
    }
    sort(v.begin(), v.end());
    cout << v[(n - 1) / 2] << '\n';

    return 0;
}