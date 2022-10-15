#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, index, num = 666;
    string temp;

    cin >> n;
    n--;

    while (n) {
        num++;
        temp = to_string(num);
        index = temp.find("666");
        if (index >= 0 && index < temp.size()) n--;
    }

    cout << num << '\n';

    return 0;
}