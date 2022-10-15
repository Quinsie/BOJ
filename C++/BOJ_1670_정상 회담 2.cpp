#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 987654321;

long long dp(int num)
{
    if (num == 0 || num == 2) return 1;

    long long ans;
    vector <long long> cache(num + 1);

    cache[0] = 1;
    cache[2] = 1;
    cache[4] = 2;
    for (int i = 6; i <= num; i += 2) {
        for (int j = 0; j <= i - 2; j += 2) {
            cache[i] = (cache[i] + (cache[j] * cache[i - j - 2]));
            cache[i] %= MOD;
        }
    }

    return cache[num];
}

void optimize()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() 
{
    int num;
    optimize();
    
    cin >> num;
    cout << dp(num) << '\n';

    return 0;
}