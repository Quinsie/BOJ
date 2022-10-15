#include <iostream>
#include <string>

using namespace std;

int char_swap(string& str, int length)
{
    char temp;
    for (int i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    return stoi(str);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n1, n2;
    string num1, num2;
    cin >> num1 >> num2;
    n1 = char_swap(num1, num1.length());
    n2 = char_swap(num2, num2.length());
    
    if (n1 > n2) cout << n1;
    else cout << n2;

    return 0;
}
