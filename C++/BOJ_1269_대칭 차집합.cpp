#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void solve()
{
    int a, b, temp, count;
    vector <int> arr;
    unordered_map <int, int> table;

    cin >> a >> b;
    for (int i = 0; i < a + b; i++) {
        cin >> temp;
        arr.emplace_back(temp);
        table[temp]++;
    }

    count = 0;
    for (auto i : arr) {
        if (table[i] == 1) count++;
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