#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int n, left, right, gap, count, now;
	vector <int> arr;
	const int thing[7] = { 1, 2, 5, 10, 20, 50, 100 };

	cin >> n;
	arr.assign(n, 0);

	for (int i = 0; i < n; i++) cin >> arr[i];

	left = arr[0]; right = arr[1];
	for (int i = 2; i < n; i++) {
		if (left == right) left += arr[i];
		else {
			if (left < right) left += arr[i];
			else right += arr[i];
		}
	}

	gap = abs(left - right);
	count = 0;

	now = 6;
	while (gap >= 0 && now >= 0) {
		if (gap - thing[now] >= 0) {
			gap -= thing[now];
			count++;
		} else {
			now--;
		}
	}

	cout << count << '\n';

	return 0;
}