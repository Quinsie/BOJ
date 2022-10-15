#include <iostream>
#include <vector>

using namespace std;

int gcd(int x, int y)
{
    int temp;
    if (y > x){
        temp = x;
        x = y;
        y = temp;
    }
    while (x % y != 0) {
        temp = x % y;
        x = y;
        y = temp;
    }
    return y;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long sum = 0;
        cin >> n;
        vector <int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                sum += gcd(v[i], v[j]);
            }
        }
        
        cout << sum << '\n';
    }
    return 0;
}