#include <iostream>
using namespace std;

int main()
{
    int num, count(0);
    cin >> num;
    for (int i = 1; i <= num; i++) count += i;
    cout << count << "\n";
    return 0;
}