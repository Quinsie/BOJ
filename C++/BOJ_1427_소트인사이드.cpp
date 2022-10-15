#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, num_arr[10] = { 0, };
    string str;

    cin >> num;
    str = to_string(num);
    for (int i = 0; i < str.length(); i++) {
        num_arr[str[i] - 48]++;
    }
    
    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < num_arr[i]; j++) cout << i;
    }

    return 0;
}