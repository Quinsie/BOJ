#include <iostream>

using namespace std;

unsigned int fibo(unsigned int n, unsigned int mod)
{
    unsigned int memo[3] = { 0, 1, 1 };
    n -= 1;
    while (n > 0) {
        memo[2] = (memo[1] + memo[0]) % mod;
        memo[0] = memo[1];
        memo[1] = memo[2];
        n--;
    }

    return memo[2] % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned int repeat, num, mod;

    cin >> repeat;
    for (int test_case = 0; test_case < repeat; test_case++) {
        cin >> num >> mod;
        cout << "Case #" << test_case + 1 << ": " << fibo(num, mod) << '\n';
    }

    return 0;
}