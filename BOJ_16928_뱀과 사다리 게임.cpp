#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main()
{
    int n, m, n1, n2, los[101] = { 0, }, d[101] = { 0, };
   	queue <int> q;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> n1 >> n2;
		los[n1] = n2;
	}
	for (int i = 0; i < m; ++i) {
		cin >> n1 >> n2;
		los[n1] = n2;
	}

	memset(d, -1, sizeof(d));
    
	q.push(1);
	d[1] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= 6; ++i) {
			int nx = x + i;
			if (nx > 100) continue;
			if (los[nx] != 0) {
				nx = los[nx];
			}
			if (d[nx] == -1) {
				d[nx] = d[x] + 1;
				q.push(nx);
			}
		}
	}

	cout << d[100] << "\n";
	return 0;
}
