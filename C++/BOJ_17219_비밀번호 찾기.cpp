#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, find;
    string temp1, temp2;
    unordered_map <string, string> arr;

    cin >> num >> find;
    for (int i = 0; i < num; i++) {
        cin >> temp1 >> temp2;
        arr.insert({temp1, temp2});
    }
    for (int i = 0; i < find; i++) {
        cin >> temp1;
        cout << arr[temp1] << "\n";
    }

    return 0;
}