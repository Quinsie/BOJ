#include <iostream>
#include <vector>

using namespace std;

int find(int n, vector <int>& arr)
{
    if (arr[n] != n) {
        arr[n] = find(arr[n], arr);
    }
    return arr[n];
}

void union_vector(int a, int b, vector <int>& arr)
{
    if (find(a, arr) > find(b, arr)) arr[arr[a]] = arr[b];
    else arr[arr[b]] = arr[a];
}

void solve()
{
    int n, m, order, a, b;
    vector <int> arr;

    cin >> n >> m;
    
    for (int i = 0; i <= n; i++) {
        arr.emplace_back(i);
    }

    for (int i = 0; i < m; i++) {
        cin >> order >> a >> b;
        if (order == 0) union_vector(a, b, arr);
        else {
            if (find(a, arr) == find(b, arr)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
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