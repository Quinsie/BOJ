#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    string ab, ba;
    ab = a + b;
    ba = b + a;

    if (a == b) return false;
    if (ab > ba) return true;
    else return false;
}

void optimize()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() 
{
    int num;
    string temp, ans;
    vector <string> arr;
    optimize();

    cin >> num;
    while (num--) {
        cin >> temp;
        arr.emplace_back(temp);
    }

    sort(arr.begin(), arr.end(), compare);

    if (arr[0] == "0") cout << 0 << '\n';
    else {
        for (auto i : arr) {
            cout << i;
        }
    }
    return 0;
}