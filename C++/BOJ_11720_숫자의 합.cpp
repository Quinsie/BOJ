#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int string_len, sum = 0;
    string str;

    cin >> string_len;
    cin >> str;
    for (int i = 0; i < string_len; i++) {
        sum += (int)str[i] - 48;
    }
    cout << sum;

    return 0;
}
