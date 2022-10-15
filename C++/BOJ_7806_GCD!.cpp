#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, factor_n, factor_k;
    long long ans;

    while (true) {
        cin >> n >> k;
        if (cin.eof()) break;

        ans = 1;
        for (int i = 2; i * i <= k; i++) {
            factor_n = 0; factor_k = 0;
            while (k % i == 0) {
                k /= i;
                factor_k++;
            }
            if (factor_k > 0) {
                for (int j = i; j <= n; j *= i) factor_n += n / j;
            }
            ans *= pow(i, min(factor_n, factor_k));
            if (k < i) break;
        }
        if (k > 1 && k < n) ans *= k;
        cout << ans << '\n';
    }
    return 0;
}