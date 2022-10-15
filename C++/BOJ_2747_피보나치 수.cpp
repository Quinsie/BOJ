#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector <int> arr;
    
    cin >> n;
    
    arr.assign(n + 1, 0);
    arr[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    
    cout << arr[n] << '\n';

    return 0;
}
