#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> adj;
vector<int> in_degree;
vector<int> dp;

int res = 0;
void search(int x) {
	res = max(res, dp[x]);
	if (in_degree[x]) return;
	in_degree[x] = -1;
	for (auto &u : adj[x]) {
		in_degree[u] --;
		dp[u] = max(dp[u], dp[x]+1);
		if (in_degree[u] == 0) search(u);
	}
}

vector<bool> processed;
pair<int,int> best;
void cycle_process(int x, int lev) {
	if (processed[x]) return;
	processed[x] = true;
	in_degree[x] = -1;

	best.first = max(best.first, dp[x]);
	best.second = max(best.second, lev);

	for (auto &u : adj[x]) {
		cycle_process(u, lev+1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	cin >> m >> n;

	adj.assign(n, vector<int>());
	in_degree.assign(n, 0);
	dp.assign(n, -1);

	for (int i=0; i<m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		in_degree[b] ++;
	}

	for (int i=0; i<n; i++) {
		if (in_degree[i] == 0) {
			dp[i] = 1;
			search(i);
		}
	}

	processed.assign(n, false);
	for (int i=0; i<n; i++) {
		if (in_degree[i] == -1) continue;
		in_degree[i] = -1;
		best = {1, -1};
		cycle_process(i, 1);
		// cout << i << ' ' << best.first << ' ' << best.second << '\n';
		res = max(res, best.first + best.second - 1);
	}

	cout << res << '\n';
	return 0;
}