#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	ll n, b, a; cin >> n >> b >> a;

	vector<ll> v(n+1);
	for (ll i=1; i<=n; i++) cin >>  v[i];
	sort(v.begin(), v.end());
		
	vector<ll> psum1(n+1, 0);
	vector<ll> psum2(n+1, 0);

	for (int i=1; i<=n; i++) {
		psum1[i] = psum1[i-1] + v[i];
		psum2[i] = psum2[i-1] + v[i]/2;
	}

	ll res = 0;

	for (int i=1; i<=n-a+1; i++) {
		if (psum1[i-1] + psum2[i+a-1] - psum2[i-1] <= b) {
			res = max(res, i+a-1);
		}
	}

	if (res == 0) {
		ll cnt = 0;
		ll cur = 0;
		for (int i=1; i<=n; i++) {
			if (cur+v[i]/2 <= b) {
				cnt ++;
				cur += v[i]/2;
			}
		}
		res = cnt;
	}

	cout << res << '\n';
	return 0;
}