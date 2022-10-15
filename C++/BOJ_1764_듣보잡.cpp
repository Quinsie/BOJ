#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, count = 0;
    string str;
    unordered_map <string, int> m;
    vector <string> v;

    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        cin >> str;
        m[str]++;
    }

    for (int i = 0; i < b; i++) {
        cin >> str;
        if (m[str]) {
            count++;
            v.emplace_back(str);
        }
    }

    sort(v.begin(), v.end());

    cout << count << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
    
    return 0;
}