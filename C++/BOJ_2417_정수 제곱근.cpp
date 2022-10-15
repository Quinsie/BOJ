#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long num, ans;

    cin >> num;
    ans = sqrt(num);

    if(pow(ans, 2) < num) ans++;
    cout << ans;

    return 0;
}