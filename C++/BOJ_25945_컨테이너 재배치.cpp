#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	ll n; cin >> n;

	
	ll sm = 0;
	vector<ll> arr(n), brr(n);
	for (int i=0; i<n; i++) {
		cin >> arr[i];
		sm += arr[i];
	}
	ll p = sm / n;
	ll q = sm % n;

	sort(arr.begin(), arr.end());

	for (int i=0; i<n; i++) {
		if (i < n-q) {
			brr[i] = p;
		}
		else {
			brr[i] = p+1;
		}
	}

	ll res = 0;
	for (int i=n-1; i>=0; i--) {
		if (arr[i] < brr[i]) break;
		res += abs(arr[i] - brr[i]);
	}

	// for (auto &u : arr) cout << u << ' ';
	// cout << '\n';
	// for (auto &u : brr) cout << u << ' ';
	// cout << '\n';


	cout << res << '\n';
	return 0;
}