#include <iostream>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x, temp = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        temp += i;
        cin >> x;
        temp -= x;
    }
    cout << -1 * temp;
    
    return 0;
}