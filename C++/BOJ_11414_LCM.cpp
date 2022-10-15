#include <iostream>
#include <vector>

using namespace std;

long long gcd (long long x, long long y)
{
	long long temp;
    if (y > x){
        temp = x;
        x = y;
        y = temp;
    }
    while (y != 0){
        temp = x;
        x = y;
        y = temp % y;
    }
    return x;
}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long A, B, X, tk, tRes, res = 1e18, ans, tAns;
    vector <long long> vl;

	cin >> A >> B;
	if (B > A) swap(A, B);
	else if (A == B) {
		cout << "1\n";
		return 0;
	}
    
	ans = X = A - B;
	for (long long i = 1; i * i <= X; i++) {
		if (X % i) continue;
		vl.push_back(i);
		if (X / i != i)
			vl.push_back(X / i);
	}

	for (long long v : vl) {
		if (A % v) {
			tk = v - A % v;
		}
		else continue;
		long long tgcd = gcd(A + tk, B + tk);
		long long tRes = tgcd * (A + tk) / tgcd * (B + tk) / tgcd;
		if (res > tRes) {
			res = tRes;
			ans = tk;
		}
		else if (res == tRes) {
			ans = min(ans, tk);
		}
	}
    
	cout << ans << "\n";
	return 0;
}