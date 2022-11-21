#include <bits/stdc++.h>

using namespace std;

const int INF = 10e8 + 7;

class edge {
public:
	int from, to, dis;

	edge() { from = 0; to = 0; dis = 0; }
	edge(int a, int b, int c) { 
		from = a;
		to = b;
		dis = c;
	}
	~edge() {}
};

bool compare(edge a, edge b)
{
	if (a.from == b.from) return a.to < b.to;
	return a.from > b.from;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, t, m, start, end, fr, to, di;
	vector <int> ans;

	cin >> n >> t >> m >> start >> end;
	ans.assign(n, INF);

	ans[start] = 0;

	for (int i = 0; i < t; i++) {
		vector <edge> arr;
		for (int j = 0; j < m; j++) {
			cin >> fr >> to >> di;
			arr.emplace_back(edge(fr, to, di));
			arr.emplace_back(edge(to, fr, di));
		}
		sort(arr.begin(), arr.end(), compare);

		for (int j = 0; j < m * 2; j++) {
			if (ans[arr[j].from] == INF) continue;

			ans[arr[j].to] = min(ans[arr[j].to], ans[arr[j].from] + arr[j].dis);
		}
	}

	if (ans[end] == INF) cout << -1 << '\n';
	else cout << ans[end] << '\n';
	
	return 0;
}