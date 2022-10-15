#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int repeat, num;
    string str;

    cin >> repeat;
    for (int r = 0; r < repeat; r++) {
        cin >> num >> str;
        for (int i = 0; i < str.length(); i++) {
            for (int j = 0; j < num; j++) {
                cout << str[i];
            }
        }
        cout << "\n";
    }

    return 0;
}
