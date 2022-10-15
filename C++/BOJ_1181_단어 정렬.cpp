#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string s1, string s2)
{
    if (s1.length() == s2.length()) return s1 < s2;
    return s1.length() < s2.length();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    string temp;
    vector<string> arr;
    
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> temp;
        arr.emplace_back(temp);
    }
    sort(arr.begin(), arr.end(), compare);
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for (int i = 0; i < arr.size(); i++) cout << arr[i] << '\n';

    return 0;
}