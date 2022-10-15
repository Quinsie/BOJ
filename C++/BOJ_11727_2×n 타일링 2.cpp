#include <iostream>

using namespace std;

const int mod = 10007;

int tile(int num)
{
    if (num == 1) return 1;
    else if (num == 2) return 3;

    int cache(3), temp = 2;

    while (temp != num) {
        if (temp % 2 == 0) {
            cache = ((cache % mod) - 1) % mod;
            cache = ((cache % mod) * 2) % mod;
            cache = ((cache % mod) + 1) % mod;
        }
        else {
            cache = ((cache % mod) - 1) % mod;
            cache = ((cache % mod) * 2) % mod;
            cache = ((cache % mod) + 3) % mod;
        }
        temp++;
    }

    return cache;
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cout << tile(n) << "\n";

    return 0;
}