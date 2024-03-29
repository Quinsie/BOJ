#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, temp;
    unordered_map <int, int> um;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        um.insert({temp, 1});
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (um[temp]) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    
    return 0;
}